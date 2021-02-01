//sudo gcc –o struct struct.c

#include<stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>

typedef struct ZWAVE_MSG_CACHE_METADATA_
{
    uint8_t cmdId;
    uint8_t cachedTimestamp;
} ZWAVE_MSG_CACHE_METADATA;

int main()
{
    ZWAVE_MSG_CACHE_METADATA * device = NULL;

    if (!device)
    {
        device = malloc(sizeof(ZWAVE_MSG_CACHE_METADATA));
        device->cmdId = 0x98;
        device->cachedTimestamp = 0x08;
    }

    printf("%d, %d\n", device->cmdId, device->cachedTimestamp);
    free(device);
}
