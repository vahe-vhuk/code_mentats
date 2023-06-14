#include "lib.h"

void concat(int* arr1, size_t n, int* arr2, size_t m, int* res)
{
	size_t ind = 0;
	for (size_t i = 0; i < n; ++i) {
		res[ind++] = arr1[i];
	}
	for (size_t i = 0; i < m; ++i) {
		res[ind++] = arr2[i];
	}
}

void filter1(int* arr, size_t n, int* res, int(*foo)(int))
{
	size_t ind = 0;
	for (size_t i = 0; i < n; ++i) {
		if (foo(arr[i])) {
			res[ind++] = arr[i];
		}
	}
}

void filter2(int* arr, size_t n, int* res, int(*foo)(int, int))
{
	size_t ind = 0;
	for (size_t i = 0; i < n; ++i) {
		if (foo(arr[i], i)) {
			res[ind++] = arr[i];
		}
	}
}

void filter3(int* arr, size_t n, int* res, int(*foo)(int, int, int*))
{
	size_t ind = 0;
	for (size_t i = 0; i < n; ++i) {
		if (foo(arr[i], i, arr)) {
			res[ind++] = arr[i];
		}
	}
}

void forEach1(int* arr, size_t n, void(*foo)(int))
{
	size_t ind = 0;
	for (size_t i = 0; i < n; ++i) {
		foo(arr[i]);
	}
}

void forEach2(int* arr, size_t n, void(*foo)(int, int))
{
	size_t ind = 0;
	for (size_t i = 0; i < n; ++i) {
		foo(arr[i], i);
	}
}

void forEach3(int* arr, size_t n, void(*foo)(int, int, int*))
{
	size_t ind = 0;
	for (size_t i = 0; i < n; ++i) {
		foo(arr[i], i, arr);
	}
}

int indexOf(int* arr, size_t n, int elem)
{
	for (size_t i = 0; i < n; ++i) {
		if (arr[i] == elem) {
			return i;
		}
	}
	return -1;
}

int indexOfAfter(int* arr, size_t n, int elem, size_t ind)
{
	for (size_t i = ind; i < n; ++i) {
		if (arr[i] == elem) {
			return i;
		}
	}
	return -1;
}

int lastIndexOf(int* arr, size_t n, int elem)
{
	for (size_t i = n - 1; i >= 0; --i) {
		if (arr[i] == elem) {
			return i;
		}
	}
	return -1;
}

int lastIndexOfBefore(int* arr, size_t n, int elem, size_t ind)
{
	for (size_t i = ind; i >= 0; --i) {
		if (arr[i] == elem) {
			return i;
		}
	}
	return -1;
}

void map1(int* arr, size_t n, int(*foo)(int))
{
	size_t ind = 0;
	for (size_t i = 0; i < n; ++i) {
		arr[i] = foo(arr[i]);
	}
}

void map2(int* arr, size_t n, int(*foo)(int, int))
{
	size_t ind = 0;
	for (size_t i = 0; i < n; ++i) {
		arr[i] = foo(arr[i], i);
	}
}

void map3(int* arr, size_t n, int(*foo)(int, int, int*))
{
	size_t ind = 0;
	for (size_t i = 0; i < n; ++i) {
		arr[i] = foo(arr[i], i, arr);
	}
}

int reduce1(int* arr, size_t n, int val, int(*foo)(int, int))
{
	for (size_t i = 0; i < n; ++i) {
		val = foo(arr[i], val);
	}
	return val;
}

int reduce2(int* arr, size_t n, int val, int(*foo)(int, int, int))
{
	for (size_t i = 0; i < n; ++i) {
		val = foo(arr[i], val, i);
	}
	return val;
}

int reduce3(int* arr, size_t n, int val, int(*foo)(int, int, int, int*))
{
	for (size_t i = 0; i < n; ++i) {
		val = foo(arr[i], val, i, arr);
	}
	return val;
}

void reverse(int* arr, size_t n)
{
	for (size_t i = 0; i < n / 2; ++i) {
		int tmp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = tmp;
	}
}

