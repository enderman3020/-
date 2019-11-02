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

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

typedef pair<int, int> PP;

double EPS = 1e-10;

double add(double a, double b){
	if(abs(a + b) < EPS * (abs(a) + abs(b))){
		return 0;
	}
	return a + b;
}

struct P{
	double x, y;
	P(){}
	P(double x, double y) : x(x), y(y){}
	P operator + (P p){
		return P(add(x, p.x), add(y, p.y));
	}
	P operator - (P p){
		return P(add(x, -p.x), add(y, -p.y));
	}
	P operator * (double d){
		return P(x * d, y * d);
	}
	double dot(P p){
		return add(x * p.x, y * p.y);
	}
	double det(P p){
		return add(x * p.y, -y * p.x);
	}
};

// x -> y の順にソート
bool cmp_x(const P& p, const P& q){
	if(p.x != q.x){
		return p.x < q.x;
	}
	return p.y < q.y;
}

// P* ps 凸包の構築
vector<P> convex_hull(P* ps, int n){
	sort(ps, ps + n, cmp_x);
	int k = 0; // 
	vector<P> qs(n * 2); // 
	
	// 
	for(int i = 0; i < n; i++){
		while(k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0){
			k--;
		}
		qs[k++] = ps[i];
	}
	
	// 
	for(int i = n - 2, t = k; i >= 0; i--){
		while(k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0){
			k--;
		}
		qs[k++] = ps[i];
	}
	qs.resize(k - 1);
	return qs;
}

P ps[110000];

int main(){
	
	int N;
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> ps[i].x >> ps[i].y;
	}
	
	vector<P> qs = convex_hull(ps, N);
	
	cout << qs.size() << endl;
	for(int i = 0; i < qs.size(); i++){
		cout << qs[i].x << " " << qs[i].y << endl;
	}
	
	return 0;
}
