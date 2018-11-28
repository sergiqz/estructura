#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef pair< int, int > pii;

const int MAX = 20010;
const int INF = 0x3f3f3f3f;

vector< pii > G[MAX];
int d[MAX];

void dijkstra(int inicio){
    int u, v, i, c, w;
    priority_queue< pii, vector< pii >, greater< pii > > Q;
    memset(d, INF, sizeof d);
    Q.push(pii(0, inicio));
    d[inicio] = 0;

    while(!Q.empty()) {
        u = Q.top().second; 
        c = Q.top().first; 
        Q.pop(); 
        if(d[u] < c) continue;
        for(i = 0; i < G[u].size(); i++) {
            v = G[u][i].first; 
            w = G[u][i].second; 
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                Q.push(pii(d[v], v));
            }
        }
    }
}

int main() {
    int test, n, e, i, u, v, w, inicio, dist, Case = 0;
    cin>>test;
    while(test--) {
        cin>>n>>e>>inicio>>dist;
        for(i = 0; i < e; i++){
            cin>>u>>v>>w;
            G[u].push_back(pii(v, w));
            G[v].push_back(pii(u, w));
        }

        dijkstra(inicio);

        if(d[dist] == INF){ 
            cout<<"Case #"<<++Case<<": unreachable"<<endl;
        }
        else{
            cout<<"Case #"<<++Case<<": "<<d[dist]<<endl;
        };

        for(i = 0; i <= n; i++){
            G[i].clear();
        }
    }
    return 0;
}