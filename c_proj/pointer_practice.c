//sudo gcc –o hexdecinput hexdecinput.c

#include<stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>

static void getValue(uint16_t * val);
static void returnValThruPtr(uint16_t * val);

static void getValue(uint16_t * val)
{
    returnValThruPtr(val);
    printf("val is %d or 0x%x\n", *val, *val);
    /*
    uint16_t temp = 0;
    returnValThruPtr(&temp);
    printf("temp is %d or 0x%x\n", temp, temp);
    val[0] = temp;
    printf("val is %d or 0x%x\n", val[0], val[0]);
    */
}

static void returnValThruPtr(uint16_t * val)
{
    *val = 0x1234;
    return;
}


int main()
{
    uint16_t value = 0;

    getValue(&value);
    printf("value is %d or 0x%x\n", value, value);
}