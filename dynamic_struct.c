/*------------------------------------------------------
* Filename: dynamic_struct.c
* Description: Program to receive 2 times (ecah includes a number of hours,minutes and seconds) and return the sum.
* Author: Ori Harel
-------------------------------------------------------*/



#include <stdio.h>
#include <malloc.h>


struct Time {
    int hours;
    int minutes;
    int seconds;
};


/*Function prototypes*/
struct Time * get_new_time();
struct Time * times_addition(struct Time t1, struct Time t2);

int main() {
    /*Get two times from user*/
    struct Time * t1 = get_new_time();
    struct Time * t2 = get_new_time();

    /*Calculate and print the sum*/
    struct Time * total_time = times_addition(*t1, *t2);
    printf("The total time is: \n"
    "Hours: %d \n"
    "Minutes: %d \n"
    "Seconds: %d \n", (*total_time).hours, (*total_time).minutes, (*total_time).seconds);

    /*Free the memory that was dynamically allocated*/
    free(t1);
    free(t2);
    free(total_time);

    return 0;
}


/*------------------------------------------------------
* Function Name - get_new_time() 
*
* Function Purpose - Get from user a number of hours, minutes and seconds and creates a new Time element.
*
* Parameters –  none
*
* Return Values - Returns a pointer to the new time
*
* Author - Ori Harel
-------------------------------------------------------*/

struct Time * get_new_time() {
    
    struct Time * new_time = (struct Time *) malloc(sizeof (struct Time));
    
    int current_input = -1;

    /*Get and set number of hours*/
    printf("Enter a number of hours between 0 and 23: \n");
    scanf("%d", &current_input);

    
    while(current_input > 23 || current_input < 0) {
        printf("Invalid number of hours. enter again: \n");
        scanf("%d", &current_input);
    }

    (*new_time).hours = current_input;
    


    /*Get and set number of minutes*/
    printf("Enter a number of minutes between 0 and 59: \n");
    scanf("%d", &current_input);

    while(current_input > 59 || current_input < 0) {
        printf("Invalid number of minutes");
        scanf("%d", &current_input);
    } 
    
    (*new_time).minutes = current_input;

    /*Get and set number of seconds*/
    printf("Enter a number of seconds between 0 and 59: \n");
    scanf("%d", &current_input);

    while(current_input > 59 || current_input < 0) {
        printf("Invalid number of seconds");
        scanf("%d", &current_input);
    }

    (*new_time).seconds = current_input;
    

    return new_time;

}



/*------------------------------------------------------
* Function Name - get_new_timetimes_additiond(struct Time t1, struct Time t2) 
*
* Function Purpose - create a new time which is the sum of two given times.
*
* Parameters –  [IN struct Time t1, struct Time t2] - the two times to sum over
*
* Return Values - Returns a pointer to the total time
*
* Author - Ori Harel
-------------------------------------------------------*/




struct Time * times_addition(struct Time t1, struct Time t2) {
    struct Time * total_time = NULL;
    
    int total_seconds = 0;
    int total_minutes = 0;
    int total_hours = 0;

    total_seconds = (t1.seconds + t2.seconds) % 60;
    total_minutes = (((t1.seconds + t2.seconds) - total_seconds)/60 + (t1.minutes + t2.minutes)) % 60;
    total_hours = ((t1.minutes + t2.minutes) - total_minutes)/60 + (t1.hours + t2.hours);

    if(total_hours > 23) {
        printf("More than one day\n");
    }
    total_time = (struct Time *) malloc(sizeof(struct Time));

    (*total_time).seconds = total_seconds;
    (*total_time).minutes = total_minutes;
    (*total_time).hours = total_hours;
    return total_time;

}