//sudo gcc –o forloops forloops.c

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
    uint8_t i = 16;
    uint8_t max = 16;

    printf("Usual: \t");
    for (i = max; i-- > 0;)
    {
        printf("%02x ", i);
    }

    printf("\nNew: \t");
    for (i = max; i-- > 0;)
    {
        printf("%02x ", i);
    }
    printf("\n");

}

