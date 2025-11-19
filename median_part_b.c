/*------------------------------------------------------
* Filename: median.c
* Description: Program to recieve integers from user and calculate their median
* Author: Ori Harel
-------------------------------------------------------*/

#include <stdio.h>
#include <malloc.h>
#include <ctype.h>

#define TRUE 1

int* get_integers_input(int *p_integers, const unsigned int initial_capacity, int *p_number_of_integers);
float calc_median(int *p_integers, int *p_number_of_integers);
void swap(int *p_one, int *p_two);

int main() {

    /*Define and initialize a dynamic integer pointer*/
    const int initial_capacity = 4;
    int *p_integers = (int*) malloc(4*sizeof(int));
    if(p_integers == NULL) { /*an error occured*/
        return 1;
    }
    /*Define and initialize the number of integers and a pointer*/
    int number_of_integers = 0;
    int *p_number_of_integers = &number_of_integers;
    
    /*Define and initialize the median*/
    float median = 0.0f;

    /*Get integers from user*/
    p_integers = get_integers_input(p_integers, initial_capacity, p_number_of_integers);
    if(p_integers == NULL) { /*an error occurred*/
        printf("ERROR\n");
        return median;
    }

    /*Find the median of the received integers*/
    median = calc_median(p_integers, p_number_of_integers);
    printf("The median is: %f\n", median);

    free(p_integers);
    return 0;
}



/*------------------------------------------------------
* Function Name - get_integers_input(int *p_integers, const unsigned int initial_capacity, int *p_number_of_integers)
*
* Function Purpose - Function to receive an unkown number of integers from user until the input is not an integer
*
* Parameters –  IN int *p_integers - a pointer to an integer
*               IN const unsigned int initial_capacity - an initial capacity of the dynamically allocated pointer
*               IN int *p_number_of_integers - a pointer to the number of integers received
*
* Return Values - Returns a pointer to the first integer received
*
* Author - Ori Harel
-------------------------------------------------------*/

int* get_integers_input(int *p_integers, const unsigned int initial_capacity, int *p_number_of_integers) {
    
    int input = 0;
    
    /*Get integers from user*/
    printf("Enter integers:\n");
    while(TRUE) {

        /*Check if input is valid*/
        if((scanf("%d", &input) != 1)) {
            printf("Not an integer\n");
            break;

        }
        /*Add the integer input*/
        if(*p_number_of_integers > initial_capacity) {
            p_integers = (int*) realloc(p_integers, *(p_number_of_integers) * sizeof(int));
        }
        
        if(p_integers == NULL) { /*an error occured*/
            printf("ERROR! p_integers = NULL\n");
            return p_integers;
        }

        *(p_integers + *p_number_of_integers) = input;
        ++(*p_number_of_integers);
        
    }

    return p_integers;
}



/*------------------------------------------------------
* Function Name - calc_median(int *p_integers, const unsigned int initial_capacity, int *p_number_of_integers)
*
* Function Purpose - Function to receive an unkown number of integers from user until the input is not an integer
*
* Parameters –  IN int *p_integers - a pointer to the first integer received
*               IN int *p_number_of_integers - a pointer to the number of integers received
*
* Return Values - Returns the median value (float)
*
* Author - Ori Harel
-------------------------------------------------------*/



float calc_median(int *p_integers, int *p_number_of_integers) {

    float median = 0.0f;
    int *p_sorted_integers = (int*) malloc((*p_number_of_integers) * sizeof(int));
    if(p_sorted_integers == NULL) {
        printf("ERROR\n");
        return  median;
    }
    p_sorted_integers = p_integers;

    /*Sort the data*/
    for(int i = 0; i < *p_number_of_integers; ++i) {
        for(int j = 0; j < *p_number_of_integers - i; ++j) {
            if(*(p_sorted_integers + i) > *(p_sorted_integers + i + j)) {
                swap((int*) (p_sorted_integers + i), (int*) (p_sorted_integers + i + j));
            }
        }
    }


    /*Calculate the median*/
    if(*p_number_of_integers % 2 == 1) {
        median = (float) *(p_integers + (int)((*p_number_of_integers)/2));
    } else if(*p_number_of_integers % 2 == 0) {
        median = (float) ((*(p_integers + (*p_number_of_integers)/2)) + (*(p_integers + (*p_number_of_integers)/2) - 1)) / 2;
    }

    free(p_sorted_integers);
    return median;

}




void swap(int *p_one, int *p_two) {
    int temp = *p_one;
    *p_one = *p_two;
    *p_two = temp;
    return;
}