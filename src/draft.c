#include "stdio.h"

int main() {

	int f[] = { 5, 4, 0, 1 };
	int g[] = { 1, 2, 7, 0 };

	int left = -3;
	int right = 3;
	int position;
	int n, k;
	
	for (position = left; position <= right; position++) {
		int from = position <= 0 ? 0 : position;
		int to = position >= 0 ? right : right + position;
		int sum = 0;
	
		for (n = from; n <= to; n++) {
			sum += f[n] * g[n - position];
			// printf("%i * %i\n", f[n], g[n - position]);

		}
		
		printf("%i\n", sum);
	}

	return 0;

}
