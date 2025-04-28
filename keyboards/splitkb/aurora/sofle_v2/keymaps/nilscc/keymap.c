#include QMK_KEYBOARD_H

// For controlling the power LED
#include "gpio.h"

static const uint16_t A = KC_A;
static const uint16_t B = KC_B;
static const uint16_t C = KC_C;
static const uint16_t D = KC_D;
static const uint16_t E = KC_E;
static const uint16_t F = KC_F;
static const uint16_t G = KC_G;
static const uint16_t H = KC_H;
static const uint16_t I = KC_I;
static const uint16_t J = KC_J;
static const uint16_t K = KC_K;
static const uint16_t L = KC_L;
static const uint16_t M = KC_M;
static const uint16_t N = KC_N;
static const uint16_t O = KC_O;
static const uint16_t P = KC_P;
static const uint16_t Q = KC_Q;
static const uint16_t R = KC_R;
static const uint16_t S = KC_S;
static const uint16_t T = KC_T;
static const uint16_t U = KC_U;
static const uint16_t V = KC_V;
static const uint16_t W = KC_W;
static const uint16_t X = KC_X;
static const uint16_t Y = KC_Y;
static const uint16_t Z = KC_Z;

/*
 * Main keymapping
 *
 */

// Use enum for layer sorting, as done in:
// https://github.com/qmk/qmk_firmware/blob/fa98117a3e10afed347f16b2614e4e8a9e26cd32/keyboards/planck/rev7/keymaps/default/keymap.c
enum nilscc_layers {
    _COLEMAK,
    _NORDRASSIL,

    // special layers
    _NAVIGATION,
    _NUMBERS,
    _SYMBOLS,
    _FUNCTIONS,

    // legacy/default layers
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define NUMBERS MO(_NUMBERS)
#define SYMBOLS MO(_SYMBOLS)
#define NAVIGATION MO(_NAVIGATION)
#define NAV NAVIGATION

#define COLEMAK PDF(_COLEMAK)
#define NRDRSSL PDF(_NORDRASSIL)

#define GUI_A LGUI_T(KC_A)
#define ALT_R ALT_T(KC_R)
#define SFT_S LSFT_T(KC_S)
#define CTL_T_ LCTL_T(KC_T)
#define CTL_A LCTL_T(KC_A)

#define GUI_O RGUI_T(KC_O)
#define ALT_I ALT_T(KC_I)
#define RALT_Y RALT_T(KC_Y)
#define SFT_E RSFT_T(KC_E)
#define CTL_N RCTL_T(KC_N)

#define NUM_SPC     LT(_NUMBERS,        KC_SPC)
#define NAV_BS      LT(_NAVIGATION,     KC_BSPC)
#define NAV_T       LT(_NAVIGATION,     KC_T)
#define SYM_ENT     LT(_SYMBOLS,        KC_ENT)
#define SYM_BS      LT(_SYMBOLS,        KC_BSPC)
#define SYM_T       LT(_SYMBOLS,        KC_T)
#define FN_REP      LT(_FUNCTIONS,      QK_REP)

// umlaut tap-hold defines: regular key on tap, umlaut variant on hold.
// needs to be defined as one of the mod-tap keys, even though its behaviour is
// overwritten in process_record_user!
#define UL_A ALGR_T(KC_A)
#define UL_O ALGR_T(KC_O)
#define UL_U ALGR_T(KC_U)
#define UL_S ALGR_T(KC_S)
#define UL_E ALGR_T(KC_E) // for euro signs

#define ALGR_A ALGR(KC_Q) // match us intl layout
#define ALGR_U ALGR(KC_Y)
#define ALGR_O ALGR(KC_P)
#define ALGR_S ALGR(KC_S)
#define ALGR_E ALGR(KC_5) // euro sign

enum custom_key_codes {
    KVM_1 = SAFE_RANGE,
    KVM_2,
    KVM_3,
    KVM_4,
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //
    // base layers
    //

    // default colemak-dh
    [_COLEMAK] = LAYOUT(
        LOWER,      KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       RAISE,
        KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,                               KC_J,       KC_L,       KC_U,       RALT_Y,     KC_QUOT,    KC_DEL,
        KC_GRV,     KC_A,       KC_R,       SFT_S,      CTL_T_,     KC_G,                               KC_M,       CTL_N,      SFT_E,      KC_I,       KC_O,       KC_SCLN,
        KC_LSFT,    KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,       XXXXXXX,    XXXXXXX,    KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                KC_LGUI,    KC_LALT,    KC_ESC,     NUM_SPC,    KC_ESC,     SYM_ENT,    NAV_BS,     KC_DEL,     KC_RALT,    KC_RGUI
    ),

