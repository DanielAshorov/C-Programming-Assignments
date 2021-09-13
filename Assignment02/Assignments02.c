#include <stdio.h>

/*Assigned by:
1. Daniel_Ashorov 313458242
2. Ohad_Edry 205533003
*/

/* Function declarations */
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
void Ex6();

/* Declarations of other functions */

int sumEven();
int largeDigit(int n);
int digitsSum(int n);
int incrementDigits(int n);
int series(int n, int result);
int removeDigit(int n, int digit);

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 6; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-6 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 6));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			case 6: Ex6(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Ex1() {
	printf("Sum of even numbers on your series is: %d\n", sumEven());  //calculating how much even numbers the user put.
}

int sumEven() {
	int n;
	printf("Please enter a number (you asked about even numbers, -1 to stop) : \n"); //The user is asked to enter a number to check if the number is even or not.
	scanf_s("%d", &n);
	if (n == -1) { //if the number = -1 then stop.
		return 0;
	}
	else {
		if (n % 2 == 0) { //divide by 2 = even number.
			return 1 + sumEven(n); //plus 1 everytime we got an even number.
		}
		else {
			return sumEven(n);
		}
	}
}

void Ex2() {
	int n;
	printf("Please enter a number: \n"); //the user is asked to put a number (no more than 9 digits) and to check which number is the biggest
	scanf_s("%d", &n);
	printf_s("Your largest digit is: %d\n", largeDigit(n));
}

int largeDigit(int n) {

	int a, b;
	if (n == 0) {
		return 0;
	}
	else {
		a = n % 10;
		b = largeDigit(n / 10);
	}
	if (a > b)
		return a;
	return b;
}

void Ex3() {

	int n;
	printf("Please enter a number: \n"); //the user is asked to put a number to check if the numbers sum is even(0) or odd (1) 
	scanf_s("%d", &n);
	printf("The answer is: %d \n", digitsSum(n));
}

int digitsSum(int n) {

	if (n == 0) {
		return 0;
	}
	if (n % 10 + digitsSum(n / 10) && (n % 2 == 0)) {
		return 0;
	}
	else
		return 1;
}

void Ex4() {

	int n;
	printf("Please enter your number: \n"); //the user is asked to put a number and than the user will get an increment digits by 1. 9 will change to 0, and 1 will change to 2.
	scanf_s("%d", &n);
	printf("Your enswer is = %d\n", incrementDigits(n));
}

int incrementDigits(int n) {
	if (n < 10) {
		return (n + 1) % 10;
	}
	else {
		return (n % 10 + 1) % 10 + 10 * incrementDigits(n / 10);
	}
}

void Ex5() {

	int n, result = 0;
	printf("Please enter a number: \n"); //the user is asked to put a number to check if the number is a ascending series or descending series or neither.
	scanf_s("%d", &n);
	printf("The answer is: %d\n", series(n, result));
}


int series(int n, int result) {
	if (n < 10) { //to stop
		return result; 
	}
	if (n % 10 < (n / 10) % 10) { //descending series
		if (result == 1) {
			return 0;
		}
		return series(n/10, -1);
	}
	else {
		if (result == -1) { //ascending series
			return 0;
		}
		return series(n/10, 1);
	}
}


void Ex6() {
	int digit = 0, n = 0;
	printf("Please enter your number: \n"); //the user is asked to put a number.
	scanf_s("%d", &n);
	printf("Please enter the digit you want to remove: \n"); //the user is asked which number to remove. for example: 122 - if he choose to remove 2 - than he will get 1.
	scanf_s("%d", &digit);
	printf("The final number is: %d\n", removeDigit(n, digit));
}

int removeDigit(int n, int digit) {

	if (n % 10 == digit) {
		return removeDigit(n / 10, digit);
	}
	if (n < 10) {
		return n;
	}
	return removeDigit(n / 10, digit) * 10 + (n % 10);
}