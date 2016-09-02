#include"iostream"

using namespace std;
int main(){
	int num;
	int flag = 1;
	int count = 0;
	while (cin >> num){
		while (flag){
			if (flag & num)
				count++;
			flag = flag << 1;
		}
		cout << count << endl;
	}
	return 0;
}
int main2(){
	int num;
	int count = 0;
	while (cin >> num){
		while (num){
			if (num % 2 == 1){
				++count;
			}
			num = num / 2;
		}
		cout << count << endl;
	}
	return 0;
}