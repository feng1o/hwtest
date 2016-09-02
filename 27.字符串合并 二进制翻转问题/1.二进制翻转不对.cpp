//char ch;   //二进制的逆转不能这样做，没有一个简单方法。。


#include<string>
#include<iostream>
#include<algorithm>
char change(char &c);

using namespace std;

int main(){
	/*char ch;   //二进制的逆转不能这样做，没有一个简单方法。。
	cin >> ch;
	cout << ":ch;" << ch << endl;
	cout << "ch ... " << ~ch << endl;
	char ch2 = ~ch;
	cout << "ch2 " << *((char*)(&ch2)) << endl;*/
	string str1;
	string  str2;
	while (cin >> str1 >> str2){
		string str = str1 + str2;
		str1.clear();
		str2.clear();
		int size = str.size();
		for (int i = 0, flag = true; i < size; ++i){
			if (flag){
				str1.push_back(str[i]);
				flag = false;
			}
			else{
				str2.push_back(str[i]);
				flag = true;
			}
		}
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());
		for (int i = 0, j = 0, k = 0, flag = true; i < size; ++i){
			if (flag){
				str[i] = change(str1[j++]);
				flag = false;
			}
			else{
				str[i] = change(str2[k++]);
				flag = true;
			}
		}
		cout << str << endl;
	}
	return 0;
}

char change(char &c){
	switch (c){
	case '0': c = '0'; break;
	case '1': c = '8'; break;
	case '2': c = '4'; break;
	case '3': c = 'C'; break;
	case '4': c = '2'; break;
	case '5': c = 'A'; break;
	case '6': c = '6'; break;
	case'7':c = 'E'; break;
	case'8':c = '1'; break;
	case'9':c = '9'; break;
	case 'a':c = '5'; break;
	case('b') : c = 'D'; break;
	case('c') : c = '3'; break;
	case('d') : c = 'B'; break;
	case('e') : c = '7'; break;
	case('f') : c = 'F'; break;
	case('A') : c = '5'; break;
	case('B') : c = 'D'; break;
	case('C') : c = '3'; break;
	case('D') : c = 'B'; break;
	case('E') : c = '7'; break;
	case('F') : c = 'F'; break;
	default:break;

	}
	return c;
}