/*tip:
1.切记在while循环输入多个测试用例的时候，清除clear所有可能存储的值，，，
2.输出格式，注意，可能没有任何值，此时不用输出，多输出endl也是error
3.如果某个条件可能为真，在循环判定中，可能遇到很多不便的，此时，必须在为真时候才做满足操作，否则可能后续操作多次，因不符合，为改变.*
*/

#if 01
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
void deal(vector<string> svec, string fstr, int rno);

int main(){
	int n;
	while (cin >> n){
		vector<string> svec;
		string str;
		while (n--){
			cin >> str;
			svec.push_back(str);
		}
		string  fstr;
		cin >> fstr;
		int rno = -1;
		cin >> rno;
		deal(svec, fstr, rno);
		//1.切记在while循环输入多个测试用例的时候，清除clear所有可能存储的值，，，
			svec.clear(); //
	}
	return 0;
}

void deal(vector<string> svec, string fstr, int rno){
	sort(svec.begin(), svec.end());
	int n = svec.size();
	//sort(fstr.begin(), fstr.end());
	int num = -1;
	string rstr = "";
	for (int i = 0; i < n; ++i){
		if (svec[i] == fstr)
			continue;
		string  bfstr = fstr;
		sort(fstr.begin(), fstr.end());
		string bstr = svec[i];
		sort(svec[i].begin(), svec[i].end());
		if (svec[i] == fstr){
			++num;
			cout << "num = " << num << endl;
		//}
		if ( num == rno)//{          //必须放在if里面，否则可能导致，没有相等时候num未变，最后返回的不是第一次的，，，，错误
			cout << "Num....i =" << i << endl;
			rstr = bstr;
		}
		fstr = bfstr;
	}
	cout << num << endl;
	if (!rstr.empty())   //格式.......................没这错误。。。。。。。。。。。
		cout << rstr << endl;
	cout << rstr << endl;

}
#endif