#include "Math.h"
#include <cstring>

int Math::Add(int a, int b) { return a + b; }
int Math::Add(int a, int b, int c) { return a + b + c; }
int Math::Add(double a, double b) { return (int)(a + b); }
int Math::Add(double a, double b, double c) { return (int)(a + b + c); }
int Math::Mul(int a, int b) { return a * b; }
int Math::Mul(int a, int b, int c) { return a * b * c; }
int Math::Mul(double a, double b) { return (int)(a * b); }
int Math::Mul(double a, double b, double c) { return (int)(a * b * c); }

int Math::Add(int count, int* numbers) {
    if (!numbers) return 0;
    int s = 0;
    for (int i = 0; i < count; i++) s += numbers[i];
    return s;
}

char* Math::Add(const char* s1, const char* s2) {
    if (!s1 || !s2) return nullptr;
    char* rez = new char[strlen(s1) + strlen(s2) + 1];
    strcpy(rez, s1);
    strcat(rez, s2);
    return rez;
}