
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> vec(n), dp(n), dq(n);
		int i, k, j, ma = 0;
		for (i = 0; i < n; ++i)
		{
			cin >> vec[i];
			dp[i] = 1;
			dq[i] = 1;
		}
		for (i = 1; i < n; ++i)
		{
			for (j = 0; j < i; ++j)
			{
				if (vec[i] > vec[j])
					dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		for (i = n - 2; i >= 0; --i)
		{
			for (j = n - 1; j > i; --j)
			{
				if (vec[i] > vec[j])
					dq[i] = max(dq[i], dq[j] + 1);
			}
		}
		for (i = 0; i < n; ++i)
			ma = max(ma, dp[i] + dq[i] - 1);
		cout << n - ma << endl;
	}
	return 0;
}