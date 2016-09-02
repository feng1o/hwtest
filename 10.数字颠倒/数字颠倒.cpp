#if 0
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

int main(){
	int num;
	cin >> num;
	int ians = 0;
	while (num){
		int bitnum = num % 10;
		ians = ians * 10 + bitnum;
		num /= 10;
	}
	cout << ians << endl;
	return 0;
}
#endif