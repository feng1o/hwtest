#if 0
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int deal(string str);
int main(){
	string str;
	while (cin >> str){
		cout << deal(str);
		str.clear();
	}

	return 0;
}

int deal(string str){
	int size = str.size();
	int max = 0;
	for (int i = 0; i < size - 1; ++i){
		if (size - i <= max)
			break;
		int num = 0;
		for (int j = size - 1; j > i; --j){
			string substr = str.substr(i, j + 1);
			string substr2 = substr;
			reverse(substr.begin(), substr.end());
			if (substr == substr2){
				if (j - i + 1 > max)
					max = j - i + 1;
				break;
			}
		}
	}
	return max;
}
#endif