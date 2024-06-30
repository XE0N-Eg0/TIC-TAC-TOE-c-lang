//FILES NEEDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

//GLOBAL VARRIABLES
char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

//FUNCTIONS WE NEED 
void resetboard();
void printboard();
void playermove();
void computermove();
void printwinner(char);
int  checkfreeblocks();
char checkwinner();



// MAIN
int main(int argc, char const *argv[])
{
    char winner = ' '; //space will be filled by the winner

    resetboard();
    
    while (winner == ' ' && checkfreeblocks() != 0)
    {
        printboard();


        playermove();
        winner = checkwinner();
        if (winner != ' ' || checkfreeblocks() == 0)
        {
            break; //breaks the loop 
        }

        computermove();
        winner = checkwinner();
        if (winner != ' ' || checkfreeblocks() == 0)
        {
            break; //breaks the loop 
        }
        
    }

    printboard();
    printwinner(winner);
    
    
    return 0;
}



void resetboard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' '; //blank space that fills up board with blank space
        }
        
    }
    

}

void printboard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1],board[2][2]);
    printf("\n");
    

}
void playermove()
{
    int row,columb;
    do
    {
        printf("Enter a row(1-3): ");
        scanf("%d",&row);
        printf("Enter a columb(1-3): ");
        scanf("%d",&columb);

        //as row and columb are initialized from 0
        row--;   
        columb--;

        if (board[row][columb] != ' ')
        {
            printf("Invalid move/occupied ");
        }
        else{
            board[row][columb] = PLAYER;
            break; //to make the player move if wrong
        }

    } while (board[row][columb] != ' ');
    

}
void computermove()
{
    //create a seed based on time 
    srand(time(NULL));
    int row, columb;

    if (checkfreeblocks() > 0)
    {
        do
        {
            row = rand() %3;
            columb = rand() %3;

        } while (board[row][columb] != ' '); // keeps generating random numbers if space is empty
        
        board[row][columb] = COMPUTER;

    }
    else
    {
        printwinner(' '); // means a draw

    }
    

}

void printwinner(char winner)
{
    if (winner == PLAYER)
    {
        printf("YOU WIN !!!  :)");
    }
    else if(winner == COMPUTER)
    {
        printf("YOU LOSE !!!  :()");
    }
    else
    {
        printf("DRAW !!!  : |");
    }

}
int  checkfreeblocks()
{
    int freespace = 9; // nine free spaces be default

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != ' ' )
            {
                freespace--; //decreases the free spaces
            }
            
        }
        
    }
    return freespace; //if this becomes 0 = game over

}
char checkwinner()
{
    //checking the rows 

    for (int i = 3; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];

        }
        
    }
    
    //checking the columbs

    for (int i = 3; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];

        }
        
    }
    
    //check diagonals 
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }
    
    return ' '; //if none of the cases satisfies the game carries on with a empty space returned

}

