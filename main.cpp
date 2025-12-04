#include <iostream>
#include <windows.h>
using namespace std;

void inputData(float* p, int n) {
    float znach;
    while (n--) {
        cin >> znach;
        while (cin.fail()) {
            cout << "Неверное значение";
            cin.clear();
            cin.ignore();
            cin >> znach;
        }
        *p=znach;
        p++;
    }
}

float Average(const float* p, int n) {
    float average=0;
    int len=n;
    while (n--) {
        average+=*p;
        p++;
    }
    return average/len;
}
float minValue(const float* p, int n) {
    float min=*p;
    while (n--) {
        if (min>*p) {
            min=*p;
        }
        p++;
    }
    return min;
}

float maxValue(const float* p, int n) {
    float max=*p;
    while (n--) {
        if (max<*p) {
            max=*p;
        }
        p++;
    }
    return max;
}
float* filterAboveAverage(const float* p, int n, int & newCount) {
    float *filter= new float[n];
    float *start_f= filter;
    float average= Average(p, n);
    while (n--) {
        if (average<*p) {
            newCount++;
            *filter=*p;
            filter++;
        }
        p++;
    }

    return start_f;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    int n,newcount=0;
    cout << "=== Анализ сенсора  ==="<<'\n';
    cout << "Введите количество измерений: " ;
    cin >> n;
    while (cin.fail() || n<=0) {
        cout << "Неверное значение";
        cin.clear();
        cin.ignore(1000);
        cin >> n;
    }
    cout << "Введите значения:";
    float* p = new float[n];
    inputData(p, n);
    cout << "Среднее значение:" <<Average(p, n) <<"\n";
    cout << "Минимум:"<< minValue(p, n) << '\n';
    cout << "Максимум" <<maxValue(p, n) << endl;
    float* filter= filterAboveAverage(p, n, newcount);
    float * temp_filter=filter;
    if (newcount==0) {
        cout << "Значения равны" << endl;
    }
    else
    {
        cout << "Значения выше среднего:" << endl   ;
    while (newcount--) {
        cout <<*temp_filter << endl;
        temp_filter++;
    }
    }
    delete[] p;
    delete[] filter;
    return 0;
}