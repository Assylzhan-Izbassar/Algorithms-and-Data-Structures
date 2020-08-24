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
    cout << a.size() << endl;
    for(size_t i=0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
}

size_t n;
vector<tp> gr;
vi dist;
const int INF = 100000;
vi parent;
int s = -1;

void bellman_ford(int x){
    dist = vi(n, INF);
    dist[x] = 0;
    parent = vi(n, -1);

    for(int i=0; i < n; ++i){
        for(auto u : gr){
            int a, b, w;
            tie(a, b, w) = u;
            if(dist[a] < INF){
                if(dist[b] > dist[a] + w){
                    dist[b] = max(-INF, dist[a] + w);
                    parent[b] = a;
                    s = b;
                }
            }
        }
    }
}

void test_case(){

    cin >> n;

    rep(i, 0, n){
        rep(j, 0, n){
            int w;
            cin >> w;
            if(w != INF){
                gr.pb(tie(i,j,w));
            }
        }
    }

    bellman_ford(0);

    //print(dist);

    if(s == -1){
        cout << "NO";
    }else{
        cout << "YES\n";
        int y = s;
        cout << y << endl;
        for(int i=0; i < n; ++i){
            y = parent[y];
        }
        // print(parent);
        // return;
        vi path;
        for(int cur = y; ; cur = parent[cur]){
            path.pb(cur);
            if(cur == y && path.size() > 1) break;
        }
        reverse(all(path));

        cout << path.size() << endl;
        rep(i,0,path.size()){
            cout << path[i] << " ";
        }
        cout << endl;
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