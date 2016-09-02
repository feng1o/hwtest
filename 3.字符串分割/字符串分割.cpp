/*Function name:
*Description:  
*Input :   stdin

*Return Value:  
*Revision Date: 2016/05/16
*/
#include "iostream"
#include "string"
#include "new"

using namespace std;
int main(){
	string str;
	while ((cin >> str) != EOF){
		int len = str.size();
		string  rstr;
		int j = 0;
		for (int i = 0; i < len; ++i)
		{
			rstr.append(1, str[i]);
			if (++j == 8){
				rstr.push_back('\n');
				j = 0;
				cout << rstr;
				rstr.clear();
			}
		}
		if (j != 0 && j != 8)
		{
			rstr.append(8 - j, '0');//不能append的一个数组,,
			rstr.insert(rstr.end(), '\n');
			j = 0;
			cout << rstr;
			rstr.clear();
		}
	}
	return 0;
}

//最初error
/*
#include"iostream"
#include"string"
#include"vector"
using namespace std;

int main(){
	string str;
	while (getline(cin, str)){
		int len = str.size();
		char* ch = const_cast<char*> (str.c_str());
		char  ans[9];
		int i = 0;
		for (int j = 0; i < len; ++j){
			if (isalnum(ch[j])){
				ans[i++] = ch[j];
				if (i == 8){
					ans[8] = '\n';
					cout << ans;
					i = 0;
				}
				if (!isalnum(ch[j])){
					if (8 != i)
						while (i != 8){
							ans[i++] = '0';
						}
					ans[i] = '\n';
					cout << ans;
					i = 0;
				}

			}
		}
	}
	return 0;
}
*/