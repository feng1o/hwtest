#include<iostream>
#include<string>
#include<vector>

using namespace std;
int deal(vector<int> vec);
int main(){
	int n;
	while (cin >> n){
		vector<int> vec;
		while (n--){
			int k = 0;
			cin >> k;
			vec.push_back(k);
		}
		cout << deal(vec) << endl;
	}
	return 0;
}
int deal(vector<int> vec){
	int size = vec.size();
	int *lflag = new int[size]();
	int *rflag = new int[size]();
	for (int i = 0; i < size; ++i){
		lflag[i] = 1;
		rflag[i] = 1;
	}
	for (int i = 1; i < size; ++i){
		for (int j = 0; j < i; ++j)
			if (vec[i] > vec[j]){
				lflag[i] = max(lflag[j] + 1, lflag[i]);
			}
		// else 
		//     lflag[i] = lflag[i-1];
	}

	//last = vec[size-1];
	for (int i = size - 2; i >= 0; --i){
		for (int j = size - 1; j > i; --j)
			if (vec[i] > vec[j]){
				rflag[i] = max(rflag[j] + 1, rflag[i]);
			}
		//else
		//    rflag[i] = rflag[i+1];
	}
	int max = 0;
	for (int i = 0; i < size; ++i)
		max = std::max(max, lflag[i] + rflag[i] - 1);
	return size - max;
}