// Section 15
// copy assignment operator
#include <iostream>

using namespace std;

class Base {
private:
    int value;
public:
    Base() 
        :value{0}{
            cout << "Base no-args constructor" << endl; 
    }
    Base(int x) 
        :value{x}{ 
            cout << "Base (int) overloaded constructor" << endl;
    }
    Base(const Base &other)
        :value(other.value){
            cout << "Base copy constructor" << endl;
    }
    Base &operator=(const Base &rhs){
        cout << " Base operator " << endl;
        if(this==&rhs){
            return *this;
        }
        value = rhs.value;
        return *this;
    }
    ~Base(){ 
       cout << "Base destructor" << endl;
    }
};

class Derived : public Base {
    using Base::Base;
private:
    int doubled_value;
public:
    Derived() 
        :Base(), doubled_value {0}{
            cout << "Derived no-args constructor " << endl; 
    } 
    Derived(int x) // Base class initialization (Explicitly invoking int overloaded constructor)
        :Base(x), doubled_value {x*2} {
            cout << "Derived (int) overloaded constructor" << endl;
    }
    Derived(const Derived &other)
        :Base(other), doubled_value{other.doubled_value} {
            cout << "Derived (int) copy constructor" << endl;
    }
    Derived &operator=(const Derived &rhs){
        cout << "Derived constructor" << endl;
        if(this == &rhs){
            return *this;
        }
        Base::operator=(rhs);
        doubled_value = rhs.doubled_value;
        return *this;
    }
    ~Derived(){
        cout << "Derived destructor " << endl; 
    } 
};
int main(){
    //Base b{100};
    //Base b1{b};
    //b = b1;

    Derived b{100};
    Derived b1{b};
    b = b1;    
    return 0;    
}