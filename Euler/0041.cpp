#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool a[10000000];

int main(){
	
	int N = 10000000;
	
	for(int i = 0; i < N; i++){
		a[i] = true;
	}
	
	a[0] = false;
	a[1] = false;
	
	for(int i = 2; i < N; i++){
		if(a[i]){
			for(int j = i * 2; j < N; j += i){
				a[j] = false;
			}
		}
	}
	
	int ans = 0;
	int b[7] = {1, 2, 3, 4, 5, 6, 7};
	
	do{
		int num = 0;
		for(int i = 0; i < 7; i++){
			num *= 10;
			num += b[i];
		}
		if(a[num]){
			ans = num;
		}
	}while(next_permutation(b, b + 7));
	
	cout << ans << endl;
	
	return 0;
}

