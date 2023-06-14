#include <stdio.h>
#include "lib.h"

void foo(int elem, int index)
{
	printf("arr[%d] = %d\n", index, elem);
}

int main()
{
	int arr[] = {5, 4, 2, 3, 6, 8, 7, 8, 5, 4, 6};

	forEach2(arr, 11, foo);

	return 0;
}
