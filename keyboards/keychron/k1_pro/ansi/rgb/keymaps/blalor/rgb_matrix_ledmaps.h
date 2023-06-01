/* Copyright 2021 Mikael Manukyan <arm.localhost@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

#ifdef RGB_MATRIX_LEDMAPS_ENABLED

// no association keycode
#    define XXX \
        { 0, 0, 0 }

// clang-format off
#   define RGB_MATRIX_LAYOUT_LEDMAP( \
        k0,     k1,      k2,      k3,      k4,      k5,      k6,      k7,       k8,       k9,       k10,      k11,      k12,                k13,      k14,      k16, \
        k17,    k18,     k19,     k20,     k21,     k22,     k23,     k24,      k25,      k26,      k27,      k28,      k29,      k30,      k31,      k33,      k34, \
        k35,    k36,     k37,     k38,     k39,     k40,     k41,     k42,      k43,      k44,      k45,      k46,      k47,      k48,      k50,      k51,      k52, \
        k53,    k54,     k55,     k56,     k57,     k58,     k59,     k60,      k61,      k49,      k62,      k15,                k32,                               \
        k63,             k64,     k65,     k66,     k67,     k68,     k69,      k70,      k71,      k72,      k73,                k74,                k86,           \
        k75,    k76,     k77,                                k78,                                   k79,      k80,      k81,      k82,      k83,      k84,      k85  \
    ) \
    { \
         k0,  k1,  k2,  k3,  k4,  k5,  k6,  k7,  k8,  k9, k10, k11, k12,      k13, k14, \
        k16, k17, k18, k19, k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k30, k31, \
        k33, k34, k35, k36, k37, k38, k39, k40, k41, k42, k43, k44, k45, k46, k47, k48, \
        k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k60, k61, k49, k62, k15, k32, \
        k63,      k64, k65, k66, k67, k68, k69, k70, k71, k72, k73,      k74, k86, k75, \
        k76, k77, k78,                k79,                k80, k81, k82, k83, k84, k85  \
    }
// clang-format on
typedef uint8_t ledmap[RGB_MATRIX_LED_COUNT][3];
extern const ledmap ledmaps[];

void set_layer_rgb(uint8_t led_min, uint8_t led_max, int layer);

void rgb_matrix_layers_enable(void);
void rgb_matrix_layers_disable(void);

// Just some handy defines to make our ledmaps look better
# define AZURE  { RGB_AZURE }
# define BLUE   { RGB_BLUE }
# define CHARTR { RGB_CHARTREUSE }
# define CORAL  { RGB_CORAL }
# define CYAN   { RGB_CYAN }
# define GOLD   { RGB_GOLD }
# define GLDNRD { RGB_GOLDENROD }
# define GREEN  { RGB_GREEN }
# define MAGENT { RGB_MAGENTA }
# define ORANGE { RGB_ORANGE }
# define PINK   { RGB_PINK }
# define PURPLE { RGB_PURPLE }
# define RED    { RGB_RED }
# define SPNGRN { RGB_SPRINGGREEN }
# define TEAL   { RGB_TEAL }
# define TURQ   { RGB_TURQUOISE }
# define WHITE  { RGB_WHITE }
# define YELLOW { RGB_YELLOW }

#endif  // RGB_MATRIX_LEDMAPS_ENABLED

bool rgb_matrix_indicators_keymap(void);
bool rgb_matrix_indicators_advanced_keymap(uint8_t led_min, uint8_t led_max);
