#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// str を sep で区切る
vector<string> split(const string &str, char sep)
{
    vector<string> v;
    stringstream ss(str);
    string buffer;
	
    while(getline(ss, buffer, sep)){
        v.push_back(buffer);
    }
	
    return v;
}

int main(){
	
	string str = "I want to split this string.";
	
	vector<string> v;
	
	v = split(str, ' ');
	
	for(int i = 0; i < v.size(); i++){
		cout << v.at(i) << "/" << endl;
	}
	
	return 0;
}
