#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > gr;
vector<bool> used;
vector<int> degrees;


void solve(){
    int n,m;
    cin >> n >> m;

    gr = vector<vector<int> >(n);

    for(int i=0; i < m; ++i){
        int v,u;
        cin >> v >> u;
        v--; u--;
        gr[v].push_back(u);
        gr[u].push_back(v);
    }

    for(int i=0; i < gr.size(); ++i){
        cout << gr[i].size() << " ";
    }
    cout << endl;
}
int main(){

    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}