#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv){
	//choice1, choice2, choice3, handPos, bonus irrelevant
	
	//random variables amount of cards in deck, hand, discard
	//card types in deck, hand, discard
	//char* names[26] = ["curse","estate","duchy","province","copper","silver","gold","adventurer","council_room","feast","gardens","mine","remodel","smithy","village",baron,great_hall,minion,steward,tribute,ambassador,cutpurse,embargo,outpost,salvager,sea_hag,treasure_map];
	srand(time(NULL));
	int i,j,q, k,t, m=0;
	int b1= 0,b2= 0,b3= 0;
	int choice1,choice2,choice3,handPos,bonus;
	struct gameState testgame;
	testgame.numPlayers = MAX_PLAYERS;
	while(!(b1&&b2&&b3)){
		j=0;
		q=0;
		testgame.whoseTurn = 0;
			for(i=0;i < rand()%50; i++){
				k=rand()%26;
				testgame.deck[0][i] = k;
				if(k==4|k==5|k==6){
					q++;
				}
			}
			testgame.deckCount[0] = i+1;
			testgame.handCount[0] = 0;
			for(i=0;i < rand()%20; i++){
				k = rand()%26;
				testgame.discard[0][i] = k;
				if(k==4|k==5|k==6){
					j++;
				}
			}
			testgame.discardCount[0] = i+1;	
			t=j+q;
		printf("\n**************ADVENTURER TEST***************\n");
		printf("Iteration: %d\n",m);
			printf("Player Card Count[Deck,Discard] = [%d,%d] \n",testgame.deckCount[0],testgame.discardCount[0]);
			printf("Treasures in[Total,Deck,Discard] = [%d,%d,%d] \n",t,q,j);
		printf("\n----------------BEGIN TEST------------------\n");
		k = cardEffect(adventurer, choice1, choice2, choice3, &testgame, handPos, bonus);
					//check to see if hand has 2 more treasures
			//printf("Cards in hand= \n");
			j=0;
			for(i=0; i< testgame.handCount[0]; i++){
				//printf("%d ",testgame.hand[0][i]);
				if(testgame.hand[0][i]==4|testgame.hand[0][i]==5|testgame.hand[0][i]==6){
					j++;
				}
			}
			for(i=0; i< testgame.deckCount[0]; i++){
				if(testgame.deck[0][i]==4|testgame.deck[0][i]==5|testgame.deck[0][i]==6){
					q++;
				}
			}
			for(i=0; i< testgame.deckCount[0]; i++){
				if(testgame.discard[0][i]==4|testgame.discard[0][i]==5|testgame.discard[0][i]==6){
					q++;
				}
			}
		if(t >= 2){
			printf("Enough Treasures avaliable\n");

			if(j==2){
				printf("\nTwo treasures have been added[TEST PASS 1/2]");
			}
			else{
				printf("\nTwo treasures have not been added[TEST FAIL 1/2]");
			}
			if(q==t-2){
				printf("\nTwo treasures have been removed[TEST PASS 2/2]");
			}
			else{
				printf("\nTwo treasures have not been removed[TEST FAIL 2/2]");
			}
			b1 = 1;
		}
		else if(t == 1){
			printf("One Treasure avaliable\n");
			//check to see if hand has 1 more treasure
			if(j==1){
				printf("\nOne treasure have been added[TEST PASS 1/2]");
			}
			else{
				printf("\nOne treasure have not been added[TEST FAIL 1/2]");
			}
			if(q==t-1){
				printf("\nOne treasure have been removed[TEST PASS 2/2]");
			}
			else{
				printf("\nOne treasure has not been removed[TEST FAIL 2/2]");
			}
			b2= 1;
		}
		else{
			printf("No Treasures avaliable\n");
			//check to see that hand is unchanged
			if(j==0){
				printf("\nNo treasures have been added[TEST PASS 1/2]");
			}
			else{
				printf("\nTreasures have been added[TEST FAIL 1/2]");
			}
			if(q==t){
				printf("\nNo treasures have been removed[TEST PASS 2/2]");
			}
			else{
				printf("\nTreasures have been removed[TEST FAIL 2/2]");
			}
			b3= 1;
		}
		printf("\n\n********************************************\n");
		m++;
	}
	return 0;
}