#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <vector>

#include "../include/SistemaMedico.hpp"


using namespace std;

//Struct do médico
struct Médico
{
    string nome;
    string especialidade;
    vector<string> Compromissos;
};

//Map que salva a especialidade do médico e os compromissos dele
map<string, Médico> mapMed;
map<string, int> mapEsp;
//map<string, string[]> mapAgenda;


//Funções que recebem entradas e as armazenam em variaveis
void contratar_medico()
{
    string nome;
    string especialidade;

    cout << "Nome: " << endl;
    getline(cin.ignore(), nome);

    cout << "Especialidade: " << endl;
    getline(cin, especialidade);

    mapMed[nome].nome = nome;
    mapMed[nome].especialidade = especialidade;

    registrar_medico(nome, especialidade);
}


void agendar_horario_medico()
{
    string nome;
    string horario;
    cout << "Digite o nome do Médico: ";
    getline(cin.ignore(), nome);
    cout << "Digite o horario: " ;
    getline(cin, horario);

    mapMed[nome].Compromissos.push_back(horario);

    salvar_compromisso(nome, mapMed[nome].Compromissos);
}



//Funções que recebem variáveis e salvam em arquivos .txt
void registrar_medico(string nome, string especialidade)
{
    fstream arquivo;
    arquivo.open("Medicos.txt", ios::out | ios::app);
    arquivo << nome << endl;
    arquivo << especialidade << endl;
    arquivo.close();
}
void salvar_compromisso(string nome, vector<string> compromissos)
{
    string linha;

    bool encontrado = false;
    bool salvo = false;

    fstream arquivo;
    fstream arquivoTemp;
    arquivo.open("Agenda.txt", ios::in | ios::out);
    arquivoTemp.open("Agenda_temp.txt", ios::out | ios::app);


        while (getline(arquivo, linha))
        {
            if (linha == nome)
            {
                encontrado = true;
            }
            if (linha != "+" || encontrado == false || salvo == true)
            {
                arquivoTemp << linha << endl;
            }
            else
            {
                arquivoTemp << compromissos[compromissos.size()-1] << endl;
                arquivoTemp << "+" << endl;
                salvo = true;
            }
        }
        if(encontrado == false)
        {
            arquivoTemp << nome << endl;
            for (int i = 0; i < compromissos.size(); i++)
            {
                arquivoTemp << compromissos[i] << endl;
            }
            arquivoTemp << "+" << endl;
        }

        arquivo.close();
        arquivoTemp.close();

        // Remove o arquivo original de compromissos
        remove("Agenda.txt");

        // Renomeia o arquivo temporário para o nome do arquivo original de compromissos
        rename("Agenda_temp.txt", "Agenda.txt");
    

}


//Funções que leem arquivos e fazem as saidas
void listar_especialidades()
{
    int idxLinha = 0;
    string linha;
    fstream arquivo;
    arquivo.open("Medicos.txt", ios::in);

    mapEsp.clear();

    while (getline(arquivo, linha))
    {
        if(idxLinha % 2 != 0)
        {
            mapEsp[linha] += 1;
        }
        idxLinha++;
    }
    arquivo.close();
    for (auto i: mapEsp)
    {
        cout << "Especialidade: " << i.first << ", Quantidade de médicos: " << i.second << endl;
    }
}
void listar_medicos()
{
    string linha;
    int idxLinha = 0;

    fstream arquivo;
    arquivo.open("Medicos.txt", ios::in);

    while (getline(arquivo, linha))
    {
        if(idxLinha % 2 == 0)
        {
            cout << "Médico: " << linha << endl;
        }
        else
        {
            cout << "Especialidade: " << linha << endl;
        }
        idxLinha++;
    }

    arquivo.close();
}
void ver_agenda()
{
    string nome;
    cout << "Nome: " << endl;
    getline(cin.ignore(), nome);

    string linha;
    fstream arquivo;
    arquivo.open("Agenda.txt", ios::in);
    while (getline(arquivo, linha))
    {
        if(linha == nome)
        {
            break;
        }
    }
    while (getline(arquivo, linha))
    {
        if(linha != "+")
        {
            cout << linha << endl;
        }
        else
        {
            break;
        }
    } 
}

