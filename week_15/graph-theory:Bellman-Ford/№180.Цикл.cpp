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

void print(vector<int> &a){
    for(int i=0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}

int n;
vector<vi> gr;
vi dist;
const int INF = 100000;

void bellman_ford(int x){
    dist = vi(n, INF);
    dist[x] = 0;

    vi p(n, -1);
    int s = -1;

    for(int i=0; i < n; ++i){
        for(int v=0; v < n; ++v){
            for(int u=0; u < n; ++u){
                if(dist[v] < INF){
                    if(dist[u] > dist[v] + gr[v][u]){
                        dist[u] = max(-INF, dist[v] + gr[v][u]);
                        p[u] = v;
                        s = u; 
                    }
                }
            }
        }
    }

    if(s == -1){
        cout << "NO\n";
    }else{
        int y = s;
        for(int i=0; i < n; ++i){
            y = p[y];
        }
        vi path;
        for(int cur = y; ; cur = p[cur]){
            path.pb(cur);
            if(cur == y && path.size() > 1) break;
        }
        reverse(all(path));
        cout << "YES\n";
        print(path);
    }

}

void test_case(){

    cin >> n;

    gr = vector<vi> (n, vi(n));

    for(int i=0; i < n; ++i)
        for(int j=0; j < n; ++j)
            cin >> gr[i][j];
    bellman_ford(0);
}

int main(){

    #ifdef _DEBUG
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test_case();

    return 0;
}