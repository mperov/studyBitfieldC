#include <stdint.h>
#include <stdio.h>
 
union Byte {
    uint8_t value;
    struct {
        uint8_t b0: 1;
        uint8_t b1: 1;
        uint8_t b2: 1;
        uint8_t b3: 1;
        uint8_t b4: 1;
        uint8_t b5: 1;
        uint8_t b6: 1;
        uint8_t b7: 1;
    } bitfield;
};

/* other variant
struct byte {
    uint8_t b0: 1;
    uint8_t b1: 1;
    uint8_t b2: 1;
    uint8_t b3: 1;
    uint8_t b4: 1;
    uint8_t b5: 1;
    uint8_t b6: 1;
    uint8_t b7: 1;
};
union Byte {
    uint8_t value;
    struct byte bitfield;
};
*/

void binPrint(union Byte byte) {
    printf("%d%d%d%d%d%d%d%d\n", byte.bitfield.b7, byte.bitfield.b6, byte.bitfield.b5, byte.bitfield.b4, byte.bitfield.b3,
                                 byte.bitfield.b2, byte.bitfield.b1, byte.bitfield.b0);
}

int main() {
    union Byte byte;
    byte.value = 5;
    binPrint(byte); // 00000101
    printf("byte.value: %d\n", byte.value); // 5
    byte.bitfield.b0 = 0; 
    binPrint(byte); // 00000100
    printf("byte.value: %d\n", byte.value); // 4
    byte.bitfield.b6 = 1; 
    byte.bitfield.b7 = 1; 
    binPrint(byte); // 11000100
    printf("byte.value: %d\n", byte.value); // 196
    return 0;
}
