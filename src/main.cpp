#include <iostream>
#include <fstream>

using namespace std;

typedef struct {
    int Tipo; // 1-casa, 2-apartamento, 3-terreno, 4-sala comerciial, 5-galpão
    int Finalidade; // 1-venda, 2-locação
    char Endereco[50]; // endereço do imóvel
    char Bairro[20]; // bairro do imóvel
    char Cidade[20]; // cidade do imóvel
    int Area; // área do imóvel em m²
    int Valor; // valor do imóvel
    int Quartos; // número de quartos
    int Suites; // número de suítes
    int Banheiros; // número de banheiros
    int Vagas; // número de vagas
    int Cozinha; // 1-sim, 0-não
    int Sala; // 1-sim, 0-não
    int Varanda; // 1-sim, 0-não
    int AreaServico; // 1-sim, 0-não
    char Piso[20]; // tipo de piso
    int Estado; // 1-novo, 2-usado, 3-reformado
    int Armarios; // 1-sim, 0-não
    int ArCondicionado; // 1-sim, 0-não
    int Aquecedor; // 1-sim, 0-não
    int Ventilador; // 1-sim, 0-não
}Imovel;

int menu() {
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

int main(){
    
    ifstream informacoes("BD_Imoveis2.txt");
    if (!informacoes) {
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }
    cout << "Arquivo aberto com sucesso!" << endl;
    Imovel Imoveis[100];

    return 0;
}