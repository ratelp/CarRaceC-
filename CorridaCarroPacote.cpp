#pragma once

//Fun��o para empacotar valores gerados e posteriormente passar para a vari�vel rede na fun��o transmitir
//Utilizando dos operadores bit a bit para juntar os bits de cada valor passado no argumento da fun��o
unsigned int empacotar(unsigned short passo, unsigned short cor, unsigned short posicao, unsigned short velocidade, unsigned short pista) {
	unsigned int pacote = 0;
	pacote = passo;
	pacote = pacote << (8);
	pacote = (pacote | cor);
	pacote = pacote << (7);
	pacote = (pacote | posicao);
	pacote = pacote << (4);
	pacote = (pacote | velocidade);
	pacote = pacote << (1);
	pacote = (pacote | pista);
	pacote = pacote << (4);
	return pacote;
}

//Fun��o para coletar valor do passo
unsigned short passo(unsigned int passo) {
	return (passo >> 24);
}

//Fun��o para coletar valor da cor
unsigned short cor(unsigned int cor) {
	unsigned int corR = cor >> 16;
	return (corR & 0xFF);
}

//Fun��o para coletar valor da posi��o
unsigned short posicao(unsigned int posicao) {
	unsigned int posicaoR = posicao >> 9;
	return (posicaoR & 0xFF);
}

//Fun��o para coletar valor da velocidade
unsigned short velocidade(unsigned int velocidade) {
	unsigned int velocidadeR = velocidade >> 5;
	return (velocidadeR & 0xF);
}

//Fun��o para coletar valor do estado da pista
unsigned short pista(unsigned int pista) {
	unsigned int pistaR = pista >> 4;
	return (pistaR & 1);
}

