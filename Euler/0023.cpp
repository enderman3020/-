#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool excess[100000];

int main(){
	
	for(int i = 0; i < 100000; i++){
		excess[i] = false;
	}
	
	for(int i = 1; i <= 30000; i++){
		int sum = 0;
		for(int j = 1; j <= sqrt(i); j++){
			if(i % j == 0){
				if(j * j == i){
					sum += j;
				}else{
					sum += j;
					sum += i / j;
				}
			}
		}
		sum -= i;
		if(sum > i){
			excess[i] = true;
		}
	}
	
	int ans = 0;
	
	for(int i = 1; i <= 30000; i++){
		bool flag = true;
		for(int j = 1; j <= i / 2; j++){
			if(excess[j] && excess[i - j]){
				flag = false;
				break;
			}
		}
		if(flag){
			ans += i;
			//cout << i << endl;
		}
	}
	
	cout << ans << endl;
	int i = 28035;
	int sum = 0;
	for(int j = 1; j <= sqrt(i); j++){
		if(i % j == 0){
			if(j * j == i){
				cout << j << endl;
				sum += j;
			}else{
				cout << j << " " << i / j << endl;
				sum += j;
				sum += i / j;
			}
		}
	}
	cout << sum - i << endl;
	return 0;
}

