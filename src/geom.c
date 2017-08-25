

// Returns a Geometric(p) rv
int geom(double p) {
	// Sanity checks
	if(p < 0 || p > 1)
		return -1;
	
	int return_value = 1;
	// Use memoryless property to generate the rv
	int stop_loop = 0;
	while(stop_loop == 0) {
		if(rand() > p)
			return_value++;
		else
			stop_loop = 1;
	}

	return return_value;
}
