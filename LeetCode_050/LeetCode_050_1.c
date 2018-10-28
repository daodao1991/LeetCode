#include <stdio.h>

#define MIN -2147483648
#define MAX 2147483647

int main()
{
	double mypow(double x, int n)
	{
		double res;
		if(n == 0)
			return 1;
		if(n < 0)
		{
			n = -n;
			x = 1/x;
		}

		if(n % 2 == 0)
		{
			res = mypow(x*x, n/2);
		}
		else
			res = x*mypow(x*x, n/2);
		
		if(res > MAX || res < MIN)
			return 0;
		return res;
	}
	
	double x, res;
	int n;
	printf("请输入所求幂指数的底数和指数：");
	scanf("%lf%d", &x,&n);
	res = mypow(x, n);
	printf("%lf\n", res);
	return 0;
}
