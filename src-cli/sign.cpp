/**
 * sign.cpp - A tool to sign given bytes and output as a json command (for debug only)
 * usage: ./sign [byte 1] [byte 2] ...
 *        byte is in hex-representation.
 * 
 * Output: {
 *   "command": "send_buffer",
 *   "buffer": [ 255, 83, ... ]
 * }
 *
 * (C)Copyright 2017-Present BSquare E.M.E.A.
*/

#include <stdint.h>
#include <stdio.h>

#include <open-osdp.h>
#include <osdp_conformance.h>

OSDP_INTEROP_ASSESSMENT osdp_conformance;
OSDP_CONTEXT context;
OSDP_BUFFER osdp_buf;
OSDP_PARAMETERS p_card;
int creds_buffer_a_next;
int creds_buffer_a_lth;
int creds_buffer_a_remaining;
unsigned char creds_buffer_a[2];


void print_data(const char* title, uint8_t* data, size_t len, bool header, bool footer) {
    if (header) {
        printf(" ,\"%s\": [ ", title);
    }

    printf("%d", 0xff);
    for(int i = 0; i < len; i++) {
        printf(", %d", data[i]);
    }

    if (footer) {
        printf(" ] \n");
    }
}

int main(const int argc, const char* argv[]) {
    auto len = argc - 1;
    if (len == 0) {
        printf("A tool to sign given bytes and output as a json command (for debug only)\n\n");
        printf("usage: %s [byte 1] [byte 2] ...\n", argv[0]);
        printf("       byte is in hex-representation.\n");
        printf("output: { \"command\", \"send_buffer\", \"buffer\": [ ... ] }\n");
        return 0;
    }
    uint8_t* data = new uint8_t[len + 2];
    uint8_t* ptr = data;
    for (int i = 1; i < argc; i++) {
        uint32_t tmp;
        sscanf(argv[i], "%02x", &tmp);
        *ptr = tmp & 0xFF;
        ptr++;
    }

    auto crc_1 = checksum(data, len);
    // printf("checksum=%d # ( 0x%02x )\n", crc_1, crc_1);

    auto crc_2 = fCrcBlk(data, len);
    auto hi = static_cast<uint8_t>(crc_2 >> 8);
    auto lo = static_cast<uint8_t>(crc_2 & 0xFF);
    // printf("crc=%d, %d # ( 0x%02x, 0x%02x )\n", lo, hi, lo, hi);


    data[len] = crc_1;

    data[len] = lo;
    data[len + 1] = hi;
    printf("{\n");
    printf("  \"command\": \"send_buffer\"\n");
    print_data("buffer", data, len + 2, true, true);
    printf("}\n");

    delete[] data;
}