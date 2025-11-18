/*------------------------------------------------------
* Filename: print_value_address.c
* Description: Program to receive an array of integers and an array of chars and print the value and address of every element.
* Author: Ori Harel
-------------------------------------------------------*/


#include <stdio.h>
#include <ctype.h>

#define ARRAY_SIZE 8

int main() {



    /*Define and initializr the array of integers and a pointer to its first term*/
    int arr_int[ARRAY_SIZE] = {0};
    int *p_int = &arr_int[0];

    /*Define and initialize the array of chars and a pointer to its first term*/
    char arr_char[ARRAY_SIZE] = {'0'};
    char *p_char = &arr_char[0];



    /*Receive an array of integers from user*/
    printf("Enter an array of %d integers\n", ARRAY_SIZE);
    for(int i = 0; i < ARRAY_SIZE; ++i) {
        scanf("%d", (p_int + i));
    }

    /*Receive an array of chars from user*/
    printf("Enter an array of %d chars (ALL IN ONE ROW)\n", ARRAY_SIZE);
    for(int i = 0; i < ARRAY_SIZE; ++i) {
        scanf("%c", &arr_char[i]);
    }





    /*Print the array of integers*/
    for(int i = 0; i < ARRAY_SIZE; ++i) {
        printf("Element number %d:\n", i);
        printf("Value: %d, Address: %X\n", arr_int[i], &arr_int[i]);
    }

    /*Print the array of chars*/
    for(int i = 0; i < ARRAY_SIZE; ++i) {
        printf("Element number %d:\n", i);
        printf("Value: %c, Address: %X\n", *(p_char + i),(char*) (p_char + i));
    }

    return 0;
}