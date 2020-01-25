//
// Created by eden on 16/01/2020.
//

#ifndef MILESTONE2_SERVERSIDE_H
#define MILESTONE2_SERVERSIDE_H

#include <iostream>
#include "ClientHandler.h"
#include <thread>
#include <iostream>
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
using namespace std;

namespace ServerSide {
    class Server {
    public:
        virtual int open(int port,ClientHandler* clientHandler) {
            cout << "server open function" << endl;
        }

        virtual void stop() {
            cout << "server stop function" << endl;
        }
        //virtual ~Server();
    };
}


#endif //MILESTONE2_SERVERSIDE_H
