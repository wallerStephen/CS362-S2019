/*
    Card test 1: cutpurseFunc() function

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

    printf("<>>>>>>>>>>>>>>>>>>>>>cutpurseFunc() Fucntion Test Completed<<<<<<<<<<<<<<<<<<<<<<>\n");
    struct gameState state, test1, test2; 
    int kingCards[] = {gardens, adventurer, mine, remodel, great_hall, village, baron, council_room};
    initializeGame(2, kingCards, 100, &state);
    state.handCount[0] = 1;
    state.hand[0][0] = cutpurse;

    //show copper test 
    memcpy(&test1, &state, sizeof(struct gameState));
    test1.handCount[1] = 1; 
    test1.hand[1][0] = copper; 
    cutpurseFunc(0, &test1, 0);
    check(2, test1.coins, "coins test"); 
    check(0, test1.handCount[1], "discard copper test");

    //Test no copper show cards 
    //Should show 5 outputs of cards not copper
    memcpy(&test2, &state, sizeof(struct gameState));
    test2.handCount[1] = 3;
    for(int i = 0; i < 3; i++){ test2.hand[1][i] = baron;} 
    cutpurseFunc(0, &test2, 0);
    printf("<>>>>>>>>>>>>>>>>>>>>>cutpurseFunc() Fucntion Test Completed<<<<<<<<<<<<<<<<<<<<<<>\n");
}