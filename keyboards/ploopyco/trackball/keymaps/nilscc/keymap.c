#include QMK_KEYBOARD_H

enum layers {
    BASE,
    RAISE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_BTN1, KC_BTN3, KC_BTN2, MO(RAISE), XXXXXXX
    ),

    [RAISE] = LAYOUT(
        KC_BTN4, KC_BTN3, KC_BTN5, XXXXXXX, XXXXXXX
    ),
};

static bool scrolling_mode = false;

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case RAISE:  // If we're on the RAISE layer enable scrolling mode
            scrolling_mode = true;
            break;
        default:
            if (scrolling_mode) {  // check if we were scrolling before and set disable if so
                scrolling_mode = false;
            }
            break;
    }
    return state;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (scrolling_mode) {

        // higher scale slower scrolling
        static const int16_t scale = 32;

        static int16_t acc_h = 0;
        static int16_t acc_v = 0;

        // axis snapping
        if (abs(mouse_report.x) > abs(mouse_report.y)) {
            acc_h += mouse_report.x;
            mouse_report.h = acc_h / scale;
            mouse_report.v = 0;
            acc_h %= scale;
        } else {
            acc_v -= mouse_report.y;
            mouse_report.h = 0;
            mouse_report.v = acc_v / scale;
            acc_v %= scale;
        }

        // clear the X and Y values of the mouse report
        mouse_report.x = 0;
        mouse_report.y = 0;
    }
    return mouse_report;
}
