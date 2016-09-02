#if 0
#include <iostream>

using namespace std;

int main(void)
{
	long input;
	//cin >> input;
	while (cin >> input)
	{
		while (input != 1)
		{
			for (int i = 2; i <= input; i++)
			{
				if (input % i == 0)
				{
					input /= i;
					cout << i << ' ';
					break;
				}
			}
		}

	}



	return 0;
}
#endif


#if 0

/*需要注意的是输出的最后一个质数因子也需要以空格结束*/
#include<iostream>

using namespace std;

void trial_divisio_fac(int n){
	int a = 2;
	while (a*a <= n){
		while (n%a == 0){
			cout << a << ' ';
			n = n / a;
		}
		a++;
	}
	if (n > 1) cout << n << ' ';
}
int main(){
	int n;
	cin >> n;
	trial_divisio_fac(n);
	return 0;
}
#endif