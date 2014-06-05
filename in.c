#include <stdio.h>

int main(int argc, char *argv)
{
	char str[50];

	//printf("%s\n", argv[0]);

	while (scanf("%s",str) != EOF) {
		printf("%s\n", str);
	}
	return 0;
}