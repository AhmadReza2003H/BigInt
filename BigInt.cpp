#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
#include "BigInt.h"
std::ostream & operator<<(std::ostream &os , const BigInt &bigInt){
    // bool isPrinting = false;
    // for(int i = 4 ; i >= 0 ; i--){
    //     if(!isPrinting && bigInt.number[i] != 0){
    //         isPrinting = true;
    //         os << bigInt.number[i];
    //     } else if(isPrinting){
    //     os << std::setfill('0') << std::setw(9) << bigInt.number[i];
    //     }
    // }
    // if(!isPrinting){
    //     os << 0;
    // }
   int firstNoneZero = 4;
    while (firstNoneZero >= 0 && bigInt.number[firstNoneZero] == 0) {
        firstNoneZero--;
    }

    if (firstNoneZero < 0) {
        os << 0;
    } else{
        os << bigInt.number[firstNoneZero];
        for(int i = firstNoneZero -1 ; i >= 0 ; i--){
            os << std::setfill('0') << std::setw(9) << bigInt.number[i];
        }
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
bool BigInt::operator==(const BigInt &bigInt){
    for(int i = 0 ; i < 5 ; i++){
        if(this->number[i] != bigInt.number[i]){
            return false;
        }
    }
    return true;
}
bool BigInt::operator!=(const BigInt &bigInt){
        for(int i = 0 ; i < 5 ; i++){
        if(this->number[i] != bigInt.number[i]){
            return true;
        }
    }
    return false;
}
bool BigInt::operator<(const BigInt &bigInt){
    for (int i = 4; i >= 0; i--) {
        if (this->number[i] < bigInt.number[i]) {
            return true; 
        } else if (this->number[i] > bigInt.number[i]) {
            return false; 
        }
    }
    return false; 
}
bool BigInt::operator<=(const BigInt &bigInt){
    for (int i = 4; i >= 0; i--) {
        if(this->number[i] == bigInt.number[i]){
            continue;
        } else if (this->number[i] < bigInt.number[i]) {
            return true; 
        } else {
            return false; 
        }
    }
    return true;
}
bool BigInt::operator>(const BigInt &bigInt){
    for (int i = 4; i >= 0; i--) {
        if (this->number[i] > bigInt.number[i]) {
            return true; 
        } else if (this->number[i] < bigInt.number[i]) {
            return false; 
        }
    }
    return true; 
}
bool BigInt::operator>=(const BigInt &bigInt){
        for (int i = 4; i >= 0; i--) {
        if(this->number[i] == bigInt.number[i]){
            continue;
        } else if (this->number[i] > bigInt.number[i]) {
            return true; 
        } else {
            return false; 
        }
    }
    return true;
}
BigInt BigInt::operator+(const BigInt &bigInt){
    BigInt returnBigInt;
    for(int i = 0 ; i < 5 ; i++){
        returnBigInt.number[i] += this->number[i] + bigInt.number[i];
        if(returnBigInt.number[i] >= pow(10 , 9)){
            if(i == 4){
                throw "out of range";
            }
            returnBigInt.number[i+1]++;
            returnBigInt.number[i] -= pow(10,9);
        } 
    }
    return returnBigInt;
}
BigInt BigInt::operator-(const BigInt &bigInt){
    BigInt returnBigInt;
    for(int i = 0 ; i < 5 ; i++){
        returnBigInt.number[i] += this->number[i] - bigInt.number[i];
        if(returnBigInt.number[i] < 0 ){
            if(i == 4){
                throw "out of range";
            }
            returnBigInt.number[i+1]--;
            returnBigInt.number[i] += pow(10,9);
        } 
    }
    return returnBigInt;
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

