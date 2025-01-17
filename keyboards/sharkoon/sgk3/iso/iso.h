/* Copyright 2022 HorrorTroll <https://github.com/HorrorTroll>
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

#define XXX KC_NO

/* ┌───┐   ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┬───┐ ┌───┬───┬───┐
 * │00 │   │01 │02 │03 │04 │ │05 │06 │07 │08 │ │09 │0A │0B │0C │ │0E │0F │0G │
 * └───┘   └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┴───┘ └───┴───┴───┘
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐ ┌───┬───┬───┐ ┌───┬───┬───┬───┐
 * │10 │11 │12 │13 │14 │15 │16 │17 │18 │19 │1A │1B │1C │1D     │ │1E │1F │1G │ │1H │1I │1J │1K │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤ ├───┼───┼───┤ ├───┼───┼───┼───┤
 * │20   │21 │22 │23 │24 │25 │26 │27 │28 │29 │2A │2B │2C │     │ │2E │2F │2G │ │2H │2I │2J │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐3D  │ └───┴───┴───┘ ├───┼───┼───┤2K │
 * │30    │31 │32 │33 │34 │35 │36 │37 │38 │39 │3A │3B │2D │    │               │3H │3I │3J │   │
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┤     ┌───┐     ├───┼───┼───┼───┤
 * │40  │41 │42 │43 │44 │45 │46 │47 │48 │49 │4A │4B │4D        │     │4F │     │4H │4I │4J │   │
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬────┤ ┌───┼───┼───┐ ├───┴───┼───┤4K │
 * │50  │51  │52  │53                      │54  │55  │56  │58  │ │5E │5F │5G │ │5I     │5J │   │
 * └────┴────┴────┴────────────────────────┴────┴────┴────┴────┘ └───┴───┴───┘ └───────┴───┴───┘
 */

#define LAYOUT_fullsize_iso( \
    K00,      K01, K02, K03, K04,   K05, K06, K07, K08,    K09, K0A, K0B, K0C,  K0E, K0F, K0G,                      \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C,    K1D,    K1E, K1F, K1G,  K1H, K1I, K1J, K1K, \
     K20,  K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C,          K2E, K2F, K2G,  K2H, K2I, K2J, K2K, \
      K30,   K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K2D, K3D,                   K3H, K3I, K3J,      \
    K40,  K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B,      K4D,           K4F,       K4H, K4I, K4J, K4K, \
    K50,  K51,  K52,                K53,                K54,  K55,  K56,  K58,  K5E, K5F, K5G,     K5I,   K5J       \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, XXX, K0E, K0F, K0G, XXX, XXX, XXX, XXX }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K }, \
    { K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, XXX, K3D, XXX, XXX, XXX, K3H, K3I, K3J, XXX }, \
    { K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, XXX, K4D, XXX, K4F, XXX, K4H, K4I, K4J, K4K }, \
    { K50, K51, K52, K53, K54, K55, K56, XXX, K58, XXX, XXX, XXX, XXX, XXX, K5E, K5F, K5G, XXX, K5I, K5J, XXX }  \
}
