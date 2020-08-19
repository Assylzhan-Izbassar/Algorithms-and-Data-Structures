#include <iostream>
#include <vector>

using namespace std;

long long n;
vector<vector<int> > gr;
vector<long long> dist;
const int INF = 1e9;
int ans = 1e9;

bool bellman_ford(int x){
    dist = vector<long long> (n, INF);
    dist[x] = 0;

    for(int i=0; i < n-1; ++i){
        for(int v = 0; v < n; ++v){
            for(int u = 0; u < n; ++u){
                dist[u] = min(dist[u], dist[v] + gr[v][u]);
            }
        }
    }
    //check for negative cycle
    for(int v = 0; v < n; ++v){
        for(int u = 0; u < n; ++u){
            if(dist[u] > dist[v] + gr[v][u])
                return false;
        }
    }
    return true;
}

int main(){

    cin >> n;
    gr = vector<vector<int> > (n, vector<int> (n));

    for(int i=0; i < n; ++i) 
        for(int j=0; j < n; ++j) 
            cin >> gr[i][j];

    bool isExist = true;

    for(int x=0; x < n; ++x){
        if(!bellman_ford(x)){
            isExist = false;
            break;
        }
        for(int i=0; i < n; ++i){
            if(ans > dist[i] && i != x) ans = dist[i];
        }
    }
    if(isExist)
        cout << ans;
    else
        cout << -1;

    cout << "\n";
    
    return 0;
}