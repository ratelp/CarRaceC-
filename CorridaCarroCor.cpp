#pragma once
#include <iostream>
#include "CorridaCarroCorHeader.h"

using namespace std;

//Fun��o para colorir o terminal
void ajustarCor(int corTexto,int corFundo) {
	cout << "\033[38;5;" << corTexto << "m" << "\033[48;5;" << corFundo << "m";
}

//Fun��o para retornar cor padr�o do terminal
void resetCor() {
	cout << padrao;
}