#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char * s){
	if(!s || *s == 0)
		return 0;

	char * p = s;
	int max = 1;
	while(*p){
		char *n = p + 1;
		int n_rep = 0;
		char *x = p;
		int sub_len;
		while (*n) {
			x = p;
			//对n遍历从p到s结尾的子串，如果存在*n，则终止
			//那么以*p为起点，可以获得
			while(x != n ){
				if(*x == *n) {
					n_rep = 1;
					goto fail;
				}
				x++;
			}
			n++;
		}
		n--;
fail:
		sub_len = 1 + (n - p - n_rep);
		max = sub_len > max ? sub_len : max;
		p = x + 1;
	}
	return max;
}

void tc1(){
	char *m = NULL;
	printf("get %d \n", lengthOfLongestSubstring(m));
}
void tc2(){
	char *m = "a";
	printf("%s:  %d \n", m, lengthOfLongestSubstring(m));
}

void tc3(){
	char *m = "abcabcbb";
	printf("%s:  %d \n", m, lengthOfLongestSubstring(m));
}

void tc4(){
	char *m = "bbbbb";
	printf("%s:  %d \n", m, lengthOfLongestSubstring(m));
}

void tc5(){
	char *m = "pwwkew";
	printf("%s:  %d \n", m, lengthOfLongestSubstring(m));
}

int main(){
	// tc1();
	tc2();
	tc3();
	tc4();
	tc5();
	printf("\n");
	return 0;
}