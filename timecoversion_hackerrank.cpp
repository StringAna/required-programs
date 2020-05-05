/*
Given a time in -hour AM/PM format, convert it to military (24-hour) time.

Note: Midnight is 12:00:00AM on a 12-hour clock, and 00:00:00 on a 24-hour clock. Noon is 12:00:00PM on a 12-hour clock, and 12:00:00 on a 24-hour clock.

Function Description

Complete the timeConversion function in the editor below. It should return a new string representing the input time in 24 hour format.

timeConversion has the following parameter(s):

s: a string representing time in  hour format
Input Format

A single string  containing a time in -hour clock format (i.e.:  or ), where  and .

Constraints

All input times are valid
Output Format

Convert and print the given time in -hour format, where .

Sample Input 0

07:05:45PM
Sample Output 0

19:05:45


This question is from the problem solving module on Hackerrank.Although it seems really simple,and it is simple,
but I was stuck in char to int and int to char conversion. This is being uploaded so that I don't make the same
mistakes twice.
*/

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the timeConversion function below.
 */

/*
 * Please either make the string static or allocate on the heap. For example,
 * static char str[] = "hello world";
 * return str;
 *
 * OR
 *
 * char* str = "hello world";
 * return str;
 *
 */
char* timeConversion(char* s) {
    char temp[2];
    temp[0]=*(s+0);
    temp[1]=*(s+1);
    int t;

    if(*(s+8)=='A'){
        if(*(s+0)=='1' && *(s+1)=='2'){
            *(s+0)='0';
            *(s+1)='0';
        }
    }
    else{
        t=atoi(temp);
        if(t!=12){
            t=12+t;
        }    
        temp[1]=((t%10))+48;
       // t=t/10;
        temp[0]= (( t - (t%10) )/10)+48;
        *(s+0)=temp[0];
        *(s+1)=temp[1];
    }
    *(s+8) = 32;
    *(s+9) = 32;
    
    printf("\n%s\n",s);
    
    return s;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = (char*)malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data =(char*) realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = (char*)realloc(data, data_length);

    return data;
}

