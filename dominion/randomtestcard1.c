#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char** argv){
	//MINION
	//random values amount of cards in hand
	
	
	srand(time(NULL));
	int i, j, k, m=0;
	int p1, p2, b1=0, b2=0, b3=0,b4=0;
	int choice1,choice2,choice3,handPos,bonus;
	struct gameState testgame;
	testgame.playedCardCount=0;
	testgame.numPlayers = MAX_PLAYERS;
	handPos =0;
	while(!(b1&&b2&&b3&&b4)){
		testgame.coins =0;
		p1=0;
		p2=0;
		choice1= rand()%2;
		choice2= rand()%2;
		testgame.whoseTurn = rand()%2;
		
		for(j=0; j< 2; j++){
			for(i=0;i < rand()%20; i++){
				testgame.deck[j][i] = copper;
				
			}
			testgame.deckCount[j] = i+1;
			for(i=0;i < rand()%10; i++){
				testgame.hand[j][i] = silver;
				
			}
			testgame.handCount[j] = i+1;
			testgame.handCount[j+2]=i+1;
			for(i=0;i < rand()%20; i++){
				testgame.discard[j][i] = gold;
				
			}
			testgame.discardCount[j] = i+1;
		}
		printf("\n****************MINION TEST*****************\n");
		printf("Iteration: %d\nPlayer's Turn: %d\n",m,testgame.whoseTurn);
		printf("Choice 1: %d	Choice 2: %d\n",choice1,choice2);
		for(j=0;j<2;j++){
			printf("Player %d Count[Hand,Deck,Discard] = [%d,%d,%d] \n", j,testgame.handCount[j],testgame.deckCount[j],testgame.discardCount[j]);
		}
		printf("\n----------------BEGIN TEST------------------\n");
		k = cardEffect(minion, choice1, choice2, choice3, &testgame, handPos, bonus);
		printf("Current Coins: %d\n", testgame.coins);
		
		for(j=0;j<testgame.handCount[0];j++){
			if(testgame.hand[0][j] != silver){
				p1 = 1;
				break;
			}
		}
		for(j=0;j<testgame.handCount[1];j++){
			if(testgame.hand[1][j] != silver){
				p2 = 1;
				break;
			}
		}
		if(choice1){
			if(testgame.coins ==2){
				printf("Minion gives correct number of coins [TEST PASS 1/3]\n");
			}
			else{
				printf("Minion gives %d coins instead of 2 [TEST FAIL 1/3]\n",testgame.coins);
			}
			
			if(!p1){
				printf("Minion did not edit the cards in players hand [TEST PASS 2/3]\n");
			}
			else{
				printf("Minion did edit the cards in players hand [TEST FAIL 2/3]\n");
			}
			if(!p2){
				printf("Minion did not edit the cards in opponents hand [TEST PASS 3/3]\n");
			}
			else{
				printf("Minion did edit the cards in players hand [TEST FAIL 3/3]\n");
			}
			b1 = 1;
		}
		else if(choice2){
			if(p1){
				printf("Minion did edit the cards in players hand [TEST PASS 1/2]\n");
			}
			else{
				printf("Minion did not edit the cards in players hand [TEST FAIL 1/2]\n");
			}
			if(!p2){
				if(testgame.handCount[3] > 4){
					printf("Minion did not edit the cards in opponents hand when they had more than 4 cards [TEST FAIL 2/2]\n");
					b2 =1;
				}
				else{
					printf("Minion did not edit the cards in opponents hand when they had less than 4 cards [TEST PASS 2/2]\n");
					b3=1;
				}
			}
			else{
				if(testgame.handCount[3] > 4){
					printf("Minion did edit the cards in opponents hand when they had more than 4 cards [TEST PASS 2/2]\n");
					b2=1;
				}
				else{
					printf("Minion did edit the cards in opponents hand when they had less than 4 cards [TEST FAIL 2/2]\n");
					b3 = 1;
				}
			}
		}
		else{
			if(testgame.coins ==0){
				printf("Minion gives correct number of coins [TEST PASS 1/3]\n");
			}
			else{
				printf("Minion gives %d coins instead of 0 [TEST FAIL 1/3]\n",testgame.coins);
			}
			if(!p1){
				printf("Minion did not edit the cards in players hand [TEST PASS 2/3]\n");
			}
			else{
				printf("Minion did edit the cards in players hand [TEST FAIL 2/3]\n");
			}
			if(!p2){
				printf("Minion did not edit the cards in opponents hand [TEST PASS 3/3]\n");
			}
			else{
				printf("Minion did edit the cards in players hand [TEST FAIL 3/3]\n");
			}
			b4=1;
		}
		printf("\n********************************************\n");
		m++;
	}
	return 0;
}