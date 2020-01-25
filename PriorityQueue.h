//
// Created by eden on 24/01/2020.
//
#include <queue>
#include <iostream>
#include "State.h"

using namespace std;

template<class T>
class PQCmp {
public:
    bool operator()(State<T> *left, State<T> *right) {
        return left->getCost() > right->getCost();
    }
};

template<class T>
class PriorityQueue {
    priority_queue<State<T> *, vector<State<T> *>, PQCmp<T>> pq;

public:
    bool empty() {
        return this->pq.empty();
    }

    void addInPQ(State<T> *state1) {
        this->pq.push(state1);
    }

    State<T> *popOutPQ() {
        State<T> *topQ = this->pq.top();
        this->pq.pop();
        return topQ;
    }

    bool contains(State<T> *check) {
        bool isFound = false;
        vector<State<T> *> temp;
        while (!this->pq.empty()) {
            State<T> *val = this->popOutPQ();
            temp.push_back(val);
            if (val == check) {
                isFound = true;
                break;
            }
        }
        for (int i = 0; i < temp.size(); i++) {
            this->addInPQ(temp[i]);
        }
        return isFound;
    }

    void updatePriority(State<T> *curr, State<T> *newV) {
        double update;
        vector<State<T> *> temp;
        while (!this->pq.empty()) {
            State<T> *topVal = this->popOutPQ();
            temp.push_back(topVal);
            if (curr == topVal) {
                topVal->setCameFrom(newV);
                update = newV->getCost() + curr->getCost();
                topVal->setCost(update);
                break;
            }
        }
        for (int i = 0; i < temp.size(); i++) {
            this->pq.push(temp[i]);
        }
    }
};
