#include <iostream>
#include "out.cpp"
using namespace std;
void add(int &a, int &b);
void testStatic(int a);
void testPointer();
void testPointer_1(int *a, int *b);
void testPointerArr();
void testPointerToArr();
void testPointerToArr(int *arr, int n);
void testPointToFunc();
void test();
void testPointToFunc_pointer(int a, void (*p)());
int *testFuncToPointer(int *a);
void testPoninterToArr();
void testRreference(int &a);
void testNewDelete();
#define pbm "12";
#define pw 12;
int pub = 1;
void testPointerToPointer();
void (*p)();
struct Child
{
    int m = 10;
};

struct Test
{
    int a;
    char b;
    int m[3];
    Child child1;
};
Test test1 = {1, 'c', {1, 2, 3}};
void testFuncStruct(Test test);

Test testArr[2];

union TestUnion {
    int a;
    int b;
    float ch;
    int m[2];
};

TestUnion testUnion;
class TestClass
{

public:
    int m = 2;
    int n = 3;
    TestClass()
    {
        cout << "no arguments" << endl;
    }

    TestClass(int a, int b)
    {
        m = a;
        n = b;
        cout << "" << m + n << endl;
    }
    ~TestClass()
    {
        cout << "the end of the object" << endl;
    }
    void minus(int a, int b);
    void add(int a, int b);

    int getM() const;
};

class TestStaticClass
{
public:
    static int a;
    int m;
    static void testStaticFunc(int m)
    {
        cout << a << endl;
        cout << a + m << endl;
    }
};
int TestStaticClass::a = 10;

class TestFriendClassP
{
public:
    TestFriendClassP(int i, int j, int k)
    {
        this->a = i;
        this->b = j;
        this->c = k;
    };
    friend int addFriend(TestFriendClassP *p);

private:
    int a;
    int b;
    int c;
};

class TestOperator{
    public:
    // 在这个类的对象里进行加法操作时运算符+被重载了
    TestOperator *operator+ (TestOperator *p);
    int m;
    int n;
    TestOperator(){}
    TestOperator(int a, int b){
        this->m = a;
        this->n = b;
    }
};
TestOperator *TestOperator::operator+ (TestOperator *p){
    TestOperator *test_oprator;
    (*test_oprator).m = m - p->m;
    (*test_oprator).n = n - p->n;
    return test_oprator;
}
int main()
{
    TestOperator test_op(3,2);
    TestOperator test_op1(4,5);
    TestOperator *p = &test_op;
    TestOperator *p1 = &test_op1;

   TestOperator *test = *p + p1;
   cout << test->m << " "<< test->n << endl;
    system("pause");
    return 0;
}
int addFriend(TestFriendClassP *p)
{
    return p->a + p->b + p->c;
}
int TestClass::getM() const
{
    return m;
}

void TestClass::minus(int a, int b)
{
    m = a;
    a--;
    b--;
    cout << a - b << endl;
    return this->add(m, a);
}

void TestClass::add(int a, int b)
{
    m = a;
    n = b;
    cout << a - b << endl;
}

void testNewDelete()
{
    // new 类型【初值】
    int *p = new int(100);
    cout << *p << endl;
}

void testFuncStruct(Test test)
{
    cout << test.a << endl;
}

void testRreference(int &a)
{
    a++;
    cout << a << endl;
}

void testPointerToPointer()
{
    int **p;
    int a = 2;
    *p = &a;
    cout << *p << endl;
    cout << **p << endl;
}

void testPoninterToArr()
{
    int *p[4];
    int b = 2;
    int a[5] = {1, b, 3, 4, 5};
    for (int i = 0; i < 4; i++)
    {
        p[i] = &a[1];
    }

    cout << p[2] << endl;
    cout << *p[2] << endl;
}

int *testFuncToPointer(int *a)
{
    int c = 2;
    *a = c;
    return a;
}
void test()
{
    int arr[5][3] = {1, 2, 3, 4, 5, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5};
    int *p = arr[0];
    int n = 10;
    testPointerToArr(p, 3);
}

void testPointToFunc_pointer(int a, void (*p)())
{
    cout << "test function pointer" << endl;
    (*p)();
}

void testPointToFunc()
{
    cout << "this is pointer to func" << endl;
}

void testPointerToArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(arr + i * 5) << " ";
    }
}

void testPointerArr()
{
    int a[5];
    int *p;
    p = &a[0]; // 或者p = a;数组名代指数组的第一个元素的地址
    for (int i = 0; i < 5; i++)
    {
        cin >> *(p + i);
    }

    for (p = a; p < a + 5;)
    {
        cout << *(p++) << endl;
    }
}

void testPointer_1(int *a, int *b)
{
    cout << *a + *b << endl;
}

void testPointer()
{
    int i = 12;
    int *pointer_1;
    pointer_1 = &i;
    cout << pointer_1 << " "; // a的地址1
    cout << *pointer_1 << " ";
    cout << endl;
    cout << &*pointer_1 << " ";  // pointer_1中存的地址指向的变量a的地址
    cout << &pointer_1 << " ";   // pointer_1的地址
    cout << *&pointer_1 << " ";  // pointer_1的地址指向的变量 即pointer_1的值，即a的地址
    cout << **&pointer_1 << " "; // a
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