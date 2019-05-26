#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv)	
{
	//Testing updateCoins(int player, struct gameState *state, int bonus)
	
	int coinCounter =0;
	int j,m,k;
	struct gameState testgame;
	//hand, handCount
	for(j=0; j< rand()%MAX_HAND; j++){
			m = (rand()%3)+ 4;
			testgame.hand[0][j] =m;
			if(m==copper){
				coinCounter++;
			}
			else if(m==silver){
				coinCounter += 2;
			}
			else if(m==gold){
				coinCounter += 3;
			}
	}
	testgame.handCount[0] = j;
	
	printf("\nBegin updateCoins Test-------------------------\n");
		k = updateCoins(0,&testgame,0);
		printf("\nChecking coins have been updated\n");
		
		if(testgame.coins == coinCounter){
			printf("\nCoins allocated to round is equal total coins {TEST PASS}\n");
		}
		else{
			printf("\nCoins allocated to round is equal total coins {TEST FAIL}\n");
		}
		
 	printf("\nEnd updateCoins Test---------------------------\n");
	
	return 0;
}
