#if 01
/*Function name:
*Difficulty:   too easy,
*Description:    
*Input :   stdin

*Return Value:  
*Revision Date: 2016/05/16
*/
#include "iostream"
#include "string"

using namespace std;

//int main(){
//	string str1;
//	while (cin >> str1){
//		reverse(str1.begin(), str1.end()); //不能使用reverse
//		cout << str1 << endl;
//		str1.clear();
//	}
//	return 0;
//}
int main(){
	string str1;
	while (cin >> str1){
		reverse(str1.begin(), str1.end()); //不能使用reverse
		cout << str1 << endl;
		string rstr;
		while (!str1.empty()){
			rstr.append(1, str1.back());
			str1.pop_back();
		}
		cout << rstr << endl;
		str1.clear();
	}
	return 0;
}

#endif