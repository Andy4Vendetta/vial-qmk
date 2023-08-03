#include QMK_KEYBOARD_H
#include "oled/bongocat.c"
/* #include "oled/luna.c" */
#include "kissetfall.h"


enum custom_keycodes {
    NEXTSEN = QK_KB,
    PREDL, 
    BRACES,
    PARENTH 
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
      [_BASE] = LAYOUT(
         KC_F1,   KC_F2, KC_F3,   KC_F4,   KC_F5,   KC_F6,                               KC_F7, KC_F8,   KC_F9,   KC_F10, KC_F11,  KC_F12,
         KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,  KC_U,    KC_I,    KC_O,   KC_P,    KC_GRV,
         QK_LEAD, KC_A,  KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,  KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT,
         KC_ESC,  KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,  KC_M,    KC_COMM, KC_DOT, KC_QUOT, KC_MPLY,
                   LALT(KC_LSFT), KC_LSFT, KC_LCTL, LOWER, KC_SPC,              KC_BSPC, RAISE, KC_RSFT, KC_RALT,  KC_RGUI 
                                               
      ),
    
      [_LOWER] = LAYOUT(
    
         _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______,  _______,
         _______, KC_3,    KC_2,    KC_1,    KC_0,    KC_4,                              KC_7,    KC_6,    KC_5,    KC_9,    KC_8,     _______,
         KC_ENT,  APP_A,   APP_S,   APP_D,   LALT(KC_TAB),  APP_G,                       _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
         _______, KC_LALT, APP_X,   APP_C,   APP_V,   APP_B,                             _______, PREVWRD, KC_PGDN, KC_PGUP, NEXTWRD,  _______,
                           KC_VOLD, KC_VOLU, _______, _______, _______,         _______, ADJUST, _______, _______, _______ 
    
      ),
    
     [_RAISE] = LAYOUT(
         _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
         _______, _______, KC_AT,   KC_EQL,  KC_PLUS, KC_LPRN,                           KC_RPRN, _______, KC_UNDS, KC_PERC, _______, _______,
         _______, KC_BSLS, KC_DLR,  KC_MINS, KC_HASH, KC_LBRC,                           KC_RBRC, KC_QUES, KC_SCLN, KC_CIRC, KC_EXLM, _______,
         _______, _______, KC_ASTR, KC_COLN, KC_SLSH, KC_LCBR,                           KC_RCBR, KC_PIPE, KC_TILD, KC_AMPR, _______, _______,
                           _______, _______, _______, ADJUST,  _______,         _______, _______, _______,  _______, _______ 
      ),
    
      [_ADJUST] = LAYOUT(
        QK_BOOT, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            KC_CAPS, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______                            
       ),
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // bongocat
    /* return OLED_ROTATION_270;  // luna */
  }
    else {
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
    }
  return rotation;
}

void render_layer_state(void) {
    // Print current mode
    oled_write_ln_P(PSTR("K:02\n"), false);
    /* oled_write_P(PSTR("\n"), false); */
    oled_write_ln_P(PSTR("v3.0\n"), false);
    oled_write_P(PSTR("\n"), false);
    oled_write_ln_P(PSTR("MODE\n"), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("Mac"), false);
    } else {
        oled_write_ln_P(PSTR("Win"), false);
    }

    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjst"), false);
            break;
        case _FOUR:
            oled_write_P(PSTR("Four\n"), false);
            break;
        case _FIVE:
            oled_write_P(PSTR("Five\n"), false);
            break;
        case _SIX:
            oled_write_P(PSTR("Six\n"), false);
            break;
        case _SEVEN:
            oled_write_P(PSTR("Seven"), false);
            break;
        case _EIGHT:
            oled_write_P(PSTR("Eight"), false);
            break;
        case _NINE:
            oled_write_P(PSTR("Nine\n"), false);
            break;
         case _TEN:
            oled_write_P(PSTR("Ten\n"), false);
            break;
         case _ELEVEN:
            oled_write_P(PSTR("Elevn"), false);
            break;
         case _TWELVE:
            oled_write_P(PSTR("Twlve"), false);
            break;
         case _THIRTEEN:
            oled_write_P(PSTR("Thrtn"), false);
            break;
         case _FOURTEEN:
            oled_write_P(PSTR("Frtn\n"), false);
            break;
         case _FIFTEEN:
            oled_write_P(PSTR("Fiftn"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}


// Used to draw on to the oled screen
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_layer_state();
    } else {
    render_bongocat();  // bongocat
    /* render_luna_status();  // luna */
}

    return false;
}

#endif

// custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        extern uint32_t tap_timer;
        tap_timer = timer_read32();
    }
    switch (keycode) {
    case NEXTSEN:  // Next sentence macro.
      if (record->event.pressed) {
        SEND_STRING(". ");
        add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
      }
      return false;

    case PREDL:  // Next sentence macro.
      if (record->event.pressed) {
        SEND_STRING("/ ");
        add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
      }
      return false;

       case BRACES:
            if (record->event.pressed) {
                uint8_t shifted = get_mods() & (MOD_MASK_SHIFT);
                    if (shifted) {
                        unregister_code(KC_LSFT);
                        unregister_code(KC_RSFT);
                        SEND_STRING("{}"SS_TAP(X_LEFT));
                    }
                    else {
                        SEND_STRING("[]"SS_TAP(X_LEFT));
                    }
            }
            break;

        case PARENTH:
            if (record->event.pressed) {
                SEND_STRING("()");
                tap_code(KC_LEFT);
            }
            break;
    }
 return true;
} 
