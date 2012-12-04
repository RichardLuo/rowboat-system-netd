/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _NAT_CONTROLLER_H
#define _NAT_CONTROLLER_H

#include <linux/in.h>

#include "SecondaryTableController.h"

class NatController {

public:
    NatController(SecondaryTableController *ctrl);
    virtual ~NatController();

    int enableNat(const int argc, char **argv);
    int disableNat(const int argc, char **argv);
    int setupIptablesHooks();

    static const char* LOCAL_FORWARD;
    static const char* LOCAL_NAT_POSTROUTING;

private:
    int natCount;
    SecondaryTableController *secondaryTableCtrl;

    int setDefaults();
    int runCmd(const char *path, const char *cmd);
    bool checkInterface(const char *iface);
    int setForwardRules(bool set, const char *intIface, const char *extIface);
};

#endif
