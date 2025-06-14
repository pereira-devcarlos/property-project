#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>

using namespace std;

typedef struct {
    char Tipo[30]; // 1-casa, 2-apartamento, 3-terreno, 4-sala comerciial, 5-galpão
    char Finalidade[10]; // 1-venda, 2-locação, 3-temporada
    char Endereco[50]; // endereço do imóvel
    char Bairro[20]; // bairro do imóvel
    char Cidade[20]; // cidade do imóvel
    int Area; // área do imóvel em m²
    char Valor[12]; // valor do imóvel
    int IPTU; // IPTU do imóvel
    int Quartos; // número de quartos
    int Suites; // número de suítes
    int Banheiros; // número de banheiros
    int Vagas; // número de vagas
    char Cozinha[4]; // 1-sim, 0-não
    char Sala[4]; // 1-sim, 0-não
    char Varanda[4]; // 1-sim, 0-não
    char AreaServico[4]; // 1-sim, 0-não
    char Piso[20]; // tipo de piso
    char Estado[10]; // 1-novo, 2-usado, 3-reformado
    char Armarios[4]; // 1-sim, 0-não
    char ArCondicionado[4]; // 1-sim, 0-não
    char Aquecedor[4]; // 1-sim, 0-não
    char Ventilador[4]; // 1-sim, 0-não
}Imovel;


int menu(int quant) {
    int opcao;
    cout << "Menu de Opções:" << endl;
    cout << "1. Inclusão de um novo imóvel" << endl;
    cout << "2. Menu de opções de busca" << endl;
    cout << "3. Relatório de Estatísticas" << endl;
    cout << "4. Listagem de todos os imóveis disponíveis" << endl;
    cout << "0. Sair" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;
    return opcao;
}

