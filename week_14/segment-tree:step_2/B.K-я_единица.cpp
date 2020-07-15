//В этой задаче вам нужно добавить в дерево отрезков операцию нахождения 𝑘-й единицы.
#include <iostream>
#include <vector>

using namespace std;

struct segment_tree{
    vector<int> tree;
    int size;

    segment_tree(){
        size = 0;
    }

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
            tree[x] = tree[2*x + 1] + tree[2*x + 2];
        }
    }
    void build(vector<int> &a){
        init(a.size());
        build(a, 0, 0, size);
    }

    void set(int i, int x, int lx, int rx){
        if(rx - lx == 1){
            if(tree[x] == 1){
                tree[x] = 0;
            }else{
                tree[x] = 1;
            }
        }else{
            int mid = lx + (rx - lx)/2;

            if(i < mid){
                set(i, 2*x + 1, lx, mid);
            }else{
                set(i, 2*x + 2, mid, rx);
            }
            tree[x] = tree[2*x + 1] + tree[2*x + 2]; 
        }
    }
    void set(int i){
        set(i, 0, 0, size);
    }

    int k_th_one(int k, int x, int lx, int rx){
        if(rx - lx == 1){
            return lx;
        }
        int mid = lx + (rx - lx)*.5;
        if(k < tree[2*x+1]){
            return k_th_one(k, 2*x + 1, lx, mid);
        }else{
            return k_th_one(k - tree[2*x+1], 2*x + 2, mid, rx);
        }
    }
    int k_th_one(int k){
        return k_th_one(k, 0, 0, size);
    }

    void print(){
        if(size == 0)
            return;
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

    for(size_t i=0; i < n; ++i) cin >> a[i];

    segment_tree st;

    st.build(a);
    
    int x;
    for(size_t j = 0; j < m; ++j){
        cin >> x;
        if(x == 1){
            int i;
            cin >> i;
            st.set(i);
        }else{
            int k;
            cin >> k;
            cout << st.k_th_one(k) << endl;
        }
    }

    return 0;
}
