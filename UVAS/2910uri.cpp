#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<iii> vii;
#define INF 1000000000
priority_queue<ii, vector<ii>, greater<ii> > resultamin;
vector<vii> AdjList;

void Dijkstra(int V,int s){
	int total=0;
	int total2=0;
	vi dist2(V, INF);
	vi dist(V, INF); 
	dist[s] = 0;
	dist2[s] = 0;                    
  	priority_queue< iii, vector<iii>, greater<iii> > pq; 
  	pq.push(iii(0,ii(s,0)));
                  
  	while (!pq.empty()){                                            
    	iii front = pq.top(); 
    	pq.pop();     
    	int d = front.first, u = front.second.first;
    	if (d > dist[u]) continue;   
    	for (int j = 0; j < (int)AdjList[u].size(); j++) {
      		iii v = AdjList[u][j];                       
      		if (dist[u] + v.second.first < dist[v.first]) {
        		dist[v.first] = dist[u] + v.second.first;
        		dist2[v.first] = dist2[u] + v.second.second;                 
        		pq.push(iii(dist[v.first],ii(v.first,v.second.first)));
  			} 
  		} 
  	}  

  	for (int i = 0; i < V; i++){ 
    	total=total+dist2[i];
    	total2=total2+dist[i];
  	}
  	resultamin.push(make_pair(total2, total));
}

int main() {

  	int V, E, s, u, v, w, w2;

  	scanf("%d %d", &V, &E);

  	AdjList.assign(V, vii()); 
  	for (int i = 0; i < E; i++) {
    	scanf("%d %d %d %d", &u, &v, &w, &w2);
    	AdjList[u-1].push_back(iii(v-1,ii(w,w2)));                              
  	}

  	for (int i = 0; i < V; ++i){
  		Dijkstra(V,i);
  	}

  	pair<int, int> topM = resultamin.top(); 
  	cout<<topM.second;

  	return 0;
}