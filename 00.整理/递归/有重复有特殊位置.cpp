//用1、2、2、3、4、5这六个数字，写一个main函数，打印出所有不同的排列，

//如：512234、412325等，要求："4"不能在第三位，"3"与"5"不能相连。

// str: 字符串
// begin: 字符串第一个字符的索引
// end: 字符串最后一个字符的索引
// cnt: 统计全排列的数目，调用之前赋值为0
#include "iostream"
#include "string"
#include "functional"
#include "numeric"
#include "algorithm"

void string_full_permutation_containing_duplicate_char2(char *str, int begin, int end, int &cnt){
	//string str2 = str;
	//if (str[2] == '4' || str2.find_first_of("35") != string::npos)  {return;}  //错误思路
	if (begin >= end){
		if (strstr(str, "53") != nullptr || strstr(str, "35") != nullptr)
			return;
		++cnt;
		cout << "str== " << str << endl;
		return;
	}// 124 23526667
	if (begin > 2 && str[2] == '4')  //1..不能取等于2，，因为=2只是处理到2号，，，2未必是4，，，也就等于去掉了4和后面几个的交换机会
		return;
	//5...
	string_full_permutation_containing_duplicate_char2(str, begin + 1, end, cnt);
	for (int i = begin + 1; i <= end; ++i)  //2..必须能取得 end。。。
	{
		if (str[i] != str[begin]){ //4..
			swap(str[i], str[begin]);
			string_full_permutation_containing_duplicate_char2(str, begin + 1, end, cnt);
			swap(str[i], str[begin]);
			//while (str[i] == str[i + 1])  //3..i+1不会出多。。。。
			//	++i;
		}
			while (str[i] == str[i + 1])  //3..i+1不会出多。。。。
				++i;
	}
}
int main(int argc, char **argv)
{
	char str[] = "142211";
	int len = strlen(str);
	int cnt = 0;

	//char str2[]{'1', '4', '3', '3','\0'};
	char str2[] = "142211";
	string_full_permutation_containing_duplicate_char2(str2, 0, len - 1, cnt);
	cout << endl << endl << cnt << endl;
}