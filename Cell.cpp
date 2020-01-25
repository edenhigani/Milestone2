//
// Created by eden on 21/01/2020.
//

#include "Cell.h"

Cell::Cell(int x1, int y1){
    this->x = x1;
    this->y = y1;
}

Cell::Cell(std::string s){
char* cpy = new char[s.size()+1];
auto ss = s.c_str();
strcpy(cpy,ss);
string token = strtok(cpy,", \n");
this->x = stod(token);
token = strtok(NULL,", \n");
this->y = stod(token);
}
int Cell::gety(){
    return  this->y;
}
/*double Cell::getval(){
    return this->val;
}*/
void Cell::setx(int x1){
    this->x = x1;
}
void Cell::sety(int y1){
    this->y = y1;
}

int Cell::getx() {
    return this->x;
}
/*void Cell::setval(double val1){
    this->val = val1;
}*/