void menuInclusao(int quant, Imovel Vetor[]){
    char Tipo[30], Finalidade[10], IPTU[12], Area[12], Quartos[12], Suites[12], Banheiros[12], Vagas[12], Cozinha[4], Sala[4], Varanda[4], AreaServico[4], Armarios[4], ArCondicionado[4], Aquecedor[4], Ventilador[4],Endereco[50], Bairro[20], Cidade[20], Piso[20], Estado[10], Valor[12];
    int Op, OpF;
    cout << "Qual o tipo do imovel?\n1.Casa  2.Apartamento  3.Terreno  4.Sala comercial  5.Galpão\nR:";
    cin >> Op;
    while(Op < 1 and 5 < Op){
        cout << "Opção invalida, digite uma opção valida:";
        cin >> Op;
    }
    if(Op == 1){
        strcpy(Tipo, "casa"); 
    }else if(Op == 2){
        strcpy(Tipo, "apartamento");
    }else if(Op == 3){
        strcpy(Tipo, "terreno");
    }else if(Op == 4){
        strcpy(Tipo, "sala_comercial");
    }else{
        strcpy(Tipo, "galpao");
    }
    cout << "Qual a finalidade do imovel?\n1.Venda  2.Locação  3.Temporada\nR:";
    cin >> OpF;
    while(OpF < 1 and 3 < OpF){
        cout << "Opção invalida, digite uma opção valida:";
        cin >> OpF;
    }
    if(OpF == 1){
        strcpy(Finalidade, "venda");
    }else if(OpF == 2){
        strcpy(Finalidade, "locacao");
    }else{
        strcpy(Finalidade, "temporada");
    }
    cout << "Qual o endereço do imovel? (Ao escrever o endereço, utilize \"_\" para espaços)\nR:";
    cin >> Endereco;
    cout << "Qual o bairro do imovel? (Ao escrever o bairro, utilize \"_\" para espaços)\nR:";
    cin >> Bairro;
    cout << "Qual a cidade do imovel? (Ao escrever a cidade, utilize \"_\" para espaços)\nR:";
    cin >> Cidade;
    cout << "Qual a área do imovel?\nR:";
    cin >> Op;
    while(Op <= 0){
        cout << "Digite um valor de area valido:";
        cin >> Op;
    }
    sprintf(Area, "%d", Op); // Atribui o valor da área
    if(OpF == 1){ // Se for venda, o valor é em reais
        cout << "Qual o valor do imovel? (Ao escrever o valor, utilize \"_\" para espaços)\nR:";
        cin >> Valor;
        while(atoi(Valor) <= 0){
            cout << "Digite um valor de imovel valido:";
            cin >> Valor;
        }
    } else { // Se for locação ou temporada, o valor é por dia
        cout << "Qual o valor do aluguel do imovel? (Ao escrever o valor, utilize \"_\" para espaços)\nR:";
        cin >> Valor;
        while(atoi(Valor) <= 0){
            cout << "Digite um valor de aluguel valido:";
            cin >> Valor;
        }
        strcat(Valor, "/dia"); // Adiciona "/dia" ao final do valor
    }

    cout << "Qual o IPTU do imovel?\nR:";
    cin >> Op;
    while (Op < 0){
        cout << "Digite um valor de IPTU valido:";
        cin >> Op;
    }  
    sprintf(IPTU, "%d", Op); // Atribui o valor do IPTU
    cout << "Quantos quartos tem o imovel?\nR:";
    cin >> Op;
    while (Op < 0){
        cout << "Digite um valor de quartos valido:";
        cin >> Op;
    }
    sprintf(Quartos, "%d", Op); // Atribui o valor dos quartos
    cout << "Quantas suites tem o imovel?\nR:";
    cin >> Op;
    while (Op < 0){
        cout << "Digite um valor de suites valido:";
        cin >> Op;
    }
    sprintf(Suites, "%d", Op); // Atribui o valor das suites
    cout << "Quantos banheiros tem o imovel?\nR:";
    cin >> Op;
    while (Op < 0){
        cout << "Digite um valor de banheiros valido:";
        cin >> Op;
    }
    sprintf(Banheiros, "%d", Op); // Atribui o valor dos banheiros
    cout << "Quantas vagas tem o imovel?\nR:";
    cin >> Op;
    while (Op < 0){
        cout << "Digite um valor de vagas valido:";
        cin >> Op;
    }
    sprintf(Vagas, "%d", Op); // Atribui o valor das vagas
    cout << "O imovel tem cozinha?\n1.Sim  0.Não\nR:";
    cin >>  Op;
    while (Op < 0 or Op > 1){
        cout << "Digite uma opção valida:";
        cin >> Op;
    }
    if(Op == 1){
        strcpy(Cozinha, "sim");
    }else{
        strcpy(Cozinha, "não");
    }
    cout << "O imovel tem sala?\n1.Sim  0.Não\nR:";
    cin >> Op;
    while (Op < 0 or Op > 1){
        cout << "Digite uma opção valida:";
        cin >> Op;
    }
    if(Op == 1){
        strcpy(Sala, "sim");
    }else{
        strcpy(Sala, "não");
    }
    cout << "O imovel tem varanda?\n1.Sim  0.Não\nR:";
    cin >> Op;
    while (Op < 0 or Op > 1){
        cout << "Digite uma opção valida:";
        cin >> Op;
    }
    if(Op == 1){
        strcpy(Varanda, "sim");
    }else{
        strcpy(Varanda, "não");
    }
    cout << "O imovel tem área de serviço?\n1.Sim  0.Não\nR:";
    cin >> Op;
    while (Op < 0 or Op > 1){
        cout << "Digite uma opção valida:";
        cin >> Op;
    }
    if(Op == 1){
        strcpy(AreaServico, "sim");
    }else{
        strcpy(AreaServico, "não");
    }
    cout << "Qual o tipo de piso do imovel? (Ao escrever o tipo, utilize \"_\" para espaços)\nR:";
    cin >> Piso;
    cout << "Qual o estado do imovel?\n1.Novo  2.Usado  3.Reformado\nR:";
    cin >> Op;
    while (Op < 1 or Op > 3){
        cout << "Digite uma opção valida:";
        cin >> Op;
    }
    if(Op == 1){
        strcpy(Estado, "novo");
    }else if(Op == 2){
        strcpy(Estado, "usado");
    }else{
        strcpy(Estado, "reformado");
    }
    cout << "O imovel tem armarios?\n1.Sim  0.Não\nR:";
    cin >> Op;
    while (Op < 0 or Op > 1){
        cout << "Digite uma opção valida:";
        cin >> Op;
    }
    if(Op == 1){
        strcpy(Armarios, "sim");
    }else{
        strcpy(Armarios, "não");
    }
    cout << "O imovel tem ar condicionado?\n1.Sim  0.Não\nR:";
    cin >> Op;
    while (Op < 0 or Op > 1){
        cout << "Digite uma opção valida:";
        cin >> Op;
    }
    if(Op == 1){
        strcpy(ArCondicionado, "sim");
    }else{
        strcpy(ArCondicionado, "não");
    }
    cout << "O imovel tem aquecedor?\n1.Sim  0.Não\nR:";
    cin >> Op;
    while (Op < 0 or Op > 1){
        cout << "Digite uma opção valida:";
        cin >> Op;
    }
    if(Op == 1){
        strcpy(Aquecedor, "sim");
    }else{
        strcpy(Aquecedor, "não");
    }
    cout << "O imovel tem ventilador?\n1.Sim  0.Não\nR:";
    cin >> Op;
    while (Op < 0 or Op > 1){
        cout << "Digite uma opção valida:";
        cin >> Op;
    }
    if(Op == 1){
        strcpy(Ventilador, "sim");
    }else{
        strcpy(Ventilador, "não");
    }

    // Adiciona o imóvel ao vetor
    strcpy(Vetor[quant].Tipo, Tipo);
    strcpy(Vetor[quant].Finalidade, Finalidade);
    strcpy(Vetor[quant].Endereco, Endereco);
    strcpy(Vetor[quant].Bairro, Bairro);
    strcpy(Vetor[quant].Cidade, Cidade);
    Vetor[quant].Area = atoi(Area);
    strcpy(Vetor[quant].Valor, Valor);
    Vetor[quant].IPTU = atoi(IPTU);
    Vetor[quant].Quartos = atoi(Quartos);
    Vetor[quant].Suites = atoi(Suites);
    Vetor[quant].Banheiros = atoi(Banheiros);
    Vetor[quant].Vagas = atoi(Vagas);
    strcpy(Vetor[quant].Cozinha, Cozinha);
    strcpy(Vetor[quant].Sala, Sala);
    strcpy(Vetor[quant].Varanda, Varanda);
    strcpy(Vetor[quant].AreaServico, AreaServico);
    strcpy(Vetor[quant].Piso, Piso);
    strcpy(Vetor[quant].Estado, Estado);
    strcpy(Vetor[quant].Armarios, Armarios);
    strcpy(Vetor[quant].ArCondicionado, ArCondicionado);
    strcpy(Vetor[quant].Aquecedor, Aquecedor);
    strcpy(Vetor[quant].Ventilador, Ventilador);
}
void menuBusca(int quant, Imovel Vetor[]) { // W.I.P
    int opcao;
    cout << "Menu de Busca:" << endl;
    cout << "1. Buscar por Tipo" << endl;
    cout << "2. Buscar por Finalidade" << endl;
    cout << "3. Buscar por Endereço" << endl;
    cout << "4. Buscar por Bairro" << endl;
    cout << "5. Buscar por Cidade" << endl;
    cout << "6. Buscar por Área" << endl;
    cout << "7. Buscar por Valor" << endl;
    cout << "8. Voltar ao Menu Principal" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;
    switch (opcao){
    case 1:{
        int Op;
        cout << "Qual tipo de imovel você deseja?\n1.casa  2.apartamento  3.terreno  4.sala comerciial  5.galpão\nR:" << endl;
        cin >> Op;
        while (not(1 <= Op <= 5)){
            cout << "Opção invalida, digite uma opção valida:";
            cin >> Op;
        }
        char Tipo[30];
        if(Op == 1){
            strcpy(Tipo, "casa");
        }else if(Op == 2){
            strcpy(Tipo, "apartamento");
        }else if(Op == 3){
            strcpy(Tipo, "terreno");
        }else if(Op == 4){
            strcpy(Tipo, "sala_comercial");
        }else if(Op == 5){
            strcpy(Tipo, "galpão");
        }
        for(int i = 0 ; i < quant; i++){
            if(strcmp(Vetor[i].Tipo, Tipo) == 0){
                cout << i+1 << "°-É um(a) " << Vetor[i].Tipo << " para " << Vetor[i].Finalidade << " no endereço " << Vetor[i].Endereco << " no bairro " << Vetor[i].Bairro << " da cidade " << Vetor[i].Cidade << " com " << Vetor[i].Area << "m² no valor de R$" << Vetor[i].Valor << ". Possui " << Vetor[i].Quartos << " Quartos, " << Vetor[i].Suites << " Suites, " << Vetor[i].Banheiros << " Banehiros e " << Vetor[i].Vagas << " Vagas. Cozinha:" << Vetor[i].Cozinha << " Sala:" << Vetor[i].Sala << " Varanda:" << Vetor[i].Varanda << " Area de Serviço:" << Vetor[i].AreaServico << " Tipo do piso: " << Vetor[i].Piso << " Ele está " << Vetor[i].Estado << " Ar condicionado:" << Vetor[i].ArCondicionado << " Aquicedor:" << Vetor[i].Aquecedor << " Ventilador:" << Vetor[i].Ventilador << endl;
            }          
        };
        break;
    }
    case 2:{
        int Op;
        char Finalidade[12];
        cout << "Qual finalidade você deseja?\n1.venda  2.aluguel  3.temporada\nR:" << endl;
        cin >> Op;
        while (not(1 <= Op <= 3)){
            cout << "Opção invalida, digite uma opção valida:";
            cin >> Op;
        }
        if(Op == 1){
            strcpy(Finalidade, "venda");
        }else if(Op == 2){
            strcpy(Finalidade, "aluguel");
        }else if(Op == 3){
            strcpy(Finalidade, "temporada");
        }
        for(int i = 0 ; i < quant; i++){
            if(strcmp(Vetor[i].Finalidade, Finalidade) == 0){
                cout << i+1 << "°-É um(a) " << Vetor[i].Tipo << " para " << Vetor[i].Finalidade << " no endereço " << Vetor[i].Endereco << " no bairro " << Vetor[i].Bairro << " da cidade " << Vetor[i].Cidade << " com " << Vetor[i].Area << "m² no valor de R$" << Vetor[i].Valor << ". Possui " << Vetor[i].Quartos << " Quartos, " << Vetor[i].Suites << " Suites, " << Vetor[i].Banheiros << " Banehiros e " << Vetor[i].Vagas << " Vagas. Cozinha:" << Vetor[i].Cozinha << " Sala:" << Vetor[i].Sala << " Varanda:" << Vetor[i].Varanda << " Area de Serviço:" << Vetor[i].AreaServico << " Tipo do piso: " << Vetor[i].Piso << " Ele está " << Vetor[i].Estado << " Ar condicionado:" << Vetor[i].ArCondicionado << " Aquicedor:" << Vetor[i].Aquecedor << " Ventilador:" << Vetor[i].Ventilador << endl;
            }          
        };        
        break;}
    case 3:{
        string Endereco;
        cout << "Qual endereço você deseja?\nR:";
        cin >> Endereco;
        for (int i = 0; i < quant; i++){
            if(Vetor[i].Endereco == Endereco){
                cout << i+1 << "°-É um(a) " << Vetor[i].Tipo << " para " << Vetor[i].Finalidade << " no endereço " << Vetor[i].Endereco << " no bairro " << Vetor[i].Bairro << " da cidade " << Vetor[i].Cidade << " com " << Vetor[i].Area << "m² no valor de R$" << Vetor[i].Valor << ". Possui " << Vetor[i].Quartos << " Quartos, " << Vetor[i].Suites << " Suites, " << Vetor[i].Banheiros << " Banehiros e " << Vetor[i].Vagas << " Vagas. Cozinha:" << Vetor[i].Cozinha << " Sala:" << Vetor[i].Sala << " Varanda:" << Vetor[i].Varanda << " Area de Serviço:" << Vetor[i].AreaServico << " Tipo do piso: " << Vetor[i].Piso << " Ele está " << Vetor[i].Estado << " Ar condicionado:" << Vetor[i].ArCondicionado << " Aquicedor:" << Vetor[i].Aquecedor << " Ventilador:" << Vetor[i].Ventilador << endl;               
            }
        }       
        break;}
    case 4:{
        string Bairro;
        cout << "Qual Bairro você deseja?\nR:";
        cin >> Bairro;
        for (int i = 0; i < quant; i++){
            if(strcmp(Vetor[i].Bairro, Bairro.c_str()) == 0){
                cout << i+1 << "°-É um(a) " << Vetor[i].Tipo << " para " << Vetor[i].Finalidade << " no endereço " << Vetor[i].Endereco << " no bairro " << Vetor[i].Bairro << " da cidade " << Vetor[i].Cidade << " com " << Vetor[i].Area << "m² no valor de R$" << Vetor[i].Valor << ". Possui " << Vetor[i].Quartos << " Quartos, " << Vetor[i].Suites << " Suites, " << Vetor[i].Banheiros << " Banehiros e " << Vetor[i].Vagas << " Vagas. Cozinha:" << Vetor[i].Cozinha << " Sala:" << Vetor[i].Sala << " Varanda:" << Vetor[i].Varanda << " Area de Serviço:" << Vetor[i].AreaServico << " Tipo do piso: " << Vetor[i].Piso << " Ele está " << Vetor[i].Estado << " Ar condicionado:" << Vetor[i].ArCondicionado << " Aquicedor:" << Vetor[i].Aquecedor << " Ventilador:" << Vetor[i].Ventilador << endl;               
            }
        } 
        break;}
    case 5:{
        string Cidade;
        cout << "Qual Bairro você deseja?\nR:";
        cin >> Cidade;
        for (int i = 0; i < quant; i++){
            if(strcmp(Vetor[i].Cidade, Cidade.c_str()) == 0){
                cout << i+1 << "°-É um(a) " << Vetor[i].Tipo << " para " << Vetor[i].Finalidade << " no endereço " << Vetor[i].Endereco << " no bairro " << Vetor[i].Bairro << " da cidade " << Vetor[i].Cidade << " com " << Vetor[i].Area << "m² no valor de R$" << Vetor[i].Valor << ". Possui " << Vetor[i].Quartos << " Quartos, " << Vetor[i].Suites << " Suites, " << Vetor[i].Banheiros << " Banehiros e " << Vetor[i].Vagas << " Vagas. Cozinha:" << Vetor[i].Cozinha << " Sala:" << Vetor[i].Sala << " Varanda:" << Vetor[i].Varanda << " Area de Serviço:" << Vetor[i].AreaServico << " Tipo do piso: " << Vetor[i].Piso << " Ele está " << Vetor[i].Estado << " Ar condicionado:" << Vetor[i].ArCondicionado << " Aquicedor:" << Vetor[i].Aquecedor << " Ventilador:" << Vetor[i].Ventilador << endl;               
            }
        } 
        break;}
    case 6:{
        int Min,Max;
        cout << "Digite o valor minimo de area:";
        cin >> Min;
        cout << "Digite o valor maximo de area:";
        cin >> Max;
        while (Max < Min){
            cout << "Digite um valor maximo maior que o minimo:";
            cin >> Max;
        }
        for(int i = 0; i < quant; i++){
            if(Min <= Vetor[i].Area <= Max){
                cout << i+1 << "°-É um(a) " << Vetor[i].Tipo << " para " << Vetor[i].Finalidade << " no endereço " << Vetor[i].Endereco << " no bairro " << Vetor[i].Bairro << " da cidade " << Vetor[i].Cidade << " com " << Vetor[i].Area << "m² no valor de R$" << Vetor[i].Valor << ". Possui " << Vetor[i].Quartos << " Quartos, " << Vetor[i].Suites << " Suites, " << Vetor[i].Banheiros << " Banehiros e " << Vetor[i].Vagas << " Vagas. Cozinha:" << Vetor[i].Cozinha << " Sala:" << Vetor[i].Sala << " Varanda:" << Vetor[i].Varanda << " Area de Serviço:" << Vetor[i].AreaServico << " Tipo do piso: " << Vetor[i].Piso << " Ele está " << Vetor[i].Estado << " Ar condicionado:" << Vetor[i].ArCondicionado << " Aquicedor:" << Vetor[i].Aquecedor << " Ventilador:" << Vetor[i].Ventilador << endl;               
            }
        }
        break;}
    case 7:{
        int Op;
        cout << "Qual tipo de imovel você deseja?\n1.Imovel para compra   2.Imovel para aluguel\nR:" << endl;
        cin >> Op;
        while (2 <= Op and Op <= 1){
            cout << "Digite o valor de uma opção valida:";
            cin >> Op;
        }
        int valor;
        switch (Op){
            case 1:{
                int Min,Max;
                cout << "Digite o valor minimo:";
                cin >> Min;
                cout << "Digite o valor maximo:";
                cin >> Max;
                while (Max < Min){
                    cout << "Digite um valor maximo maior que o minimo:";
                    cin >> Max;
                }
                for(int i = 0; i < quant; i++){
                    sscanf(Vetor[i].Valor, "%d", &valor); // Converte o valor de string para int
                    if((Min <= valor and valor <= Max) and (Vetor[i].Finalidade == "venda")){
                        cout << i+1 << "°-É um(a) " << Vetor[i].Tipo << " para " << Vetor[i].Finalidade << " no endereço " << Vetor[i].Endereco << " no bairro " << Vetor[i].Bairro << " da cidade " << Vetor[i].Cidade << " com " << Vetor[i].Area << "m² no valor de R$" << Vetor[i].Valor << ". Possui " << Vetor[i].Quartos << " Quartos, " << Vetor[i].Suites << " Suites, " << Vetor[i].Banheiros << " Banehiros e " << Vetor[i].Vagas << " Vagas. Cozinha:" << Vetor[i].Cozinha << " Sala:" << Vetor[i].Sala << " Varanda:" << Vetor[i].Varanda << " Area de Serviço:" << Vetor[i].AreaServico << " Tipo do piso: " << Vetor[i].Piso << " Ele está " << Vetor[i].Estado << " Ar condicionado:" << Vetor[i].ArCondicionado << " Aquicedor:" << Vetor[i].Aquecedor << " Ventilador:" << Vetor[i].Ventilador << endl;               
                    }
                }    
                break;
            }
            case 2:{
                int Min,Max;
                cout << "Digite o valor minimo do aluguel:";
                cin >> Min;
                cout << "Digite o valor maximo do aluguel:";
                cin >> Max;
                while (Max < Min){
                    cout << "Digite um valor maximo maior que o minimo:";
                    cin >> Max;
                }
                for(int i = 0; i < quant; i++){
                    sscanf(Vetor[i].Valor, "%d", &valor); // Converte o valor de string para int e tira o /dia do valor
                    if((Min <= valor and valor <= Max) and !(Vetor[i].Finalidade == "venda")){
                        cout << i+1 << "°-É um(a) " << Vetor[i].Tipo << " para " << Vetor[i].Finalidade << " no endereço " << Vetor[i].Endereco << " no bairro " << Vetor[i].Bairro << " da cidade " << Vetor[i].Cidade << " com " << Vetor[i].Area << "m² no valor de R$" << Vetor[i].Valor << ". Possui " << Vetor[i].Quartos << " Quartos, " << Vetor[i].Suites << " Suites, " << Vetor[i].Banheiros << " Banehiros e " << Vetor[i].Vagas << " Vagas. Cozinha:" << Vetor[i].Cozinha << " Sala:" << Vetor[i].Sala << " Varanda:" << Vetor[i].Varanda << " Area de Serviço:" << Vetor[i].AreaServico << " Tipo do piso: " << Vetor[i].Piso << " Ele está " << Vetor[i].Estado << " Ar condicionado:" << Vetor[i].ArCondicionado << " Aquicedor:" << Vetor[i].Aquecedor << " Ventilador:" << Vetor[i].Ventilador << endl;               
                    }
                }
                break;
            }
        }  
        break;
    }
    }
    int rep;
    cout << "Deseja pesquisar por outro critério?\n1. Sim   2. Não\nR:";
    cin >> rep;
    while(rep > 2 and rep < 1){
        cout << "Digite uma opção valida:";
        cin >> rep;
    }
    if(rep == 1){
        menuBusca(quant, Vetor);
    } else {
        menu(quant);
    }
}
void excluirImovel(Imovel imoveis[], int &total){

    int opcao;
    cout << "Menu de Exclusão:" << endl;
    cout << "Escolha um critério para buscar o imóvel a ser excluído:\n";
    cout << "Digite 1 para excluir pelo endereço" << endl;
    cout << "Digite 2 para excluir pelo tipo" << endl;
    cout << "Digite 3 para excluir pelo Bairro" << endl;
    cout << "Digite 4 para excluir pelo Cidade" << endl;
    cout << "Digite 5 para não excluir" << endl;
    cin >> opcao;

    char entrada[50];
    bool encontrado = false;

    if (opcao == 5) {
        cout << "Exclusão cancelada." << endl;
        return;
    }

    cout << "Digite o que vc quer excluir (O endereço, o tipo, bairro ou cidade): ";
    cin.ignore();
    cin.getline(entrada, 50);

    for (int i = 0; i<total; i++){

        bool deveExcluir = false;
        switch (opcao){
            case 1: // Excluir pelo endereço
                if (strcmp(imoveis[i].Endereco, entrada) == 0) {
                    deveExcluir = true;
                }
                break;
            case 2: // Excluir pelo tipo
                if (strcmp(imoveis[i].Tipo, entrada) == 0) {
                    deveExcluir = true;
                }
                break;
            case 3: // Excluir pelo bairro  
                if (strcmp(imoveis[i].Bairro, entrada) == 0) {
                    deveExcluir = true;
                }
                break;
            case 4: // Excluir pela cidade
                if (strcmp(imoveis[i].Cidade, entrada) == 0) {
                    deveExcluir = true;
                }
                break;
                default:
                cout << "Critério inválido." << endl;
                return;

        }
        if (deveExcluir){
            encontrado = true;
            cout << "Imóvel encontrado no índice " << i << ": " << imoveis[i].Endereco << endl;
            cout << "Voce deseja excluir esse imóvel? (s = 1/n = 0): ";
            int resp;
            cin >> resp;
            if (resp == 1){
                for (int j = i; j < total - 1; j++){
                    imoveis[j] = imoveis[j + 1];
                }
                total--;
                cout << "Imóvel excluído com sucesso!" << endl;
                i--;

            } else {
                cout << "O imovel nao foi excluído." << endl;
            }
        }
        if (!encontrado) {
            cout << "Nenhum imóvel encontrado com o critério especificado." << endl;
        }

    }

}
void relatorio(int totalImoveis,int cVenda,int cLocacao,int totalCasas,int casas_com_suite,int salacomercial_totais,int salacomercial_ceramica) {
    
    printf("Relatório de Estatísticas dos Imóveis\n");
    printf("------------------------------------\n");
    printf("Total de imóveis lidos: %d\n", totalImoveis);

    if (totalImoveis == 0) {
        printf("Nenhum imóvel cadastrado no arquivo.\n");
        return;
    }

    printf("Porcentagem de imóveis por finalidade:\n");
    printf(" - Venda: %.1f%%\n", (cVenda * 100.0) / totalImoveis);
    printf(" - Locação (Aluguel/Temporada): %.1f%%\n", (cLocacao * 100.0) / totalImoveis);

    if (totalCasas > 0) {
        printf("Porcentagem de casas com suítes: %.1f%% (%d de %d casas)\n",
               (casas_com_suite * 100.0) / totalCasas, casas_com_suite, totalCasas);
    } else {
        printf("Não há casas cadastradas.\n");
    }

    if (salacomercial_totais > 0) {
        printf("Porcentagem de pisos com cerâmica nas salas comerciais: %.1f%% (%d de %d salas comerciais)\n",
               (salacomercial_ceramica * 100.0) / salacomercial_totais,
               salacomercial_ceramica, salacomercial_totais);
    } else {
        printf("Não há salas comerciais cadastradas.\n");
    }
}
void listarImoveis(Imovel Imoveis[], int quantidade) {
    for (int i = 0; i < quantidade; i++) { // Corrigido!
        cout << "Tipo: " << Imoveis[i].Tipo << endl;
        cout << "Finalidade: " << Imoveis[i].Finalidade << endl;
        cout << "Endereço: " << Imoveis[i].Endereco << endl;
        cout << "Bairro: " << Imoveis[i].Bairro << endl;
        cout << "Cidade: " << Imoveis[i].Cidade << endl;
        cout << "Área: " << Imoveis[i].Area << endl;
        cout << "Valor: " << Imoveis[i].Valor << endl;
        cout << "Quartos: " << Imoveis[i].Quartos << endl;
        cout << "Suites: " << Imoveis[i].Suites << endl;
        cout << "Banheiros: " << Imoveis[i].Banheiros << endl;
        cout << "Vagas: " << Imoveis[i].Vagas << endl;
        cout << "Cozinha: " << Imoveis[i].Cozinha << endl;
        cout << "Sala: " << Imoveis[i].Sala << endl;
        cout << "Varanda: " << Imoveis[i].Varanda << endl;
        cout << "Área de Serviço: " << Imoveis[i].AreaServico << endl;
        cout << "Piso: " << Imoveis[i].Piso << endl;
        cout << "Estado: " << Imoveis[i].Estado << endl;
        cout << "Armários: " << Imoveis[i].Armarios << endl;
        cout << "Ar Condicionado: " << Imoveis[i].ArCondicionado << endl;
        cout << "Aquecedor: " << Imoveis[i].Aquecedor << endl;
        cout << "Ventilador: " << Imoveis[i].Ventilador << endl;
        cout << "-------------------------" << endl;
    }
}


