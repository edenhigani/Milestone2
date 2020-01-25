//
// Created by eden on 21/01/2020.
//

#ifndef MILESTONE2_ISEARCHABLE_H
#define MILESTONE2_ISEARCHABLE_H

#include <iostream>
#include <vector>
#include "State.h"
//#include "ISearcher.h"

template<typename T>
class ISearchable {
public:
    virtual State<T>* getInitialState()=0;

    virtual State<T>* getGoalState()=0;

    virtual std::vector<State<T>*> getAllPossibleStates(State<T> *state1)=0;
};


#endif //MILESTONE2_ISEARCHABLE_H
