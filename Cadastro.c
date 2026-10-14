#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int matricula[20];
    char nome[20][50];
    int idade[20];
    char curso[20][50];
    int total = 0;
    int opcao;

    do {
        system("cls");

        printf("\n======= Cadastro de Alunos ===========\n");
        printf("1 - Cadastrar\n");
        printf("2 - Consultar\n");
        printf("3 - Listar\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
        printf("0 - Sair\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: {
                if (total >= 20) {
                    printf("Numero maximo de alunos atingido.\n");
                } else {
                    int novaMatricula;
                    int duplicada = 0;

                    printf("\n===== CADASTRO =====\n");
                    printf("Matricula: ");
                    scanf("%d", &novaMatricula);

                    for (int i = 0; i < total; i++) {
                        if (matricula[i] == novaMatricula) {
                            duplicada = 1;
                            break;
                        }
                    }

                    if (duplicada) {
                        printf("Erro: Esta matricula ja esta cadastrada!\n");
                    } else {
                        matricula[total] = novaMatricula;

                        printf("Nome: ");
                        scanf(" %[^\n]", nome[total]);

                        printf("Idade: ");
                        scanf("%d", &idade[total]);

                        printf("Curso: ");
                        scanf(" %[^\n]", curso[total]);

                        total++;
                        printf("Aluno cadastrado com sucesso!\n");
                    }
                }

                system("pause");
                break;
            }

            case 2: {
                int busca;
                int encontrado = 0;

                printf("\n===== CONSULTA =====\n");
                printf("Digite a matricula: ");
                scanf("%d", &busca);

                for (int i = 0; i < total; i++) {
                    if (matricula[i] == busca) {
                        printf("\nMatricula: %d\n", matricula[i]);
                        printf("Nome: %s\n", nome[i]);
                        printf("Idade: %d\n", idade[i]);
                        printf("Curso: %s\n", curso[i]);

                        encontrado = 1;
                        system("pause");
                        break;
                    }
                }

                if (encontrado == 0) {
                    printf("Registro nao encontrado.\n");
                }

                system("pause");
                break;
            }

            case 3:
                printf("\n===== LISTAGEM DE ALUNOS =====\n");

                if (total == 0) {
                    printf("Nenhum registro cadastrado.\n");
                } else {
                    for (int i = 0; i < total; i++) {
                        printf("\nAluno %d\n", i + 1);
                        printf("Matricula: %d\n", matricula[i]);
                        printf("Nome: %s\n", nome[i]);
                        printf("Idade: %d\n", idade[i]);
                        printf("Curso: %s\n", curso[i]);
                    }
                }

                system("pause");
                break;

            case 4: {
                int busca;
                int encontrado = 0;

                printf("\n===== ALTERAR ALUNO =====\n");
                printf("Digite a matricula: ");
                scanf("%d", &busca);

                for (int i = 0; i < total; i++) {
                    if (matricula[i] == busca) {
                        printf("Novo nome: ");
                        scanf(" %[^\n]", nome[i]);

                        printf("Nova idade: ");
                        scanf("%d", &idade[i]);

                        printf("Novo curso: ");
                        scanf(" %[^\n]", curso[i]);

                        encontrado = 1;
                        printf("Aluno alterado com sucesso!\n");

                        system("pause");
                        break;
                    }
                }

                if (encontrado == 0) {
                    printf("Registro nao encontrado.\n");
                }

                break;
            }

            case 5: {
                int busca;
                int posicao = -1;

                printf("\n===== EXCLUIR ALUNO =====\n");
                printf("Digite a matricula: ");
                scanf("%d", &busca);

                for (int i = 0; i < total; i++) {
                    if (matricula[i] == busca) {
                        posicao = i;
                        system("pause");
                        break;
                    }
                }

                if (posicao == -1) {
                    printf("Registro nao encontrado.\n");
                } else {
                    for (int i = posicao; i < total - 1; i++) {
                        matricula[i] = matricula[i + 1];
                        strcpy(nome[i], nome[i + 1]);
                        idade[i] = idade[i + 1];
                        strcpy(curso[i], curso[i + 1]);
                    }

                    total--;
                    printf("Aluno excluido com sucesso!\n");
                }

                system("pause");
                break;
            }

            case 0:
                printf("Saindo....\n");
                break;

            default:
                printf("Opcao invalida.\n");
                system("pause");
        }

    } while (opcao != 0);

    return 0;
}
