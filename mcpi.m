#import <Foundation/Foundation.h>

#define ITERATIONS 1000*1000000l

@interface MCPI:NSObject

@property (nonatomic) long iterations;
@property (nonatomic,readonly) double value;

-(MCPI*)initWithIterations:(long)iterations;
@end

@implementation MCPI

@synthesize iterations = _iterations;
@synthesize value = _value;

-(MCPI*)initWithIterations:(long)iterations{
	self = [super init];
	self.iterations =  iterations;
	return self;
}

-(double)value {
	double pi = 0;

	srand ( time(NULL) );

	long _i = self.iterations;

	for(long i=1; i < _i; i++) {
                double randx = (double)rand() / RAND_MAX;
                double randy = (double)rand() / RAND_MAX;
 
		double r = randx*randx + randy*randy;

		if(0 == i%(ITERATIONS/10)) {
			NSLog(@"(intermediary) Pi with %ld iterations is %lf", i,  1.0f*pi/i*4);
		}

		if (r < 1) pi++;
	}
	return 4.0 * pi/_i;
}
@end

int main() {
	
	MCPI* mcpi = [[MCPI alloc] initWithIterations: ITERATIONS];

	NSLog(@"Pi with %ld iterations is %1.50lf", ITERATIONS,  mcpi.value);
	return 0;
}

