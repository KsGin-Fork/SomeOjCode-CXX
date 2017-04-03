/*
 ============================================================================
 Name        : 指针操作数组.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<string.h>
void func(char * s, char * t) {
	char k;
	k = *s;
	*s = *t;
	*t = k;
	s++, t--;
	if (*s)
		func(s, t);
}
int main() {
	char a[] = "!puorGxuniLuoyiX ot emocleW";
	char *p = a + strlen(a) / 2 + 1;
	func(p, p - 2);
	printf("%s\n", a);
	return 0;
}
