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

size_t n, m, k, s, f;
vector<tp> edges;
vi dist;
vi parent;
vi path;
const int INF = 1e9;

void ford_bellman(int x){
    dist = vi(n, INF);
    dist[x] = 0;

    parent = vi(n, -1);

    for(int i=0; i < k; ++i){
        for(auto e : edges){
            int a, b, p;
            tie(a,b,p) = e;
            if(dist[b] > dist[a] + p){
                dist[b] = dist[a] + p;
                parent[b] = a;
            }
        }
    }
    for(int i=f; i != -1; i=parent[i])
        path.pb(i);
}

void test_case(){
    cin >> n >> m >> k >> s >> f;

    rep(i, 0, m){
        int x,y,p;
        cin >> x >> y >> p;
        --x, --y;
        edges.pb({x,y,p});
    }
    --s;--f;
    ford_bellman(s);

    while(path.size()-1 > k){
        path.clear();
        rep(i,0,m){
            int a, b, w;
            tie(a,b,w) = edges[i];
            if(a == path[0] && b == path[1]){
                edges[i] = {a,b,INF};
            }
        }
        ford_bellman(s);
    }

    if(dist[f] != INF){
        cout << dist[f] << endl;
    }else{
        cout << -1 << endl;
    } 
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