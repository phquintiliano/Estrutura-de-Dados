#include <iostream>
using namespace std;

class Aluno{
  private: 
    int ra;
    string nome;

  public:
    Aluno();
    Aluno(int r, string n);
    int obterRa();
    string obterNome();
};

Aluno :: Aluno(){
  ra = -1;
  nome = " ";
}

Aluno :: Aluno(int r, string n){
  ra = r;
  nome = n;
}

int Aluno :: obterRa(){
  return ra;
}

string Aluno :: obterNome(){
  return nome; 
}


class Hash{
  private:
    int FuncaoHash(Aluno aluno);
    int max_itens;
    int max_posicoes;
    int quant_itens;
    Aluno* estrutura;


  public:
    Hash(int tam_vetor, int max);
    ~Hash();
    bool estacheio();
    int obterTamanhoAtual();
    void inserir(Aluno aluno);
    void deletar(Aluno aluno);
    void buscar(Aluno& aluno, bool& busca);
    void imprimir();
};

  int Hash :: FuncaoHash(Aluno aluno){
    return (aluno.obterRa() % max_posicoes);
  }

  Hash :: Hash(int tam_vetor, int max){
    quant_itens = 0;
    max_itens = max;
    max_posicoes = tam_vetor;
    estrutura = new Aluno[tam_vetor];
  }

  Hash :: ~Hash(){
    delete [] estrutura;
  }

  bool Hash :: estacheio(){
    return (quant_itens == max_itens);
  }

  int Hash :: obterTamanhoAtual(){
    return (quant_itens);
  } 

  void Hash :: inserir(Aluno aluno){
    int local = FuncaoHash(aluno);
    estrutura[local] = aluno;
    quant_itens++;
  }
  void Hash :: deletar(Aluno aluno){
    int local = FuncaoHash(aluno);
    if(estrutura[local].obterRa() != -1){
      estrutura[local] = Aluno (-1, " ");
      quant_itens--;
    }
  }

  void Hash :: buscar(Aluno& aluno, bool& busca){
    int local = FuncaoHash(aluno);
    Aluno aux = estrutura[local];
    if(aluno.obterRa() != aux.obterRa()){
      busca = false;
    } else{
      busca = true;
      aluno = aux;

    }
  }
  void Hash :: imprimir(){
    cout << "Tabela Hash:\n";
    for(int i = 0; i < max_posicoes; i++){
      if(estrutura[i].obterRa() != -1){
        cout << i << ":" << estrutura[i].obterRa();
        cout << estrutura[i].obterNome() << endl;
      }
    }
  }

  int main(){
    cout << "Programa gerador de Hash!\n";
    int tam_vetor, max;
    cout << "Digite o tamanho da Hash\n";
    cin >> tam_vetor;
    cout << "Digite o numer maximo de elementos!\n";
    cin >> max;
    cout << "O fator de carga e: " << (float)max/ (float)tam_vetor << endl;
    Hash alunohash(tam_vetor, max);
    int opcao;
    int ra;
    string nome;
    bool busca;

    do{
      cout << "Digite 0 para para o algoritmo!/n";
      cout << "Digite 1 para inserir um elemento!/n";
      cout << "Digite 2 para remover um elemento!/n";
      cout << "Digite 3 para busca um elemento!/n";
      cout << "Digite 4 para imprimir a Hash!/n";
      cin >> opcao;

        if(opcao == 1){
          cout << "Qual o RA do aluno?\n";
          cin >> ra;
          cout << "Qual o nome do aluno?\n";
          cin >> nome;
          Aluno aluno(ra,nome);
          alunohash.inserir(aluno);
        } else if(opcao == 2){
          cout << "Qual e o RA do aluno a ser removido?\n";
          cin>> ra;
          Aluno aluno(ra, " ");
          alunohash.deletar(aluno);
        } else if(opcao == 3){
          cout << "Qual e o RA do aluno a ser buscado";
          cin >> ra;
          Aluno aluno(ra, " ");
          alunohash.buscar(aluno, busca);
          if(busca){
            cout << "Aluno encontrado:\n" << endl;
            cout << "RA: " << aluno.obterRa() << endl;
            cout << "Nome:" << aluno.obterNome() << endl;
          } else{
            cout << "Aluno nao encontrado!\n";
          }
        } else if (opcao == 4){
          alunohash.imprimir();
        }


    } while (opcao == 1);

    return 0;
  }