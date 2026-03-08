#include "Canvas.h"

int main() {
    Canvas c(20, 10);
    c.DrawRect(2, 2, 7, 7, '#');
    c.FillRect(10, 1, 15, 4, '*');

    c.Print();

    return 0;
}