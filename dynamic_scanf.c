/*------------------------------------------------------
* Filename: dynamic_scanf.c
* Description: Program to receive a text line and print it.
* Author: Ori Harel
-------------------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1

/*Function decleration*/
char *dyn_scanf(void);

int main() {
    
    /*Dynamically allocate a char pointer and initialize it*/
    char *buffer = (char*) calloc(1, sizeof(char));

    /*Get a line of text from user and keep it*/
    printf("Enter text: \n");
    buffer = dyn_scanf();

    /*Check if buffer is NULL*/
    if(NULL == buffer) {
        printf("ERROR\n");
        return 1;
    }
    
    /*Print the input string*/
    printf("The received string:\n");
    unsigned int i = 0;
    while(TRUE) {
        printf_s("%c", *(buffer + i));
        if(*(buffer + i) == '\n') { /*End of line*/
            break;
        }
        if(i == UINT_MAX) { /*Overflow*/
            break;
        }
        ++i;
    }


    if(i == 1) {
        printf("Empty line\n");
    }

    free(buffer);

    return 0;
}



/*------------------------------------------------------
* Function Name - char *dyn_scanf(void)
*
* Function Purpose - Read a line of text and return the received string
*
* Parameters –  None
*
* Return Values - string (char*) - the received text line
*
* Author - Ori Harel
-------------------------------------------------------*/


char *dyn_scanf(void) {

    /*Define and initialize a char and a number of chars variables*/
    char c = '\0';
    unsigned int number_of_chars = 0;

    /*Dynamically allocate a char* */
    char *string = (char*) malloc(number_of_chars * sizeof(char) + 1);
    if(NULL == string) {
        printf("ERROR\n");
        return string;
    }

    /*Read a text line from user*/
    while(TRUE) {
        c = getchar();
        if(number_of_chars == UINT_MAX) {
            printf("\n Overflow - too many characters\n");
            return string;
        }
        ++number_of_chars;
        char *temp = realloc(string, number_of_chars * sizeof(char) + 1);
        if(NULL == temp) {
            printf("\n ERROR - Not enough memory\n");
            return string;
        } else {
            string = temp;
        }
        *(string + number_of_chars) = c;
        if('\n' == c) {
            break;
        }
    }


    return string;

    


}
