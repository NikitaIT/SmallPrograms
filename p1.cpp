#include <iostream>
using namespace std;

template<typename T> T maxp(T a[],const unsigned long n){
	int max1(-1488), min1(228),max2(-1488),min2(228);
	for (int i(0); i < n; i++)
	{
			if (max1<=a[i]){max2=max1;max1=a[i];}
			else if (max2<=a[i]) max2=a[i];
				else{
				if (a[i]<=min1){min2=min1;min1=a[i];}
				else if (a[i]<=min2) min2=a[i];
				}
	}
	if (max1*min2>max2*max2){return max1*min2;}
	else {return max2*max2;}
}


int main()
{
    int n;          // Размер массива
    int i;          // Счетчик в циклах
    cin >> n; // Считываем размер массива
    int A[n];       // Объявление массива
                    // Считываем массив
    for (i = 0; i < n; ++i)
    {
        cin >> A[i];
    }
    // Прибавляем по 1 к каждому элементу
    cout << maxp(A,n)<< endl;
    // Выводим массив на экран
    for (i = 0; i < n; ++i)
    {
        cout << A[i] << " ";
    }
    // Переведем курсор на новую строку
    cout << endl;
    return 0;
}
