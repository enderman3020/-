#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

// “ñ•ª’Tõ‚ª‰Â”\‚ÈƒŠƒXƒg

int main(){
	
	set<int> s;
	
	s.insert(1);
	s.insert(3);
	s.insert(5);
	
	set<int>::iterator ite;
	
	for(ite = s.begin(); ite != s.end(); ite++){
		printf("%d\n", ite);
	}
	
	ite = s.find(1);
	if(ite == s.end()){
		printf("not found\n");
	}else{
		printf("found\n");
	}
	
	ite = s.find(2);
	if(ite == s.end()){
		printf("not found\n");
	}else{
		printf("found\n");
	}
	
	s.erase(3);
	
	if(s.count(3)){
		printf("found\n");
	}else{
		printf("not found\n");
	}
	
	return 0;
}
