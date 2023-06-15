#include <stdio.h>

char at(char* str, size_t ind);

char charAt(char* str, size_t ind);

int charCodeAt(char* str, size_t ind);

void concat(char* str1, char* str2);

int endsWith1(char* str1, char* str2);
int endsWith2(char* str1, char* str2, size_t ind);

int includes1(char* str1, char* str2);
int includes2(char* str1, char* str2, size_t ind);

int indexOf1(char* str1, char* str2);
int indexOf2(char* str1, char* str2, size_t ind);

int lastIndexOf1(char* str1, char* str2);
int lastIndexOf2(char* str1, char* str2, size_t ind);

void padEnd1(char* str, size_t cnt);
void padEnd2(char* str, size_t cnt, char sym);

void padStart1(char* str, size_t cnt);
void padStart2(char* str, size_t cnt, char sym);

void repeat(char* str, char* res, size_t cnt);

void replace(char* str, char* targ, char* val);

void replaceAll(char* str, char* targ, char* val);

void slice1(char* str, char* res, size_t i1);
void slice2(char* str, char* res, size_t i1, size_t i2);

void split(char* str, char** res, char sep);

int startsWith1(char* str1, char* str2);
int startsWith2(char* str1, char* str2, size_t ind);

void toLowerCase(char* str);

void toUpperCase(char* str);

void trimEnd(char* str);

void trimStart(char* str);

void trim(char* str);













