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
	@param * this
	@param Bankomat* money -  ������, � �������� *this �������������
	@return Bankomat* 
	*/
	Bankomat* operator=(Bankomat* money);
	/*
	<������������� �������� ��������>
	@param Bankomat ban1
	@param double l -  ������, ������� ������������ � ban1
	@return Bankomat* (������ ������, � �������� ���������� ������, ���������� �����)
	*/
	friend Bankomat* operator+(Bankomat ban1, double l);
	/*
	<������������� �������� ���������>
	@param Bankomat ban1
	@param double l -  ������, ������� ���������� �� ban1
	@return Bankomat* (������ ������, � �������� ���������� ������, ���������� ��������)
	*/
	friend Bankomat* operator-(Bankomat ban1, double l);
};