int main(){
    
    ifstream informacoes("../../data/BD_Imoveis2.txt");
    if (!informacoes) {
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }
    cout << "Arquivo aberto com sucesso!" << endl;
    Imovel Imoveis[200];
    int QuantAtual = 0;
    while (
        informacoes >> Imoveis[QuantAtual].Tipo
        >> Imoveis[QuantAtual].Finalidade
        >> Imoveis[QuantAtual].Endereco
        >> Imoveis[QuantAtual].Bairro
        >> Imoveis[QuantAtual].Cidade
        >> Imoveis[QuantAtual].Area
        >> Imoveis[QuantAtual].Valor
        >> Imoveis[QuantAtual].IPTU
        >> Imoveis[QuantAtual].Quartos
        >> Imoveis[QuantAtual].Suites
        >> Imoveis[QuantAtual].Banheiros
        >> Imoveis[QuantAtual].Vagas
        >> Imoveis[QuantAtual].Cozinha
        >> Imoveis[QuantAtual].Sala
        >> Imoveis[QuantAtual].Varanda
        >> Imoveis[QuantAtual].AreaServico
        >> Imoveis[QuantAtual].Piso
        >> Imoveis[QuantAtual].Estado
        >> Imoveis[QuantAtual].Armarios
        >> Imoveis[QuantAtual].ArCondicionado
        >> Imoveis[QuantAtual].Aquecedor
        >> Imoveis[QuantAtual].Ventilador
    ) {
    QuantAtual++;
    }

    int QuantLeitura;
    if(QuantAtual > 100)  QuantLeitura = 100;
    else QuantLeitura = QuantAtual;
    cout << "A lista de imoveis está carregada com " << QuantAtual << " imóveis." << endl;
 
    int quant = 0;
    int opcao;
    opcao = menu(quant); // exibe o menu uma vez antes do loop

    while (opcao != 0) {
        switch(opcao) {
            case 1:
                cout << "Incluindo um novo imóvel..." << endl;
                menuInclusao(QuantLeitura, Imoveis); // chama a função de inclusão
                QuantAtual++; // incrementa o contador de imóveis
                break;
            case 2:
                cout << "Acessando menu de busca..." << endl;
                menuBusca(QuantLeitura, Imoveis); // chama a função de busca
                break;
             case 3:{
                cout << "Acessando relatorio..." << endl;
                // lógica de relatório
                int totalImoveis = 0;
                int cVenda = 0;
                int cLocacao = 0;
                int totalCasas = 0;
                int casas_com_suite = 0;
                int salacomercial_totais = 0;
                int salacomercial_ceramica = 0;

                string line;
                while (getline(informacoes, line)) {
                    if (line.empty()) continue;

                    istringstream iss(line);
                    Imovel imovel;

                    string tipo_str, finalidade_str, piso_str, estado_str;
                    string cozinha_str, sala_str, varanda_str, area_servico_str;
                    string armarios_str, ar_str, aquecedor_str, ventilador_str;

                    // Leitura dos campos
                    iss >> tipo_str >> finalidade_str
                        >> imovel.Endereco >> imovel.Bairro >> imovel.Cidade
                        >> imovel.Area >> imovel.Valor >> imovel.IPTU
                        >> imovel.Quartos >> imovel.Suites >> imovel.Banheiros >> imovel.Vagas
                        >> cozinha_str >> sala_str >> varanda_str >> area_servico_str >> piso_str
                        >> estado_str >> armarios_str >> ar_str >> aquecedor_str >> ventilador_str;

                    // Preenchendo os campos da struct com strncpy
                    strncpy(imovel.Tipo, tipo_str.c_str(), sizeof(imovel.Tipo));
                    strncpy(imovel.Finalidade, finalidade_str.c_str(), sizeof(imovel.Finalidade));
                    strncpy(imovel.Cozinha, cozinha_str.c_str(), sizeof(imovel.Cozinha));
                    strncpy(imovel.Sala, sala_str.c_str(), sizeof(imovel.Sala));
                    strncpy(imovel.Varanda, varanda_str.c_str(), sizeof(imovel.Varanda));
                    strncpy(imovel.AreaServico, area_servico_str.c_str(), sizeof(imovel.AreaServico));
                    strncpy(imovel.Piso, piso_str.c_str(), sizeof(imovel.Piso));
                    strncpy(imovel.Estado, estado_str.c_str(), sizeof(imovel.Estado));
                    strncpy(imovel.Armarios, armarios_str.c_str(), sizeof(imovel.Armarios));
                    strncpy(imovel.ArCondicionado, ar_str.c_str(), sizeof(imovel.ArCondicionado));
                    strncpy(imovel.Aquecedor, aquecedor_str.c_str(), sizeof(imovel.Aquecedor));
                    strncpy(imovel.Ventilador, ventilador_str.c_str(), sizeof(imovel.Ventilador));

                    // Garantindo terminação nula
                    imovel.Tipo[sizeof(imovel.Tipo) - 1] = '\0';
                    imovel.Finalidade[sizeof(imovel.Finalidade) - 1] = '\0';

                    // Atualizar contagens
                    totalImoveis++;

                    if (strcmp(imovel.Finalidade, "venda") == 0)
                        cVenda++;
                    else
                        cLocacao++;

                    if (strcmp(imovel.Tipo, "casa") == 0) {
                        totalCasas++;
                        if (imovel.Suites > 0)
                            casas_com_suite++;
                    }

                    if (strcmp(imovel.Tipo, "sala_comercial") == 0) {
                        salacomercial_totais++;
                        if (strcmp(imovel.Piso, "ceramica") == 0 || strcmp(imovel.Piso, "cerâmica") == 0)
                            salacomercial_ceramica++;
                    }
                }


                // coommit teste
                
                informacoes.close();

                // Relatório
                relatorio(
                    totalImoveis,
                    cVenda,
                    cLocacao,
                    totalCasas,
                    casas_com_suite,
                    salacomercial_totais,
                    salacomercial_ceramica
                );
                break;
            }          
            case 4:
                cout << "Listando todos os imóveis disponíveis..." << endl;
                // lógica de listagem
                listarImoveis(Imoveis, QuantLeitura);        
            break;
            default:
                cout << "Opção inválida! Tente novamente." << endl;
            break;
        }
        cout << endl;
        opcao = menu(quant); // exibe o menu novamente após a execução da opção
    }
    cout << "Saindo do programa..." << endl;
    return 0;
} 