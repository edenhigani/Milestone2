//
// Created by eden on 21/01/2020.
//

#ifndef MILESTONE2_MATRIX_H
#define MILESTONE2_MATRIX_H

#include <vector>
#include "Cell.h"
#include "State.h"
#include "ISearchable.h"

class Matrix: public ISearchable<Cell>{
private:
    State<Cell> *initial;
    State<Cell> *goal;
    //std::vector<std::vector<double>> mat;
    std::vector<std::vector<State<Cell>*>> mat;
    int size;

public:

    //Matrix(vector<string>);

    //Matrix(State<Cell> *initial1,State<Cell> *goal1,std::vector<std::vector<double>> mat1, int size1);
    Matrix(State<Cell> *initial1,State<Cell> *goal1,std::vector<std::vector<State<Cell>*>> mat1, int size1);

    State<Cell>* getInitialState();

     State<Cell> * getGoalState();
    //State<Cell> * getGoalState(State<Cell> *state1);
vector<State<Cell>> getPath(State<Cell> A){

}



    std::vector<State<Cell>*> getAllPossibleStates(State<Cell> *state1);

    //Matrix(vector<std::vector<double>> vector, State<struct Cell> *pState, State<struct Cell> *pState1);

};


#endif //MILESTONE2_MATRIX_H
