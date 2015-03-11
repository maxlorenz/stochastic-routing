#include <stdio.h>

#include "convolution.h"


int main() {

	float f[] = { 0.5, 0.5 };
	float g[] = { 0.5, 0.5 };
	
	float *result = convolute(f, g, 2);

	int i;
	for (i = 0; i < 3; i++)
		printf("%f\n", result[i]);

	return 0;

}
