/*
tip:
1.dp问题，，，，，理解提议，，，，本搞错
2.动态规划过程，，，，，必须依赖一个结构保存状态,,,,,,
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> isPrim(int n);

int main(){
	int n;
	vector<int> ivec;
	while (cin >> n){
		ivec.clear();
		int nn = n;
		while (nn--){
			int tmp = 0;
			cin >> tmp;
			ivec.push_back(tmp);
		}
		vector<int> prim = isPrim(60000);  //ok的，，，

		vector<int> nvec(n + 1, 0);   //n+1很关键，，，，，，，，，，，，，，，，，，，n不对，，
		for (int i = n - 2; i >= 0; --i){
			int num = 0;
			for (int j = n - 1; j > i; --j){
				//cout << ivec[i] + ivec[j] << endl;
				if (prim[ivec[i] + ivec[j]] == 1){
					num = nvec[j + 1] - nvec[j - 1] + nvec[i + 1] + 1;
				}
				else
					num = nvec[i + 1];
				if (num > nvec[i])
					nvec[i] = num;
			}
		}
		cout << nvec[0] << endl;
	}
	return 0;
}

vector<int> isPrim(int n){
	vector<int>  prim(n + 1, 1);
	prim[0] = -1;
	for (int i = 2; i <= n; ++i){
		if (prim[i] == 1)
			for (int j = i + i; j <= n; j = j + i)
				prim[j] = -1;
		else
			continue;
	}
	return prim;
}