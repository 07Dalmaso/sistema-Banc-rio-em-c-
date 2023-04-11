#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#include  "term.h"


typedef struct {
    int v[10];
    
    int nElementos;
} t_lista;



struct User {
	char cpf[15];
	char ac[50];
	char password[50];
	float balance;
  char sexo[12];
  char idade[3];
  /*char mae[50];
  char pai[50];
  char renda[50];*/
  
};


int main(){
	struct User user,usr;
	char filename[50],cpf[12],password[50] = {0},cpf2[15];
	FILE *fp,*fptr;
	int opt,choice,i;
	int amount;
  
	char cont = 's';
  char menu = 'v';
  char ch;
  int j = 0;


  
  while(menu == 'v'){
    printf("\n------ GDL --------\n");
    printf("\n  Seja bem vindo!\n\n");
    printf("-------------------\n");
	  printf("\n\n1.Registrar uma conta.");
	  printf("\n2.Fazer o login.");

	printf("\n\nEntre com o numero da operação:\t");
	scanf("%d",&opt);

  tc_canon_on();
	if(opt == 1){
		system("clear");
		printf("\nNome de usuario:\t");
		scanf("%s",user.ac);
    printf("--------------------------------------\n");
    
      
		printf("CPF:\t");
		scanf("%s",user.cpf);
    printf("--------------------------------------\n");
		printf("Senha:\t");
		scanf("%s", user.password);
		user.balance=0;
   
    printf("--------------------------------------\n");
    printf("Insira o seu gênero:\t");
		scanf("%s", user.sexo);
    printf("--------------------------------------\n");
    printf("Insira a sua idade:\t");
		scanf("%s", user.idade);
    printf("--------------------------------------\n");
   /* printf("Insira o nome da sua mãe:\t");
		scanf("%s", user.mae);
    printf("--------------------------------------\n");
    printf("Insira o nome do seu pai:\t");
		
    scanf("%s", user.pai);
    printf("--------------------------------------\n");
    printf("Insira a sua renda média :\t");
		scanf("%s",user.renda);
    printf("--------------------------------------\n");*/
    
		stpcpy(filename,user.cpf);
		fp=fopen (strcat(filename, ".dat"),"wb");
		fwrite(&user,sizeof(struct User),1,fp);
		if(fwrite != 0){
			printf("\nConta criada com sucesso! \n\n");
		}
  fclose(fp);
	}
	else if(opt == 2){
		system("clear");
		printf("\nCPF:\t");
		scanf("%s",cpf);

	  ch = 0;
		j = 0;
		printf("\nSenha:");
	
	    tc_canon_off ();
		tc_echo_off();
	
	    while (j < 40) {
	        ch = getchar();
	    
	        if (ch == 10 && j != 0)
	            break;
			if (ch == 104)
				continue;

			if (ch == 27) {
				system("clear");
				printf("\nCPF:\t%s", cpf);
	            printf("\n\nSenha: ");

	            printf("%s", password);
				printf("\n Pressione qualquer caractere para continuar");
				getchar();

				system("clear");
				printf("\nCPF:\t%s", cpf);
	            printf("\n\nsenha: ");
	    
	            for (int i = 0; i < j; i++)
	                printf("*");
				continue;
			}
	
	        if (ch == 127) {
	          	if(!j)
	         		continue;
	            j--;
	            password[j] = 0;
	    
	            system("clear");
				printf("\nCPF:\t%s", cpf);
	            printf("\n\nsenha: ");
	    
	            for (int i = 0; i < j; i++)
	                printf("*");
				continue;
	        }
	        password[j] = ch;
	        j++;
	        printf("*");
	    }
    //printf("%s", password);
    //getchar();
    tc_canon_on ();
		tc_echo_on();

  
    

		fp = fopen(strcat(cpf,".dat"),"r");
		if(fp == NULL) printf("Está conta não existe");
		else {
			fread(&user,sizeof(struct User),1,fp);
			fclose(fp);
      //printf("\n%s%s", user.password, password);
      
			if(!strcmp(password, user.password)){
				while(cont == 's'){
				printf("\n\n\tBem vindo, %s.\n\n ",user.ac);
				printf("\n0 - Ver saldo.\n");
				printf("1 - Depósito.\n");
				printf("2 - Retirar.\n");
				printf("3 - Transferência .\n");
        printf("4 - Menu Principal .\n");
				printf("5 - Trocar Senha.\n");
				scanf("%d",&choice);
				switch(choice){
          case 0:
						printf("Seu saldo atual é de R$ %.2f",user.balance);

          break;
          
					case 1:
system("clear");
						printf("Insira o valor a ser adicionado:\t");
						scanf("%d",&amount);
						user.balance += amount;
						fp = fopen(cpf,"w");
						fwrite(&user,sizeof(struct User),1,fp);
						if(fwrite !=0) printf("\n\nVocê depositou R$%d",amount);
						fclose(fp);
						break;

					case 2:
system("clear");
						printf("Insira o valor da retirada:\t");
						scanf("%d",&amount);
						if(amount % 1 != 0) printf("\nDesculpa, o valor inválido");
						else if(amount>user.balance) printf("\nDesculpe saldo insuficiente ");
						else {
							user.balance -= amount;
						fp = fopen(cpf,"wb");
						fwrite(&user,sizeof(struct User),1,fp);
						if(fwrite !=0) printf("\n\nVocê retirou R$.%d",amount);
						fclose(fp);
						}
						break;

					case 3:
printf("Colocar o CPF do receptor:\t");
						scanf("%s",cpf);
						printf("Coloque o valor a transferir:\t");
						scanf("%d",&amount);
						if(amount > user.balance) printf("\nSaldo Insuficiente");
						else {
fptr = fopen(strcat(cpf,".dat"),"rb");
							if(fptr == NULL) printf("Numero não registrado");
							else {
								fread(&usr,sizeof(struct User),1,fptr);
								fclose(fptr);
							
								user.balance += amount;
								
								fptr = fopen(cpf,"wb");
								fwrite(&usr,sizeof(struct User),1,fptr);
								if(fwrite != 0){
								// 	printf("ACcount:%s",usr.ac);
								// printf("\npassword%s",usr.password);
								// printf("\nphone%s",usr.cpf);
								// printf("\nbalance%f",usr.balance);
									printf("Transação concluida, você enviou.%d para %s",amount,usr.cpf);
									fclose(fptr);
									user.balance -= amount;
									strcpy(filename,user.cpf);
									fp = fopen(strcat(filename,".dat"),"wb");
									fwrite(&user,sizeof(struct User),1,fp);
									fclose(fp);
								}
							}
						}
						break;
					
					case 4:

            printf("\n\nDeseja voltar ao menu?[s/n]:\t");
				scanf("%s",&menu);
            if(menu == 's'){
              main ();
            }else{
             continue;
            }
      

    break;
					case 5:
						printf("\n\nColoque a sua antiga senha:\t");
						scanf("%s",password);
						if(!strcmp(password,user.password)){
							printf("\n\nColoque a nova senha:\t");
							scanf("%s",password);
							strcpy(user.password,password);
							strcpy(filename,user.cpf);
							fp = fopen(strcat(filename,".dat"),"wb");
							fwrite(&user,sizeof(struct User),1,fp);
							fclose(fp);	
							printf("\nSenha alterada com sucesso");
						}else printf("\nSua senha está errada");
					
					default:
					break;
				}
          
				printf("\n\nDeseja continuar?[s/n]\t");
				scanf("%s",&cont);
        if (cont == 's')
          continue;
				}
			}
			else {
				printf("Senha invalida");
        break;
			}	
		}
		printf("\n\n***Obrigado por utilizar GDL***\n\n");

	
				
	
	return 0;
}
          }
}