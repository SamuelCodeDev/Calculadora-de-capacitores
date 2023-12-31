#pragma once
struct Capacitor
{
    double capacitancia;
    char unidade[3];
};

Capacitor Serie(int);
Capacitor Paralelo(int);
Capacitor Mista(int, int);
double ConverterUnidade(const Capacitor&);