    // abyssal nordrassil with basic repeat key (no arcane). also shifted z into left hand and moved x
    //
    // q y o u -   j g n w k
    // h i e a .   p d r s l z      =>      h i e a .   p d r s l /
    // x / ' , ;   b c m f v        =>      z x ' , ;   b c m f v
    //       ␣ *     t
    //
    // See: https://github.com/empressabyss/nordrassil
    //
    [_NORDRASSIL] = LAYOUT(
        KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_SLSH,
        KC_TAB,     Q,          Y,          UL_O,       UL_U,       KC_MINS,                            J,          G,          N,          W,          K,          KC_BSPC,
        KC_ESC,     H,          I,          UL_E,       UL_A,       KC_DOT,                             P,          D,          R,          UL_S,       L,          KC_ENT,
        KC_LSFT,    Z,          X,          KC_QUOT,    KC_COMM,    KC_SCLN,    XXXXXXX,    XXXXXXX,    B,          C,          M,          F,          V,          KC_RSFT,
                                KC_LGUI,    KC_LALT,    KC_LCTL,    QK_REP,     NUM_SPC,    SYM_T,      NAV,        KC_RCTL,    KC_RALT,    KC_DEL
    ),

    //
    // special layers
    //

    [_NUMBERS] = LAYOUT(
        _______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
        _______,    _______,    _______,    _______,    _______,    _______,                            KC_NUM,     KC_7,       KC_8,       KC_9,       KC_PSLS,    KC_F12,
        _______,    KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    KC_PSCR,                            KC_PPLS,    KC_4,       KC_5,       KC_6,       KC_PDOT,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_PMNS,    KC_1,       KC_2,       KC_3,       KC_PAST,    _______,
                                _______,    _______,    _______,    _______,    _______,    KC_PENT,    KC_0,       _______,    _______,    _______
    ),

    [_FUNCTIONS] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,                            _______,    KC_7,       KC_8,       KC_9,       _______,    _______,
        _______,    KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    _______,                            _______,    KC_4,       KC_5,       KC_6,       _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_1,       KC_2,       KC_3,       _______,    _______,
                                _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_0,       _______,    _______
    ),

    [_NAVIGATION] = LAYOUT(
        _______,    COLEMAK,    NRDRSSL,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,                            KC_GRV,     KC_TAB,     KC_LSFT,    KC_LALT,    _______,    _______,
        _______,    KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    _______,                            KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,    _______,
        _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     KC_INS,     _______,
                                _______,    _______,    _______,    _______,    _______,    _______,    _______,    KC_DEL,     _______,    _______
    ),

