cmake_minimum_required(VERSION 3.3)
project(libosdp_conformance)

set(CMAKE_CXX_STANDARD 11)

include_directories(include aes src-485 src-lib src-tls src-ui)

set (COMMON_HEADER_FILES
        include/open-osdp.h
        include/osdp_conformance.h)

set (LIB_SOURCE_FILES
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


# Build sign.
add_executable(osdp-sign src-cli/sign.cpp)

# Build libosdp
link_libraries(tinyaes)
link_libraries(jansson)
add_library(osdp SHARED ${LIB_SOURCE_FILES})

# Build open-osdp
link_libraries(osdp)
add_executable(open-osdp ${SOURCE_FILES})

add_custom_target(buildtest ./test.sh)

# Install to system
install(TARGETS osdp DESTINATION lib)
install(TARGETS open-osdp DESTINATION bin)
install(TARGETS osdp-sign DESTINATION bin)
install(FILES ${COMMON_HEADER_FILES} DESTINATION include/${PROJECT_NAME})
