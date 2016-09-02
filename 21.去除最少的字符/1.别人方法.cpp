#include <iostream>
#include <string>
using namespace std;
int main()
{
	int i, m, min;
	int a[26];
	string str, temp;
	while (cin >> str)
	{
		for (int i = 0; i < 26; i++)
			a[i] = 0;

		m = str.size();
		for (i = 0; i < m; i++)
			a[str[i] - 'a']++;
		min = a[str[0] - 'a']; //这个方法不错....
		for (i = 0; i < m; i++)
			if (a[str[i] - 'a'] <= min)
				min = a[str[i] - 'a'];
		for (i = 0; i < m; i++)
			if (a[str[i] - 'a'] > min)
				cout << str[i];  //here。。。。。。

		cout << endl;
	}
	return 0;
}