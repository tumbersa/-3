#pragma once
#include "Money.h"
class Bankomat
{
	int idnum;
	Money balance;
public:
	/*
	<����������� �� ���������>
	@param *this
	@return NULL
	*/
	Bankomat();
	/*
	<�����������>
	@param int idnum - ����� ���������
	@param long rub - ���������� ������
	@return NULL
	*/
	Bankomat(int idnum, long rub);
	/*
	<�����������>
	@param int idnum - ����� ���������
	@param long rub - ���������� ������
	@param unsigned char kop - ���������� ������
	@return NULL
	*/
	Bankomat(int idnum,long rub,unsigned char kop);
	/*
	<����������� �����������>
	@param Bankomat* this 
	@param Bankomat& ban - ������ �����������
	@return NULL
	*/
	Bankomat(const Bankomat& ban);
	/*
	<������ �������>
	@param Bankomat* this
	@param long rub - ���������� ������
	@param unsigned char kop - ���������� ������
	@return NULL
	*/
	void setBalance(long rub, unsigned char kop);
	/*
	<������ ������ ���������>
	@param Bankomat* this
	@param int idnum - ����� ���������
	@return NULL
	*/
	void setIdnum(int idnum);
	/*
	<����� �������������� � ������>
	@param *this
	@return string 
	*/
	string toString();
	/*
	<������������� �������� ������������>
	@param this
	@param Bankomat& money -  ������, � �������� *this �������������
	@return Bankomat 
	*/
	Bankomat& operator=(const Bankomat& money);
	/*
	<������������� �������� ��������>
	@param Bankomat this
	@param Money& money1 -  ������, ������� ������������ � this
	@return Bankomat (������ ������, � �������� ���������� ������, ���������� �����)
	*/
	Bankomat operator+(Money& money1);
	/*
	<������������� �������� ���������>
	@param Bankomat ban1
	@param Money& money1 -  ������, ������� ���������� �� ban1
	@return Bankomat (������ ������, � �������� ���������� ������, ���������� ��������)
	*/
	Bankomat operator-(Money& money1);
};

