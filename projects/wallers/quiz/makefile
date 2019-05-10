
CFLAGS = -Wall -fpic -coverage -lm

testme:
	gcc -o testme -g testme.c $(CFLAGS)

tester: testme 
	./testme
	
all: testme tester

clean:
	rm -f testme *.gcov *.gcda *.gcno *.o