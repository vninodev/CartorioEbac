#include <stdio.h> //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> // biblioteca de aloca��o de espa�o  em memoria.
#include <locale.h> // biblioteca de aloca��o de teste por regi�o
#include <string.h> // Biblioteca responsavel por cuida da string.

int registrar() //FUN��O RESPONSAVEL POR CADASTRA OS USUARIOS NO SISTEMA.
{
	//INICIO DE CRIA��O DE VARIVAVEIS/STRING
	char arquivo[40];
	char cpf[40];
	char nome[40];	
	char sobrenome[40];
	char cargo[40];
	//FINAL DE CRIA��O DE VARIVAVEIS/STRING
	
		printf("Digite o CPF a ser cadastrado :"); // COLETANDO INFORMA��ES DO USUARIO.
		scanf("%s",cpf); // %s REFERE-SE A STRINGS.
	
	strcpy(arquivo, cpf); /// RESPONSAVEL POR COPIAR OS VALORES DAS STRINGS. OBS: O NOME DOS ARQUIVO SER�O OS CPFS,
	
	FILE *file;        // CRIAR ARQUIVO NO BANCO DE DADOS
	file = fopen(arquivo,"w"); // ABRIU ARQUIVO E O "W" � PRA ESCREVER. 
	fprintf(file,cpf); // SALVOU VALOR DA VARIAVEL.
	fclose(file);     // FECHAR O ARQUIVO.
	
	file = fopen(arquivo, "a"); // ABRIU O ARQUIVO.
	fprintf(file,","); // COLOCOU A "," COMO VARIAVEL.
	fclose(file); // FECHOU ARQUIVO
	
		printf("Digite seu nome:"); //COLETANDO INFORMA��ES DE NOME DO USUARIO.
		scanf("%s",nome); // "%S" REFERE-SE A STRINGS.
	
	file = fopen(arquivo, "a");//ABRIU ARQUIVO 
	fprintf(file,nome); // SALVOU VALOR DA VARIAVEL
	fclose(file);// FECHOU ARQUIVO
	
	file = fopen(arquivo, "a"); // ABRIU ARQUIVO
	fprintf(file,","); // SALVOU VALOR DA VARIAVEL
	fclose(file); // FECHOU ARQUIVO
		
		printf("Digite seu sobrenome:"); // USUARIO IRA DIGITAR O SOBRENOME
		scanf("%s",sobrenome); // "%S" REFERE-SE A STRINGS
	
	file = fopen(arquivo, "a"); //ABRIU ARQUIVO
	fprintf(file,sobrenome); // SALVOU VALOR DA VARIAVEL
	fclose(file); // FECHOU ARQUIVO
	
	file = fopen(arquivo, "a");//CRIOU ARQUIVO
	fprintf(file,","); // SALVOU VALOR DA VARIAVEL
	fclose(file); //FECHOU ARQUIVO
	
		printf("Digite seu cargo:"); // USUARIO IRA DIGITAR SEU CARGO.
		scanf("%s",cargo);// "%S" REFERE-SE A STRINGS
	
	file = fopen(arquivo,"a");//CRIOU ARQUIVO
	fprintf(file,cargo); // SALVOU VALOR DA VARIAVEL
	fclose(file); // FECHOU ARQUIVO
		
	system("pause"); // PAUSOU O SISTEMA
}
int consultar()//FUN��O RESPONSAVEL POR CONSULTAR OS USUARIOS.
{
	setlocale(LC_ALL, "Portuguese"); // Definindo as Linguagens.
	
  	char cpf[40]; // VARIAVEL
  	char conteudo[200]; // VARIAVEL
  	
  	printf("Digite o numero de CPF a ser consultado : "); // PARA O USUARIO DIGITA CPF PARA SER CONSULTADO.
  	scanf("%s", cpf);// "%S" REFERE-SE A STRINGS
  	
  		FILE *file; //CRIOU ARQUIVO NO BANCO DE DADOS
  		file = fopen(cpf, "r"); // ABRIU ARQUIVO
  	
  		if (file== NULL)// SE FOR NULO = NULL N�O S�RA POSSIVEL LOCALIZAR O ARQUIVO
  	{
  		printf("N�o foi possivel localizar o arquivo.");// MENSAGEM FINAL PRA USUARIO.
 	   }
 	
	 while(fgets(conteudo, 200, file) !=NULL)  
  	{
  		printf("\nEssas s�o as informa��es do usuario: ");
  		printf("%s", conteudo);
  		printf("\n\n");
	   } 	
system("pause"); // PAUSA DE SISTEMA

}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
				
	FILE *file;	
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nO usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	else
	{
		fclose(file);
		remove(cpf);
		FILE *file;	
		file = fopen(cpf,"r");
		if(file == NULL)
		{
			printf("\nUsu�rio deletado com sucesso!.\n");
			system("pause");
		}
	}
	fclose(file);
	
}
	
int main()
{
	
	int opcao=0; //Definindo as Variaveis.
	int	laco=1; // DEFININDO VARIAVEIS
	char senhadigitada[10]="a";
	int comparacao;
	
	
	printf("\t###Cart�rio da Ebac###\n\n"); //Inicio do Menu
	printf("Login de Administrador.\n\nDigite a sua senha:");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp (senhadigitada, "admin");  // 
	
	if (comparacao == 0)
	{
	    system ("cls");
		for(laco=1;laco=1;)
		{
			
			setlocale(LC_ALL, "Portuguese"); // Definindo as Linguagens.
	
			printf("\t###Cart�rio da Ebac###\n\n"); //Inicio do Menu
			printf("Escolha as op��es desejadas do MENU\n\n");
			printf("\t1 - Registrar Nomes\n\n");
			printf("\t2 - Consultar os Nomes\n\n");
			printf("\t3 - Deletar Nomes \n\n"); 
			printf("\n\t4 - Sair do Sistema\n\n");
			printf("Op��o:"); // fim do menu
	
			scanf("%d", &opcao); // Armazenando a escolha do usuario.
	
			system("cls"); // RESPONSAVEL POR LIMPA A TELA
		
		
			switch (opcao) // INICIO DA SELE��O DO MENU
			{
				case 1:
				registrar(); // CHAMADA DE FUNC�O REGISTRAR
				break;
					
				case 2:
				consultar(); // CHAMADA DE FUNC�O CONSULTAR
				break;
					
				case 3:
				deletar(); // CHAMADA DE FUNC�O DELETAR
			    break;
						
				case 4:
				printf("\n\t Obrigado por Utilizar nosso Sistema.");
				return 0;
				break;				
							
							default:
								printf("Voc� escolheu uma op��o Invalida.\n");
								system("pause");
							break;
	    	}
		} 
	}
	else
	printf("\n\nSenha Incorreta");
	
}
	
	


