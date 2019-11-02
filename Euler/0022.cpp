#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// •¶š—ñ‚ğ“Á’è‚Ì•¶š‚Å‹æØ‚Á‚Ä•ªŠ„‚·‚é
vector<string> split(const string &str, char sep){
	vector<string> v;
	stringstream ss(str);
	string buffer;
	
	while(getline(ss, buffer, sep)){
		v.push_back(buffer);
	}
	
	return v;
}

int main(){
	
	ifstream fs("0022.txt");
	
	string str;
	
	fs >> str;
	
	vector<string> v = split(str, ',');
	
	sort(v.begin(), v.end());
	
	long long int ans = 0;
	
	for(int i = 0; i < v.size(); i++){
		string str_name = v[i].substr(1, v[i].size() - 2);
		int score = 0;
		for(int j = 0; j < str_name.size(); j++){
			score += str_name[j] - 'A' + 1;
		}
		ans += score * (i + 1);
		cout << str_name << endl;
	}
	
	cout << ans << endl;
	
	return 0;
}

