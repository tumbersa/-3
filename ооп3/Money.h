#include <iostream>
#include <string>

using namespace std;


class Money {
private:
    long rub;
    unsigned char kop;

public:
    /*
    <����������� �� ���������>
    @param Money*this
    @return NULL
    */
    Money();
    /*
    <�����������>
    @param long rub - ���������� ������
    @return NULL
    */
    Money(long rub);
    /*
    <�����������>
    @param long rub - ���������� ������
    @param unsigned char kop - ���������� ������
    @return NULL
    */
    Money(long rub, unsigned char kop);
    /*
    <����������� �����������>
    @param Money* this
    @param Money& money - ������ ������, ������� ������������ ��� �������� �����
    @return NULL
    */
    Money(Money& money);
    /*
    <������ ���������� ������>
    @param Money* this
    @param long rub - ���������� ������
    @return NULL
    */
    void setRub(long rub);
    /*
   <������ ���������� ������>
   @param Money* this
   @param unsigned char kop - ���������� ������
   @return NULL
   */
    void setKop(unsigned char kop);
    /*
    <������ ���������� ������>
    @param Money* this
    @return long rub - ���������� ������
    */
    long getRub();
    /*
    <������ ���������� ������>
    @param Money* this
    @return unsigned char kop - ���������� ������
    */
    int getKop();
    /*
    <������������� �������� ������������>
    @param Money* this
    @param Money* money -  ������, � �������� *this �������������
    @return Money*
    */
    Money* operator=(Money* money);
    /*
    <������������� �������� �����>
    @param Money money1 - ���������
    @param Money money2 - ���������
    @return Money* (������ ������, � �������� ���������� ������, ���������� �����)
    */
    friend Money* operator+(Money money1, Money money2);
    /*
    <������������� �������� ���������>
    @param Money money1 - �����������
    @param Money money2 - ����������
    @return Money* (������ ������, � �������� ���������� ������, ���������� ��������)
    */
    friend Money* operator-(Money money1, Money money2);
    /*
    <������������� �������� �������>
    @param Money money1 - ���������
    @param Money money2 - �����������
    @return double - �������
    */
    friend double operator/(Money money1, Money money2);
    /*
    <������������� �������� �������>
    @param Money money1 - ���������
    @param double digit - �����������
    @return Money* - �������
    */
    friend Money* operator/(Money money1, double digit);
    /*
    <������������� �������� ���������>
    @param Money money1 - ���������
    @param double digit - ���������
    @return Money* - ������������
    */
    friend Money* operator*(Money money1, double digit);
    /*
    <������������� �������� ���������>
    @param Money money1
    @param Money money2 -  ������, � ������� ������������ *this
    @return bool (��������, ������������ ��������� ����������� ���������)
    */
    friend bool operator==(Money money1, Money money2);
    /*
    <�������������, ������������� �������� ������>
    @param ostream& os - �����, � ������� ������������ ������
    @param  Money& corner -  ������, ������� ������� ��������� �� �����
    @return ostream& (������ �� ����� ������ ostream, ��� ������������� � ������� �����������)
    */
    friend ostream& operator<<(ostream& os, Money& corner);
    /*
    <�������������, ������������� �������� �����>
    @param istream& is - �����, � �������� �������������� ������
    @param Money& money -  ������, ������� ��������
    @return istream& (������ �� ����� ����� istream)
    */
    friend istream& operator>>(istream& in, Money& money);
};
