#pragma once

class Student
{
    char nume[100];
    float mate, eng, ist;

public:
    void SetNume(const char* n);
    const char* GetNume();

    void SetMate(float nota);
    float GetMate();

    void SetEngleza(float nota);
    float GetEngleza();

    void SetIstorie(float nota);
    float GetIstorie();

    float GetMedie();
};