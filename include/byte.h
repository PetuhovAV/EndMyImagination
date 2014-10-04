#ifndef Byte_H
#define Byte_H
#include <string.h>

class Byte
{
    private:
        unsigned char value;
    public:
        Byte();
        Byte(const int &i);
        Byte(const Byte &i);
        Byte(const char &i);
        Byte(const size_t &i);
        Byte(const Byte &b1,const Byte &b2);
        //------------------------------------перегрузка операторов
        operator int();
        Byte &operator=(const Byte &b);
        Byte *print(const char *str);
        Byte getS();
        Byte getM();
};

#endif // Byte_H
