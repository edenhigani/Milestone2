//
// Created by eden on 17/01/2020.
//

#ifndef MILESTONE2_STRINGREVERSER_H
#define MILESTONE2_STRINGREVERSER_H

#include "Solver.h"
#include "string"
#include <algorithm>

class StringReverser: public Solver<std::string,std::string> {
public:
    std::string solve(std::string problem) override {
        std::reverse(problem.begin(),problem.end());
        return problem;
    }
};


#endif //MILESTONE2_STRINGREVERSER_H
