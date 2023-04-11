#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct user {
	char cpf[50];
	char ac[50];
	char password[50];
	float balance;
};

int main(){
	struct user user,usr;
	char filename[50],cpf[50],password[50],cpf2[50];
	FILE *fp,*fptr;
	int opt,choice;
	int amount;
	char cont = 'y';
	printf("\nO que deseja fazer?");
	printf("\n\n1.Registrar uma conta?");
	printf("\n2.Fazer o login?");

	printf("\n\nEntre com o numero da operação:\t");
	scanf("%d",&opt);
	if(opt == 1){
		system("clear");
		printf("\nNome de usuario:\t");
		scanf("%s",user.ac);
		printf("CPF:\t");
		scanf("%s",user.cpf);
		printf("Senha:\t");
		scanf("%s",user.password);
		user.balance=0;
		stpcpy(filename,user.cpf);
		fp=fopen(strcat(filename,".dat"),"w");
		fwrite(&user,sizeof(user),1,fp);
		if(fwrite != 0){
			printf("Conta criada com sucesso");
		}
  
	}
	else if(opt == 2){
		system("limpar");
		printf("\nCPF:\t");
		scanf("%s",cpf);
		printf("Senha:\t");
		scanf("%s",password);
		fp = fopen(strcat(cpf,".dat"),"r");
		if(fp == NULL) printf("Está conta não existe");
		else {
			fread(&user,sizeof(struct user),1,fp);
			fclose(fp);
			if(!strcmp(password,user.password)){
				while(cont == 'y'){
				printf("\n\tBem vindo %s\n",user.ac);
				printf("0 - Ver saldo.\n");
				printf("1 - Extrato.\n");
				printf("2 - Depósito.\n");
				printf("3 - Transferência .\n");
				printf("5 - Menu pricipal.\n");
        printf("6 - Mais.\n");
        printf("7 - Sair do sistema .\n");
				scanf("%d",&choice);
				switch(choice){
          case 0:
				
						break;
          
					case 1:
				
						break;

					case 2:
						
						break;

					case 3:
						
						break;
					
					case 4:
						
						break;
					case 5:
						
					break;
	
				
	
	return 0;
}
          }
        }
      }
    }
  }
