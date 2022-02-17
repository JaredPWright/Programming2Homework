#include <iostream>
#include <sstream>
using namespace std;

struct Fraction{
    int num;
    int den;
};

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

Fraction reduce(Fraction &f){
    int divisor = gcd(f.num, f.den);
    f.num = f.num / divisor;
    f.den = f.den / divisor;

    if(f.den < 0){
        f.num *= -1;
        f.den *= -1;
    }

    return f;
}

istream& operator>>(istream& in, Fraction &f)
{
    string nom;
    char junk;
    // Implement fraction input here
    getline(in, nom);

    stringstream strstr;
    strstr << nom;

    strstr >> f.num;
    strstr >> junk;
    strstr >> f.den;

    //reduce(f);

    return in;
}

ostream& operator<<(ostream& out, Fraction f)
{
    // Implement fraction output here
    reduce(f);
    out << f.num << "/" << f.den;
    return out;
}

Fraction operator+(Fraction a, Fraction b)
{
    Fraction c;
    // reduce(a);
    // reduce(b);
    if(a.den == b.den){
       c.num = a.num + b.num;
       c.den = a.den;
    }
    else{
        int tempaden = a.den;
        a.num = a.num * b.den;
        a.den = a.den * b.den;

        b.num = b.num * tempaden;

        c.num = a.num + b.num;
        c.den = a.den;
    }

    reduce(c);
    return c;
    // Implement fraction addition here
}

Fraction operator-(Fraction a, Fraction b)
{
    // Implement fraction subtraction (a-b) here
    Fraction c;
    if(a.den == b.den){
       c.num = a.num - b.num;
       c.den = a.den;
    }
    else{
        int tempint = a.den;
        a.num *= b.den;
        a.den *= b.den;

        b.num *= tempint;

        c.num = a.num - b.num;
        c.den = a.den;
    }

    reduce(c);
    return c;
}

Fraction operator*(Fraction a, Fraction b)
{
    // Implement fraction multiplication here
    Fraction c;
    c.num = a.num * b.num;
    c.den = a.den * b.den;

    reduce(c);
    return c;
}

Fraction operator/(Fraction a, Fraction b)
{
    // Implement fraction division (a/b) here
    Fraction c;
    c.num = a.num * b.den;
    c.den = a.den * b.num;

    reduce(c);
    return c;
}