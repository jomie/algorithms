#include <iostream>
#include <assert.h>

using namespace std;

int check(int *arr, int m, int n, int key)
{
	assert(arr != NULL && m != 0 && n != 0);

	int			row = 0;
	int 		column = n - 1;
	bool 		bResult = false;

	while((row <= m - 1) && (column >= 0)) {
		if (key == arr[row * n + column]) {
			bResult = true;
			break;
		}else if (key < arr[row * n + column]) {
			column--;
		}else {
			row++;
		}	
	}
	return bResult;
}

int calc_utf8_count(unsigned char *data_ptr, unsigned int data_len)
{
	unsigned int		len = 0;
	unsigned char 		*data = data_ptr;
	unsigned int 		i = 0;
	bool 				flag = true;

	while (i < data_len) {
		if  (data[i] <= 127 && data[i] >= 0) {
			i++;
			len++;
		}else if ((data[i] >= 192 && data[i] <= 223) &&
				 ( data[i + 1] >= 128 && data[i + 1] <= 191)) {
				i += 2;
				len++;
		}else if ((data[i] >= 224 && data[i] <= 239) && 
					(data[i + 1] >= 128 && data[i + 1] <= 191) &&
					(data[i + 2] >= 128 && data[i + 2] <= 191)) {
			i += 3;
			len++;
		}else {
			flag = false;
			break;
		}
	}
	if (flag == false)
		len = -1;

	return len;
}



int main()
{
	int array[9] = {1,2,5,3,4,13,7,11,17};
	cout << check(array, 3, 3, 7) << endl;
	return 0;
}




