#if 0

/*Function name:
*Description:   进制转换
*Input :   stdin

*Return Value:  转换为10进制
*Revision Date: 2016/05/16
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
	string input(istream &in){
		getline(in, m_inStrHex);
		m_len = m_inStrHex.size();
		//cout << m_inStrHex << "\nlength : "<< m_len << endl;
		return m_inStrHex;
	}
	int radixTrans();
private:
	string m_inStrHex;
	int m_len;
};



int main(){
	cRadixTransfer radixTransfer;
	radixTransfer.input(cin);
	int ans = radixTransfer.radixTrans();

	cout << ans << endl << endl;
	stringstream ss;
	ss << ans;
	string str;
	ss >> str;
	cout << "str" << str << endl;

	return 0;
}

int cRadixTransfer::radixTrans(){
	int deci = 0;
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
	return deci;
}
#endif