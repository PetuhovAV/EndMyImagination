#include <iostream>
#include "include/web.h"
#include "include/Package.h"
#include "functions.h"

#pragma comment(lib, "ws2_32.lib")

using namespace std;
int main()
{
    cByte    message         [PACKAGE_SIZE];

    cByte   mti             [MTI_SIZE+1]="0101";
    Byte    pan             [PAN_SIZE];
    Byte    exp_date        [EXP_DATE_SIZE];
    word    cvv2;
    cByte   price           [PRICE_SIZE+1]="54462";
    word    currency;
    cByte    date_operation  [DATA_TIME_SIZE+1]="010206";
    cByte    time_operation  [DATA_TIME_SIZE+1]="010203";
    cByte   card_holder     [CARD_HOLDER_SIZE+1]="Petuchov Alexey Vladimirovich";
    cByte   msg             [MSG_SIZE+1]="000";

    pan->print("123654");                       //костыльно но работает поленился разберать перегрузку типа как mti[MTI_SIZE+1]="0101"
    exp_date->print("☼↕");                      //зполнять так - alt+(циферки)
    cvv2=228;
    currency=258;


    Package p;
    p.SetParams(mti,12,pan,exp_date,cvv2,price,currency,date_operation,time_operation,
                strlen(card_holder),card_holder,msg);
    p.inPack();
    p.Print();

    p.readMessage(p);
    p.inPack();
    p.Print();
    return 0;
}
