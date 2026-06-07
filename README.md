# ⚡ CPU Matrix Benchmark & Memory Tester (C)

Uma ferramenta de baixo nível desenvolvida em C para realizar testes de estresse em unidades de processamento (CPU) e avaliar o gerenciamento de memória RAM. O algoritmo utiliza a multiplicação de matrizes densas para gerar carga computacional pesada.

## 🚀 Conceitos Técnicos Aplicados
* **Gerenciamento de Memória Dinâmica:** Uso ostensivo de ponteiros, `malloc()` e `free()` para evitar memory leaks.
* **Análise de Performance:** Medição de ciclos de clock e tempo de execução utilizando a biblioteca `<time.h>`.
* **Complexidade de Algoritmos:** Implementação proposital de lógica $O(n^3)$ para simulação de carga de trabalho intensiva no processador.

## 💻 Como executar
1. Compile o código via GCC: `gcc hardware_benchmark.c -o benchmark`
2. Execute o binário: `./benchmark` (ou `benchmark.exe` no Windows).
