#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int div_sum[20000];

int main(){
	
	for(int i = 0; i < 20000; i++){
		div_sum[i] = 0;
	}
	
	for(int i = 1; i <= 10000; i++){
		for(int j = 1; j <= sqrt(i); j++){
			if(i % j == 0){
				if(j * j == i){
					div_sum[i] += j;
				}else{
					div_sum[i] += j;
					div_sum[i] += i / j;
				}
			}
		}
		div_sum[i] -= i;
	}
	
	int ans = 0;
	
	for(int i = 1; i <= 10000; i++){
		int ref = div_sum[i];
		if(ref > 10000){
			continue;
		}
		if(i == div_sum[ref] && i < ref){
			cout << i << " " << ref << endl;
			ans += (i + ref);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

