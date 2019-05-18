/*
    Random Test 1: Adventurer Func
    Bugs: Segmentation fualt in adventurer line 1239
            int cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]];//top card of hand is most recently drawn card.


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
  
    int handPos = 0, drawnTreasure = 0, z = 0; 
    int temphand[MAX_HAND];
    struct gameState check; 
     

    memcpy(&check, G, sizeof(struct gameState));  
    adventurerFunc(p, &check, handPos, drawnTreasure, z, temphand);
    
    if(check.handCount[p] != G->handCount[p] + 2){

        printf("Error With HandCount: Expected %d Received %d\n", G->handCount[p] + 2, check.handCount[p]); 
    }
}
int main(int argv, char **argc){

    int i, n, p, seed, loop, k, loop2, r; 
    struct gameState G; 
    int kingCards[] = {curse, estate,duchy, province, copper,
                    silver, gold, adventurer, council_room, feast, gardens,
                    mine, remodel, smithy,village,baron, great_hall,minion, steward, tribute,
                    ambassador, cutpurse,embargo, outpost,salvager, sea_hag,treasure_map};
    srand(time(0)); 
    
    printf("<<<<<<Starting AdventurerFunc Randome Test>>>>>>>\n");
    
    for(i = 0; i < 50; i++){

        
        p = rand() % 2 + 1; 
        seed = rand() % 1000;
        initializeGame(p, kingCards, seed, &G);
        loop = rand() % 40 + 1; 
        loop2 = rand() % 20 + 1;
        G.deckCount[p] = loop; 
        G.handCount[p] = loop2;

        for(n = 0; n < loop2; n++){ 
        
            k = rand() % 27; 
            G.hand[p][n] = kingCards[k];
        } 

        for(n = 0; n < loop; n++){ 
        
            k = rand() % 27; 
            G.deck[p][n] = kingCards[k];
        }

        r = rand() % loop + 2; 
        k = rand() % 6 + 4; 

        G.hand[p][r] = kingCards[k]; 

        G.hand[p][0] = adventurer;
        printf("Random Test #%d \n", i);  
        checkRandom(&G, p);
        
    }
    printf("<<<<<<<<Ending AdventurerFunc Randome Test>>>>>>>>>\n");
}