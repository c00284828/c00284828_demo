#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char * ret_substr(char *p, char *q)
{
	int ret_len = q - p + 1;
	char *ret = malloc(ret_len+1);
	memcpy(ret, p, ret_len);
	ret[ret_len] = 0;
	return ret;
}

int get_palind(char *s, char *e, char *p, char *q, char **ret_p, char ** ret_q)
{
	while (p >= s && q<= e){
		if(*p == *q){
			p--;
			q++;
		}else{
			break;
		}
	}

	*ret_p = p+1;
	*ret_q = q-1;
	return *ret_q - *ret_p +1;
}


char * longestPalindrome(char * s){
	char *p = s;

	int len = strlen(s);
	if(len < 2)
		return ret_substr(s, s);

	char *rp;
	char *rq;
	int rlen = 0;
	char *p_max = s + len;
	while (p < p_max)
	{
		char *ret_p, *ret_q;
		int t_len;

		t_len = get_palind(s, s+len, p, p, &ret_p, &ret_q);
		if(rlen < t_len){
			rlen = t_len;
			rp = ret_p;
			rq = ret_q;
			p_max = s + len - (rlen >>1);
		}

		if(*p == *(p +1)){
			t_len = get_palind(s, s+len, p, p + 1, &ret_p, &ret_q);
			if(rlen < t_len){
				rlen = t_len;
				rp = ret_p;
				rq = ret_q;
				p_max = s + len - (rlen>>1);
			}
		}

		p++;
	}

	return ret_substr(rp, rq);
}

void tc2(){
	char *m = "aa";
	char *ret = longestPalindrome(m);
	printf("%s: %s \n", m, ret);
	free(ret);
}

void tc3(){
	char *m = "babad";
	char *ret = longestPalindrome(m);
	printf("%s: %s \n", m, ret);
	free(ret);
}

void tc4(){
	char *m = "";
	char *ret = longestPalindrome(m);
	printf("%s: %s \n", m, ret);
	free(ret);
}

void tc5(){
	char *m = "pwwkew";
	char *ret = longestPalindrome(m);
	printf("%s: %s \n", m, ret);
	free(ret);
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