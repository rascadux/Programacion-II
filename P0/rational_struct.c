#include "rational_struct.h"
//Crea un numero racional a partir de un numerador n y un denominador d
Rational createRational(int n, int d) {
    Rational temp;
    temp.num= n;
    temp.den= d;
    return temp;
}
//Devuelve el numerador de un racional r
int numerator(Rational r) {
    return r.num;
}
//Devuelve el denominador de un racional r
int denominator(Rational r) {
    return r.den;
}
//Suma dos racionales
Rational sum(Rational r1, Rational r2) {
    Rational s;
    s.num= r1.num * r2.den + r2.num * r1.den;
    s.den= r1.den * r2.den;
    return s;
}

