#include<iostream>
#include<vector>
#include<string>
#include<stdexcept>

using namespace std;

class Person{
    public:
        Person(){}
        Person(string f, string l, int a) : n{n}, a{a}{
            string n = f + l;

            if(a < 0 || a >= 150)
            {
                throw runtime_error("Invalid age in Person");
            }
            for (char c : n {
                    switch (c){
                        case ';':
                        case ':':
                        case '"':
                        case '\'':
                        case '[':
                        case ']':
                        case '*':
                        case '&':
                        case '^':
                        case '%':
                        case '$':
                        case '#':
                        case '@':
                        case '!': runtime_error("Invalid character!");
                    default: break;                    }
            }
            
        };
       
        string first() const {return f;}
        string last() const {return l;}
        int age() const {return a;}
    private:
        string f;
        string l;
        int a;
};

ostream& operator<<(ostream& os, const Person& p)
{
    return os << p.name() << " " << p.age();
}

istream& operator>>(istream& is, Person& p){
    string n;
    int a;

    is >> n >> a;
    p = Person(n, a)

    return is;
}

int main(){

Person p = Person("Goofy",63);
cout << p << endl;
Person p2;
cin >> p2;
cout << p2 << endl;

vector<Person> vec;
for(Person p; cin >>p;)
{
    if(p.name() == "end") break;
    vec.push_back(p);
}

for(Person p: vec)
    cout << p << endl;

}
