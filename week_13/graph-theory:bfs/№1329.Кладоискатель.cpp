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
typedef vector<char> vc;
typedef vector<bool> vb;
typedef pair<int,int> pii;

vector<vc> gr;
vector<vi> dist;
vector<vb> used;
int n, m;
pii coor;
const int INF = 1e9;

bool cl(int u, int v){
    if(u >= 0){
        if(gr[v][u] != '1'){
            return true;
        }
    }
    return false;
}
bool cr(int u, int v){
    if(u < m){
        if(gr[v][u] != '1'){
            return true;
        }
    }
    return false;
}
bool cu(int u, int v){
    if(v >= 0){
        if(gr[v][u] != '1'){
            return true;
        }
    }
    return false;
}
bool cd(int u, int v){
    if(v < n){
        if(gr[v][u] != '1'){
            return true;
        }
    }return false;
}

void bfs(int x, int y){
    queue<pii> q;
    used = vector<vb> (n, vb(m,false));
    dist = vector<vi> (n, vi(m,INF));
    dist[y][x] = 0;
    q.push(make_pair(y,x));
    used[y][x] = true;

    while(!q.empty()){
        pii p = q.front();
        int u = p.second;
        int v = p.first;
        q.pop();
        if(cl(u-1,v) && !used[v][u-1]){
            used[v][u-1] = true;
            q.push(make_pair(v, u-1));
            dist[v][u-1] = dist[v][u] + 1;
            }
        if(cr(u+1,v) && !used[v][u+1]){
            used[v][u+1] = true;
            q.push(make_pair(v, u+1));
            dist[v][u+1] = dist[v][u] + 1;
        }
        if(cu(u,v-1) && !used[v-1][u]){
            used[v-1][u] = true;
            q.push(make_pair(v-1, u));
            dist[v-1][u] = dist[v][u] + 1;
        }
        if(cd(u,v+1) && !used[v+1][u]){
            used[v+1][u] = true;
            q.push(make_pair(v+1, u));
            dist[v+1][u] = dist[v][u] + 1;
        }
    }
}

void test_case(){
    cin >> n >> m;

    gr = vector<vc> (n, vc(m));

    for(int i=0; i < n; ++i){
        for(int j=0; j < m; ++j){
            cin >> gr[i][j];
            if(gr[i][j] == '*'){
                coor = make_pair(i,j);
            }
        }
    }
    int k;
    cin >> k;
    int mini = INF;
    int ans = -1;

    for(int i=0; i < k; ++i){
        int x,y;
        cin >> x >> y;
        --x; --y;
        bfs(y,x);
        if(dist[coor.first][coor.second] != INF){
            if(mini > dist[coor.first][coor.second]){
                ans = i+1;
                mini = dist[coor.first][coor.second];
            }
        }
    }
    cout << ans << endl;
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