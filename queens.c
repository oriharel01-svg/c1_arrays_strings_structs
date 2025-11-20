/*------------------------------------------------------
* Filename: [Filename here]
* Description: [Brief description of the program here]
* Author: [Your full name here]
-------------------------------------------------------*/


/*------------------------------------------------------
* Function Name - [Function Name here] 
*
* Function Purpose - [demonstrates proper documentation] 
*
* Parameters –  [IN first_parameter - an input sample parameter.] 
*		        [INOUT second_parameter * – an input + output sample parameter]
*		        [OUT third_parameter * – an output sample parameter]
*
* Return Values - [possible return value]
*
* Author - [Your full name here]
-------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

#define UNTAKEN 0 /*Define an untaken square*/
#define TAKEN 1 /*Define a taken square*/
#define IN_DANGER 2 /*Define a square in danger*/

#define BOARD_SIDE 7
#define MAX_DANGER 64

int number_of_in_danger(int board[][BOARD_SIDE], int size, int row, int col);
void update_board(int (*board)[BOARD_SIDE], int size, int row, int col);

int main() {

    /*Define and initialize the board*/
    int board[BOARD_SIDE][BOARD_SIDE];
    for(int i = 0; i < BOARD_SIDE; ++i) {
        for(int j = 0; j < BOARD_SIDE; ++j) {
            board[i][j] = UNTAKEN;
        }
    }


    int chosen_row=-1;
    int chosen_col=-1;

    for(int i=0; i<BOARD_SIDE;i++) {
        int min=MAX_DANGER;
        for(int j=0;j<BOARD_SIDE;j++){
            if(board[i][j]!=IN_DANGER && (board[i][j]!=TAKEN)){
                int tmp=number_of_in_danger(board, BOARD_SIDE, i, j);

            

                if(tmp<min){            
                    min = tmp;
                    chosen_row = i;
                    chosen_col = j;
                }
            }
        }
        update_board(board, BOARD_SIDE, chosen_row, chosen_col);


    }



    for(int i=0; i<BOARD_SIDE; i++){
        for(int j=0; j<BOARD_SIDE; j++)
        {
           if(board[i][j] == TAKEN) {
                printf(" %d |", TAKEN);
           } else {
                printf(" %d |", UNTAKEN);
           }
        } 
        printf("\n");
        printf("-------------------------------\n");
    }
    
    
    return 0;
}


int number_of_in_danger(int board[][BOARD_SIDE], int size, int row, int col){
    

    int number_of_dangerous = 0;
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(board[i][j] == UNTAKEN){
                if((i==row) || (j==col) || (abs(row - i) == abs(col - j))){
                    number_of_dangerous++;
                }
            }
        }
    }
    return number_of_dangerous;
}



void update_board(int (*board)[BOARD_SIDE], int size, int row, int col) {
    
    /*Update the square of the current queen*/
    board[row][col] = TAKEN;

    /*Update the squares in danger*/
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(board[i][j] == UNTAKEN){
                if((i==row) || (j==col) || (abs(row - i) == abs(col - j))){
                    board[i][j] = IN_DANGER;
                }
            }
        }
    }
}






