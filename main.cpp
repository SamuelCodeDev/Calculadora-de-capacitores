#include "capacitor.h"
#include "menu.h"
#include <iostream>
using namespace std;

int main()
{
#ifdef _WIN32
    ConfigurarAcentuacaoConsole();
#endif
    void (*pf[3])(void) {
        menu_serie,
        menu_paralelo,
        menu_mista,
    };
    
    menu();
    int opcao;
    cin >> opcao;
    validar_opcao(opcao);

    while(opcao != SAIR) {
        pf[opcao - 1]();
        
        menu();
        cin >> opcao;
        validar_opcao(opcao);
    }
}