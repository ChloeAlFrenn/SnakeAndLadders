//
//  main.c
//  SnakeAndLadders
//
//  Created by Chloe Al-Frenn on 2022-12-27.
//

#include <stdio.h>
#include <stdlib.h>

void printBoard(void);
int diceRoll(void);
void checkSnakeOrLadder(int *, int);

int main(int argc, const char * argv[]) {
    
    int numOfPlayers;
    
    printf("Welcome to snakes and ladders\n");
    printf("Enter the number of players varying from 2 to 4\n");
    scanf("%d", &numOfPlayers);
    while(numOfPlayers > 4 || numOfPlayers < 2){
        printf("Wrong input try again\n");
        scanf("%d", &numOfPlayers);
    }
    int playersPos[numOfPlayers]; // create an array that will contain the position of the players
    for(int i=0; i<numOfPlayers; i++){
        playersPos[i] = 0; //initializes everyone's position at 0
    }
    
    printf("Here is the board:\n");
    printBoard();
    printf("Snakes are located from 36 to 9, 83 to 42 and 95 to 35");
    printf(" and ladders are located from 3 to 24, 33 to 48 and 53 to 79.\n");
    printf("Now lets start the game!\n");
   
    int entry;
    int playing = 0; //player who is playing now we start at player 1 who's at index 0
    int dice;
    while(1){
        printf("\n------------------------- \n");
        printf(" 1 to continue playing\n");
        printf(" 2 to get the rules\n");
        printf(" 3 to exit the game\n");
        printf("------------------------- \n");
        scanf("%d", &entry);
        printf("\n");
     
        if(entry == 1){
            printf("player %d's turn\n", playing+1);
            dice = diceRoll();
            printf("you rolled %d\n", dice);
            if(playersPos[playing] + dice < 100){
                playersPos[playing] = playersPos[playing] + dice; // set the position
                checkSnakeOrLadder(playersPos, playing);
                printf("your new position is %d\n", playersPos[playing]);
            } else if(playersPos[playing] + dice == 100) {
               playersPos[playing] = playersPos[playing] + dice;
               printf("your new position is %d\n", playersPos[playing]);
               printf("player %d's won\n", playing+1);
               break;
               
           } else {
               printf("you exceeded 100 so your position will not change\n");
           }
        
            while(dice == 6){
                printf("player %d's turn again after rolling a 6\n", playing+1);
                dice = diceRoll();
                printf("you rolled %d\n", dice);
                if(playersPos[playing] + dice < 100){
                    playersPos[playing] = playersPos[playing] + dice; // set the position
                    checkSnakeOrLadder(playersPos, playing);
                    printf("your new position is %d\n", playersPos[playing]);
                } else if(playersPos[playing] + dice == 100) {
                    playersPos[playing] = playersPos[playing] + dice;
                    printf("your new position is %d\n", playersPos[playing]);
                    printf("player %d won\n", playing+1);
                    break;
                    
                } else {
                    printf("you exceeded 100 so your position will not change\n");
                }
            }
            
            if(playersPos[playing] + dice == 100) {
                break;
            }
        }
        else if(entry == 2){
            //show rules
            printf("show rules :)\n");
        }
        else if (entry == 3){
          printf("Thank you for playing!\n");
        break;
        } else {
            printf("Wrong input try again\n");
        }
        
        playing = (playing + 1) % numOfPlayers;
    }
    return 0;
}

//Function that prints the board in the same way a normal snake and ladders game board is printed
void printBoard(){
    int change = 1;
    for(int i=100; i>0; i =i-10){
        int current;
        
        if(change == 1) {
            for(int j=0; j<10; j++){
                current = i-j;
                printf("%d ", current);
            }
        }
        
        if (change == -1) {
            for(int k=9; k>=0; k--){
                current = i-k;
                printf("%d ", current);
            }
        }

        printf("\n");
        change = change * -1;
    }
    printf("\n");
}
//generates and returns a random number between 1 and 6
int diceRoll(){
    int r = rand()%7;
    if(r == 0){
        r = diceRoll();
    }
        return r;
}

//receives a pointer to an array as a parameter
void checkSnakeOrLadder(int *position, int player){
    int pos = position[player];
    switch(pos){
        case 3: //ladder 3 to 24
            printf("Congrats you got a ladder! you move from 3 to 24\n");
            position[player] = 24;
            break;
        case 33: //ladder 33 to 48
            printf("Congrats you got a ladder! you move from 33 to 48\n");
            position[player] = 48;
            break;
        case 53: //ladder 53 to 79
            printf("Congrats you got a ladder! you move from 53 to 79\n");
            position[player] = 79;
            break;
        case 36: //snake 36 to 9
            printf("Sadly you got a snake! you move from 36 to 9\n");
            position[player] = 9;
            break;
        case 83: // snake 83 to 42
            printf("Sadly you got a snake! you move from 83 to 42\n");
            position[player] = 42;
            break;
        case 95: //snake 95 to 35
            printf("Sadly you got a snake! you move from 95 to 35\n");
            position[player] = 35;
            break;
        default:
            break;
    }
}
