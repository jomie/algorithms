#include <stdio.h>
#include <assert.h>
#include <string.h>


int substr(char dst[], char src[], int start, int len);
void deblank(char *str);
void test();

int main()
{
	// test();
	
}


void test()
{
	char	src[100], dst[100];
	int 	start, len;


	do {
		bzero(src, 100);
		// bzero(dst, 100);
		printf("\nInput the src :" );
		fgets(src, 100, stdin);

		// scanf("%s", src);
		printf("The src is :%s\n", src);
		// printf("Input the start and len  :\n");
		// scanf("%d%d", &start, &len);
	
		// substr(dst, src, start, len);
		// printf("\nThe dst is :%s\n", dst);

		deblank(src);
		printf("After deblank :%s\n", src);
	

	} while(src != NULL);
}


int substr(char *dst, char *src, int start, int len) 
{
	assert(len < sizeof(dst));

	int 	i, j;
	int 	s_len = strlen(src);

	 if (start < 0 || len < 0 || start > s_len) {
	 	memset(dst, 0, 100);
	 } else {
	 		for (j = 0, i = start; j < len; j++, i++) {
	 			dst[j] = src[i];
	 			if (src[i] == 0)
	 				break;
	 		}
	 		if (j < len) {
	 			j++;
	 			bzero(&dst[j], len - j);
	 		}
	 }
}


void deblank(char *str)
{
	assert(str != NULL);
	int flag = 0;
	int last , start, i, j;
	int len = strlen(str);

	for (i = 0; i < len; i++) {
			if (str[i] == ' ' && flag == 0) {
				flag = 1;
				start = i;	
			}

			if (str[i] != ' ' && flag == 1) {
				last = i;
				flag = 0;
				if (start == 0) {
					while(last <= len)
						str[start++] = str[last++];
					len -= (last - start);
				} else {
					while (last <= len) 
						str[++start] = str[last++];
					len -= (last - start - 1);
				}
			}
	}

}