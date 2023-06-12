#include <stdio.h>
#include <stdlib.h>

typedef struct vector
{
	size_t size;
	size_t capacity;
	int* arr;

} vector;

void resize(vector* vec, size_t n)
{
	int* tmp = (int*)malloc(n*sizeof(int));
	for (size_t i = 0; i < vec->size; ++i) {
		tmp[i] = vec->arr[i];
	}
	free(vec->arr);
	vec->arr = tmp;
}

void reverse(vector* vec, size_t n)
{
	vec->capacity = 4;
	vec->size = 0;
	vec->arr = (int*)malloc(vec->capacity*sizeof(int));
}

void delete(vector* vec)
{
	free(vec->arr);
}

void push_back(vector* vec, int val)
{
	if (vec->size == vec->capacity) {
		vec->capacity *= 2;
		resize(vec, vec->capacity);
	}
	vec->arr[vec->size++] = val;
}

void insert(vector* vec, size_t ind, int val)
{
	if (ind > vec->size) {
		return;
	}
	if (vec->size == vec->capacity) {
		vec->capacity *= 2;
		resize(vec, vec->capacity);
	}
	for (size_t i = vec->size; i > ind; --i) {
		vec->arr[i] = vec->arr[i - 1];
	}
	++vec->size;
	vec->arr[ind] = val;
}

int at(vector* vec, size_t ind)
{
	if (ind >= vec->size) {
		return 0;
	}
	return vec->arr[ind];
}

size_t size(vector* vec)
{
	return vec->size;
}

size_t capacity(vector* vec)
{
	return vec->capacity;
}

int empty(vector* vec)
{
	return (vec->size == 0);
}

void print(vector* vec)
{
	for (size_t i = 0; i < vec->size; ++i) {
		printf("%d ", vec->arr[i]);
	}
}




int main()
{
	vector a;

	reverse(&a, 4);

	push_back(&a, 3);
	push_back(&a, 3);
	push_back(&a, 3);
	push_back(&a, 3);
	push_back(&a, 3);
	push_back(&a, 3);
	push_back(&a, 3);

	insert(&a, 3, 7);
	insert(&a, 8, 15);

	print(&a);

	return 0;
}
