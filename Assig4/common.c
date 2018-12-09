/**
 * NWEN 241 Programming Assignment 4
 * common.c C Source File
 */

#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"


int is_number(char *str)
{
    while(*str != '\n' && *str != '0') {
        if(!isdigit(*str)) return FALSE;
        str++;
    }
    return TRUE;    
}


int force_integer_input(char *prompt, char *err_msg, int min, int max)
{
    int input = INT_MIN;
    char line[100];

    while(TRUE) {
        printf(prompt);
        fgets(line, 100, stdin);
        input = is_number(line) ? atoi(line) : INT_MIN;
        if(input >= min && input <= max)
            break;
        if(err_msg)
            printf(err_msg);
    }    
    return input;
}

int is_valid_char(char in, char *valid_chars, int len)
{
    int i=0;
    
    while(i < len) {
        if(in == valid_chars[i]) return TRUE;
        i++;
    }
    return FALSE;
}

char force_char_input(char *prompt, char *err_msg, char *valid_chars, int len)
{
    char line[100];

    while(TRUE) {
        printf(prompt);
        fgets(line, 100, stdin);
        if(strlen(line) == 2) 
            if (is_valid_char(line[0], valid_chars, len)) 
                return line[0];
        if(err_msg)
            printf(err_msg);
    }    
    /* Shouldn't reach this */
    return 0;
}
