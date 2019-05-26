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
	//testing shuffle(int player, struct gameState *state)
	int j,k;
	int test_deck[MAX_DECK];
	struct gameState testgame;
	
	for(j=0; j< rand()%MAX_DECK; j++){
		k = rand()%26;
		test_deck[j] = k;
		testgame.deck[0][j] = k;
	}
	testgame.deckCount[0] = j;
	
	
	//Shuffle test
	printf("\nBegin Shuffle Test-----------------------------\n");
		k = shuffle(0,&testgame);
		
	printf("\nChecking deck has been shuffled\n");
	for(j=0;j<testgame.deckCount[0];j++){
		if(testgame.deck[0][j] != test_deck[j]){
			printf("\nShuffled deck is not equal to reference deck {TEST PASS}\n");
			break;
		}
	}
	if(j == testgame.deckCount[0]-1){
		printf("\nShuffled deck is equal to reference deck {TEST FAIL}\n");
	}

 	printf("\nEnd Shuffle Test-------------------------------\n");
	
	return 0;
}