# 🏠 Projeto Imobiliária – Manipulação de Registros em Vetores

## 📚 Primeiro Projeto da Disciplina: **AEDs I Prática (UNIFAL-MG)**

Este é o primeiro projeto prático solicitado na disciplina de Algoritmos e Estruturas de Dados I (P), do curso Ciência da Computação **Universidade Federal de Alfenas (UNIFAL-MG)**.

---

## 🎯 Objetivo

> **Aprender manipulação de registros em vetores e construção de estatísticas com variáveis e estruturas de controle em C++.**

---

## 💻 Recursos Utilizados

- **Linguagem:** C++
- **IDE Recomendada:** NetBeans, DevC++ ou VSCode
- **Arquivo de Dados:** `BD_Imoveis2.txt`
- **Estruturas de Dados:** Vetores e Structs
- **Operações de Entrada/Saída:** Leitura e gravação em arquivo texto
- **Estruturas de Controle:** if/else, switch, for, while, do-while
- **Documentação:** Este README e comentários no código

---

## 📋 Descrição Geral

Este projeto consiste em um sistema de gerenciamento de imóveis para venda e locação, desenvolvido em C++.  
O sistema lê e grava informações de imóveis em um arquivo-texto, permitindo diversas operações de consulta, inserção e exclusão.

- **Arquivo:** `BD_Imoveis2.txt`
- **Limite:** 100 imóveis
- **Campos:** 22 atributos por imóvel (tipo, finalidade, endereço, bairro, cidade, área, valor, IPTU, quartos, suítes, banheiros, vagas, cozinha, sala, varanda, área de serviço, piso, conservação, armários, ar-condicionado, aquecedor, ventilador)
- **Observações:**  
  - Primeira linha do arquivo é descartada  
  - Última linha contém a palavra “fim” e não entra nas estatísticas

---

## 🛠 Funcionalidades

- **Adicionar imóvel**  
  Inclusão de um novo registro no sistema.
- **Buscar e excluir por rua**  
  Localiza imóveis pela rua e permite exclusão.
- **Buscar por faixa de valor**  
  Filtra imóveis por valores de venda, aluguel ou temporada.
- **Buscar por características**  
  Filtra por armários, ar-condicionado, aquecedor e ventilador.
- **Buscar por quartos e suítes**  
  Filtra por quantidade de quartos e suítes.
- **Relatório estatístico**  
  - Porcentagem de imóveis por finalidade
  - Porcentagem de casas com suítes
  - Porcentagem de salas comerciais com piso cerâmico
- **Listar todos os imóveis**  
  Exibe todos os imóveis cadastrados.

> **Dica:**  
> Ao excluir um imóvel, os registros seguintes são deslocados para não deixar “buracos” no vetor.

---

## 📂 Estrutura do Arquivo

```
tipo finalidade endereço bairro cidade área valor IPTU quartos suítes banheiros vagas cozinha sala varanda área_serviço piso conservação armários ar-condicionado aquecedor ventilador
Casa Venda Rua_Azul Centro CidadeX 120 350000 800 3 1 2 2 1 1 1 1 Cerâmica Nova Sim Não Não Sim
...
fim
```
- **Separador:** Espaço
- **Máximo:** 100 linhas (excluindo cabeçalho e linha “fim”)

---

## 🚀 Como Usar

1. **Pré-requisitos**
   - Compilador C++ (G++, Code::Blocks, DevC++, etc.)
   - Arquivo `BD_Imoveis2.txt` na mesma pasta do executável

2. **Compilação**
   - Abra o projeto em sua IDE ou terminal
   - Compile normalmente

3. **Execução**
   - Execute o programa
   - Utilize o menu interativo:

```
===== MENU =====
[1] Incluir novo imóvel
[2] Buscar e excluir por rua
[3] Buscar por faixa de valor
[4] Buscar por características
[5] Buscar por quartos e suítes
[6] Relatório estatístico
[7] Listar todos os imóveis
[8] Sair
================
```

4. **Limpeza e Entrega**
   - Limpe arquivos temporários e executáveis (Run → Batch Build Project → Clean)
   - Exporte o projeto para ZIP (File → Export Project → To ZIP…)

---

## 💡 Observações Importantes

- **Comente** seu código-fonte e coloque o nome dos autores no início do arquivo principal.
- **Dúvidas?** Consulte o professor.
- **Entrega:** Envie apenas o ZIP pelo Classroom, sem arquivos temporários ou executáveis.

---

## 👨‍💻 Autores

- Carlos Eduardo Pereira
- [Colegas,]
