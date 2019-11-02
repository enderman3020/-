#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	
	long long int hoge = 0;
	
	for(int i = 1; i <= 100000; i++){
		hoge += i;
		int count = 0;
		for(int j = 1; j <= sqrt(hoge); j++){
			if(hoge % j == 0){
				count++;
			}
		}
		if(count >= 250){
			break;
		}
	}
	
	cout << hoge << endl;
	
	return 0;
}

