#include "Money.h"
#include <iostream>


using namespace std;

Money::Money() {
    rub = 0;
    kop = 0;
}

Money::Money(long rub) {

    if (rub >= 0) {
        this->rub = rub;
    }
    else {
        this->rub = 0;
    }
    kop = 0;
}

Money::Money(long rub, unsigned char kop) {
    if (rub >= 0) {
        this->rub = rub;
    }
    else {
        this->rub = 0;
    }

    if (kop >= 0) {
        if (kop >= 100) {
            this->rub += kop / 100;
        }
        this->kop = kop % 100;
    }
    else {
        this->kop = 0;
    }
}

void Money::setRub(long rub) {
    if (rub >= 0) {
        this->rub = rub;
    }
}

void Money::setKop(unsigned char kop) {

    if (kop >= 0) {
        if (kop >= 100) {
            this->rub = kop / 100;
        }
        this->kop = kop % 100;
    }
}

long Money::getRub() {
    return rub;
}

int Money::getKop() {
    return (int)kop;
}

Money::Money(Money& money) {
    this->rub = money.getRub();
    this->kop = money.getKop();
}


Money* Money::operator=(Money* money) {
    setRub(money->getRub());
    setKop(money->getKop());
    return this;
}

Money* Money::operator+(Money& money1) {
    Money* money = new Money(money1.getRub() + getRub(), money1.getKop() + getKop());

    if (money->getKop() >= 100) {
        money->setRub(money->getRub() + 1);
        money->setKop(money->getKop() - 100);
    }

    return money;
}


Money* Money::operator-(Money& money1) {
    Money* money = new Money;
    long tempMoney;

    tempMoney = (getRub() * 100 + getKop()) - (money1.getRub() * 100 + money1.getKop());

    if (tempMoney > 0) {
        money->setRub(tempMoney / 100);
        money->setKop(tempMoney % 100);
    }
    else {
        money->setRub(0);
        money->setKop(0);
    }

    return money;
}



bool Money::operator==(Money& money1) {
    if (getRub() == money1.getRub() && getKop() == money1.getKop()) {
        return true;
    }
    else {
        return false;
    }
}

ostream& operator<<(ostream& os, Money& money) {
    return os << money.getRub() << ',' << money.getKop();
}

istream& operator>>(istream& in, Money& money)
{
    long rub;
    unsigned char kop;

    in >> rub >> kop;

    money.setRub(rub);
    money.setKop(kop);

    return in;
}
