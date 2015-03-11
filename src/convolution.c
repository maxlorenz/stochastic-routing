#include <stdio.h>
#include <stdlib.h>

#include "convolution.h"

float *convolute(float f[], float g[], int length) {

	// Return array, convolution yields 2*n - 1 results
	float *result = malloc((2*length - 1) * sizeof(float));

	// Convoluting two discrete functions with n values yields 2n - 1 results
	// Because of this, I use ]-n, n[ as the index
	int right = length - 1; 			
	int left = - right; 
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
		
		result[position + right] = sum;
	}

	return result;
}

