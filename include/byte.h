#ifndef BYTE_H
#define BYTE_H
#include <string.h>

class byte
{
    private:
        unsigned char value;
    public:
        byte();
        byte(const int &i);
        byte(const byte &i);
        byte(const char &i);
        byte(const size_t &i);
        byte(const byte &b1,const byte &b2);
        //------------------------------------перегрузка операторов
        operator int();
        byte &operator=(const byte &b);
        byte *print(const char *str);
        byte getS();
        byte getM();
};

#endif // BYTE_H
