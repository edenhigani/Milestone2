//
// Created by eden on 22/01/2020.
//
#pragma once
#include <vector>
#include "ISearchable.h"
#include "Matrix.h"


//template<class P, class S>
template <class T>
class ISearcher{
public:
    virtual vector<State<T>*> search(ISearchable<T> *searchable) = 0;
    virtual ISearcher * clone () const = 0;
    //virtual string search(ISearchable<P> searchable)=0;
    virtual int getNumberOfNodesEvaluated() = 0;
};

