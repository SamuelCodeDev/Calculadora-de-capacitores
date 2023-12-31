#include "capacitor.h"
#include <iostream>
#include <cstring>
#include <limits>
using std::cin;
using std::cout;
using std::strcmp;
using std::numeric_limits;

#define endl '\n'

static void validarEntrada(double & capacitancia) {
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Digite novamente o valor: ";
        cin >> capacitancia;
    }
}

static void validarUnidadeMedida(char * unidadeMedida) {
    while (strcmp(unidadeMedida, "F") != 0 &&
           strcmp(unidadeMedida, "mF") != 0 &&
           strcmp(unidadeMedida, "uF") != 0 &&
           strcmp(unidadeMedida, "pF") != 0 &&
           strcmp(unidadeMedida, "nF") != 0)
    {
        cout << "Unidade inválida. Digite novamente: ";
        cin >> unidadeMedida;
    }
}

Capacitor Serie(int qtd)
{
    Capacitor * capacitores = new Capacitor[qtd];
    Capacitor total{0, "F"};

    for (int i = 0; i < qtd; ++i)
    {
        cout << endl;
        cout << "Capacitor " << i + 1 << ": "; 
        cin >> capacitores[i].capacitancia;
        validarEntrada(capacitores[i].capacitancia);

        cout << "Unidade (F, mF, uF, pF, nF): ";
        cin >> capacitores[i].unidade;
        validarUnidadeMedida(capacitores[i].unidade);

        capacitores[i].capacitancia = ConverterUnidade(capacitores[i]);
        cout << endl;
    }

    for (int i = 0; i < qtd; ++i) {
        total.capacitancia += 1 / capacitores[i].capacitancia;
    }

    total.capacitancia = 1 / total.capacitancia;

    delete[] capacitores;

    return total;
}

Capacitor Paralelo(int qtd)
{
    Capacitor * capacitores = new Capacitor[qtd];
    Capacitor total{0, "F"};

    for (int i = 0; i < qtd; ++i)
    {
        cout << endl;
        cout << "Capacitor " << i + 1 << ": "; 
        cin >> capacitores[i].capacitancia;
        validarEntrada(capacitores[i].capacitancia);

        cout << "Unidade (F, mF, uF, pF, nF): ";
        cin >> capacitores[i].unidade;
        validarUnidadeMedida(capacitores[i].unidade);

        capacitores[i].capacitancia = ConverterUnidade(capacitores[i]);
        cout << endl;
    }

    for (int i = 0; i < qtd; ++i) {
        total.capacitancia += capacitores[i].capacitancia;
    }

    delete[] capacitores;
    
    return total;
}

Capacitor Mista(int qtd_serie, int qtd_paralelo)
{
    Capacitor total_serie = Serie(qtd_serie);
    Capacitor total_paralelo = Paralelo(qtd_paralelo);
    return Capacitor { total_serie.capacitancia + total_paralelo.capacitancia, "F" };
}

double ConverterUnidade(const Capacitor& c)
{
    if (strcmp(c.unidade, "F") == 0)
        return c.capacitancia;
    else if (strcmp(c.unidade, "mF") == 0)
        return c.capacitancia * 1e-3;
    else if (strcmp(c.unidade, "uF") == 0)
        return c.capacitancia * 1e-6;
    else if (strcmp(c.unidade, "nF") == 0)
        return c.capacitancia * 1e-9;
    else if (strcmp(c.unidade, "pF") == 0)
        return c.capacitancia * 1e-12;
    else
        return c.capacitancia;
}