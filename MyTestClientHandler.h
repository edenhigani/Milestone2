//
// Created by eden on 17/01/2020.
//

#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H

#include <string>
#include "ClientHandler.h"
#include "Solver.h"

using namespace std;

class MyTestClientHandler:public ClientHandler {
    Solver<string,string> *solver;

public:
    MyTestClientHandler(Solver<string,string> *solver1);

     void handleClient(int clientsocket) override;
};


#endif //MILESTONE2_MYTESTCLIENTHANDLER_H
