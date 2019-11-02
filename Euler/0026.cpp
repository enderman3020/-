#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int memory[10000];
int digs[10000];

int main(){
	
	int ans = 0;
	int max = 0;
	
	for(int i = 2; i <= 1000; i++){
		int from = 0;
		for(int j = 0; j < 10000; j++){
			memory[j] = 0;
			digs[j] = 0;
		}
		int rest = 1;
		int digit = 1;
		while(true){
			rest *= 10;
			if(rest == 0){
				break;
			}
			if(memory[rest] > 0){
				from = memory[rest];
				break;
			}
			memory[rest] = digit;
			digs[digit] = rest / i;
			rest = rest % i;
			digit++;
		}
		cout << "0.";
		for(int j = 1; j < digit; j++){
			if(j == from){
				cout << "(";
			}
			cout << digs[j];
		}
		
		if(from > 0){
			cout << ")";
		}
		
		cout << endl;
		
		if(max < digit - from){
			max = digit - from;
			ans = i;
		}
		
	}
	
	cout << ans << endl;
	
	return 0;
}

