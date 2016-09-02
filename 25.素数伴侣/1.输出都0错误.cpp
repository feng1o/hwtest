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
		vector<int> prim = isPrim(60000);  //okµÄ£¬£¬£¬
		int num = 0;
		for (int i = 0; i < n; ++i){
			for (int j = i + 1; j < n; ++j){
				cout << ivec[i] + ivec[j] << endl;
				if (prim[ivec[i] + ivec[j]] == 1){
					++num;
				}
			}
		}
		cout << num << endl;
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