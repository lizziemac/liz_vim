//sudo gcc –o hexdecinput hexdecinput.c

#include<stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>

static uint16_t BUI_ProcessNumber(char * val);

uint16_t BUI_ProcessNumber(char * val)
{
    regex_t regex;
    char temp[255];
    char resp = '\0';
    memset(temp, 0, sizeof(temp));

    regcomp(&regex,"^[a-fA-F0-9]+$", REG_EXTENDED);

    printf("Hex or Decimal? (h/d)  ");
    scanf(" %c", &resp);

    if ((resp == 'h') || (resp == 'H'))
    {
        if(strncmp(val, "0x", 2) == 0)
        {
            if(regexec(&regex, val + 2, 0, NULL, 0) == 0)
            {
                sprintf(temp, "%s", val);
                return strtol(temp, NULL, 0);
            }
            else
            {
                printf("\nInvalid Input\n");
                return 0;
            }
        }
        else
        {
            if(regexec(&regex, val, 0, NULL, 0) == 0)
            {
                sprintf(temp, "0x%s", val);
                return strtol(temp, NULL, 0);
            }
        }
        printf("\nInvalid Input\n");
        return 0;
    }
    else if ((resp == 'd') || (resp == 'D'))
    {
        sprintf(temp, "%s", val);
        return atoi(temp);
    }

    printf("\nInvalid Input\n");
    return 0;
}

int main()
{
    char input[255] = "0x123fe";
    uint16_t value = 0;

    printf("Please input a value: ");
    scanf("%s", input);
    printf("\n");
    value = BUI_ProcessNumber(input);
    printf("value is %d or 0x%x\n", value, value);


}