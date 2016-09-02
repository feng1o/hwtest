#include"iostream"
#include"vector"
#include "cmath"
#include "algorithm"
using namespace std;
bool compaire(int a, int  b){ return a <= b; }
int main(){
	int n;
	while (cin >> n){//这个不能少，，否则error！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
		vector<int> ivec;
		for (int i = 0; i < n; ++i){
			int tmp;
			cin >> tmp;
			ivec.push_back(tmp);
		}
		sort(ivec.begin(), ivec.end());
		//int tmp;
		if (n >= 1){
			//tmp = ivec[0];
			cout << ivec[0] << endl;
		}
		int k = 1;
		while (k < n){
			if (ivec[k - 1] != ivec[k])
			{
				cout << ivec[k] << endl;
				//tmp = ivec[k];
//				++k;  //tip>>>>>>>>>>>>>>>>>>>>>>>>>>>>>注意，不要在if里面操作一个索引值
			}
			++k;
		}
	}
	return 0;
}