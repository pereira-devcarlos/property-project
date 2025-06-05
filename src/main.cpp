#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct {
    char Tipo[10]; // 1-casa, 2-apartamento, 3-terreno, 4-sala comerciial, 5-galpão
    char Finalidade[10]; // 1-venda, 2-locação
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
        string Tipo;
        cout << "Qual tipo de imovel você deseja?\n1.casa  2.apartamento  3.terreno  4.sala comerciial  5.galpão\nR:" << endl;
        cin >> Op;
        while (not(1 <= Op <= 5)){
            cout << "Opção invalida, digite uma opção valida:";
            cin >> Op;
        }
        if(Op = 1){
            Tipo = "casa";
        }else if(Op = 2){
            Tipo = "apartamento";
        }else if(Op = 3){
            Tipo = "terreno";
        }else if(Op = 4){
            Tipo = "sala_comercial";
        }else if(Op = 5){
            Tipo = "galpão";
        }
        for(int i = 0 ; i < quant; i++){
            if(Vetor[i].Tipo == Tipo){
                cout << i << "°- " << Tipo <<  << endl;
            }
            
        };
        break;
    }
    case 2:
        
        break;
    case 3:
        
        break;
    case 4:
        
        break;
    case 5:
        
        break;
    case 6:
        
        break;
    case 7:
        
        break;
    case 8:
        menu();
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
    Imovel Imoveis[100];
    
    for(int i = 0; i < 100 ; i++){
        informacoes >> Imoveis[i].Tipo;
        informacoes >> Imoveis[i].Finalidade;
        informacoes >> Imoveis[i].Endereco;
        informacoes >> Imoveis[i].Bairro;
        informacoes >> Imoveis[i].Cidade;
        informacoes >> Imoveis[i].Area;
        informacoes >> Imoveis[i].Valor;
        informacoes >> Imoveis[i].Quartos;
        informacoes >> Imoveis[i].Suites;
        informacoes >> Imoveis[i].Banheiros;
        informacoes >> Imoveis[i].Vagas;
        informacoes >> Imoveis[i].Cozinha;
        informacoes >> Imoveis[i].Sala;
        informacoes >> Imoveis[i].Varanda;
        informacoes >> Imoveis[i].AreaServico;
        informacoes >> Imoveis[i].Piso;
        informacoes >> Imoveis[i].Estado;
        informacoes >> Imoveis[i].Armarios;
        informacoes >> Imoveis[i].ArCondicionado;
        informacoes >> Imoveis[i].Aquecedor;
        informacoes >> Imoveis[i].Ventilador;
    }


    return 0;
}