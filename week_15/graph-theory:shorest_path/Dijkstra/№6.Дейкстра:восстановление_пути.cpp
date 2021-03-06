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
typedef pair<int, int> pii;
typedef tuple<int, int, int> tp;
typedef priority_queue<pii> pqp;


void print(vector<int> &a){
    for(int i=0; i < a.size(); ++i){
        cout << a[i] + 1 << " ";
    }
    cout << endl;
}
int n, s, f;
vector<pii> gr[101101];
vi dist;
vb mark;
pqp q;
vi parent;
const int INF = 1e9;

void dijkstra(int x){
    dist = vi(n, INF);
    dist[x] = 0;
    q.push({0, x});
    parent = vi(n);

    while(!q.empty()){
        int a = q.top().second; q.pop();
        if(mark[a]) continue;
        mark[a] = true;

        for(auto u : gr[a]){
            int b = u.first; int w = u.second;
            if(dist[b] > dist[a] + w){
                dist[b] = dist[a] + w;
                q.push({-dist[b], b});
                parent[b] = a; 
            }
        }
    }
}

void test_case(){
    cin >> n >> s >> f;

    mark = vb(n, false);

    for(int i=0; i < n; ++i){
        for(int j=0; j < n; ++j){
            int w;
            cin >> w;
            if(w != -1){
                gr[i].pb({j, w});
            }
        }
    }
    --s; --f;
    dijkstra(s);

    if(dist[f] == INF){
        cout << -1 << endl;
        return;
    }
    
    vi path;
    for(int v = f; v != s; v = parent[v]){
        path.pb(v);
    }
    path.pb(s);
    reverse(all(path));

    print(path);
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