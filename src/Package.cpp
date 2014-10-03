#include "..\include\Package.h"

Package::Package()
{
    RealMessageSize=0;
    PANRealSize=0;
    CardHolderRealSize=0;
}

Package::~Package()
{
    //dtor
}

void Package::Print()
{
    for (int i=0;i<RealMessageSize;i++)
        cout<<message[i];
    cout<<endl;
}

void Package::SetParams(cbyte mti[MTI_SIZE],byte panSize,byte *pan, byte exp_date[EXP_DATE_SIZE],
                       word cvv2, cbyte price[PRICE_SIZE], word currency,
                       cbyte date_operation[DATA_TIME_SIZE], cbyte time_operation[DATA_TIME_SIZE],
                       byte cardHolderSize, cbyte card_holder[CARD_HOLDER_SIZE],
                       cbyte msg[MSG_SIZE])
{

    memcpy(this->mti,              mti,            MTI_SIZE);
    this->PANRealSize=panSize;
    memcpy(this->pan,              pan,            panSize);
    memcpy(this->exp_date,         exp_date,       EXP_DATE_SIZE);
    this->cvv2=cvv2;
    memcpy(this->price,            price,          PRICE_SIZE);
    this->currency=currency;
    memcpy(this->date_operation,   date_operation, DATA_TIME_SIZE);
    memcpy(this->time_operation,   time_operation, DATA_TIME_SIZE);
    this->CardHolderRealSize=cardHolderSize;
    memcpy(this->card_holder,      card_holder,    cardHolderSize);
    memcpy(this->msg,              msg,            MSG_SIZE);
}
byte *Package::inPack()
{
    RealMessageSize=0;
    byte tmp;
    memcpy(message+RealMessageSize, mti, MTI_SIZE);                         RealMessageSize+=MTI_SIZE;
    memcpy(message+RealMessageSize, &PANRealSize, BYTE_SIZE);               RealMessageSize+=BYTE_SIZE;
    for(int i=0;i<PANRealSize/2;i++)
    {
        tmp=byte(pan[i*2],pan[i*2+1]);
        memcpy(message+RealMessageSize, &tmp, BYTE_SIZE);                   RealMessageSize+=BYTE_SIZE;
    }
    if (PANRealSize%2==1)
    {
        memcpy(message+RealMessageSize, &pan[PANRealSize-1], BYTE_SIZE);    RealMessageSize+=BYTE_SIZE;
    }
    memcpy(message+RealMessageSize, exp_date, EXP_DATE_SIZE);               RealMessageSize+=EXP_DATE_SIZE;
    memcpy(message+RealMessageSize, &cvv2, WORD_SIZE);                      RealMessageSize+=WORD_SIZE;
    memcpy(message+RealMessageSize, price, PRICE_SIZE);                     RealMessageSize+=PRICE_SIZE;
    memcpy(message+RealMessageSize, &currency, WORD_SIZE);                  RealMessageSize+=WORD_SIZE;
    memcpy(message+RealMessageSize, date_operation, DATA_TIME_SIZE);        RealMessageSize+=DATA_TIME_SIZE;
    memcpy(message+RealMessageSize, time_operation, DATA_TIME_SIZE);        RealMessageSize+=DATA_TIME_SIZE;
    memcpy(message+RealMessageSize, &CardHolderRealSize, BYTE_SIZE);        RealMessageSize+=BYTE_SIZE;
    memcpy(message+RealMessageSize, card_holder, CardHolderRealSize);       RealMessageSize+=CardHolderRealSize;
    memcpy(message+RealMessageSize, msg,MSG_SIZE);                          RealMessageSize+=MSG_SIZE;
}
void Package::readMessage(cbyte *message,byte size)
{
    cbyte *link;
    byte tmp;
    RealMessageSize=size;
    link=message;
    memcpy(this->message,message,size);
    memcpy(mti,link,MTI_SIZE);     link+=MTI_SIZE;
    memcpy(&PANRealSize,link, BYTE_SIZE);  link+=BYTE_SIZE;
    for(int i=0;i<PANRealSize/2;i++)
    {
        memcpy(&tmp, link, BYTE_SIZE);                   link+=BYTE_SIZE;
        pan[i*2]=tmp.getS();
        pan[i*2+1]=tmp.getM();
    }
    if (PANRealSize%2==1)
    {
        memcpy(&pan[PANRealSize-1],link, BYTE_SIZE);    link+=BYTE_SIZE;
    }
    memcpy(exp_date,link, EXP_DATE_SIZE);               link+=EXP_DATE_SIZE;
    memcpy(&cvv2,link, WORD_SIZE);                      link+=WORD_SIZE;
    memcpy(price,link, PRICE_SIZE);                     link+=PRICE_SIZE;
    memcpy(&currency,link, WORD_SIZE);                  link+=WORD_SIZE;
    memcpy(date_operation,link, DATA_TIME_SIZE);        link+=DATA_TIME_SIZE;
    memcpy(time_operation,link, DATA_TIME_SIZE);        link+=DATA_TIME_SIZE;
    memcpy(&CardHolderRealSize,link, BYTE_SIZE);        link+=BYTE_SIZE;
    memcpy(card_holder,link, CardHolderRealSize);       link+=CardHolderRealSize;
    memcpy(msg,link,MSG_SIZE);
}
void Package::readMessage(Package &Pack)
{
    readMessage(Pack.message,Pack.RealMessageSize);
}
