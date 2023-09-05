#ifndef _BIGINT_H
#define _BIGINT_H
#include <iostream>
#define null -1
class BigInt{
public:
    BigInt();
    BigInt(int x0);
    BigInt(int x0 , int x1);
    BigInt(int x0 , int x1 , int x2);
    BigInt(int x0 , int x1 , int x2 , int x3);
    BigInt(int x0 , int x1 , int x2 , int x3 , int x4);
    BigInt operator+(const BigInt &bigInt);
    BigInt operator-(const BigInt &bigInt);
    bool operator<(const BigInt &bigInt);
    bool operator<=(const BigInt &bigInt);
    bool operator>(const BigInt &bigInt);
    bool operator>=(const BigInt &bigInt);
    bool operator==(const BigInt &bigInt);
    bool operator!=(const BigInt &bigInt);

    friend std::ostream & operator<<(std::ostream &os , const BigInt &bigInt);
    friend std::istream & operator>>(std::istream &is , BigInt &bigInt);

private:
    int number[5] = {0 , 0 , 0 , 0 , 0};
};

std::istream & operator>>(std::istream &is , const BigInt &bigInt);
std::ostream & operator<<(std::ostream &os , const BigInt &bigInt);

#endif