#include "hbb.h"
#include "list.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    HBB low(64);
    HBB high(64);
    vector<int> lev;
    vector<int> hev;
    for(int n = 100000; n<500000; n+=10000) {
        cout << n << endl;
        lev.clear();
        hev.clear();
        for (int k=0; k<1000; k++) {
            low.init();
            high.init();
            for(int i=0; i<n; i++) {
                low.play();
                high.play_infty();
            }
            lev.push_back(low.estimate());
            hev.push_back(high.estimate());
        }
        string lname = "data/lev"+to_string(n)+".list";
        string hname = "data/hev"+to_string(n)+".list";
        list_write(lev, lname.c_str());
        list_write(hev, hname.c_str());   
    }
        
    return 0;
}