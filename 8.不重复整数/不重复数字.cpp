/*
***************tip :

*Function name:
*Description:
*Input :

*Return Value:
*Revision Date: 2016/05/16
*/
//easy..........................easy
#include "iostream"
#include "string"
#include "bitset"

using namespace std;

int main(){
	long int lnum = 0;
	while (cin >> lnum){
		cout << "input is:" << lnum << endl;
		int *a = new int[10]();
		long int ans = 0;
		while (lnum){
			int bitn = lnum % 10;
			if (a[bitn] == 0){
				ans = ans * 10 + bitn;
				a[bitn] = 1;
			}
			lnum = lnum / 10;
		}
		cout << ans << endl;
	}
	return 0;
}