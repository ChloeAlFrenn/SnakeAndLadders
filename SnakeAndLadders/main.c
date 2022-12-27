//
//  main.c
//  SnakeAndLadders
//
//  Created by Chloe Al-Frenn on 2022-12-27.
//

#include <stdio.h>

void printBoard(void);

int main(int argc, const char * argv[]) {
    printBoard();
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
