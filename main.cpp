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

long double average(const float* p, int n) {
    long double average=0;
    int len=n;
    while (n--) {
        average+=*p;
        p++;
    }
    return average/len;

}
float minValue(const float* p, int n) {
    float min=*p;
    int len=n;
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
    int len=n;
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
    long double average=0;
    int len=n;
    while (n--) {
        average+=*p;
        p++;
    }
    p--;
    average=average/len;
    while (len--) {
        if (average<*p) {
            newCount++;
            *filter=*p;
            filter++;
        }
        p--;
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
    while (cin.fail()) {
        cout << "Неверное значение";
        cin.clear();
        cin.ignore();
        cin >> n;
    }
    cout << "Введите значения:";
    float* p = new float[n];
    inputData(p, n);
    cout << "Среднее значение:" <<average(p, n) <<"\n";
    cout << "Минимум:"<< minValue(p, n) << '\n';
    cout << "Максимум" <<maxValue(p, n) << endl;
    float* filter= filterAboveAverage(p, n, newcount);
    float * temp_filter=filter;
    cout << "Значения выше среднего:";
    while (newcount--) {
        cout <<*temp_filter << endl;
        temp_filter++;

    }
    delete[] p;
    delete[] filter;
    return 0;
}