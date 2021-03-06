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

#include "open-osdp.h"

// the server key and cert for the OSDP TLS server

#define OSDP_LCL_CA_KEYS "/opt/osdp-conformance/etc/ca_keys.pem"
#define OSDP_LCL_SERVER_CERT "/opt/osdp-conformance/etc/cert.pem"
#define OSDP_LCL_SERVER_KEY "/opt/osdp-conformance/etc/key.pem"


#if ENABLE_WEB_RPC
#define OSDP_LCL_COMMAND_PATH "/opt/osdp-conformance/run/%s/open_osdp_command.json"
#define OSDP_LCL_SERVER_RESULTS "/opt/osdp-conformance/run/%s"
#define OSDP_LCL_UNIX_SOCKET "/opt/osdp-conformance/run/%s/open-osdp-control"
#define OSDP_BASE_DIR "/opt/osdp-conformance/"
#else
#define OSDP_LCL_COMMAND_PATH "./tmp/command_%s.json"
#define OSDP_LCL_SERVER_RESULTS "./tmp/result_%s"
#define OSDP_LCL_UNIX_SOCKET "./tmp/socket_%s"
#define OSDP_BASE_DIR "./tmp/"
#endif

#define OSDP_LCL_DEFAULT_PSK "speakFriend&3ntr"

#define OSPD_LCL_SET_PID_TEMPLATE "/opt/osdp-conformance/bin/set-pid %s %d"
