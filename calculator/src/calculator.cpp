#include "calculator.h"

int dev::add(int x, int y){
    return x + y;
}

int dev::mul(int x, int y){
    return x*y;
}


int dev::sub(int x, int y){
    return x - y;
}

double dev::div(int x, int y){
    if (y == 0){
        throw "Zero Division Error";
    }
    return static_cast<double>(x) / y;
}