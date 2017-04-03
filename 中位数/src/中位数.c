/*
 ============================================================================
 Name        : 中位数.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//输出数组中的第偶数个数字的中位数

void mid_number() {
	int length = 0, count = 0;
	float mid;
	int arr[100], arr1[200];
	while ((scanf("%d", &arr1[length]) != EOF)) {
		if ((length+1) % 2 == 0){
			arr[count] = arr1[length];
			count++;
		}
		printf("此时数组是[");
		for (int i = 0; i < length + 1; i++) {
			printf("%d", arr1[i]);
			if (i == length)
				printf("]    ");
			else
				printf(",");
		}
		for (int i = 0; i < count; i++)
			for (int j = 0; j < count - i - 1; j++)
				if (arr[j] > arr[j + 1]) {
					int temp;
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
		if (count % 2 == 0)
			mid = (float)(arr[count / 2 - 1] + arr[count / 2 ])/2.0;
		else
			mid = arr[count / 2 ];
		if((int)mid == mid)
			printf("此时数组第偶数个元素的中位数是%.f\n", mid);
		else printf("此时数组第偶数个元素的中位数是%.1f\n", mid);

		length++;
	}
}

int main(void) {
	mid_number();
	return EXIT_SUCCESS;
}
