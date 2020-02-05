#pragma once

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void list_read(vector<int>& vec, const char* filename) {
    ifstream ifs;
    ifs.open(filename);
    if(ifs.fail()) {
        cerr << "Fail to open list file " << filename << endl;
        exit(-1);
    }
    char temp=0;
    vec.clear();
    int tempd=0;
    while(ifs >> tempd) {
        vec.push_back(tempd);
    }
    ifs.close();
    return;
}

void list_write(const vector<int>& vec, const char* filename) {    
    ofstream ofs;
    ofs.open(filename);
    for(auto& d : vec) {
        ofs << d << '\n';
    }
    ofs.close();
    return;
}