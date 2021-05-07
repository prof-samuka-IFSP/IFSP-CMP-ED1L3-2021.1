#include <stdio.h>
#include <stdlib.h>


typedef struct matriz {
    int n_linhas;  // número de amostras
    int n_colunas; // número de características
    float **data;
} Matriz;

typedef struct vetor {
    int n_elems;
    int *data;
} Vetor;


Matriz *cria_matriz(int n_linhas, int n_colunas) {
    Matriz *mat = (Matriz *) calloc(1, sizeof(Matriz));
    mat->n_linhas = n_linhas;
    mat->n_colunas = n_colunas;

    // alocando a matriz de floats
    mat->data = (float **) calloc(mat->n_linhas, sizeof(float *));
    for (int i = 0; i < mat->n_linhas; i++) {
        mat->data[i] = (float *) calloc(mat->n_colunas, sizeof(float));
    }

    return mat;
}


void destroi_matriz(Matriz **mat_ref) {
    Matriz *mat = *mat_ref;

    for (int i = 0; i < mat->n_linhas; i++) {
        free(mat->data[i]);
    }
    free(mat->data);

    free(mat);
    *mat_ref = NULL;
}


Vetor *cria_vetor(int n_elems) {
    Vetor *vet = calloc(1, sizeof(Vetor));
    vet->n_elems = n_elems;
    vet->data = (int*) calloc(vet->n_elems, sizeof(int));

    return vet;
}


void destroi_vetor(Vetor **vet_ref) {
    Vetor *vet = *vet_ref;
    free(vet->data);
    free(vet);
    *vet_ref = NULL;
}



// classifica um conjunto de testes, X_test, usando o
// algoritmo KNN
Vetor *knn(const Matrix *X_train, const Vetor *y_train,
           const Vetor *X_test, int k) {
    int n_amostras_teste = X_test->n_linhas;
    Vetor *y_test = cria_vetor(n_amostras_teste);


    // para cada amostra de teste q {
    //     para cada amostra de treino p {
    //         distancia[p] = compute_distancia(aluno_q, aluno_p)
    //         ordena(distancias) e retorna os índices originais ordenados
    //         checa qual o rótulo dos k alunos de treino (vizinhos) mais próximos ao aluno q
    //         atribui o rótulo mais frequente para o aluno de teste q
    //     }
    // }

    return y_test;
}



int main() {
    int n_amostras_treino; // número de amostras de treinamento
    int n_amostras_teste; // número de amostras de teste
    int k; // número de vizinhos + próximos

    scanf("%d %d %d", &n_amostras_treino, &n_amostras_teste, &k);
    printf("n_amostras_treino = %d\n", n_amostras_treino);
    printf("n_amostras_teste = %d\n", n_amostras_teste);
    printf("k = %d\n\n", k);

    // matriz de características
    // shape: (n_amostras_treino, 2)
    // NOTA MÉDIA, QUANTIDADE DE HORAS DE ESTUDO
    Matriz *X_train = cria_matriz(n_amostras_treino, 2);

    // vetor de rótulos para cada amostra (aluno) de treino
    Vetor *y_train = cria_vetor(n_amostras_treino);

    // LÊ OS DADOS DO CONJUNTO DE TREINAMENTO
    // obs: n_amostras_treino == X_train->n_linhas
    // para cada aluno de treino p
    for (int p = 0; p < n_amostras_treino; p++) {
        scanf("%f %f %d", &X_train->data[p][0],
                          &X_train->data[p][1],
                          &y_train->data[p]);

        printf("Aluno de Treino [%d] / %d\n", p, n_amostras_treino - 1);
        printf("Características %f, %f\n", X_train->data[p][0],
                                           X_train->data[p][1]);
        printf("Rótulo: %d\n\n", y_train->data[p]);
    }
    puts("------------------\n");


    Matriz *X_test = cria_matriz(n_amostras_teste, 2);

    // LÊ OS DADOS DO CONJUNTO DE TESTE
    // obs: n_amostras_teste == X_test->n_linhas
    // para cada aluno de teste q
    for (int q = 0; q < n_amostras_teste; q++) {
        scanf("%f %f", &X_test->data[q][0], &X_test->data[q][1]);

        printf("Aluno de Teste [%d] / %d\n", q, n_amostras_teste - 1);
        printf("Características %f, %f\n", X_test->data[q][0], X_test->data[i][1]);
    }

    destroi_matriz(&X_train);
    destroi_vetor(&y_train);
    destroi_matriz(&X_test);

    return 0;
}
