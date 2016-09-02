
/*Function name:
*Description:   进制转换
*Input :   stdin

*Return Value:  转换为10进制
*Revision Date: 2016/05/16
牛客上输出总是有问题，，vs是ok的，，牛客会出现输出为空？为什么？
为什么有时候不能输出，在成员函数内部或者main单独输出不会有，必须两处都cout才会，此时又重复，且值不对？？？
*/

#include"iostream"
#include"string"
#include "istream"
#include"cmath"
#include"sstream"
using namespace std;
class cRadixTransfer{
public:
	cRadixTransfer() :m_inStrHex(), m_len(0){};
	istream& input(istream &in){

		//cin.ignore(1000, '0');
		//istream &in2 = getline(in, xxxx),,,//错误的，重载运算符可参考
		getline(in, m_inStrHex);
		m_len = m_inStrHex.size();
		//cout << m_inStrHex << "\nlength : " << m_len << endl;
		return in;
	}
	long long int radixTrans();
private:
	string m_inStrHex;
	int m_len;
};



int main(){
	//int a;
	//while(cin >> hex >> a)
	//cout << a;
	cRadixTransfer radixTransfer;
	while (radixTransfer.input(cin)){
		long long int ans = radixTransfer.radixTrans();
		//cout << ans << endl;
	}
	/*    stringstream ss;
	ss << ans;
	string str;
	ss >> str;
	cout << str <<endl;
	*/
	//char a[20];
	// sprintf(a, "%d", ans);
	//str.append(a);
	//cout << str;
	return 0;
}

long long int cRadixTransfer::radixTrans(){
	long long int deci = 0;
	for (int i = m_len; i > 2; --i)
	{
		if (isalpha(m_inStrHex[i - 1]))
		{
			//cout << "is alpha" << m_inStrHex[i-1] << endl;
			int index = m_inStrHex[i - 1] - 'A';
			deci += (10 + index) * static_cast<int> (pow(16.0, m_len - i));
		}
		else{
			int index = m_inStrHex[i - 1] - '0';
			deci += (index)* static_cast<int> (pow(16.0, m_len - i));
		}
	}
	stringstream ss;
	ss << deci;
	string str;
	ss >> str;
	cout << str << endl;

	return deci;
}


















/*

//gets 
#include<stdio.h>
#include<math.h>
#include<string.h>

int htod(char *hStr)
{
	int d = 0, td = 0;
	int len = strlen(hStr);
	int ind = len - 1;
	char c;
	while (ind >= 2)
	{
		c = *(hStr + ind);
		if (c >= '0' && c <= '9')
		{
			td = c - '0';
		}
		else if (c >= 'a' && c <= 'f')
		{
			td = c - 'a' + 10;
		}
		else if (c >= 'A' && c <= 'F')
		{
			td = c - 'A' + 10;
		}
		d = d + td*pow(16, len - 1 - ind);
		ind--;
	}
	return d;
}

int main()
{
	char hStr[100];
	while (scanf("%s", hStr) != EOF)
	{
		printf("%d\n", htod(hStr));
	}
}*/