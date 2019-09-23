#include <iostream>
#include <list>
using namespace std;
#define NumVertice 9

class Grafo
{
public:
	//Caminhos entre os vertices
	int aresta[NumVertice][NumVertice];
	//Vertices que contem as Estimativas (sem predecessor)
	int vertice[NumVertice];
	//Set Grafo padrão
	void setGrafoPadrao();
	Grafo();
};

Grafo::Grafo(){
	//Init Arestas (Caminhos)
	int i=0,j=0;
	for (i = 0; i < NumVertice; i++)
	{
		this->vertice[i] = 999;
		for (j = i+1; j < NumVertice; j++)
		{
			this->aresta[i][j] = 999;
		}
	}
}

void Grafo::setGrafoPadrao(){
	this->aresta[0][1] = 2;
	this->aresta[0][2] = 3;
	this->aresta[1][3] = 2;
	this->aresta[1][4] = 5;
	this->aresta[2][3] = 3;
	this->aresta[2][5] = 4;
	this->aresta[3][6] = 5;
	this->aresta[3][8] = 5;
	this->aresta[4][5] = 2;
	this->aresta[4][8] = 6;
	this->aresta[5][7] = 1;
	this->aresta[6][7] = 2;
	this->aresta[7][8] = 3;
}

void dijkstra (Grafo *f, int origem, int destino) {
	int *aux;
	int i;
	int j;
	for (i=origem; i<destino; ++i)
	{
		for (j=i+1; j<destino; ++j)
		{
			if (f->vertice[j] > f->aresta[i][j] + f->vertice[i])
				f->vertice[j] = f->aresta[i][j] + f->vertice[i];
		}
	}
	for (i=0; i<NumVertice; ++i) 
	{
		cout << "Menor distancia do V[" << origem << "] ate " << "V[" << i << "]: " << f->vertice[i] << "\n";
	}
}

int main (){
	Grafo *f = new Grafo();
	f->setGrafoPadrao();
	int origem=0, destino=NumVertice;
	cout << "Vertice destino: " << destino-1 << endl;
	cout << "Vertice inicial: ";
	cin >> origem;
	f->vertice[origem] = 0;
	dijkstra(f,origem,destino);
	return 0;
}