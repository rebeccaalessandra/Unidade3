#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_ALUNOS 100

typedef struct {
    int id;
    char nome[50];
    int idade;
    char idioma[20];
} Aluno;

Aluno alunos[MAX_ALUNOS];
int contadorAlunos = 0;

// Fun��o para adicionar um novo aluno
void cadastrarAluno(Aluno *novoAluno) {
    int escolhaIdioma;

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", novoAluno->nome);

    printf("Digite a idade do aluno: ");
    scanf("%d", &novoAluno->idade);

    printf("Escolha o idioma:\n");
    printf("1. Ingl�s\n");
    printf("2. Espanhol\n");
    printf("3. Franc�s\n");
    printf("Op��o: ");
    scanf("%d", &escolhaIdioma);

    // Define o idioma com base na escolha
    switch (escolhaIdioma) {
        case 1:
            strcpy(novoAluno->idioma, "Ingl�s");
            break;
        case 2:
            strcpy(novoAluno->idioma, "Espanhol");
            break;
        case 3:
            strcpy(novoAluno->idioma, "Franc�s");
            break;
        default:
            printf("Idioma inv�lido! Cadastro n�o realizado.\n");
            return;
    }

    novoAluno->id = contadorAlunos + 1; // Define o ID do aluno
    printf("Aluno cadastrado com sucesso! ID: %d, Idioma: %s\n\n", novoAluno->id, novoAluno->idioma);
}

// Fun��o para listar todos os alunos
void listarAlunos() {
    if (contadorAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }
    
    printf("Lista de Alunos:\n");
    for (int i = 0; i < contadorAlunos; i++) {
        printf("ID: %d | Nome: %s | Idade: %d | Idioma: %s\n",
               alunos[i].id, alunos[i].nome, alunos[i].idade, alunos[i].idioma);
    }
    printf("\n");
}

// Fun��o para buscar aluno por ID
void buscarAluno() {
    int id;
    printf("Digite o ID do aluno que deseja buscar: ");
    scanf("%d", &id);

    for (int i = 0; i < contadorAlunos; i++) {
        if (alunos[i].id == id) {
            printf("Aluno encontrado: Nome: %s | Idade: %d | Idioma: %s\n",
                   alunos[i].nome, alunos[i].idade, alunos[i].idioma);
            return;
        }
    }
    printf("Aluno com ID %d n�o encontrado.\n\n", id);
}

// Fun��o para editar informa��es do aluno
void editarAluno() {
    int id;
    printf("Digite o ID do aluno que deseja editar: ");
    scanf("%d", &id);

    for (int i = 0; i < contadorAlunos; i++) {
        if (alunos[i].id == id) {
            printf("Editando aluno: %s\n", alunos[i].nome);
            
            printf("Novo nome: ");
            scanf(" %[^\n]", alunos[i].nome);
            
            printf("Nova idade: ");
            scanf("%d", &alunos[i].idade);
            
            printf("Novo idioma (Ingl�s, Espanhol, Franc�s): ");
            scanf(" %[^\n]", alunos[i].idioma);
            
            if (strcmp(alunos[i].idioma, "Ingl�s") != 0 && 
                strcmp(alunos[i].idioma, "Espanhol") != 0 && 
                strcmp(alunos[i].idioma, "Franc�s") != 0) {
                printf("Idioma inv�lido! Edi��o n�o realizada.\n");
                return;
            }
            
            printf("Aluno atualizado com sucesso!\n\n");
            return;
        }
    }
    printf("Aluno com ID %d n�o encontrado.\n\n", id);
}

// Fun��o para excluir um aluno
void excluirAluno() {
    int id;
    printf("Digite o ID do aluno que deseja excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < contadorAlunos; i++) {
        if (alunos[i].id == id) {
            for (int j = i; j < contadorAlunos - 1; j++) {
                alunos[j] = alunos[j + 1];
            }
            contadorAlunos--;
            printf("Aluno exclu�do com sucesso!\n\n");
            return;
        }
    }
    printf("Aluno com ID %d n�o encontrado.\n\n", id);
}

// Fun��o principal para exibir o menu
void exibirMenu() {
    printf("Sistema de Cadastro de Alunos - Escola de Idiomas\n");
    printf("1. Cadastrar Aluno\n");
    printf("2. Listar Alunos\n");
    printf("3. Buscar Aluno\n");
    printf("4. Editar Aluno\n");
    printf("5. Excluir Aluno\n");
    printf("6. Sair\n");
    printf("Escolha uma op��o: ");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int opcao;

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (contadorAlunos < MAX_ALUNOS) {
                    cadastrarAluno(&alunos[contadorAlunos]);
                    contadorAlunos++;  // Incrementa o n�mero de alunos cadastrados
                } else {
                    printf("Limite m�ximo de alunos alcan�ado.\n");
                }
                break;
            case 2:
                listarAlunos();
                break;
            case 3:
                buscarAluno();
                break;
            case 4:
                editarAluno();
                break;
            case 5:
                excluirAluno();
                break;
            case 6:
                printf("Saindo... At� a pr�xima\n");
                break;
            default:
                printf("Op��o inv�lida! Tente novamente.\n\n");
        }
    } while (opcao != 6);

    return 0;
}

