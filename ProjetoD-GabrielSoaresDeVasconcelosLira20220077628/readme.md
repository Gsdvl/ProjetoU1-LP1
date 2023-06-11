## Projeto unidade 1 Linguagem de Programação 1

## Sobre o projeto:
    Este projeto foi realizado durante a 1 unidade da matéria de Linguagem de Programação 1 do Bacharelado em Tecnologia da informação da UFRN pelo IMD
    por Gabriel Soares de Vasconcelos Lira
# Proposta
    
    Trata-se de um sistema de gerenciamento de médico com 2 possíveis usuários: Atendente e Gerente

    O acesso de atendente pode ser livremente acessada, e possui as opções de:
    Listar médicos, listar especialidades e quantos médicos disponiveis de cada, agendar horarios e listar os horarios de um médico especifico

    O acesso de gerente só pode ser acessado se for utilizada a senha : "admin", e possui as mesmas opções do atendente, mais as seguintes:
    Adicionar médicos novos, alterar a especialidade de algum médico e excluir um médico

# Organização de arquivos

    O projeto foi modularizado em 3 pastas: A pasta bin, que contem o arquivo compilado pronto para ser executado, a pasta include que contém
    os cabeçalhos .hpp, e a pasta src que contém tanto os arquivos .cpp quanto os arquivos de texto que armazenam os dados, permitindo que o

    dentro da pasta src, estão contidos os arquivos SistemaMedico.cpp e o main.cpp

# Como usar

    Para pôr o programa em funcionamento, você precisa necessariamente executar o programa localizado na pasta bin estando com o diretório na pasta src
    pois assim os códigos em cpp conseguirão ler os arquivos.txt que o programa irá gerar durante a execução, para tal, abra o terminal e navegue até a pasta src de onde o programa está instalado

    a seguir, execute o seguinte comando para compilar os arquivos
        g++ main.cpp SistemaMedico.cpp -o../bin/Programa 
    E para executar, é necessário enviar o seguinte comando no terminal
        ../bin/Programa 
