#include <iostream>
#include <vector>

using namespace std;

struct segment_tree{

    vector<int> tree;
    int size;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        tree.assign(2*size - 1, 0);
    }

    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx == 1){
            if(lx < a.size()){
                tree[x] = a[lx];
            }
        }else{
            int mid = lx + (rx - lx)/2;
            build(a, 2*x + 1, lx, mid);
            build(a, 2*x + 2, mid, rx);
            tree[x] = max(tree[2*x + 1], tree[2*x + 2]);
        }
    }
    void build(vector<int> &a){
        init(a.size());
        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx == 1){
            tree[x] = v;
        }else{
            int mid = lx + (rx - lx)/2;
            if(i < mid){
                set(i, v, 2*x + 1, lx, mid);
            }else{
                set(i, v, 2*x + 2, mid, rx);
            }
            tree[x] = max(tree[2*x + 1], tree[2*x + 2]);
        }
    }
    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    int find_above(int t, int x, int lx, int rx){
        if(rx - lx == 1){
            if(tree[x] < t){
                return -1;
            }else{
                return lx;
            }
        }
        else{
            int mid = lx + (rx - lx)/2;
            if(tree[2*x + 1] >= t){
                return find_above(t, 2*x + 1, lx, mid);
            }else{
                return find_above(t, 2*x + 2, mid, rx);
            }
        }
    }
    int find_above(int t){
        return find_above(t, 0, 0, size);
    }

    void print(){
        for(size_t i=0; i < tree.size(); ++i){
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i=0; i < a.size(); ++i) cin >> a[i];

    segment_tree st;

    st.build(a);

    for(int j = 0; j < m; ++j){
        int x;
        cin >> x;
        if(x == 1){
            int i, v;
            cin >> i >> v;
            st.set(i,v);
        }else{
            int t;
            cin >> t;
            cout << st.find_above(t) << endl;
        }
    }

    //st.print();

    return 0;
}