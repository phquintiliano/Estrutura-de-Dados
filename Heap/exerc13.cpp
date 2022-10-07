/*
    MaxHeap, para alteração de prioridade
    by joukim & bruno, 2019
*/

#include <iostream>
#include <utility> // para usar swap
#include <stdexcept> // para usar exceção com runtime_error

using namespace std;

struct dado {
    int prioridade;
    int valor;
};

bool operator>(dado d1, dado d2) {
    return d1.prioridade > d2.prioridade;
}

bool operator<(dado d1, dado d2) {
    return d1.prioridade < d2.prioridade;
}

ostream& operator<<(ostream& output,const dado& d) {
    output << "[" << d.valor << "/" << d.prioridade << "]"; 
    return output;
}

class MaxHeap {
private:
    dado* heap;
    int capacidade;
    int tamanho;
    inline int pai(int i);
    inline int esquerdo(int i);
    inline int direito(int i); 
    void corrigeDescendo(int i); 
    void corrigeSubindo(int i);
public:
    MaxHeap(int cap);
    ~MaxHeap();
    void imprime();
    dado retiraRaiz();
    void insere(dado d);
    void alteraPrioridade(int umValor, int novaPrioridade);
};

MaxHeap::MaxHeap(int cap) {
    int capacidade = cap;
    tamanho = 0;
    heap = new dado[capacidade];

}

MaxHeap::~MaxHeap() {
    delete[] heap;

}

int MaxHeap::pai(int i) {
    return (i - 1)/2;

}
    
int MaxHeap::esquerdo(int i) {
    return (2* i)+1;

}
    
int MaxHeap::direito(int i) {
    return (2* i) + 2;

}
    
void MaxHeap::corrigeDescendo(int i) {
    int filhoEsquerdo = esquerdo(i);
    int filhoDireita = direito(i);
    int maior = i;

    if(filhoEsquerdo < tamanho and heap[filhoEsquerdo] > heap[maior]){
        maior = filhoEsquerdo;
    }
    if(filhoDireita < tamanho and heap[filhoDireita] > heap[maior]){
        maior = filhoDireita;
    }
    if(i != maior){
        swap(heap[maior], heap[i]);
        corrigeDescendo(maior);
    }

}

void MaxHeap::corrigeSubindo(int i) {
    int nohPai = pai(i);

    if(i !=0 ){
            if(heap[nohPai] < heap[i]){
                swap(heap[nohPai], heap[i]);
                corrigeSubindo(nohPai);
            }
    }

}
        
void MaxHeap::imprime() {
    for (int j = 0; j < tamanho; j++)
	{
		cout << heap[j] << " ";
	}
	cout << endl;
}

dado MaxHeap::retiraRaiz() {
    dado aux = heap[0];
	swap(heap[0], heap[tamanho - 1]);
	tamanho--;
	if (tamanho > 1)
	{
		corrigeDescendo(0);
	}
	return aux;
}


void MaxHeap::insere(dado d){
    if (tamanho == capacidade) {
        cerr << "Erro ao inserir" << endl;
        exit(EXIT_FAILURE);
    }
    heap[tamanho] = d;
    corrigeSubindo(tamanho);
    tamanho++;

}

void MaxHeap::alteraPrioridade(int umValor, int novaPrioridade) {
	int i = 0;
    while(heap[i].valor != umValor){
        i++;
    }
    heap[i].prioridade = novaPrioridade;

    corrigeDescendo(i);
    corrigeSubindo(i);
}

int main () {
    int capacidade;
    cin >> capacidade;
    MaxHeap meuHeap(capacidade);
   
    char opcao;
    cin >> opcao;
    
    dado umDado;
    int valor, novaPrioridade;

    while (opcao != 'Q') {
        switch(opcao) {
            case 'I':
                cin >> umDado.valor;
                cin >> umDado.prioridade;
                meuHeap.insere(umDado);
                break;
            case 'R':
                cout << meuHeap.retiraRaiz().valor << endl;
                break;
            case 'A':
                cin >> valor >> novaPrioridade;
                meuHeap.alteraPrioridade(valor,novaPrioridade); 
                break;               
            case 'P':
                meuHeap.imprime();
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
        cin >> opcao;
    }
    
    return 0;
}

