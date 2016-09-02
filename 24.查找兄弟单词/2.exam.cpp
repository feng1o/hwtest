#if 0
#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> dict;

bool is_friend(string a, string b) {
	if (a == b) return false;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	return a == b;
}

int main() {
	int n;
	while (scanf("%d", &n) == 1) {
		dict.clear();

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			dict.push_back(s);
		}
		sort(dict.begin(), dict.end());

		string ask;
		cin >> ask;
		int id;
		scanf("%d", &id);


		int cnt = 0;
		string res = "";
		for (int i = 0; i < (int)dict.size(); i++) {
			if (is_friend(dict[i], ask)) {
				cnt++;
				if (cnt == id) {
					res = dict[i];
				}
			}
		}

		printf("%d\n", cnt);
		if (cnt >= id)
			printf("%s\n", res.c_str());
	}
	return 0;

}
#endif