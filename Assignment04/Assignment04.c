/*Assigned by:
1. Daniel_Ashorov 313458242
2. Ohad_Edry 205533003
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include<assert.h>

#define N 4

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
void Ex51();
void Ex52();
void Ex6();

/* Declarations of other functions */

int find_max(int *, int);
int *input_array_dyn(int);
void swap(int *, int *);
void quick_sort(int *, int, int);
int partition(int *, int, int);
int tmura(int *a, int *, int);
void print_array(int *, int);
int difference_shows_in_arrays(int *array_x, int *array_y, int n, int m, int diff);
int *merge_arrays(int *, int *, int *);
void pushZerosToEnd(int arr[], int n);
int Tmura_Monim(int *array1, int *array2, int Size);
int isIncluded(int *arr, int n, int *ezer);

/* ------------------------------- */

int main() { 
	int select = 0, i, all_Ex_in_loop = 0;  
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");  
	if (scanf_s("%d", &all_Ex_in_loop) == 1)   
	do { 
		for (i = 1; i <= 6; i++)     
			printf("Ex%d--->%d\n", i, i);    
		printf("EXIT-->0\n");    
		do { 
			select = 0;     
			printf("please select 0-6 : ");     
			scanf_s("%d", &select); 
		} 
		while ((select < 0) || (select > 6));    
			switch (select) { 
				case 1: Ex1(); 
				break;    
				case 2: Ex2(); 
				break;    
				case 3: Ex3(); 
				break;    
				case 4: Ex4(); 
				break;    
				case 5: Ex5(); 
				break;                   
				case 6: Ex6(); 
				break; 
			} 
	} 
	while (all_Ex_in_loop && select);   
	return 0; 
}

//Ex01-----------------------------------------------------------------------------------------------------------

void Ex1() {
	int *array, i = 0, elements;
	printf("Please enter your in the array: \n");
	scanf_s("%d", &elements);
	array = (int*) malloc(elements * sizeof(int));
	for (i = 0; i < elements; i++)
	{
		printf("Please enter value for index nNo. array[%d] : \n", i);
		scanf_s("%d", array + i);
	}
	printf("The Max nubmer if found in array[%d]\n", find_max(array, elements));
	free(array);
}

int find_max(int *array, int size_array) {
	int right = size_array - 1;
	int left = 0;
	int i = (left + right) / 2;
	while (left <= right)
	{
		if (array[i] > array[i - 1] && array[i] > array[i + 1])
			return i;
		else {
			if (array[i] < array[i + 1]) {
				left = i + 1;
				i = (left + right) / 2;
			}
			else {
				right = i - 1;
				i = (left + right) / 2;
			}
		}
	}
	return -1;
}


//Ex02-----------------------------------------------------------------------------------------------------------

void Ex2()
{
	int *array_x, *array_y;
	int i = 0, n, m, diff;
	printf("Please enter number of elements first array  \n");
	scanf_s("%d", &n);
	array_x = (int *)malloc(n * sizeof(int));
	for (; i < n; i++)
	{
		printf("Please enter %d number \n", i + 1);
		scanf_s("%d", array_x + i);
	}
	printf("Please enter number of elements second array \n");
	scanf_s("%d", &m);
	array_y = (int *)malloc(m * sizeof(int));
	for (i = 0; i < m; i++)
	{
		printf("Please enter %d number \n", i + 1);
		scanf_s("%d", array_y + i);
	}
	printf("Please enter your d: \n");
	scanf_s("%d", &diff);
	if (n > m)
		quick_sort(array_y, 0, m - 1);
	else
		quick_sort(array_x, 0, m - 1);

	if (difference_shows_in_arrays(array_x, array_y, n, m, diff))
		printf("The answer is: 1\n");
	else
		printf("The answer is : 0\n");
}

int difference_shows_in_arrays(int *array_x, int *array_y, int n, int m, int diff) {//function that check if theres x[i]-y[i]=difined diff.
	if (n > m) {
		int i;
		for (i = 0; i < n; i++) {
			int left = 0, right = m - 1;
			int mid = m / 2;
			while (left <= right) {
				if (array_x[i] - array_y[mid] == diff)
					return 1;
				if (array_x[i] < array_y[mid]) {
					right = mid - 1;
					mid = (left + right) / 2;
				}
				else
				{
					left = mid + 1;
					mid = (left + right) / 2;
				}
			}
		}
		return 0;
	}
	else
	{
		int i;
		for (i = 0; i < m; i++)
		{
			int left = 0, right = n - 1;
			int mid = n / 2;
			while (left <= right)
			{
				if (array_y[i] + diff == array_x[mid])
					return 1;
				if (array_y[i] + diff < array_x[mid])
				{
					right = mid - 1;
					mid = (left + right) / 2;
				}
				else
				{
					left = mid + 1;
					mid = (left + right) / 2;
				}

			}
		}
		return 0;
	}
}

//Ex3-----------------------------------------------------------------------------------------------------------

void Ex3() {
	//The fuction gets 2 arrays and return new array with the common numbers//
	int *d, *a, *b, n, m, size;
	printf("Please enter the size of your first array\n");
	scanf_s("%d", &n);
	a = input_array_dyn(n);
	printf("Please enter the size of your second array\n");
	scanf_s("%d", &m);
	b = input_array_dyn(m);
	quick_sort(a, 0, n - 1);
	quick_sort(b, 0, m - 1);
	if (m > n)
		size = m;
	else
		size = n;
	d = merge_arrays(a, b, &size);
	printf("The size of array : %d \nArray : ", size);
	print_array(d, size);
	printf("\n\n");
	free(a);
	free(b);
}

//Ex3 function-----------------------------------------------------------------------------------------------------------

