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

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
    _BASE,
    _FN,
};

enum user_rgb_mode {
    RGB_MODE_ALL,
    RGB_MODE_NONE,
};

typedef union {
    uint32_t raw;
    struct {
        uint8_t rgb_mode :8;
    };
} user_config_t;

user_config_t user_config;

enum layer_keycodes {
    GUI_LCK,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
       ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
       │ Esc │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Fn│ Del │
       ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴─┬───┤
       │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Bakspc│Hom│
       ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
       │ Tab │ q │ w │ e │ r │ t │ y │ u │ i │ o │ p │ [ │ ] │  \  │PgU│
       ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
       │ Caps │ a │ s │ d │ f │ g │ h │ j │ k │ l │ ; │ ' │  Enter │PgD│
       ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬────┬┴───┤
       │ LShift │ z │ x │ c │ v │ b │ n │ m │ , │ . │ / │RSft│  ↑ │ End│
       ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┼────┼────┼────┤
       │LCrl│GUI │LAlt│         Space          │RAlt│RCl│  ← │  ↓ │  → │
       └────┴────┴────┴────────────────────────┴────┴───┴────┴────┴────┘
       ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
       │     │   │   │   │   │   │   │   │   │   │   │   │   │   │     │
       ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴─┬───┤
       │ ~ │ ! │ @ │ # │ $ │ % │ ^ │ & │ * │ ( │ ) │ _ │ + │       │   │
       ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
       │     │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ { │ } │  |  │   │
       ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
       │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ : │ " │        │   │
       ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬────┬┴───┤
       │ LShift │ Z │ X │ C │ V │ B │ N │ M │ < │ > │ ? │RSft│    │    │
       ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┼────┼────┼────┤
       │    │    │    │                        │    │   │    │    │    │
       └────┴────┴────┴────────────────────────┴────┴───┴────┴────┴────┘
*/
    /*  Row:    0        1        2        3       4     5      6      7      8      9        10       11       12       13       14      */
    [_BASE] = LAYOUT(
                KC_ESC,  KC_F1,   KC_F2,   KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9,   KC_F10,  KC_F11,  KC_F12,  MO(_FN), KC_DEL,
                KC_GRV,  KC_1,    KC_2,    KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
                KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
                KC_CAPS, KC_A,    KC_S,    KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
                KC_LSFT,          KC_Z,    KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,
                KC_LCTL, KC_LGUI, KC_LALT,                      KC_SPC,                       KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RIGHT
            ),

/*
       ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬─────┐
       │Reset│Mut│MeP│Ply│VoD│VoU│Hom│Mai│Mod│Rod│Tog│Sad│Sai│   │ Ins │
       ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴─┬───┤
       │   │   │   │   │   │   │   │   │   │   │   │Spd│Spi│       │Pse│
       ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
       │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │
       ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
       │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
       ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴──┬────┬┴───┤
       │        │   │   │   │   │   │   │   │   │   │   │    │ Vai│Prts│
       ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┼────┼────┼────┤
       │    │TGUI│    │                        │    │   │ Hud│ Vad│ Hui│
       └────┴────┴────┴────────────────────────┴────┴───┴────┴────┴────┘
*/
    /*  Row:    0        1        2        3        4        5        6        7        8        9         10       11       12       13       14      */
    [_FN]   = LAYOUT(
                RESET,   KC_MUTE, KC_MSEL, KC_MPLY, KC_VOLD, KC_VOLU, KC_WHOM, KC_MAIL, RGB_MOD, RGB_RMOD, RGB_TOG, RGB_SAD, RGB_SAI, _______, KC_INS,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, RGB_SPD, RGB_SPI, _______, KC_PAUSE,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,          _______, _______,
                _______,          _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, RGB_VAI, KC_PSCR,
                _______, GUI_LCK, _______,                            _______,                             _______, _______, RGB_HUD, RGB_VAD, RGB_HUI
            ),
};

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    switch (user_config.rgb_mode) {
        case RGB_MODE_ALL:
            rgb_matrix_set_flags(LED_FLAG_ALL);
            rgb_matrix_enable_noeeprom();
            break;
        case RGB_MODE_NONE:
            rgb_matrix_set_flags(LED_FLAG_NONE);
            rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RGB_TOG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_set_color_all(0, 0, 0);
                        user_config.rgb_mode = RGB_MODE_NONE;
                    }
                    break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                        rgb_matrix_enable_noeeprom();
                        user_config.rgb_mode = RGB_MODE_ALL;
                    }
                    break;
                }
                eeconfig_update_user(user_config.raw);
            }
            return false;
        case GUI_LCK:
            if (record->event.pressed) {
                keymap_config.no_gui = !keymap_config.no_gui;
                break;
            }
            return false;
	}
    return true;
}

void rgb_matrix_indicators_user(void) {
    if ((rgb_matrix_get_flags() & LED_FLAG_ALL)) {
        if (keymap_config.no_gui) {
            rgb_matrix_set_color(74, 255, 0, 0);
        }
    } else {
        if (keymap_config.no_gui) {
            rgb_matrix_set_color(74, 255, 0, 0);
        } else {
            rgb_matrix_set_color(74, 0, 0, 0);
        }
    }
}
