#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[100];
    int idade;
} Pessoa;

void Bubble_Sort(Pessoa pessoas[], int quantidade, int *comparacao, int *trocas) {
    *comparacao = 0, *trocas = 0;
    Pessoa temp;

    for (int i = 0; i < quantidade - 1; i++) {
        for (int j = 0; j < quantidade - i - 1; j++) {
            (*comparacao)++;
            if (strcmp(pessoas[j].nome, pessoas[j + 1].nome) > 0) {
                temp = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temp;
                (*trocas)++;
            }
        }
    }
}

void selection_sort(Pessoa pessoas[], int quantidade, int *comparacao, int *trocas) {
    *comparacao = 0, *trocas = 0;
    Pessoa temp;

    for (int i = 0; i < quantidade - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < quantidade; j++) {
            (*comparacao)++;
            if (strcmp(pessoas[j].nome, pessoas[min_idx].nome) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            temp = pessoas[i];
            pessoas[i] = pessoas[min_idx];
            pessoas[min_idx] = temp;
            (*trocas)++;
        }
    }
}

void insert_sort(Pessoa pessoas[], int quantidade, int *comparacao, int *trocas) {
    *comparacao = 0, *trocas = 0;
    Pessoa temp;

    for (int i = 1; i < quantidade; i++) {
        temp = pessoas[i];
        int j = i - 1;
        while (j >= 0) {
            (*comparacao)++;
            if (strcmp(pessoas[j].nome, temp.nome) > 0) {
                pessoas[j + 1] = pessoas[j];
                (*trocas)++;
                j--;
            } else {
                break;
            }
        }
        pessoas[j + 1] = temp;
        if (j + 1 != i)
            (*trocas)++;
    }
}

void copiarPessoas(Pessoa destino[], Pessoa origem[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        destino[i] = origem[i];
    }
}

void imprimirPessoas(Pessoa pessoas[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("Nome: %-10s Idade: %d\n", pessoas[i].nome, pessoas[i].idade);
    }
}

