#include <stdio.h> 

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		
		int a, b;
		scanf("%d %d", &a, &b);

		int ans =a%b ;
		printf("%d\n", ans);
	}

	return 0;
}