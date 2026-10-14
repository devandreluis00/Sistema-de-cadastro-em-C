# Sistema de Cadastro de Alunos em C

## Sobre o Projeto

Este projeto foi desenvolvido como trabalho da disciplina de **Lógica de Programação**, com o objetivo de aplicar os conceitos fundamentais da linguagem C na criação de um sistema simples para gerenciamento de alunos.

O programa funciona por meio de um menu interativo no terminal, permitindo cadastrar, consultar, listar, alterar e excluir registros de alunos.

## Funcionalidades

- **Cadastrar alunos:** registra matrícula, nome, idade e curso.
- **Consultar alunos:** busca um aluno específico por meio da matrícula.
- **Listar alunos:** exibe todos os alunos cadastrados.
- **Alterar dados:** permite modificar o nome, a idade e o curso de um aluno.
- **Excluir alunos:** remove um aluno do sistema.
- **Validar matrículas:** impede o cadastro de duas pessoas com a mesma matrícula.
- **Limitar cadastros:** permite armazenar até 20 alunos.
- **Encerrar o programa:** finaliza a execução pelo menu principal.

## Tecnologias Utilizadas

- Linguagem C
- Biblioteca `stdio.h`
- Biblioteca `stdlib.h`
- Biblioteca `locale.h`
- Biblioteca `string.h`
- Biblioteca `windows.h`
- Git e GitHub para versionamento e compartilhamento do código.

## Estrutura dos Dados

O sistema utiliza vetores para armazenar as informações dos alunos durante a execução do programa.

| Vetor | Informação armazenada |
|---|---|
| `matricula` | Número de matrícula do aluno |
| `nome` | Nome completo do aluno |
| `idade` | Idade do aluno |
| `curso` | Curso do aluno |
| `total` | Quantidade de alunos cadastrados |

Os dados são mantidos em memória durante a execução. Atualmente, o sistema não utiliza banco de dados nem salva automaticamente os registros em arquivos

**Observação:** o programa utiliza comandos específicos do Windows, como `system("cls")` e `system("pause")`.

## Conceitos de Lógica de Programação Aplicados

Durante o desenvolvimento, foram utilizados os seguintes conceitos:

- Variáveis e tipos de dados.
- Vetores e matrizes.
- Estruturas condicionais (`if`, `else` e `switch`).
- Estruturas de repetição (`for` e `do while`).
- Funções de entrada e saída (`scanf` e `printf`).
- Manipulação de strings com `strcpy`.
- Busca e validação de registros.
- Organização de dados por índices.
- Operações de inclusão, consulta, alteração e exclusão.

## Participantes

Trabalho desenvolvido em grupo pelos seguintes integrantes:

- **André Luís Silva**
- **Eduardo Marinho Madureira**
- **João Victor Valentim**

## Disciplina

**Lógica de Programação**

Projeto acadêmico desenvolvido com a finalidade de praticar os fundamentos da programação em linguagem C.

  - A Inteligência Artificial foi utilizada para fins de apoio ao desenvolvimento e à documentação do projeto.
