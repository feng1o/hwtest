#include"iostream"
#include"string"

using namespace std;
char dealUper(char ch){
	char lower = tolower(ch);
	if (lower != 'z')
		lower = lower + 1;
	else
		lower = 'a';
	return lower;
}
char dealLower(char ch){
	int rInt;
	if (ch >= 'a' && ch <= 'c')
		return '2';
	if (ch >= 'd' && ch <= 'f')
		return '3';
	if (ch >= 'g' && ch <= 'i')
		return '4';
	if (ch >= 'j' && ch <= 'l')
		return '5';
	if (ch >= 'm' && ch <= 'o')
		return '6';
	if (ch >= 'p' && ch <= 's')
		return  '7';
	if (ch >= 't' && ch <= 'v')
		return  '8';
	if (ch >= 'w' && ch <= 'z')
		return  '9';
	return ' ';
}
int main(){
	string str;
	while (cin >> str){
		int len = static_cast<int>(str.size());
		string ans;
		for (int i = 0; i < len; ++i){
			if (isdigit(str.at(i)))
				ans.push_back(str.at(i));
			else if (isupper(str.at(i)))
				ans.push_back(dealUper(str.at(i)));
			else
				ans.push_back(dealLower(str.at(i)));
		}
		cout << ans;
	}
	return 0;
}