/*
    Unit Test 2: ScoreFor() function

*/
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

#define MAXCARDS 10

void check(int expected, int result, char line[]){

    if(expected != result){

        printf("###%s scoreFore(). Expected %d Result was %d##\n", line, expected, result);
    }
	else{
        printf("%s test passed successfully\n", line);
    }
}
int main(int argc, char** argv){

	struct gameState state, test1, test2, test3, test4; 
	int player = 2; 
	int score = 0; 
	int i = 0;	
	
	printf("<>>>>>>>>>>>>>>>>>>>>>scoreFor() Fucntion Test<<<<<<<<<<<<<<<<<<<>\n");

	score = scoreFor(player, &state);  
	check(0, score, "No players no cards returned unexpected results");

	

	//test negative numbers 
	memcpy(&test1, &state, sizeof(struct gameState));
	test1.handCount[i] = 1;
	test1.hand[i][0] = curse;  
	score = scoreFor(i, &test1);
	check(-1, score, "Unexpected result with curse card. ");
		
	//test hand count 
	memcpy(&test2, &state, sizeof(struct gameState));
	test2.handCount[i] = 10;
	test2.hand[i][0] = curse;
	test2.hand[i][1] = estate; 
	test2.hand[i][2] = duchy; 
	test2.hand[i][3] = province; 
	test2.hand[i][4] = great_hall; 
	test2.hand[i][5] = gardens; 
	test2.hand[i][6] = copper; 
	test2.hand[i][7] = copper; 
	test2.hand[i][8] = copper; 
	test2.hand[i][9] = copper; 
	score = scoreFor(i, &test2);
	check(11, score, "Returned an unexpected result handCount loop");

	//test discard count
	memcpy(&test3, &state, sizeof(struct gameState));
	test3.handCount[i] = 10;
	test3.hand[i][0] = curse;
	test3.hand[i][1] = estate; 
	test3.hand[i][2] = duchy; 
	test3.hand[i][3] = province; 
	test3.hand[i][4] = great_hall; 
	test3.hand[i][5] = gardens; 
	test3.hand[i][6] = copper; 
	test3.hand[i][7] = copper; 
	test3.hand[i][8] = copper; 
	test3.hand[i][9] = copper; 
	score = scoreFor(i, &test3);
	check(11, score, "Returned an unexpected result discardCount loop");

	//test deck count
	memcpy(&test4, &state, sizeof(struct gameState));
	test4.handCount[i] = 10;
	test4.hand[i][0] = curse;
	test4.hand[i][1] = estate; 
	test4.hand[i][2] = duchy; 
	test4.hand[i][3] = province; 
	test4.hand[i][4] = great_hall; 
	test4.hand[i][5] = gardens; 
	test4.hand[i][6] = copper; 
	test4.hand[i][7] = copper; 
	test4.hand[i][8] = copper; 
	test4.hand[i][9] = copper; 
	score = scoreFor(i, &test4);
	check(11, score, "Returned an unexpected result discardCount loop");

	printf("<>>>>>>>>>>>>>>>scoreFor() Fucntion Test Completed<<<<<<<<<<<<<<<>\n");

}