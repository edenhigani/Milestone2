//
// Created by eden on 21/01/2020.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H
#include <list>
template<typename T>
class State {
private:
    T *state;
    double cost = 0;
    State<T> *cameFrom = NULL;
    bool visited = false;
    double value;

    double pathcost=0;
public:
    State<T>(T* state1){
        this->state = state1;
    }/**
    T* getState();
    double getCost();
    State<T>* getCameFrom();
    bool getVisited();
    double getVal();
    void setCost(double c);
    void setCameFrom(State<T> *prev);
    void setVisited(bool b);
    void setVal(double val);*/

   double getVal() {
       return this->value;
   }

    double getCost(){
        return this->cost;
    }

    State<T>* getCameFrom(){
        return this->cameFrom;
    }
    bool getVisited(){
        return this->visited;
    }
    void setCost(double c){
        this->cost = c;
    }
    void setCameFrom(State<T> *prev){
        this->cameFrom = prev;
    }
    void setVisited(bool b){
        this->visited  = b;
    }
    void setVal(double val) {
        this->value = val;
    }

    T *getState() {
        return this->state;
    }


    void setPathCost(double pc){
       this->cost = pc;
   }

   double getPathCost(){
       return this->cost;
   }


    bool operator==(State<T> *otherState) {
        return this->getState() == otherState->getState();
    }
    bool operator!=(State<T> *otherState) {
        return this->getState() != otherState->getState();
    }

};


#endif //MILESTONE2_STATE_H
