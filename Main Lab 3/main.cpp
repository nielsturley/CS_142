#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double CalcCircumferenceOfCircle(double radius);
double CalcAreaOfCircle(double radius);
double CalcVolumeOfSphere(double radius);
void Swap(int& valueA, int& valueB);
void Swap(double& valueA, double& valueB);
double CalcRectanglePerimeter(double heightRectangle, double widthRectangle);
void PrintRectanglePerimeter(double heightRectangle, double widthRectangle);
void DoubleRectanglePerimeter(double& heightRectangle, double& widthRectangle);
const double PI = 3.14;

//main function
int main(){
    cout << "Getting this line to print earns you points!\n";

    double height = 0.0;
    double width = 0.0;
    double radius = 0.0;

    cin >> height >> width >> radius;

    PrintRectanglePerimeter(height, width);
    cout << CalcRectanglePerimeter(height, width) << endl;
    cout << "... about to double height and width...\n";
    DoubleRectanglePerimeter(height, width);
    PrintRectanglePerimeter(height, width);


    return 0;
}

double CalcCircumferenceOfCircle(double radius) {
    double circumferenceOfCircle = 0.0;
    circumferenceOfCircle = 2 * PI * radius;
    return circumferenceOfCircle;
}

double CalcAreaOfCircle(double radius) {
    double areaOfCircle = 0.0;
    areaOfCircle = PI * pow(radius, 2.0);
    return areaOfCircle;
}

double CalcVolumeOfSphere(double radius) {
    double volumeOfSphere = 0.0;
    volumeOfSphere = (4.0 / 3.0) * PI * pow(radius, 3.0);
    return volumeOfSphere;
}

void Swap(int& valueA, int& valueB) {
    int placeHolderValue = 0;
    placeHolderValue = valueA;
    valueA = valueB;
    valueB = placeHolderValue;
}

void Swap(double& valueA, double& valueB) {
    double placeHolderValue = 0.0;
    placeHolderValue = valueA;
    valueA = valueB;
    valueB = placeHolderValue;
}

double CalcRectanglePerimeter(double heightRectangle, double widthRectangle) {
    double rectanglePerimeter = 0.0;
    rectanglePerimeter = (heightRectangle * 2.0) + (widthRectangle * 2.0);
    return rectanglePerimeter;
}

void PrintRectanglePerimeter(double heightRectangle, double widthRectangle) {
    cout << fixed << setprecision(1) << "A rectangle with height " << heightRectangle << " and width " << widthRectangle << " has a perimeter of " << CalcRectanglePerimeter(heightRectangle, widthRectangle) << "." << endl;
}

void DoubleRectanglePerimeter(double& heightRectangle, double& widthRectangle) {
    heightRectangle *= 2;
    widthRectangle *= 2;
}