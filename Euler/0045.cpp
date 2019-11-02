#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

long long int tri[1000000];
long long int pen[1000000];
long long int hxa[1000000];

int main(){
	
	for(long long int i = 1; i <= 1000000; i++){
		tri[i - 1] = i * (i + 1) / 2;
		pen[i - 1] = i * (3 * i - 1) / 2;
		hxa[i - 1] = i * (2 * i - 1);
	}
	
	for(int i = 145; i < 1000000; i++){
		int index_tri = distance(tri, lower_bound(tri, tri + 1000000, hxa[i]));
		int index_pen = distance(pen, lower_bound(pen, pen + 1000000, hxa[i]));
		if(hxa[i] == tri[index_tri] && hxa[i] == pen[index_pen]){
			cout << hxa[i] << endl;
			break;
		}
	}
	
	
	return 0;
}

