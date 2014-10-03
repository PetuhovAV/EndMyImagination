#include "../include/word.h"

word::word(){}
word::word(const int &i)
{
    value=i;
}
word::word(const word &i)
{
    value=i.value;
}
word::word(const char &i)
{
    value=i;
}
//------------------------------------перегрузка операторов
word::operator int()
{
    return (int)value;
}
word &word::operator=(const word &b)
{
    value=b.value;
    return *this;
}