//Funções que alteram informações já existentes
void alterar_especialidade()
{
    string nome;
    string novaEspecialidade;
    cout << "Digite o nome do Médico: ";
    getline(cin.ignore(), nome);
    cout << "Digite a nova especialidade: ";
    getline(cin, novaEspecialidade);

    // Atualiza a especialidade no mapMed
    mapMed[nome].especialidade = novaEspecialidade;

    // Abre o arquivo original para leitura
    fstream arquivoOriginal;
    arquivoOriginal.open("Medicos.txt", ios::in);

    // Abre o arquivo temporário para escrita
    fstream arquivoTemp;
    arquivoTemp.open("Medicos_temp.txt", ios::out);

    string linha;
    bool encontrado = false;

    // Percorre o arquivo original e faz as alterações no arquivo temporário
    while (getline(arquivoOriginal, linha))
    {
        if (linha == nome)
        {
            // Encontrou o médico, pula a linha da especialidade antiga
            getline(arquivoOriginal, linha);
            encontrado = true;
        }
        else
        {
            // Copia as linhas originais para o arquivo temporário
            arquivoTemp << linha << endl;
        }
    }

    // Escreve a nova especialidade no arquivo temporário
    arquivoTemp << nome << endl;
    arquivoTemp << novaEspecialidade << endl;

    // Fecha os arquivos
    arquivoOriginal.close();
    arquivoTemp.close();

    // Remove o arquivo original
    remove("Medicos.txt");

    // Renomeia o arquivo temporário para o nome do arquivo original
    rename("Medicos_temp.txt", "Medicos.txt");

    if (encontrado)
    {
        cout << "Especialidade alterada com sucesso." << endl;
    }
    else
    {
        cout << "Médico não encontrado." << endl;
    }
}
void excluir_medico()
{
    string nome;
    cout << "Digite o nome do Médico: ";
    getline(cin.ignore(), nome);

    // Verifica se o médico existe no mapa
    if (mapMed.find(nome) != mapMed.end())
    {
        // Remove o médico do mapa
        mapMed.erase(nome);

        // Abre o arquivo original de especialidades para leitura
        fstream arquivoEsp;
        arquivoEsp.open("Medicos.txt", ios::in);

        // Abre um novo arquivo temporário para escrita
        fstream arquivoTempEsp;
        arquivoTempEsp.open("Medicos_temp.txt", ios::out);

        string linha;

        // Percorre o arquivo original de especialidades e faz a exclusão do médico
        while (getline(arquivoEsp, linha))
        {
            if (linha != nome)
            {
                // Copia as linhas originais para o arquivo temporário, exceto a linha do médico a ser excluído
                arquivoTempEsp << linha << endl;
            }
            else
            {
                // Lê e descarta a linha da especialidade
                getline(arquivoEsp, linha);
            }
        }

        // Fecha os arquivos de especialidades
        arquivoEsp.close();
        arquivoTempEsp.close();

        // Remove o arquivo original de especialidades
        remove("Medicos.txt");

        // Renomeia o arquivo temporário para o nome do arquivo original de especialidades
        rename("Medicos_temp.txt", "Medicos.txt");

        // Abre o arquivo original de compromissos para leitura
        fstream arquivoComp;
        arquivoComp.open("Agenda.txt", ios::in);

        // Abre um novo arquivo temporário para escrita
        fstream arquivoTempComp;
        arquivoTempComp.open("Agenda_temp.txt", ios::out);

        bool encontrado = false;
        bool excluir = false;

        // Percorre o arquivo original de compromissos e faz a exclusão do médico
        while (getline(arquivoComp, linha))
        {
            if (linha == nome)
            {
                encontrado = true;
                excluir = true;
            }
            else if (linha == "+")
            {
                excluir = false;
            }
            else if (!excluir)
            {
                arquivoTempComp << linha << endl;
            }
        }

        // Fecha os arquivos de compromissos
        arquivoComp.close();
        arquivoTempComp.close();

        // Remove o arquivo original de compromissos
        remove("Agenda.txt");

        // Renomeia o arquivo temporário para o nome do arquivo original de compromissos
        rename("Agenda_temp.txt", "Agenda.txt");

        
    }

}