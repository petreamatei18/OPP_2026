#include "Sort.h"
#include <iostream>

int main() {
    Sort s1(5, 10, 50);
    s1.BubbleSort(true);
    std::cout <<"Random (Bubble): ";
    s1.Print();

    Sort s2({5, 1, 9, 3});
    s2.InsertSort(true);
    std::cout <<"Init List (Insert): ";
    s2.Print();

    int v[]={10, 40, 20};
    Sort s3(v,3);
    s3.QuickSort(false);
    std::cout <<"Vector (Quick desc): ";
    s3.Print();

    Sort s4(4, 7, 2, 9, 1);
    s4.BubbleSort(true);
    std::cout<<"Variadic: ";
    s4.Print();

    Sort s5("10,40,100,5,70");
    std::cout<<"String initial: ";
    s5.Print();
    std::cout<<"Element index 2: " << s5.GetElementFromIndex(2) << std::endl;

    return 0;
}