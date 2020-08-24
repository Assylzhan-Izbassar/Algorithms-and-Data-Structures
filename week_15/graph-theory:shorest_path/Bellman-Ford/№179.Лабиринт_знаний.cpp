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

int n,m;
vector<tp> gr;
vi dist;
int const NINF = -10000;
vi loops;

void bellman_ford(int x){
    dist = vi(n, NINF);
    if(loops[x] == 0)
        dist[x] = 0;
    else
        dist[x] = loops[x];

    for(int i=1; i <= n-1; ++i){
        for(auto e : gr){
            int a, b, w;
            tie(a,b,w) = e;
            dist[b] = max(dist[b], dist[a] + w);
        }
    }
}

void test_case(){
    cin >> n >> m;
    loops = vi(n);

    rep(i, 0, m){
        int v, u, w;
        cin >> v >> u >> w;
        --v; --u;
        gr.pb(tie(v,u,w));
        if(v == u){
            loops[v] = w;
        }
    }
    bellman_ford(0);

    if(dist[n-1] != NINF){
        cout << dist[n-1];
    }else if(dist[n-1] == NINF){
        cout << ":(";
    }else{
        cout << ":)";
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

    int t = 1; 
    // cin >> t;
    while(t--)
        test_case();

    return 0;
}