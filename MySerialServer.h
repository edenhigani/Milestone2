//
// Created by eden on 17/01/2020.
//

#ifndef MILESTONE2_MYSERIALSERVER_H
#define MILESTONE2_MYSERIALSERVER_H

#include "ServerSide.h"


class MySerialServer : public ServerSide::Server {
    int open(int port,ClientHandler* clientHandler);
     void stop(){

     }
};


#endif //MILESTONE2_MYSERIALSERVER_H
