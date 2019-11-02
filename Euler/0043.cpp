#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int main(){
	
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int primes[8] = {0, 2, 3, 5, 7, 11, 13, 17};
	
	long long int ans = 0;
	
	do{
		bool flag = true;
		for(int i = 1; i <= 7; i++){
			int num = 0;
			for(int j = i; j <= i + 2; j++){
				num *= 10;
				num += a[j];
			}
			if(num % primes[i] != 0){
				flag = false;
			}
		}
		if(flag){
			long long int piyo = 0;
			for(int i = 0; i < 10; i++){
				piyo *= 10;
				piyo += a[i];
				cout << a[i];
			}
			ans += piyo;
			cout << endl;
		}
	}while(next_permutation(a, a + 10));
	
	cout << ans << endl;
	
	return 0;
}

