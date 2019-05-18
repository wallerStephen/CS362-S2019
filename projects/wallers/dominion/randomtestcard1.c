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



void checkRandomCut(struct gameState *G, int p, int cop){


    struct gameState check; 
    memcpy(&check, G, sizeof(struct gameState));  

    cutpurseFunc(p, &check);
    if(check.handCount[1] == G->handCount[1] - cop){

        printf("Copper Discarded: Expected %d Result %d - Passed\n", G->handCount[1] - cop, check.handCount[1]) ; 
    }
    else{

        printf("To pass player must reveial cards\n");
    }
    if(check.coins == G->coins + 2){

        printf("Coins were added to players count - Passed\n");
    }
}

int main(int argv, char** argc){

   
    
    printf("<<<<<<Starting CutpurseFunc Randome Test>>>>>>>\n");
    
    int i, n, p0 = 0, p1 = 1, seed, loop, k, cop; 
    struct gameState G; 
    int kingCards[] = {curse, estate,duchy, province, copper,
                    silver, gold, adventurer, council_room, feast, gardens,
                    mine, remodel, smithy,village,baron, great_hall,minion, steward, tribute,
                    ambassador, cutpurse,embargo, outpost,salvager, sea_hag,treasure_map};
    srand(time(0)); 

    for(i = 0; i < 100; i++){


        initializeGame(2, kingCards, seed, &G);
        loop = rand() % 40 + 1; 
        cop = 0; 
        seed = rand() % 1000;
        G.handCount[p1] = loop; 
        G.hand[p1][0] = cutpurse; 
      
        for(n = 1; n <= loop; n++){ 
        
            k = rand() % 27; 
            if(k == copper){

                cop++; 
            }
            
            G.hand[p1][n] = kingCards[k];
        }
        printf("Random Test #%d \n", i);  
        checkRandomCut(&G, p0, cop);
        
    }

    printf("<<<<<<<<Ending CutPurseFunc Randome Test>>>>>>>>>\n");


}