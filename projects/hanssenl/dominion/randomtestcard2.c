#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv){
	//salvager
	
	srand(time(NULL));
	int i, j, k, m=0;
	int b1=0,b2=0;
	int choice1,choice2,choice3,handPos,bonus;
	struct gameState testgame;
	testgame.numPlayers = 0;
	while(!(b1&&b2)){
		testgame.playedCardCount=0;
		testgame.whoseTurn = 0;
		testgame.coins= 0;
		choice1= rand()%2;
			for(i=0;i < rand()%20; i++){
				testgame.deck[0][i] = tribute;
			}
			testgame.deckCount[0] = i+1;
			k = rand()%10;
			for(i=0;i < k; i++){
				testgame.hand[0][i] = rand()%26;
			}
			handPos = 0;
			testgame.handCount[0] = i+1;	
			for(i=0;i < rand()%20; i++){
				testgame.discard[0][i] = tribute;
			}
			testgame.discardCount[0] = i+1;	
		testgame.hand[0][handPos]= salvager;
		
		printf("\n**************SALVAGER TEST*****************\n");
		printf("Iteration: %d\n",m);
		printf("Coins: %d	Choice: %d\n",testgame.coins,choice1);
		printf("Player %d Count[Hand,Deck,Discard] = [%d,%d,%d]\n", k,testgame.handCount[k],testgame.deckCount[k],testgame.discardCount[k]);
		j = testgame.hand[0][choice1];
		printf("Card to be trashed: %d",j);
		printf("\n----------------BEGIN TEST------------------\n");
		k = cardEffect(salvager, choice1, choice2, choice3, &testgame, handPos, bonus);
		
		if(choice1){
			if(j == testgame.hand[0][choice1]){
				printf("Card not trashed while being asked to do so [TEST FAIL 1/2]\n");
			}
			else{
				printf("Card trashed while being asked to do so [TEST PASS 1/2]\n");
			}
			if(testgame.coins == getCost(j)){
				printf("Correct number of coins given for card trashed [TEST PASS 2/2]\n");
			}
			else{
				printf("Incorrect number of coins given for card trashed [TEST FAIL 2/2]\n");
			}
			b1= 1;
		}
		else{
			if(j == testgame.hand[0][choice1]){
				printf("Card not trashed while being asked to do so [TEST PASS 1/2]\n");
			}
			else{
				printf("Card trashed while being asked not to do so [TEST FAIL 1/2]\n");
			}
			if(testgame.coins == 0){
				printf("No coins were given for nothing[TEST PASS 2/2]\n");
			}
			else{
				printf("Coins were given for nothing[TEST FAIL 2/2]\n");
			}
			b2 = 1;
		}
		
		printf("********************************************\n");
		m++;
	}
	return 0;
}