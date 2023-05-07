// C Program to return array from a function
#include <stdio.h>

// function
int* func()
{
	static int arr[5] = { 1, 2, 3, 4, 5 };

	return arr;
}

// driver code
int main()
{

	int* ptr = func();

	printf("Array Elements: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", *ptr++);
	}
	return 0;
}
