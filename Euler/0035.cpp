#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

string str_int(long long int num){
	string str = "";
	bool minus = false;
	if(num < 0){
		minus = true;
		num = -num;
	}else if(num == 0){
		str = "0";
		return str;
	}
	while(true){
		if(num == 0){
			break;
		}
		string d = "D";
		d[0] = '0' + (num % 10);
		str = d + str;
		num /= 10;
	}
	if(minus){
		str = "-" + str;
	}
	return str;
}

long long int int_str(string str){
	long long int num = 0;
	bool minus = false;
	if(str[0] == '-'){
		str = str.substr(1);
		minus = true;
	}
	for(int i = 0; i < str.size(); i++){
		num *= 10;
		num += (str[i] - '0');
	}
	if(minus){
		num = -num;
	}
	return num;
}

bool a[1000000];

int main(){
	
	int N = 1000000;
	
	for(int i = 0; i < N; i++){
		a[i] = true;
	}
	
	a[0] = false;
	a[1] = false;
	
	for(int i = 2; i < N; i++){
		if(a[i]){
			for(int j = i * 2; j < N; j += i){
				a[j] = false;
			}
		}
	}
	
	int ans = 0;
	
	for(int i = 1; i < N; i++){
		int num = i;
		int count = 0;
		if(!a[num]){
			continue;
		}
		for(int j = 0; j < 8; j++){
			int fin = num % 10;
			num /= 10;
			num = int_str(str_int(fin) + str_int(num));
			if(a[num]){
				count++;
			}
		}
		if(count == 8){
			ans++;
			cout << i << endl;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

