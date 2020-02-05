#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

class HBB {
    public:
    HBB(int m_) {
        m = m_;
        srand(time(NULL));
    }
    void init() {
        lrow.clear();
        lrow.resize(m, 0);
        lcnt = 0;
        urow.clear();
        urow.resize(m, 0);
        ucnt = 0;
        profile.clear();
        profile.resize(m, 0);
        lgn = 5;

    }
    void play() {
        int c = rand() % m;
        int temp;
        int cnt = 0;
        do {
            cnt ++;
            temp = rand() % 2;
        } while(temp == 0);
        // P(cnt = k) = 2^{-k}
        // P(r = k) = 2^{-k-1}
        // thus we can couple r = cnt-1
        int r = cnt - 1;
        profile[c] = max(profile[c], r);
        if(r > lgn) {
            if (lrow[c] == 0) {
                lcnt ++;
                lrow[c] = 1;
            }
        }
        if(r > lgn+1) {
            if (urow[c] == 0) {
                ucnt ++;
                urow[c] = 1;
            }
        }
        if(lcnt > m/2-1) {
            rollUp();
        }
    }
    void play_infty() {
        int c = rand() % m;
        int temp;
        int cnt = 0;
        do {
            cnt ++;
            temp = rand() % 2;
        } while(temp == 0);
        // P(cnt = k) = 2^{-k}
        // P(r = k) = 2^{-k-1}
        // thus we can couple r = cnt-1
        int r = cnt - 1;
        profile[c] = max(profile[c], r);
        if(r > lgn) {
            if (lrow[c] == 0) {
                lcnt ++;
                lrow[c] = 1;
            }
        }
        if(r > lgn+1) {
            if (urow[c] == 0) {
                ucnt ++;
                urow[c] = 1;
            }
        }
        if(lcnt > m/2-1) {
            rollUp_infty();
        }
    }
    int estimate() {
        return (int) pow(2.0, lgn + 5.4 + ((float) lcnt) / ((float) m) * 2.0);
    }
    private:
    int m;
    vector<int> lrow;
    int lcnt;
    vector<int> urow;
    int ucnt;
    vector<int> profile;
    float lgn;
    void rollUp() {
        lcnt = ucnt;
        for(int i=0; i<m; i++) {
            lrow[i] = urow[i];
            urow[i] = 0;
        }
        ucnt = 0;

        lgn++;
    }
    void rollUp_infty() {
        lcnt = ucnt;
        ucnt = 0;
        for(int i=0; i<m; i++) {
            lrow[i] = urow[i];
            if (profile[i] > lgn+2) {
                urow[i] = 1;
                ucnt ++;
            } else {
                urow[i] = 0;
            }
        }

        lgn++;
    }
};