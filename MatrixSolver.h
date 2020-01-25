//
// Created by yuval on 21/01/2020.
//

#ifndef MILESTONE2_MATRIXSOLVER_H
#define MILESTONE2_MATRIXSOLVER_H

#include <string>
#include <iostream>
#include "Cell.h"
#include "State.h"
//#include "ISearchable.h"
//#include "ISearcher.h"
#include "Solver.h"
#include "Matrix.h"
#include "ISearcher.h"
//#include "BFS.h"
//#include "DFS.h"

class MatrixSolver : public Solver<vector<std::string>, string> {
    ISearcher<Cell> *searcher;

public:
    MatrixSolver(ISearcher<Cell> *searcher1) {
        this->searcher = searcher1;
    }
    MatrixSolver *clone() const        // Virtual constructor (copying)
    {
        return new MatrixSolver(*this);
    }
    MatrixSolver(MatrixSolver const &a) {
        this->searcher = a.searcher->clone();
    }

    MatrixSolver() {}

    string solve(vector<string> vec) override {
        std::vector<std::vector<double>> mat;
        //
        vector<vector<State<Cell>>> mats;
        vector<double> linevec;
        //  Cell goal1 = ;
        ///State<Cell>* goal =new State<Cell>(new Cell(vec.back()));
        Cell *goalCell = new Cell(vec.back());
        vec.pop_back();
        //     Cell initial1 = Cell(vec.back());
        ///State<Cell>* initial = new State<Cell>(new Cell(vec.back()));
        Cell *initialCell = new Cell(vec.back());
        vec.pop_back();
//running all over the vector
        int row = 0, col = 0, size = vec.size();
        for (string line : vec) {
            char *cpy = new char[line.size() + 1];
            auto ss = line.c_str();
            strcpy(cpy, ss);
            string token = strtok(cpy, ", \n");
            for (col = 0; col < size; col++) {
                linevec.push_back(stod(token));
                if (col != size - 1)
                    token = strtok(NULL, ", \n");
            }
            mat.push_back(linevec);
            row++;
            linevec.clear();
        }


        vector<State<Cell> *> lineStateVec;
        vector<vector<State<Cell> *>> stateVec;
        int r = 0, c = 0, s = size;
        for (r = 0; r < size; r++) {
            for (c = 0; c < size; c++) {
                State<Cell> *newstate = new State<Cell>(new Cell(r, c));
                newstate->setVal(mat[r][c]);
                lineStateVec.push_back(newstate);
            }
            stateVec.push_back(lineStateVec);
            lineStateVec.clear();
        }

        State<Cell> *goal1 = stateVec[goalCell->getx()][goalCell->gety()];
        State<Cell> *initial1 = stateVec[initialCell->getx()][initialCell->gety()];

        /// goal->setVal(mat[goal->getState()->getx()][goal->getState()->gety()]);
        /// initial->setVal(mat[initial->getState()->getx()][initial->getState()->gety()]);

        //ISearchable<Cell>* X = new Matrix(initial,goal,mat,size);
        ISearchable<Cell> *X = new Matrix(initial1, goal1, stateVec, size);
        vector<State<Cell>*> resultVec =  this->searcher->search(X);
        string path = getStringResult(resultVec);
        cout << "SDdsds" << std::endl;
        return path;

    }

    string getStringResult(vector<State<Cell>*> vector){
        string result="";
        for(int i =0 ; i<vector.size()-1; i++){
            auto curr = vector[i];
            auto next = vector[i+1];
            if(curr->getState()->getx()+1 == next->getState()->getx()){
                //down
                result += " ,Down (" + to_string(int(next->getCost())) + ")";

            }
            if(curr->getState()->getx()-1 == next->getState()->getx()){
                //up
                result += " ,Up ("+ to_string(int(next->getCost())) + ")";
            }
            if(curr->getState()->gety()+1 == next->getState()->gety()){
                //right
                result += " ,Right ("+ to_string(int(next->getCost())) + ")";
            }
            if(curr->getState()->gety()-1 == next->getState()->gety()){
                //left
                result += " ,Left ("+ to_string(int(next->getCost())) + ")";
            }
        }

        string ret = result.substr(2);
        return ret;
    }


};


/*
 *  this->goal = new State<Cell>(Cell(vec.back()));
    vec.pop_back();
    this->initial = new State<Cell>(vec.back());
    vec.pop_back();
//running all over the vector
    int row = 0, col = 0;
    for (string line : vec) {
        char *cpy = strcpy(cpy, line.c_str());
        string token = strtok(cpy, ",\n");
        for (col = 0; col < row; col++) {
            //string str = token;
            //Cell cell = Cell(row, col);
            //State<Cell> *state = new State<Cell>(cell);
            this->mat[row][col] = stod(token);
            token = strtok(NULL, ",\n");
        }
        row++;
    }
    this->initial->setVal(mat[this->initial->getState()->getx()][this->initial->getState()->gety()]);

    this->goal->setVal(mat[this->goal->getState()->getx()][this->goal->getState()->gety()]);
 */

#endif //MILESTONE2_MATRIXSOLVER_H
