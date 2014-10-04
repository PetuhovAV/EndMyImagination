#ifndef PACKAGE_H
#define PACKAGE_H
#include <iostream>
#include <string.h>

#include "../constantes.h"
using namespace std;

class Package
{
    private:    //data strage
        cByte    message         [PACKAGE_SIZE];

        cByte   mti             [MTI_SIZE];
        Byte    pan             [PAN_SIZE];
        Byte    exp_date        [EXP_DATE_SIZE];
        word    cvv2;
        cByte   price           [PRICE_SIZE];
        word    currency;
        cByte    date_operation [DATA_TIME_SIZE];
        cByte    time_operation [DATA_TIME_SIZE];
        cByte   card_holder     [CARD_HOLDER_SIZE];
        cByte   msg             [MSG_SIZE];

        Byte PANRealSize;
        Byte CardHolderRealSize;

    public:
        Package();
        virtual ~Package();
        void Print();
        void SetParams(cByte mti             [MTI_SIZE],
                       Byte panSize,
                       Byte *pan,
                       Byte exp_date         [EXP_DATE_SIZE],
                       word cvv2,
                       cByte price           [PRICE_SIZE],
                       word currency,
                       cByte date_operation   [DATA_TIME_SIZE],
                       cByte time_operation   [DATA_TIME_SIZE],
                       Byte cardHolderSize,
                       cByte card_holder     [CARD_HOLDER_SIZE],
                       cByte msg             [MSG_SIZE]);
        Byte *inPack();
        void readMessage(cByte *message,Byte size);
        void readMessage(Package &Pack);
    protected:
    private:
        int RealMessageSize;
};


#endif // PACKAGE_H

