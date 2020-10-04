#include <stdio.h>
#include <math.h>

double findingAreaBySimpson(double leftBorder, double rightBorder, int amountOfRectangles) {
    double subgraphArea = 0, rectangleSize = (rightBorder - leftBorder) / amountOfRectangles;
    for(int i = 1; i < amountOfRectangles; i+=2) {
        subgraphArea += sin(leftBorder + (i - 1) * rectangleSize) + 4 * sin(leftBorder + i * rectangleSize)
                + sin(leftBorder + (i + 1) * rectangleSize);
    }
    return (subgraphArea * rectangleSize) / 3;
}

double findingAreaByRectangleMethod(double leftBorder, double rightBorder, int amountOfRectangles) {
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
    if(leftBorder >= rightBorder || leftBorder > M_PI || rightBorder > M_PI || leftBorder < 0) {
        printf("Incorrect borders");
        return 0;
    }

    //Подсчет площади и вывод
    const int amountOfCases = 6;
    int experiments[amountOfCases] = {6, 10, 20, 100, 500, 1000};
    double results[amountOfCases][2];
    for(int i = 0; i < amountOfCases; i++) {
        results[i][0] = findingAreaByRectangleMethod(leftBorder, rightBorder, experiments[i]);
        results[i][1] = findingAreaBySimpson(leftBorder, rightBorder, experiments[i]);
        printf("%i ", experiments[i]);
        printf("%.5f ", results[i][0]);
        printf("%.5f\n", results[i][1]);
    }
    return 0;
}