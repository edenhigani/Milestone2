//
// Created by eden on 17/01/2020.
//

#ifndef MILESTONE2_CLIENTHANDLER_H
#define MILESTONE2_CLIENTHANDLER_H



class ClientHandler {
public:
    virtual void handleClient(int clientsocket)=0;

    virtual ClientHandler * clone ()  = 0;

};


#endif //MILESTONE2_CLIENTHANDLER_H