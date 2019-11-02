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

int main(){
	
	int ans = 0;
	
	for(int i = 0; i < 1000; i++){
		for(int j = 0; j < 1000; j++){
			string hoge = str_int(i * j);
			bool check = true;
			for(int k = 0; k < hoge.size(); k++){
				if(hoge[k] != hoge[hoge.size() - k - 1]){
					check = false;
					break;
				}
			}
			if(check && ans < i * j){
				ans = i * j;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

