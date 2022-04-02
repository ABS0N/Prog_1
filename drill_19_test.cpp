//g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11

#include "std_lib_facilities.h"
#include <iostream>
#include <vector>
using namespace std;

template<typename T> struct S
{
    S(T v) : val{v} {}
    T& get();
    const T& get() const;
    
    void set(const T&);
    void operator=(const T&);
    
    friend istream& operator>>(istream& ist, S<T>& ss)
    {   
        return ist >> ss.val;
    } 
    
    friend ostream& operator<<(ostream& ost, S<T>& ss)
    {   
        return ost << ss.val;
    }
    
    
 
private:
        T val;
};


template<typename T> 
T& S<T>::get() 
{   return val; }

template<typename T>
const T& S<T>::get() const
{   return val; }

template<typename T>
void S<T>::set(const T& t)
{   val = t;    }

template<typename T>
void S<T>::operator=(const T& t)
{   val = t;    }

template<typename T>
void read_val(T& v) 
{
    cin.clear();
    cin >> v;       
}

template<typename T>
void print_val(T& v)
{
    cout << v;
}

/*
    {val,val,val,val}
*/
template<typename T>
istream& operator>>(istream& ist, vector<T>& v) 
{
    char c1, c2;
    ist >> c1;
    if(c1 != '{') cout << "Invalid format";
    
    T t;
    while(ist >> t && ist >> c2) {
        v.push_back(t);
    }
    return ist; 
}

template<typename T>
ostream& operator<<(ostream& ost, vector<T>& v)
{
    for(int i = 0  ; i < v.size();++i)
    {
        if(i == 0 ) ost << "{";
        ost << v[i];    
        if(i < v.size() -1) ost << ",";
        else ost << "}";
    }
    return ost;
}


/*
int main()
{
    vector<int> a;
    S<vector<int>> s(a);
    read_val(s);
    print_val(s);
}
*/


int main()
{     
	S<int> s1(1);
    S<char> s2('a');
    S<double> s3(3.14);
    S<string> s4("Hello");
    S<vector<int>> s5(vector<int>{1,2,3});
    
    cout << s1.get() << "\n";
    cout << s2.get() << "\n";
    cout << s3.get() << "\n";
    cout << s4.get() << "\n";
    
    vector<int> v = s5.get();
    for(int vv : v)
        cout << vv << " ";
    cout << "\n";
    
    s1.set(2);
    cout << s1.get();
    cout << "\n";
    
    cout << s1.get() << "\n";
    
    s1 = 3;
    cout << s1.get();
    cout << "\n";
    
    const S<string> s6("const version of get()");
    cout << s6.get(); 

    cout << "int: \n";
    int v_int;
    read_val(v_int);
    S<int> s_int(v_int);
    cout << s_int.get() << "\n";
    
    cout << "char: \n";
    char v_char;
    read_val(v_char);
    S<char> s_char(v_char);
    cout << s_char.get() << "\n";
    
    cout << "double: \n";
    double v_double;
    read_val(v_double);
    S<double> s_double(v_double);
    cout << s_double.get() << "\n";
    
    cout << "string: \n";
    string v_string;
    read_val(v_string);
    S<string> s_string(v_string);
    cout << s_string.get() << "\n";

    cout << "\n";
    cout << "int:\n";
    vector<int> v2_int;
    read_val(v2_int);
    print_val(v2_int);
    
    cout << "\n";
    cout << "double:\n";
    vector<double> v2_double;
    read_val(v2_double);
    print_val(v2_double);
    

    vector<int> a;
    S<vector<int>> s(a);
    read_val(s);
    print_val(s);

}
