#ifndef PACKAGE_H
#define PACKAGE_H
#include <iostream>
#include <string.h>

#include "../constantes.h"
using namespace std;

class Package
{
    private:    //data strage
        cbyte    message         [PACKAGE_SIZE];

        cbyte   mti             [MTI_SIZE];
        byte    pan             [PAN_SIZE];
        byte    exp_date        [EXP_DATE_SIZE];
        word    cvv2;
        cbyte   price           [PRICE_SIZE];
        word    currency;
        cbyte    date_operation [DATA_TIME_SIZE];
        cbyte    time_operation [DATA_TIME_SIZE];
        cbyte   card_holder     [CARD_HOLDER_SIZE];
        cbyte   msg             [MSG_SIZE];

        byte PANRealSize;
        byte CardHolderRealSize;

    public:
        Package();
        virtual ~Package();
        void Print();
        void SetParams(cbyte mti             [MTI_SIZE],
                       byte panSize,
                       byte *pan,
                       byte exp_date         [EXP_DATE_SIZE],
                       word cvv2,
                       cbyte price           [PRICE_SIZE],
                       word currency,
                       cbyte date_operation   [DATA_TIME_SIZE],
                       cbyte time_operation   [DATA_TIME_SIZE],
                       byte cardHolderSize,
                       cbyte card_holder     [CARD_HOLDER_SIZE],
                       cbyte msg             [MSG_SIZE]);
        byte *inPack();
        void readMessage(cbyte *message,byte size);
        void readMessage(Package &Pack);
    protected:
    private:
        int RealMessageSize;
};


#endif // PACKAGE_H

