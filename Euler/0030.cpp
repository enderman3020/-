#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int pow_5(int x){
	return x * x * x * x * x;
}

int main(){
	
	int ans = 0;
	
	for(int num = 2; num < 1000000; num++){
		int hoge1 = num;
		int hoge2 = 0;
		while(true){
			if(hoge1 == 0){
				break;
			}
			hoge2 += pow_5(hoge1 % 10);
			hoge1 /= 10;
		}
		if(num == hoge2){
			cout << num << endl;
			ans += num;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

