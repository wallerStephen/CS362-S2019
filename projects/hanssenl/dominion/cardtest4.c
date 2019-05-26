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
	//Baron Testing
	int handPos, bonus, choice1, choice2, choice3;
	int i,j,k;
	
	struct gameState testgame;
	testgame.playedCardCount =0;
	testgame.whoseTurn = 0;
	testgame.supplyCount[estate] =3;
	
	for(j=0; j< 20; j++){
			testgame.hand[0][j] = silver;
	}
	testgame.handCount[0] = j+1;
	for(j=0; j< 30; j++){
			testgame.deck[0][j] = great_hall;
	}
	testgame.deckCount[0] = j+1;
	for(j=0; j< 50; j++){
			testgame.discard[0][j] = tribute;
	}
	testgame.discardCount[0] = j+1;
	
	printf("\nBaron Test Start----------------------------------------\n");
	printf("\nOption 1 No estates-------------------------------------\n");
	choice1 = 0;
	testgame.coins=0;
	k = cardEffect(baron, choice1, choice2, choice3, &testgame, handPos, bonus);
	if(testgame.coins==0){
		printf("Player received no coins for no estate {TEST PASS}");
	}
	else{
		printf("Player was given coins for nonexistent estate {TEST FAIL}"); 
	}
	
	printf("\nOption 1 Estates-------------------------------------\n");
	testgame.hand[0][3] = estate;
	testgame.coins= 0;
	k = cardEffect(baron, choice1, choice2, choice3, &testgame, handPos, bonus);
	if(testgame.coins==4){
		printf("Player receives %d coins instead of 4 for estate {TEST PASS}", testgame.coins);
	}
	else{
		printf("Player was given no coins for estate{TEST FAIL}"); 
	}
	testgame.hand[0][3] = silver;
	printf("\nOption 2--------------------------------------------\n");
	choice1 = 1;
	k = cardEffect(baron, choice1, choice2, choice3, &testgame, handPos, bonus);
	for(j=0; j<testgame.handCount[0];j++){
		if(testgame.hand[0][j]==estate){
			i++;
		}
	}
	if(i>0){
		printf("Player was given an estate {TEST PASS}"); 
	}else{
		printf("Player was not given an estate{TEST FAIL}"); 
	}
	printf("\nBaron Test Complete----------------------------------------\n");
	return 0;
} 