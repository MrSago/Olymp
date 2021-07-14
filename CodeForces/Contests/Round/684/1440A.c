
#if defined _MSC_VER
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))


int main() {
	uint8_t t;
	scanf("%hhu\n", &t);

	unsigned long* res = (unsigned long*)malloc(sizeof(unsigned long) * t);

	for (uint8_t i = 0; i < t; ++i) {
		uint16_t n, a, b, h;
		uint16_t count = 0;
		char c;

		scanf("%hu %hu %hu %hu\n", &n, &a, &b, &h);
		while ((c = getchar()) != '\n') {
			if (c == '0') {
				++count;
			}
		}

		if (b < a) {
			uint16_t tmp = a;
			a = b;
			b = tmp;
			count = n - count;
		}

		res[i] = (unsigned long)count * (unsigned long)a + (unsigned long)(n - count) * min((unsigned long)h + (unsigned long)a, (unsigned long)b);
	}

	for (uint8_t i = 0; i < t; ++i) {
		printf("%lu\n", res[i]);
	}

	return (0);
}

