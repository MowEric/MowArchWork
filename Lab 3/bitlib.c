#include <stdio.h>

/*
 * bitwise_nor  - implement ~(x | y) using only ~ and &.
 * Example biwise_nor(6, 5) = 0xFFFFFFF8
 * Max. # of operators: 8
 */
int bitwise_nor(int x, int y) {
    return (~x & ~y);
}


/*
 * bitwise_xor - implement (x ^ y) using only ~ and &.
 * Example bitwise_xor(4, 5) = 0x1
 * Max. # of operators: 14
 */
int bitwise_xor(int x, int y) {
    return (~x & y);
}


/*
 * eval_not_equal - implement (x != y)
 * using only !, ~, &, |, ^, +, << and >>,
 * returns 0 if x == y, otherwise 1.
 * Examples: eval_not_equal(2, 2) = 0, eval_not_equal(3, 4) = 1
 * Max. # of operators: 6
 */
int eval_not_equal(int x, int y) {
    return !((x ^ y) == 0);
}


/*
 * get_byte - extract byte n from 32-bit integer x
 * using only !, ~, &, |, ^, +, << and >>,
 * do not use any constant values of more than 1 byte in size,
 * assume ordering as 0 = least significant byte, 3 = most significant byte.
 * Example: get_byte(0x12345678, 1) = 0x56 (8 bits in a byte, 4 bits make up a hex)
 * Max. # of operators: 6
 */
int get_byte(int x, int n) {
    int ans = x>>n*8;
    return ans&0xff;
}

/*
 * copy_lsbit - set all bits of result value to the least significant bit of x
 * using only !, ~, &, |, ^, +, << and >>,
 * do not use any constant values of more than 1 byte in size.
 * Examples: copy_lsbit(5) = 0xFFFFFFFF, copy_lsbit(8) = 0x0
 * Max. # of operators: 5
 */
int copy_lsbit(int x) {
    int ans = ~(x & 1) +1;
    return ans;
}


/*
 * rightmost - return the rightmost bit set of x or 0 if x is equal to
 * 0 using only !, ~, &, |, ^, +, *, -, << and >>.
 * Examples: rightmost(0) = 0x0, righmost(1) = 0x1, rightmost(7) = 0x1,
 * rightmost(2) = 0x2, rightmost(16) = 0x10, rightmost(32) = 0x20
 * Max. # of operators: 5
 */
int rightmost(int x) {
    return x&0xff;
}


/*
 * bit_count - returns the # of bits in x that are 1
 * using only !, ~, &, |, ^, +, << and >>,
 * do not use any constant values of more than 1 byte in size.
 * Examples: bit_count(2) = 1, bit_count(10) = 2, bit_count(7) = 3
 * Max. # of operators: 40
 */
int bit_count(int x) {
    x = x - ((x >> 1) & 0x55555555);
    x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
    x = (x + (x >> 4)) & 0x0F0F0F0F;
    x *= 0x01010101;
    return  x >> 24; 
}
