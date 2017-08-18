# libosdp-conformance
Conformance testing plans and tools for SIA OSDP.
For more information about OSDP visit www.securityindustry.org/OSDP

# Setup
Unless specified, all commands from command blocks
shall begin from current project directory.

Requirement:

* Python 3.x - `poke-command.py`
* `jansson` - JSON Manipulation Library.
  * `apt install libjansson-dev` - Ubuntu
  * `pacman -S jansson` - Arch Linux
  * `zypper in libjansson4` - openSUSE
  * `yum i jansson` - CentOS
* CMake/gcc - build project

## Build

```
mkdir build
cd build
cmake .. && make && echo ok!
```


## Control Panel (CP)

Replace `/dev/pts/2` to your device path.

```sh
# setup config
DEV=/dev/pts/2

mkdir -p tmp
cat ./doc/config-samples/open-osdp-params-CP.json\
    | sed -e "s~{~{\n   \"serial_device\": \"$DEV\",~g" \
    > tmp/cp.json

# run
./build/open-osdp tmp/cp.json
```

### poke

```sh
echo '{
  "command" : "dump_status"
}' | ./poke CP -
```

## Peripheral Device (PD)


Replace `/dev/pts/3` to your device path.

```sh
# setup config
DEV=/dev/pts/3

mkdir -p tmp
cat ./doc/config-samples/open-osdp-params-PD.json\
    | sed -e "s~/dev/ttyUSB0~$DEV~g" \
    > tmp/pd.json

# run
./build/open-osdp tmp/pd.json

```

### poke

```sh
echo '{
  "command" : "dump_status"
}' | ./poke PD -
```


## poke - send_buffer

Buffer is sent on your behalf.

Poke to CP: CP write buffer to PD (Work other way around as well).

### Send POLL

```
./build/sign 53 00 08 00 04 60 | ./poke CP -

# 53: Start of Message
# 00: PD-Address
# 08 00: Packet Size (including CRC)
# 04: Control Bit: Use CRC (2 bytes)
# 60: POLL
```

### Present card

```
./build/sign 53 80 16 00 07 50 00 00 4b 00 09 a4 49 4a a3 27 4c d5 2b c0

# 53: Start of Message
# 80: PD-Address (0), from PD.
# 16 00: Packet Size (including CRC)
# 07: Control Bit: Use CRC | SQN_3
# 50: osdp_RAW (Reader Data – Raw bit image of card data)

# Card Data:
# 00: Reader Number
# 00: Format Code  -  not specified, raw bit array
# 4b 00: Bit Count (9.375 bytes)
# 09 a4 49 4a a3 27 4c d5 2b c0: Card data (80 bits used to represent.)
```