/*
Unit Test 1: Get cost test 


*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void check(int expectedValue, int valueReturned, char name[]){

    if(expectedValue != valueReturned){

        printf("###%s card returned an unexpected value from the getCost()###\n", name);
    }
    else{
        printf("%s test passed successfully\n", name);
    }
}
int main(int argc, char** argv){

    printf("<>>>>>>>>>>>>>>>>>>>>>GetCost() Fucntion Test<<<<<<<<<<<<<<<<<<<>\n");

    for(int i = 0; i <= 26; i++){

        int valueReturned = getCost(i);

        switch(i){
            case curse:
                check(0, valueReturned, "curse");
                break; 
            case estate:
                check(2, valueReturned, "estate");
                break;
            case duchy:
                check(5, valueReturned, "duchy");
                break;
            case province:
                check(8, valueReturned, "province");
                break;
            case copper:
                check(0, valueReturned, "copper");
                break;
            case silver:
                check(3, valueReturned, "silver");
                break;
            case gold:
                check(6, valueReturned, "gold");
                break;
            case adventurer:
                check(6, valueReturned, "adventurer");
                break;
            case council_room:
                check(5, valueReturned, "council_room");
                break;
            case feast:
                check(4, valueReturned, "feast");
                break;
            case gardens:
                check(4, valueReturned, "gardens");
                break;
            case mine:
                check(5, valueReturned, "mine");
                break;
            case remodel:
                check(4, valueReturned, "remodel");
                break;
            case smithy:
                check(4, valueReturned, "smithy");
                break;
            case village:
                check(3, valueReturned, "village");
                break;
            case baron:
                check(4, valueReturned, "baron");
                break;
            case great_hall:
                check(3, valueReturned, "great_hall");
                break;
            case minion:
                check(5, valueReturned, "minion");
                break;
            case steward:
                check(3, valueReturned, "steward");
                break;
            case tribute:
                check(5, valueReturned, "tribute");
                break;
            case ambassador:
                check(3, valueReturned, "ambassador");
                break;
            case cutpurse:
                check(4, valueReturned, "cutpurse");
                break;
            case embargo: 
                check(2, valueReturned, "embargo");
                break;
            case outpost:
                check(5, valueReturned, "outpost");
                break;
            case salvager:
                check(4, valueReturned, "salvager");
                break;
            case sea_hag:
                check(4, valueReturned, "sea_hag");
                break;
            case treasure_map:
                check(4, valueReturned, "treasure_map");
                break;
        }
    }
    printf("<>>>>>>>>>>>>>>>>>GetCost() Fucntion Test Completed<<<<<<<<<<<<<<<<<>\n");
}