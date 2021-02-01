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

static uint8_t isUserSequenceValid(uint16_t newSeq, uint16_t currentSeq);

static uint8_t isUserSequenceValid(uint16_t newSeq, uint16_t currentSeq)
{
    if ((newSeq < currentSeq + MAX_SEQUENCE_VARIANCE) &&
            (currentSeq > MIN_ROLLOVER_VALUE))
    {
        printf("Valid rollover\n");
        return 0;
    }
    else if ((newSeq > currentSeq) && (newSeq <= (currentSeq + MAX_SEQUENCE_VARIANCE)))
    {
        printf("Value good\n");
        return 0;
    }

    printf("Value invalid\n");
    return 1;
}


int main()
{
    uint16_t prevVal = 0x0000;
    uint16_t newVal = 0x000a;
    uint8_t isValid = 0;

    isValid = isUserSequenceValid(newVal, prevVal);
    printf("Status is %d\n", isValid);
    printf("0x%02x\n", 0x0000 - 11);


}