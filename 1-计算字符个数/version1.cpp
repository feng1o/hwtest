#if 0
#include<iostream>

using namespace std;

int main(){
	string str;
	char ch;
	char a[256] = { 0 };  //1.error char  2.ERROR no initialization，，，
	//while(getline(cin, str, '\n')){
	getline(cin, str, '\n');
	{
		//stringstream ss(str);

		int len = str.length();
		if (len == 1)
			for (int i = 0; i < len; ++i){
				a[str[i]]++;
			}
		str.clear();  //清状态的，这里没用
	}
	cin.ignore(10000, ' ');
	//cin.clear();

	cin >> ch;
	cout << a[ch] << endl;
	//cout << ch << endl;
	return 0;
}
#endif