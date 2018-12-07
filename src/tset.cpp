// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : bitField(mp)
{
	maxPower=mp;
}  

// конструктор копирования

TSet::TSet(const TSet &s) : bitField(s.bitField)
{
	maxPower=s.maxPower;
} 

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : bitField(bf)
{
	maxPower=bf.GetLength();
}

TSet::operator TBitField()    
{
	TBitField temp(this->bitField);
	return temp;
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
	return maxPower;
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	if (Elem < 0 || Elem >= maxPower)
	throw "incorrect data";
	return bitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	if (Elem < 0 || Elem >= maxPower)
	throw "incorrect data";
	bitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{   
	if (Elem < 0 || Elem >= maxPower)
	throw "incorrect data";
	bitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
	if (this != &s)
	{
		maxPower = s.GetMaxPower();
		bitField = s.bitField;
	}
	return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
	return (bitField == s.bitField);
}

int TSet::operator!=(const TSet &s) const // сравнение
{
	if (maxPower != s.maxPower) return 1;
	else
	if (bitField != s.bitField) return 1;
	return 0;
}

TSet TSet::operator+(const TSet &s) // объединение
{
	int len = maxPower;
	if (s.maxPower > maxPower)
	len = s.maxPower;
	TSet temp(len);
	temp.bitField = bitField | s.bitField;
	return temp;
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
	if ((Elem < 0) || (Elem >= maxPower))
	throw "Incorrect data";
	bitField.SetBit(Elem);
	return *this;
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
	if ((Elem < 0) || (Elem >= maxPower))
	throw "Incorrect data";
	bitField.ClrBit(Elem);
	return *this;
}

TSet TSet::operator*(const TSet &s) // пересечение
{

	int len = maxPower;
	if (s.maxPower > maxPower)
	len = s.maxPower;
	TSet temp(len);
	temp = bitField & s.bitField;
	return temp;
}

TSet TSet::operator~(void) // дополнение
{
	TSet temp=*this;
	temp.bitField = ~temp.bitField;
	return temp;
}

// перегрузка ввода/вывода

istream& operator>>(istream &istr, TSet &s) // ввод  
{
	char ch;
	int temp;
	do {istr >> ch;} while (ch != '{');
	do
	{
		istr >> temp;
		s.InsElem(temp);
		do 
		{ 
			istr >> ch; 
		} while ((ch!=',')&&(ch!='}'));
	} while (ch != '}');
	return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод 
{
	ostr << '{';
	for (int i = 0; i < s.GetMaxPower(); i++)
	{
		if (s.IsMember(i))
		ostr << i;
		ostr << ',';
	}
	ostr << '}';
	return ostr;
}
