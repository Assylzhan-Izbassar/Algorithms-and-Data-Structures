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

int n;
vector<vi> gr;
vb used;
vi min_e, sel_e;
const int INF = 1e9;

void prim(){
    used = vb(n, false);
    min_e = vi(n, INF);
    sel_e = vi(n, -1);

    min_e[0] = 0;

    rep(i, 0, n){
        int v = -1;
        rep(j, 0, n){
            if(!used[j] && (v == -1 || min_e[v] > min_e[j])){
                v = j;
            }
        }

        if(min_e[v] == INF){
            cout << "NO\n";
            return;
        }
        used[v] = true;

        if(sel_e[v] != -1){
            cout << v + 1 << " " << sel_e[v] + 1 << endl;
        }

        rep(u, 0, n){
            if(gr[v][u] == 1 && gr[v][u] < min_e[u]){
                min_e[u] = gr[v][u];
                sel_e[u] = v;
            }
        }
    }
}

void test_case(){
    int m;
    cin >> n >> m;
    gr = vector<vi>(n, vi(n));

    rep(i, 0, m){
        int v,u;
        cin >> v >> u;
        --v; --u;
        gr[v][u] = 1;
        gr[u][v] = 1;
    }
    prim();
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