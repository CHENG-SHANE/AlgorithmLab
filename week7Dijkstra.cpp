#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
const int INF = numeric_limits<int>::max();

void Dijkstra(int s, const vector<vector<pair<int, int>>>& adj, vector<int>& latency) {
    fill(latency.begin(), latency.end(), INF);
    latency[s] = 0;
    //<(距離,節點),使用的容器,將其設定為最小堆> 尚未處理的節點U
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //將起點加入到V'中(已經處理過的節點)
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        // 取得佇列中延遲最小的元素
        pair<int, int> p = pq.top(); //我們用的是最小堆，所以top是最小的
        pq.pop();
        int time = p.first;// 取得當前節點的延遲
        int u = p.second;// 取得當前節點的編號
        // 如果當前時間大於已知的最小延遲，則跳過
        if (time > latency[u]) continue;

        // 遍歷所有與u相鄰的節點
        for (size_t i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i].first; // 相鄰節點的編號
            int weight = adj[u][i].second; // 邊的權重
            // 如果經過u到v的路徑比已知的v的最短路徑更短，則更新
            if (latency[v] > latency[u] + weight) {
                latency[v] = latency[u] + weight;
                pq.push(make_pair(latency[v], v)); // 將更新後的節點加入佇列
            }
        }
    }
}

int main() {
    int tc;
    cin >> tc; // 讀取測試案例數量

    for (int k = 1; k <= tc; ++k) {
        int n, m, s, t;
        cin >> n >> m >> s >> t; // 讀取節點數、邊數、起點和終點

        vector<vector<pair<int, int>>> adj(n); // 鄰接表
        for (int i = 0; i < m; ++i) {
            int x, y, l;//兩端點,權重
            cin >> x >> y >> l;
            adj[x].push_back(make_pair(y, l)); // x可以到y
            adj[y].push_back(make_pair(x, l)); // y可以到x
        }

        vector<int> latency(n); // 存儲最短路徑
        Dijkstra(s, adj, latency);

        cout << "Case #" << k << ": ";
        // 如果終點的最短路徑不是無限大，
        if (latency[t] != INF) {
            cout << latency[t] << endl;}
        else {
            cout << "unreachable" << endl;
        }
    }

    return 0;
}
