# Algoritmos de Ordenação em C

Este projeto em linguagem C compara o desempenho de três algoritmos clássicos de ordenação — **Bubble Sort**, **Selection Sort** e **Insertion Sort** — aplicados a um vetor de structs contendo nomes e idades de pessoas.

---

## 📋 Descrição

O programa:

- Possui uma base com **mais de 500 registros** de nomes e idades.
- Aplica os três algoritmos de ordenação para ordenar os registros por nome.
- Conta e exibe o número de **comparações**, **trocas** e o **tempo de execução** de cada algoritmo.
- Imprime o vetor ordenado ao final de cada ordenação.

---

## 🧠 Algoritmos Implementados

### 🔵 Bubble Sort

**Descrição**:  
Percorre o vetor diversas vezes, comparando elementos adjacentes e trocando-os de lugar se estiverem fora de ordem. Ao final de cada passagem, o maior elemento "borbulha" para o final da lista.

**Complexidade**:
- Melhor caso: O(n) (com verificação de troca)
- Caso médio: O(n²)
- Pior caso: O(n²)

### 🟢 Selection Sort

**Descrição**:  
Percorre o vetor buscando o menor elemento e o coloca na primeira posição, depois busca o segundo menor e o coloca na segunda posição, e assim por diante.

**Complexidade**:
- Melhor caso: O(n²)
- Caso médio: O(n²)
- Pior caso: O(n²)

**Obs**: Mesmo que o vetor esteja ordenado, ele sempre realiza o mesmo número de comparações.

### 🟡 Insertion Sort

**Descrição**:  
Constrói a lista ordenada inserindo um elemento de cada vez na posição correta. É eficiente para listas pequenas ou parcialmente ordenadas.

**Complexidade**:
- Melhor caso: O(n)
- Caso médio: O(n²)
- Pior caso: O(n²)

---

## 📌 Estrutura do Struct

```c
typedef struct {
    char nome[100];
    int idade;
} Pessoa;
