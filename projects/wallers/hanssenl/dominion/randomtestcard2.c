/*
    Random Test 2: CutPurseFunc
    Bug - found bug in cut purse loop does not go to full hand count 


*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>


void checkRandom(struct gameState *G, int p){

    struct gameState check; 
    memcpy(&check, G, sizeof(struct gameState));

    smithyFunc(p, &check, 0);

    if(check.handCount[p] != G->handCount[p] + 2){

        printf("Hand Count Has Unexpected Value: Expected %d Result %d\n", G->handCount[p] + 2, check.handCount[p]);
    }
    if(check.deckCount[p] != G->deckCount[p] - 1){

        printf("Error With Deck in Smithy: Expected %d Result %d \n", G->deckCount[p] - 3,  check.deckCount[p]);
    }

}
int main(){

    printf("<<<<<<Starting SmithyFunc Randome Test>>>>>>>\n");
    
    int i, n, p, seed, loop, k, loop2; 
    struct gameState G; 
    int kingCards[] = {curse, estate,duchy, province, copper,
                    silver, gold, adventurer, council_room, feast, gardens,
                    mine, remodel, smithy,village,baron, great_hall,minion, steward, tribute,
                    ambassador, cutpurse,embargo, outpost,salvager, sea_hag,treasure_map};


    for(i = 0; i < 100; i++){

        p = rand() % 4 + 1; 
        seed = rand() % 1000;
        initializeGame(p, kingCards, seed, &G);
        loop = rand() % 80 + 1; 
        loop2 = rand() % 20 + 1; 
        G.handCount[p] = loop2; 
        for(int u = 0; u < loop2; u++){

            k = rand() % 27; 
            G.hand[p][n] = kingCards[k];
        }

        G.deckCount[p] = loop; 
        G.hand[p][0] = smithy; 

        for(n = 0; n < loop; n++){ 
        
            k = rand() % 27; 
            G.deck[p][n] = kingCards[k];
        }
        printf("Random Test #%d \n", i);  
        checkRandom(&G, p);


    } 
    printf("<<<<<<<<Ending SmithyFunc Randome Test>>>>>>>>>\n");

}