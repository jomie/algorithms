#include <iostream>

using namespace std;

void getNext(char *src, int *next, int len)
{
	if (src == NULL)
		return ;
	int i = 0;
	int j = -1;
	next[i] = 0;
	while(i < len - 1)
	{	
		if (j == -1 || src[i] == pattern[j])
		{
			i++;
			j++;
			if (src[i] != src[j])
				next[i] = j;
			else 
				next[i] = next[j];
		} else
		{
			j = next[j];
		}
	}
}


int kmp_search(char *src, int src_len, char * pattern, int pattern_len, int pos, int *next)
{
	int i = pos;
	int j = 0;
	while(j < pattern_len && i < src_len)
	{
		if (j == -1 || src[i] == pattern[j])
		{
			i++;
			j++;
		}else
		{
			j = next[j];
		}
	}
	if (j == pattern_len)
		return i - j;
	else 
		return -1;
}
