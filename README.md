# Sistema Bancário em c
Este é um sistema de conta bancária simples desenvolvido em C. O sistema permite que os usuários registrem uma conta, façam login, verifiquem o saldo, depositem dinheiro, retirem dinheiro, transfiram dinheiro para outra conta e alterem suas senhas.

## Compilação

Certifique-se de que você tem um compilador C instalado em seu sistema. Você pode compilar o código usando o GCC (GNU Compiler Collection) com o seguinte comando

$ gcc -o banco main.c term.c

Isso irá gerar um executável chamado banco. Execute o programa com:

$ ./banco

## Funcionalidades

O sistema possui as seguintes funcionalidades:

Registrar uma conta: Os usuários podem registrar uma conta inserindo seu nome de usuário, CPF, senha, gênero e idade. Os dados do usuário são armazenados em um arquivo binário com base no CPF como nome do arquivo.

### Fazer o login: Os usuários podem fazer login fornecendo seu CPF e senha. O sistema verifica se o CPF e a senha correspondem aos dados armazenados no arquivo.

### Ver saldo: Após fazer login, os usuários podem verificar seu saldo atual.

### Depósito: Os usuários podem fazer depósitos em suas contas, adicionando um valor ao saldo.

### Retirar: Os usuários podem retirar dinheiro de suas contas, desde que tenham saldo suficiente. A retirada deve ser um valor inteiro.

### Transferência: Os usuários podem transferir dinheiro para outra conta, fornecendo o CPF do destinatário e o valor a ser transferido. O sistema verifica se o saldo é suficiente antes de concluir a transferência.

### Trocar senha: Os usuários podem alterar sua senha após fazer login, fornecendo a senha antiga e a nova senha.

## Uso


Ao iniciar o programa, você será apresentado com um menu de registro e login.

Para registrar uma conta, escolha a opção 1 e forneça as informações necessárias.

Para fazer login, escolha a opção 2 e insira seu CPF e senha.

Após fazer login com sucesso, você terá acesso às opções de conta, onde poderá verificar saldo, fazer depósitos, retirar dinheiro, transferir dinheiro e alterar sua senha.

Siga as instruções na tela para interagir com o sistema.


## Observações

O sistema usa arquivos binários para armazenar os dados do usuário. Cada usuário é identificado pelo seu CPF, que é usado como nome do arquivo.

A senha é mascarada durante a entrada para maior segurança.

Este é um sistema simples e não inclui recursos avançados de segurança ou validação de entrada. É importante lembrar de não compartilhar suas senhas.

Certifique-se de que as bibliotecas "term.h" e "string.h" estão disponíveis no sistema para compilar e executar o código.

O código inclui algumas funcionalidades comentadas (como nome do pai, nome da mãe e renda) que podem ser habilitadas ou personalizadas de acordo com suas necessidades.

Espero que  tenha ajudado a entender e utilizar o sistema de conta bancária em C. Se tiver alguma dúvida ou encontrar problemas, sinta-se à vontade para entrar em contato.
