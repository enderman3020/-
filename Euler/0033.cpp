#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
	
	for(int i = 1; i < 100; i++){
		for(int j = 1; j < 100; j++){
			if(i % 10 == j / 10 && i * (j % 10) == (i / 10) * j){
				cout << i << " " << j << endl;
			}
		}
	}
	
	return 0;
}

