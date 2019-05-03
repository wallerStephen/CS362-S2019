/*
    Card test 1: smithyFunc() function

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

        printf("#####Unexpected result in smithyFunc() function at %s. Expected %d Result was %d####\n", str, expected, result);
    }
    else{
        printf("%s test passed successfully\n", str);
    }
}
int main(int argv, char** argc){

    printf("<>>>>>>>>>>>>>>>>>smithyFunc() Fucntion Test<<<<<<<<<<<<<<<<<>\n");
    struct gameState state, test1; 
    int kingCards[] = {gardens, adventurer, mine, remodel, great_hall, village, baron, council_room};
    initializeGame(1, kingCards, 100, &state);
    state.deckCount[0] = 10;
    state.handCount[0] = 1;
    for(int i = 0; i < 10; i++){ state.deck[0][i] = 1;}

    //Test smithy function for drawing 3 cards from deck and discard 
    //Expected result should be 3 cards in hand 
    
    memcpy(&test1, &state, sizeof(struct gameState)); 
    smithyFunc(0, &test1, 0);
    check(3, test1.handCount[0], "cards in hand");
    check(7, test1.deckCount[0], "deck count");   
    printf("<>>>>>>>>>>>>>>>>>smithyFunc() Fucntion Test Completed<<<<<<<<<<<<<<<<<>\n");
}
