#include <inttypes.h>

typedef enum {
    BIG_ENDIAN,
    LITTLE_ENDIAN
} Endianness;

Endianness get_endianness();

int main()
{
    Endianness endianness = get_endianness();
    return 0;
}

/* This function determines whether the host device is Big-Endian or
 * Little-Endian.
 */
Endianness get_endianness()
{
    Endianness result;
    uint16_t value = 0x1234;
    // Look at first byte of 2 byte unsigned integer.
    uint8_t first_byte = *((uint8_t*)(&value));
    if (first_byte == 0x12) {
        // The first byte is not the LSB.
        result = BIG_ENDIAN;
    } else if (first_byte == 0x34){
        // The first byte is the LSB.
        result = LITTLE_ENDIAN;
    }
    return result;
}
