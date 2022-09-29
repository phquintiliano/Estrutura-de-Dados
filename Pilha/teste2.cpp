#include <iostream>

using namespace std;

const int max_itens = 2;

class pilha{
    private:
    int tamanho;
    int* estrutura; 

    public: 
    pilha(); //construtora com o mesmo nome da classe
    ~pilha(); //destrutora 
    bool estaCheia(); //verifica se a pilha esta cheia
    bool estaVazia(); // verifica se a pilha esta vazia
    void inserir(int item); //inserir elemento na pilha
    int remover(); //remove da pilha
    void imprimir(); //imprimi o item
    int qualTamanho(); // verifica o tamanho
};


    pilha::pilha(){  //construtora com o mesmo nome da classe
        tamanho = 0;
        estrutura = new int[max_itens];
    }

    pilha::~pilha(){  //destrutora 
        delete [] estrutura;
    } 

    bool pilha::estaCheia(){ //verifica se a pilha esta cheia
        return (tamanho == max_itens);
    } 

    bool pilha::estaVazia(){  //verifica se a pilha esta vazia
        return (tamanho == 0);
    } 

    void pilha::inserir(int item){ //inserir elemento na pilha
        if(estaCheia()){
            cout << "A PILHA ESTA CHEIA!" << endl;
            cout << "Nao e possivel inserir este elemento!" << endl;
        } else{
            estrutura[tamanho] = item;
            tamanho++;
        }
    } 

    int pilha::remover(){ //remove da pilha
        if(estaVazia()){
            cout << "A pilha esta vazia!" << endl;
            cout << "Nao tem elemento para ser removido!" << endl;
            return 0;
        } else {
            tamanho--;
            return estrutura[tamanho];  

        }

    } 

    void pilha::imprimir(){ //imprimi o item
        cout << "Pilha: [";
        for(int i=0; i < tamanho; i++){
            cout << estrutura[i] << " ";
        }

        cout << "]" << endl;

    } 

    int pilha::qualTamanho(){// verifica o tamanho
        return tamanho;

    } 


    int main(){

        pilha pilha1;
        int item;
        int opcao;
        cout << "Programa gerador de pilha:" << endl;

        do{
            cout << "Digite 0 para parar o programa" << endl;
            cout << "Digite 1 para inserir um elemento" << endl;
            cout << "Digite 2 para remover um elemento"<< endl;
            cout << "Digite 3 para imprimir um elemento" << endl;
            cout << "Digite 4 para verificar o tamanho da pilha" << endl;
            cout << "Digite 5 para verificar se a pilha esta vazia" << endl;
            cout << "Digite 6 para verificar se a pilha esta cheia" << endl;

            cin >> opcao;

            if(opcao == 1){
                cout << "Digite o elemento a ser inserido" << endl;
                cin >> item;
                pilha1.inserir(item);
            } else if(opcao == 2){
                item = pilha1.remover();
                cout << "Elemento Removido: " << item << endl;
            } else if(opcao == 3){
                pilha1.imprimir();
            } else if(opcao == 4){
                pilha1.qualTamanho();
                cout << pilha1.qualTamanho() << endl;
            } else if(opcao == 5){
                if(pilha1.estaVazia() == true){
                    cout << "A pilha esta vazia" << endl;
                }else {
                    cout << "A pilha nao esta vazia" << endl;
                }
            } else if(opcao == 6){
               if(pilha1.estaCheia() == true){
                cout << "A pilha esta cheia" << endl;
               }else {
                    cout << "A pilha nao esta cheia" << endl;
               }
            }

        }while(opcao != 0);

 
        return 0;
    }

  