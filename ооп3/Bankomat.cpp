#include "Bankomat.h"
#include <vector>
Bankomat::Bankomat() {
	idnum = 0;
	balance.setKop(0);
	balance.setRub(0);
}

Bankomat::Bankomat(int idnum, long rub) {
	this->idnum = idnum;
	balance.setKop(0);
	balance.setRub(rub);
}

Bankomat::Bankomat(int idnum, long rub, unsigned char kop) {
	this->idnum = idnum;
	balance.setKop(kop);
	balance.setRub(rub);
}
Bankomat::Bankomat(const Bankomat& ban) {
    this->idnum=ban.idnum;
    this->balance = ban.balance;
};
void Bankomat::setBalance(long rub, unsigned char kop) {
	balance.setRub(rub);
	balance.setKop(kop);
}
 
void Bankomat::setIdnum(int idnum) {
    this->idnum = idnum;
}
Bankomat& Bankomat::operator=(const Bankomat& money) {
    idnum = money.idnum;
    balance = money.balance;
    return *this;
};


 Bankomat Bankomat::operator+(Money& money) {
    Bankomat b;
    if (money.getRub() >= 100 && money.getRub() <= 100000) {
        b.balance=balance + money;
    }
    else { 
        b.balance = balance;
        cout << "wrong amount"<<endl; }
    b.setIdnum(idnum);
    return b;
};

 Bankomat Bankomat::operator-(Money& money) {
     Bankomat b;
     if (money.getRub()>balance.getRub() || money.getRub()==balance.getRub() && money.getKop()<balance.getKop()) {
                 cout << "not enough money";
             }
             else if (money.getRub() >= 100 && money.getRub() <= 100000) {
                 b.balance =balance - money;
             }
             else {
         b.balance = balance;
         cout << "wrong amount" << endl;
            }
     b.setIdnum(idnum);
     return b;
 };


string Bankomat::toString() {
    string* units = new string[10]{ "ноль", "один", "два", "три", "четыре", "п€ть", "шесть", "семь", "восемь", "дев€ть" };
    string* unitsFem = new string[10]{ "ноль", "одна", "две", "три", "четыре", "п€ть", "шесть", "семь", "восемь", "дев€ть" };
    string* teens = new string[10]{ "дес€ть", "одиннадцать", "двенадцать", "тринадцать", "четырнадцать", "п€тнадцать", "шестнадцать", "семнадцать","восемнадцать", "дев€тнадцать" };
    string* dozens = new string[8]{ "двадцать", "тридцать", "сорок", "п€тьдес€т", "шестьдес€т", "семьдес€т", "восемьдес€т","дев€носто" };
    string* hundreds = new string[9]{ "сто", "двести", "триста", "четыресто", "п€тьсот", "шестьсот", "семьсот", "восемьсот","дев€тьсот" };
    string** matrix = new string * [5] {units, unitsFem, teens, dozens, hundreds};

    string strRub = "";
    string strKop = "";

    long rub = this->balance.getRub();
    long tempRub;
    unsigned char kop = this->balance.getKop();
    unsigned char tempKop;
    size_t size;

    vector<long> digits;

    do {
        tempRub = rub % 10;
        digits.insert(digits.begin(), tempRub);
        rub /= 10;
    } while (rub > 0);

    size = digits.size();

    for (int i = 0; i < digits.size(); i++) {

        if (size == 4) {
            strRub += matrix[1][digits[i]];

            if (digits[i] == 1) {
                strRub += " тыс€ча";
            }
            else if (digits[i] >= 2 && digits[i] <= 4) {
                strRub += " тыс€чи";
            }
            else if (digits[i] >= 5 && digits[i] <= 9) {
                strRub += " тыс€ч";
            }
        }
        else if (size == 3 || size == 6) {
            if (digits[i] != 0) {
                strRub += matrix[4][digits[i] - 1];
            }
        }
        else if (size == 2 || size == 5) {
            if (digits[i] >= 2) {
                strRub += matrix[3][digits[i] - 2];
            }
            else if (digits[i] == 1) {
                i++;
                strRub += matrix[2][digits[i]];

                if (size == 5) {
                    strRub += " тыс€ч";
                    size--;
                }
                else {
                    strRub += " рублей,";
                }
            }
        }
        else if (size == 1) {
            if (!(digits[i] == 0 && !strRub.empty())) {
                strRub += matrix[0][digits[i]];
            }
            if (digits[i] == 1) {
                strRub += " рубль,";
            }
            else if (digits[i] >= 2 && digits[i] <= 4) {
                strRub += " рубл€,";
            }
            else {
                strRub += " рублей,";
            }
        }
        strRub += " ";
        size--;
    }

    digits.clear();

    do {
        tempKop = kop % 10;
        digits.insert(digits.begin(), tempKop);
        kop /= 10;
    } while (kop > 0);

    size = digits.size();

    for (int i = 0; i < digits.size(); i++) {

        if (size == 2) {
            if (digits[i] >= 2) {
                strKop += matrix[3][digits[i] - 2];
            }
            else if (digits[i] == 1) {
                i++;
                strKop += matrix[2][digits[i]];

                strKop += " копеек";
            }
        }
        else if (size == 1) {
            if (!(digits[i] == 0 && !strKop.empty())) {
                strKop += matrix[1][digits[i]];
            }
            if (digits[i] == 1) {
                strKop += " копейка";
            }
            else if (digits[i] >= 2 && digits[i] <= 4) {
                strKop += " копейки";
            }
            else {
                strKop += " копеек";
            }
        }
        strKop += " ";
        size--;
    }
    return strRub + strKop;
}
