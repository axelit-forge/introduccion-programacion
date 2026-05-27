#include "bitwise_utils.h"




bitmask_t bitmask_set(bitmask_t mask, uint8_t bit_pos) {
    return mask | (1ULL << bit_pos);
}

bitmask_t bitmask_clear(bitmask_t mask, uint8_t bit_pos) {
    return mask & ~(1ULL << bit_pos);
}

bool bitmask_check(bitmask_t mask, uint8_t bit_pos) {
    bool bit = (mask >> bit_pos) & 1;
    return bit;
}

bitmask_t bitmask_toggle(bitmask_t mask, uint8_t bit_pos) {
    return mask ^ (1ULL << bit_pos);
}
