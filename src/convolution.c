#include "convolution.h" // defines printf
#include "stdio.h" // defines printf

#define ARRAY_LENGTH(array) (&array)[1] - array

void convolute(float f[], float g[]) {

	// Convoluting two discrete functions with n values yields 2n - 1 results
	// Because of this, I use ]-n, n[ as the index
	int left = ARRAY_LENGTH(f) + 1; 
	int right = - left; 			
	int position;
	int n;
	
	for (position = left; position <= right; position++) {

		// Calculate range for which f and g are defined
		int from = 	position <= 0 ? 0 		: position;
		int to = 	position >= 0 ? right 	: right + position;

		float sum = 0;
	
		for (n = from; n <= to; n++) {
			sum += f[n] * g[n - position];
		}
		
		printf("%f\n", sum);
	}
}

