#include <iostream>
using namespace std;

// Estrutura que representa uma atração com custo e diversão
struct Atraction {
    int custo;
    int diversao;
};

int main() {
    int N;
    cin >> N;

    // Vetores para armazenar os dados das atrações brutas
    int* S = new int[N];  // Força inicial da atração
    int* B = new int[N];  // Penalidade quadrática
    int* C = new int[N];  // Custo

    // Entrada dos dados das atrações
    for (int i = 0; i < N; ++i)
        cin >> S[i] >> B[i] >> C[i];

    int V;
    cin >> V;

    // Entrada dos orçamentos das V visitas
    int* K = new int[V];
    int maiorK = 0;  // Usado para definir o tamanho máximo da mochila

    for (int i = 0; i < V; ++i) {
        cin >> K[i];
        if (K[i] > maiorK)
            maiorK = K[i];
    }

    // Lista para guardar todas as atrações geradas (versões decrescentes)
    Atraction* Atractions = new Atraction[200000];  // Estimativa alta
    int pos = 0;  // Posição para inserir nova atração

    for (int i = 0; i < N; ++i) {
        int t = 1;
        while (true) {
            // Fórmula da diversão: S - (t-1)^2 * B
            int f = S[i] - (t - 1) * (t - 1) * B[i];
            if (f <= 0) break;  // Se a diversão virou 0 ou negativa, pare

            // Calcular custo total acumulado com `t` repetições
            int custo_total = t * C[i];
            if (custo_total > maiorK) break;  // Se nunca caberia, pare

            // Inserir nova versão da atração
            Atractions[pos++] = { C[i], f };
            ++t;
        }
    }

    // Libera memória dos vetores brutos
    delete[] S;
    delete[] B;
    delete[] C;

    // Vetor de programação dinâmica para knapsack (1D otimizado)
    int* dp = new int[maiorK + 1];
    for (int i = 0; i <= maiorK; ++i) dp[i] = 0;

    // Processa cada atração no estilo 0/1 knapsack
    for (int i = 0; i < pos; ++i) {
        int custo = Atractions[i].custo;
        int valor = Atractions[i].diversao;

        // Faz o update reverso no vetor dp
        for (int j = maiorK; j >= custo; --j) {
            int novo_valor = dp[j - custo] + valor;
            if (novo_valor > dp[j])
                dp[j] = novo_valor;
        }
    }

    // Imprime a resposta para cada orçamento K[v]
    for (int v = 0; v < V; ++v)
        cout << v << ": " << dp[K[v]] << '\n';

    // Libera memória
    delete[] K;
    delete[] dp;
    delete[] Atractions;

    return 0;
}
