/*
 ============================================================================
 Name        : 移动距离.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(void) {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int arr[N / n][n];
	for (int i = 0; i < N / n; i++) {
		for (int j = 0; j < n; j++) {
			if (i % 2 == 0)
				arr[i][j] = i * n + j + 1;
			else
				arr[i][j] = (i + 1) * n - j;
		}
	}
	int x1, y1, x2, y2;
	for (int i = 0; i < N / n; i++) {
		for (int j = 0; j < n; j++) {
			if (a == arr[i][j]) {
				x1 = i;
				y1 = j;
			}
			if (b == arr[i][j]) {
				x2 = i;
				y2 = j;
			}
		}
	}
	printf("%d",abs(x2-x1)+abs(y2-y1));
	return EXIT_SUCCESS;
}
