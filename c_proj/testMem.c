//sudo gcc –o testMem testMem.c

#include<stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>


int main()
{
    uint8_t numBytes = 20;
    uint8_t i = 0;

    uint8_t * ptr = (uint8_t *) malloc(numBytes);
    if (ptr != NULL)
    {
        memset(ptr, 0x42, numBytes);

        for (i = 0; i < numBytes; i++)
        {
            if (ptr[i] != 0x42)
            {
                printf("broken");
                break;
            }
        }

        free(ptr);
    }
}

