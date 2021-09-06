/* Copyright 2018 Canaan Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __GC0328_H
#define __GC0328_H

#include <stdint.h>

#define GC0328_ID (0x9d)
#define GC0328_ADDR (0x42)
#define SCCB_ID 0x42

extern uint32_t g_lcd_gram0[38400] __attribute__((aligned(64)));
extern uint32_t g_lcd_gram1[38400] __attribute__((aligned(64)));

extern volatile uint8_t g_dvp_finish_flag;
extern volatile uint8_t g_ram_mux;
void camera_init(void);
#define FRAMESIZE_QQVGA 1

#endif /* __GC0328_H */
