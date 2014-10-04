#include "../include/Byte.h"

#define Byte_SIZE 1

Byte::Byte(){}
Byte::Byte(const int &i)
{
    value=i;
}
Byte::Byte(const Byte &i)
{
    value=i.value;
}
Byte::Byte(const Byte &b1,const Byte &b2)
{
    value=(b1.value<<4)+b2.value;
}
Byte::Byte(const char &i)
{
    value=i;
}
Byte::Byte(const size_t &i)
{
    value=i;
}
//------------------------------------перегрузка операторов
Byte::operator int()
{
    return (int)value;
}
Byte &Byte::operator=(const Byte &b)
{
    value=b.value;
    return *this;
}
Byte *Byte::print(const char *str)
{
    strcpy((char *)this,str);
    return this;
}
Byte Byte::getS()
{
    return (value>>4);
}
Byte Byte::getM()
{
    return value-((value>>4)<<4);
}
