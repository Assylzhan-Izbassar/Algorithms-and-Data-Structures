#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class point{
    public:
    double x;
    double v;

    point(double _x, double _v){
        x = _x;
        v = _v;
    }
};

bool f(vector<point> &a, double T){

    double l,r,l1,r1,l2,r2;

    l1 = a[0].x - T*a[0].v;
    r1 = a[0].x + T*a[0].v;
    l2 = a[1].x - T*a[1].v;
    r2 = a[1].x + T*a[1].v;

    l = max(l1,l2);
    r = min(r1,r2);

    if(l > r){
        return false;
    }

    for(size_t i=2; i < a.size(); ++i){
        l1 = a[i].x - (double)T*a[i].v;
        r1 = a[i].x + (double)T*a[i].v;
        l = max(l1,l);
        r = min(r1,r);
        if(l > r){
            return false;
        }
    }
    return true;
}

int main(){

    int n;
    double x,v;

    cin >> n;

    vector<point> a;

    for(size_t i=0; i < n; ++i){
        cin >> x >> v;
        a.push_back(point(x,v));
    }

    double l = 0;
    double r = 1e10;

    for(size_t i=0; i < 100; ++i){
        double T = l + (r-l)/2;

        if(f(a, T)){
            r = T;
        }else{
            l = T;
        }
    }
    cout << setprecision(20) << r << endl;

    return 0;
}