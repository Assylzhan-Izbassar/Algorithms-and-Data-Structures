#include <iostream>
#include <vector>

using namespace std;

struct segment_tree{
    vector<int> tree;
    int size;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2*size - 1, INT_MAX);
    }

    void build(vector<int> &a){
        init(a.size());
        build(a, 0, 0, size);
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < a.size()){
                tree[x] = a[lx];
            }
        }else{
            int mid = lx + (rx - lx)/2;
            build(a, 2*x+1, lx, mid);
            build(a, 2*x+2, mid, rx);
            tree[x] = min(tree[2*x+1], tree[2*x+2]);
        }
    }

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            tree[x] = v;
            return;
        }
        int mid = lx + (rx - lx)/2;
        if(i < mid){
            set(i, v, 2*x + 1, lx, mid);
        }else{
            set(i, v, 2*x + 2, mid, rx);
        }
        tree[x] = min(tree[2*x+1], tree[2*x+2]);
    }

    int get_min(int l, int r){
        return get_min(l, r, 0, 0, size);
    }
    int get_min(int l, int r, int x, int lx, int rx){
        if(l >= rx || lx >= r)
            return INT_MAX;
        if(lx >= l && rx <= r){
            return tree[x];
        }
        int mid = lx + (rx-lx)/2;
        int m1 = get_min(l, r, 2*x+1, lx, mid);
        int m2 = get_min(l, r, 2*x+2, mid, rx);
        return min(m1,m2);
    }
};

int main(){

    ios::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;

    segment_tree st;

    vector<int> v(n);

    int x;
    for(size_t i=0; i < n; ++i) cin >> v[i];

    st.build(v);

    for(size_t j=0; j < m; ++j){
        cin >> x;
        if(x == 1){
            int i, v;
            cin >> i >> v;
            st.set(i,v);
        }else{
            int l,r;
            cin >> l >> r;
            cout << st.get_min(l,r) << endl;
        }
    }

    return 0;
}