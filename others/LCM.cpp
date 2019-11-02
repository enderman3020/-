#include <iostream>
#include <cstdio>
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

long long int GCD(long long int a, long long int b){
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
	return dummy1;
}

// 方程式 ax + by = gcd(a, b) の整数解 x, y を求める
// a, b の最大公約数を返す
// 解のうち、最も abs(x) + abs(y) が小さいものが出力される
long long int extGCD(long long int a, long long int b, long long int &x, long long int &y){
	long long int d = a;
	if(b == 0){
		x = 1;
		y = 0;
	}else{
		d = extGCD(b, a % b, y, x);
		y -= a / b * x;
	}
	return d;
}

int main(){
	
	return 0;
}

