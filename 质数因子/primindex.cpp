/*
***************tip :输出string，不一定要cout <<string,,,cout << 2 << ' ' 也是string，！！！
               tip2:看清题意，让输出质数因子，并不是说列出所有可能出现的的质数因子，这里就是打印能被指数因子除jin的，

*Function name:
*Description:   
*Input :   

*Return Value:  
*Revision Date: 2016/05/16

*first 未能明白题目意思，并不是找到质数，就ok，，是要找出所有的质数因子，可重复的，
实际是以因子为准，找出因子，，，不管多少个，，，
另外，要明白不需要判定是不是因子的原因，因为从2开始除，总是一直到除不尽为止，再加，那么
不能被2除了，肯定也不能被4/8...除，，，同理3，，，不能其他的也不能，只能加到7，，，
*/

//正确版本 my
#include "iostream"
#include "string"
#include "iostream"
#include "sstream"

using namespace std;
int main(){
	//string str1;
	//cin >> str1;
	////str1.clear();   //clear erarse 
	//cout << "str1==" << str1 << endl;
	//
	//str1.erase();
	//cout << "str1==" << str1 << endl;

	//string str;
	//getline(cin, str);
	//stringstream ss(str);
	//string str2;
	//while (ss >> str2)
	//	cout << "str2 = "<< str2 << endl;
	//ss.str("");
	//cout << str2.size() << endl;
	long int num;
	cin >> num;
	int i = 2;
	while (num != 1){
		while (num % i == 0)
		{
			cout << i << ' ';
			num = num / i;
		}
		++i;
	}
	return 0;
}


#if 0
//起初版本，没看清提议，是找因子，，不是找因子中为质数的因子
//相同因子不重复出现，这个方法ok
#define _CRT_SECURE_NO_WARNINGS
#include"iostream"
#include"string"
#include"cmath"
using namespace std;

bool isPrim(long int &i){
	int sqrti = static_cast<int> (sqrt(i));
	for (long int j = 2; j <= sqrti; ++j){
		//cout << "prime  \n";
		if (i%j == 0)
			return false;
	}
	return true;
}
int main(){
	long int  num;
	string  str;
	cin >> num;
	//cout << num << endl;
	//for (int i = 2; i <= static_cast<int> (sqrt(num)); ++i){
	for (long int i = 2; i <= num / 2; ++i){
		if (isPrim(i) && (num % i == 0)){
			//cout << "in\n\n";
			if (!str.empty())
				str.append(1, ' ');
			//str.append(1, i);
			//str.append(_itoa(i,nullptr, 10));
			char *buf = new char[20];
			sprintf(buf, "%d", i);
			//itoa(i, buf, 10);
			str.append(buf);
		}
	}
	if (isPrim(num)){
		char *buf = new char[20];
		sprintf(buf, "%d", num);
		str.append(buf);
	}
	cout << str << ' ';

	return 0;
}
#endif

