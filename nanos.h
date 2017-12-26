#ifndef _NANOS_H_
#define _NANOS_H_

#define ORIGIN_RAM   0x20000000
#define LENGTH_RAM   6K

#define ORIGIN_STACK 0x2000083c

#define SYMBOL_TABLE \
    GENERATE_BRANCH(io_seproxyhal_send,     0x08004b5c, 0xFF, 0xF7, 0x36, 0xFC) \
    GENERATE_BRANCH(bagl_draw_with_context, 0x08004fe0, 0xFE, 0xF7, 0x28, 0xFD) \
    \
    GENERATE_FUNCTION(udivsi3, 0x080061a8, 0x08002984, 266) \
    GENERATE_FUNCTION(memcpy,  0x08006310, 0x08002a9c, 124)

#define PROVIDE_TABLE \
    PROVIDE_FUNCTION(bagl_draw_with_context, 0x08003a35) \
    PROVIDE_FUNCTION(io_seproxyhal_send,     0x080043cd) \
    PROVIDE_FUNCTION(HAL_Delay,              0x08005295)

#endif /* _NANOS_H_ */
