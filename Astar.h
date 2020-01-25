//
// Created by eden on 24/01/2020.
//

#include <vector>
#include <stack>
#include "ISearcher.h"
#include <unordered_set>
#include <algorithm>

//template<class P, class S>
template<class T>
//class BFS : public ISearcher<P,S> {
class Astar : public ISearcher<T> {
private:
    int evaluatedNodes = 0;
public:
    void setEvaluatedNodes(int num) {
        this->evaluatedNodes = num;
    }
    Astar (Astar const &){

    }
    Astar * clone () const        // Virtual constructor (copying)
    {
        return new Astar (*this);
    }
    int getNumberOfNodesEvaluated() {
        return this->evaluatedNodes;
    }

    //huristics function for states in matrix
    int h(State<Cell> *current, State<Cell> *goal) {
        return abs(current->getState()->getx() - goal->getState()->getx())
               + abs(current->getState()->gety() - goal->getState()->gety());
    }

    //gets the lowest state by f(), [which is h()+cost]
    State<T> *minimal(vector<State<T> *> open1, State<T> *goal) {
        State<T> *minState = open1[0];
        double minF = minState->getCost() + h(minState, goal);
        State<T> *curr;
        double currF;

        for (int i = 0; i < open1.size(); i++) {
            curr = open1[i];
            //comparing f() values
            currF = curr->getCost() + h(curr, goal);
            if (minF > currF) {
                minF = currF;
                minState = curr;
            }
        }
        return minState;
    }


    vector<State<T> *> search(ISearchable<T> *searchable) {
        vector<State<T> *> returnVal;
        vector<State<T> *> open;
        State<T> *goalState = searchable->getGoalState();
        State<T> *initialState = searchable->getInitialState();

        // double fInitial = h(initialState, goalState);
        //Put node_start in the OPEN list
        initialState->setCost(initialState->getVal());
        open.push_back(initialState);

        State<T> *curr = initialState;
        State<T> *successor;
        bool flag = true;

        while (!open.empty()) {
            //Take from the open list the node node_current with the lowest f
            if (flag) {
                flag = false;
            } else
                curr = minimal(open, goalState);
//pop it out
            typename vector<State<T> *>::iterator it1 = std::find(open.begin(), open.end(), curr);
            if (!open.empty() && it1 != open.end())
                open.erase(it1);

            if (curr == goalState) {
                break;
            }
            vector<State<T> *> neigbhers = searchable->getAllPossibleStates(curr);
            for (int i = 0; i < neigbhers.size(); i++) {
                successor = neigbhers[i];
                double successor_current_cost = curr->getCost() + successor->getVal();

                if (std::find(open.begin(), open.end(), successor) != open.end()) {
                    if (successor->getVal() <= successor_current_cost) {
                        continue;
                    }
                } else if (successor->getVisited()) {
                    if (successor->getVal() <= successor_current_cost) {
                        continue;
                    }
                    ///move successor from close list to open list
                    open.push_back(successor);
                    successor->setVisited(false);
                } else {
                    open.push_back(successor);
                    successor->setVisited(false);
                }
                ///Set g(node_successor) = successor_current_cost
                successor->setCost(successor_current_cost);
                ///Set the parent of node_successor to node_current
                successor->setCameFrom(curr);
            }
            curr->setVisited(true);
            evaluatedNodes++;
            typename vector<State<T> *>::iterator it = std::find(open.begin(), open.end(), curr);
            if (!open.empty() && it != open.end())
                open.erase(it);
        }
        if (curr->getState() != goalState->getState()) {
            cout << "no path found\n";
            return returnVal;
        }

        State<T> *currentState = searchable->getGoalState();
        State<T> *start = searchable->getInitialState();
        if (currentState->getCameFrom() == NULL) {
            return returnVal;
        }
        //create path
        while (start != currentState) {
            returnVal.push_back(currentState);
            currentState = currentState->getCameFrom();
        }
        returnVal.push_back(searchable->getInitialState());

        reverse(returnVal.begin(), returnVal.end());

        cout << getNumberOfNodesEvaluated() << endl;
        return returnVal;

    }

    Astar() {

    }
};


