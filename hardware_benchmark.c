#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para multiplicar matrizes e estressar a CPU
void stress_cpu(int size) {
    printf("⏳ Alocando memória para matrizes %dx%d...\n", size, size);
    
    // Alocação dinâmica de memória usando ponteiros
    int **A = (int **)malloc(size * sizeof(int *));
    int **B = (int **)malloc(size * sizeof(int *));
    int **C = (int **)malloc(size * sizeof(int *));
    
    for (int i = 0; i < size; i++) {
        A[i] = (int *)malloc(size * sizeof(int));
        B[i] = (int *)malloc(size * sizeof(int));
        C[i] = (int *)malloc(size * sizeof(int));
        
        for (int j = 0; j < size; j++) {
            A[i][j] = rand() % 100;
            B[i][j] = rand() % 100;
            C[i][j] = 0;
        }
    }

    printf("🔥 Iniciando teste de estresse de processamento...\n");
    clock_t start_time = clock();

    // Multiplicação de matrizes (Custo computacional O(n^3))
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    clock_t end_time = clock();
    double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("✅ Benchmark concluído!\n");
    printf("⏱️ Tempo de execução: %f segundos.\n\n", time_spent);

    // Liberação obrigatória de memória para evitar Memory Leaks
    for (int i = 0; i < size; i++) {
        free(A[i]); free(B[i]); free(C[i]);
    }
    free(A); free(B); free(C);
    printf("🧹 Memória RAM liberada com sucesso.\n");
}

int main() {
    printf("==========================================\n");
    printf("   CPU & RAM BENCHMARK TOOL (C/C++)       \n");
    printf("==========================================\n");
    
    srand(time(NULL));
    int matrix_size = 500; // Altere para 1000 ou 2000 para fritar CPUs parrudas
    
    stress_cpu(matrix_size);
    
    return 0;
}