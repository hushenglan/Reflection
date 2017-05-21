#include <iostream>

using namespace std;

class Base1 {
public:
    int ibase1;
    Base1():ibase1(10) {}
    virtual void f() { cout << "Base1::f()" << endl; }
    virtual void g() { cout << "Base1::g()" << endl; }
    virtual void h() { cout << "Base1::h()" << endl; }
 
};
 
class Base2 {
public:
    int ibase2;
    Base2():ibase2(20) {}
    virtual void f() { cout << "Base2::f()" << endl; }
    virtual void g() { cout << "Base2::g()" << endl; }
    virtual void h() { cout << "Base2::h()" << endl; }
};
 
class Base3 {
public:
    int ibase3;
    Base3():ibase3(30) {}
    virtual void f() { cout << "Base3::f()" << endl; }
    virtual void g() { cout << "Base3::g()" << endl; }
    virtual void h() { cout << "Base3::h()" << endl; }
};
 
 
class Derive : public Base1, public Base2, public Base3 {
public:
    int iderive;
    Derive():iderive(100) {}
    virtual void f() { cout << "Derive::f()" << endl; }
    virtual void g1() { cout << "Derive::g1()" << endl; }
};

int main() {
    typedef void(*Fun)(void);
    typedef int* POINTER;

    Derive d;
    POINTER obj = POINTER(&d);
    long** pVtab = (long**)&d;

    cout << "[0] Base1::_vptr->" << pVtab[0][0] << endl;
    Fun pFun = (Fun)pVtab[0][0];
    cout << "     [0] ";
    pFun();

    pFun = (Fun)pVtab[0][1];
    cout << "     [1] ";
    pFun();

    pFun = (Fun)pVtab[0][2];
    cout << "     [2] ";
    pFun();

    pFun = (Fun)pVtab[0][3];
    cout << "     [3] ";
    pFun();

    pFun = (Fun)pVtab[0][4];
    cout << "     [4] ";
    cout<<pFun<<endl;

    cout << "[1] Base1.ibase1 = " << *(POINTER)(obj + 2) << endl;
    
    

    int s = 2;

    cout << "[" << s << "] Base2::_vptr->" << pVtab[s][0] << endl;
    pFun = (Fun)pVtab[s][0];
    cout << "     [0] ";
    pFun();

    pFun = (Fun)pVtab[s][1];
    cout << "     [1] ";
    pFun();

    pFun = (Fun)pVtab[s][2];
    cout << "     [2] ";
    pFun();

    pFun = (Fun)pVtab[s][3];
    cout << "     [3] ";
    cout<<pFun<<endl;

    cout << "["<< 3 <<"] Base2.ibase2 = " << *(POINTER)(obj + 6) << endl;
    
    
    s = 4;

    cout << "[" << s << "] Base3::_vptr->" << pVtab[s][0] << endl;
    pFun = (Fun)pVtab[s][0];
    cout << "     [0] ";
    pFun();

    pFun = (Fun)pVtab[s][1];
    cout << "     [1] ";
    pFun();

    pFun = (Fun)pVtab[s][2];
    cout << "     [2] ";
    pFun();

    pFun = (Fun)pVtab[s][3];
    cout << "     [3] ";
    cout<<pFun<<endl;


    s = 5;
    cout << "["<< s <<"] Base3.ibase3 = " << *(POINTER)(obj + 10) << endl;
    
    s = 6;
    cout << "["<< s <<"] Derive.iderive = " << *(POINTER)(obj + 11) << endl;
}



