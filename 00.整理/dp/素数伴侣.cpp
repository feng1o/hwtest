//适用于对一堆数据，进行两两或者33匹配配对，怎么能配对数目最多，，动态规划

//素数伴侣 hw

#include<iostream>
#include <vector>
#include <cmath>
using namespace std;

//判断输入是不是素数
bool isPrime(int n){
	if (n <= 1) return false;

	for (int i = 2; i * i <= n; i++){
		if (n % i == 0) return false;
	}

	return true;
}
int PrimePairs(vector<int> &vi)
{
	int maxValue = 0;
	size_t n = vi.size();  //n即为总个数
	vector<int> dp(n + 1, 0); //定义一个含有n+1个数的容器，初始值均为0,dp[i]表示下标范围为[i, n-1]的范围内，最多的素数对数
	int cnt = 0;
	for (int i = n - 2; i > -1; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			//当vi[i]+vi[j]为素数,dp[i]+dp[j] = dp[i+1]+dp[j+1]+1;由于伴侣数成对出现，必然只能在i+1和j+1的基础上出现一对。

			//若和为素数，则将当前两个数i和j组成对，此时总对数dp[i]=放入j之前的最大对数 + j和i之间的整数能组成的最大对数 + 1（即i和j组成的一对）=dp[j+1]+（dp[i+1]-dp[j-1]）+1 。
			//j和i之间的整数能组成的最大对数（i和j都是开区间）应该不是（dp[i+1]-dp[j-1]），而是dp[i+1]-dp[j]

			//当vi[i]+vi[j]不为素数,dp[i] = dp[i + 1]
			//即i和j对应的数的和不为素数，则表示放入第i个数与没放入相同，故dp[i]=dp[i+1]。
			if (isPrime(vi[i] + vi[j]))
			{
				cnt = dp[i + 1] - dp[j - 1] + dp[j + 1] + 1;
				//cnt = dp[i + 1] - dp[j] + dp[j + 1] + 1;我觉得应该是这样，虽然后台说是上面那个对

			}
			else
			{
				cnt = dp[i + 1];
			}
			//更新dp[i]
			//为什么更新呢，因为上面的工作是把i加进去后更新，i和[i+1,n-1]里面所有能组成素数的组合都试过了，取最大的
			if (cnt > dp[i])
			{
				dp[i] = cnt;
			}
		}
	}
	return dp[0];
}
int main()
{
	int n;
	while (cin >> n)
	{
		//输入，把n个数放入vector容器中
		vector<int> v;
		int temp;
		for (int i = 0; i < n; i++){
			cin >> temp;
			v.push_back(temp);
		}

		//通过传入容器地址来调用子函数
		cout << PrimePairs(v) << endl;
	}
	return 0;
}