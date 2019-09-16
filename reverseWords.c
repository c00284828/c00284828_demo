#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *reverseWords(char *s)
{
	int len = strlen(s);
	char *ret = malloc(len + 1);

	if (len == 0) {
		ret[0] = 0;
		return ret;
	}

	char *pret = ret;
	*pret = 0;

	char *q = s + len - 1;
	while (q >= s) {
		//trim space
		while (q >= s && *q == ' ')
			q--;
		if (q < s) {
			if (pret > ret)
				pret--;
			*pret = 0;
			return ret;
		}

		char *p = q - 1;
		while (p >= s && *p != ' ')
			p--;
		int sub_len = q - (p + 1) + 1;
		memcpy(pret, p + 1, sub_len);
		pret += sub_len;
		*pret++ = ' ';

		q = p;
	}
	*--pret = 0;
	return ret;
}

void tc1()
{
	char *m = "";
	char *ret = reverseWords(m);
	printf("[%s]:[%s].\n", m, ret);
	free(ret);
}

void tc2()
{
	char *m = "  hello world!  ";
	char *ret = reverseWords(m);
	printf("[%s]:[%s].\n", m, ret);
	free(ret);
}

void tc3()
{
	char *m = "                ";
	char *ret = reverseWords(m);
	printf("[%s]:[%s].\n", m, ret);
	free(ret);
}

void tc4()
{
	char *m = "a good   example";
	char *ret = reverseWords(m);
	printf("[%s]:[%s].\n", m, ret);
	free(ret);
}

void tc5()
{
	char *m = "   a   ";
	char *ret = reverseWords(m);
	printf("[%s]:[%s].\n", m, ret);
	free(ret);
}

typedef struct {
	int a;
	int b;
} node;

int tc_cmp(const void *a, const void *b)
{
	return ((node *)a)->a < ((node *)b)->a;
}

void tcxx()
{
	struct node {
		int a;
		int b;
	} mm[5] = {};

	for (int i = 0; i < 5; i++) {
		mm[i].a = i;
	}
	for (int i = 0; i < 5; i++) {
		printf("mm[%d]:%d\n", i, mm[i].a);
	}

	qsort(mm, 5, sizeof(node), tc_cmp);

	for (int i = 0; i < 5; i++) {
		printf("mm[%d]:%d\n", i, mm[i].a);
	}
}

int main()
{
	tc1();
	tc5();
	tc2();
	tc3();
	tc1();
	tc4();
	return 0;
}