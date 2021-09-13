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
int median(int a, int b, int c);    //func Ex1
int bigdigit(int num);              //func Ex2
int rainDays(int n);                //func Ex3
int multiplication(int x, int y);   //func Ex4
double factorial(double x, int n);  //func Ex5
int amicable(int a);                //func Ex6

/* ------------------------------- */

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
								  /////////////////////////////////////////////////////////////////////////

//////////////////////////Ex1

void Ex1() {
	int a, b, c;
	printf("Please enter three integers: \n");
	printf("First number: \n");
	scanf_s("%d", &a);
	printf("Second number: \n");
	scanf_s("%d", &b);
	printf("Third number: \n");
	scanf_s("%d", &c);
	printf("The median number is: %d\n", median(a, b, c));
}

//function to check where is the middle value of three numbers
int median (int a, int b, int c) {
	// Checking for b 
	if ((a < b && b < c) || (c < b && b < a))
		return b;
	// Checking for a 
	else if ((b < a && a < c) || (c < a && a < b))
		return a;
	else
		return c;
}

//////////////////////////Ex2

void Ex2() {
	int num;
	printf("Please enter your n value: \n");
	scanf_s("%d", &num);
	printf("The largest digit in the integer: %d\n", bigdigit(num));
}

//function to check who is the big digit of the series (max of 9 numbers)
int bigdigit (int num) {
	int temp = 0, large = 0;
	while (num > 0) {
		temp = num % 10;
		if (temp > large) {
			large = temp;
		}
		num = num / 10;
	}
	return large;
}

//////////////////////////Ex3

void Ex3() {
	int n;
	printf("Please enter how much days you want to check: \n");
	scanf_s("%d", &n);
	printf("Longest run of rain days is starts at: the %d day \n", rainDays(n));
}

//function to check when there is the long run of rain days 
int rainDays(int n) {
	int first = -1, counter, limitl = 0, length = 0;

	for (int i = 0; i < n; i++) {
		printf("Please enter the rain milimeters value of the day %d: \n", i+1); //Asking the user to enter rain milimeters value every day until the n day, starts with day 1.
		int update;
		scanf_s("%d", &update);
		//If the user enter 0 value of mm
		if (update == 0) {
			first = -1;
			length = 0;
		}
		else {
			length++;
			if (length > limitl) {
				limitl = length;
				counter = first;
			}
			if (first == -1) {
				first = i + 1;
			}
		}
	}
	return counter;
}

//////////////////////////Ex4

void Ex4() {
	int x, y;
	printf("Please enter the first integer: \n");
	scanf_s("%d", &x);
	printf("Please enter the second integer: \n");
	scanf_s("%d", &y);
	printf("%d * %d value is: %d\n", x, y, multiplication(x, y));
}

// function to multiply two numbers - (x * y)
int multiplication(int x, int y) {
	int product = 0;
	while (y != 0) {
		product = product + x;
		y--;
	}
	return product;
}

//////////////////////////Ex5

void Ex5() {
	int n;
	double x, sum = 0;
	printf("Please enter your x value: \n");
	scanf_s("%lf", &x);
	printf("Please enter your n value: \n");
	scanf_s("%d", &n);
	printf("The answer is: %.2lf\n", (double) factorial(x, n)); 
}

//function which ask you to put a n value and x value and return an answer after factorial use
double factorial (double x, int n) {

	double last = 1, sum = 1;
	int i, sign = -1;
	for (i = 1; i <= n; i++) {
		last = last * sign * x * x / (i);
		sum = sum + last;
	}
	return sum;
}

//////////////////////////Ex6

void Ex6() {
	int n, i, j;
	printf("Please enter a number to check if he have an amicable numbers\n");
	scanf_s("%d", &n);
	for (i = n; i > 1; i--) {
		for (j = i; j > 1; j--) {
			if (j == amicable(amicable(j)) && amicable(j) < amicable(amicable(j))) {
				printf("%d and %d are an amicable numbers!\n", amicable(j), amicable(amicable(j)));
				i = j - 1;
				j = 0;
			}
		}
	}
}

//function to check if there is an amicable between numbers 
int amicable(int a) {
	int i, r = a, x = 1;
	for (i = r; i > 1; i--) {
		if (a%i == 0 && a != i)
			x = x + i;
	}
	return x;
}