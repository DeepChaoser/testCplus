#include <iostream>
using namespace std;
void add(int &a, int &b);
void testStatic();
int main(){
    int a = 0;
    int b = 1;
    // add(a, b);
    // cout <<"outer" << a << endl;

    for(int i = 0; i<10; i++){
        testStatic();
    }

    system("pause");
    return 0;
}
void add (int &a, int &b){
    a = a + b;
    cout <<"inner" << a << endl;
}

void testStatic(){
static int c = 0;
cout << c++ << endl;
}