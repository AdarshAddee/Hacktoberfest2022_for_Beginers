#include <iostream>
#define r 3
#define c 3
using namespace std;
int main()
{
	int i, j, flag = 0;
	 int arr[r][c];
	if (r != c)
		cout << "\nNot a symmetric matrix";
	else
	{
		cout << "\nEnter the values in the matrix :" << endl;
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				cin >> arr[i][j];
			}
		}
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				if (arr[i][j] != arr[j][i])
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0)
			cout << "\nIt's a symmetric matrix";
		else
			cout << "\nNot a symmetric matrix";
	}
	return 0;
}