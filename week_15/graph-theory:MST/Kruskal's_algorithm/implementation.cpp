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
// vector<tp> edges; <- not recommended to use tp, for reason that sort is not work fine;
vector<pair<int, pii> > edges;
vector<pii> res;
vi tree_id;

int kruskal(){
    int cost = 0;

    sort(all(edges));
    tree_id = vi(n);

    rep(i, 0, n)
        tree_id[i] = i;

    for(auto e : edges){
        int a, b, w;
        a = e.se.fi; b = e.se.se; w = e.fi;
        if(tree_id[a] != tree_id[b]){
            res.pb({a+1,b+1});
            cost += w;
            int old_id = tree_id[b]; // here you should be accurate 
            int new_id = tree_id[a]; // with indices of a and b;
            rep(j, 0, n){
                if(tree_id[j] == old_id){
                    tree_id[j] = new_id;
                }
            } 
        }
    }

    return cost;
}

void test_case(){
    cin >> n >> m;

    rep(i, 0, m){
        int v,u,w;
        cin >> v >> u >> w;
        --v; --u; 
        edges.pb({w,{v,u}});
    }
    cout << kruskal() << endl;

    for(auto e : res){
        int a = e.fi; int b = e.se;
        cout << a << " " << b << endl;
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