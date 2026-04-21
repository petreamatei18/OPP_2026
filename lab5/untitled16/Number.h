#ifndef NUMBER_H
#define NUMBER_H

class Number {
    // Membri privați pentru stocarea stării obiectului
    char* value; // Reprezentarea sub formă de șir de caractere a valorii
    int base;    // Baza sistemului de numerație (2-16)

    // Metode helper pentru conversii interne
    long long ToDecimal() const;
    void FromDecimal(long long decimal, int targetBase);
    int CharToVal(char c) const;
    char ValToChar(int v) const;

public:
    // Constructori și destructor
    Number(const char* value, int base);
    Number(int value);
    ~Number();

    // Gestiunea resurselor: Copy Constructor și Copy Assignment
    Number(const Number& other);
    Number& operator=(const Number& other);

    // Gestiunea resurselor: Move Constructor și Move Assignment
    Number(Number&& other) noexcept;
    Number& operator=(Number&& other) noexcept;

    // Operatori de atribuire prin supraîncărcare
    Number& operator=(const char* val);
    Number& operator=(int val);

    // Operatorul de acces
    char operator[](int index) const;

    // Operatori aritmetici implementați prin funcții prieten
    friend Number operator+(const Number& n1, const Number& n2);
    friend Number operator-(const Number& n1, const Number& n2);
    Number& operator+=(const Number& other);

    // Operatori relaționali pentru compararea valorică
    bool operator>(const Number& other) const;
    bool operator<(const Number& other) const;
    bool operator>=(const Number& other) const;
    bool operator<=(const Number& other) const;
    bool operator==(const Number& other) const;

    // Operatori de decrementare
    Number& operator--();    // Prefix: elimină MSD
    Number operator--(int);  // Postfix: elimină LSD

    // Metode publice pentru manipularea și interogarea obiectului
    void SwitchBase(int newBase);
    void Print() const;
    int GetDigitsCount() const;
    int GetBase() const;
};

#endif