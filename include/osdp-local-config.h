/*
  osdp-local-config.h - local (platform) configuration values

  (C)Copyright 2015-2017 Smithee,Spelvin,Agnew & Plinge, Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  Support provided by the Security Industry Association
  http://www.securityindustry.org
*/

#pragma once

#if ENABLE_WEB_RPC
#define OSDP_BASE_DIR "/opt/osdp-conformance"
#else
#define OSDP_BASE_DIR "./tmp"
#endif

// the server key and cert for the OSDP TLS server

#define OSDP_LCL_CA_KEYS        OSDP_BASE_DIR "/etc/ca_keys.pem"
#define OSDP_LCL_SERVER_CERT    OSDP_BASE_DIR "/etc/cert.pem"
#define OSDP_LCL_SERVER_KEY     OSDP_BASE_DIR "/etc/key.pem"
#define OSDP_LCL_COMMAND_PATH   OSDP_BASE_DIR "/run/%s/open_osdp_command.json"
#define OSDP_LCL_STATUS_PATH    OSDP_BASE_DIR "/run/%s/open-osdp-status.json"
#define OSDP_LCL_SERVER_RESULTS OSDP_BASE_DIR "/run/%s"
#define OSDP_LCL_UNIX_SOCKET    OSDP_BASE_DIR "/run/%s/open-osdp-control"

#define OSDP_LCL_DEFAULT_PSK    "speakFriend&3ntr"

#define OSPD_LCL_SET_PID_TEMPLATE \
  OSDP_BASE_DIR "/bin/set-pid %s %d"

