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
