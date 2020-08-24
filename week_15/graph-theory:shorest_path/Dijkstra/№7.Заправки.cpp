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
#define mp make_pair
#define sz(c) (int)((c).size())
#define all(c) c.begin(),c.end()
#define rep(i,a,n) for (int i = a; i < n; i++)
#define fi first
#define se second

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;

void print(vector<int> &a){
    for(int i=0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
    cout << endl;
}

int n, m;
vi cost;
vector<pii> gr[100100];
vi dist;
vb mark;
priority_queue<pii> q;
const int INF = 1e9;

void dijkstra(int x){
    mark = vb(n, false);
    dist = vi(n, INF);
    dist[x] = 0;
    q.push({0, x});

    while(!q.empty()){
        int a = q.top().se; q.pop();
        if(mark[a]) continue;
        mark[a] = true;
        for(auto u : gr[a]){
            int b = u.fi; int w = u.se;
            if(dist[b] > dist[a] + w){
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
            }
        }
    }
}

void test_case(){
    cin >> n;
    cost = vi(n);

    rep(i, 0, n) cin >> cost[i];

    cin >> m;

    rep(i, 0, m){
        int v,u;
        cin >> v >> u;
        --v; --u;
        gr[v].pb(mp(u,cost[v]));
        gr[u].pb(mp(v,cost[u]));
    }
    dijkstra(0);

    if(dist[n-1] == INF){
        cout << -1;
    }else{
        cout << dist[n-1];
    }
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