void slice1(int* arr, size_t n, int* res, size_t i1)
{
	size_t ind = 0;
	for (size_t i = i1; i < n; ++i) {
		res[ind++] = arr[i];
	}
}

void slice2(int* arr, size_t n, int* res, size_t i1, size_t i2)
{
	size_t ind = 0;
	for (size_t i = i1; i < i2; ++i) {
		res[ind++] = arr[i];
	}
}

int some1(int* arr, size_t n, int(*foo)(int))
{
	for (size_t i = 0; i < n; ++i) {
		if (foo(arr[i])) {
			return 1;
		}
	}
	return 0;
}

int some2(int* arr, size_t n, int(*foo)(int, int))
{
	for (size_t i = 0; i < n; ++i) {
		if (foo(arr[i], i)) {
			return 1;
		}
	}
	return 0;
}

int some3(int* arr, size_t n, int(*foo)(int, int, int*))
{
	for (size_t i = 0; i < n; ++i) {
		if (foo(arr[i], i, arr)) {
			return 1;
		}
	}
	return 0;
}

void fill1(int* arr, size_t n, int val)
{
	for (size_t i = 0; i < n; ++i) {
		arr[i] = val;
	}
}

void fill2(int* arr, size_t n, int val, size_t i1)
{
	for (size_t i = i1; i < n; ++i) {
		arr[i] = val;
	}
}

void fill3(int* arr, size_t n, int val, size_t i1,  size_t i2)
{
	for (size_t i = i1; i < i2; ++i) {
		arr[i] = val;
	}
}

int find1(int* arr, size_t n, int(*foo)(int))
{
	for (size_t i = 0; i < n; ++i) {
		if (foo(arr[i])) {
			return arr[i];
		}
	}
	return 0;
}

int find2(int* arr, size_t n, int(*foo)(int, int))
{
	for (size_t i = 0; i < n; ++i) {
		if (foo(arr[i], i)) {
			return arr[i];
		}
	}
	return 0;
}

int find3(int* arr, size_t n, int(*foo)(int, int, int*))
{
	for (size_t i = 0; i < n; ++i) {
		if (foo(arr[i], i, arr)) {
			return arr[i];
		}
	}
	return 0;
}

int findIndex1(int* arr, size_t n, int(*foo)(int))
{
	for (size_t i = 0; i < n; ++i) {
		if (foo(arr[i])) {
			return i;
		}
	}
	return -1;
}

int findIndex2(int* arr, size_t n, int(*foo)(int, int))
{
	for (size_t i = 0; i < n; ++i) {
		if (foo(arr[i], i)) {
			return i;
		}
	}
	return -1;
}

int findIndex3(int* arr, size_t n, int(*foo)(int, int, int*))
{
	for (size_t i = 0; i < n; ++i) {
		if (foo(arr[i], i, arr)) {
			return i;
		}
	}
	return -1;
}

int findLastIndex1(int* arr, size_t n, int(*foo)(int))
{
	for (size_t i = n - 1; i >= 0; --i) {
		if (foo(arr[i])) {
			return i;
		}
	}
	return -1;
}

int findLastIndex2(int* arr, size_t n, int(*foo)(int, int))
{
	for (size_t i = n - 1; i >= 0; --i) {
		if (foo(arr[i], i)) {
			return i;
		}
	}
	return -1;
}

int findLastIndex3(int* arr, size_t n, int(*foo)(int, int, int*))
{
	for (size_t i = n - 1; i >= 0; --i) {
		if (foo(arr[i], i, arr)) {
			return i;
		}
	}
	return -1;
}

int includes1(int* arr, size_t n, int val)
{
	for (size_t i = 0; i < n; ++i) {
		if (arr[i] == val) {
			return 1;
		}
	}
	return 0;
}

int includes2(int* arr, size_t n, int val, size_t i1)
{
	for (size_t i = i1; i < n; ++i) {
		if (arr[i] == val) {
			return 1;
		}
	}
	return 0;
}

void with(int* arr, size_t n, int* res, size_t ind, int val)
{
	for (size_t i = 0; i < n; ++i) {
		res[i] = arr[i];
	}
	res[ind] = val;
}

























