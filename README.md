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

```

## 📊 Desempenho dos Algoritmos de Ordenação

| Algoritmo      | Trocas | Comparações | Tempo (média de 5 execuções) |
|----------------|--------|-------------|-------------------------------|
| Selection Sort | 299    | 46.360      | 0.0 ms                        |
| Insertion Sort | 25.307 | 25.319      | 0.6 ms                        |
| Bubble Sort    | 25.020 | 46.360      | 4.3 ms                        |

> ℹ️ **Obs:** Os dados de tempo são médias calculadas a partir de 5 execuções consecutivas.

Diante dos resultados conclui-se que o Selection Sort possui melhor desempenho em comparacão com os outros algoritmos de ordenação apresentados

## 🚀 Como Executar

### 1. Pré-requisitos  
Tenha um compilador C instalado:

- **Windows**: MinGW, VsCode ou Code::Blocks  
- **Linux**:
  ```bash
  sudo apt update
  sudo apt install gcc
  
  ```
### 2. Baixar o Projeto
Via Git:
```bash
Copiar
Editar
git clone https://github.com/seu-usuario/seu-repositorio.git
cd seu-repositorio

```

Ou via ZIP:
Acesse o repositório no GitHub

Clique em Code > Download ZIP

Extraia os arquivos no seu computador

### 3. Compilar o Código
No terminal, execute:

````bash
Copiar
Editar
gcc main.c -o ordenacao
````

### 4. Executar o Programa
Linux/Mac:
```bash
Copiar
Editar
./ordenacao
```
Windows:

```bash
Copiar
Editar
ordenacao.exe
```
👩‍💻 **Desenvolvido por [Phaola Paraguai da Paixão Lustosa]**



