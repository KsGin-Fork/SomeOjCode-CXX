/*
 ============================================================================
 Name        : 输出素数因子.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void num_print(int m) {
	for (int i = 2; i < m; i++) {
		int count = 0;
		if (m % i == 0) {
			for (int j = 2; j < i; j++) {
				if (i % j == 0)
					count = 1;
			}
			if (count == 0)
				printf("%d  ", i);
		}
	}
}

int main(void) {
	int m;
	scanf("%d", &m);
	num_print(m);
	return EXIT_SUCCESS;
}
