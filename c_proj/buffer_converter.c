//sudo gcc –o hexdecinput hexdecinput.c

#include<stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>

#define MAX_SEQUENCE_VARIANCE        (10)
#define MIN_ROLLOVER_VALUE           (0xFFF5) //(0 - MAX_SEQUENCE_VARIANCE - 1)

static void convertUint16ToBuffer(uint16_t val, uint8_t * buffer);
static uint16_t convertBufferToUint16(uint8_t * buffer);
static uint64_t bufferToEpochHelper(uint8_t * buf, uint8_t bufSize);

static uint64_t bufferToEpochHelper(uint8_t * buf, uint8_t bufSize)
{
    if (bufSize != 8)
    {
        return 0;
    }

    uint8_t i = 0;
    uint64_t time = 0;
    printf("\n");
    for (i = 0; i < bufSize; i++)
    {
        time = time << 8 | buf[i];
        printf("0x%02x - 0x%llx\n", buf[i], time);
    }
    return time;
}

static void convertUint16ToBuffer(uint16_t val, uint8_t * buffer)
{
    printf("converting to buffer...");
    buffer[0] = (val >> 8);
    buffer[1] = (val & 0x00FF);
}

static uint16_t convertBufferToUint16(uint8_t * buffer)
{
    printf("converting to uint...");
    if (buffer != NULL)
    {
        //[0x12, 0x34] -> 0x1234
        return (buffer[0] << 8) | buffer[1];
    }
    return 0;
}


int main()
{
    uint16_t val = 0x1234;
    uint64_t time = 0;
    uint16_t unknown = 0;
    uint8_t buf[2] = {0x12, 0x34};
    uint8_t timeBuf[10] = {0xFF, 0x12, 0x34, 0x56, 0x78, 0xAA, 0xBB, 0xCC, 0xDD, 0xFF};
    uint8_t * buf2 = malloc (sizeof(uint16_t));

    unknown = convertBufferToUint16(buf);
    convertUint16ToBuffer(val, buf2);

    time = bufferToEpochHelper(timeBuf + 1, 8);
    printf("time is %llx\n", time);

    printf("uint16 is %x\n", unknown);
    printf("buffer is %x %x\n", buf2[0], buf2[1]);


}