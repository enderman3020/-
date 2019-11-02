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

typedef pair<long long int, long long int> P;

int N = 210000 - 1; // 必要な数よりも大きい2^nよりも大きい数を入れるとよい
long long int B1[210000], B2[210000];

void add(int a, long long int w, long long int BIT[]){
	
	// a番目の要素にwを足す O(log N)
	
	for(int x = a; x <= N; x += x & -x){
		BIT[x] += w;
	}
}

long long int sum(int a, long long int BIT[]){
	
	// 1からaまでの要素の合計を返す O(log N)
	
	long long int ret = 0;
	for(int x = a; x > 0; x -= x & -x){
		ret += BIT[x];
	}
	return ret;
}

void init(long long int BIT[]){
	for(int i = 0; i < N; i++){
		BIT[i] = 0;
	}
}

int main(){
	
	int n, q;
	cin >> n >> q;
	
	init(B1);
	init(B2);
	
	for(int i = 0; i < q; i++){
		long long int num, a, b, c;
		cin >> num;
		if(num == 0){
			cin >> a >> b >> c;
			add(a, c, B1);
			add(b + 1, -c, B1);
			add(a, -(a - 1) * c, B2);
			add(b + 1, b * c, B2);
			/*
			for(int j = 1; j <= n; j++){
				cout << sum(j, B1) << " ";
			}
			cout << endl;
			for(int j = 1; j <= n; j++){
				cout << sum(j, B2) << " ";
			}
			cout << endl;
			*/
			for(int j = 0; j < n; j++){
				long long int num1 = sum(j, B1) * j + sum(j, B2);
				long long int num2 = sum(j + 1, B1) * (j + 1) + sum(j + 1, B2);
				cout << num2 - num1 << " ";
			}
			cout << endl;
			
		}else{
			cin >> a >> b;
			a--;
			long long int num1 = sum(a, B1) * a + sum(a, B2);
			long long int num2 = sum(b, B1) * b + sum(b, B2);
			cout << num2 - num1 << endl;
		}
	}
	
	return 0;
}