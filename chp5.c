#include <stdio.h>

int func();
void testFunc();

// for p89--4
void set_bit(char bit_array[], unsigned bit_number);
void clear_bit(char *bit_array, unsigned bit_number);
void assign_bit(char *bit_array, unsigned bit_number, int value);
int test_bit(char *bit_array, unsigned bit_number);

// for p113

int main()
{	
	int a[5];
	int i ;
	int *p = NULL;
	for (i = 0; i < 5; i++) {
		a[i] = i;
	}
	p = a;
	for (i = 0; i < 5; i++) {
		printf("a[%d] = %d\n", i, (*p)++);
	}
	

	return 0;
}


int func()
{
	static int counter = 1;
	return ++counter;
}
void testFunc()
{
	int answer;
	answer = func() - func() * func();
	printf("answer = %d\n", answer);
}

void set_bit(char *bit_array, unsigned bit_number)
{
	switch (bit_number % 8) {
		case 0:
			bit_array[bit_number / 8] |= 0x80;
			break;
		case 1:
			bit_array[bit_number / 8] |= 0x40;
			break;
		case 2:
			bit_array[bit_number / 8] |= 0x20;
			break;
		case 3:
			bit_array[bit_number / 8] |= 0x10;
			break;
		case 4:
			bit_array[bit_number / 8] |= 0x08;
			break;
		case 5:
			bit_array[bit_number / 8] |= 0x04;
			break;
		case 6:
			bit_array[bit_number / 8] |= 0x02;
			break;
		case 7:
			bit_array[bit_number / 8] |= 0x01;
			break;
		default:
			break;
	}
}

void clear_bit(char *bit_array, unsigned bit_number)
{
	switch (bit_number % 8) {
		case 0:
			bit_array[bit_number / 8] &= 0x7f;
			break;
		case 1:
			bit_array[bit_number / 8] &= 0xbf;
			break;
		case 2:
			bit_array[bit_number / 8] &= 0xdf;
			break;
		case 3:
			bit_array[bit_number / 8] &= 0xef;
			break;
		case 4:
			bit_array[bit_number / 8] &= 0xf7;
			break;
		case 5:
			bit_array[bit_number / 8] &= 0xfb;
			break;
		case 6:
			bit_array[bit_number / 8] &= 0xfd;
			break;
		case 7:
			bit_array[bit_number / 8] &= 0xfe;
			break;
		default:
			break;
	}
}

void assign_bit(char *bit_array, unsigned bit_number, int value)
{
	if (value != 0) {
		set_bit(bit_array, bit_number);
	} else {
		clear_bit(bit_array, bit_number);
	}
}

int test_bit(char *bit_array, unsigned bit_number)
{
	int flag = 0;
	switch (bit_number % 8) {
		case 0:
			if ((bit_array[bit_number / 8] & 0x80) != 0)
				flag = 1;
			break;
		case 1:
			if ((bit_array[bit_number / 8] & 0x40) != 0)
				flag = 1;
			break;	
		case 2:
			if ((bit_array[bit_number / 8] & 0x20) != 0)
				flag = 1;
			break;	
		case 3:
			if ((bit_array[bit_number / 8] & 0x10) != 0)
				flag = 1;
			break;	
		case 4:
			if ((bit_array[bit_number / 8] & 0x08) != 0)
				flag = 1;
			break;
		case 5:
			if ((bit_array[bit_number / 8] & 0x04) != 0)
				flag = 1;
			break;	
		case 6:
			if ((bit_array[bit_number / 8] & 0x02) != 0)
				flag = 1;
			break;	
		case 7:
			if ((bit_array[bit_number / 8] & 0x01) != 0)
				flag = 1;
			break;	
	}
	if (flag == 1)
		return 1;
	else 
		return 0;
}