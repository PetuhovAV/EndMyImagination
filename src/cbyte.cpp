#include "../include/cbyte.h"

#define cbyte_SIZE 1

cbyte::cbyte(){}
cbyte::cbyte(const int &i)
{
    value=i;
}
cbyte::cbyte(const cbyte &i)
{
    value=i.value;
}
cbyte::cbyte(const char &i)
{
    value=i;
}
//------------------------------------перегрузка операторов
cbyte::operator int()
{
    return (int)value;
}
cbyte &cbyte::operator=(const cbyte &b)
{
    value=b.value;
    return *this;
}
cbyte *cbyte::print(const char *str)
{
    strcpy((char *)this,str);
    return this;
}
