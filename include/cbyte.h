#ifndef Ccbyte_H
#define Ccbyte_H
#include <string.h>

class cbyte
{
    private:
        unsigned char value;
    public:
        cbyte();
        cbyte(const int &i);
        cbyte(const cbyte &i);
        cbyte(const char &i);
        //------------------------------------перегрузка операторов
        operator int();
        cbyte &operator=(const cbyte &b);
        cbyte *print(const char *str);
};

#endif // cbyte_H
