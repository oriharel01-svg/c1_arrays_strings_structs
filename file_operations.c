/*------------------------------------------------------
* Filename: file_operations.c
* Description: Program to implement various file operations
* Author: Ori Harel
-------------------------------------------------------*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



#define MAX_LINE 2048 /*A maximal size for a buffer*/

int main() {
    // Your code here

    return 0;
}



/*------------------------------------------------------
* Function Name - read_and_print_text_file(char *text_file_name)
*
* Function Purpose - Read and print to console the content of a given text file
*
* Parameters –  IN  char *text_file_name - the name of the text file to read and print
*
* Return Values - None
*
* Author - Ori Harel
-------------------------------------------------------*/

void read_and_print_text_file(char *text_file_name) {

    /*Define and initialize a char*/
    char c = '\0';

    FILE *fp = NULL;
    /*Open file*/
    fp = fopen(text_file_name, "r");
    if(NULL == fp) {
        printf("Could not open %s\n", text_file_name);
        return;
    }

    /*Print every char until end of file*/
    while(EOF != (c = fgetc(fp))) {
        printf("%c", c);
    }

    /*Close the file*/
    if(0 != fclose(fp)) {
        printf("Could not close %s\n", text_file_name);
    }

    return;
}


/*------------------------------------------------------
* Function Name - copy_text_file(char *in_text_file_name, char *out_text_file)
*
* Function Purpose - Copy the content of a given text file into a another given text file. If the other given text file does not exist, create a new one.
*
* Parameters –  IN  char *in_text_file_name - the name of the text file to copy
*               IN  char *out_text_file_name - the name of the text file to copy into
*
* Return Values - None
*
* Author - Ori Harel
-------------------------------------------------------*/




void copy_text_file(char *in_text_file_name, char *out_text_file_name) {

    /*Define and initialize a char*/
    char c = '\0';

    /*Define and initialize the file pointers*/
    FILE *fp_in = NULL;
    FILE *fp_out = NULL;

    /*Open files*/
    fp_in = fopen(in_text_file_name, "r");
    if(NULL == fp_in) {
        printf("Could not open %s\n", in_text_file_name);
        return;
    }
    fp_out = fopen(out_text_file_name, "w");
    if(NULL == fp_out) {
        printf("Could not open or create %s\n", out_text_file_name);
        return;
    }

    /*Copy every char into the new file*/
    while(EOF != (c = fgetc(fp_in))) {
        fputc(c, fp_out);
    }
    
    /*Close the files*/
    if(0 != fclose(fp_in)) {
        printf("Could not close %s\n", in_text_file_name);
    }
    if(0 != fclose(fp_out)) {
        printf("Could not close %s\n", out_text_file_name);
    }

    return;


}




/*------------------------------------------------------
* Function Name - print_content_details(char * file_name)
*
* Function Purpose - Function to read a text file and print the number of lines, words and letters in it.
*
* Parameters –  [IN char * file_name]- the name of the text file.
*
* Return Values - None
*
* Author - Ori Harel
-------------------------------------------------------*/



void print_content_details(char * file_name) {

    int c = 0;

    int number_of_lines = 0;
    int number_of_words = 0;
    int number_of_letters = 0;


    FILE * fp = NULL;


    /*Open the file*/
    fp = fopen(file_name, "r");
    if(NULL == fp) {
        printf("Could not open %s. \n", file_name);

    }

    /*Calculate the number of lines, words and letters*/

    while(EOF != (c = fgetc(fp))) {
        if(c == '\n') {
            number_of_lines += 1;
        }

        if(isspace(c)) {
            number_of_words += 1;
        }

        if((isalpha(c))) {
            number_of_letters += 1;
        }
    }



    /*Print the results*/
    printf("%d \n", number_of_lines);
    printf("%d \n", number_of_words);
    printf("%d \n", number_of_letters);

    /*Close the file*/
    if(0 != fclose(fp)) {
        printf("Could not close %s. \n", file_name);
    }

}

/*------------------------------------------------------
* Function Name - delete_line(char * file_name, int line_number)
*
* Function Purpose - Function to delete a specific line in a file.
*
* Parameters –  [IN char * file_name]- the name of the file
                [IN int line_number]- the number of the line to delete
*
* Return Values - None
*
* Author - Ori Harel
-------------------------------------------------------*/


void delete_line(char * file_name, int line_number) {


    


    FILE * fp = NULL;
    FILE * fp_temp = NULL;

    char temp_file_name[strlen(file_name) + strlen("temp____")];
    strcpy(temp_file_name, "temp____");
    strcat(temp_file_name, file_name);

    char buffer[MAX_LINE];

    int current_line = 0;

    /*Open the file for reading*/
    fp = fopen(file_name, "r");
    /*Open the temporary file for writing*/
    fp_temp = fopen(temp_file_name, "w");

    /*Copy every line from the original file, except the line that needs to be deleted*/
    while(NULL != fgets(buffer, MAX_LINE, fp)) {
        ++current_line;
        if(current_line != line_number) {
            fputs(buffer, fp_temp);
        }
    }

    fclose(fp);
    fclose(fp_temp);

    /*Rewrite the original file without the deleted line*/
    fp_temp = fopen(temp_file_name, "r");
    fp = fopen(file_name, "w");
    while(NULL != (fgets(buffer, MAX_LINE, fp_temp))) {
        fputs(buffer, fp);
    }

    /*Close files*/
    if(0 != fclose(fp_temp)) {
        printf("Could not close a temporay file\n");
    }
    if(0 != fclose(fp)) {
        printf("Could not close %s\n", file_name);
    }


}


/*------------------------------------------------------
* Function Name - number_of_shows(char *file_name, char *string)
*
* Function Purpose - Function to calculate how many times a given string is found in a given file.
*
* Parameters –  [IN char *file_name]- the name of the file
                [IN char *string]- the string to calculate the number of shows of
*
* Return Values - number_of_shows (int) - the number of times the string is found in the file
*
* Author - Ori Harel
-------------------------------------------------------*/



int number_of_shows(char *file_name, char *string) {

    /*Define and initialize a file pointer, a char and a number of shows*/
    FILE *fp = NULL;
    char c = '\0';
    int number_of_shows = 0;
    int correct_chars = 0;

    /*Open file*/
    fp = fopen(file_name, "r");
    if(NULL == fp) {
        printf("Could not open %s\n", file_name);
    }

    while(EOF != (c = fgetc(fp))) {
        if(c == *(string + correct_chars)) {
            ++correct_chars;
        } else {
            correct_chars = 0;
        }
        if(correct_chars == strlen(string)) {
            ++number_of_shows;
            correct_chars = 0;
        }

    }

    /*Close the file*/
    if(0 != fclose(fp)) {
        printf("Could not close %s\n", file_name);
    }

    return number_of_shows;

}



