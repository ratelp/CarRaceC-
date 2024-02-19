#include <iostream>
#include "CorridaCarroCorHeader.h"
#include "CorridaCarroRedeHeader.h"
using namespace std;

//Para Desenhar
void desenhar(unsigned short, unsigned short);
void espacos(int);

int main() {

	// --------------------
	// Inicializando dados:
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout.precision(2);
	srand(unsigned(time(NULL)));

	unsigned short pos1 = 0;
	unsigned short pos2 = 0;

	unsigned short velo1 = 0;
	unsigned short velo2 = 0;
	
	unsigned short cor1 = verde;
	unsigned short cor2 = azul;
	
	unsigned short estPis1 = 0;
	unsigned short estPis2 = 0;

	int passo = 0;
	// --------------------

	do
	{

	// ------------------------
	// Limpando sistema anterior e desenhando carros nas posi��es atuais
	system("cls");
	desenhar(pos1, verde);
	desenhar(pos2, azul);
	// ------------------------
	
	// ------------------------
	// Gerando nova Velocidade e valor para �leo
	velo1 = (rand() % 10 + 1);
	velo2 = (rand() % 10 + 1);

	estPis1 = (rand() % 2);
	estPis2 = (rand() % 2);
	// ------------------------

			
	// ----------------------------------
	// Dados na tela e Calcula Pr�xima posi��o
	transmitir(passo,cor1,pos1,velo1,estPis1);
	pos1 = processar(receber());

	transmitir(passo,cor2,pos2,velo2,estPis2);
	pos2 = processar(receber());
	// ----------------------------------


	// Aguarda pressionamento de tecla
	system("pause > NULL");
	// -------------------------------

	passo = passo + 1;
	} while (pos1 <= 100 && pos2 <= 100);
	// --------------------
	//Inicializando Velocidades M�dia
	float velocidadeMedia1 = float(pos1) / float(passo);
	float velocidadeMedia2 = float(pos2) / float(passo);

	// --------------------
	// Tela FINAL
	system("cls");
	//Passos
	desenhar(pos1, verde);
	desenhar(pos2, azul);
	ajustarCor(preto, amarelo);
	cout << " Passos  ";
	resetCor();
	ajustarCor(amarelo, preto);
	cout << " "; cout.width(3); cout << passo << " " << endl;
	ajustarCor(preto, verde);

	//Posi��o e velocidade m�dia do 1� carro
	cout << " Posi��o ";
	resetCor();
	ajustarCor(verde, preto);
	cout << " "; cout.width(3); cout << pos1 << " ";
	resetCor();
	ajustarCor(preto, verde);
	cout << " Velocidade m�dia ";
	resetCor();
	ajustarCor(verde, preto);
	cout << " " << velocidadeMedia1 << " " << endl;
	resetCor();

	//Posi��o e velocidade m�dia do 2� carro
	ajustarCor(preto, azul);
	cout << " Posi��o ";
	resetCor();
	ajustarCor(azul, preto);
	cout << " "; cout.width(3); cout << pos2 << " ";
	resetCor();
	ajustarCor(preto, azul);
	cout << " Velocidade m�dia ";
	resetCor();
	ajustarCor(azul, preto);
	cout << " " << velocidadeMedia2 << " " << endl;
	resetCor();
	// --------------------


}

//Fun��o para desenhar os carros e a pista.
void desenhar(unsigned short posicao, unsigned short cor) {
	ajustarCor(cor, preto);
	cout << "\n\n\n";
	espacos(posicao); cout << "\xDB\xDC\xDB\xDB\xDB\xDB\xDB\xDC\n";
	espacos(posicao); cout << "\xDFO\xDF\xDF\xDF\xDFO\xDF\xDF\n";
	cout << "---------------------------------------------------------------------------------------------------|--------------------";
	cout.width(101); cout << "100" << endl; resetCor();
}

//Fun��o para fazer os carros andarem.
void espacos(int qtd) { 
	while (qtd-- > 0) cout << ' '; 
}