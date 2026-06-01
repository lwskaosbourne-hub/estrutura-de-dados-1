#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_ACERVO 20 // Define uma constante do máximo de livros no acervo.

// Estrutura base dos livros:
struct Livro {
	int codigo;
	char titulo[50];
	char autor[30];
	char area[30];
	int ano;
	char editora[30];
};

// Assinaturas das funções antes do main, elas serão definidas no fim do código:
void cadastrarLivros(struct Livro acervo[], int tamanho);
void excluirLivro(struct Livro acervo[], int id);
void imprimirLivros(struct Livro acervo[], int tamanho);
void pesquisarLivro(struct Livro acervo[], int tamanho);
void ordenarLivros(struct Livro acervo[], int tamanho);
////////////////////////////////////////////////////////
void salvarAcervo(struct Livro acervo[], int tamanho); // Função para salvar arquivos.
void carregarAcervo(struct Livro acervo[], int tamanho); // Função para carregar os dados do programa.

int main(void){
	int StatusDoSistema = 0; // Variável responsável pela estrutura while. Enquanto ela valer 0 o sistema ficará ativo, quando for 1 ele será encerrado.
	
	struct Livro acervo[TAMANHO_ACERVO]; // Cria um Vetor com o mesmo tamanho da variável constante definida no começo do código (20).
										// Cada espaço do Vetor recebrá a estrutura criada para um livro contendo todas as variáveis necessárias.
				
	
	for (int i = 0; i < TAMANHO_ACERVO; i++){
		acervo[i].codigo = 0;
	}

	carregarAcervo(acervo, TAMANHO_ACERVO); // Carrega os dados.
	
	// Início do sistema (Mensagem de entrada do sistema):
	printf("====================================================\n====== SISTEMA DE ESTOQUE DO ACERVO DE LIVROS ======\n====================================================\n");
	
	// Inicia um sistema de repetição onde o usuário poderá selecionar entre:
	// 1 - Cadastrar livros
	// 2 - Imprimir todos os livros
	// 3 - Pesquisar livro por código
	// 4 - Ordenar livros por ano de publicação
	// 5 - Sair do programa
	
	while(StatusDoSistema < 1) {
		int opcao; // Responsável por receber a opção escolhida pelo usuário.
		printf("====================================================\nSelecione uma opcao: \n");
		printf("1 - Cadastrar livros \n2 - Imprimir todos os livros \n3 - Pesquisar livro por codigo \n4 - Ordenar livros por ano de publicacao \n5 - Excluir livro \n6 - Sair do programa e salvar dados\n");
		scanf("%d", &opcao);
		fflush(stdin);
		
		switch(opcao) {
			case 1: // Chama a função cadastrarLivros
				cadastrarLivros(acervo, TAMANHO_ACERVO);
				break;
			case 2: // Chama a função imprimirLivros
				imprimirLivros(acervo, TAMANHO_ACERVO);
				break;
			case 3: // Chama a função pesquisarLivro
				pesquisarLivro(acervo, TAMANHO_ACERVO);
				break;
			case 4: // Chama a função ordenarLivros
				ordenarLivros(acervo, TAMANHO_ACERVO);
				break;
			case 5:
				excluirLivro(acervo, TAMANHO_ACERVO);
				break;
			case 6:
				salvarAcervo(acervo, TAMANHO_ACERVO); // Chama a função de salvar os dados em um arquivo.
				StatusDoSistema = 1; // Quebra o ciclo de repetição e encerra o programa.
				break;
			default:
				printf("\nSELECIONE UMA OPCAO VALIDA!!!\n\n");
				break;
		}
	}
	
	// Fim do programa.
	return 0;
}

void cadastrarLivros(struct Livro acervo[], int tamanho){
	for (int i = 0; i < tamanho; i++){
		if (acervo[i].codigo == 0){ // Se o código for igual a 0, então ele irá sobrescrever os valores conforme atribuído pelo usuário.
			printf("=== CADASTRO DE LIVROS ===\n");

			printf("Codigo: ");
			scanf("%d", &acervo[i].codigo);
			fflush(stdin);

			printf("Titulo: ");
			scanf(" %50[^\n]s", &acervo[i].titulo);
			fflush(stdin);

			printf("Autor: ");
			scanf(" %30[^\n]s", &acervo[i].autor);
			fflush(stdin);

			printf("Area: ");
			scanf(" %30[^\n]s", &acervo[i].area);
			fflush(stdin);

			printf("Ano: ");
			scanf("%d", &acervo[i].ano);
			fflush(stdin);

			printf("Editora: ");
			scanf(" %30[^\n]s", &acervo[i].editora);
			fflush(stdin);

			printf("\nLIVRO CADASTRADO!\n\n");

			return;
		} else{
			// Se ao final do loop todos os campos estiverem cheios, será mostrada a seguinte mensagem:
			if (i == tamanho - 1)
			{
				printf("\nO ACERVO JA ESTA CHEIO!!!\n\n");
			}
			
		}
	}

	return;
}

