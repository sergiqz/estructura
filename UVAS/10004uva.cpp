#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> conecciones;

bool bicolor(int node, int color, vector<int>& colors)
{
    if (colors[node]==-1)
    {
        colors[node]=color;
        for (int i = 0; i < conecciones[node].size(); i++){
            if (!bicolor(conecciones[node][i], 1-color, colors)){
                return false;
            }
        }
    }
    else {
        if (colors[node]!=color){
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    while (cin>>n,n)
    {
        conecciones.assign(n,vector<int>());  
        int l;
        cin>>l;
        while (l--)
        {
            int inicio, fin;
            cin>>inicio>>fin;
            conecciones[inicio].push_back(fin);
            conecciones[fin].push_back(inicio);
        }
        vector<int> color(n,-1);
        if (bicolor(0, 0, color)){
            cout<<"BICOLORABLE."<<endl;
        }
        else{
            cout<<"NOT BICOLORABLE."<<endl;
        }
    }
}