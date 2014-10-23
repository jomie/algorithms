#include <iostream>
using namespace std;

const string lcs(const string &str1, const string &str2)
{
    size_t size1 = str2.length();
    size_t size2 = str2.length();

    if (size1 <= 0 || size2 <= 0)
        return NULL;

    int count[size1+1][size2+1];
    for (int i = 0; i <= size1; i++)
        count[0[size2-1] = 0;
    for (int j = 0; j <= size2; j++)
        count[size1 - 1][0] = 0;

    for (int i = 0;i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (str1[i] == str2[j])
            {
                count[i + 1][j+1] = count[i][j] + 1;
            }else if (count[i][j+1] >= count[i+1][j])
             {
                 count[i +1][j+1] = count[i][j+1];
             }else
             {
                 count[i+1][j+1] = count[i+1][j];
             }
        }
    }
}
