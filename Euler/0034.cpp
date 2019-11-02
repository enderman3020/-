#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int pow(int x){
	if(x <= 1){
		return 1;
	}
	return x * pow(x - 1);
}

int main(){
	
	int ans = 0;
	
	for(int i = 1; i < 5000000; i++){
		int sum = 0;
		int num = i;
		while(true){
			if(num == 0){
				break;
			}
			sum += pow(num % 10);
			num /= 10;
		}
		if(i == sum){
			cout << i << endl;
			ans += i;
		}
	}
	
	ans -= 3;
	cout << ans << endl;
	
	return 0;
}

