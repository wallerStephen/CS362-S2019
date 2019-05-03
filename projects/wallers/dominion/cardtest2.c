/*
    Card test 2: adventurerFunc() function

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

        printf("#####Unexpected result in adventurerFunc() function at %s. Expected %d Result was %d####\n", str, expected, result);
    }
    else{
        printf("%s test passed successfully\n", str);
    }
}
int main(int argv, char** argc){

    printf("<>>>>>>>>>>>>>>>>>adventurerFunc() Fucntion Test<<<<<<<<<<<<<<<<<>\n");
    struct gameState state, test1, test2; 
    int kingCards[] = {gardens, adventurer, mine, remodel, great_hall, village, baron, council_room};
    initializeGame(1, kingCards, 100, &state);
    int temphand[MAX_HAND]; 


    //Baseline test 
    memcpy(&test1, &state, sizeof(struct gameState));
    test1.deckCount[0] = 2; 
    test1.deck[0][0] = copper; 
    test1.deck[0][1] = copper; 
    adventurerFunc(0, &test1, 0, 0, 0, temphand);
    check(2, test1.handCount[0], "hand count");

    memcpy(&test2, &state, sizeof(struct gameState));
    test2.deckCount[0] = 10; 
    for(int i = 0; i < 8; i++ ){ test2.deck[0][i] = baron; }
    test2.deck[0][8] = copper; 
    test2.deck[0][9] = copper; 
    adventurerFunc(0, &test2, 0, 0, 0, temphand);
    check(2, test2.handCount[0], "extra cards");

  printf("<>>>>>>>>>>>>>>>>>adventurerFunc() Fucntion Test Completed<<<<<<<<<<<<<<<<<>\n");
    
}