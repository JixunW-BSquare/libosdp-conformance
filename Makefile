PREFIX ?=

all: debug
everything: all

noop:
	@true

and:  noop
then: noop

clean:
	rm -rf build-debug

debug:
	mkdir -p build-debug
	cmake -DCMAKE_BUILD_TYPE=Debug -Bbuild-debug -H.
	make -C build-debug

install-debug: debug
	cp build-debug/liblibosdp.so $(PREFIX)/lib/liblibosdp.so
	cp build-debug/open-osdp $(PREFIX)/bin/open-osdp
	cp build-debug/sign $(PREFIX)/bin/sign
	cp poke $(PREFIX)/bin/poke