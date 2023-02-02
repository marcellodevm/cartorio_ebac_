
#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> // biblioteca respons�vel por cuidar das strings


int registrar() //fun��o feita pra s� chamar depois facilitando no switch para cadastrar os usu�rios
{
	char arquivo[40];
	char cpf[40]; 
	char nome[40];                    //criando as v�ri�veis
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o dos usu�rios
	scanf("%s", cpf); //pra salvar as strings passadas pelo usu�rio
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo e o 'w' significa escrever
	file = fopen(arquivo, "a"); //atualizo a vari�vel
	fprintf(file, "\nCPF: "); //informo o que � na frente da informa��o
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //"a" de atualiza��o e 
	fprintf(file,"\nNome:  "); //salvo com a informa��o
	fclose(file); //fecho o arquivo
	
	printf("\tDigite o nome a ser cadastrado: "); //pe�o pro usu�rio informa��o
	scanf("%s", nome); //salvo a informa��o
	
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
	
	
	system("pause"); //pausa a tela pro usu�rio

	
}

int consultar() //fun��o feita pra s� chamar depois facilitando no switch
{
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //criando as vari�veis na consulta
	char conteudo[200]; 
	
	printf("\tDigite o CPF a ser consultado: "); //pedindo informa��o
	scanf("%s",cpf); //guardando a string
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //indica que ir� LER(r) o arquivo
	
	if(file == NULL) //cria a v�riavel que ser� passada pro usu�rio caso n�o tenha no sistema
	{ 
	    printf("\tN�o foi poss�vel abrir o arquivo, n�o localizado! \n");
	}
	
	printf("\nEssas s�o as informa��es dos usu�rios, "); //passa as informa��es
	
	while(fgets(conteudo, 200, file) != NULL) //mostra as informa��es que existem daquele usu�rio
	{
		printf("%s", conteudo);
	}
	
	system("pause"); //pausa a tela pro usu�rio
	
}

int deletar() //fun��o feita pra s� chamar depois facilitando no switch
{
	char cpf[40]; //cria a vari�vel no deletar
	
	printf("\tDigite o CPF do usu�rio a ser deletado: "); //pede a informa��o
	scanf("%s",cpf); //guarda a informa��o
	
	remove(cpf); //criando o deletar o cpf do usu�rio
	
	FILE *file; //cria e chama o arquivo
	file = fopen(cpf, "r"); //indica a leitura do arquivo a ser deletado
	
	if(file == NULL) //cria a informa��o a ser passada pro usu�rio caso n�o tenha o cpf
	{
		printf("\tO usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	
	if(file != NULL) //cria a informa��o a ser passada pro usu�rio caso tenha o cpf 
	{
		printf("\tO usu�rio foi deletado com sucesso! \n");
		system("pause");
	}
	
}

int main() //fun��o principal 
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls"); //limpando tela
	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	printf("###Cart�rio da EBAC###\n\n"); //In�cio do menu
	printf("Escolha a op��o desejada no menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n"); 
	printf("Op��o:"); //Fim do menu
	
	
	scanf("%d", &opcao); // Armazenando a escolha do usu�rio 
	
	system("cls"); //como limpar a tela
	
	switch(opcao) //incio da sele��o do menu
	{
		case 1:
		registrar(); //chamada de fun��es
		break;
		
		case 2:
		consultar();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf("\tEssa op��o n�o est� dispon�vel\n");
		system("pause");  //pausando pra n�o voltar
		break;
		
	}	//Fim da sele��o 
			
		
	}
	

}

