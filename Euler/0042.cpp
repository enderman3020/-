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
	
	ifstream fs("0042.txt");
	
	string str;
	
	fs >> str;
	
	vector<string> v = split(str, ',');
	
	int ans = 0;
	
	for(int i = 0; i < v.size(); i++){
		cout << v[i] << " ";
		int num = 0;
		for(int j = 1; j < v[i].size() - 1; j++){
			num += v[i][j] - 'A' + 1;
		}
		cout << num << endl;
		for(int j = 1; j < 100; j++){
			if(num == j * (j + 1) / 2){
				ans++;
			}else if(num < j * (j + 1) / 2){
				break;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

