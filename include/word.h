#ifndef WORD_H
#define WORD_H


class word
{
    private:
        unsigned char value;
    public:
        word();
        word(const int &i);
        word(const word &i);
        word(const char &i);
        //------------------------------------���������� ����������
        operator int();
        word &operator=(const word &b);
};

#endif // WORD_H
