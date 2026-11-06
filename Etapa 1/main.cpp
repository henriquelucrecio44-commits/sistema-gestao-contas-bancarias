#include <iostream>
#include <string>
using namespace std;

int main() {
    // Vetores usados para armazenar os dados de até 5 contas
    int numeroConta[5];
    string nome_Cliente[5];
    string cpf[5];
    int tipoconta[5];
    double saldo[5];
    bool contaAtiva [5];
    bool contacadastrada [5];
 // Variáveis de controle do menu e da quantidade de contas cadastradas
    int Menu;
    int quantidadeContas = 0;
    
 // Mantém o menu funcionando até o usuário escolher a opção 6
     do {

         // Exibe o menu principal do Banco Prime
     cout <<"******************"<< endl;
    cout <<"==Banco Prime== "<< endl;
    cout <<"******************"<< endl;

    cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Consultar conta" << endl;
        cout << "3 - Verificar saldo" << endl;
        cout << "4 - Alterar tipo da conta" << endl;
        cout << "5 - Ativar/Desativar conta" << endl;
        cout << "6 - Sair" << endl;

        cout << "Escolha uma opcao: ";
        cin >> Menu;
 // Verifica qual opção foi escolhida pelo usuário
    switch (Menu){
        // Opção 1 - Cadastro de uma nova conta
        case 1:
        cout <<"Cadastrar conta. " <<endl;

 // Verifica se o limite de 5 contas já foi atingido
         if (quantidadeContas >= 5)
    {
        cout << "\nLimite de 5 contas atingido!" << endl;
        break;

        }
// Solicita um número de conta válido

  do
    {
        
    cout <<"Digite o numero da conta:";
    cin >> numeroConta [quantidadeContas];

// O número da conta não pode ser menor ou igual a zero
     if (numeroConta [quantidadeContas]<=0) {
        cout << "Numero da conta invalido! Digite um numero mairor que zero." << endl;

     }
    } while (numeroConta [quantidadeContas] <= 0);
    

// Limpeza de buffer necessária antes do próximo getline()
    cin.ignore();

 // Solicita o nome do titular
    cout << "Digite o nome do titular:";
    getline(cin,nome_Cliente[quantidadeContas]);
 // 3. Leitura de outra string com espaços

 // Solicita o CPF do titular
    cout <<"Digite o CPF do titular :";
    cin >> cpf[quantidadeContas];
  // Solicita e valida o tipo da conta
do
{ 

    cout << "Digite tipo de conta (1 =Corrente; 2 = Poupanca): ";
    cin >> tipoconta [quantidadeContas];
 // Aceita somente os tipos 1 ou 2
     if (tipoconta [quantidadeContas] != 1 && tipoconta [quantidadeContas] != 2)
    
     {
        cout << "tipo de conta invalida! Digite 1 ou 2." << endl ;
     }
       

} while (tipoconta [quantidadeContas] != 1 && tipoconta [quantidadeContas] !=2);

     // Solicita e valida o saldo inicial
   do
   { 
    cout <<"Qual seu saldo atual:";
    cin >> saldo [quantidadeContas];
// O saldo não pode ser negativo
    if (saldo [quantidadeContas] < 0)
    {
        cout << " Saldo invalido! o saldo nao pode ser negativo" << endl;

    }

   } while (saldo [quantidadeContas] < 0);
    // Toda conta cadastrada começa como ativa
   contaAtiva[quantidadeContas] = true;
// Aumenta a quantidade de contas cadastradas
    quantidadeContas++ ;
  // Marca a conta como cadastrada
    contacadastrada [quantidadeContas -1] = true;

         cout <<"\n Conta cadastrada com sucesso!"<< endl;
         break;
         // Opção 2 - Consulta dos dados de uma conta
         case 2:
    {    // Verifica se existe alguma conta cadastrada
         if (quantidadeContas == 0) {
        cout << "\nNenhuma conta cadastrada ainda!" << endl;
        break;
         }

         int contaConsulta;

       cout << "\nDigite o numero da conta que deseja consultar: ";
        cin >> contaConsulta;
// Guarda a posição da conta encontrada
         int posicao = -1;
 // Procura a conta pelo número informado
        for (int i = 0; i < quantidadeContas; i++)
    {
    if (numeroConta[i] == contaConsulta)
    {
        posicao = i;
        break;
    }
    }

 // Informa caso a conta não seja encontrada
    if (posicao == -1)
    {
    cout << "\nConta nao encontrada!" << endl;
    break;
    }
// Exibe os dados da conta encontrada
                cout << "\n====== DADOS DA CONTA ===="<< endl;
                cout << "Numero da conta:" << numeroConta [posicao]<< endl;
                cout << "Nome do titular:" << nome_Cliente [posicao] << endl;
                cout << "CPF:" <<cpf [posicao] << endl;
 // Mostra o tipo da conta
                if (tipoconta [posicao] ==1)
                { cout << "Tipo de conta:Corrente"<< endl;/* code */
                }
                else{
                    cout <<"Tipo de conta: Poupanca"<< endl;
                }
                
                cout << "Saldo: R$"<< saldo [posicao] << endl;
 // Mostra se a conta está ativa ou desativada
                if (contaAtiva [posicao])
                { cout << "Status: Ativo" << endl;
                    /* code */
                } 
                else {
                    cout << "status: Desativada"<< endl;

                } break;
                
    }
                 // Opção 3 - Verificação do saldo da conta
            case 3:
     { // Verifica se existem contas cadastrada
            if (quantidadeContas == 0)
            {
                cout << "\n Nenhuma conta cadastrada ainda" << endl;
                break;
            }
                int contaSaldo;

    cout << "\nDigite o numero da conta: ";
    cin >> contaSaldo;
  // Guarda a posição da conta encontrada
    int posicaoSaldo = -1;
// Procura a conta pelo número informado
    for (int i = 0; i < quantidadeContas; i++)
    {
    if (numeroConta[i] == contaSaldo)
    {
        posicaoSaldo = i;
        break;
    }

    }
     // Verifica se a conta foi encontrada
    if (posicaoSaldo == -1)
    {
        // Exibe o saldo da conta
    cout << "\nConta nao encontrada!" << endl;
    break;
    }

             cout << "\n ====SALDO NA CONTA====="<< endl;
             cout << "Saldo atual: R$ " << saldo [posicaoSaldo]<< endl;
             break;
        }
            case 4: // Opção 4 - Alteração do tipo da conta
            {
                // Verifica se existe alguma conta cadastrada
                if ( quantidadeContas ==0)
            {
                cout << "\n Nenhuma conta cadastrada ainda" << endl;
                break;
            }
                int contaAlterar;

cout << "\nDigite o numero da conta que deseja alterar: ";
cin >> contaAlterar;

int posicaoAlterar = -1;

for (int i = 0; i < quantidadeContas; i++)
{
    if (numeroConta[i] == contaAlterar)
    {
        posicaoAlterar = i;
        break;
    }
}

if (posicaoAlterar == -1)
{
    cout << "\nConta nao encontrada!" << endl;
    break;
}


                cout << "\nDigite o novo tipo de conta (1 = Corrente; 2 = Poupanca): ";
                cin >> tipoconta [posicaoAlterar];

              if (tipoconta  [posicaoAlterar]== 1) {
             cout << "Tipo da conta alterado para Corrente!" << endl;
            }
            else if (tipoconta  [posicaoAlterar] == 2) {
            cout << "Tipo da conta alterado para Poupanca!" << endl;
        }
        else {
        cout << "Tipo de conta invalido!" << endl;
        }

        break;
    }
            case 5:
    {
           if (quantidadeContas == 0)
{
    cout << "\nNenhuma conta cadastrada ainda!" << endl;
    break;
}

    int contaStatus;

    cout << "\nDigite o numero da conta: ";
    cin >> contaStatus;

        int posicaoStatus = -1;

    for (int i = 0; i < quantidadeContas; i++)
    {
    if (numeroConta[i] == contaStatus)
    {
        posicaoStatus = i;
        break;
    }
}

if (posicaoStatus == -1)
{
    cout << "\nConta nao encontrada!" << endl;
    break;
}

    if (contaAtiva[posicaoStatus])
    {
    contaAtiva[posicaoStatus] = false;
    cout << "\nConta desativada com sucesso!" << endl;
    }
    else
    {
    contaAtiva[posicaoStatus] = true;
    cout << "\nConta ativada com sucesso!" << endl;
    }

    break;
}           // Opção 6 - Encerra o programa
            case 6:
                cout << "Saindo do sistema..." << endl;
                break;
 // Caso o usuário digite uma opção que não existe
            default:
                cout << "Opcao invalida!" << endl;
        
              }
              // Repete o menu enquanto a opção escolhida não for 6
    } while (Menu != 6);

    
    return 0;
}
