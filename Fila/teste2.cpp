#include <iostream>

using namespace std;

const int maxItens = 30;

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
    int qualTamanho();
    void ordena();
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

     int fila::qualTamanho(){// verifica o tamanho
        return primeiro - ultimo;

    } 


    void fila::ordena()
{
    fila Aux;
    int maior = 0;
    int elementoCompara = 0;
    int elementosOrdenados = 0;
    int tamanho = primeiro - ultimo;
    int desemp = 0;

    while (elementosOrdenados < tamanho)
    {
        if (elementosOrdenados == 0)
        { //Primeira comparação desempilha da pilha original
            maior = remover();
            for (int i = 0; i < tamanho - (elementosOrdenados + 1); i++)
            {
                elementoCompara = remover();
                if (maior > elementoCompara)
                {
                    Aux.inserir(elementoCompara);
                }
                else
                {
                    Aux.inserir(maior);
                    maior = elementoCompara;
                }
            }
        }
        else
        { //Proximas comparações desempilham de aux e armazenam os elementos ordenados na pilha original
            maior = Aux.remover();
            for (int i = 0; i < tamanho - (elementosOrdenados + 1); i++)
            {
                elementoCompara = Aux.remover();
                if (maior > elementoCompara)
                {
                    inserir(elementoCompara);
                }
                else
                {
                    inserir(maior);
                    maior = elementoCompara;
                }
            }
            for (int i = 0; i < tamanho - (elementosOrdenados + 1); i++)
            {
                //Desempilha os elementos desordenados de A em aux para a proxima comparação
                desemp = remover();
                Aux.inserir(desemp);
            }
        }
        inserir(maior);
        elementosOrdenados++;
    }
}


    int main(){
        fila fila1;
        fila fila2;
        fila filaFinal;
        int num1, num2, num3;
        int item;
        int cont = 0;
        
        cin >> num1;
        for(int i = 0; i < num1; i++){
            cin >> item;
            fila1.inserir(item);
            filaFinal.inserir(item);
        }

        cin >> num2;
        for(int i = 0; i < num2; i++){
            cin >> item;
            fila2.inserir(item);
            filaFinal.inserir(item);
        }

 

        filaFinal.ordena();
        fila1.imprimir();
        fila2.imprimir();
        filaFinal.imprimir();
        

        return 0;
    }