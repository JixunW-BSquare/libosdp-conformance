/*
  open-osdp-kick - kick the OSDP process in the Unix socket

  (C)Copyright 2015-2017 Smithee,Spelvin,Agnew & Plinge, Inc.

  Support provided by the Security Industry Association
  http://www.securityindustry.org

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <osdp-local-config.h>

char socket_path[1024];

int main(int argc, char* argv[])
{
    struct sockaddr_un addr;
    char buf[100];
    int fd, rc;
    char* tag;

    tag = "CP";
    if (argc > 1) {
        if (strcmp(argv[1], "MON") == 0)
            tag = "MON";
        if (strcmp(argv[1], "PD") == 0)
            tag = "PD";
    };
    sprintf(socket_path, OSDP_LCL_UNIX_SOCKET, tag);

    if ((fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket error");
        exit(-1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, socket_path, sizeof(addr.sun_path) - 1);

    if (connect(fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("connect error");
        exit(-1);
    }

    while ((rc = read(STDIN_FILENO, buf, sizeof(buf))) > 0) {
        if (write(fd, buf, rc) != rc) {
            if (rc > 0)
                fprintf(stderr, "partial write");
            else {
                perror("write error");
                exit(-1);
            }
        }
    }

    return 0;
}
