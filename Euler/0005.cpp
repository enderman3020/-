#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long int LCM(long long int a, long long int b){
	long long int dummy1, dummy2, dummy;
	dummy1 = max(a, b);
	dummy2 = min(a, b);
	while(true){
		dummy = dummy1 % dummy2;
		dummy1 = dummy2;
		dummy2 = dummy;
		if(dummy == 0){
			break;
		}
	}
	return (a / dummy1) * (b / dummy1) * dummy1;
}

int main(){
	
	long long int ans = 1;
	
	for(int i = 1; i <= 20; i++){
		ans = LCM(i, ans);
	}
	
	cout << ans << endl;
	
	return 0;
}

