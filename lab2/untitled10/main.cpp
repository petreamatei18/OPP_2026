#include "NumberList.h"
int main()
{
    NumberList n;
    n.Init();
    n.Add(10);
    n.Add(2);
    n.Add(8);
    n.Add(1);
    n.Add(5);
    n.Add(100);
    n.Add(20);
    n.Add(0);
    n.Add(7);
    n.Add(45);
    n.Add(999);
    n.Sort();
    n.Print();
    return 0;
}