#include <iostream>

using namespace std;

typedef int Dado;

class noh{
    friend class lista;
private: 
    const Dado dado;
    noh* proximo;
    noh* anterior;
public:
    noh(Dado d = 0);
};

noh::noh(Dado d) : dado (d){
    proximo = NULL;
}

class lista{
private:
    noh* primeiro;
    noh* ultimo;
    int tamanho;
    void removeTodos();
    void imprimeReversoAux(noh * umNoh);
public:
    lista();
    lista(const lista& umaLista);
    ~lista();
    lista& operator = (const lista& umaLista);
    inline void insere(Dado dado);
    void insereNoFim(Dado dado);
    void insereNoInicio(Dado dado);
    void insereNaPosicao(int posicao, Dado dado);
    int procura(Dado valor);
    void imprime();
    void imprimeReverso();
    inline bool vazia();
    void removeNoFim();
    void removeNoInicio();
    void removeRepetidos();
};

lista::lista(){
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}
lista::lista (const lista& umaLista){
    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
    

    noh* aux = umaLista.primeiro;

    while (aux!= NULL){
        insereNoFim(aux -> dado);
        aux = aux -> proximo;
    }
}

lista:: ~lista(){
    removeTodos();
}

void lista:: removeTodos(){
    noh* aux = primeiro;
    noh* temp;

    while(aux != NULL){
        temp = aux;
        aux = aux -> proximo;
        delete temp;
    }

    tamanho = 0;
    primeiro = NULL;
    ultimo = NULL;
}

lista& lista::operator = (const lista& umaLista){
    removeTodos();

    noh* aux = umaLista.primeiro;

    while(aux != NULL){
        insereNoFim(aux -> dado);
        aux = aux -> proximo;
    }

    return *this;
}

void lista:: insere(Dado dado){
    insereNoFim(dado);
}

void lista:: insereNoFim(Dado dado){
    noh* novo = new noh(dado);

    if(vazia()){
        primeiro = novo;
        ultimo = novo;
    } else{
        ultimo -> proximo = novo;
        novo->anterior = ultimo;
        ultimo = novo;
    }
    tamanho++;
}

void lista:: insereNoInicio(Dado dado){
    noh* novo = new noh(dado);


    if(vazia()){
        primeiro = novo;
        ultimo = novo;
    } else {
        novo -> proximo = primeiro;
        novo->anterior = ultimo;
        primeiro = novo;
    }
}

void lista::insereNaPosicao ( int posicao, Dado dado){
    noh* novo = new noh(dado);

    if((posicao <= tamanho) and (posicao >= 0)){
        if(vazia()){
            primeiro = novo;
            ultimo = novo;
        } else if(posicao == 0){
            novo -> proximo = primeiro;
            primeiro = novo;
        } else if(posicao == tamanho){
            ultimo -> proximo = novo;
            ultimo = novo;
        } else {
            noh* aux = primeiro;
            int posAux = 0;

             while (posAux < (posicao -1)){
                aux = aux -> proximo;
                posAux++; 
            }
            novo -> proximo = aux -> proximo;
            aux -> proximo = novo;
        }
        tamanho++;
    } else{
        cerr << "Posicao Inexistente!" << endl;
        exit (EXIT_FAILURE);
    }
}

int lista::procura(Dado valor){
    noh* aux = primeiro;
    int posAux = 0;

    while((aux!=NULL)and (aux->dado != valor)){
        posAux++;
        aux = aux->proximo;
    }

    if(aux==NULL){
        posAux = -1;
    }
    return posAux;
}

void lista::imprime(){
    noh* aux = primeiro;

    while(aux!= NULL){
        cout << aux-> dado << " ";
        aux = aux-> proximo;
    }

    cout<< endl;
}

void lista::imprimeReverso(){
    imprimeReversoAux (primeiro);
    cout << endl;
}

void lista::imprimeReversoAux(noh* umNoh){
    if(umNoh != NULL){
        imprimeReversoAux(umNoh -> proximo);
        cout << umNoh -> dado << " ";
    }
}

inline bool lista:: vazia(){
    return (primeiro == NULL);
}

void lista:: removeNoFim(){
    if(vazia()){
        cerr << "Remocao em lista vazia!" << endl;
        exit(EXIT_FAILURE);
    }
    noh* aux = primeiro;
    noh* anterior;

    while(aux -> proximo != NULL){
        anterior = aux;
        aux = aux-> proximo;
    }

    delete ultimo;
    anterior->proximo = NULL;
    ultimo = anterior;
    tamanho--;

    if(tamanho == 0) primeiro = NULL;
    
}

void lista:: removeNoInicio(){
    if(vazia()){
        cerr << "Remocao em lista vazia!" << endl;
        exit(EXIT_FAILURE);
    }

    noh* removido = primeiro;
    primeiro = primeiro -> proximo;
    delete removido;
    tamanho--;

    if(vazia()) ultimo = NULL;

}

void lista::removeRepetidos()
{
    noh *compara = primeiro;
    noh *aux, *aux2, *aux3;

    while (compara->proximo != NULL)
    {
        aux = compara->proximo;
        if (aux->proximo == NULL)
        {
            if (compara->dado == aux->dado)
            {
                aux2 = aux->anterior;
                aux2->proximo = NULL;
                ultimo = aux2;
                tamanho--;
            }
        }
        while (aux->proximo != NULL)
        {
            if (compara->dado == aux->dado)
            {
                aux2 = aux->anterior;
                aux3 = aux->proximo;
                aux2->proximo = aux3;
                aux3->anterior = aux2;
                tamanho--;
                aux = aux2;
            }
            aux = aux->proximo;
            if (aux->proximo == NULL)
            {
                if (compara->dado == aux->dado)
                {
                    aux2 = aux->anterior;
                    aux2->proximo = NULL;
                    ultimo = aux2;
                    tamanho--;
                }
            }
        }
        if (compara->proximo == NULL)
        {
            break;
        }
        else
        {
            compara = compara->proximo;
        }
    }
}

int main(){
    lista minhaLista;

    int valor;
    int num;
    cin >> num;

    for(int i= 0; i<num; i++){
        cin >> valor;
        minhaLista.insere(valor);
    }

    minhaLista.removeRepetidos();
    minhaLista.imprime();
    minhaLista.imprimeReverso();

    return 0;
}