
#if defined _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))


int main() {
	uint8_t t;
	scanf("%hhu\n", &t);

	for (uint8_t i = 0; i < t; ++i) {
		uint16_t x, y;
		scanf("%hu %hu\n", &x, &y);
		if (x == y) {
			printf("%hu\n", 2 * x);
		} else {
			printf("%hu\n", max(x, y) * 2 - 1);
		}
	}

	return (0);
}

