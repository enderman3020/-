#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <list>

using namespace std;

typedef pair<double, double> P;
long long int INF = 1e18;
long long int MOD = 1e9 + 7;

int N;
P A[500001];

bool compare_y(P a, P b){
	return a.second < b.second;
}

// Å‹ß‚Q“_ŠÔ‹——£‚ð‹‚ß‚é
double closest_pair(P *a, int n){
	if(n <= 1){
		return INF;
	}
	int m = n / 2;
	double x = a[m].first;
	double d = min(closest_pair(a, m), closest_pair(a + m, n - m));
	inplace_merge(a, a + m, a + n, compare_y);
	
	vector<P> b;
	for(int i = 0; i < n; i++){
		if(fabs(a[i].first - x) >= d){
			continue;
		}
		for(int j = 0; j < b.size(); j++){
			double dx = a[i].first - b[b.size() - j - 1].first;
			double dy = a[i].second - b[b.size() - j - 1].second;
			if(dy >= d){
				break;
			}
			d = min(d, sqrt(dx * dx + dy * dy));
		}
		b.push_back(a[i]);
	}
	return d;
}

int main(){
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> A[i].first >> A[i].second;
	}
	
	sort(A, A + N);
	
	printf("%.10f\n", closest_pair(A, N));
	
	return 0;
}