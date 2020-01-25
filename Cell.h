//
// Created by eden on 21/01/2020.
//

#ifndef MILESTONE2_CELL_H
#define MILESTONE2_CELL_H

#include <string>
#include <string.h>
using namespace std;
class Cell {
private:
    int x;
    int y;
    //double val;
public:
    Cell(int x1, int y1);
    Cell(std::string s);
    Cell(){

    }
    int getx();
    int gety();
    //double getval();
    void setx(int x1);
    void sety(int y1);
    //void setval(double val1);
    bool operator==(Cell otherCell) {
        return ((this->getx() == otherCell.getx()) && (this->gety() == otherCell.gety()));
    }
    bool operator!=(Cell otherCell) {
        return ((this->getx() != otherCell.getx()) || (this->gety() != otherCell.gety()));
    }
};


#endif //MILESTONE2_CELL_H
