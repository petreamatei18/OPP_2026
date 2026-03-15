#ifndef SORT_H
#define SORT_H

#include <initializer_list>

class Sort {
    int* lista;
    int numar_elemente;

public:
    Sort(int nr_elem, int minim, int maxim);
    Sort(std::initializer_list<int> l);
    Sort(int* vector, int nr_elem);
    Sort(int nr_elem, ...);
    Sort(const char* text);

    ~Sort();

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);

private:
    void QuickSortRecursiv(int stanga, int dreapta, bool ascendent);
};

#endif