#include<iostream>
#include<string>

using namespace std;

string quickSort(string str, int begin, int end){
	if (begin < end){
		cout << "beging =" << begin << "end=" << end << endl;
		char key = str[begin];
		int lhs = begin;
		int rhs = end;
		while (lhs < rhs){
			while (lhs < rhs && str[lhs] <= key)
				++lhs;
			while (rhs > lhs && str[rhs] > key)
				--rhs;
			swap(str[lhs], str[rhs]);
		}
		cout << rhs << endl;
		swap(str[begin], str[rhs]);
		quickSort(str, begin, rhs - 1);
		quickSort(str, rhs + 1, end);
	}
	return str;

}

int main(){
	string str;
	while (cin >> str){
		cout << quickSort(str, 0, str.size() - 1) << endl;
	}
	return 0;
}