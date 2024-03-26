/*
Author: Mark Harburg
Date: 4/23/13
Project 3- Mastermind
ENG 220-section: 06
Dr. Jonathan P. Leidig
Description: This is an implementation of the game Mastermind(R). With the game choice of easy or hard.
The user must guess the correct combination of colors in order to win.
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
//#include <process.h>
#include <time.h>
#include <string.h>

//prototype functions that retrun r and w and print the board.
char check_W(char guess[],char ans[], char rw[], char check, char temp[], int nolap[],int n, int len);
int check_R_PrintBoard(char guess[],char ans[], char **board[][9], int n, int level);

int main()
{

    srand(time(NULL));
    int i=0, j=0, n=0;
    int gameagain, game=0, level, win=0, overall=0;
    char arrayletter[]="ROYGBW";
    char difficulty;
    char guess[10]={};
    char ans[4];

    do
    {
         if (game>0)//asks user if they want to paly again after first try
        {
            printf ("\nOut of %d games, your cumulative wins against the computer are %d times.", game, overall);
            printf ("\nDo you wish to play again? enter 1 for yes or 0 for no: ");
            scanf ("%d", &gameagain);
            if (gameagain==0)
            {
                printf("\nGoodbye!\n");
                return (0);
            }
        }
        //difficulty choice
        printf ("\nWelcome to an implementation of the game Mastermind(R).\n");
        printf ("The hard game will chose a sequence of 4 colors for you to guess and you will have only 10 attempts to guess.\n");
        printf ("The easy game will chose a sequence of 3 colors for you to guess and you will be allowed 15 attempts to guess.\n");
        printf("\nDo you wish to play the hard or easy verison? Enter H or E: ");
        do
        {
            scanf (" %c", &difficulty);
        }while (difficulty!='e'&&difficulty!='E'&&difficulty!='H'&&difficulty!='h');

        char **board[16][10]={};//resets the board to blankspace

        if (difficulty=='H'||difficulty=='h')//code for hard choice
        {
            level=2;
            n=0;
            //instructions
            printf ("Please choose out of these options for colors:\n");
            printf ("R=Red, O=Orange, Y=Yellow, G=Green, B= Blue, W=White\n");
            printf ("For the computer evaluation,'r' means red in the responses, and 'w' means white in the responses\n");
            printf ("If it is a 'r' it means that it is the correct color and correct placement.\n");
            printf ("If it is a 'w' it means it is the correct color wrong placement.\n");

            for (i=0;i<4;i++) //gets random answer
                ans[i]=arrayletter[rand()%5+1];

            for (n=1;n<11;n++)//ten attempts to solve
            {
                do
                {
                    printf (" \nWhat's your current guess? please enter: ");
                    scanf (" %c%c%c%c", &guess[0], &guess[1], &guess[2], &guess[3]);//scans in users guess
                    for (i=0;i<5;i++)
                        if(isalpha(guess[i]) && (int)guess[i]>= 97) //changes to uppercase
                            guess[i]= toupper(guess[i]);
                //checks to make sure it is a correct input
                }while (guess[0]!='B'&&guess[0]!='b'&&guess[0]!='R'&&guess[0]!='r'&&guess[0]!='O'&&guess[0]!='o'&&guess[0]!='Y'&&guess[0]!='y'&&guess[0]!='G'&&guess[0]!='g'&&guess[0]!='W'&&guess[0]!='w'
                                             &&guess[1]!='B'&&guess[1]!='b'&&guess[1]!='R'&&guess[1]!='r'&&guess[1]!='O'&&guess[1]!='o'&&guess[1]!='Y'&&guess[1]!='y'&&guess[1]!='G'&&guess[1]!='g'&&guess[1]!='W'&&guess[1]!='w'
                                             &&guess[2]!='B'&&guess[2]!='b'&&guess[2]!='R'&&guess[2]!='r'&&guess[2]!='O'&&guess[2]!='o'&&guess[2]!='Y'&&guess[2]!='y'&&guess[2]!='G'&&guess[2]!='g'&&guess[2]!='W'&&guess[2]!='w'
                                             &&guess[3]!='B'&&guess[3]!='b'&&guess[3]!='R'&&guess[3]!='r'&&guess[3]!='O'&&guess[3]!='o'&&guess[3]!='Y'&&guess[3]!='y'&&guess[3]!='G'&&guess[3]!='g'&&guess[3]!='W'&&guess[3]!='w');

                win=check_R_PrintBoard(guess,ans,board,n,level);//calls check r function
                 if (win==8)//checks to see if they won
                    {
                        overall++;//intcrements users winning score
                        n=20;
                    }
            }
            if (n==11)
                printf("\nYou are all out of guesses, sorry you lose.");
        }//end of if H loop
        if (difficulty=='E'||difficulty=='e')//code for easy choice
        {
            level=1;
            printf ("please choose out of these options for colors:\n");
            printf ("R=Red, O=Orange, Y=Yellow, G=Green, B= Blue, W=White\n");
            printf ("For the computer evaluation,'r' means red in the responses, and 'w' means white in the responses\n");
            printf ("If it is a 'r' it means that it is the correct color and correct placement.\n");
            printf ("If it is a 'w' it means it is the correct color wrong placement.\n");

            for (i=0;i<3;i++) //gets random answer
                ans[i]=arrayletter[rand()%5+1];
            n=0;
            for (n=1;n<16;n++)//15 attempts to solve
            {
                do
                {
                    printf (" \nWhat's your current guess? please enter: ");
                    scanf (" %c%c%c", &guess[0], &guess[1], &guess[2]);
                    for (i=0;i<4;i++)
                        if(isalpha(guess[i]) && (int)guess[i]>= 97) //changes to uppercase
                            guess[i]= toupper(guess[i]);
                //checks to make sure it is a correct input
                }while (guess[0]!='B'&&guess[0]!='b'&&guess[0]!='R'&&guess[0]!='r'&&guess[0]!='O'&&guess[0]!='o'&&guess[0]!='Y'&&guess[0]!='y'&&guess[0]!='G'&&guess[0]!='g'&&guess[0]!='W'&&guess[0]!='w'
                                             &&guess[1]!='B'&&guess[1]!='b'&&guess[1]!='R'&&guess[1]!='r'&&guess[1]!='O'&&guess[1]!='o'&&guess[1]!='Y'&&guess[1]!='y'&&guess[1]!='G'&&guess[1]!='g'&&guess[1]!='W'&&guess[1]!='w'
                                             &&guess[2]!='B'&&guess[2]!='b'&&guess[2]!='R'&&guess[2]!='r'&&guess[2]!='O'&&guess[2]!='o'&&guess[2]!='Y'&&guess[2]!='y'&&guess[2]!='G'&&guess[2]!='g'&&guess[2]!='W'&&guess[2]!='w');
                win=check_R_PrintBoard(guess,ans,board,n,level);
                if (win==8)//checks to see if they won
                    {
                        overall++;//intcrements users winning score
                        n=20;
                    }
            }
            if (n==16)
                printf("\nYou are all out of guesses, sorry you lose.");
        }//end of if E loop
        game++;//increments number of games played
    }while(gameagain!=0);//loops until user chooses to quit.
return (0); //end program
} //end of main

//----------------------------------------Check RED---------------------------------------------

int check_R_PrintBoard(char guess[],char ans[],char **board[][9], int n, int level)
{

    int i=0,j=0, b=0, win=0, len;
    char rw[5]={};
    char check;// used to check answer acording to the guess
    char temp[5];//makes a temperary array to store guess into
    int nolap[5];//checks to make sure there is no overlap

    if (level==2)//if hard then length of array is 4
        len=4;
    if (level==1)//if easy then length of array is 3
        len=3;

    for (i=0;i<len;i++)
    {
        temp[i]=guess[i];//puts guess into a temp array
    }
    for (i=0;i<len;i++)
    {
        check=temp[i];//puts the character into check
        if (check==ans[i])//checks to see it the caharacter matches
        {
            rw[i]='r';
            nolap[i]=1;//makes sure its doesnt happen again
            temp[i]=' ';//makes a space in temp
        }
    }
    check_W(guess,ans,rw,check,temp,nolap,n,len);
    board[n][4]=':';
    for (j=0;j<4;j++)
    {
        board[n][j]=guess[j];//puts guess into board
    }
    for (j=5;j<9;j++)
    {
        board[n][j]=rw[b];//puts rw into board.
        b++;
    }
    for(b=1;b<=n;b++)
    {
        printf("\n");
        printf("%d. ", b);
        for(j=0;j<9;j++)
            printf ("%c ", board[b][j]);//prints board
    }
    if (level==2)//checks to see if user won hard game
        if (rw[0]=='r'&&rw[1]=='r'&&rw[2]=='r'&&rw[3]=='r')
        {
            printf ("\nCongradulations you guessed the correct combination %c%c%c%c. You Win!\n", ans[0],ans[1],ans[2],ans[3]);
            win=8;
            return (win);
        }
    if (level==1)//checks to see if user wins easy game
        if (rw[0]=='r'&&rw[1]=='r'&&rw[2]=='r')
        {
            printf ("\nCongradulations you guessed the correct combination %c%c%c. You Win!\n", ans[0],ans[1],ans[2]);
            win=8;
            return (win);
        }
    return (0);
}
//--------------------------------------------------Checks W-------------------------------------------
char check_W(char guess[],char ans[], char rw[], char check, char temp[], int nolap[],int n, int len)
{
    int i=0,j=0;
    for(i=0;i<len;i++)
    {
        check=temp[i];
        if (check!=' ')//checks to see if there is a space
        {
            for(j=0;j<len;j++)
            {
                if (nolap[j]!=1 && check==ans[j])
                {
                    nolap[j]=1;//makes sure it doesnt overlap.
                    rw[i]='w';
                    break;
                }
            }
        }
    }
    return(rw);
}
