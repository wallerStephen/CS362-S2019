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
	int choice1,choice2,choice3,bonus;
	
	int i,j,k;
	int handPos = 13;
	struct gameState testgame;
	testgame.whoseTurn =0;
	testgame.playedCardCount =0;
	
	
	for(j=0; j< 20; j++){
		testgame.hand[0][j] = silver;
	}
	testgame.handCount[0] = j;
	testgame.hand[0][13] = smithy;
	
	for(j=0; j< 30; j++){
			testgame.deck[0][j] = great_hall;
	}
	testgame.deckCount[0] = j;
	for(j=0; j< 50; j++){
			testgame.discard[0][j] = tribute;
	}
	testgame.discardCount[0] = j;

	printf("\nSmithy Test Start---------------------------------------\n");
	
	k = cardEffect(smithy, choice1, choice2, choice3, &testgame, handPos, bonus);
	i = testgame.handCount[0]-i;
	
	if(i == 3){
		printf("\nHand has 3 more card after Smithy {TEST PASS}\n");
	}
	else{
		printf("\nHand dones not contain %d more cards not 3{TEST FAIL}\n", i);
	}
	
	printf("\nSmithy Test Complete------------------------------------\n");
	
	return 0;
}