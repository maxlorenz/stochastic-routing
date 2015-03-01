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
	for (i = 0; i <= n; i = i + 2) {
		printf("i=%i, n=%i\n", i, n);
		tmp[i] = f[i];
		tmp2[i] = f[i + 1];
	}

	printf("Berechne g\n");
	complex double *g = fft(n/2, tmp);
	printf("Berechne u\n");
	complex double *u = fft(n/2, tmp2);

	int k;
	for (k = 0; k < n/2; k++) {
		printf("Setze zusammen: k=%i, n/2=%i, k + n/2=%i\n", k, n/2, k + n/2);
		c[k] 		= g[k] + u[k] * transform(n, k); 
		printf("c[%i]=%f i%f\n", k, creal(c[k]), cimag(c[k]));	
		c[k + n/2] 	= g[k] - u[k] * transform(n, k);
		printf("c[%i]=%f i%f\n", k, creal(c[k]), cimag(c[k]));	
	}

	return c;	
}

int main() {
	complex double f[] = { 8, 4 };
	complex double *test = fft(2, f);

	// DEBUG
	int x;
	for (x = 0; x < 2; x++) {
		printf("%f i%f\n", creal(test[x]), cimag(test[x]));	
	}

	return 0;
}
