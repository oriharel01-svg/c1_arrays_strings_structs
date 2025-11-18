/*------------------------------------------------------
* Filename: array_sort.c
* Description: Program to sort a given array of pointers which point to the elements of an integers array of the same size.
* Author: Ori Harel
-------------------------------------------------------*/

#include <stdio.h>
#include <ctype.h>

#define ARRAY_SIZE 10

void swap(int **p_one, int **p_two);
void print_values_and_addresses(int *pointers_arr[], const unsigned int len);



int main() {

    /*Define and initialize the integers array and a pointer to its first term*/
    int integers_arr[ARRAY_SIZE] = {0};
    int *p_integers_arr = &integers_arr[0];

    /*Define and initialize the pointers array and a pointer to its first term*/
    int *pointers_arr[ARRAY_SIZE] = {NULL};
    int **p_pointers_arr = &pointers_arr[0];

    for(int i = 0; i < ARRAY_SIZE; ++i) {
        pointers_arr[i] = p_integers_arr + i;
    }

    int input = 0;

    /*Receive an array of integers from user*/
    printf("Enter an array of %d integers\n", ARRAY_SIZE);
    for(int i = 0; i < ARRAY_SIZE; ++i) {
        scanf("%d", (p_integers_arr + i));
    }

    /*Print the pointers from the pointers array and the values in these addresses*/
    printf("Before sort:\n");
    print_values_and_addresses(pointers_arr, ARRAY_SIZE);

    /*Sort the pointers array according to the integers array (from smallest to largest)*/
    for(int i = 0; i < ARRAY_SIZE; ++i) {
        for(int j = 0; j < ARRAY_SIZE - i; ++i) {
            if(*(p_integers_arr + i) > *(p_integers_arr + j - i)) {
                swap((p_pointers_arr + i), (p_pointers_arr + j - i));
            }
        }
    }

    /*Print the pointers from the pointers array and the values in these addresses*/
    printf("After sort:\n");
    print_values_and_addresses(pointers_arr, ARRAY_SIZE);


    return 0;
}


/*------------------------------------------------------
* Function Name - swap(int **p_one, int **p_two)
*
* Function Purpose - Function to swap between the values of to pointers to pointers
*
* Parameters –  IN int **p_one, int **p_two - the pointers to pointers to swap between
*		        
*
* Return Values - No return values
*
* Author - Ori Harel
-------------------------------------------------------*/

void swap(int **p_one, int **p_two) {
    int *temp = *p_one;
    **p_one = **p_two;
    **p_two = *temp;
    return;
}



/*------------------------------------------------------
* Function Name - swap(int *p_one, int *p_two)
*
* Function Purpose - Function to swap between the values of to pointers 
*
* Parameters –  IN int *pointers_arr[] - an array of pointers that point to integers
                IN const unsigned int len - the size of the pointers array
*		        
*
* Return Values - No return values
*
* Author - Ori Harel
-------------------------------------------------------*/


void print_values_and_addresses(int *pointers_arr[], const unsigned int len) {
    for(int i = 0; i < len; ++i) {
        printf("%d) Adress: %X, Value: %d\n", i, pointers_arr[i], *pointers_arr[i]);
    }
}