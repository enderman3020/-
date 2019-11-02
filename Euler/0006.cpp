#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	
	long long int ans = 5050 * 5050;
	
	for(int i = 1; i <= 100; i++){
		ans -= i * i;
	}
	
	cout << ans << endl;
	
	return 0;
}

