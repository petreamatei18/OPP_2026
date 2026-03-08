#include "Canvas.h"

Canvas::Canvas(int width, int height) {
    printf("Canvas::Canvas\n");
    this->width = width;
    this->height = height;
    this->matrix = new char* [this->height];
    for (int i=0;i<this->height; i++) {
        this->matrix[i]=new char[this->width];
        memset(this->matrix[i], ' ', this->width);
    }
}
bool Canvas::SetPoint(int x, int y, char ch) {
    if (x >=this->height || x < 0)
        return false;
    if (y >=this->width || y < 0)
        return false;
    this->matrix[x][y] = ch;
    return true;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int j=left; j<=right;j++) {
        SetPoint(top, j, ch);
        SetPoint(bottom, j, ch);
    }
    for (int i = top; i <= bottom; i++) {
        SetPoint(i, left, ch);
        SetPoint(i, right, ch);
    }
}

void Canvas::FillRect(int left,int top,int right,int bottom,char ch) {
    for (int i=top;i<=bottom; i++) {
        for (int j = left; j <= right; j++) {
            SetPoint(i, j, ch);
        }
    }
}
void Canvas::Print() {
    for (int i=0;i<this->height; i++) {
        for (int j=0;j<this->width; j++) {
            printf("%c", this->matrix[i][j]);
        }
        printf("\n");
    }
}
void Canvas::Clear() {
    for (int i = 0; i < this->height; i++) {
        memset(this->matrix[i], ' ', this->width);
    }
}

Canvas::~Canvas() {
    printf("Canvas::~Canvas\n");
    if (this->matrix) {
        for (int i=0; i<this->height; i++) {
            delete[] this->matrix[i];
        }
        delete[] this->matrix;
    }
}