/**
 * Copyright (c) 2016-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#pragma once

#define OPT_WARNINGS                                                     \
  OPT_WARN(NON_JUMBO_STRING, "Non-jumbo string encoded in jumbo opcode") \
  OPT_WARN(PURE_ABSTRACT_CLASS, "Pure abstract class passed to encode")  \
  OPT_WARN(UNSHORTENED_SRC_STRING, "Could not find replacement for src " \
                                   "string") \
  OPT_WARN(COLDSTART_STATIC, "Unknown method in coldstart list")

enum OptWarning {
#define OPT_WARN(warn, str) warn,
  OPT_WARNINGS
#undef OPT_WARN
};

enum OptWarningLevel {
  NO_WARN,
  WARN_COUNT,
  WARN_FULL,
};

extern OptWarningLevel g_warning_level;

void opt_warn(OptWarning warn, const char* fmt, ...);
void print_warning_summary();
