#include<bits/stdc++.h>
using namespace std;

class graph{
public:
    unordered_map<int,list<int> >adj;

    void addEdges(int u,int v, bool directed){
        adj[u].push_back(v);
        if(directed == 0){
            adj[v].push_back(u);
        }
    }

    void printAdj(){
        for(auto i:adj){
            cout << i.first << " -> ";
            for(auto j:i.second){
                cout << j << ",";
            }
            cout << endl;
        }
    }
};

int main(){
    graph g;
    int n,m;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> m;

    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        g.addEdges(u,v,0);
    }
    g.printAdj();
}