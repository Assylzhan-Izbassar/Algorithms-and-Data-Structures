#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > gr;
vector<int> dist;
const int INF = 1e9;

void bellman_ford(int x){
    int n = gr.size(); 
    dist = vector<int> (n, INF);
    dist[x] = 0;

    for(int i=1; i <= n-1; ++i){
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

    int n, s, t;
    cin >> n >> s >> t;

    gr = vector<vector<int> > (n, vector<int> (n));

    for(int i=0; i < n; ++i){
        for(int j=0; j < n; ++j){
            cin >> gr[i][j];
        }
    }
    --s, --t;
    bellman_ford(s);

    int ans = dist[t];

    if(ans == 1e9){
        cout << -1;
    }else{
        cout << ans; 
    }
    cout << endl;

    return 0;
}