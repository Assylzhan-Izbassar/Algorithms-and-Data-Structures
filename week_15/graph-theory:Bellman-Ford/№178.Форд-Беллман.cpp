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
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;

int n, m;
vector<tp> edges;
vi dist;
const int INF = 30000;

void bellman_ford(int x){
    dist = vi(n, INF);
    dist[x] = 0;

    for(int i=0; i < n-1; ++i){
        for(auto e : edges){
            int v, u, w;
            tie(v,u,w) = e;
            dist[u] = min(dist[u], dist[v] + w);
        }
    }
}

void test_case(){

    cin >> n >> m;

    for(int i=0; i < m; ++i){
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y;
        w = abs(w);
        edges.pb({x,y,w});
    }
    bellman_ford(0);

    for(int i=0; i < n; ++i)
        cout << dist[i] << " ";
    cout << endl;
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