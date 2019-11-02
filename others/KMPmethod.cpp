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
#include <set>
#include <unordered_map> 
#include <unordered_set>

using namespace std;

typedef pair<long long int, long long int> P;
typedef tuple<int, int, int> T;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

const int MAX_N = 210000;

int table[MAX_N];
void createTable(string pat){
    table[0] = -1;
    int j = -1;
    for(int i = 0; i < pat.size(); i++){
        while(j >= 0 && pat[i] != pat[j]){
            j = table[j];
        }
        j += 1;
        table[i + 1] = j;
    }
}

int KMPSearch(string target, string pattern){
    createTable(pattern);
    int ret = 0;
    int i = 0, p = 0;
    while(i < target.size() && p < pattern.size()){
        if(target[i] == pattern[p]){
            i += 1;
            p += 1;
        }else if(p == 0){
            i += 1;
        }else{
            p = table[p];
        }
    }
    if(p == pattern.size()){
        return i - p;
    }
    return -1;
}

int main(){
    int pos = KMPSearch("ABCABABCABABA", "ABCABABA");
    cout << pos << endl;
	return 0;
}