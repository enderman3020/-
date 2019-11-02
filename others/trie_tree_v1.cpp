#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

class Trie{
	public:
	Trie* next[26];
	
	Trie(){
		fill(next, next + 26, (Trie*)0);
	}

	void insert(const char *s){
		if(*s == '\0') return;
		if(this->next[*s - 'a'] == NULL){
			this->next[*s - 'a'] = new Trie();
		}
		this->next[*s - 'a']->insert(s + 1);
	}

	bool find(const char *s){
		if(*s == '\0') return true;
		if(this->next[*s - 'a'] == NULL){
			return false;
		}
		return this->next[*s - 'a']->find(s + 1);
	}
};

int main(){
	
	Trie T;
	string str;
	cin >> str;
	T.insert(str.c_str());
	T.insert("fuga");
	T.insert("piyo");
	cout << T.find("fug") << endl;
	cout << T.find("bug") << endl;
	cout << T.find("hog") << endl;
	return 0;
}