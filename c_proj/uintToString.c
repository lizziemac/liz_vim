//sudo gcc –o uintTostring uintTostring.c

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
    uint8_t node = 0x1c;
    char str[12];

    sprintf(str, "%d", node);
    printf("\n%s, %lu, %lu\n", str, strlen(str), sizeof(uint8_t));
}