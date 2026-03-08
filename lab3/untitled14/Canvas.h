#pragma once
#include <cstdio>
#include <cstring>
class Canvas {
private:
    int width, height;
    char** matrix;
public:
    Canvas(int width,int height);
    ~Canvas();
    bool SetPoint(int x, int y, char ch);
    void DrawRect(int left,int top, int right, int bottom, char ch);
    void FillRect(int left,int top, int right, int bottom, char ch);

    void Print();
    void Clear();
    void DrawCircle(int x,int y, int ray, char ch) {}
    void FillCircle(int x,int y, int ray, char ch) {}
    void DrawLine(int x1,int y1, int x2, int y2, char ch) {}
};