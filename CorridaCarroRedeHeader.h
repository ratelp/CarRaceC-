#pragma once
#include "CorridaCarroPacoteHeader.h"

//Pr�tipo das fun��es

//Para biblioteca de REDE
void transmitir(unsigned short passo, unsigned short cor, unsigned short posicao, unsigned short velocidade, unsigned short pista);
unsigned int receber();
unsigned int processar(unsigned int dados);
