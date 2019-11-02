#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int odd[200000];

vector<int> G[200000];

bool search_(int n, int hoge){
	//cout << n << " " << odd[n] << " " << hoge << endl;
	if(odd[n] == hoge){
		return true;
	}else if(odd[n] != -1 && odd[n] != hoge){
		return false;
	}
	odd[n] = hoge;
	bool res = true;
	int hoge2 = (hoge + 1) % 2;
	
	for(int i = 0; i < G[n].size(); i++){
		//cout << n << " " << G[n][i] << " " << hoge2 << endl;
		bool res2 = search_(G[n][i], hoge2);
		res = res && res2;
	}
	
	return res;
}
 
int main(){
	
	long long int N, M;
	cin >> N >> M;
	
	for(int i = 0; i <= N; i++){
		odd[i] = -1;
	}
	
	for(int i = 0; i < M; i++){
		int p1, p2;
		cin >> p1 >> p2;
		G[p1].push_back(p2);
		G[p2].push_back(p1);
	}
	
	bool res = search_(1, 0);
	
	long long int ans;
	
	if(res){
		long long int count1 = 0;
		long long int count2 = 0;
		for(int i = 1; i <= N; i++){
			if(odd[i] == 0){
				count1++;
			}else{
				count2++;
			}
		}
		ans = count1 * count2 - M;
	}else{
		ans = N * (N - 1) / 2 - M;
	}
	
	cout << ans << endl;
	
	return 0;
}
