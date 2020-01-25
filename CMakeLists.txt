cmake_minimum_required(VERSION 3.15)
project(milestone2)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS -pthread)

add_executable(milestone2 main.cpp ServerSide.cpp ServerSide.h MySerialServer.cpp MySerialServer.h ClientHandler.h MyTestClientHandler.cpp MyTestClientHandler.h Solver.h StringReverser.cpp StringReverser.h MyClientHandler.cpp MyClientHandler.h ISearchable.h State.cpp State.h Matrix.cpp Matrix.h Cell.cpp Cell.h MatrixSolver.cpp MatrixSolver.h ISearcher.h BFS.cpp BFS.h Searcher.cpp Searcher.h DFS.h PriorityQueue.h BestFirstSearch.h Astar.h MyParallelServer.cpp MyParallelServer.h CacheManager.h MyCacheManager.cpp MyCacheManager.h)