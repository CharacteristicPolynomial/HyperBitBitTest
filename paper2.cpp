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
    int tL = 12;
    int tS0 = 31;
    lev.clear();
    hev.clear();
    for (int k=0; k<10000; k++) {
        cout << k << endl;
        low.init();
        high.init();
        lev.push_back(low.play_till(tL,tS0));
        // cout << lev.back() << endl;
        hev.push_back(high.play_infty_till(tL,tS0));
    }
    string lname = "lev_till_"+to_string(tL)+"_"+to_string(tS0)+".list";
    string hname = "hev_till_"+to_string(tL)+"_"+to_string(tS0)+".list";
    list_write(lev, lname.c_str());
    list_write(hev, hname.c_str());           
    return 0;
}