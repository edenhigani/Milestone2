#include <iostream>
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include "ServerSide.h"
#include "MySerialServer.h"
#include "ClientHandler.h"
#include "MyParallelServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
//#include "ISearcher.h"
//#include "ISearchable.h"
#include "MyClientHandler.h"
#include "MatrixSolver.h"
#include "BFS.h"
#include "DFS.h"
#include "BestFirstSearch.h"
#include "Astar.h"
#include "MyCacheManager.h"

using namespace std;
using namespace ServerSide;


int main(int argc, char *argv[]) {

    if(argc<2){
            cerr<< "port not found in main arguments";
            exit(1);
        }
        string portS = argv[1];
    int port = stoi(portS);

    Server *server = new MyParallelServer();
    CacheManager<string, string> *cache = new MyCacheManager();
    ClientHandler *handler = new MyClientHandler(new MatrixSolver(new Astar<Cell>),cache);
    ///ClientHandler *handler = new MyClientHandler(new MatrixSolver());
    server->open(port, handler);

    return 0;
}