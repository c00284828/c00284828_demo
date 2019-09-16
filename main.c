#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char *p = malloc(12);
	// p = malloc(20);
	free(p);
	free(p);
	// *p = 2;
	tcxx();
	printf("main \n");
	return 0;
}