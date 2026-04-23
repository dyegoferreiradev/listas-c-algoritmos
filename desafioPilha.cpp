/*
Grupo:
Dyego Ferreira da Silva (dfs10)
Paulo Vinícius Aquino dos Santos (pvas2)
*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
#define typeItem double

struct Node
{
    typeItem valor;
    Node *proximo;
    Node *anterior;
};

// PILHA
class Stack
{
public:
    Node *Topo;

    Stack()
    {
        Topo = NULL;
    }

    ~Stack()
    {
        Node *tempNode;
        while (Topo != NULL)
        {
            tempNode = Topo;
            Topo = Topo->anterior;
            delete tempNode;
        }
    }

    bool isEmpty()
    {
        return (Topo == NULL);
    }

    void inserir(typeItem item)
    {
        Node *newNode = new Node;
        newNode->valor = item;
        newNode->proximo = NULL;
        newNode->anterior = Topo;
        Topo = newNode;
    }

    typeItem remove()
    {
        if (isEmpty())
        {
            cout << "Erro: Pilha Vazia!! Underflow" << endl;
            exit(1);
        }
        else
        {
            Node *tempNode = Topo;
            Topo = Topo->anterior;
            if (Topo != NULL)
            {
                Topo->proximo = NULL;
            }
            typeItem valor = tempNode->valor;
            delete tempNode;
            return valor;
        }
    }

    typeItem top()
    {
        if (isEmpty())
        {
            cout << "Erro: Pilha Vazia!! Underflow" << endl;
            exit(1);
        }
        else
        {
            return Topo->valor;
        }
    }
};

//DECLARAÇÃO DE FUNÇÕES
int priority(char op);
string infixToPostfix(string entrada);
double calcularPosfixa(string posfixa);

int main()
{
    string entrada;
    cout << "Digite uma expressao infixa: ";
    cin >> entrada;

    string saida = infixToPostfix(entrada);
    cout << "Expressao pos-fixa: " << saida << endl;

    double resultado = calcularPosfixa(saida);
    cout << "Resultado: " << resultado << endl;

    return 0;
}

//PRIORIDADE DOS OPERADORES
int priority(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

//INFIXA PARA POSFIXA
string infixToPostfix(string entrada)
{
    Stack operadores;
    string resultado;

    for (int i = 0; i < (int) entrada.length(); i++)
    {
        // Se o caractere for operando (número ou letra) adiciona direto
        if ((entrada[i] >= '0' && entrada[i] <= '9') || (entrada[i] >= 'a' && entrada[i] <= 'z') || (entrada[i] >= 'A' && entrada[i] <= 'Z'))
        {
            resultado += entrada[i];
        }
        else if (entrada[i] == '(')
        {
            operadores.inserir(entrada[i]);
        }
        else if (entrada[i] == ')')
        {
            // remove ate achar parentese
            while (!operadores.isEmpty() && operadores.top() != '(')
            {
                resultado += operadores.remove();
            }
            operadores.remove(); // remove (
        }
        else
        {
            // Ordem de prioridade dos operadores
            while (!operadores.isEmpty() && priority(operadores.top()) >= priority(entrada[i]))
            {
                resultado += operadores.remove();
            }
            operadores.inserir(entrada[i]);
        }
    }
    while (!operadores.isEmpty())
    {
        resultado += operadores.remove();
    }

    return resultado;
}

//CALCULAR RESULTADO DA EXPRESSAO
double calcularPosfixa(string posfixa)
{
    Stack valores;

    for (int i = 0; i < (int) posfixa.length(); i++)
    {
        // Se o caractere for um número, converte e insere na pilha de valores.
        if (posfixa[i] >= '0' && posfixa[i] <= '9')
        {
            valores.inserir(posfixa[i] - '0');
        }
        else
        {
            // tirar os dois ultimos valores da pilha e faz a operação
            double b = valores.remove();
            double a = valores.remove();
            switch (posfixa[i])
            {
            case '+':
                valores.inserir(a + b);
                break;
            case '-':
                valores.inserir(a - b);
                break;
            case '*':
                valores.inserir(a * b);
                break;
            case '/':
                if (b == 0)
                {
                    cout << "Erro: Divisão por zero!" << endl;
                    exit(1);
                }
                valores.inserir(a / b);
                break;
            case '^':
                valores.inserir(pow(a, b));
                break;
            default:
                cout << "Erro: Operador inválido!" << endl;
                exit(1);
            }
        }
    }

    return valores.remove();
}