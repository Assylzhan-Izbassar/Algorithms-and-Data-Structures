#include <iostream>
#include <vector>

using namespace std;

long long n;
vector<vector<int> > gr;
vector<long long> dist;
const int INF = 1e9;
int ans = 1e9;

void bellman_ford(int x){
    dist = vector<long long> (n, INF);
    dist[x] = 0;

    for(int i=0; i < n-1; ++i){
        for(int v = 0; v < n; ++v){
            for(int u = 0; u < n; ++u){
                dist[u] = min(dist[u], dist[v] + gr[v][u]);
            }
        }
    }
}

int main(){

    cin >> n;
    gr = vector<vector<int> > (n, vector<int> (n));

    for(int i=0; i < n; ++i) 
        for(int j=0; j < n; ++j) 
            cin >> gr[i][j];

    for(int x=0; x < n; ++x){
        bellman_ford(x);
        long long sum = 0;

        for(int i=0; i < n; ++i)
            sum += dist[i];
        if(sum < 0){
            cout << -1 << endl;
            return 0;
        }else{
            for(int i=0; i < n; ++i){
                if(ans > dist[i] && i != x) ans = dist[i];
            }
        }    
    }
    cout << ans << endl;

    return 0;
}