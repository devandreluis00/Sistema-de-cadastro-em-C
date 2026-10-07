#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

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
        // Menu de opcoes
        printf("\n======= Cadastro de Alunos ===========\n");
        printf("1 - Cadastrar\n");
        printf("2 - Consultar\n");
        printf("3 - Listar\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
        printf("0 - Sair\n");

        // Selecionar a opcao
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:

                // Caso tenha 20 alunos ou mais, ele nao deixa criar mais alunos
                if(total >= 20){

                    printf("Numero de alunos atingido.\n");

                }else{

                    printf("\n===== CADASTRO =====\n");

                    printf("Matricula: ");
                    scanf("%d", &matricula[total]);

                    printf("Nome: ");
                    scanf(" %[^\n]", nome[total]);

                    printf("Idade: ");
                    scanf("%d", &idade[total]);

                    printf("Curso: ");
                    scanf(" %[^\n]", curso[total]);

                    // Incrementa a quantidade de alunos
                    total++;

                    printf("Aluno cadastrado com sucesso!\n");
                }

                break;
            case 2: {
                
                // Variáveis para auxiliar na busca
                int busca;
                int encontrado = 0;

                printf("\n===== CONSULTA =====\n");

                // Solicita a matrícula que o usuário deseja procurar
                printf("Digite a matricula: ");
                scanf("%d", &busca);

                // Percorre todos os alunos cadastrados até o momento
                for(int i = 0; i < total; i++){

                    // Verifica se a matrícula atual é igual à buscada
                    if(matricula[i] == busca){

                        // Exibe os dados do aluno encontrado
                        printf("\nMatricula: %d\n", matricula[i]);
                        printf("Nome: %s\n", nome[i]);
                        printf("Idade: %d\n", idade[i]);
                        printf("Curso: %s\n", curso[i]);

                        // Sinaliza que o aluno foi encontrado
                        encontrado = 1;

                        // Interrompe o loop, pois já achou o que procurava
                        break;
                    }
                }

                // Se a variável 'encontrado' continuar 0, significa que o aluno não existe
                if(encontrado == 0){
                    printf("Registro nao encontrado.\n");
                }

                break;
            }
            case 3:

                printf("\n===== LISTAGEM DE ALUNOS =====\n");

                // Verifica se o sistema está vazio (nenhum aluno cadastrado)
                if(total == 0){

                    printf("Nenhum registro cadastrado.\n");

                }else{

                    // Se houver alunos, percorre e imprime os dados de cada um
                    for(int i = 0; i < total; i++){

                        printf("\nAluno %d\n", i + 1);
                        printf("Matricula: %d\n", matricula[i]);
                        printf("Nome: %s\n", nome[i]);
                        printf("Idade: %d\n", idade[i]);
                        printf("Curso: %s\n", curso[i]);
                    }
                }

                break;
            case 4: {

                // Variáveis para a busca e validação
                int busca;
                int encontrado = 0;

                printf("\n===== ALTERAR ALUNO =====\n");

                // Pede a matrícula do aluno que terá os dados alterados
                printf("Digite a matricula: ");
                scanf("%d", &busca);

                // Percorre os alunos buscando a matrícula correspondente
                for(int i = 0; i < total; i++){

                    if(matricula[i] == busca){

                        // Solicita os novos dados e sobrescreve os antigos na mesma posição (i)
                        printf("Novo nome: ");
                        scanf(" %[^\n]", nome[i]);

                        printf("Nova idade: ");
                        scanf("%d", &idade[i]);

                        printf("Novo curso: ");
                        scanf(" %[^\n]", curso[i]);

                        // Confirma que o aluno foi encontrado e alterado
                        encontrado = 1;
                        printf("Aluno alterado com sucesso!\n");

                        // Para o loop após a alteração
                        break;
                    }
                }

                // Caso o loop termine sem encontrar a matrícula
                if(encontrado == 0){
                    printf("Registro nao encontrado.\n");
                }

                break;
            }
            case 5: {

                int busca;
                // Inicializa a posição como -1 para indicar que ainda não achou
                int posicao = -1; 

                printf("\n===== EXCLUIR ALUNO =====\n");

                // Solicita a matrícula a ser deletada
                printf("Digite a matricula: ");
                scanf("%d", &busca);

                // Procura a matrícula para descobrir em qual posição (índice) ela está
                for(int i = 0; i < total; i++){

                    if(matricula[i] == busca){
                        // Salva o índice onde o aluno está e para a busca
                        posicao = i;
                        break;
                    }
                }
                
                // Se a posição continuar -1, o aluno não foi encontrado
                if(posicao == -1){
                    printf("Registro nao encontrado.\n");
                }else{
                    // A partir da posição encontrada, puxa todos os próximos alunos uma casa para trás, sobrescrevendo o excluído
                    for(int i = posicao; i < total - 1; i++){

                        matricula[i] = matricula[i + 1];
                        strcpy(nome[i], nome[i + 1]); // Necessário incluir <string.h> no início do código
                        idade[i] = idade[i + 1];
                        strcpy(curso[i], curso[i + 1]);
                    }
                    
                    // Diminui o total de alunos cadastrados
                    total--;
                    printf("Aluno excluido com sucesso!\n");
                }

                break;
            }

            case 0:
                // Finaliza a execução do programa
                printf("Saindo....\n");
                break;
                
            default:
                // Trata o caso onde o usuário digita um número fora das opções do menu
                printf("Opcao invalida.\n");
        }
    } while(opcao != 0);

    return 0;
}
