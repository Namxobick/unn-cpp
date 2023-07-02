// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле

#include "tbitfield.h"

TBitField::TBitField(int len) : BitLen(len)
{
	if (BitLen < 1) throw BitLen;
	unsigned int powerTwo = (int)(log2(sizeof(TELEM) * 8));
	MemLen = ((BitLen - 1) >> powerTwo) + 1;

	pMem = new TELEM[MemLen];
	if (pMem != nullptr)
		for (int i = 0; i < MemLen; i++)
			pMem[i] = 0;
}

TBitField::TBitField(const TBitField &bf) // конструктор копирования
{
	MemLen = bf.MemLen;
	BitLen = bf.BitLen;
	pMem = new TELEM[MemLen];
	if (pMem != nullptr)
		for (int i = 0; i < MemLen; i++) 
			pMem[i] = bf.pMem[i];
}

TBitField::~TBitField()
{
	delete[] pMem;
	pMem = nullptr;
	BitLen = 0;
	pMem = 0;
	MemLen = 0;
}

int TBitField::GetMemIndex(const int n) const // индекс Мем для бита n
{
	if (n < 0) throw n;
	return n >> (int)(log2(8 * sizeof(TELEM)));
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	if (n < 0) throw n;
	return 1 << (n & (sizeof(TELEM) * 8 - 1));
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return BitLen;
}

void TBitField::SetBit(const int n) // установить бит
{
	if (n < 0 || n >= BitLen) throw n;
	pMem[GetMemIndex(n)] |= GetMemMask(n);
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if (n < 0 || n >= BitLen) throw n;
	pMem[GetMemIndex(n)] &= ~GetMemMask(n);
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if (n < 0 || n >= BitLen) throw n;
	return (pMem[GetMemIndex(n)] & GetMemMask(n)) != 0;
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) // присваивание
{
	if (this == &bf) return *this;

	BitLen = bf.BitLen;
	if (MemLen != bf.MemLen)
	{
		MemLen = bf.MemLen;
		if (pMem != nullptr)
			delete[] pMem;
	}

	std::copy(bf.pMem, bf.pMem + bf.MemLen, pMem);

	return *this;
}

int TBitField::operator==(const TBitField &bf) const // сравнение
{
	if (BitLen != bf.BitLen) return false;
	
	for (int i = 0; i < MemLen; i++)
		if (pMem[i] != bf.pMem[i]) return false;

	return true;
}

int TBitField::operator!=(const TBitField &bf) const // сравнение
{
	return !(*this == bf);
}

TBitField TBitField::operator|(const TBitField &bf) // операция "или"
{

	int maxBitLen = std::max(BitLen, bf.BitLen);
	int minMemLen = std::min(MemLen, bf.MemLen);
	int maxMemLen = std::max(MemLen, bf.MemLen);
	TBitField result(maxBitLen);

	for (int i = 0; i < minMemLen; i++)
		result.pMem[i] = pMem[i] | bf.pMem[i];

	for (int i = minMemLen; i < maxMemLen; i++)
		result.pMem[i] = BitLen > bf.BitLen ? pMem[i] : bf.pMem[i];

	return result;
}

TBitField TBitField::operator&(const TBitField &bf) // операция "и"
{
	int maxBitLen = std::max(BitLen, bf.BitLen);
	int minMemLen = std::min(MemLen, bf.MemLen);
	TBitField result(maxBitLen);

	for (int i = 0; i < minMemLen; i++)
		result.pMem[i] = pMem[i] & bf.pMem[i];
	
	return result;
}

TBitField TBitField::operator~(void) // отрицание
{
	TBitField result(BitLen);
	for (int i = 0; i < BitLen; i++)
		GetBit(i) == 1 ? result.ClrBit(i) : result.SetBit(i);

	return result;
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{ 
	std::string str;
	istr >> str;
	bf = TBitField(str.length());
	for (int i = str.length() - 1; i > -1; i--)
		if (str[i] == '1') bf.SetBit(i);

	return istr;
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
	if (bf.pMem == nullptr) throw bf.pMem;

	for (int i = 0; i < bf.BitLen; i++)
		ostr << bf.GetBit(i);
	return ostr;
}
