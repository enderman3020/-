#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	
	bool a[10];
	
	for(int i = 5000; i < 10000; i++){
		for(int j = 0; j < 10; j++){
			a[j] = false;
		}
		int num = i;
		for(int k = 0; k < 4; k++){
			a[num % 10] = true;
			num /= 10;
		}
		num = i * 2;
		for(int k = 0; k < 5; k++){
			a[num % 10] = true;
			num /= 10;
		}
		bool flag = true;
		for(int j = 1; j < 10; j++){
			flag = flag && a[j];
		}
		if(flag){
			cout << i << endl;
		}
	}
	
	return 0;
}

