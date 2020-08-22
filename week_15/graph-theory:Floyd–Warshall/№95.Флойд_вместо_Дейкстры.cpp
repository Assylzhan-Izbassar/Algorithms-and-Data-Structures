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
int gr[50][50];
int dist[50][50];
const int INF = 1e9;

void floyd_warshall(){
    rep(i, 0, n){
        rep(j, 0, n){
            if(i == j) dist[i][j] = 0;
            else if(gr[i][j] != -1) dist[i][j] = gr[i][j];
            else dist[i][j] = INF;
        }
    }

    rep(k, 0, n){
        rep(i, 0, n){
            rep(j, 0, n){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
int s,e;
void test_case(){
    cin >> n >> s >> e;

    rep(i, 0, n){
        rep(j, 0, n){
            cin >> gr[i][j];
        }   
    }
    floyd_warshall();

    if(dist[--s][--e] != INF){
        cout << dist[s][e] << endl;
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