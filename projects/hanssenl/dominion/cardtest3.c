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
	//Minion Testing
	int choice1, choice2, choice3, bonus;
	int i,j,k;
	int handPos = 4;
	int test_hand[50];
	struct gameState testgame;
	testgame.whoseTurn= 0;
	for(i=0; i < 2; i++){
		for(j=0; j<3;j++){
			testgame.deck[i][j] = tribute;
			testgame.hand[i][j] = remodel;
			testgame.discard[i][j] = great_hall;
		}
		testgame.deckCount[i] = j;
		testgame.handCount[i] = j;
		testgame.discardCount[i] = j;
	}
	
	
	testgame.deck[0][4] = minion;
	printf("\nMinion Test Start---------------------------------------\n");
	
	printf("\nTesting Option 1----------------------------------------\n");
	choice1 = 1;
	choice2 = 0;
	testgame.coins = 0;
	k = cardEffect(minion, choice1, choice2, choice3, &testgame, handPos, bonus);
		if(testgame.coins == 2){
			printf("\n2 coins added to Players turn {TEST PASS}\n");
		}
		else
			printf("\nAdded %d coins instead of 2 {TEST FAIL}\n", testgame.coins);
	
	printf("\nTesting Option 2: Less than 5 cards---------------------\n");
	choice1 = 0;
	choice2 = 1;
	
	i=0;
	k = cardEffect(minion, choice1, choice2, choice3, &testgame, handPos, bonus);
	if(testgame.handCount[0]==4 && testgame.handCount[1]==3){
		printf("The Player Now has 4 card and the opponent still has 3 {TEST PASS}");
	}
	else{
		printf("The Player has %d cards not 4 and the opponent has %d not his original 3 {TEST FAIL}",testgame.handCount[0],testgame.handCount[1]);
	}
	printf("\nTesting Option 2: More than 5 cards---------------------\n");
	testgame.hand[1][4] = tribute;
	testgame.hand[1][3] = tribute;
	testgame.handCount[1]= 5;
	
	i=0;
	k = cardEffect(minion, choice1, choice2, choice3, &testgame, handPos, bonus);
	if(testgame.handCount[0]==4 && testgame.handCount[1]==3){
		printf("The Player and Opponent both now have 4 cards {TEST PASS}");		
	}
	else{
		printf("The Player has %d cards not 4 and the opponent has %d not 4 {TEST FAIL}",testgame.handCount[0],testgame.handCount[1]);
	}
	
	printf("\nMinion Test Complete---------------------------------------\n");
	
	return 0;
	
}