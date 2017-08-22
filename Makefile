COPY_TO ?=

all: debug

clean:
	rm -rf build-debug

debug:
	mkdir -p build-debug
	cmake -DCMAKE_BUILD_TYPE=Debug -Bbuild-debug -H.
	make -C build-debug

copy: debug
	cp build-debug/open-osdp $(COPY_TO)