#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

// キーを参照して二分探索が可能なリスト

int main(){
	
	map<int, string> m;
	
	m.insert(make_pair(1, "ONE"));
	m[10] = "TEN";
	m[100] = "HUNDRED";
	
	for(int key = 1; key <= 1000; key *= 10){
		if(m.find(key) != m.end()){
			cout << m[key] << endl;
		}else{
			printf("not found\n");
		}
	}
	
	map<int, string>::iterator ite;
	
	for(ite = m.begin(); ite != m.end(); ite++){
		printf("%d: %s\n", ite -> first, ite -> second);
	}
	
	return 0;
}
