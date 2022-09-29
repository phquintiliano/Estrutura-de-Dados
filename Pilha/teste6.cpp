#include <iostream>

using namespace std;

class noh
{
	friend class pilha;
	private:
		char dado;
		noh *proximo;
	public:
		noh(char valor)
		{
			dado = valor;
			proximo = NULL;
		}
};

class pilha
{
	private:
		noh *topo;
		int tam;
	public:
		pilha()
		{
			topo = NULL;
			tam = 0;
		}
		~pilha()
		{
			limpaPilha();
		}
		limpaPilha()
		{
			while(tam > 0)
				desempilha();
		}
		void empilha(char valor)
		{
			noh *novo = new noh(valor); 
			novo->proximo = topo;
			topo = novo;
			tam++;
		}
		char desempilha()
		{
			char aux;
			aux = topo->dado;
			noh *temp = topo;
			topo = topo->proximo;
			delete temp;
			tam--;
			return aux; 
		}
		void verificaPalavra()
		{
			char letra, aux;
			int contA = 0, b = 0;
			pilha auxA, auxC;
			while(tam != 0)
			{
				aux = desempilha();
				if(aux == 'A')
				{
					letra = 'A';
					auxA.empilha(letra);	
				}
				if(aux == 'C')
				{
					letra = 'C';
					auxC.empilha(letra);	
				}	
			}
			while(auxC.tam > 0)
			{
				if(auxC.desempilha() and auxC.desempilha())
				{
					auxA.desempilha();
				}	
			}
			if(auxA.tam == 0 and auxC.tam == 0)
			{
				cout << "sim ";
				cout << auxA.tam << " ";
				cout << auxC.tam;
			}
			else
			{
				cout << "nao ";
				cout << auxA.tam << " ";
				cout << auxC.tam;	
			}
		}
};

int main()
{
	char palavra;
	pilha L;
	cin >> palavra;
	while(palavra != 'X')
	{
		L.empilha(palavra);
		cin >> palavra;
	}	
	L.verificaPalavra();
	return 0;
}