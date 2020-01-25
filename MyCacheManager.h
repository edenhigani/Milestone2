//
// Created by eden on 25/01/2020.
//
#include <string>
#include <fstream>
#include "CacheManager.h"
#include <unordered_map>
#include <list>
#include <mutex>
#include <iostream>

using namespace std;
class MyCacheManager : public CacheManager<string,string>{
public:
    MyCacheManager() {

    }

    MyCacheManager (MyCacheManager const & a){

    }
    MyCacheManager* clone()  override {
        return new MyCacheManager(*this);
    }
    void insert(string problemAsString,string solution){
        ofstream data;
        data.open(problemAsString, ios_base::app);
        data << solution << endl;
        data.close();
    }
    string get(string key) {
        string solution;
        ifstream infoFromTheFile;
        infoFromTheFile.open(key);
        if (!infoFromTheFile) {
            // if not in data
            return "no file was found";
        }
        getline(infoFromTheFile, solution);
        insert(key, solution);
        return solution;
    }
};