//
// Created by eden on 17/01/2020.
//

#ifndef MILESTONE2_SOLVER_H
#define MILESTONE2_SOLVER_H
template <typename P, typename S>
class Solver{
public:
    virtual S solve(P probelm) = 0;

    virtual Solver * clone () const = 0;
};
#endif //MILESTONE2_SOLVER_H