    [_SYMBOLS] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
        _______,    XXXXXXX,    XXXXXXX,    KC_LBRC,    KC_RBRC,    KC_PLUS,                            _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_SLSH,    KC_BSLS,    KC_LPRN,    KC_RPRN,    KC_EQL,                             _______,    KC_LCTL,    KC_LSFT,    KC_LALT,    KC_LGUI,    _______,
        _______,    XXXXXXX,    KC_PIPE,    KC_LCBR,    KC_RCBR,    XXXXXXX,    _______,    _______,    _______,    KC_COLN,    _______,    _______,    _______,    _______,
                                _______,    _______,    KC_QUOT,    KC_TAB,     KC_ENT,     _______,    _______,    _______,    _______,    _______
    ),

    //
    // Legacy layers
    //

    /* Lower layer */
    [_LOWER] = LAYOUT(
        KC_BSPC,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,
        KC_DEL,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_F12,
        _______,    KC_EXLM,    KC_AT,      KC_LCBR,    KC_RCBR,    KC_PERC,                            KC_CIRC,    KC_LPRN,    KC_RPRN,    KC_AMPR,    KC_ASTR,    KC_PIPE,
        _______,    KC_DLR,     KC_EQL,     KC_MINS,    KC_PLUS,    KC_HASH,    _______,    _______,    KC_COLN,    KC_LBRC,    KC_RBRC,    KC_SCLN,    KC_BSLS,    _______,
                                _______,    _______,    _______,    _______,    _______,    _______,    ADJUST,      _______,    _______,    _______
    ),


    /* Raised layer */
    [_RAISE] = LAYOUT(
        _______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
        _______,    KC_INS,     KC_PSCR,    KC_APP,     XXXXXXX,    KC_SCRL,                            KC_PGUP,    C(KC_LEFT), KC_UP,      C(KC_RGHT), C(KC_BSPC), KC_BSPC,
        _______,    KC_LALT,    KC_LCTL,    KC_LSFT,    XXXXXXX,    KC_CAPS,                            KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_DEL,     KC_BSPC,
        _______,    C(KC_Z),    C(KC_X),    C(KC_C),    C(KC_V),    XXXXXXX,    _______,    _______,    XXXXXXX,    KC_HOME,    XXXXXXX,    KC_END,     XXXXXXX,    _______,
                                _______,    _______,    _______,    ADJUST,     _______,    _______,    _______,    _______,    _______,    _______
    ),

    /* Adjustment layer */
    [_ADJUST] = LAYOUT(
        XXXXXXX,    KVM_1,      KVM_2,      KVM_3,      KVM_4,      XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                            XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    RM_TOGG,    RM_HUEU,    RM_SATU,    RM_VALU,    XXXXXXX,                            XXXXXXX,    KC_VOLD,    KC_MUTE,    KC_VOLU,    XXXXXXX,    XXXXXXX,
        XXXXXXX,    RM_NEXT,    RM_HUED,    RM_SATD,    RM_VALD,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_MPRV,    KC_MPLY,    KC_MNXT,    XXXXXXX,    XXXXXXX,
                                _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______
    )

};

// Define encoder mapping
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

    // base layers
    [_COLEMAK]    = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(MS_WHLU, MS_WHLD)  },
    [_NORDRASSIL] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(MS_WHLU, MS_WHLD)  },

    // special layers
    [_NAVIGATION] = { ENCODER_CCW_CW(RM_VALD, RM_VALU),  ENCODER_CCW_CW(RM_SATD, RM_SATU)  },
    [_NUMBERS]    = { ENCODER_CCW_CW(RM_SATD, RM_SATU),  ENCODER_CCW_CW(RM_HUED, RM_HUEU)  },
    [_FUNCTIONS]  = { ENCODER_CCW_CW(RM_SATD, RM_SATU),  ENCODER_CCW_CW(RM_HUED, RM_HUEU)  },
    [_SYMBOLS]    = { ENCODER_CCW_CW(RM_PREV, RM_NEXT),  ENCODER_CCW_CW(RM_SPDD, RM_SPDU)  },

    // legacy layers
    [_LOWER]  = { ENCODER_CCW_CW(UG_HUED, UG_HUEU),  ENCODER_CCW_CW(UG_SATD, UG_SATU)  },
    [_RAISE]  = { ENCODER_CCW_CW(UG_VALD, UG_VALU),  ENCODER_CCW_CW(UG_SPDD, UG_SPDU)  },
    [_ADJUST] = { ENCODER_CCW_CW(UG_PREV, UG_NEXT),  ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif
/* clang-format on */

// static void switch_kvm(uint16_t screen) {
//     tap_code(KC_SCRL);
//     SEND_STRING(SS_DELAY(200));
//     tap_code(KC_SCRL);
//     SEND_STRING(SS_DELAY(200));
//     tap_code(screen);
// }

static bool tap_hold(keyrecord_t *record, uint16_t tap, uint16_t hold) {
    if (record->event.pressed) {
        // check caps word state
        if (is_caps_word_on())
        {
            add_weak_mods(MOD_BIT(KC_LSFT));
        }
        tap_code16(record->tap.count ? tap : hold);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case UL_A: return tap_hold(record, KC_A, ALGR_A);
        case UL_U: return tap_hold(record, KC_U, ALGR_U);
        case UL_O: return tap_hold(record, KC_O, ALGR_O);
        case UL_S: return tap_hold(record, KC_S, ALGR_S);
        case UL_E: return tap_hold(record, KC_E, ALGR_E);
        default: break;
    }
    return true;
}

// shift only symbols on alpha layer of nordrassil layout
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_MINS:
        case KC_DOT:
        case KC_QUOT:
        case KC_COMM:
        case KC_SCLN:
            return true;
        default:
            return false;
    }
}

// Disable power LED of liatris board
void keyboard_pre_init_user(void) {
    gpio_set_pin_output(24);
    gpio_write_pin_high(24);
}
