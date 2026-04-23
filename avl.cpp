#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Classe para representar uma Árvore AVL
class ArvoreAVL{
private:
    struct Node{
        int chave;
        Node* esquerda;
        Node* direita; 
        int altura;

        Node(int k){
            chave = k;
            esquerda = NULL;
            direita = NULL;
            altura = 1;
        }
    };

    Node* raiz;

    // Liberar a memória dos nós recursivamente
    void destrutorAVL(Node* node){
        if(node != NULL){
            destrutorAVL(node->esquerda); 
            destrutorAVL(node->direita); 
            delete node;
        }
    }

    // Calcula a altura de um nó
    int acharAltura(Node* n){
        return (n != NULL) ? n->altura : 0;
    }

    // Calcula o fator de balanceamento de um nó
    int acharBalanceamento(Node* n){
        return (n != NULL) ? acharAltura(n->esquerda) - acharAltura(n->direita) : 0;
    }

    // Realiza rotação à direita em um nó para balanceamento
    Node* rotacaoDir(Node* y){
        Node* x = y->esquerda; 
        Node* T2 = x->direita;
        x->direita = y;
        y->esquerda = T2;

        y->altura = max(acharAltura(y->esquerda), acharAltura(y->direita)) + 1;
        x->altura = max(acharAltura(x->esquerda), acharAltura(x->direita)) + 1;

        return x;
    }

    // Realiza rotação à esquerda em um nó para balanceamento
    Node* rotacaoEsq(Node* x){
        Node* y = x->direita; 
        Node* T2 = y->esquerda;
        y->esquerda = x;
        x->direita = T2;

        x->altura = max(acharAltura(x->esquerda), acharAltura(x->direita)) + 1;
        y->altura = max(acharAltura(y->esquerda), acharAltura(y->direita)) + 1;

        return y; 
    }

    // Inserir um novo valor na árvore AVL
    Node* inserir(Node* node, int chave){
        if(node == NULL){ 
            return new Node(chave);
        }

        if(chave < node->chave){
            node->esquerda = inserir(node->esquerda, chave);
        }else if(chave > node->chave){
            node->direita = inserir(node->direita, chave);
        }else{
            return node;
        }

        node->altura = 1 + max(acharAltura(node->esquerda), acharAltura(node->direita));
        int balance = acharBalanceamento(node);

        // Rotação simples à direita
        if(balance > 1 && chave < node->esquerda->chave){
            return rotacaoDir(node);
        }

        // Rotação simples à esquerda
        if(balance < -1 && chave > node->direita->chave){
            return rotacaoEsq(node);
        }

        // Rotação dupla
        if(balance > 1 && chave > node->esquerda->chave){
            node->esquerda = rotacaoEsq(node->esquerda);
            return rotacaoDir(node);
        }

        // Rotação dupla: direita-esquerda.
        if(balance < -1 && chave < node->direita->chave){
            node->direita = rotacaoDir(node->direita);
            return rotacaoEsq(node);
        }

        return node;
    }

    // Métodos para percorrer a árvore em diferentes ordens
    void preOrdem(Node* node){
        if(node != NULL){
            cout << node->chave << ", "; 
            preOrdem(node->esquerda); 
            preOrdem(node->direita);
        }
    }

    void emOrdem(Node* node){
        if(node != NULL){
            emOrdem(node->esquerda); 
            cout << node->chave << ", "; 
            emOrdem(node->direita);
        }
    }

    void posOrdem(Node* node){
        if(node != NULL){
            posOrdem(node->esquerda); 
            posOrdem(node->direita); 
            cout << node->chave << ", ";
        }
    }

public:
    // Construtor
    ArvoreAVL(){ 
        raiz = NULL;
    }

    // Destrutor
    ~ArvoreAVL(){
        destrutorAVL(raiz);
    }

    void inserir(int chave){
        raiz = inserir(raiz, chave);
    }

    // Métodos para imprimir a árvore em diferentes ordens
    void imprimirPreOrdem(){
        cout << "Pre-ordem: ";
        preOrdem(raiz);
        cout << "\b\b \n";
    }

    void imprimirEmOrdem(){
        cout << "Em-ordem: ";
        emOrdem(raiz);
        cout << "\b\b \n";
    }

    void imprimirPosOrdem(){
        cout << "Pos-ordem: ";
        posOrdem(raiz);
        cout << "\b\b \n"; 
    }

    // Método para inserir múltiplos raizes a partir de uma string separada por vírgulas
    void manipularString(const string& entrada){
        size_t start = 0;
        size_t end = entrada.find(',');

        while(end != string::npos){
            inserir(atoi(entrada.substr(start, end - start).c_str())); // Converte para int e insere.
            start = end + 1;
            end = entrada.find(',', start);
        }

        inserir(atoi(entrada.substr(start).c_str()));
    }
};

int main(){

    ArvoreAVL saida;

    cout << "Digite os numeros separados por virgulas: ";
    string entrada;
    getline(cin, entrada);

    saida.manipularString(entrada); 
    saida.imprimirPreOrdem(); 
    saida.imprimirEmOrdem(); 
    saida.imprimirPosOrdem(); 

    return 0;
}
