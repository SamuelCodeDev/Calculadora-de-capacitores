#pragma once

#ifdef _WIN32
#include <Windows.h>

inline void ConfigurarAcentuacaoConsole() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
}
#endif

inline void LimparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

enum { SERIE = 1, PARALELO, MISTA, SAIR };

void menu();
void menu_mista();
void menu_serie();
void menu_paralelo();
void validar_opcao(int&);