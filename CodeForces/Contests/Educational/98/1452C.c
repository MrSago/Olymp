
#include <stdio.h>
#include <stdint.h>


int main() {
	uint16_t t;
	scanf("%hu\n", &t);

	while (t--) {
		uint32_t a = 0, b = 0;
		uint32_t res = 0;
		int c;
		while ((c = getchar()) != '\n') {
			switch (c) {
			case '(':
				++a;
				break;
			case ')':
				if (a) {
					--a;
					++res;
				}
				break;
			case '[':
				++b;
				break;
			case ']':
				if (b) {
					--b;
					++res;
				}
				break;
			}
		}

		printf("%d\n", res);
	}

	return (0);
}

