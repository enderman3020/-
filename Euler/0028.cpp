#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	
	long long int ans = 1;
	long long int cur = 1;
	for(int loop = 1; loop <= 500; loop++){
		for(int i = 0; i < 4; i++){
			cur += loop * 2;
			ans += cur;
		}
	}
	
	cout << ans << endl;
	
	ans = 1;
	
	for(int loop = 1; loop <= 500; loop++){
		ans += ((loop * 2 + 1) * (loop * 2 + 1) - 3 * loop) * 4;
	}
	
	cout << ans << endl;
	
	return 0;
}

