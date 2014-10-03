#include <iostream>
#include "include/Package.h"
#include "functions.h"
using namespace std;
int main()
{
    cbyte    message         [PACKAGE_SIZE];

    cbyte   mti             [MTI_SIZE+1]="0101";
    byte    pan             [PAN_SIZE];
    byte    exp_date        [EXP_DATE_SIZE];
    word    cvv2;
    cbyte   price           [PRICE_SIZE+1]="54462";
    word    currency;
    cbyte    date_operation  [DATA_TIME_SIZE+1]="010206";
    cbyte    time_operation  [DATA_TIME_SIZE+1]="010203";
    cbyte   card_holder     [CARD_HOLDER_SIZE+1]="Petuchov Alexey Vladimirovich";
    cbyte   msg             [MSG_SIZE+1]="000";

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
