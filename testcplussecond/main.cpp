#include <iostream>
#include "out.cpp"
using namespace std;
void add(int &a, int &b);
void testStatic(int a);
void testPointer();
void testPointer_1(int *a, int *b);
int main()
{
    int m = 10;
    int n = 12;

    int *pointer_1 = &m;
    int *pointer_2 = &n;
    cout << *pointer_1 << " "<< *pointer_2 << endl;
    int temp = *pointer_1;
    *pointer_1 = *pointer_2;
    *pointer_2 = temp;
    cout << *pointer_1 << " "<< *pointer_2 << endl;
    cout << m << " "<< n << endl;
    
    system("pause");
    return 0;
}

void testPointer_1(int *a, int *b){
    cout << *a + *b << endl;
}

void testPointer(){
    int i = 12;
    int *pointer_1;
    pointer_1 = &i;
    cout << pointer_1 <<" ";// a的地址1
    cout << *pointer_1 <<" ";

    cout << endl;

    cout<< &*pointer_1 << " "; // pointer_1中存的地址指向的变量a的地址
     cout<< &pointer_1 << " ";// pointer_1的地址
      cout<< *&pointer_1 << " ";  // pointer_1的地址指向的变量 即pointer_1的值，即a的地址
      cout<< **&pointer_1 << " "; // a

}

void add(int &a, int &b)
{
    a = a + b;
    cout << "inner" << a << endl;
}

void testStatic(int a)
{
    static int c = 2;
    cout << a + c << endl;
}