#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int BIT_SIZE = 550000; // 必要な数よりも大きい2^nよりも大きい数を入れるとよい
long long int BIT[BIT_SIZE + 1];

void init(){
	for(int i = 0; i <= BIT_SIZE; i++){
		BIT[i] = 0;
	}
}

void add(int a, long long int w){
	
	// a番目の要素にwを足す O(log N)
	
	for(int x = a; x <= BIT_SIZE; x += x & -x){
		BIT[x] += w;
	}
}

long long int sum(int a){
	
	// 1からaまでの要素の合計を返す O(log N)
	
	long long int ret = 0;
	for(int x = a; x > 0; x -= x & -x){
		ret += BIT[x];
	}
	return ret;
}

// バブルソートの交換回数、ind[i] が交換後のインデックス
long long int solve(int n, int A[]){
	long long int ans = 0;
	for(int i = 0; i < n; i++){
		ans += i - sum(A[i]);
		add(A[i], 1);
	}
	return ans;
}

// BIT が単調増加（元の配列の各要素が非負）であるときに使える
int lowerBound(int w){
	if(w <= 0){
		return 0;
	}
	int x = 0;
	for (int k = 128; k > 0; k /= 2) { // k の初期値は N 以下の最大の 2 ベキとするとよい（少し大きくてもよい）
		if (x + k <= N && bit[x + k] < w) {
			w -= bit[x + k];
			x += k;
		}
	}
	return x + 1;
}

int main(){
	
	N = 200;
	
	init();
	
	for(int i = 1; i < 150; i++){
		add(i, i);
	}
	
	printf("sum(1 to 10) = %d\n", sum(10));
	printf("sum(1 to 100) = %d\n", sum(100));
	printf("sum(20 to 40) = %d\n", sum(40) - sum(19));
	
	return 0;
}
