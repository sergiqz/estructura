#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int set[500];

struct cord 
{
	int x, y;
	double peso;
};

struct edge
{
	int a, b;
};

vector <edge> grafo;
vector <cord> edge;

int find(int x)
{
    if (set[x] == x){
        return x;
    }
    return set[x] = find(set[x]);
}

bool join(const cord & ed, vector<float> & pesoEDGE)
{
    int a = find(ed.x);
    int b = find(ed.y);
    if (a == b) {
        return false;
    }
    set[a] = b;
    pesoEDGE.push_back(ed.peso);
    return true;
}

bool _sort(cord u, cord v){
    return u.peso < v.peso;
}

int main(){
	int n,s,p,x,y;
	cin>>n;
	while(n--){
		cin>>s>>p;
		for(int i=0;i<p;i++){
			cin>>x>>y;
			grafo.push_back({x, y});
			set[i] = i;
		}
        for (int i=0; i<p; i++){
            for (int j=i+1; j<p; j++){
                double dist = sqrt(pow(grafo[i].a-grafo[j].a,2) + pow(grafo[i].b-grafo[j].b,2));
                edge.push_back({i, j, dist});
            }
        }		
  		sort(edge.begin(), edge.end(), _sort);
        vector<float> pesoE;
        for (int i=0, nE=0; nE!=p-1; i++){
            if (join(edge[i],pesoE)){
            	nE++;
            }
        }
        printf("%.2f\n",pesoE[p-s-1]);
        edge.clear();
        grafo.clear();
	}
	return 0;
}