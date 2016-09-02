#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<cstdlib>
#include<stdio.h>
#include<cstring>
#include<sstream>

using namespace std;
void deal(vector<int> ivec, vector<int> rvec);
int main(){
	int n;
	vector<int> ivec;  //在while前面，必须记得clear，，。。。。。。。。
	cin >> n;
	while (n--){
		ivec.clear();
		int tmp;
		cin >> tmp;
		ivec.push_back(tmp);
	}
	cin >> n;
	vector<int> rvec;
	while (n--){
		int tmp;
		cin >> tmp;
		rvec.push_back(tmp);
	}
	deal(ivec, rvec);
	ivec.clear();
	return 0;
}

void deal(vector<int> ivec, vector<int> rvec){
	//rvec.sort();
	sort(rvec.begin(), rvec.end());
	int rsize = rvec.size();
	int isize = ivec.size();
	vector<int> rcover;
	int n = 0;
	vector<vector<pair<int, int> > > ipair;
	vector<pair<int, int>> vpair;
	for (int i = 0; i < rsize; ++i){
		stringstream ss;
		ss << rvec[i];
		string rstr;
		ss >> rstr;
		cout << "rstr=" << rstr << endl;
		ss.clear();
		for (int j = 0; j < isize; ++j){
			stringstream ss;
			ss << ivec[j];
			string jstr;
			ss >> jstr;
			cout << "jstr=" << jstr << endl;
			ss.clear();

			//if(strstr(itoa(ivec[j]), itoa(rvec[i])) != nullptr)            
			if (strstr(jstr.c_str(), rstr.c_str()) != nullptr){
				cout << ".........." << endl;
				vpair.push_back(make_pair(j, ivec[j]));
			}
		}
		if (!vpair.empty()){
			n += vpair.size();
			rcover.push_back(rvec[i]);
			rcover.push_back(vpair.size());
			ipair.push_back(vpair);
		}
		//ipair.push_back(vpair);
		vpair.clear();
		while (i + 1 < rsize && rvec[i] == rvec[i + 1])
			++i;
	}
	cout << n << " ";
	for (int i = 0; i < rcover.size(); i = i + 2){ //空格有无问题《，，，，，，，，，，，，，，，，，，，，，，，，，，，，，，
		cout << " " << rcover[i] << " " << rcover[i + 1];
		//cout << rcover[i] << " " << rcover[i + 1]  << " ";

		for (auto it : ipair[i / 2])
			cout << " " << it.first << " " << it.second;
		//cout << it.first << " " << it.second  << " ";

	}
}