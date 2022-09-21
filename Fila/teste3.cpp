/*Implemente um estrutura de dados do tipo pilha com as operações de empilhar e desempilhar.
Adicione um método que, utilizando uma pilha auxiliar, faça a ordenação crescente da pilha original,
com o menor elemento no topo da pilha. Nenhuma outra estrutura pode ser utilizada além da pilha auxiliar.

Entradas:
    Quantidade de elementos a serem armazenados na pilha
    Elementos da pilha
Saídas:
    Elementos da pilha ordenados*/

#include <iostream>

using namespace std;

class noh
{
    friend class Pilha;

private:
    int mDado;
    noh *mProximo;

public:
    noh(int valor);
};

noh::noh(int valor)
{
    mDado = valor;
    mProximo = NULL;
}

class Pilha
{
private:
    noh *mTopo;
    int mTamanho;

public:
    Pilha();
    ~Pilha();
    void ordena();
    int desempilhar();
    void empilhar(int dado);
};

Pilha::Pilha()
{
    mTopo = NULL;
    mTamanho = 0;
}

Pilha::~Pilha()
{
    while (mTamanho > 0)
    {
        desempilhar();
    }
}

void Pilha::empilhar(int dado)
{
    noh *novo = new noh(dado);
    novo->mProximo = mTopo;
    mTopo = novo;
    mTamanho++;
}

int Pilha::desempilhar()
{
    noh *aux = mTopo;
    int dado = aux->mDado;
    mTopo = aux->mProximo;
    delete aux;
    mTamanho--;
    return dado;
}

void Pilha::ordena()
{
    Pilha Aux;
    int maior = 0;
    int elementoCompara = 0;
    int elementosOrdenados = 0;
    int tamanho = mTamanho;
    int desemp = 0;

    while (elementosOrdenados < tamanho)
    {
        if (elementosOrdenados == 0)
        { //Primeira comparação desempilha da pilha original
            maior = desempilhar();
            for (int i = 0; i < tamanho - (elementosOrdenados + 1); i++)
            {
                elementoCompara = desempilhar();
                if (maior > elementoCompara)
                {
                    Aux.empilhar(elementoCompara);
                }
                else
                {
                    Aux.empilhar(maior);
                    maior = elementoCompara;
                }
            }
        }
        else
        { //Proximas comparações desempilham de aux e armazenam os elementos ordenados na pilha original
            maior = Aux.desempilhar();
            for (int i = 0; i < tamanho - (elementosOrdenados + 1); i++)
            {
                elementoCompara = Aux.desempilhar();
                if (maior > elementoCompara)
                {
                    empilhar(elementoCompara);
                }
                else
                {
                    empilhar(maior);
                    maior = elementoCompara;
                }
            }
            for (int i = 0; i < tamanho - (elementosOrdenados + 1); i++)
            {
                //Desempilha os elementos desordenados de A em aux para a proxima comparação
                desemp = desempilhar();
                Aux.empilhar(desemp);
            }
        }
        empilhar(maior);
        elementosOrdenados++;
    }
}

int main()
{
    int dado;
    Pilha pilha;
    int tamPilha;

    cin >> tamPilha;

    for (int i = 0; i < tamPilha; i++)
    {
        cin >> dado;
        pilha.empilhar(dado);
    }

    pilha.ordena();
    for (int i = 0; i < tamPilha; i++)
        cout << pilha.desempilhar() << " ";

    return 0;
}