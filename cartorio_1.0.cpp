
#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> // biblioteca responsável por cuidar das strings


int registrar() //função feita pra só chamar depois facilitando no switch para cadastrar os usuários
{
	char arquivo[40];
	char cpf[40]; 
	char nome[40];                    //criando as váriáveis
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação dos usuários
	scanf("%s", cpf); //pra salvar as strings passadas pelo usuário
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o 'w' significa escrever
	file = fopen(arquivo, "a"); //atualizo a variável
	fprintf(file, "\nCPF: "); //informo o que é na frente da informação
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //"a" de atualização e 
	fprintf(file,"\nNome:  "); //salvo com a informação
	fclose(file); //fecho o arquivo
	
	printf("\tDigite o nome a ser cadastrado: "); //peço pro usuário informação
	scanf("%s", nome); //salvo a informação
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,nome); //guarda dentro do arquivo
	fclose(file); //fecha o arquivo
	 
	file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome: ");
	fclose(file);
	
	printf("\tDigite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\nCargo: ");
	fclose(file);
	
	printf("\tDigite o cargo da pessoa cadastrada: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	
	system("pause"); //pausa a tela pro usuário

	
}

int consultar() //função feita pra só chamar depois facilitando no switch
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //criando as variáveis na consulta
	char conteudo[200]; 
	
	printf("\tDigite o CPF a ser consultado: "); //pedindo informação
	scanf("%s",cpf); //guardando a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //indica que irá LER(r) o arquivo
	
	if(file == NULL) //cria a váriavel que será passada pro usuário caso não tenha no sistema
	{ 
	    printf("\tNão foi possível abrir o arquivo, não localizado! \n");
	}
	
	printf("\nEssas são as informações dos usuários, "); //passa as informações
	
	while(fgets(conteudo, 200, file) != NULL) //mostra as informações que existem daquele usuário
	{
		printf("%s", conteudo);
	}
	
	system("pause"); //pausa a tela pro usuário
	
}

int deletar() //função feita pra só chamar depois facilitando no switch
{
	char cpf[40]; //cria a variável no deletar
	
	printf("\tDigite o CPF do usuário a ser deletado: "); //pede a informação
	scanf("%s",cpf); //guarda a informação
	
	remove(cpf); //criando o deletar o cpf do usuário
	
	FILE *file; //cria e chama o arquivo
	file = fopen(cpf, "r"); //indica a leitura do arquivo a ser deletado
	
	if(file == NULL) //cria a informação a ser passada pro usuário caso não tenha o cpf
	{
		printf("\tO usuário não se encontra no sistema! \n");
		system("pause");
	}
	
	if(file != NULL) //cria a informação a ser passada pro usuário caso tenha o cpf 
	{
		printf("\tO usuário foi deletado com sucesso! \n");
		system("pause");
	}
	
}

int main() //função principal 
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls"); //limpando tela
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("###Cartório da EBAC###\n\n"); //Início do menu
	printf("Escolha a opção desejada no menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n"); 
	printf("Opção:"); //Fim do menu
	
	
	scanf("%d", &opcao); // Armazenando a escolha do usuário 
	
	system("cls"); //como limpar a tela
	
	switch(opcao) //incio da seleção do menu
	{
		case 1:
		registrar(); //chamada de funções
		break;
		
		case 2:
		consultar();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("\tEssa opção não está disponível\n");
		system("pause");  //pausando pra não voltar
		break;
		
	}	//Fim da seleção 
			
		
	}
	

}