int * merge_arrays(int *a, int *b, int *size)
{
	int i = 0, j = 0, k = 0, count = 0;
	int *c;
	c = (int*)calloc(*size, sizeof(int));
	while (i < *size && j < *size)
	{
		if (a[i] < b[j])
		{
			a[i++];
		}
		else if (a[i] > b[j])
		{
			b[j++];
		}
		else if (a[i] == b[j])
		{
			c[k] = a[i];
			b[j++];
			a[i++];
			c[k++];
			count++;
		}
	}
	*size = count;
	c = (int*)realloc(c, (*size) * sizeof(int));
	return c;
	free(c); 

}

//Ex04-----------------------------------------------------------------------------------------------------------

void Ex4()
{
	int *arr, n, *ezer, result;
	printf("Please enter the size of your array\n");
	scanf_s("%d", &n);
	arr = input_array_dyn(n);
	ezer = (int *)calloc(n, sizeof(int));
	result = isIncluded(arr, n, ezer);
	printf("\nReturn value is: %d \n", result);
	free(arr);
	free(ezer);
}

int isIncluded(int *arr, int n, int *ezer) {
	int i;
	for (i = 0; i < n; i++) {
		if (arr[i] > n || arr[i] < 1)
			return 0;
		ezer[arr[i] - 1] = arr[i];
	}
	for (i = 0; i < n; i++) {

		if (ezer[i] != i + 1)
			return 0;
	}
	return 1;
}

//Ex5-----------------------------------------------------------------------------------------------------------
void Ex5() {
	int select;  
	printf("For 5a select 1, for 5b select 2\n");  
	scanf_s("%d", &select);  
	switch (select) { 
		case 1: 
		Ex51(); 
		break;  
		case 2: 
		Ex52(); 
		break;  
		default: 
		printf("Invalid choice\n"); 
	}
}
void Ex51()
{
	int *arr, *arr2, n, result;
	printf("Please enter the size of your arrays\n");
	scanf_s("%d", &n);
	arr = input_array_dyn(n);
	arr2 = input_array_dyn(n);
	result = tmura(arr, arr2, n);
	if (result)
		printf("\nArray 1 is permutation of array 2 , result : %d\n\n", result);
	else
		printf("\Not a permutation , result : %d\n\n", result);

	free(arr);
	free(arr2);

}

//Ex51 function-----------------------------------------------------------------------------------------------------------

int tmura(int *a, int *b, int n)
{
	int i = 0, j = 0;
	quick_sort(a, 0, n - 1);
	quick_sort(b, 0, n - 1);
	while (a[i] == b[j] && i < n)
	{
		i++;
		j++;
	}
	if (i == n)
		return 1;
	else
		return 0;
}

void Ex52()
{
	int *Array_1, *Array_2, Size_Arrays;
	printf("Enter size for Array1 & Array2: ");
	scanf_s("%d", &Size_Arrays);
	printf("Enter numbers between 1-100 for Array1: \n");
	Array_1 = input_array_dyn(Size_Arrays);
	printf("Enter numbers between 1-100 for Array2: \n");
	Array_2 = input_array_dyn(Size_Arrays);
	printf("\n");
	printf("* %d *\n\n", Tmura_Monim(Array_1, Array_2, Size_Arrays));
	free(Array_1);
	free(Array_2);
}

//Ex51 function-----------------------------------------------------------------------------------------------------------

int Tmura_Monim(int *array1, int *array2, int Size) 
{
	int i, monim_array[101] = { 0 };
	for (i = 0; i < Size; i++) {
		monim_array[array1[i]]++; 
		monim_array[array2[i]]--;
	}
	for (i = 1; i < 101; i++)
		if (monim_array[i] != 0)
			return 0; // 0 if one of them are different
	return 1; 
}

////Ex6-----------------------------------------------------------------------------------------------------------

void Ex6()
{
	int *arr, i, n;
	printf("Please enter the size of your arrays\n");
	scanf_s("%d", &n);
	arr = input_array_dyn(n);
	pushZerosToEnd(arr, n);
	printf("Array after pushing all zeros to end of array :\n");
	for (i = 0; i < n; i++)
		printf("%2d", arr[i]);
	printf("\n");
	return 0;

	free(arr);
	free(*arr);
}

////Ex6 function-----------------------------------------------------------------------------------------------------------

void pushZerosToEnd(int arr[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] != 0)
			arr[count++] = arr[i];
	while (count < n)
		arr[count++] = 0;
}

/* Declarations of other functions */

int *input_array_dyn(int n)
{
	int i;
	int *a;
	a = (int *)calloc(n, sizeof(int));
	assert(a);
	printf("Please enter length of your array %d\n", n);
	for (i = 0; i < n; i++)
		scanf_s("%d", a + i);
	return a;
}

void swap(int *i, int *j)
{
	int t = *i;
	*i = *j;
	*j = t;
}
void print_array(int *a, int l)
{
	int i;
	for (i = 0; i < l; i++)
	{
		printf("[%d] ", a[i]);
	}
	printf("\n");
}
void quick_sort(int *a, int first, int last)
{
	int pos;
	if (first < last)
	{
		pos = partition(a, first, last);
		quick_sort(a, first, pos - 1);
		quick_sort(a, pos + 1, last);
	}
}

int partition(int *a, int left, int right)
{
	int first = left;
	int pivot = a[first];
	int pos;
	while (left < right)
	{
		while (a[right] > pivot) right--;
		while ((left < right) && (a[left] <= pivot)) left++;
		if (left < right)
			swap(a + left, a + right);
	}
	pos = right;
	a[first] = a[pos];
	a[pos] = pivot;
	return pos;
}