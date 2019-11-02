#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;
long long int INF = 1e18;


// �ŏ��S��؂ł���AO(V^2)

// �ŏ��ɂ��ׂĂ̒��_�Ԃ̃R�X�g��z��ɑ�����Ă�������


#define MAX_V 200

long long int cost[MAX_V][MAX_V]; // cost[u][v] �͒��_u����v�ւ̃R�X�g
long long int mincost[MAX_V];
bool used[MAX_V];

long long int prim(int V){
	
	for(int i = 0; i < V; i++){
		mincost[i] = INF;
		used[i] = false;
	}
	
	mincost[0] = 0;
	
	long long int total = 0;
	
	while(true){
		
		int add_v = -1;
		
		for(int u = 0; u < V; u++){
			if(!used[u] && (add_v == -1 || mincost[u] < mincost[add_v])){
				add_v = u;
			}
		} // �ǉ����钸�_������
		
		if(add_v == -1){
			break;
		} // �X�V���钸�_���Ȃ��ꍇ�A�I��
		used[add_v] = true;
		total += mincost[add_v];
		
		for(int u = 0; u < V; u++){
			mincost[u] = min(mincost[u], cost[add_v][u]);
		} // �W���̊O�̒��_�ւ̍ŏ��R�X�g���X�V
	}
	return total;
}

int main(){
	
	long long int ans;
	
	int V = 3;
	
	cost[0][1] = 6;
	cost[1][0] = 6;
	cost[0][2] = 4;
	cost[2][0] = 4;
	cost[1][2] = 5;
	cost[2][1] = 5;
	cost[0][0] = INF;
	cost[1][1] = INF;
	cost[2][2] = INF;
	
	ans = prim(V);
	cout << ans << endl;
	
	return 0;
}