int main() {
    Pessoa nomesOriginais[] = {
    {"Carlos", 30}, {"Ana", 25}, {"Beatriz", 22}, {"Daniel", 35}, {"Elisa", 27},
    {"Fernando", 40}, {"Gabriela", 19}, {"Helena", 33}, {"Luis", 28}, {"Joana", 24},
    {"Paloma", 37}, {"Lúcia", 20}, {"Marcos", 26}, {"Natália", 31}, {"Otávio", 38},
    {"Patrícia", 23}, {"Melissa", 41}, {"Rafaela", 29}, {"Samuel", 32}, {"Tainá", 21},
    {"Ulisses", 45}, {"Vanessa", 34}, {"Wagner", 36}, {"Marta", 18}, {"Yuri", 30},
    {"Sara", 39}, {"Amanda", 27}, {"Bruno", 33}, {"Cíntia", 25}, {"Diego", 42},
    {"Eduarda", 22}, {"Bruna", 29}, {"Giovana", 24}, {"Henrique", 35}, {"Isabela", 28},
    {"Juliana", 30}, {"Kaio", 23}, {"Larissa", 21}, {"Gabriella", 37}, {"Nina", 19},
    {"Orlando", 43}, {"Paula", 26}, {"Quezia", 34}, {"Renato", 20}, {"Sabrina", 38},
    {"Tiago", 27}, {"Ursula", 22}, {"Vitor", 36}, {"William", 32}, {"Zeca", 31},
    {"Aline", 26}, {"Bianca", 24}, {"Camila", 30}, {"Douglas", 29}, {"Eduardo", 34},
    {"Fábio", 27}, {"Gustavo", 21}, {"Hugo", 25}, {"Ítalo", 28}, {"Jéssica", 33},
    {"Karla", 20}, {"Letícia", 23}, {"Matheus", 31}, {"Nicole", 19}, {"Otávia", 40},
    {"Pedro", 32}, {"Quésia", 22}, {"Raquel", 35}, {"Silvia", 26}, {"Tatiane", 41},
    {"Ubirajara", 36}, {"Valéria", 39}, {"Washington", 38}, {"Xuxa", 18}, {"Yasmin", 30},
    {"Zuleika", 21}, {"Alana", 20}, {"Breno", 34}, {"Caio", 23}, {"Daniele", 25},
    {"Elias", 29}, {"Felipe", 33}, {"Geovana", 27}, {"Heitor", 28}, {"Ingrid", 19},
    {"João", 30}, {"Kelly", 24}, {"Leonardo", 26}, {"Milena", 22}, {"Nathan", 37},
    {"Olívia", 31}, {"Priscila", 35}, {"Rogério", 40}, {"Simone", 38}, {"Túlio", 43},
    {"Uelinton", 18}, {"Vitória", 28}, {"Wesley", 34}, {"Xavier", 36}, {"Yanca", 21},
    {"Zion", 30}, {"Adriana", 25}, {"Bárbara", 22}, {"Cauã", 27}, {"Débora", 19},
    {"Enzo", 22}, {"Sophia", 20}, {"Miguel", 29}, {"Alice", 24}, {"Arthur", 31},
    {"Laura", 26}, {"Heitor", 35}, {"Manuela", 23}, {"Maria", 38}, {"Noah", 21},
    {"Isabella", 33}, {"Gabriel", 28}, {"Heloísa", 20}, {"Benício", 37}, {"Luísa", 25},
      {"Leonardo", 33}, {"Isabela", 28}, {"Gustavo", 20}, {"Manuela", 37}, {"Davi", 25},
    {"Ana Júlia", 40}, {"Felipe", 19}, {"Laura", 32}, {"Samuel", 27}, {"Sophia", 30},
    {"Daniel", 22}, {"Carolina", 34}, {"Heitor", 29}, {"Elisa", 21}, {"João Pedro", 36},
    {"Larissa", 23}, {"Mariana", 31}, {"Gabriel", 26}, {"Lívia", 39}, {"Murilo", 20},
    {"Sofia", 33}, {"Arthur", 28}, {"Beatriz", 24}, {"Thiago", 37}, {"Manuela", 22},
    {"Pedro", 41}, {"Giovanna", 18}, {"Lucas", 30}, {"Alice", 27}, {"Guilherme", 35},
    {"Júlia", 23}, {"Enzo", 38}, {"Maria Eduarda", 21}, {"Matheus", 33}, {"Luana", 28},
    {"Rafael", 20}, {"Isadora", 37}, {"João Lucas", 25}, {"Helena", 40}, {"Bruno", 19},
    {"Maria Clara", 32}, {"Gabriel", 27}, {"Heloísa", 30}, {"Felipe", 22}, {"Sophia", 34},
    {"Antônio", 29}, {"Laura", 21}, {"Bernardo", 36}, {"Lorena", 23}, {"Lucas", 31},
    {"Valentina", 26}, {"Enzo", 39}, {"Maria Alice", 20}, {"Davi", 33}, {"Isabela", 28},
    {"Gustavo", 24}, {"Manuela", 37}, {"Heitor", 22}, {"Pedro Henrique", 41}, {"Larissa", 18},
    {"Samuel", 30}, {"João", 27}, {"Beatriz", 35}, {"Arthur", 23}, {"Maria Julia", 38},
    {"Felipe", 21}, {"Carolina", 33}, {"Leonardo", 28}, {"Ana Luísa", 20}, {"Thiago", 37},
    {"Eliza", 25}, {"Daniel", 40}, {"Maria Fernanda", 19}, {"Bruno", 32}, {"Ana Laura", 27},
    {"Marcelo", 30}, {"Vitória", 22}, {"Guilherme", 34}, {"Pietra", 29}, {"Luiz Miguel", 21},
    {"Lívia", 36}, {"Rodrigo", 23}, {"Nicole", 31}, {"Enzo Gabriel", 26}, {"Laura", 39},
    {"Diego", 20}, {"Mariana", 33}, {"João Gabriel", 28}, {"Manuela", 24}, {"Gustavo", 37},
    {"Evelyn", 22}, {"Carlos Eduardo", 41}, {"Pâmela", 18}, {"Lucas Gabriel", 30}, {"Sarah", 27},
    {"Rafael", 35}, {"Vitória", 23}, {"Luiz Felipe", 38}, {"Carolina", 21}, {"Marcelo", 33},
    {"Sofia", 28}, {"Fernando", 20}, {"Ester", 37}, {"Arthur", 25}, {"Isadora", 40},
    {"João Vitor", 19}, {"Giovanna", 32}, {"André", 27}, {"Brenda", 30}, {"Ricardo", 22},
    {"Júlia", 34}, {"Bruno", 29}, {"Sophia", 21}, {"Eduarda", 36}, {"Caio", 23},
    {"Mariana", 31}, {"Pedro", 26}, {"Beatriz", 39}, {"Antônio", 20}, {"Heloísa", 33},
    {"Miguel", 28}, {"Laura", 24}, {"Enzo", 37}, {"Helena", 22}, {"Arthur", 41},
    {"Maria Luísa", 18}, {"João Gabriel", 30}, {"Alice", 27}, {"Bernardo", 35}, {"Lorena", 23},
    {"Lucas", 38}, {"Valentina", 21}, {"Leonardo", 33}, {"Isabela", 28}, {"Gustavo", 20},
    {"Manuela", 37}, {"Davi", 25}, {"Ana Júlia", 40}, {"Felipe", 19}, {"Laura", 32},
    {"Samuel", 27}, {"Sophia", 30}, {"Daniel", 22}, {"Carolina", 34}, {"Heitor", 29},
    {"Elisa", 21}, {"João Pedro", 36}, {"Larissa", 23}, {"Mariana", 31}, {"Gabriel", 26},
    {"Lívia", 39}, {"Murilo", 20}, {"Sofia", 33}, {"Arthur", 28}, {"Beatriz", 24},
    {"Thiago", 37}, {"Manuela", 22}, {"Pedro", 41}, {"Giovanna", 18}, {"Lucas", 30},
    {"Alice", 27}, {"Guilherme", 35}, {"Júlia", 23}, {"Enzo", 38}, {"Maria Eduarda", 21},
    {"Matheus", 33}, {"Luana", 28}, {"Rafael", 20}, {"Isadora", 37}, {"João Lucas", 25},
    {"Helena", 40}, {"Bruno", 19}, {"Maria Clara", 32}, {"Gabriel", 27}, {"Heloísa", 30},
    {"Felipe", 22}, {"Sophia", 34}, {"Antônio", 29}, {"Laura", 21}, {"Bernardo", 36},
    {"Lorena", 23}, {"Lucas", 31}, {"Valentina", 26}, {"Enzo", 39}, {"Maria Alice", 20}
    };

    int quantidade = sizeof(nomesOriginais) / sizeof(nomesOriginais[0]);

    Pessoa nomesBubble[quantidade];
    Pessoa nomesSelect[quantidade];
    Pessoa nomesInsert[quantidade];

    int compBubble = 0, trocasBubble = 0;
    int compSelect = 0, trocasSelect = 0;
    int compInsert = 0, trocaInsert = 0;

    copiarPessoas(nomesInsert, nomesOriginais, quantidade);
    clock_t inicio = clock();
    insert_sort(nomesInsert, quantidade, &compInsert, &trocaInsert);
    clock_t fim = clock();
    double tempoInsert =  ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;

    copiarPessoas(nomesBubble, nomesOriginais, quantidade);
    inicio = clock();
    Bubble_Sort(nomesBubble, quantidade, &compBubble, &trocasBubble);
    fim = clock();
    double tempoBubble = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;

    copiarPessoas(nomesSelect, nomesOriginais, quantidade);
    inicio = clock();
    selection_sort(nomesSelect, quantidade, &compSelect, &trocasSelect);
    fim = clock();
    double tempoSelect = ((double)(fim - inicio)) / CLOCKS_PER_SEC * 1000;

    printf("\n BUBBLE SORT\n");
    printf("Comparações: %d\nTrocas: %d\n", compBubble, trocasBubble);
    printf("Tempo: %.6f ms\n\n", tempoBubble);
    imprimirPessoas(nomesBubble, quantidade);

    printf("\nSELECTION SORT\n");
    printf("Comparações: %d\nTrocas: %d\n", compSelect, trocasSelect);
    printf("Tempo: %.6f ms\n\n", tempoSelect);
    imprimirPessoas(nomesSelect, quantidade);

    printf("\n INSETION SORT\n");
    printf("Comparações: %d\nTrocas: %d\n", compInsert, trocaInsert);
    printf("Tempo: %.6f ms\n\n", tempoInsert);
    imprimirPessoas(nomesInsert, quantidade);


    return 0;
}
