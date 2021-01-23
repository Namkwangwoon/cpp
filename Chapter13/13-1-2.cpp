#include <iostream>
using namespace std;

template <class T>
T SumArray(T arr[], int len)
{
    T sum = (T)0;
    for(int i=0; i<len; i++)
        sum += arr[i];
    return sum;
}

int main(void)
{
    int arr1[] = {10, 20, 30};
    cout<<SumArray(arr1, sizeof(arr1)/sizeof(int))<<endl;
    double arr2[] = {10.3, 20.4, 30.5};
    cout<<SumArray(arr2, sizeof(arr2)/sizeof(double))<<endl;
    return 0;
}