/*Function name:
*Description:   
*Input :   stdin

*Return Value:  
*Revision Date: 2016/05/16
*/
#include "iostream"
#include "string"

using namespace std;

int main(){
	string str;
	int count = 0;
	while (getline(cin, str)){ //getline(cin, str ' ');
		// 不要while也是对的。。。。。。。
		count = 0;
		cout << str << endl;
		int len = str.size();
		bool barr[128] = { false };
		cout << barr[0] << endl;
		cout << barr[1] << endl;
		cout << barr[3] << endl;
		for (int i = 0; i < len; ++i)
		{
			barr[str.at(i)] ++;
		}
		for (auto it : barr)
		{
			if (it)
			{
				++count;
			}
		}
		cout << count << endl;
	}
	return 0;
}