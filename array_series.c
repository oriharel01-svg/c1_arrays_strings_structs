/*------------------------------------------------------
* Filename: array_series.c
* Description: Program to receive an array of integers and return whether the array is increaing, decreasing, constant or messed up.
* Author: Ori Harel
-------------------------------------------------------*/

#include <stdio.h>

#define ARRAY_SIZE 15

#define CONSTANT 0
#define INCREASING 1
#define DECREASING 2
#define MESSED_UP 3

int main() {

    /*Define and initialize the array and the array type*/
    int arr[ARRAY_SIZE] = {0};
    int arr_type = CONSTANT;

    /*Receive an array from user*/
    printf("Enter an array of 15 integers: \n");
    for(int i = 0; i < ARRAY_SIZE; ++i) {
        scanf("%d", &arr[i]);
    }

    /*Check the array type*/
    for(int i = 1; i < ARRAY_SIZE; ++i) {

        /*Check if increasing*/
        if((arr[i] > arr[i-1]) && (arr_type == CONSTANT)) {
            arr_type = INCREASING;
            continue;
        }
        /*Check if decreasing*/
        if((arr[i] < arr[i-1]) && (arr_type == CONSTANT)) {
            arr_type = DECREASING;
            continue;
        }
        /*Check if messed up*/
        if(((arr[i] < arr[i-1]) && (arr_type == INCREASING)) || ((arr[i] > arr[i-1]) && (arr_type == DECREASING))) {
            arr_type = MESSED_UP;
            break;
        }
    }

    /*Print the array type*/
    switch (arr_type) {
        case CONSTANT:
            printf("The array is constant\n");
            break;
        case INCREASING:
            printf("The array is increasing\n");
            break;
        case DECREASING:
            printf("The array is decreasing\n");
            break;
        case MESSED_UP:
            printf("The array is messed up\n");
            break;
        default:
            printf("ERROR\n");

    }

    return 0;
}