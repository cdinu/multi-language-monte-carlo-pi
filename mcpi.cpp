#include <iostream>


#define ITERATIONS 1000*1000000l


class MCPI {
    long _iterations;
	
	MCPI();
	MCPI(long iterations);
	
	double value();
public:
	static double value(long irerations);
}; 

double MCPI::value() {
        double pi = 0;

        srand ( time(NULL) );

        for(long i=1; i < _iterations; i++) {
                double randx = (double)rand() / RAND_MAX;
                double randy = (double)rand() / RAND_MAX;
                double r = randx*randx + randy*randy;

                if(0 == i%(ITERATIONS/10)) {
                        //td::cout << "(intermediary) Pi with " <<  i << " iterations is "  << 1.0f*pi/i*4 << "\n";
			printf("(intermediary) Pi with %ld iterations is %lf\n", i,  1.0f*pi/i*4);
                }
                if (r < 1) pi++;
        }
        return pi/_iterations*4;
}

MCPI::MCPI(long iterations) {
	_iterations = iterations;	
}

double MCPI::value(long iterations) {
	MCPI* instance = new MCPI(iterations);
	return instance->value();
	
}


int main(void){
	//std::cout << "PI" << MCPI::value(ITERATIONS) << "\n";
	printf("Pi with %ld iterations is %1.50lf", ITERATIONS,  MCPI::value(ITERATIONS));
	return 0;
}
