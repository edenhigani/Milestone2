//
// Created by eden on 22/01/2020.
//
#include <vector>
#include <queue>
#include "ISearcher.h"
#include <unordered_set>
#include <algorithm>

//template<class P, class S>
template<class T>
//class BFS : public ISearcher<P,S> {
class BFS : public ISearcher<T> {
private:
    int evaluatedNodes = 0;
public:
    void setEvaluatedNodes(int num) {
        this->evaluatedNodes = num;
    }

    BFS (BFS const &){

    }
    BFS * clone () const        // Virtual constructor (copying)
    {
        return new BFS (*this);
    }

    vector<State<T>*> search(ISearchable<T> *searchable) {
        ///State<T> *start = searchable->getInitialState();
        State<T> *end = searchable->getGoalState();
        vector<State<T>*> returnVal;
        vector<State<T> *> neigbhers;
        queue<State<T> *> Q;
        State<T> *initialState = searchable->getInitialState();
        initialState->setVisited(true);
        initialState->setCost(initialState->getVal());
        evaluatedNodes++;
        Q.push(initialState);
        while (!Q.empty()) {
            State<T> *u = Q.front(); // Node *u = Q.pop()
            Q.pop();
            neigbhers = searchable->getAllPossibleStates(u);
            int numOfNeighbors = neigbhers.size();
            for (int i = 0; i < numOfNeighbors; i++) {
                if (neigbhers[i]->getVisited()== false) {
                    neigbhers[i]->setVisited(true);
                    ///
                    evaluatedNodes++;
                    neigbhers[i]->setCameFrom(u);
                    neigbhers[i]->setCost(u->getCost() + u->getVal());
                    Q.push(neigbhers[i]);
                }
            }
        }


        if (searchable->getGoalState()->getCameFrom() == NULL) {
            return returnVal;
        }

        while (initialState != end) {
            returnVal.push_back(end);
            end = end->getCameFrom();
        }
        returnVal.push_back(initialState);
        reverse(returnVal.begin(), returnVal.end());
        cout << getNumberOfNodesEvaluated() << endl;
        return returnVal;
    }

    int getNumberOfNodesEvaluated() {
        return this->evaluatedNodes;
    }
    BFS() {

    }
};
