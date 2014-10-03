#include "../include/byte.h"

#define BYTE_SIZE 1

byte::byte(){}
byte::byte(const int &i)
{
    value=i;
}
byte::byte(const byte &i)
{
    value=i.value;
}
byte::byte(const byte &b1,const byte &b2)
{
    value=(b1.value<<4)+b2.value;
}
byte::byte(const char &i)
{
    value=i;
}
byte::byte(const size_t &i)
{
    value=i;
}
//------------------------------------перегрузка операторов
byte::operator int()
{
    return (int)value;
}
byte &byte::operator=(const byte &b)
{
    value=b.value;
    return *this;
}
byte *byte::print(const char *str)
{
    strcpy((char *)this,str);
    return this;
}
byte byte::getS()
{
    return (value>>4);
}
byte byte::getM()
{
    return value-((value>>4)<<4);
}
