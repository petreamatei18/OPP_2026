#include "Student.h"
#include <cstring>

void Student::SetNume(const char* n)
{
    strcpy(this->nume, n);
}
const char* Student::GetNume()
{
    return this->nume;
}
void Student::SetMate(float nota)
{
    this->mate = nota;
}
float Student::GetMate()
{
    return this->mate;
}
void Student::SetEngleza(float nota)
{
    this->eng = nota;
}
float Student::GetEngleza()
{
    return this->eng;
}
void Student::SetIstorie(float nota)
{
    this->ist = nota;
}
float Student::GetIstorie()
{
    return this->ist;
}
float Student::GetMedie()
{
    return (this->mate + this->eng + this->ist) / 3.0f;
}