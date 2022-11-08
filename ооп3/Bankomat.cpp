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

void Bankomat::setBalance(long rub, unsigned char kop) {
	balance.setRub(rub);
	balance.setKop(kop);
}
 
void Bankomat::setIdnum(int idnum) {
    this->idnum = idnum;
}
Bankomat* Bankomat::operator=(Bankomat* money) {
    balance.setRub(money->balance.getRub());
    balance.setKop(money->balance.getKop());
    return this;
};


 Bankomat* operator+(Bankomat ban1, double l) {
    Bankomat* b=new Bankomat;
    b->balance.setRub(ban1.balance.getRub());
    b->balance.setKop(ban1.balance.getKop());
    if (l >= 100 && l <= 100000) {
        Money mm((int)l, (l-(int)l) * 100);
        b->balance=ban1.balance + mm;
    }
    else cout << "wrong amount";
    return b;
};

Bankomat* operator-(Bankomat ban1, double l) {
    Bankomat* b = new Bankomat;
    b->balance.setRub(ban1.balance.getRub());
    b->balance.setKop(ban1.balance.getKop());
    if (l > ban1.balance.getRub() + ban1.balance.getKop() / 100) {
        cout << "not enough money";
    }
    else if (l >= 100 && l <= 100000) {
        Money mm((int)l, (l - (int)l) * 100);
        b->balance = ban1.balance - mm;
    }
    else cout << "wrong amount";
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
    int size;

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
