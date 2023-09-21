#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include "BigInt.h"

#define EQUAL 0
#define GREATER 1
#define SMALLER -1
#define ADD 1
#define SUB -1

std::ostream & operator<<(std::ostream &os , const BigInt &bigInt){
    bool isPrinting = false;
    for(int i = 4 ; i >= 0 ; i--){
        if(!isPrinting && bigInt.number[i] != 0){
            isPrinting = true;
        } else if(isPrinting){
            os << std::setfill('0') << std::setw(9);
        }
        if(isPrinting){
            os << bigInt.number[i];
        }
    }
    if(!isPrinting){
        os << 0;
    }
    return os;
}

std::istream & operator>>(std::istream &is , BigInt &bigInt){
    std::string number;
    is >> number;
    int length = number.length();
    int partCount = ceil(length / 9.0);
    for (int i = 0; i < partCount; ++i) {
        int endIndex = length - i * 9;
        int startIndex = std::max(endIndex - 9, 0);
        bigInt.number[i] = std::stoi(number.substr(startIndex, endIndex - startIndex));
    }
    return is;
}

bool BigInt::operator==(const BigInt &bigInt) const {
    return (this->compare(bigInt) == EQUAL);
}

bool BigInt::operator!=(const BigInt &bigInt) const {
    return (this->compare(bigInt) != EQUAL);
}

bool BigInt::operator<(const BigInt &bigInt) const {
    return (this->compare(bigInt) == SMALLER);
}

bool BigInt::operator<=(const BigInt &bigInt) const {
    int compare = this->compare(bigInt);
    return (compare == EQUAL || compare == SMALLER);
}

bool BigInt::operator>(const BigInt &bigInt)const { 
    return (this->compare(bigInt) == GREATER);
}

bool BigInt::operator>=(const BigInt &bigInt) const {
    int compare = this->compare(bigInt);
    return (compare == EQUAL || compare == GREATER);
}

BigInt BigInt::operator+(const BigInt &bigInt) {
    return this->plusMinusOps(bigInt , ADD);
}

BigInt BigInt::operator-(const BigInt &bigInt) {
    return this->plusMinusOps(bigInt , SUB);
}

BigInt BigInt::plusMinusOps(const BigInt &bigInt , int operation){
    BigInt returnBigInt;
    for(int i = 0 ; i < 5 ; i++){
        returnBigInt.number[i] += this->number[i] + (bigInt.number[i] * operation );
        if(returnBigInt.number[i] < 0 || returnBigInt.number[i] >= pow(10 , 9)){
            if(i == 4){
                throw "out of range";
            }
            returnBigInt.number[i+1] += operation;
            returnBigInt.number[i] += pow(10,9)*(operation*(-1));
        } 
    }
    return returnBigInt;
}

int BigInt::compare(const BigInt & bigInt) const {
    for (int i = 4; i >= 0; i--) {
        if(this->number[i] == bigInt.number[i]){
            continue;
        } else if (this->number[i] > bigInt.number[i]) {
            return GREATER; 
        } else {
            return SMALLER; 
        }
    }
    return EQUAL;
}

BigInt::BigInt(){
    
}

BigInt::BigInt(int x0){
    this->number[0] = x0;
}

BigInt::BigInt(int x0 , int x1){
    this->number[0] = x0;
    this->number[1] = x1;
}

BigInt::BigInt(int x0 , int x1 , int x2){
    this->number[0] = x0;
    this->number[1] = x1;
    this->number[2] = x2;
}

BigInt::BigInt(int x0 , int x1 , int x2 , int x3){
    this->number[0] = x0;
    this->number[1] = x1;
    this->number[2] = x2;
    this->number[3] = x3;
}

BigInt::BigInt(int x0 , int x1 , int x2 , int x3 , int x4){
    this->number[0] = x0;
    this->number[1] = x1;
    this->number[2] = x2;
    this->number[3] = x3;
    this->number[4] = x4;
}

