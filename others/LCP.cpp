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

const int MAX_N = 200000;

int n, k;
int rnk[MAX_N];
int tmp[MAX_N];

// sa[i] : 接尾辞を全て列挙した際、辞書順でｉ番目の文字列は sa[i] 文字目 (0-indexed) から始まる文字列となる

// (rank[i], rank[i + k]) と (rank[j], rank[j + k]) を比較
bool compare_sa(int i, int j){
	if(rnk[i] != rnk[j]){
		return rnk[i] < rnk[j];
	}
	int ri = -1, rj = -1;
	if(i + k <= n){
		ri = rnk[i + k];
	}
	if(j + k <= n){
		rj = rnk[j + k];
	}
	return ri < rj;
}

void construct_sa(string S, long long int *sa){
	n = S.length();

	// rank を文字コードで初期化
	for(int i = 0; i <= n; i++){
		sa[i] = i;
		rnk[i] = i < n ? S[i] : -1;
	}

	// ｋ文字でソートされているところから、２ｋ文字でソートする
	for(k = 1; k <= n; k *= 2){
		sort(sa, sa + n + 1, compare_sa);

		// いったん tmp に次のランクを計算し、それから rank に移す
		tmp[sa[0]] = 0;
		for(int i = 1; i <= n; i++){
			tmp[sa[i]] = tmp[sa[i - 1]] + compare_sa(sa[i - 1], sa[i]);
		}
		for(int i = 0; i <= n; i++){
			rnk[i] = tmp[i];
		}
	}
}

void construct_lcp(string S, long long int *sa, long long int *lcp){
	n = S.length();
	for(int i = 0; i <= n; i++){
		rnk[sa[i]] = i;
	}

	int h = 0;
	lcp[0] = 0;
	for(int i = 0; i < n; i++){
		// 文字列中での位置ｉでの接尾辞と、接尾辞配列中でその１つ前の接尾辞の LCP を求める
		int j = sa[rnk[i] - 1];

		// ｈを先頭の分１減らし、後ろが一致しているだけ増やす
		if(h > 0){
			h--;
		}
		for(; j + h < n && i + h < n; h++){
			if(S[j + h] != S[i + h]){
				break;
			}
		}
		lcp[rnk[i] - 1] = h;
	}
}

long long int SA[110000], LCP[110000];

int main(){
	int N;
	cin >> N;
	string S;
	cin >> S;
	construct_sa(S, SA);
	construct_lcp(S, SA, LCP);
	
	for(int i = 0; i <= S.size(); i++){
		cout << SA[i] << " ";
	}cout << endl;
	for(int i = 0; i <= S.size(); i++){
		cout << LCP[i] << " ";
	}cout << endl;
	
	return 0;
}