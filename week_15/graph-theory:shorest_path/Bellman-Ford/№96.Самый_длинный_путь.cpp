#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int> > gr;
vector<int> dist;
const int INF = 1e9;
int ans = -1;

void bellman_ford(int x){
    dist = vector<int> (n, INF);
    dist[x] = 0;

    for(int i=0; i < n-1; ++i){
        for(int v = 0; v < n; ++v){
            for(int u = 0; u < n; ++u){
                if(gr[v][u] != -1){
                    dist[u] = min(dist[u], dist[v] + gr[v][u]);
                }
            }
        }
    }
}


int main(){

    cin >> n;
    gr = vector<vector<int> >(n, vector<int> (n));

    for(int i=0; i < n; ++i)
        for(int j=0; j < n; ++j)
            cin >> gr[i][j];
        
    for(int x=0; x < n; ++x){
        bellman_ford(x);
        for(int i=0; i < n; ++i){
            if(dist[i] > ans) ans = dist[i];
        }
    }
    cout << ans << endl;

    return 0;
}