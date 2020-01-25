//
// Created by eden on 21/01/2020.
//

#include "Matrix.h"

//template <typename T>
//Matrix::Matrix(State<Cell> *initial1, State<Cell> *goal1, std::vector<std::vector<double>> mat1, int size1) {
Matrix::Matrix(State<Cell> *initial1,State<Cell> *goal1,std::vector<std::vector<State<Cell>*>> mat1, int size1){
    this->initial = initial1;
    this->goal = goal1;
    this->mat = mat1;
    this->size = size1;
}

//Matrix::Matrix(std::vector<std::string> vec) {
//}

State<Cell> *Matrix::getInitialState() {
    return this->initial;
}


State<Cell> *Matrix::getGoalState() {
    return this->goal;
}


std::vector<State<Cell> *> Matrix::getAllPossibleStates(State<Cell> *state1) {
    std::vector<State<Cell> *> neighbors;
    int n = this->size;
    int y = state1->getState()->gety();
    int x = state1->getState()->getx();

    if (x - 1 >= 0 && this->mat[x - 1][y]->getVal() >= 0) {
        neighbors.push_back(this->mat[x - 1][y]); // Up
    }

    if (y + 1 < size && this->mat[x][y+1]->getVal() >= 0) {
        neighbors.push_back(this->mat[x][y + 1]); // Right
    }

    if (x + 1 < size && this->mat[x + 1][y]->getVal() >= 0) {
        neighbors.push_back(this->mat[x + 1][y]); // Down
    }

    if (y - 1 >= 0 && this->mat[x][y - 1]->getVal() >= 0) {
        neighbors.push_back(this->mat[x][y - 1]); // Left
    }

    return neighbors;
}

/*vector<State<Cell> *> Matrix::getPath(State<Cell> *state1) {
    vector<State<Cell> *> path;
    State<Cell> *currState = this->getGoalState();
    while (currState->getState() != this->getInitialState()->getState()) {
        // insert the state to the vector
        path.insert(path.begin(), currState);
        currState = currState->getCameFrom();
    }
    return path;
}

string traceback(vector<State<Cell>*> path){
    State<Cell> *curr = path.back(); //goal?
    State<Cell> *prev = curr->getCameFrom();
    string res;

    while (prev != nullptr) {
        Cell* currPos = curr->getState();
        Cell* prevPos = prev->getState();
        if (currPos->getx() == prevPos->getx() + 1) {
            res.insert(0, ",down");
        } else if (currPos->getx() == prevPos->getx() - 1) {
            res.insert(0, ",up");
        } else if (currPos->gety() == prevPos->gety() - 1) {
            res.insert(0, ",left");
        } else if (currPos->gety() == prevPos->gety() + 1) {
            res.insert(0, ",right");
        }
        curr = prev;
        prev = curr->getCameFrom();
    }

    res.erase(0, 1);
    return res;
}*/





