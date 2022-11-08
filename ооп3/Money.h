#include <iostream>
#include <string>

using namespace std;


class Money {
private:
    long rub;
    unsigned char kop;

public:
    /*
    <Конструктор по умолчанию>
    @param Money*this
    @return NULL
    */
    Money();
    /*
    <Конструктор>
    @param long rub - количество рублей
    @return NULL
    */
    Money(long rub);
    /*
    <Конструктор>
    @param long rub - количество рублей
    @param unsigned char kop - количество копеек
    @return NULL
    */
    Money(long rub, unsigned char kop);
    /*
    <Конструктор копирования>
    @param Money* this
    @param Money& money - объект класса, который используется для создания копии
    @return NULL
    */
    Money(Money& money);
    /*
    <Сеттер количества рублей>
    @param Money* this
    @param long rub - количество рублей
    @return NULL
    */
    void setRub(long rub);
    /*
   <Сеттер количества копеек>
   @param Money* this
   @param unsigned char kop - количество копеек
   @return NULL
   */
    void setKop(unsigned char kop);
    /*
    <Геттер количества рублей>
    @param Money* this
    @return long rub - количество рублей
    */
    long getRub();
    /*
    <Геттер количества копеек>
    @param Money* this
    @return unsigned char kop - количество копеек
    */
    int getKop();
    /*
    <Перегруженный оператор присваивания>
    @param Money* this
    @param Money* money -  объект, к которому *this присваивается
    @return Money*
    */
    Money* operator=(Money* money);
    /*
    <Перегруженный оператор суммы>
    @param Money money1 - слагаемое
    @param Money money2 - слагаемое
    @return Money* (объект класса, к которому присвоится объект, содержащий сумму)
    */
    friend Money* operator+(Money money1, Money money2);
    /*
    <Перегруженный оператор вычитания>
    @param Money money1 - уменьшаемое
    @param Money money2 - вычитаемое
    @return Money* (объект класса, к которому присвоится объект, содержащий разность)
    */
    friend Money* operator-(Money money1, Money money2);
    /*
    <Перегруженный оператор деления>
    @param Money money1 - числитель
    @param Money money2 - знаменатель
    @return double - частное
    */
    friend double operator/(Money money1, Money money2);
    /*
    <Перегруженный оператор деления>
    @param Money money1 - числитель
    @param double digit - знаменатель
    @return Money* - частное
    */
    friend Money* operator/(Money money1, double digit);
    /*
    <Перегруженный оператор умножения>
    @param Money money1 - множитель
    @param double digit - множитель
    @return Money* - произведение
    */
    friend Money* operator*(Money money1, double digit);
    /*
    <Перегруженный оператор равенства>
    @param Money money1
    @param Money money2 -  объект, с которым сравнивается *this
    @return bool (значение, показывающее результат логического оператора)
    */
    friend bool operator==(Money money1, Money money2);
    /*
    <Дружественный, перегруженный оператор вывода>
    @param ostream& os - поток, в который записываются данные
    @param  Money& corner -  объект, который который выводится на экран
    @return ostream& (ссылка на поток вывода ostream, для совместимости с другими операторами)
    */
    friend ostream& operator<<(ostream& os, Money& corner);
    /*
    <Дружественный, перегруженный оператор ввода>
    @param istream& is - поток, с которого осуществляется чтение
    @param Money& money -  объект, который вводится
    @return istream& (ссылка на поток ввода istream)
    */
    friend istream& operator>>(istream& in, Money& money);
};
