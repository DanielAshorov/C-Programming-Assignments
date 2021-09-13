/*Assigned by:
1. Daniel_Ashorov 313458242
2. Ohad_Edry 205533003
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

/* Function declarations */

typedef char* verylong;
typedef unsigned long s;
verylong add_verylong(verylong v1, verylong v2);
verylong input_long();
verylong multiply_verylong(verylong vl1, verylong vl2);
verylong multiplation(verylong vl1, s n);
verylong multihelp(verylong vl1, verylong vl2);

void main(void)
{
	verylong a, b, c;
	do {
		printf("enter the first long integer: ");
		a = input_long();
	} while (!a);
	do {
		printf("enter the second long integer: ");
		b = input_long();
	} while (!b);
	c = add_verylong(a, b);
	printf("%s + %s = %s\n", a, b, c);
	free(c);
	c = multiply_verylong(a, b);
	printf("%s * %s = %s\n", a, b, c);
	free(c);

	free(a);
	free(b);
	getch();
}

	verylong input_long(void) {
	char str[MAX_SIZE];
	gets(str);
	int i, length; 
	length = strlen(str); 
	verylong n;
	n = (char*) calloc (length + 1, sizeof(char));  //+1 for \0

	for (i = 0; i < length; i++) {
		if (str[i] - '0' > 9 || str[i] - '0' < 0 ) {   //not a digit
			printf("not a digit! please try again. \n");
			return NULL; //returing NULL is asked in the question
		}
		n[i] = str[i];    //++
	}
	n[i] = '\0';   //finished
	return n;
}

   // very long number + very long number function
verylong add_verylong(verylong v1, verylong v2) {
	int x, y, sum, r;
	int i;
	i = strlen(v1);
	int j;
	j = strlen(v2);
	int c;
	if (i > j) {
		c = i + 1;
	}
	else {
		c = j + 1;
	}	
	verylong result = (char*) malloc (c + 1);
	for (r = 0; r < c; r++) {
		result[r] = '0';
	}
	result[r] = '\0';
	c = c - 1;
	i = i - 1;
	j = j - 1;
	while (i >= 0 && j >= 0) {
		x = v1[i--] - '0';
		y = v2[j--] - '0';
		sum = x + y + (result[c] - '0');
		result[c] = sum % 10 + '0';
		if (sum >= 10) {
			result[c - 1] = sum / 10 + '0';
		}
		c = c - 1;
	}
	while (j >= 0) {
		y = v2[j--] - '0';
		sum = y + (result[c] - '0');
		result[c] = sum % 10 + '0';
		if (sum >= 10) {
			result[c - 1] = sum / 10 + '0';
		}
		c = c - 1;
	}
	while (i >= 0) {
		x = v1[i--] - '0';
		sum = x + (result[c] - '0');
		result[c] = sum % 10 + '0';
		if (sum >= 10) {
			result[c - 1] = sum / 10 + '0';
		}
		c = c - 1;
	}

	r = 0; // intiallzing
	c = 0; // intiallzing
	while (result[r] == '0') {
		r = r + 1;
	}
	while (result[r] != '\0') {
		result [c++] = result[r++];
	}
	result [c++] = '\0'; //last
	result = (char*) realloc (result, c);
	return result;
}


verylong multiply_verylong(verylong vl1, verylong vl2) {
	verylong x = "0";
	s vl1Length = (float)strlen(vl1);
	s vl2Length = (float)strlen(vl2);
	s growth = 1;
	s i;
	for (i = 0; i < vl2Length; i++) {
		x = add_verylong(x, multiplation(vl1, growth* (vl2[vl2Length - i - 1] - '0')));
		growth = growth * 10;
	}
	return x;
}

//calculating first number * second number
verylong multiplation(verylong vl1, s n) {
	verylong vl3 = "0";
	s i;
	for (i = 0; i < n; i++) {
		vl3 = add_verylong(vl3, vl1);
	}
	return vl3;
}
//check which number is longer and then call multply
verylong multihelp(verylong vl1, verylong vl2) {
	if (strlen(vl2) < strlen(vl1)) {
		return  multihelp(vl1, vl2);
	}
	return multihelp(vl2, vl1);
}