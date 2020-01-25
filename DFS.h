//
// Created by eden on 22/01/2020.
//
#include <vector>
#include <stack>
#include "ISearcher.h"
#include <unordered_set>
#include <algorithm>

//template<class P, class S>
template<class T>
//class BFS : public ISearcher<P,S> {
class DFS : public ISearcher<T> {
private:
    int evaluatedNodes = 0;
public:
    void setEvaluatedNodes(int num) {
        this->evaluatedNodes = num;
    }

    DFS (DFS const &){

    }
    DFS * clone () const        // Virtual constructor (copying)
    {
        return new DFS (*this);
    }

    vector<State<T>*> search(ISearchable<T> *searchable) {
        //State<T> *start = searchable->getInitialState();
        State<T> *end = searchable->getGoalState();
        vector<State<T>*> returnVal;
        vector<State<T> *> neigbhers;
        stack<State<T> *> Stack;
        State<T> *initialState = searchable->getInitialState();
        initialState->setVisited(true);
        initialState->setCost(initialState->getVal());

        evaluatedNodes++;

        Stack.push(initialState);
        while (!Stack.empty()) {
            State<T> *u = Stack.top(); // Node *u = Q.pop()
            Stack.pop();
            neigbhers = searchable->getAllPossibleStates(u);
            int numOfNeighbors = neigbhers.size();
            for (int i = 0; i < numOfNeighbors; i++) {
                if (neigbhers[i]->getVisited()== false) {
                    neigbhers[i]->setVisited(true);
                    evaluatedNodes++;
                    neigbhers[i]->setCameFrom(u);
                    neigbhers[i]->setCost(u->getCost() + u->getVal());
                    Stack.push(neigbhers[i]);
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
    DFS() {

    }
};

