/*Function name:
*Description:   
*Input :   stdin

*Return Value:  
*Revision Date: 2016/05/16
*/
#include<iostream>
#include "string"
using namespace std;

int main(){
	string str;
	char ch;
	int *a = new  int[256]();
// 	string xx = "abcdef";
// 	cout << xx[1] << endl;
// 
// 	a['a'] = 2;
// 	cout << dec << 'a' << endl;
// 	cout << "a [a] :" << a['a'] << endl;
// 
// 	a['a' - '0'] = 1;
// 	cout << 'a' - '0' << endl;
// 	cout << "xxx :" << a['a'-'0'] << endl; //ok
// 	cout << a[0] << " " << a[2] << endl;

// 	a[xx[1]] = 11;
// 	cout << a[xx[1]] << endl;  //0k

	//while(getline(cin, str, '\n')){
	getline(cin, str, '\n');
	{
		cout << "str is :" << str << endl;
		//stringstream ss(str);

		int len = str.length();
	//	if (len == 1)
			for (int i = 0; i < len; ++i){
				a[str[i]]++;
				cout << "str[" << str[i] << "]   :" << a[str[i]] << endl;
			}
		//str.clear();
	}
	for (int i = 0; i < 256; ++i)
 	{
		if (a[i] != 0)
		{
			cout << a[i] << endl;
		}
 	}
	//cin.ignore(10000, ' ');
	//cin.clear();

	cin >> ch;
	cout << "ch :" << ch << endl;
	cout << a[ch] << endl;
	//cout << ch << endl;
	return 0;
}