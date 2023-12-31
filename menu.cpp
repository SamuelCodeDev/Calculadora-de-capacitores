#include "capacitor.h"
#include "menu.h"
#include <iostream>
#include <limits>
using std::cin;
using std::cout;
using std::streamsize;
using std::numeric_limits;

#define endl '\n'

static void validar_entrada(int & entrada, const char mensagem[]) {
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << mensagem;
        cin >> entrada;
    }
}

static void lerCapacitores(int & qtd_capacitores, const char * mensagem) {
    cout << mensagem;
    cin >> qtd_capacitores;
    validar_entrada(qtd_capacitores, "Digite novamente a quantidade de capacitores: ");
}

void menu() {
    cout << "==========================\n";
    cout << "Calculadora de capacitores\n";
    cout << "==========================\n\n";

    cout << "1) Série\n";
    cout << "2) Paralelo\n";
    cout << "3) Mista\n\n";
    cout << "4) Sair\n\n";
    cout << "Sua opção: ";
}

void validar_opcao(int & opcao) {
    while (opcao != SERIE && opcao != PARALELO && opcao != MISTA && cin.fail())
    {
        validar_entrada(opcao, "Digite novamente sua opção");
        cin >> opcao;
    }
}

void menu_serie() {
    int qtd_capacitores;
    lerCapacitores(qtd_capacitores, "Digite a quantidade de capacitores: ");
    
    Capacitor resul { Serie(qtd_capacitores) };

    cout << "A capacitância total dos capacitores na associação em série é igual a ";
    cout << resul.capacitancia << ' ' << resul.unidade << endl;
}

void menu_paralelo() {
    int qtd_capacitores;
    lerCapacitores(qtd_capacitores, "Digite a quantidade de capacitores: ");
    
    Capacitor resul { Paralelo(qtd_capacitores) };

    cout << "A capacitância total dos capacitores na associação em paralelo é igual a ";
    cout << resul.capacitancia << ' ' << resul.unidade << endl;
}

void menu_mista() {
    int qtd_capacitores_serie, qtd_capacitores_paralelo;

    lerCapacitores(qtd_capacitores_serie, "Digite a quantidade de capacitores em série: ");
    lerCapacitores(qtd_capacitores_paralelo, "Digite a quantidade de capacitores em paralelo: ");

    Capacitor resul { Mista(qtd_capacitores_serie, qtd_capacitores_paralelo) };

    cout << "A capacitância total dos capacitores na associação mista é igual a ";
    cout << resul.capacitancia << ' ' << resul.unidade << endl;
}