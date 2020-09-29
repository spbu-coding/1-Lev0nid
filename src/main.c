#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double areaBySimpson(double leftBorder, double rightBorder, int amountOfRectangles) {
    double subgraphArea = 0, rectangleSize = (rightBorder - leftBorder) / amountOfRectangles;
    for(int i = 1; i < amountOfRectangles; i+=2) {
        subgraphArea += sin(leftBorder + (i - 1) * rectangleSize) + 4 * sin(leftBorder + i * rectangleSize) + sin(leftBorder + (i + 1) * rectangleSize);
    }
    return subgraphArea * rectangleSize / 3;
}

double areaByRectangleMethod(double leftBorder, double rightBorder, int amountOfRectangles) {
    double subgraphArea = 0, rectangleSize = (rightBorder - leftBorder) / amountOfRectangles;
    for(int j = 0; j < amountOfRectangles; j++) {
        subgraphArea += sin(leftBorder + (j + 0.5) * rectangleSize) * rectangleSize;
    }
    return subgraphArea;
}

int main() {
    //Считываем границы
    double leftBorder, rightBorder;
    scanf("%lf%lf", &leftBorder, &rightBorder);

    //Подсчет площади и вывод
    int amountOfCases = 6;
    int experiments[6] = {5, 10, 20, 100, 500, 1000};
    double results[6][2];
    for(int i = 0; i < amountOfCases; i++) {
        results[i][0] = areaByRectangleMethod(leftBorder, rightBorder, experiments[i]);
        results[i][1] = areaBySimpson(leftBorder, rightBorder, experiments[i]);
        printf("%i%c", experiments[i], ' ');
        printf("%.5f%c", results[i][0], ' ');
        printf("%.5f\n", results[i][1]);
    }
    return 0;
}