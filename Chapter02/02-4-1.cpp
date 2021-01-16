#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char str1[50] = "Hello";
    char str2[50] = " World!";

    cout<<strlen(str1)<<endl<<strlen(str2)<<endl;
    cout<<strcat(str1, str2)<<endl;
    cout<<strcpy(str2, str1)<<endl;
    cout<<strcmp(str1, str2)<<endl;
    
    return 0;
}