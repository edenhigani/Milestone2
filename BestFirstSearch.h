//
// Created by eden on 24/01/2020.
//
#include "ISearcher.h"
#include "PriorityQueue.h"
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

template<class T>
class BestFirstSearch : public ISearcher<T> {
private:
    int evaluatedNodes = 0;
    vector<State<T> *> path;
public:
    void setEvaluatedNodes(int num) {
        this->evaluatedNodes = num;
    }

    BestFirstSearch (BestFirstSearch const &){

    }
    BestFirstSearch * clone () const        // Virtual constructor (copying)
    {
        return new BestFirstSearch (*this);
    }

    int getNumberOfNodesEvaluated() {
        return this->evaluatedNodes;
    }

    vector<State<T> *> search(ISearchable<T> *searchable) {
        PriorityQueue<T> *open;
        open = new PriorityQueue<T>();
        State<T> *initial = searchable->getInitialState();
        open->addInPQ(initial);
        initial->setCost(initial->getVal());
        State<T> *goal = searchable->getGoalState();

        while (!open->empty()) {
            State<T> *curr = open->popOutPQ();
            curr->setVisited(true);
            evaluatedNodes++;

            if (curr == goal) {
                path.push_back(goal);

                while (goal->getCameFrom() != NULL) {
                    State<T> *currsCameFrom = goal->getCameFrom();
                    path.push_back(currsCameFrom);
                    goal = currsCameFrom;
                }
                reverse(path.begin(), path.end());
                cout << getNumberOfNodesEvaluated() << endl;
                return path;
            }
            //////evaluatedNodes++;

            vector<State<T> *> neighbors = searchable->getAllPossibleStates(curr);
            for (int i = 0; i < neighbors.size(); i++) {
                State<T> *neighbor = neighbors[i];
                double currentPath = curr->getCost() + neighbor->getVal();

                if (!neighbor->getVisited() && !open->contains(neighbor)) {
                    neighbor->setCameFrom(curr);
                    neighbor->setCost(currentPath);
                    open->addInPQ(neighbor);

                } else if (currentPath < neighbor->getVal()) {
                    if (!open->contains(neighbor)) {
                        open->addInPQ(neighbor);
                    } else {
                        open->updatePriority(neighbor, curr);
                    }
                }
            }
        }
        //set the path to return
        path.push_back(goal);
        while (goal->getCameFrom() != NULL) {
            State<T> *currsCameFrom = goal->getCameFrom();
            path.push_back(currsCameFrom);
            goal = currsCameFrom;
        }

        if (goal->getCameFrom() == NULL) {
            vector<State<T> *> returnVal;
            return returnVal;
        }
        reverse(path.begin(), path.end());
        cout << getNumberOfNodesEvaluated() << endl;
        return path;
    }

    BestFirstSearch() {

    }

};

