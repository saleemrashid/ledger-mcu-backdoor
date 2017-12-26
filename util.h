#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdint.h>
#include <stddef.h>

#if TARGET_NANOS
#include "nanos.h"
#endif

#define MAX_USB_BIDIR_ENDPOINTS
#include "seproxyhal.h"

#define SECTION(TYPE, NAME) __attribute__((section("." #TYPE "_" #NAME)))

#define TEXT(NAME)   SECTION(text,   NAME)
#define RODATA(NAME) SECTION(rodata, NAME)

extern void _real_bagl_draw_with_context(void *component, void *context, uint16_t context_length, uint8_t context_encoding);
extern void _real_io_seproxyhal_send(const uint8_t *buffer, uint16_t length);
extern void _real_HAL_Delay(volatile uint32_t Delay);

#endif /* _UTIL_H_ */
