#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N;

long long int A[100001];

bool check(long long int min_A){
	return false;
}

long long int bin_search(long long int lef, long long int rig){
	long long int middle = (lef + rig) / 2;
	//cout << middle << " ";
	if(rig - lef <= 1){
		if(check(rig)){
			return rig;
		}else{
			return lef;
		}
	}
	if(check(middle)){
		lef = middle;
	}else{
		rig = middle;
	}
	return bin_search(lef, rig);
}

int main(){
	
	cin >> N;
	
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	long long int rig_max = 100000000000000;
	
	long long int ans = bin_search(0, rig_max);
	
	cout << ans << endl;
	
	return 0;
}
