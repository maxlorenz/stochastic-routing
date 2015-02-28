#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "complex.h"

complex double transform(int n, int k) {
	complex double argument = (2.0 * M_PI * k) / n;
	return cos(argument) - I * sin(argument);
}

complex double *fft(int n, complex double *f) {

	if (n == 1)
		return f;

	complex double *tmp 	= malloc(n/2 * sizeof(complex double));
	complex double *tmp2 	= malloc(n/2 * sizeof(complex double));
	complex double *c 		= malloc(n/2 * sizeof(complex double));

	int i;
	for (i = 0; i < n; i = i + 2) {
		tmp[i] = f[i];
		tmp2[i] = f[i + 1];
	}

	complex double *g = fft(n/2, tmp);
	complex double *u = fft(n/2, tmp2);

	int k;
	for (k = 0; k <= n/2; k++) {
		printf("k = %i, n/2 = %i\n", k, n/2);
		c[k] 		= g[k] + u[k] * transform(n, k); 
		c[k + n/2] 	= g[k] - u[k] * transform(n, k);
	}

	return c;	
}

int main() {
	complex double f[] = { 1.0, 2.0, 3.0, 4.0, 1.0, 2.0, 3.0, 4.0 };
	complex double *test = fft(8, f);

	// DEBUG
	int x;
	for (x = 0; x < 8; x++) {
		printf("%f i%f\n", creal(test[x]), cimag(test[x]));	
	}

	return 0;
}
