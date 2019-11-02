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
long long int MOD = 998244353;

vector<P> factors[1100000];

int main(){
	for(int i = 2; i <= 1000100; i++){
		if(factors[i].size() == 0){
			long long int num = i;
			for(int pNum = 1; num <= 1000100; pNum++){
				for(int j = num; j <= 1000100; j += num){
					if(pNum != 1){
						factors[j].pop_back();
					}
					factors[j].push_back(P(i, pNum));
				}
				num *= i;
			}
		}
	}
	for(int i = 2; i <= 100; i++){
		cout << i << " = ";
		for(int j = 0; j < factors[i].size(); j++){
			if(j != 0){
				cout << " * ";
			}
			P p = factors[i][j];
			cout << p.first << "^" << p.second;
		}
		cout << endl;
	}
	return 0;
}