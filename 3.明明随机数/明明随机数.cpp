#if 0
#include"iostream"
#include"vector"
#include "cmath"
#include "algorithm"
using namespace std;
bool compaire(int& a, const int & b){ return a >= b; }
int main(){
	int n;
	cin >> n;
	vector<int> ivec;
	for (int i = 0; i < n; ++i){
		int tmp;
		cin >> tmp;
		ivec.push_back(tmp);
	}
	sort(ivec.begin(), ivec.end(),compaire);
	int tmp = ivec[--n];
	cout << tmp << endl;
	while (n){
		if (tmp != ivec[n-1])
		{
			cout << ivec[n-1] << endl;
			tmp = ivec[n - 1];
			--n;
		}
	}
	return 0;
}
#endif