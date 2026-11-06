//************* Henrique **********
 // =========================================================
    // SISTEMA DE REGISTRO E GESTÃO DE CONTAS BANCÁRIAS
    // ETAPA 2 - 
    // =========================================================


#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int MAX_CONTAS = 100;

    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS];

    const int MAX_MOVIMENTACOES = 500;

    int contaMovimentacao[MAX_MOVIMENTACOES];
    char tipoMovimentacao[MAX_MOVIMENTACOES];
    double valorMovimentacao[MAX_MOVIMENTACOES];

    int quantidadeMovimentacoes = 0;
    int quantidadeContas = 0;
    int opcao;

    // MENU
    do {
        cout << "\n===== SISTEMA BANCARIO =====" << endl;
        cout << "1 - Cadastrar contas." << endl;
        cout << "2 - Listar as contas cadastradas." << endl;
        cout << "3 - Consultar uma conta." << endl;
        cout << "4 - Deposito dinheiro." << endl;
        cout << "5 - Sacar dinheiro. " << endl;
        cout << "6 - Realizar transferencias . " << endl;
        cout << "7 - Extrato da conta " << endl ;
        cout << "8 - Sair." << endl ;


        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            
            //********* 1- Cadastrar conta *******

            case 1:

                if (quantidadeContas < MAX_CONTAS) {

                    cout << "Numero da Conta: ";
                    cin >> numeroConta[quantidadeContas];

                    cout << "Nome do Cliente: ";
                    cin.ignore();
                    getline(cin, nomeCliente[quantidadeContas]);

                    cout << "CPF: ";
                    cin >> cpf[quantidadeContas];

                    
                    cout << "Tipo de conta (1-Corrente / 2-Poupanca): ";
                    cin >> tipoConta[quantidadeContas];

                    cout << "Saldo inicial: R$ ";
                    cin >> saldo[quantidadeContas];

                    contaAtiva[quantidadeContas] = true;


                    quantidadeContas++;

                    cout << "Conta cadastrada com sucesso!" << endl;
                    
                }
                else {
                    cout << "Limite de contas atingido!" << endl;
                }

                break;

            case 2:

                // ******** 2- LISTAR CONTAS ******
                for (int i = 0; i < quantidadeContas; i++) {

                    cout << "-------------------" << endl;
                    cout << "Conta " << i + 1 << endl;
                    cout << "Numero da conta: " << numeroConta[i] << endl;
                    cout << "Nome do cliente: " << nomeCliente[i] << endl;
                    cout << "CPF: " << cpf[i] << endl;
                }

                break;


                //********* 3-CONSULTAR CONTA ******

            case 3: {

                int numero;
                int i;
                bool encontrou;

                encontrou = false;
                i = 0;

                cout << "Digite o numero da conta: ";
                cin >> numero;

                // WHILE: procurar a conta
                while (i < quantidadeContas) {

                    if (numeroConta[i] == numero &&
                        contaAtiva[i] == true) {

                        encontrou = true;

                        cout << "Conta encontrada!" << endl;
                        cout << "Numero: " << numeroConta[i] << endl;
                        cout << "Cliente: " << nomeCliente[i] << endl;
                        cout << "CPF: " << cpf[i] << endl;
                        cout << "Saldo: R$ " << saldo[i] << endl;

                        break;
                    }

                    i++;
                }

                if (encontrou == false) {
                    cout << "Conta nao encontrada!" << endl;
                }

                break;
            }

            // *********** 4- DEPOSITO *****

            case 4: {

                int numero;
                int i =0;
                int indice = -1 ;
                double valor ;

 cout << "Digite o numero da conta: ";
    cin >> numero;

    // WHILE: procurar a conta
    while (i < quantidadeContas) {

        if (numeroConta[i] == numero &&
            contaAtiva[i] == true) {

            indice = i;
            break;
        }

        i++;
    }

    if (indice == -1) {

        cout << "Conta nao encontrada!" << endl;

    }
    else {

        cout << "Digite o valor do deposito: R$ ";
        cin >> valor;

        if (valor <= 0) {

            cout << "Valor invalido!" << endl;

        }
        else if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {

            cout << "Historico cheio!" << endl;

        }
        else {

            // AUMENTAR O SALDO
            saldo[indice] = saldo[indice] + valor;

            // REGISTRAR A MOVIMENTACAO
            contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];

            tipoMovimentacao[quantidadeMovimentacoes] = 'D';

            valorMovimentacao[quantidadeMovimentacoes] = valor;

            quantidadeMovimentacoes++;

            cout << "Deposito realizado com sucesso!" << endl;
            cout << "Novo saldo: R$ " << saldo[indice] << endl;
        }
    }

    break;
}

        //********** 5-Saque *********

     case 5: 
      {

     int numero;
                int i =0;
                int indice = -1 ;
                double valor ;

                cout << "Digite o numero da conta: ";
    cin >> numero;

    // WHILE: procurar a conta
    while (i < quantidadeContas) {

        if (numeroConta[i] == numero &&
            contaAtiva[i] == true) {

            indice = i;
            break;
        }

        i++;
    }

    if (indice == -1) {

        cout << "Conta nao encontrada!" << endl;

    }
    else {

        cout << "Digite o valor do Saque: R$ ";
        cin >> valor;

        if (valor <= 0) {

            cout << "Valor invalido!" << endl;

         } else if (valor > saldo [indice]){
            cout << "Saldo insuficiente!" << endl;


        }
        else if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {

            cout << "Historico cheio!" << endl;

        }
        else {

            // DIMINUIR O SALDO
            saldo[indice] = saldo[indice] - valor;

            // REGISTRAR A MOVIMENTACAO
            contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];

            tipoMovimentacao[quantidadeMovimentacoes] = 'S';

            valorMovimentacao[quantidadeMovimentacoes] = valor;

            quantidadeMovimentacoes++;

            cout << "Saque realizado com sucesso!" << endl;
            cout << "Novo saldo: R$ " << saldo[indice] << endl;
        }
    }
    
    break;

            // ******* 6- transferencia ********
    }
           case 6: {

                int numeroOrigem;
                int numeroDestino;
                int indiceOrigem = -1 ;
                int indiceDestino =-1;
                int i = 0;
                double valor ;

                 cout << "Digite o numero da conta Origem: ";
    cin >> numeroOrigem;

     cout << "Digite o numero da conta de destino: ";
    cin >> numeroDestino;

    // WHILE: procurar a conta de origem e de destino
    while (i < quantidadeContas) {

        if (numeroConta[i] == numeroOrigem &&
            contaAtiva[i] == true) {

            indiceOrigem = i ;
            }
             
             if (numeroConta[i] == numeroDestino &&
            contaAtiva[i] == true) {
            indiceDestino = i;
         
        }

        i++;
    }

    if (indiceOrigem == -1 || indiceDestino == -1) {

        cout << " Um das contas nao foi encontrada!" << endl;

    }
    else if (indiceOrigem == indiceDestino)
    {
        cout << "Nao e possivel transferir para a mesma conta!" << endl;
    }


        else {
    cout << "Digite o valor da transferencia: R$ ";
    cin >> valor;


        if (valor <= 0) {

            cout << "Valor invalido!" << endl;

         } else if (valor > saldo [indiceOrigem]){

            cout << "Saldo insuficiente!" << endl;

        } else if (quantidadeMovimentacoes +2 > MAX_MOVIMENTACOES) {

            cout << "Historico cheio!" << endl;
        } else {

            // RETIRAR DINHEIRO DA CONTA DE ORIGEM
        saldo[indiceOrigem] = saldo[indiceOrigem] - valor;

        // COLOCAR DINHEIRO NA CONTA DE DESTINO 
        saldo[indiceDestino] = saldo[indiceDestino] + valor;


                    // REGISTRAR A SAIDA
            contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceOrigem];
            tipoMovimentacao[quantidadeMovimentacoes] = 'S';
            valorMovimentacao[quantidadeMovimentacoes] = valor;
            quantidadeMovimentacoes++;

            // REGISTRAR A ENTRADA
            contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceDestino];
            tipoMovimentacao[quantidadeMovimentacoes] = 'D';
            valorMovimentacao[quantidadeMovimentacoes] = valor;
            quantidadeMovimentacoes++;

        cout << "Transferencia realizada com sucesso!" << endl;
        }
    }
            break;

        }
        
            //*********** 7- Extrato Bancario ********

        case 7:{
            
            
                int numero ;
                int i = 0;
                int indice = -1 ;

 cout << "Digite o numero da conta: ";
    cin >> numero;

    // Procurar a conta
    while (i < quantidadeContas) {
        if (numeroConta[i] == numero && contaAtiva[i] == true) {
            indice = i;
            break;
        }
        i++;
    }

    if (indice == -1) {
        cout << "Conta nao encontrada!" << endl;
    } else {
        cout << "\n===== EXTRATO BANCARIO =====" << endl;
        cout << "Conta: " << numeroConta[indice] << endl;
        cout << "Cliente: " << nomeCliente[indice] << endl;

        // Mostrar movimentacoes da conta
        for (int j = 0; j < quantidadeMovimentacoes; j++) {
            if (contaMovimentacao[j] == numero) {
                if (tipoMovimentacao[j] == 'D') {
                    cout << "Deposito: R$ " << valorMovimentacao[j] << endl;
                } else if (tipoMovimentacao[j] == 'S') {
                    cout << "Saque: R$ " << valorMovimentacao[j] << endl;
                }
            }
        }

        cout << "Saldo atual: R$ " << saldo[indice] << endl;
    }

    break;
        


    }

            // ********** 8- saida (opçao invalida)
        
                case 8:
                cout << "Saindo..." << endl;
                break;

            default:
                cout << "Opcao invalida!" << endl;

        } // fecha o switch

    } while (opcao != 8); // fecha o do-while

    return 0;
}

