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

void bytePrint(union Byte byte) {
    printf("%d%d%d%d%d%d%d%d\n", byte.bitfield.b7, byte.bitfield.b6, byte.bitfield.b5, byte.bitfield.b4, byte.bitfield.b3,
                                 byte.bitfield.b2, byte.bitfield.b1, byte.bitfield.b0);
}

union Descriptor {
    uint64_t value;
    struct {
        uint64_t first: 1;
        uint64_t area: 25;
        uint64_t middle: 1;
        uint64_t some: 10;
        uint64_t end: 27;
    } bitfield;
};

void descPrint(union Descriptor desc) {
    printf("first: %x\n", desc.bitfield.first);
    printf("area: %x\n", desc.bitfield.area);
    printf("middle: %x\n", desc.bitfield.middle);
    printf("some: %x\n", desc.bitfield.some);
    printf("end: %x\n", desc.bitfield.end);
    printf("\n");
}

int main() {
    printf("Simple using bitfield:\n\n");
    union Byte byte;
    byte.value = 5;
    bytePrint(byte); // 00000101
    printf("byte.value: %d\n", byte.value); // 5
    byte.bitfield.b0 = 0; 
    bytePrint(byte); // 00000100
    printf("byte.value: %d\n", byte.value); // 4
    byte.bitfield.b6 = 1; 
    byte.bitfield.b7 = 1; 
    bytePrint(byte); // 11000100
    printf("byte.value: %d\n", byte.value); // 196

    printf("\nComplex using bitfield:\n\n");
    union Descriptor descriptor;
    descriptor.value = 0xffa9134342A01f85;
    descPrint(descriptor);
    descriptor.value = 0;
    descriptor.bitfield.first = 1;
    descriptor.bitfield.area = 0x1FFFFFF;
    printf("area <- %x\n", 0x1FFFFFF);
    descriptor.bitfield.some = 5;
    descriptor.bitfield.end = 0x7FE7CFF;
    printf("end <- %x\n", 0x7FE7CFF);
    descPrint(descriptor);
    return 0;
}
