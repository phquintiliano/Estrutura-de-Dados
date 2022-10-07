#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int INVALIDO = -1;

struct dado
{
	int base;
	int relativo;
};

class torneio 
{
	private:
		dado *heap;
		int iCapacidade;
		int iTamanho;
		int iInicioDados;
	public:
		torneio(dado vet[], int _iTamanho)
		{
			iCapacidade = 1;
			while (iCapacidade < _iTamanho)
			{
				iCapacidade *= 2;
			}	
			iCapacidade = iCapacidade - 1 + _iTamanho;
			heap = new dado[iCapacidade];
			iInicioDados = iCapacidade - _iTamanho;	
			memcpy(&heap[iInicioDados], vet, _iTamanho*sizeof(dado));	
			iTamanho = _iTamanho;	
			arruma();
		}
		torneio(int iNumeroFolhas)
		{
			iCapacidade = 1;
			while (iCapacidade < iNumeroFolhas)
			{
				iCapacidade *=2;
			}	
			iCapacidade = iCapacidade - 1 + iNumeroFolhas;
			heap = new dado[iCapacidade];
			iInicioDados = iCapacidade - iNumeroFolhas;	
			for (int i = 0; i < iCapacidade; i++)
			{
				heap[i].base = INVALIDO;
				heap[i].relativo = INVALIDO;
			}
		}
		/*void insere(dado d)
		{
			if (iTamanho == iCapacidade)
			{
				cout << "Não foi possível inserir" << endl;
			}	
			heap[iTamanho + iInicioDados] = d;
			copiaSubindo(iTamanho + iInicioDados);
			iTamanho++;
		}*/
		void imprime()
		{
			for (int i = 0; i < iCapacidade; i++)
			{
				cout << heap[i].base << " " << heap[i].relativo << " ";
			}
			cout << endl;
		}
		void imprimeCampeao()
		{
			cout << heap[0].base << endl;
		}
		void arruma()
		{
			for (int i = iInicioDados - 1; i >= 0; i--)
			{
				copiaMaior(i);
			}
		}
		int pai(int i)
		{
			return ((i-1)/2);
		}
		int esquerdo(int i)
		{
			return 2*i+1;
		}
		int direito(int i) 
		{
			return 2*i+2;
		}
		void copiaMaior(int i)
		{
			int esq = esquerdo(i);
			int dir = direito(i);	
			int maior = -1;	
			if (esq < iCapacidade)
			{
				if ((dir < iCapacidade) and (heap[dir].relativo > heap[esq].relativo))
				{				
					maior = dir;
				} 
				else
				{
					maior = esq;
				}
				heap[i] = heap[maior];
				//heap[maior].relativo = heap[maior].relativo - heap[i].relativo;
			} 
			else
			{
				heap[i].base = INVALIDO;
				heap[i].relativo = INVALIDO;
			}
		}
		/*void copiaSubindo(int i)
		{
			int p = pai(i);
			if (heap[i].base > heap[p].base)
			{
				heap[p].base = heap[i].base;
				copiaSubindo(p);
			}
		}*/
		~torneio()
		{
			delete[] heap;
		}
};

int main()
{
	int quant;
	cin >> quant;
	dado aux[quant];
	for(int i = 0; i < quant; i ++)
	{
		cin >> aux[i].base;
		aux[i].relativo = aux[i].base;
	}
	torneio Torneio(aux,quant);
	//Torneio.imprime();
	Torneio.imprimeCampeao();
	return 0;
}