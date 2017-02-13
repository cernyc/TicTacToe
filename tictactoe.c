// Tic-Tac-Toe
// CMS 230, 2016

#include <stdio.h>
#include "tictactoe.h"  // Local header containing function prototypes


// Reads and returns a single character from input using getchar()
//
// Input: none
// Returns: the character represented as an int type
int getInputChar() {
    // Read the character
    int c = getchar();
    
    // Pressing the ENTER key adds a newline to the input stream
    // Read a second character to consume the newline
    getchar();
    
    return c;
}


// Prints the board
//
// Inputs: the board, a 3x3 char array
// Returns: nothing, the board is printed to the console
void printBoard(char board[3][3]) {

    int i;
    int n;

    printf("\n");

    for(i=0; i<3; i++) {
        
        for(n=0; n<3; n++) {
            
            printf(" %c |", board[i][n]);
        }
        
        printf("\n------------\n");
    }
}


// Checks for three characters in a row
//
// Inputs:
//   char board[3][3]: the 3x3 board
//   char charToCheck: a character to check
//
// Returns: 1 if the character is in three consecutive positions
int checkWin(char board[3][3], char c) {
    
    int i;
    int n;
    
   for (i=0; i<3; i++){
       if( board[i][1] == board[i][0] && c == board[i][2] && board[i][1] == board[i][2] ) {
           return 1;
       }
       if( board[0][i] == board[1][i] && board [1][i] == board[2][i] && c == board[2][i] ) {
           return 1;
        }
   }
    
    //for (i=0; i<3; i+2){
    //    for (n=2; n>=0; n-2){
    //        if (board[1][1] == board[i][n] && board[1][1] == board[n][i] ){
    //            return 0;
    //        }
    //    }
    //}
    
    if (board[1][1] == board[0][0] && board[1][1] == board[2][2] && c == board[1][1] ) {
       return 1;
    }
    
    if ( board[1][1] == board[0][2] && board[1][1] == board[2][0] && c== board[1][1] ) {
       return 1;
    }
    
    return 0;
}



//Adds the X or the O to the case chose by the player
int addPlay (char board[3][3], int place, char type) {
    
    if (place == '1' && board[0][0] == ' ' ) {
     board[0][0]=type;
     return 0;
    }
    if (place == '2' && board[0][1] == ' ' ) {
     board[0][1]=type;
     return 0;
    }
    if (place == '3' && board[0][2] == ' ' ) {
     board[0][2]=type;
     return 0;
    }
    if (place == '4' && board[1][0] == ' ' ) {
     board[1][0]=type;
     return 0;
    }
    if (place == '5' && board[1][1] == ' ' ) {
     board[1][1]=type;
     return 0;
    }
    if (place == '6' && board[1][2] == ' ' ) {
     board[1][2]=type;
     return 0;
    }
    if (place == '7' && board[2][0] == ' ' ) {
     board[2][0]=type;
     return 0;
    }
    if (place == '8' && board[2][1] == ' ' ) {
     board[2][1]=type;
     return 0;
    }
    if (place == '9' && board[2][2] == ' ' ) {
     board[2][2]=type;
     return 0;
    }
    
    return 1;
}



// This fonction just gives the instructions to the players
int instructionsRemainder(char type) {
    
     printf("\n It's %c turn, please enter the case you want according to the given board \n \n", type);
     printf("  1 | 2 | 3 | \n -------------\n  4 | 5 | 6 | \n -------------\n  7 | 8 | 9 | \n \n ");
    
    return 0;
    
}


int main() {
    
    int games;
    char charToPlay;
    char c;
    
    // Create a blank 3x3 board array
    char board[3][3] = {{' ', ' ', ' '},  // Row 0
                        {' ', ' ', ' '},  // Row 1
                        {' ', ' ', ' '}}; // Rpw 2

    // Don't put all your code in main!
    
    for (games=1; games<= 9; games++) {
        
        if (games %2 != 0) {
            charToPlay = 'X';
        }
        else {
            charToPlay = 'O';
        }
        
        instructionsRemainder(charToPlay);
        
        c = getInputChar();
        printf("\n You played case %c\n", c);
        
        if (addPlay(board, c, charToPlay) == 1) {
            printf("\n Please enter a case from 1 to 9 not already taken.\n");
            games --;
        } 
        else {
        addPlay(board, c, charToPlay);
        printBoard(board);
        }
        
        if (checkWin(board, charToPlay) == 1) {
             printf("\n %c Wins !\n", charToPlay);
             return 0;
        }
    
    }
        
    printf("\n Draw !\n");
    

    // In particular, think about how to handle nearly identical turns for the
    // two players.
    
    return 0;
    
}
