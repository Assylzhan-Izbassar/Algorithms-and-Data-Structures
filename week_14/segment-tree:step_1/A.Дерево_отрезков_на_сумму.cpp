#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct segment_tree{
    vector<ll> tree;
    int size;

    void init(int n){
        size = 1;
        while(size < n){
            size *= 2;
        }   
        tree.assign(2*size-1, 0); // потому что это бинарное дерево, мы size умножаем на 2, и правую границу исключительно.
    }

    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < a.size())
                tree[x] = a[lx];
        }else{
            int mid = lx + (rx - lx)/2;
            build(a,2*x+1, lx,mid);
            build(a,2*x+2, mid, rx);
            tree[x] = tree[2*x + 1] + tree[2*x + 2];
        }
    }
    void build(vector<int> &a){
        init(a.size());
        build(a, 0, 0, size);
    }
    void set(int i, int v){
        set(i, v, 0, 0, size); // начинаем от корня и обходим дерево
    }
    void set(int i, int v, int x, int lx, int rx){ // i, v, номер узла, и его границы
        if(rx - lx == 1){
            tree[x] = v; 
            return;
        }
        int mid = lx + (rx-lx)/2;

        if(i < mid){ // если i находится на левой половине
            set(i, v, 2*x + 1, lx, mid); // здесь mid не включительно
        }else{ //иначе
            set(i, v, 2*x + 2, mid, rx);
        }
        tree[x] = tree[2*x+1] + tree[2*x+2];
    }

    ll sum(int l, int r){
        return sum(l,r,0,0,size);
    }
    ll sum(int l, int r, int x, int lx, int rx){
        if(l >= rx || lx >= r){
            return 0;
        }
        if(lx >= l && rx <= r){
            return tree[x];
        }
        int mid = lx + (rx-lx)/2;
        ll s1 = sum(l, r, 2*x + 1, lx, mid);
        ll s2 = sum(l, r, 2*x + 2, mid, rx);
        return s1+s2;
    }
};

int main(){
    ios::sync_with_stdio(false);
    
    segment_tree st;

    int n,m;
    cin >> n >> m;

    vector<int> v(n);

    for(size_t i=0; i < v.size(); ++i) cin >> v[i];

    st.build(v);

    // for(size_t i=0; i < n; ++i){
    //     cin >> x;
    //     st.set(i,x);
    // }
    int x;
    for(size_t j=0; j < m; ++j){
        cin >> x;
        if(x == 1){
            int i,v;
            cin >> i >> v;
            st.set(i,v);
        }else{
            int l,r;
            cin >> l >> r;
            cout << st.sum(l,r) << endl;
        }
    }

    return 0;
}