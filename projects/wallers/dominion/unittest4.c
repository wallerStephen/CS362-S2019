/*
    Unit Test 4: fullDeckCount() function

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

        printf("#####Unexpected result in fullDeckCount() function at %s. Expected %d Result was %d####\n", str, expected, result);
    }
    else{
        printf("%s test passed successfully\n", str);
    }
}
int main(int argv, char** argc){

        printf("<>>>>>>>>>>>>>>>>>fullDeckCount() Fucntion Test<<<<<<<<<<<<<<<<<>\n");
    struct gameState state, test1, test2, test3; 
    //checks for count of card in discard
    memcpy(&test1, &state, sizeof(struct gameState));
    test1.deckCount[0] = 26; 
    for(int i = 0; i < test1.deckCount[0]; i++){ test1.deck[0][i] = i;}
    for(int i = 0; i < test1.deckCount[0]; i++){ 
        
        int result = fullDeckCount(0, i, &test1);
        check(1, result, "loop for deck count"); 

    }
    //checks for count of card in discard
    memcpy(&test2, &state, sizeof(struct gameState));
    test2.handCount[0] = 26; 
    for(int i = 0; i < test2.handCount[0]; i++){ test2.hand[0][i] = i;}
    for(int i = 0; i < test2.handCount[0]; i++){ 
        
        int result = fullDeckCount(0, i, &test2);
        check(1, result, "loop for hand count"); 

    }
    //checks for count of card in discard
    memcpy(&test3, &state, sizeof(struct gameState));
    test3.discardCount[0] = 26; 
    for(int i = 0; i < test3.discardCount[0]; i++){ test3.discard[0][i] = i;}
    for(int i = 0; i < test3.discardCount[0]; i++){ 
        
        int result = fullDeckCount(0, i, &test3);
        check(1, result, "loop for hand count"); 

    }  
        printf("<>>>>>>>>>>>>>>>>>fullDeckCount() Fucntion Test Completed<<<<<<<<<<<<<<<<<>\n"); 
}