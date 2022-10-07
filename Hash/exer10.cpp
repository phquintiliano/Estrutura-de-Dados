#include <iostream>
using namespace std;

int functionHash(int elemento){
    return elemento % 101;
}

struct informacaoHash{
    int chave;
    int valor;
};

class Hash{
  private:
    int FuncaoHashTam();
    int buscar(int chave);
    int max_itens = 101;
    int max_posicoes;
    int quant_itens;
    informacaoHash* tabela;
    informacaoHash dado;


  public:
    Hash(int tam_vetor = 101);
    ~Hash();
    bool estacheio(int verificaElemento);
    void inserir(int elemento);
    void deletar(int elemento);
    void imprimir();
    
};


  Hash :: Hash(int tam_vetor){
    quant_itens = tam_vetor;
    tabela = new informacaoHash[tam_vetor];
    for(int i = 0; i < tam_vetor; i++){
        tabela[i].chave = -1;
        tabela[i].valor = -1;

    }
    max_posicoes = 0;
  }

  Hash :: ~Hash(){
    delete [] tabela;
  }

  void Hash :: inserir(int chave){
    int pos = functionHash(chave);
    if(max_posicoes < quant_itens and buscar(chave) == -1){
        while (tabela[pos].valor != -1){
            pos = (pos +1) % quant_itens;
        }
        tabela[pos].chave = chave;
        tabela[pos].valor = 1;
        max_posicoes++;
    }
    
  }
  void Hash :: deletar(int elemento){
    int pos = buscar(elemento);
    if (max_itens != 0 and pos != -1)
	{
		tabela[pos].chave = -1;
		tabela[pos].valor = -1;
		max_itens--;
	}

  }

  int Hash :: buscar(int chave){
    int pos = functionHash(chave);
    int posFinal = pos;

    do{
        dado = tabela[pos];
        if(dado.valor == -1){
            return -1;
        }
        if(dado.chave == chave){
            return pos;
        }
        pos = (pos +1) % quant_itens;

    } while(pos != posFinal);

    return -1;
    
  }

   int Hash :: FuncaoHashTam(){
     return max_itens;
   }


   bool Hash::estacheio(int verificaElemento)
{
	if (verificaElemento == buscar(verificaElemento))
	{
		return true;
	}
	else
	{
		return false;
	}
}

  void Hash :: imprimir(){
    if (max_itens == 0)
	{
		cout << "{}" << endl;
	}
	else
	{
		for (int i = 0; i < quant_itens; i++)
		{
			if (tabela[i].valor == 1)
			{
				cout << tabela[i].chave << " ";
			}
		}
		cout << endl;
	}
  }

  int main(){
    Hash tabela;

	int elementos;
	for (int i = 0; i < 10; i++)
	{
		cin >> elementos;
		tabela.inserir(elementos);
	}

	int apagados;
	for (int i = 0; i < 3; i++)
	{
		cin >> apagados;
		tabela.deletar(apagados);
	}

	bool membro;
	int verificaElemento;
	for (int i = 0; i < 2; i++)
	{
		cin >> verificaElemento;
		membro = tabela.estacheio(verificaElemento);
		if (membro == true)
		{
			cout << "1" << endl;
		}
		else
		{
			cout << "-1" << endl;
		}
	}

	tabela.imprimir();

	int insere3;
	for (int i = 0; i < 3; i++)
	{
		cin >> insere3;
		tabela.inserir(insere3);
	}

	tabela.imprimir();
    return 0;
  }