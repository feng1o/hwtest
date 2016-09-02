#include<string>
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>

using namespace std;

int main(){
	string str;
	while (getline(cin, str)){
		int size = str.size();
		stack<string, vector<string>> stack;
		string stmp = "";
		for (int i = 0, flag = -1; i < size; ++i){
			if (flag == -1)
				stmp.clear();
			if (isalpha(str[i]) && isprint(str[i])){
				stmp.push_back(str[i]);
				flag = 1;
			}
			else{
				flag = -1;
				if (!stmp.empty())
					stack.push(stmp);
			}

		}
		if (!stmp.empty()){
			stack.push(stmp);
			stmp.clear();
			//if(!stmp.empty())
			//	cout << stmp << " ";
			//stack.pop();
		}
		cout << "tst:" << (stack.top()).size() << endl; 
		cout << stack.top() << endl;
		while (!stack.empty()){
			cout << stack.top() << " ";
			stack.pop();
		}
	}
	return 0;
}