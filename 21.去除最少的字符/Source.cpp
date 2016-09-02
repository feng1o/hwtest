#if 0
#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int>  deal(char *ch, int len);
int main(){
	string str;
	while (cin >> str){
		vector<int> vec = deal(const_cast<char*>(str.c_str()), str.size());
		string substr;
		for (auto it : vec)
			substr.push_back('a' + it);
		size_t pos;
		do{
			pos = str.find_first_of(substr);  //默认从0开始的pos = str.find_first_of(substr, 0);
			if (pos != string::npos)
				str.erase(str.begin() + pos);
			//str.erase(pos, 1);///tip...........................不是迭代器，不鞥年直接某个位置
		} while (pos != string::npos);
		cout << str << endl;

	}
	return 0;
}

vector<int> deal(char *ch, int len){
	int a[26];
	for (int i = 0; i < 26; ++i)
		a[i] = 0;
	for (int i = 0; i < len; ++i)
		++a[ch[i] - 'a'];
	int min = -1;
	for (int i = 0; i < 26; ++i){
		if (a[i] > 0){
			if (min == -1)
				min = i;
			else if (a[i] < a[min])
				min = i;
		}
	}
	vector<int> vec;
	vec.push_back(min);
	for (int i = 0; i < 26; ++i){
		if (a[i] == a[min])
			vec.push_back(i);
	}
	return  vec;
}
#endif