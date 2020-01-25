//
// Created by eden on 25/01/2020.
//
#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <functional>
#include <map>
#include <fstream>
#include <stack>

using namespace std;

#include <vector>
#include <sstream>
#include <iterator>


using namespace std;

template<class Problem, class Solution>
class CacheManager {
public:

    virtual void insert(Problem problem, Solution solution) = 0;

    virtual Solution get(Problem problem) = 0;

    virtual CacheManager * clone ()  = 0;
};
