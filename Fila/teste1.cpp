#include <iostream>

using namespace std;

const int maxItens = 5;

class fila{
    private: 
    int primeiro, ultimo;
    int* estrutura;

    public:
    fila();
    ~fila();
    bool estaVazio();
    bool estaCheio();
    void inserir(int item);
    int remover();
    void imprimir();
};

    fila::fila(){
        primeiro = 0;
        ultimo = 0;
        estrutura = new int[maxItens];
    }

    fila::~fila(){
        delete [] estrutura;
    }

    bool fila:: estaVazio(){
        return (primeiro == ultimo);
    }

    bool fila::estaCheio(){
        return (ultimo - primeiro == maxItens);
    }

    void fila::inserir(int item){
        if(estaCheio()){
            cout << "A fila esta cheia" << endl;
            cout << "Esse elemento nao pode ser inserido";
        } else{
            estrutura[ultimo % maxItens] = item;
            ultimo++;
        }
    }

    int fila::remover(){
        if(estaVazio()){
            cout << "A fila esta vazia" << endl;
            cout << "Nenhum elemento foi removido";
            return 0;
        } else{
            primeiro++;
            return estrutura[primeiro -1 % maxItens];
        }
    }

    void fila::imprimir(){
        cout << "Fila: [";
        for(int i = primeiro ; i< ultimo; i++){
            cout << estrutura[i % maxItens] << " ";
        }
        cout << "]" << endl;
    } 


    int main(){
        fila fila1;
        int opcao;
        int item;
        cout << "Programa gerador de filas" << endl;

        do{
            cout << "Digite 0 para parar o programa!" << endl;
            cout << "Digite 1 para inserir um elemento!" << endl;
            cout << "Digite 2 para remover um elemento!" << endl;
            cout << "Digite 3 para imprimir a fila!" << endl;
            cin >> opcao;
            if(opcao == 1){
                cout << "Digite o elemento a ser inserido na fila!" << endl;
                cin >> item;
                fila1.inserir(item);
            } else if(opcao == 2){
                item = fila1.remover();
                cout << "O elemento removido foi: " << item << endl;
            } else if (opcao == 3){
                fila1.imprimir();
            }
            

        }while(opcao != 0);


        return 0;
    }