#include<iostream>
using namespace std;

struct edge {
    int a;   // 起點
    int b;   // 終點
    int v;   // 權重
};

int n,m;//n 星系（節點）的數量。m 蟲洞（邊）的數量。

edge E[2005];  // 記錄所有邊
long long dis[1005]; // 記錄從起點到各點的最短路徑

bool Bellman(){
	dis[0] = 0;
	for (int i=1;i<n;i++)
		dis[i]=1000000000000000LL;// 10^15

	// 雙重迴圈，每次更新所有邊
	for (int i=0;i<n-1;i++){//如果一個徒沒有負環，最多只需要n-1次鬆弛操作就可以得到最短路徑
		for (int i=0;i<m;i++){
			//進行鬆弛操作
			if (dis[E[i].a]>dis[E[i].b]+E[i].v)//dis[E[i].a]表示從起點到點a的最短路徑
				dis[E[i].a]=dis[E[i].b]+E[i].v;
		}
	}
	//跑完n-1次後，再跑一次，如果還有更新，表示有負環
	bool negcyc = 0;
	// 檢查是否有負環
	for (int i=0;i<m;i++){
		// 如果dis[E[i].a]可以一直減小
		if (dis[E[i].a]>dis[E[i].b]+E[i].v){
			negcyc=1;
			break;
		}
	}
	return !negcyc;
	
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t,a,b,vv;// t:測資數, a,b:點, vv:邊的權重
	cin>>t;
	while (t--){
		cin>>n>>m;
		for (int i=0;i<m;i++){
			cin>>a>>b>>vv;
			E[i].a=a, E[i].b = b, E[i].v = vv;
		}
		if (Bellman()) cout<<"not possible\n";
		else cout<<"possible\n";
		
	}
}