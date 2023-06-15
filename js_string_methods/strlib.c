#include "strlib.h"

char at(char* str, size_t ind)
{
	return str[ind];
}

char charAt(char* str, size_t ind)
{
	return at(str, ind);
}

int charCodeAt(char* str,  size_t ind)
{
	return at(str, ind);
}

int startsWith1(char* str1, char* str2)
{
	size_t len = 0;
	for (; str2[len]; ++len);

	for (size_t i = 0; i < len; ++i) {
		if (str1[i] != str2[i]) {
			return 0;
		}
	}
	return 1;
}

int startsWith2(char* str1, char* str2, size_t ind)
{
	size_t len = 0;
	for (; str2[len]; ++len);

	for (size_t i = 0; i < len; ++i) {
		if (str1[ind + i] != str2[i]) {
			return 0;
		}
	}
	return 1;
}

int endsWith1(char* str1, char* str2)
{
	size_t len1 = 0;
	size_t len2 = 0;
	for (; str1[len1]; ++len1);
	for (; str2[len2]; ++len2);

	if (len1 < len2) {
		return 0;
	}

	return startsWith1(str1 + len1 - len2, str2);
}

int endsWith2(char* str1, char* str2, size_t ind)
{
	size_t len1 = 0;
	size_t len2 = 0;
	for (; str1[len1]; ++len1);
	for (; str2[len2]; ++len2);

	if (len1 < len2) {
		return 0;
	}

	return startsWith1(str1 + ind - len2, str2);
}

int includes2(char* str1, char* str2, size_t ind)
{
	size_t len1 = 0;
	size_t len2 = 0;
	for (; str1[len1]; ++len1);
	for (; str2[len2]; ++len2);

	if (len1 - ind < len2) {
		return 0;
	}

	size_t i = ind;
	while (i < len1 - len2) {
		int flag = 1;
		if (str1[i] == str2[0]) {
			size_t j = 1;
			while (j < len2) {
				if (str1[i + j] != str2[j]) {
					j = 0;
					break;
				}
				++j;
			}
		}
		if (flag) {
			return 1;
		}
		++i;
	}
	return 0;
}

int includes1(char* str1, char* str2)
{
	return includes2(str1, str2, 0);
}

int indexOf2(char* str1, char* str2, size_t ind)
{
	size_t len1 = 0;
	size_t len2 = 0;
	for (; str1[len1]; ++len1);
	for (; str2[len2]; ++len2);

	if (len1 - ind < len2) {
		return -1;
	}

	size_t i = ind;
	while (i < len1 - len2) {
		int flag = 1;
		if (str1[i] == str2[0]) {
			size_t j = 1;
			while (j < len2) {
				if (str1[i + j] != str2[j]) {
					j = 0;
					break;
				}
				++j;
			}
		}
		if (flag) {
			return i;
		}
		++i;
	}
	return -1;
}

int indexOf1(char* str1, char* str2)
{
	return indexOf2(str1, str2, 0);
}

int lastIndexOf2(char* str1, char* str2, size_t ind)
{
	size_t len1 = 0;
	size_t len2 = 0;
	for (; str1[len1]; ++len1);
	for (; str2[len2]; ++len2);

	if (len1 - ind < len2) {
		return -1;
	}

	size_t i = len1 - ind - len2;
	while (i >= 0) {
		int flag = 1;
		if (str1[i] == str2[0]) {
			size_t j = 1;
			while (j < len2) {
				if (str1[i + j] != str2[j]) {
					j = 0;
					break;
				}
				++j;
			}
		}
		if (flag) {
			return i;
		}
		--i;
	}
	return -1;
}

int lastIndexOf1(char* str1, char* str2)
{
	size_t len = 0;
	for (; str1[len]; ++len);

	return lastIndexOf1(str1, str2, len);
}

void padEnd2(char* str, size_t cnt, char sym)
{
	size_t len = 0;
	for (; str[len]; ++len);
	if (len <= cnt) {
		return;
	}

	for (size_t i = len; i < cnt; ++i) {
		str[i] = sym;
	}
	str[cnt] = '\0';
}

int padEnd1(char* str,  size_t cnt)
{
	padEnd2(str, cnt, ' ');
}


























