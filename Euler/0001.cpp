#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	
	int fib[1000];
	
	for(int i = 0; i < 1000; i++){
		fib[i] = 0;
	}
	
	fib[0] = 1;
	fib[1] = 2;
	
	int ans = 1;
	
	for(int i = 2; i < 1000; i++){
		fib[i] = fib[i - 1] + fib[i - 2];
		if(fib[i] > 4000000){
			break;
		}
		if(fib[i] % 2 == 0){
			ans += fib[i];
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

