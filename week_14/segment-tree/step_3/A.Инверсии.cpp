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

    void set(int i, int x, int lx, int rx){
        if(rx - lx == 1){
            tree[x]++;
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

    int sum(int l, int r, int x, int lx, int rx){
        if(l >= rx || lx >= r){
            return 0;
        }
        if(lx >= l && rx <= r){
            return tree[x];
        }
        int mid = lx + (rx - lx)/2;
        int s1 = sum(l, r, 2*x + 1, lx, mid);
        int s2 = sum(l, r, 2*x + 2, mid, rx);
        return s1 + s2;
    }
    int sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }

    void print(){
        for(size_t i=0; i < tree.size(); ++i)  
            cout << tree[i] << " ";
        cout << endl;
    }
};

int main(){

    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for(size_t i=0; i < n; ++i) cin >> a[i];

    segment_tree st;
    st.init(n);
    for(size_t i=0; i < n; ++i){
        cout << st.sum(a[i]-1, n) << " ";
        st.set(a[i]-1);
    }

    //st.print();
    return 0;
}