void excluirLivro(struct Livro acervo[], int tamanho){
	int id;
	printf("\nInforme o código do livro: ");
	scanf("%d", &id);
	fflush(stdin);

	for (int i = 0; i < tamanho; i++)
	{
		if(acervo[i].codigo == id){
			acervo[i].ano = 0;
			strcpy(acervo[i].area, "");
			strcpy(acervo[i].autor, "");
			strcpy(acervo[i].editora, "");
			strcpy(acervo[i].titulo, "");
			acervo[i].codigo = 0;

			printf("\nLIVRO EXCLUIDO!");
		} else{
			if(i == tamanho-1){
				printf("\nLIVRO NÃO ENCONTRADO!");
			}
		}
	}
	
	return;
}

void imprimirLivros(struct Livro acervo[], int tamanho){
	for (int i = 0; i < tamanho; i++){
		if (acervo[i].codigo != 0){ // Nesse caso é verificado se o código do produto é DIFERENTE de 0.
			printf("\n- LIVRO %d\n", i + 1);
        	printf("Codigo: %d\n", acervo[i].codigo);
        	printf("Titulo: %s\n", acervo[i].titulo);
        	printf("Autor: %s\n", acervo[i].autor);
        	printf("Area: %s\n", acervo[i].area);
        	printf("Ano: %d\n", acervo[i].ano);
        	printf("Editora: %s\n", acervo[i].editora);
		}
	}
}

void pesquisarLivro(struct Livro acervo[], int tamanho){
	int codigoBusca; // Cria uma variável local que será atribuída pelo usuário.
	int acha = 0, i = 0;
	printf("Digite o codigo: ");
	scanf("%d", &codigoBusca);
	fflush(stdin);

	while ((acha == 0) && (i < tamanho)){
		if (acervo[i].codigo == codigoBusca){
 			acha = 1;
 		} else {
 			i++;
 		}
 	}
 	if (acha == 1){
		printf("\nLIVRO %d\n", i + 1);
        printf("Codigo: %d\n", acervo[i].codigo);
        printf("Titulo: %s\n", acervo[i].titulo);
        printf("Autor: %s\n", acervo[i].autor);
        printf("Area: %s\n", acervo[i].area);
        printf("Ano: %d\n", acervo[i].ano);
        printf("Editora: %s\n", acervo[i].editora);
	} else {
		printf("\nLIVRO NAO ENCONTRADO!\n\n");
	}
}

void ordenarLivros(struct Livro acervo[], int tamanho){
	// Função feita utilizando a técnica de BubbleSort:
	struct Livro troca;

	for (int i = 0; i < tamanho; i++)
	{
		for (int j = 0; j < tamanho; j++)
		{
			if (acervo[i].ano > acervo[j].ano)
			{
				troca = acervo[i];
				acervo[i] = acervo[j];
				acervo[j] = troca;
			}
			
		}
		
	}
	
	printf("\nLIVROS ORDENADOS COM SUCESSO!\n\n");
}

void salvarAcervo(struct Livro acervo[], int tamanho){
	FILE *arquivo;
	arquivo = fopen("acervo.txt", "w"); // Abre o arquivo onde será salvo os livros com o parâmetro "w", que significa que será aberto para escrita.

	if(arquivo == NULL){ // Verifica se o arquivo existe.
		printf("\nERRO AO CRIAR O ARQUIVO!\n\n");
		return;
	}

	for (int i = 0; i < tamanho; i++)
	{
		fprintf(arquivo, "%d;%s;%s;%s;%d;%s;\n", // Função que escreve dados FORMATADOS dentro do arquivo.
			acervo[i].codigo,
			acervo[i].titulo,
			acervo[i].autor,
			acervo[i].area,
			acervo[i].ano,
			acervo[i].editora
		);
	}
	
	fclose(arquivo); // Fecha o arquivo.
	printf("\nACERVO SALVO COM SUCESSO!\n\n");
}

void carregarAcervo(struct Livro acervo[], int tamanho) {
    FILE *arquivo; // Cria um ponteiro na memória para o arquivo.
    arquivo = fopen("acervo.txt", "r"); // Abre o arquivo onde será salvo os livros com o parâmetro "r", que significa que será aberto para leitura.

    if (arquivo == NULL) {
        // Se o arquivo não existir então ele apenas retorna e segue com o programa normalmente.
        return;
    }

    int i = 0; // Cria um contador para preencher o vetor.

    while (!feof(arquivo) && i < tamanho) { // Verifica se ainda não chegou no fim do arquivo e se ainda há espaço no vetor.
        fscanf(arquivo, "%d;%49[^;];%29[^;];%29[^;];%d;%29[^\n]", // É lido exatamente da mesma forma que foi salvo com fprintf().
            &acervo[i].codigo,
            acervo[i].titulo,
            acervo[i].autor,
            acervo[i].area,
            &acervo[i].ano,
            acervo[i].editora
        );
        i++;
    }

    fclose(arquivo); // Fecha o arquivo.
}
