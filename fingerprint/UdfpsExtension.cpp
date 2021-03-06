/*
 * Copyright (C) 2020 The LineageOS Project
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

#include <compositionengine/UdfpsExtension.h>
#include <vendor/oneplus/hardware/display/1.0/IOneplusDisplay.h>

#define OP_DISPLAY_SET_DIM 10

using ::android::sp;
using ::vendor::oneplus::hardware::display::V1_0::IOneplusDisplay;

static const sp<IOneplusDisplay> gVendorDisplayService = IOneplusDisplay::getService();

uint32_t getUdfpsZOrder(uint32_t z, bool touched) {
    gVendorDisplayService->setMode(OP_DISPLAY_SET_DIM, !!touched);
    return touched ? 0xfc8 : z;
}

uint64_t getUdfpsUsageBits(uint64_t usageBits, bool) {
    return usageBits;
}
