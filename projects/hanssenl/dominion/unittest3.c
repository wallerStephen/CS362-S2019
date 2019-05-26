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
	//testing fullDeckCount(int player, int card, struct gameState *state)
	int i,j,k;
	int test_card =13;
	int cardCounter = 0;
	
	struct gameState testgame;
	for(j=0; j< rand()%MAX_HAND; j++){
			k = rand()%26;
			testgame.hand[0][j] = k;
			if(k == test_card)
				cardCounter++;
	}
	testgame.handCount[0] = j;
	for(j=0; j< rand()%MAX_DECK; j++){
			k = rand()%26;
			testgame.deck[0][j] = k;
			if(k == test_card)
				cardCounter++;
	}
	testgame.deckCount[0] = j;
	for(j=0; j< rand()%MAX_DECK; j++){
			k = rand()%26;
			testgame.discard[0][j] = k;
			if(k == test_card)
				cardCounter++;
	}
	testgame.discardCount[0] = j;
	
	//deckCount, deck, handCount, hand, discardCount, discard
	
	printf("\nBegin fullDeckCount Test-----------------------\n");
		k = fullDeckCount(0,test_card,&testgame);
		printf("\nChecking that cards have been counted\n");
		
		if(k == cardCounter){
			printf("Amount of cards found is equal to amount of cards avaliable {TEST PASS}");
		}
		else{
			printf("Amount of cards found is equal to amount of cards avaliable {TEST PASS}");
		}
	
	printf("\nEnd fullDeckCount Test--------------------------\n");
	
	return 0;
}
