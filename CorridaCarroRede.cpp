#pragma once
#include <iostream>
#include "CorridaCarroPacoteHeader.h"
#include "CorridaCarroCorHeader.h"

using namespace std;

//vari�vel global para ser utilizada nas fun��es transmitir e receber
unsigned int rede = 0;

// fun��o para coletar os dados de empacotar e transmitir para vari�vel global rede.
void transmitir(unsigned short passo, unsigned short cor, unsigned short posicao, unsigned short velocidade, unsigned short pista) {
	rede = empacotar(passo, cor, posicao, velocidade, pista);
	cout << "Transmitindo dados..." << endl;
	ajustarCor(preto,cor);
	cout << rede;
	resetCor();
}

//Fun��o para receber os dados da vari�vel global e colocar as informa��es no terminal
unsigned int receber() {
	// vari�vel para o resultado do �leo ser passado como true ou false
	bool resultado;
	cout << "\nRecebendo dados..." << endl;

	//Frame
	ajustarCor(cor(rede),preto);
	cout << "Frame: ";
	resetCor();
	ajustarCor(preto, cor(rede));
	cout << " " << passo(rede) << " ";
	resetCor();

	//Posi��o
	ajustarCor(cor(rede), preto);
	cout << " Pos: "; 
	resetCor();
	ajustarCor(preto, cor(rede));
	cout << " " << posicao(rede) << " ";
	resetCor();

	//Velocidade
	ajustarCor(cor(rede), preto);
	cout << " Vel: "; 
	resetCor();
	ajustarCor(preto, cor(rede));
	cout << " " << velocidade(rede) << " ";
	resetCor();

	//Estado da pista
	ajustarCor(cor(rede), preto);
	cout << " Oil: "; 
	resetCor();
	ajustarCor(preto, cor(rede));
	if (pista(rede) == 1) {
		cout << " " << "true" << " " << endl;
	}
	else {
		cout << " " << "false" << " " << endl;
	}
	resetCor();
	return rede;
}

// Fun��o que utilizando das informa��es de receber para gerar a nova posi��o do carro.
unsigned int processar(unsigned int dados) {
	unsigned short posicaoAtual = posicao(dados);
	unsigned short velo = velocidade(dados);
	unsigned short oleo = pista(dados);
	unsigned short novaPosicao = posicaoAtual + (velo - oleo);
	cout << "Processando dados..." << endl;
	ajustarCor(cor(dados), preto);
	cout << "Pr�xima posi��o: " << novaPosicao << "\n\n";
	resetCor();
	return novaPosicao;
}