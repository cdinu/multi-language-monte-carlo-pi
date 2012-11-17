sys = require("sys");

function mcpi() {
	var pi = 0;
	var i;
	
	var start = new Date().getTime();
	var now = 0;

	for(i = 1; i<100000000;i++) {
		var x = Math.random();
		var y = Math.random();
		var r = x*x + y*y;
		if (r < 1) pi++;
		
		now = (new Date().getTime() - start)/1000;
		if(0 == i%(100000000/10)) {
			sys.puts(4.0*pi/i + " after " +  now + "s<br/>");
                }

	}
	return pi/100000000*4.0;
}

sys.puts(mcpi());
