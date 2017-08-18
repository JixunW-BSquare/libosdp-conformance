cmake_minimum_required(VERSION 3.8)
project(libosdp_conformance)

set(CMAKE_CXX_STANDARD 11)

include_directories(include aes src-485 src-lib src-tls src-ui)

add_executable(sign src-cli/sign.cpp)



link_libraries(jansson)

set (COMMON_HEADER_FILES
        aes/aes.h
        include/open-osdp.h
        include/osdp_conformance.h)

set (LIB_SOURCE_FILES
        aes/aes.c
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
        ${COMMON_HEADER_FILES})

set(SOURCE_FILES
        src-485/osdp-local-config.h
        src-485/open-osdp.c
        ${COMMON_HEADER_FILES})

add_library(libosdp SHARED ${LIB_SOURCE_FILES})

link_libraries(libosdp)
add_executable(open-osdp ${SOURCE_FILES})
