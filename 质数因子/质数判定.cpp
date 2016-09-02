#if 0


#include "iostream"
#include "string"

using namespace  std;

bool isPrim(int &i){
	int sqrti = static_cast<int> (sqrt(i));
	for (int j = 2; j <= sqrti; ++j){
		if (i%j == 0)
			return false;
	}
	return true;
}
	
int  main(){
	int num;
// 	cin >> num;
// 	cout << "num is =" << num;
// 	int sqrti = static_cast<int> (sqrt(num));
// 	for (int j = 2; j <= sqrti; ++j){
// 		if (num%j == 0)
// 			cout << "prime ....." << j << endl;
// 	}
	for (int i = 0; i < 100; ++i)
	{
		if (isPrim(i))
			cout << "prime :" << i << endl;
	}
	return 0;
}

#endif