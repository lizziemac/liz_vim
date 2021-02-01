//sudo gcc –o mergeBuffers mergeBuffers.c

#include<stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>

static uint8_t mergeBufs(uint8_t * data, uint8_t dataSize, uint8_t ** finalBuf);

static uint8_t mergeBufs(uint8_t * data, uint8_t dataSize, uint8_t ** finalBuf)
{
    uint8_t number = 0x0c;
    uint8_t anotherBuf[] = {0x0a, 0x0b};
    uint8_t finalBufSize = (uint8_t)(dataSize + sizeof(number) + sizeof(anotherBuf));
    *finalBuf = malloc(finalBufSize);
    printf("merging buffers...data size=%d + %d + %d\n", dataSize,
            sizeof(number), sizeof(anotherBuf));

    memcpy(*finalBuf, &number, sizeof(number));
    memcpy(*finalBuf + 1, (uint8_t *)data, dataSize);
    memcpy(*finalBuf + dataSize + 1, (uint8_t *)anotherBuf, sizeof(anotherBuf));
    printf("%02x ", finalBufSize);

    return finalBufSize;
}

int main()
{
    uint8_t i = 0;
    uint8_t size = 0;
    uint8_t buf[2] = {0x12, 0x34};
    uint8_t * final = NULL;

    size = mergeBufs(buf, sizeof(buf), &final);

    for (i = 0; i < size; i++)
    {
        printf("%02x ", final[i]);
    }

    free(final);
}