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
    int n = 400000;
    cout << n << endl;
    lev.clear();
    hev.clear();
    for (int k=0; k<10000; k++) {
        cout << k << endl;
        low.init();
        high.init();
        for(int i=0; i<n; i++) {
            low.play();
            high.play_infty();
        }
        lev.push_back(low.estimate());
        hev.push_back(high.estimate());
    }
    string lname = "lev"+to_string(n)+".list";
    string hname = "hev"+to_string(n)+".list";
    list_write(lev, lname.c_str());
    list_write(hev, hname.c_str());           
    return 0;
}