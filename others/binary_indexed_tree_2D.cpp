#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int BIT[2000][2000];

void add(int a, int b, int w){
	
	// (a, b)”Ô–Ú‚Ì—v‘f‚Éw‚ð‘«‚· O(log N)
	
	for(int x = a; x <= N; x += x & -x){
		for(int y = b; y <= N; y += y & -y){
			BIT[x][y] += w;
		}
	}
}

int sum(int a, int b){
	
	// (1, 1)‚©‚ç(a, b)‚Ü‚Å‚Ì—v‘f‚Ì‡Œv‚ð•Ô‚· O(log N)
	
	int ret = 0;
	for(int x = a; x > 0; x -= x & -x){
		for(int y = b; y > 0; y -= y & -y){
			ret += BIT[x][y];
		}
	}
	return ret;
}

string map[8] = {
	"11100111",
	"11100111",
	"11100111",
	"11100111",
	"11111001",
	"11111001",
	"11111001",
	"11111001"
};

int main(){
	
	N = 8;
	
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			BIT[i][j] = 0;
		}
	}
	
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if(map[i][j] == '1'){
				add(j + 1, i + 1, 1);
			}
		}
	}
	
	int a, b, c, d;
	
	cout << "sum(1, 1), (5, 5) = " << sum(5, 5) << endl;
	
	while(true){
		cin >> a >> b >> c >> d;
		if(a * b * c * d == 0){
			break;
		}
		printf("sum(%d, %d), (%d, %d) = %d\n", a, b, c, d, sum(c, d) + sum(a - 1, b - 1) - sum(a - 1, d) - sum(c, b - 1));
	}
	
	return 0;
}
