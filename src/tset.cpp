// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tset.cpp - Copyright (c) Гергель В.П. 04.10.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Множество - реализация через битовые поля

#include "tset.h"

TSet::TSet(int mp) : BitField(mp), MaxPower(mp){}  

// конструктор копирования
<<<<<<< HEAD
TSet::TSet(const TSet &s) : BitField(s.BitField), MaxPower(s.MaxPower) {} 
=======
TSet::TSet(const TSet &s) : BitField(-1)
{
	
}
>>>>>>> 49bd0c0081709a09fc43d7f800e0d6f1bf4c9cd4

// конструктор преобразования типа
TSet::TSet(const TBitField &bf) : BitField(bf), MaxPower (bf.GetLength()){}

TSet::operator TBitField()    
{
<<<<<<< HEAD
	TBitField temp = (TBitField)*this;
	return temp;
=======
	return TBitField(1);
>>>>>>> 49bd0c0081709a09fc43d7f800e0d6f1bf4c9cd4
}

int TSet::GetMaxPower(void) const // получить макс. к-во эл-тов
{
<<<<<<< HEAD
	return MaxPower;
=======
	return 0;
>>>>>>> 49bd0c0081709a09fc43d7f800e0d6f1bf4c9cd4
}

int TSet::IsMember(const int Elem) const // элемент множества?
{
	if (Elem < 0 || Elem >= MaxPower)
		throw "incorrect data";
	return BitField.GetBit(Elem);
}

void TSet::InsElem(const int Elem) // включение элемента множества
{
	if (Elem < 0 || Elem >= MaxPower)
		throw "incorrect data";
	BitField.SetBit(Elem);
}

void TSet::DelElem(const int Elem) // исключение элемента множества
{   
	if (Elem < 0 || Elem >= MaxPower)
		throw "incorrect data";
	BitField.ClrBit(Elem);
}

// теоретико-множественные операции

TSet& TSet::operator=(const TSet &s) // присваивание
{
<<<<<<< HEAD
	if (this != &s)
	{
		MaxPower = s.GetMaxPower();
		BitField = s.BitField;
	}
=======
>>>>>>> 49bd0c0081709a09fc43d7f800e0d6f1bf4c9cd4
	return *this;
}

int TSet::operator==(const TSet &s) const // сравнение
{
	return (BitField == s.BitField);
}

int TSet::operator!=(const TSet &s) const // сравнение
{
<<<<<<< HEAD
	if (MaxPower != s.MaxPower)
		return 1;
	else
		if (BitField != s.BitField)
			return 1;
=======
>>>>>>> 49bd0c0081709a09fc43d7f800e0d6f1bf4c9cd4
	return 0;
}

TSet TSet::operator+(const TSet &s) // объединение
{
<<<<<<< HEAD

	int len = MaxPower;
	if (s.MaxPower > MaxPower)
		len = s.MaxPower;
	TSet temp(len);
	temp.BitField = BitField | s.BitField;
	return temp;
=======
	return TSet(1);
>>>>>>> 49bd0c0081709a09fc43d7f800e0d6f1bf4c9cd4
}

TSet TSet::operator+(const int Elem) // объединение с элементом
{
<<<<<<< HEAD
	if ((Elem < 0) || (Elem >= MaxPower))
		throw "Incorrect data";
	BitField.SetBit(Elem);
	return *this;
=======
	return TSet(1);
>>>>>>> 49bd0c0081709a09fc43d7f800e0d6f1bf4c9cd4
}

TSet TSet::operator-(const int Elem) // разность с элементом
{
<<<<<<< HEAD
	if ((Elem < 0) || (Elem >= MaxPower))
		throw "Incorrect data";
	BitField.ClrBit(Elem);
	return *this;
=======
	return TSet(1);
>>>>>>> 49bd0c0081709a09fc43d7f800e0d6f1bf4c9cd4
}

TSet TSet::operator*(const TSet &s) // пересечение
{

<<<<<<< HEAD
	int len = MaxPower;
	if (s.MaxPower > MaxPower)
		len = s.MaxPower;
	TSet temp(len);
	temp = BitField & s.BitField;
	return temp;
=======
	return TSet(1);
>>>>>>> 49bd0c0081709a09fc43d7f800e0d6f1bf4c9cd4
}

TSet TSet::operator~(void) // дополнение
{
<<<<<<< HEAD
	TSet temp(*this);
	temp.BitField = ~temp.BitField;
	return temp;
=======
	return TSet(1);
>>>>>>> 49bd0c0081709a09fc43d7f800e0d6f1bf4c9cd4
}

// перегрузка ввода/вывода

<<<<<<< HEAD
istream &operator>>(istream &istr, TSet &s) // ввод  
{
	char h;
	int temp;
	do
	{
		istr >> h;
	} while (h != '{');
	do
	{
		istr >> temp;
		s.InsElem(temp);
		istr >> h;
	} while (h != '}');
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
=======
istream &operator>>(istream &istr, TSet &s) // ввод
{
	return istr;
}

ostream& operator<<(ostream &ostr, const TSet &s) // вывод
{
>>>>>>> 49bd0c0081709a09fc43d7f800e0d6f1bf4c9cd4
	return ostr;
}
