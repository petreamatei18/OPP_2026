#include "Sort.h"
#include <iostream>
#include <cstdarg>
#include <ctime>
#include <cstdlib>
#include <cstring>

Sort::Sort(int nr_elem, int minim, int maxim) {
    this->numar_elemente = nr_elem;
    this->lista = new int[nr_elem];
    srand(time(0));
    for (int i = 0; i < nr_elem; i++) {
        this->lista[i] = minim + rand() % (maxim - minim + 1);
    }
}

Sort::Sort(std::initializer_list<int> l) {
    this->numar_elemente = l.size();
    this->lista =new int[this->numar_elemente];
    int i = 0;
    for (int x : l) {
        this->lista[i++] = x;
    }
}

Sort::Sort(int* vector, int nr_elem) {
    this->numar_elemente = nr_elem;
    this->lista = new int[nr_elem];
    for (int i = 0; i < nr_elem; i++) {
        this->lista[i] = vector[i];
    }
}

Sort::Sort(int nr_elem, ...) {
    this->numar_elemente = nr_elem;
    this->lista = new int[nr_elem];
    va_list args;
    va_start(args, nr_elem);
    for (int i = 0; i < nr_elem; i++) {
        this->lista[i] = va_arg(args, int);
    }
    va_end(args);
}

Sort::Sort(const char* text) {
    int n = 0;
    for (int i = 0; text[i]; i++) if (text[i] == ',') n++;
    this->numar_elemente = n + 1;
    this->lista = new int[this->numar_elemente];

    char copie[1000];
    strcpy(copie, text);
    char* p = strtok(copie, ",");
    int i = 0;
    while (p != nullptr) {
        this->lista[i++] = atoi(p);
        p = strtok(nullptr, ",");
    }
}

Sort::~Sort() {
    delete[] this->lista;
}

void Sort::Print() {
    for (int i = 0; i < this->numar_elemente; i++) {
        std::cout << this->lista[i] << " ";
    }
    std::cout << std::endl;
}

int Sort::GetElementsCount() {
    return this->numar_elemente;
}

int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < this->numar_elemente) return this->lista[index];
    return -1;
}

void Sort::BubbleSort(bool ascendent) {
    for (int i = 0; i < numar_elemente - 1; i++) {
        for (int j = 0; j < numar_elemente - i - 1; j++) {
            if (ascendent ? (lista[j] > lista[j + 1]) : (lista[j] < lista[j + 1])) {
                int aux = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = aux;
            }
        }
    }
}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < numar_elemente; i++) {
        int x = lista[i];
        int j = i - 1;
        while (j >= 0 && (ascendent ? (lista[j] > x) : (lista[j] < x))) {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = x;
    }
}

void Sort::QuickSort(bool ascendent) {
    QuickSortRecursiv(0, numar_elemente - 1, ascendent);
}

void Sort::QuickSortRecursiv(int stanga, int dreapta, bool ascendent) {
    if (stanga >= dreapta) return;
    int pivot = lista[stanga];
    int i = stanga, j = dreapta;
    while (i < j) {
        while (i <j && (ascendent ? (lista[j] >= pivot) : (lista[j] <= pivot))) j--;
        lista[i] =lista[j];
        while (i < j && (ascendent ? (lista[i] <= pivot) : (lista[i] >= pivot))) i++;
        lista[j] = lista[i];
    }
    lista[i] = pivot;
    QuickSortRecursiv(stanga, i - 1, ascendent);
    QuickSortRecursiv(i + 1, dreapta, ascendent);
}