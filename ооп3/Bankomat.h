#pragma once
#include "Money.h"
class Bankomat
{
	int idnum;
	Money balance;
public:
	/*
	<Конструктор по умолчанию>
	@param *this
	@return NULL
	*/
	Bankomat();
	/*
	<Конструктор>
	@param int idnum - номер банкомата
	@param long rub - количество рублей
	@return NULL
	*/
	Bankomat(int idnum, long rub);
	/*
	<Конструктор>
	@param int idnum - номер банкомата
	@param long rub - количество рублей
	@param unsigned char kop - количество копеек
	@return NULL
	*/
	Bankomat(int idnum,long rub,unsigned char kop);
	/*
	<Сеттер баланса>
	@param Bankomat* this
	@param long rub - количество рублей
	@param unsigned char kop - количество копеек
	@return NULL
	*/
	void setBalance(long rub, unsigned char kop);
	/*
	<Сеттер номера банкомата>
	@param Bankomat* this
	@param int idnum - номер банкомата
	@return NULL
	*/
	void setIdnum(int idnum);
	/*
	<Метод преобразования в строку>
	@param *this
	@return string 
	*/
	string toString();
	/*
	<Перегруженный оператор присваивания>
	@param * this
	@param Bankomat* money -  объект, к которому *this присваивается
	@return Bankomat* 
	*/
	Bankomat* operator=(Bankomat* money);
	/*
	<Перегруженный оператор сложения>
	@param Bankomat ban1
	@param double l -  объект, который складывается с ban1
	@return Bankomat* (объект класса, к которому присвоится объект, содержащий сумму)
	*/
	friend Bankomat* operator+(Bankomat ban1, double l);
	/*
	<Перегруженный оператор вычитания>
	@param Bankomat ban1
	@param double l -  объект, который вычитается от ban1
	@return Bankomat* (объект класса, к которому присвоится объект, содержащий разность)
	*/
	friend Bankomat* operator-(Bankomat ban1, double l);
};

