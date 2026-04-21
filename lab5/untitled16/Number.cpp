#include "Number.h"
#include <iostream>
#include <cstring>
#include <cstdio>

// Conversia caracterului ASCII în valoare întreagă corespunzătoare
int Number::CharToVal(char c) const {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    return 0;
}

// Conversia valorii întregi în caracter ASCII (0-9, A-F)
char Number::ValToChar(int v) const {
    if (v >= 0 && v <= 9) return v + '0';
    return (v - 10) + 'A';
}

// Evaluarea valorii numerice în baza 10
long long Number::ToDecimal() const {
    long long res = 0;
    long long p = 1;
    int len = (int)strlen(value);
    for (int i = len - 1; i >= 0; i--) {
        res += (long long)CharToVal(value[i]) * p;
        p *= base;
    }
    return res;
}

// Reconstrucția șirului de caractere pornind de la o valoare zecimală și o bază țintă
void Number::FromDecimal(long long decimal, int targetBase) {
    char temp[128];
    int idx = 0;
    if (decimal == 0) temp[idx++] = '0';
    while (decimal > 0) {
        temp[idx++] = ValToChar(decimal % targetBase);
        decimal /= targetBase;
    }
    delete[] value; // Eliberarea memoriei curente pentru realocare
    value = new char[idx + 1];
    for (int i = 0; i < idx; i++) value[i] = temp[idx - i - 1];
    value[idx] = '\0';
    base = targetBase;
}

Number::Number(const char* val, int b) : base(b) {
    value = new char[strlen(val) + 1];
    strcpy(value, val);
}

Number::Number(int val) : base(10) {
    value = nullptr; 
    FromDecimal(val, 10);
}

Number::~Number() { 
    delete[] value; 
}

// Copy Constructor: Realizează Deep Copy pentru membrul value
Number::Number(const Number& other) : base(other.base) {
    value = new char[strlen(other.value) + 1];
    strcpy(value, other.value);
}

// Copy Assignment Operator: Evită auto-atribuirea și gestionează memoria
Number& Number::operator=(const Number& other) {
    if (this != &other) {
        delete[] value;
        base = other.base;
        value = new char[strlen(other.value) + 1];
        strcpy(value, other.value);
    }
    return *this;
}

// Move Constructor: Transferă proprietatea resurselor fără alocare suplimentară
Number::Number(Number&& other) noexcept : value(other.value), base(other.base) {
    other.value = nullptr;
}

// Move Assignment Operator: Transfer eficient al resurselor între instanțe
Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        delete[] value;
        value = other.value;
        base = other.base;
        other.value = nullptr;
    }
    return *this;
}

Number& Number::operator=(const char* val) {
    delete[] value;
    value = new char[strlen(val) + 1];
    strcpy(value, val);
    return *this;
}

Number& Number::operator=(int val) {
    FromDecimal(val, base);
    return *this;
}

char Number::operator[](int index) const { 
    return value[index]; 
}

// Adunarea a două obiecte Number: rezultatul adoptă baza maximă a operanzilor
Number operator+(const Number& n1, const Number& n2) {
    int resBase = (n1.base > n2.base) ? n1.base : n2.base;
    Number res(n1);
    res.FromDecimal(n1.ToDecimal() + n2.ToDecimal(), resBase);
    return res;
}

// Scăderea a două obiecte Number
Number operator-(const Number& n1, const Number& n2) {
    int resBase = (n1.base > n2.base) ? n1.base : n2.base;
    Number res(n1);
    res.FromDecimal(n1.ToDecimal() - n2.ToDecimal(), resBase);
    return res;
}

Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}

// Implementarea operatorilor relaționali prin conversie intermediară la baza 10
bool Number::operator>(const Number& other) const { return this->ToDecimal() > other.ToDecimal(); }
bool Number::operator<(const Number& other) const { return this->ToDecimal() < other.ToDecimal(); }
bool Number::operator==(const Number& other) const { return this->ToDecimal() == other.ToDecimal(); }

// Prefix --: Elimină prima cifră prin translatarea memoriei
Number& Number::operator--() { 
    if (value && strlen(value) > 0) {
        memmove(value, value + 1, strlen(value));
    }
    return *this;
}

// Postfix --: Elimină ultima cifră prin inserarea terminatorului nul
Number Number::operator--(int) { 
    Number temp(*this);
    if (value && strlen(value) > 0) {
        value[strlen(value) - 1] = '\0';
    }
    return temp;
}

void Number::SwitchBase(int newBase) { FromDecimal(ToDecimal(), newBase); }
void Number::Print() const { printf("%s (Baza %d)\n", value, base); }
int Number::GetDigitsCount() const { return (int)strlen(value); }
int Number::GetBase() const { return base; }