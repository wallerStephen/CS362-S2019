/*
    Card test 4: stewardFunc() function

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

    printf("<>>>>>>>>>>>>>>>>>>>>>stewardFunc() Fucntion Test<<<<<<<<<<<<<<<<<<<>\n");
    struct gameState state, test1, test2, test3; 
    int kingCards[] = {gardens, adventurer, mine, remodel, great_hall, village, baron, council_room};
    initializeGame(1, kingCards, 100, &state);
    state.handCount[0] = 1; 
    state.hand[0][0] = steward; 

    //Test choice 1
    memcpy(&test1, &state, sizeof(struct gameState));
    test1.deckCount[0] = 2; 
    test1.deck[0][0] = 1; 
    test1.deck[0][1] = 1; 
    stewardFunc(0, 0, &test1, 1, 0, 0);
    check(2, test1.handCount[0], "choice 1 test"); 

    //choice 2 test
    memcpy(&test2, &state, sizeof(struct gameState));
    stewardFunc(0, 0, &test2, 2, 0, 0);
    check(2, test2.coins, "choice 2 test"); 
    
    //choice 3 test 
    memcpy(&test3, &state, sizeof(struct gameState));
    test3.handCount[0] += 2; 
    test3.hand[0][1] = 1; 
    test3.hand[0][2] = 1;
    stewardFunc(0, 0, &test3, 3, 1, 2);
    check(0, test3.handCount[0], "choice 3 test"); 

    printf("<>>>>>>>>>>>>>>>>>>>>>stewardFunc() Fucntion Test Completed<<<<<<<<<<<<<<<<<<<>\n");
    

}