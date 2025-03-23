#include <stdio.h> //biblioteca de comunicção com usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função Responsável por Cadastrar os Usuários no Sistema
{
    //Início da Criação de Variaveis/Strings
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da Crição de Variaveis/String
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando Informações do Usuário
    scanf("%s", cpf); //Refere-se a String
    
    strcpy(arquivo, cpf); //Responsável por Copiar os Valores da String
    
    FILE *file; //Cria o Arquivo
    file = fopen(arquivo, "w"); //Cria o Arquivo
    fprintf(file,cpf); //Salva o Valor da Variável
    fclose(file); //Fecha o Arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    
    
}

int consulta()  //Função Responsável por Consultar Usuarios do Sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi posssivel abrir o arquivo, não localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //Função Responsável por Deletar Usuarios do Sistema
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!. \n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo Variáveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
  	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador\n\n Digite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
        system ("cls");
    	for(laco=1;laco=1;)
    	{
	
        	system("cls");
	
        	setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	
            printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
            printf("Escolha a opção desejada do menu:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n\n");
            printf("\t4 - Sair do Sistema\n\n");
            printf("Esse Softare é de livre uso dos alunos\n"); //Fim do Menu
            printf("Opção:");
            scanf("%d", &opcao); //Armazenando a Escolha do Usuário
    
            system("cls");
        
            switch(opcao)
            {
             	case 1: 
            	registro();
            	break;
        	
            	case 2:
                consulta();
    	        break;
    	    
    	        case 3:
    	        deletar();
		    	break;
			
    			case 4:
		    	printf("Obrigado por utilizar o sitema!\n");
    			return 0;
    			break; 
			
    			default:
    			printf("Essa opção não está disponível!\n");
            	system("pause");
     			break;	
	        }
	    	
                if(opcao==1) //Início da Seleção
                {
            	printf("Você escolheu o resgistro de nomes!\n");
             	system("pause");
            	}
               if(opcao==2) 
                {
            	printf("você escolheu consultar os nomes!\n");
    	        system("pause");
            	}
            	if(opcao==3) 
                {
            	printf("Você escolheu deletar os nomes!\n");
            	system("pause");
            	}
            	if(opcao>=4 || opcao<=0) 
                {
            	printf("Essa opção não está disponível!\n");
            	system("pause");
             	} // Fim da Seleção
        }
    
	}
     
     else
     printf("Senha incorreta!");
     
}
	
	
