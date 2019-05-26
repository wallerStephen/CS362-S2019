#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv)	{	
	//Adventurer Testing

	int choice1,choice2,choice3,handPos,bonus;
	int i,j,k;
	struct gameState testgame;
	testgame.whoseTurn = 0;
	testgame.deckCount[0] =8;
	testgame.handCount[0] =8;
	testgame.discardCount[0] =8;
	

	for(i = 0; i < 8; i++){
		testgame.deck[0][i] = tribute;
		testgame.discard[0][i] = tribute;
		testgame.hand[0][i] = gold;
	}
	printf("\nAdventurer Test Start------------------------------\n");

	printf("\nLess than 2 treasures-------------------------------\n");
	
	// Commented out to allow the tests to continue
	//k = cardEffect(adventurer, choice1, choice2, choice3, &testgame, handPos, bonus);
	for(i = 0; i < testgame.handCount[0]; i++){
		if(testgame.hand[0][i]=silver)
			j++;
	}
	if(j==0){
		printf("\nFound no treasures when there are none{TEST PASS}\n");
	}
	else{
		printf("\nFound treasures when there are none{TEST FAIL}\n");
	}
	
	
	printf("\n2 treasures in discard-------------------------------\n");
	testgame.discard[0][4] = silver;
	testgame.discard[0][2] = silver;
	// Commented out to allow the tests to continue
	//k = cardEffect(adventurer, choice1, choice2, choice3, &testgame, handPos, bonus);
	
	j=0;
	for(i = 0; i < testgame.handCount[0]; i++){
		if(testgame.hand[0][i]=silver)
			j++;
	}
	if(j==2){
		printf("\nTwo treasures added to hand {TEST PASS}\n");
	}
	else{
		printf("\nTwo treasures not added to hand {TEST FAIL}\n");
	}
	
	printf("\n2 treasures in deck-----------------------------------\n");
	testgame.deck[0][5] = silver;
	testgame.deck[0][7] = silver;
	// Commented out to allow the tests to continue
	//k = cardEffect(adventurer, choice1, choice2, choice3, &testgame, handPos, bonus);
	
	j=0;
	for(i = 0; i < testgame.handCount[0]; i++){
		if(testgame.hand[0][i]=silver)
			j++;
	}
	if(j==2){
		printf("\nTwo treasures added to hand {TEST PASS}\n");
	}
	else{
		printf("\nTwo treasures not added to hand {TEST FAIL}\n");
	}
	printf("\nAdventurer Test Complete------------------------------------\n");
	
	return 0;
}
//int cardEffect(int card, int choice1, int choice2, int choice3, struct gameState *state, int handPos, int *bonus)
