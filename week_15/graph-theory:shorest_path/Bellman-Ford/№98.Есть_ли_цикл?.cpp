#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>

using namespace std;

#define pb push_back
#define sz(c) (int)((c).size())
#define all(c) c.begin(),c.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

void print(vi &a){
    for(int i=0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}
void print(vector<ll> &a){
    for(int i=0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}

vector<vi> gr;
vi dist;
int n;
const int INF = 1e9;

bool bellman_ford(int x){
    dist = vi(n, INF);
    dist[x] = 0;

    for(int i=0; i < n-1; ++i){
        for(int v = 0; v < n; ++v){
            for(int u=0; u < n; ++u){
                dist[u] = min(dist[u], dist[v] + gr[v][u]);
            }
        }
    }
    //check for negative cycle
    //this is nth relaxation 
    for(int v = 0; v < n; ++v){
        for(int u=0; u < n; ++u){
            if(dist[u] > dist[v] + gr[v][u]){
                return true;
            }
        }
    }
    return false;
}

void test_case(){
    cin >> n;

    gr = vector<vi>(n, vi(n));

    for(int i=0; i < n; ++i)
        for(int j=0; j < n; ++j)
            cin >> gr[i][j];

    for(int i=0; i < n; ++i){
        for(int j=0; j < n; ++j){
            if(gr[i][j] == 1) gr[i][j] = -1;
            else gr[i][j] = 1e9;
        }
    }

    for(int i=0; i < n; ++i){
        if(bellman_ford(i)){
            cout << 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main(){

    #ifdef _DEBUG
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1; 
    // cin >> t;
    while(t--)
        test_case();

    return 0;
}