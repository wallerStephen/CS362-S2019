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
	//testing getCost(int cardNumber)
	
	int testCosts[27] = {0,2,5,8,0,3,6,6,5,4,4,5,4,4,3,4,3,5,3,5,3,4,2,5,4,4,4};
	
	int i;
	printf("\nBegin getCost Test-----------------------------\n\n");
	for(i = 0; i< 27; i++){
		if(getCost(i) == testCosts[i]){
			printf("Card %d pulls the correct cost{TEST PASS}\n", i);
		}
		else{
			printf("Card %d does not pull the correct cost{TEST FAIL}\n", i);
		}
	}
	printf("\nEnd getCost Test-------------------------------\n");
	
	return 0;
}
