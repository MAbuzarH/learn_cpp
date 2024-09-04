#include <iostream>

using namespace std;
class AreaCalculater
{
    // static const def_len = 0;

private:
    int Length;
    int Width;
    int Radius;

public:
    AreaCalculater(int length = 0, int width = 0, int radius = 0) : Length{length}, Width{width},
                                                                    Radius{radius}
    {
    }
    int getLength() { return Length; }
    int getWidth() { return Width; }
    int getRadius() { return Radius; }

    int cal_sqr_area(int length, int width)
    {
        int area = length * width;
        return area;
    }

    int cal_cir_area(int radius)
    {
        int area = 3.16 * (radius * radius);
        return area;
    }

    int cal_tri_area(int length, int width)
    {
        int area = (1 / 2) * length * width;
        return area;
    }
};
int main()
{
    int choice;
    int length, width, radius;
    AreaCalculater A1;
    do
    {
        cout << "enter 1 to caculate area of sqr" << endl;
        cout << "enter 2 to caculate area of cir" << endl;
        cout << "enter 3 to caculate area of tri" << endl;
        cout << "enter 0 to exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter length :" << endl;
            cin >> length;
            cout << "enter width :" << endl;
            cin >> width;
            cout << "area of sqr" << A1.cal_sqr_area(length, width) << endl;
            break;
        case 2:
            cout << "enter redius :" << endl;
            cin >> radius;
            cout << "area of cir" << A1.cal_cir_area(radius) << endl;
            break;
        case 3:
            cout << "enter length :" << endl;
            cin >> length;
            cout << "enter width :" << endl;
            cin >> width;
            cout << "area of triangle: " << A1.cal_tri_area(length, width);
            break;
        default:
            cout << "in valid state" << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}