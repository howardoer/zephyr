# Makefile - echo client test application

#
# Copyright (c) 2015 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

NET_IFACE ?= slip
MDEF_FILE = prj.mdef
KERNEL_TYPE = micro
BOARD ?= qemu_x86
CONF_FILE = prj_$(NET_IFACE).conf
SOURCE_DIR = $(ZEPHYR_BASE)/samples/net/echo_client/src/

include $(ZEPHYR_BASE)/Makefile.inc
include $(ZEPHYR_BASE)/samples/net/echo_server/Makefile.ipstack
