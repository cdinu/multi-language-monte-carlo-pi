import java.util.Random;

public class MCPI {
	public final static long ITERATIONS = 1000*1000000;
	private long _iterations;

	public MCPI(long iterations) {
		this._iterations = iterations;
	}

	public double value() {
		Random r = new Random();
		long pi = 0;

		for (int i = 1; i < _iterations; i++) {
			double x = r.nextDouble();
			double y = r.nextDouble();
			double d = x*x + y*y;
            
			if (d < 1) pi++;

            
			if(0 == i%(ITERATIONS/10)) {
                		System.out.println("x=" + x + "y=" + y + " r=" + d);
            			System.out.println("(intermediary) PI with " + i  + " iteration is " + ((double)pi/i)*4);
			}

		}

		return (double)pi/_iterations*4;
	}

	public static void main(String[] args) {
		MCPI _i = new MCPI(ITERATIONS);
		double PI = _i.value();

		System.out.println("PI with " + ITERATIONS + " iteration is " + PI);
	}
} 
