
//  SnakeAndLadders game implemented in c by ChloeAlFrenn
//

#include <stdio.h>
#include <stdlib.h>

void printBoard(int, int);
int diceRoll(void);
void checkSnakeOrLadder(int *, int);
void showRules(void);

//main function who manages the game
int main(int argc, const char * argv[]) {
    
    int numOfPlayers;
    
    printf("Welcome to my snake and ladders game!\n\n");
    showRules();
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
    printBoard(0, 0);
    printf("Snakes are located from 36 to 9, 83 to 42 and 95 to 35");
    printf(" and ladders are located from 3 to 24, 33 to 48 and 53 to 79.\n");
    printf("Now lets start the game!\n");
   
    int entry;
    int playing = 0; //player who is playing currently
    int dice;
    int won = 0; // is set to 1 if anyone wins
    while(1){
        printf("\n------------------------- \n");
        printf(" 1 to continue playing\n");
        printf(" 2 to get the rules\n");
        printf(" 3 to exit the game\n");
        printf("------------------------- \n");
        scanf("%d", &entry);
        printf("\n");
     
        if(entry == 1){
            printf("Player %d's turn\n", playing+1);
            dice = diceRoll();
            printf("you rolled %d\n", dice);
            if(playersPos[playing] + dice < 100){
                playersPos[playing] = playersPos[playing] + dice; // set the position
                checkSnakeOrLadder(playersPos, playing);
                printf("your new position is %d\n", playersPos[playing]);
                printBoard(playersPos[playing], playing+1);
            } else if(playersPos[playing] + dice == 100) {
                playersPos[playing] = playersPos[playing] + dice;
                printf("your new position is %d\n", playersPos[playing]);
                printBoard(playersPos[playing], playing+1);
                printf("Player %d won\n", playing+1);
                won = 1;
                break;
               
           } else {
               printf("you exceeded 100 so your position will not change\n");
               printBoard(playersPos[playing], playing+1);
           }
        
            while(dice == 6){
                printf("Player %d's turn again after rolling a 6\n", playing+1);
                dice = diceRoll();
                printf("you rolled %d\n", dice);
                if(playersPos[playing] + dice < 100){
                    playersPos[playing] = playersPos[playing] + dice; // set the position
                    checkSnakeOrLadder(playersPos, playing);
                    printf("your new position is %d\n", playersPos[playing]);
                    printBoard(playersPos[playing], playing+1);
                } else if(playersPos[playing] + dice == 100) {
                    playersPos[playing] = playersPos[playing] + dice;
                    printf("your new position is %d\n", playersPos[playing]);
                    printBoard(playersPos[playing], playing+1);
                    printf("Player %d won\n", playing+1);
                    won = 1;
                    break;
                
                    
                } else {
                    printf("you exceeded 100 so your position will not change\n");
                    printBoard(playersPos[playing], playing+1);
                }
    
            }
            
            if(won == 1){
                break;
            }
            
        
        }
        else if(entry == 2){
            showRules();
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

//function that prints the board of the game, it will also show the current player's position
void printBoard(int pos, int player){
    int change = 1;
    printf("\n");
    for(int i=100; i>0; i =i-10){
        int current;
        
        if(change == 1) {
            for(int j=0; j<10; j++){
                current = i-j;
                if(current == pos){
                    printf("Player%d ", player);
                } else {
                    printf("%d ", current);
                }
            }
        }
        
        if (change == -1) {
            for(int k=9; k>=0; k--){
                current = i-k;
                if(current == pos){
                    printf("Player%d ", player);
                } else {
                    printf("%d ", current);
                }
            }
            
        }

        printf("\n");
        change = change * -1;
    }
    printf("\n");
}

//function generates and returns a random number between 1 and 6
int diceRoll(){
    int r = rand()%7;
    if(r == 0){
        r = diceRoll();
    }
        return r;
}

//function that receives a pointer to an array as a parameter and changes the value of the array accordingly
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

//function that prints the rules of the game
void showRules(){
    printf("These are the rules: ");
    printf("You roll a dice from 1 to 6, and if you land on 6 you can roll again. \nYour position will be incremented by the number rolled.\n");
    printf("Also if you stumble onto a snake or a ladder your position will then be incremented or decremented by their specific amount.\n");
    printf("Finally to win you need to land on 100, if you exceed this number your position will not be changed until you reach the exact value.\n \n");
}
