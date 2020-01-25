//
// Created by eden on 17/01/2020.
//

#include "MyTestClientHandler.h"
#include <iostream>
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
using namespace std;


MyTestClientHandler::MyTestClientHandler(Solver<string,string> *solver1){
    solver = solver1;
}


void MyTestClientHandler::handleClient(int clientsocket){
    //reading from client
    char buffer[1024] = {0};
    int valread = read( clientsocket , buffer, 1024);
    string a = string(buffer);
    //string r = "sol";
    //check in cash manager, if not we solve
    string r = solver->solve(a);

    //writing back to client
    send(clientsocket , r.c_str() , r.size() , 0 );
};