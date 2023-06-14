#include <stdio.h>

void concat(int* arr1, size_t n, int* arr2, size_t m, int* res);

int every1(int* arr, size_t n, int(*foo)(int));
int every2(int* arr, size_t n, int(*foo)(int, int));
int every3(int* arr, size_t n, int(*foo)(int, int, int*));

void filter1(int* arr, size_t n, int* res, int(*foo)(int));
void filter2(int* arr, size_t n, int* res, int(*foo)(int, int));
void filter3(int* arr, size_t n, int* res, int(*foo)(int, int, int*));

void forEach1(int* arr, size_t n, void(*foo)(int));
void forEach2(int* arr, size_t n, void(*foo)(int, int));
void forEach3(int* arr, size_t n, void(*foo)(int, int, int*));

int indexOf(int* arr, size_t n, int elem);
int indexOfAfter(int* arr, size_t n, int elem, size_t ind);

int lastIndexOf(int* arr, size_t n, int elem);
int lastIndexOfBefore(int* arr, size_t n, int elem, size_t ind);

void map1(int* arr, size_t n, int(*foo)(int));
void map2(int* arr, size_t n, int(*foo)(int, int));
void map3(int* arr, size_t n, int(*foo)(int, int, int*));

int reduce1(int* arr, size_t n, int val, int(*foo)(int, int));
int reduce2(int* arr, size_t n, int val, int(*foo)(int, int, int));
int reduce3(int* arr, size_t n, int val, int(*foo)(int, int, int, int*));

void reverse(int* arr, size_t n);

void slice1(int* arr, size_t n, int* res, size_t i);
void slice2(int* arr, size_t n, int* res, size_t i1, size_t i2);

int some1(int* arr, size_t n, int(*foo)(int));
int some2(int* arr, size_t n, int(*foo)(int, int));
int some3(int* arr, size_t n, int(*foo)(int, int, int*));

void sort(int* arr, size_t n);

void fill1(int* arr, size_t n, int val);
void fill2(int* arr, size_t n, int val, size_t i);
void fill3(int* arr, size_t n, int val, size_t i1, size_t i2);

int find1(int* arr, size_t n, int(*foo)(int));
int find2(int* arr, size_t n, int(*foo)(int, int));
int find3(int* arr, size_t n, int(*foo)(int, int, int*));

int findIndex1(int* arr, size_t n, int(*foo)(int));
int findIndex2(int* arr, size_t n, int(*foo)(int, int));
int findIndex3(int* arr, size_t n, int(*foo)(int, int, int*));

int findLastIndex1(int* arr, size_t n, int(*foo)(int));
int findLastIndex2(int* arr, size_t n, int(*foo)(int, int));
int findLastIndex3(int* arr, size_t n, int(*foo)(int, int, int*));

int includes1(int* arr, size_t n, int val);
int includes2(int* arr, size_t n, int val, size_t i);

void with(int* arr, size_t n, int* res, size_t i, int val);















