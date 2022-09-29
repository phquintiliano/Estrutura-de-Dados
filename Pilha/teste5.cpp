#include <iostream>

using namespace std;

const int max_itens = 100;

class pilha{
    private:
    int tamanho;
    char* estrutura; 

    public: 
    pilha(); //construtora com o mesmo nome da classe
    ~pilha(); //destrutora 
    void inserir(char item); //inserir elemento na pilha
    char remover(); //remove da pilha
    void imprimir(); //imprimi o item
    int qualTamanho(); // verifica o tamanho
};


    pilha::pilha(){  //construtora com o mesmo nome da classe
        tamanho = 0;
        estrutura = new char[max_itens];
    }

    pilha::~pilha(){  //destrutora 
        delete [] estrutura;
    } 
    


    void pilha::inserir(char item){ //inserir elemento na pilha
            estrutura[tamanho] = item;
            tamanho++;
        
    } 

    char pilha::remover(){ //remove da pilha
            tamanho--;
            return estrutura[tamanho];  

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
        pilha pilhaA;
        pilha pilhaC;
        char item;
        
        do{
		cin >> item;
        pilha1.inserir(item);

        if(item == 'A'){
            pilhaA.inserir(item);
        } else if(item == 'C'){
            pilhaC.inserir(item);
        }
		} while (item != 'X');


        while(pilhaC.qualTamanho() != 0){
            item = pilhaC.remover(); 
            item = pilhaC.remover();
            item = pilhaA.remover();
        }



        if((pilhaA.qualTamanho() != 0) || (pilhaC.qualTamanho() != 0)) {
            cout << "nao" << " " << pilhaA.qualTamanho() << " " << pilhaC.qualTamanho() << endl;
        } else{
             cout << "sim" << " " << pilhaA.qualTamanho() << " " << pilhaC.qualTamanho() << endl;
        }
		
	
        return 0;
    }
