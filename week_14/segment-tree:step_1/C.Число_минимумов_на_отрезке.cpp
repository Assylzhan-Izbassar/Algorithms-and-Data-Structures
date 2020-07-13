#include <iostream>
#include <vector>

using namespace std;

struct segment_tree{
    struct node{
        int min, cnt;
        node(){}
        node(int _min, int _cnt){
            min = _min;
            cnt = _cnt;
        }
    };

    vector<node> tree;
    int size;
    node ZERO;

    segment_tree(){
        ZERO = node(INT_MAX, 0);
    }

    node which_one(node a, node b){
        if(a.min < b.min) return a;
        if(a.min > b.min) return b;
        return node(a.min, a.cnt + b.cnt);
    }

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2*size - 1, ZERO);
    }
    void build(vector<int> &a){
        init(a.size());
        build(a, 0, 0, size);
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < a.size()){
                tree[x] = node(a[lx], 1);
            }
        }else{
            int mid = lx + (rx-lx)/2;
            build(a, 2*x+1, lx, mid);
            build(a, 2*x+2, mid, rx);
            tree[x] = which_one(tree[2*x+1], tree[2*x+2]);
        }
    }

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }
    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            tree[x] = node(v,1);
            return;
        }
        int mid = lx + (rx-lx)/2;
        if(i < mid){
            set(i, v, 2*x + 1, lx, mid);
        }else{
            set(i, v, 2*x + 2, mid, rx);
        }
        tree[x] = which_one(tree[2*x+1], tree[2*x+2]);
    }

    node get_min(int l, int r){
        return get_min(l, r, 0, 0, size);
    }
    node get_min(int l, int r, int x, int lx, int rx){
        if(l >= rx || lx >= r)
            return ZERO;
        if(l <= lx && rx <= r){
            return tree[x];
        }
        int mid = lx + (rx - lx)/2;
        node m1 = get_min(l, r, 2*x + 1, lx, mid);
        node m2 = get_min(l, r, 2*x + 2, mid, rx);
        return which_one(m1,m2);
    }
};

int main(){

    ios::sync_with_stdio(false);

    int n,m;
    cin >> n >> m;

    segment_tree st;

    vector<int> v(n);

    for(size_t i=0; i < n;  ++i) cin >> v[i];
    
    st.build(v);

    int x;
    for(size_t j=0; j < m; ++j){
        cin >> x;
        if(x == 1){
            int i,v;
            cin >> i >> v;
            st.set(i,v);
        }else{
            int l, r;
            cin >> l >> r;
            segment_tree::node ans = st.get_min(l,r);
            cout << ans.min << " " << ans.cnt << endl;
        }
    }

    return 0;
}