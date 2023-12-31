#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o (Brasil)
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//fim da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se � strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //abre o arquivo na pasta do sistema e escreve com o w(write)
	fprintf(file,cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file, ","); //coloca a v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //abre o arquivo para atualizar
	fprintf(file,nome); //coloca o nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo
	fprintf(file,sobrenome); //atualiza com o sobrenome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file; //abre o arquivo na biblioteca FILE
	file = fopen(cpf,"r"); //l� o arquivo pelo r de read
	
	if(file == NULL) //para alguma informa��o nula
	{
		printf("\nN�o foi poss�vel abrir o arquivo, n�o localizado!\n\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio: \n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); //escaneia com o %s porque � uma string e na string cpf
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("\nO usu�rio n�o se encontra no sistema! \n\n");
	}	
	 
	if(file != NULL)
	{
		remove(cpf);
		printf("\nUsu�rio deletado com sucesso!\n\n");
		fclose(file);
	}
	
	system("pause");
			
}

int main()
{
	int opcao=0; //definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	setlocale(LC_ALL, "Portuguese");
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		system ("cls");				
		for(laco=1;laco=1;)
		{
			system("cls"); //respons�vel por limpar a tela
		
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
			printf("### Cart�rio da EBAC ###\n\n"); //in�cio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n"); 
			printf("\t4 - Sair do sistema\n\n");
			printf("Op��o: "); //fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usu�rio
		
			system("cls");
		
			switch(opcao) //in�cio da sele��o do menu
			{
				case 1:
				registro(); //chamada de fun��es
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
					
				default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
			} //fim da sele��o do menu
		}
	}
	
	else //caso a senha estiver errada, n�o precisa de {} pois � s� uma instru��o
		printf("Senha incorreta!");
	
}
