#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;
long long int INF = 1e18;

long long int a[110000], LIS[110000];

int main(){
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i < N; i++){
		LIS[i] = INF;
	}
	
	bool flag = false;
	
	for(int i = 0; i < N; i++){
		int pos = lower_bound(LIS, LIS + N, a[i]) - LIS;
		LIS[pos] = a[i];
	}
	
	int num = (int)(lower_bound(LIS, LIS + N, INF) - LIS);
	
	cout << num << endl;
	
	return 0;
}