/*
    Unit Test 3: isGameOver() function

*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>




void check(int expected, int result, char str[]){

    if(result != expected){

        printf("#####Unexpected result in isGameOver() function at %s. Expected %d Result was %d####\n", str, expected, result);
    }
    else{
        printf("%s test passed successfully\n", str);
    }
}
int main(int argv, char** argc){

    printf("<>>>>>>>>>>>>>>>>>isGameOver() Fucntion Test<<<<<<<<<<<<<<<<<>\n");
    struct gameState state, test0, test1, test2; 
    int isOver = 0; 
    
    //test baseline 
    memcpy(&test0, &state, sizeof(struct gameState));
    for(int i = 0; i < 27; i++){

        test0.supplyCount[i] = 1; 
    }
    isOver = isGameOver(&test0);
    check(0, isOver, "baseline check");

    //Check for game over for province cards 
    memcpy(&test1, &state, sizeof(struct gameState));
    for(int i = 0; i < 27; i++){ test1.supplyCount[i] = 10;}
    test1.supplyCount[province] = 0; 
    isOver = isGameOver(&test1);
    check(1, isOver, "Province check");

    //Check 3 piles of cards 
    memcpy(&test2, &state, sizeof(struct gameState));     
        
    for(int i = 0; i < 27; i++){ test2.supplyCount[i] = 10;}
    test2.supplyCount[7] = 0;
    test2.supplyCount[8] = 0;
    test2.supplyCount[9] = 0;

    isOver = isGameOver(&test2);
    check(1, isOver, "three cards test");
    printf("<>>>>>>>>>>>>>>>>>isGameOver() Fucntion Test Completed<<<<<<<<<<<<<<<<<>\n");
}