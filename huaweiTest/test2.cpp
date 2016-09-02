#if 0
#include "iostream"
#include "string"

using namespace std;
int main(){
	int n = 5;
	int m = 2;

	int *arr = new int[n]();
	for (int i = 0; i < n; ++i)
		cout << arr[i] << endl;
	int  index = 0;
	for (int i = 0; i < n + 3; ++i){
		int k = 0;
		while (1){
			if (arr[index] == 0)
				++k;
			if (k == m){
				arr[index] = 1;
				cout << index << endl;
				cout << endl;
				++index;
				index = index % n;
				break;
			}
			++index;

			index = index % n;

		}
	}
	cout << "   " << index << endl;
	return index;
}
#endif