//
// Created by eden on 20/01/2020.
//

#ifndef MILESTONE2_MYCLIENTHANDLER_H
#define MILESTONE2_MYCLIENTHANDLER_H

#include <string>
#include <vector>
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
using namespace std;

class MyClientHandler:public ClientHandler {
    Solver<vector<string>,string> *solver;
    CacheManager<string,string>* cacheManager;
    hash<string> hashFu;

public:
    MyClientHandler(Solver<vector<string>,string> *solver1, CacheManager<string,string> *cacheManager1);

    MyClientHandler (MyClientHandler const & a){
        this->solver = a.solver->clone();
       this->cacheManager = a.cacheManager->clone();
    }
    MyClientHandler* clone()  override {
        return new MyClientHandler(*this);
    }

    void handleClient(int clientsocket) override;
};


#endif //MILESTONE2_MYCLIENTHANDLER_H
