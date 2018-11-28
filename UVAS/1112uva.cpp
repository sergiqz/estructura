#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define vi vector<long long>
#define ii pair<long long, long long>
#define vii vector<ii>
#define INF 100000000000

long long T, N, M, E, D, TLE, W, X, Y;
vii V[10000];
long long dist[10000];

void dijkstra(int D){
	priority_queue<ii, vector<ii>, greater<ii> >pq;
	pq.push(ii(0, D));
	dist[D] = 0;
	while(!pq.empty()){
		ii head = pq.top();
		pq.pop();
		long long u = head.second;
		long long d = head.first;
		if(d > dist[u])
			continue;
		for(long long i = 0; i < V[u].size(); i++){
			long long v  = V[u][i].first;
			if(dist[u] + V[u][i].second  < dist[v]){
				dist[v]  = dist[u] + V[u][i].second;
				pq.push(ii(dist[v], v));
			}
		}
	}
}

int main(){
	cin >> T;
	while(T--){
		cin>>N>>D>>TLE>>M;
		for(long long i = 1; i <= N + 3; i++){
			dist[i] = INF; 
			V[i].clear();
		}
		for(long long i = 0; i < M ; i ++){
			cin>>X>>Y>>W;
			V[Y].push_back(ii(X, W));
		}
		dijkstra(D);
		long long ans = 0;
		for(long long i = 1; i <= N; i++){
			if(dist[i]<=TLE){
				ans++;
			}
		}
		cout<<ans;	
    }
	return 0;
}