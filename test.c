#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <stdlib.h>

void print_bits(uint8_t value);
int get_nth_bit(int value, int n);

int main(int argc, char *argv[]) {
    for (int i = -128; i < 128; i++) {
        printf("%4d ", i);
        print_bits(i);
        printf("\n");
    }

    return 0;
}


// Print binary representation of an int
void print_bits(uint8_t value) {
    
    // sizeof returns size in bytes and 1 byte == 8 bits
    int how_many_bits = 8 * (sizeof value);
    // print bits from most significant to least significant
    for (int i = how_many_bits - 1; i >= 0; i--) {
        int bit = get_nth_bit(value, i);
        printf("%d", bit);
    }
}

int get_nth_bit(int value, int n) {
    uint32_t unsigned_value = value;
    uint32_t shifted_value = unsigned_value >> n;
    int bit = shifted_value & 1;
    return bit;
}