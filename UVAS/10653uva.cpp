#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;

int grafo[1001][1001];
int visited[1001][1001];
int level[1001][1001];
int R,C;
int X[]={-1,0,0,1};
int Y[]={0,-1,1,0};

void bfs(int x,int y)
{   
    int ux,uy,vx,vy;
    queue<int>q;
    q.push(x);
    q.push(y);
    visited[x][y] = 1;
    level[x][y]=0;
    while(!q.empty()){
        ux=q.front();
        q.pop();
        uy=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            vx = ux+X[i];
            vy = uy+Y[i];
            if((vx>=0 and vx<=R) and (vy>=0 and vy<=C) and grafo[vx][vy]==0){
                if(!visited[vx][vy] and !level[vx][vy]){
                    visited[vx][vy]=1;
                    level[vx][vy]=level[ux][uy]+1;
                    q.push(vx);
                    q.push(vy);
                }
            }
        }
    }
}

int main()
{
    int row,r,numBom,b,inicio,inicio_,destino,destino_;
    while(cin>>R>>C and (R!=0 and C!=0)){
        memset(visited,0,sizeof(visited));
        memset(level,0,sizeof(level));
        memset(grafo,0,sizeof(grafo));
        cin>>row;
        for(int i=0;i<row;i++){
            cin>>r>>numBom;
            for(int j=0;j<numBom;j++){
                cin>>b;
                grafo[r][b]=1;
            }
        }
        cin>>inicio>>inicio_;
        bfs(inicio,inicio_);
        cin>>destino>>destino_;
        cout<<level[destino][destino_]<<endl;
    }
    return 0;
}