#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ITERATIONS 1000*1000000l

double mcpi(long iterations){
	double pi = 0;

	srand ( time(NULL) );

	for(long i=1; i < iterations; i++) {
                double randx = (double)rand() / RAND_MAX;
                double randy = (double)rand() / RAND_MAX;
 
		double r = randx*randx + randy*randy;

		if(0 == i%(ITERATIONS/10)) {
			printf("(intermediary) Pi with %ld iterations is %lf\n", i,  1.0f*pi/i*4);
		}
		if (r < 1) pi++;
	}
	return pi/iterations*4;
}

int main() {

	printf("Pi with %ld iterations is %1.50lf", ITERATIONS,  mcpi(ITERATIONS));
	return 0;
}

