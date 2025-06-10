#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

typedef struct {
    char Tipo[10]; // 1-casa, 2-apartamento, 3-terreno, 4-sala comerciial, 5-galpão
    char Finalidade[10]; // 1-venda, 2-locação, 3-temporada
    char Endereco[50]; // endereço do imóvel
    char Bairro[20]; // bairro do imóvel
    char Cidade[20]; // cidade do imóvel
    int Area; // área do imóvel em m²
    int Valor; // valor do imóvel
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
    cout << "1. Cadastrar Imóvel" << endl;
    cout << "2. Listar Imóveis" << endl;
    cout << "3. Buscar Imóvel" << endl;
    cout << "4. Excluir Imóvel" << endl;
    cout << "5. Sair" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;
    return opcao;
}

void menuBusca(int quant, Imovel Vetor[]) {
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
        char Tipo[10];
        cout << "Qual tipo de imovel você deseja?\n1.casa  2.apartamento  3.terreno  4.sala comerciial  5.galpão\nR:" << endl;
        cin >> Op;
        while (not(1 <= Op <= 5)){
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
        }else if(Op == 5){
            strcpy(Tipo, "galpão");
        }
        for(int i = 0 ; i < quant; i++){
            if(strcmp(Vetor[i].Tipo, Tipo) == 0){
                cout << i+1 << "°-É um(a) " << Tipo << " para " << Vetor[i].Finalidade << " no endereço " << Vetor[i].Endereco << " no bairro " << Vetor[i].Bairro << " da cidade " << Vetor[i].Cidade << " com " << Vetor[i].Area << "m² no valor de R$" << Vetor[i].Valor << ". Possui " << Vetor[i].Quartos << " Quartos, " << Vetor[i].Suites << " Suites, " << Vetor[i].Banheiros << " Banehiros e " << Vetor[i].Vagas << " Vagas. Cozinha:" << Vetor[i].Cozinha << " Sala:" << Vetor[i].Sala << " Varanda:" << Vetor[i].Varanda << " Area de Serviço:" << Vetor[i].AreaServico << " Tipo do piso: " << Vetor[i].Piso << " Ele está " << Vetor[i].Estado << " Ar condicionado:" << Vetor[i].ArCondicionado << " Aquicedor:" << Vetor[i].Aquecedor << " Ventilador:" << Vetor[i].Ventilador << endl;
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
            if(Min <= Vetor[i].Area <= Max){
                cout << i+1 << "°-É um(a) " << Vetor[i].Tipo << " para " << Vetor[i].Finalidade << " no endereço " << Vetor[i].Endereco << " no bairro " << Vetor[i].Bairro << " da cidade " << Vetor[i].Cidade << " com " << Vetor[i].Area << "m² no valor de R$" << Vetor[i].Valor << ". Possui " << Vetor[i].Quartos << " Quartos, " << Vetor[i].Suites << " Suites, " << Vetor[i].Banheiros << " Banehiros e " << Vetor[i].Vagas << " Vagas. Cozinha:" << Vetor[i].Cozinha << " Sala:" << Vetor[i].Sala << " Varanda:" << Vetor[i].Varanda << " Area de Serviço:" << Vetor[i].AreaServico << " Tipo do piso: " << Vetor[i].Piso << " Ele está " << Vetor[i].Estado << " Ar condicionado:" << Vetor[i].ArCondicionado << " Aquicedor:" << Vetor[i].Aquecedor << " Ventilador:" << Vetor[i].Ventilador << endl;               
            }
        }
        break;}
    case 8:
        menu(100);
        break;
    }
}

int main(){
    
    ifstream informacoes("BD_Imoveis2.txt");
    if (!informacoes) {
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }
    cout << "Arquivo aberto com sucesso!" << endl;
    int QuantMax = 200;
    Imovel Imoveis[QuantMax];
    int QuantAtual = 0;

    while (
        QuantAtual < QuantMax &&
        informacoes >> Imoveis[QuantAtual].Tipo
        >> Imoveis[QuantAtual].Finalidade
        >> Imoveis[QuantAtual].Endereco
        >> Imoveis[QuantAtual].Bairro
        >> Imoveis[QuantAtual].Cidade
        >> Imoveis[QuantAtual].Area
        >> Imoveis[QuantAtual].Valor
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

    menuBusca(QuantAtual,Imoveis);
    return 0;
}