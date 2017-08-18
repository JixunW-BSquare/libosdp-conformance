
debug:
	mkdir -p build-debug
	cmake -DCMAKE_BUILD_TYPE=Debug -Bbuild-debug -H.
	make -C build-debug