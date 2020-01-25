//
// Created by eden on 20/01/2020.
//

#include "MyClientHandler.h"
#include <iostream>
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <vector>

using namespace std;


MyClientHandler::MyClientHandler(Solver<vector<string>, string> *solver1,CacheManager<string,string> *cacheManager1) {
    this->solver = solver1;
    this->cacheManager = cacheManager1;
}

void MyClientHandler::handleClient(int clientsocket) {
    bool flag = true;
    vector<std::string> matrixString;
    string asString = "";
    string line = "";
    while (flag) {
        char buffer[1024] = {0};
        int valread = read(clientsocket, buffer, 1024);
        string check = string(buffer);
        for (int i = 0; i < 1024; i++) {
            if (buffer[i] == '\n') {
                matrixString.push_back(line);
                asString += line;
                line = "";
            } else {
                if (buffer[i] == 0) {
                    line = "";
                    break;
                }
                //for "end"
                if (buffer[i] == 'e') {
                    flag = false;
                    break;
                }
                line += buffer[i];
            }
        }
    }
    string result, notFound = "no file was found";
    string key = to_string(this->hashFu(asString));
    result = cacheManager->get(key);
    if (result == notFound) {
        cout << "using the solver" << endl;
        result = this->solver->solve(matrixString);
        this->cacheManager->insert(key, result);
    } else {
        cout<<"not using the solver"<<endl;
    }
    int valsent = send(clientsocket, result.c_str(), result.size(), 0);
}