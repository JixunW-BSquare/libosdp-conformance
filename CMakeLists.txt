cmake_minimum_required(VERSION 3.8)
project(libosdp_conformance)

set(CMAKE_CXX_STANDARD 11)

include_directories(include aes src-485 src-lib src-tls src-ui)

link_libraries(jansson)

set(SOURCE_FILES
        include/open-osdp.h
        include/osdp-tls.h
        include/osdp_conformance.h
        src-485/open-osdp.c
        src-485/osdp-local-config.h
        src-lib/oo_cmdbreech.c
        src-lib/oo_initialize.c
        src-lib/oo_process.c
        src-lib/oo_util.c
        src-lib/oo_util2.c
        src-lib/oosdp_actions.c
        src-lib/oosdp_conformance.c
        src-lib/oosdp_crc.c
        src-lib/oosdp_files.c
        src-lib/oosdp_logmsg.c
        src-lib/oosdp_secure.c
        src-lib/oosdp_ui.c
        src-lib/osdp-api.c
        aes/aes.c
        aes/aes.h)

add_executable(libosdp_conformance ${SOURCE_FILES})