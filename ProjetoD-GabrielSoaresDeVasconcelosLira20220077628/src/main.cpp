#include <iostream>
#include <string>

#include "../include/SistemaMedico.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    string acesso;
    int opt;
    cout << "Bem vindo ao sistema gerenciador de médicos" << endl;
    cout << "Deseja entrar como:" << endl;
    cout << "1 - Atendente" << endl;
    cout << "2 - Gerente" << endl;
    cin >> opt;
    
    //While que controla o nível de acesso do usuário
    while(true)
    {
        if(opt == 1) 
        {
            acesso = "atendente";
        }
        else
        {
            string senha;
            while (senha != "admin")
            {
                cout << "Digite a senha: ";
                cin >> senha;
                if(senha == "admin")
                {
                    acesso = "admin";
                    break;
                }
                else
                {
                    cout << "Senha inválida" << endl;
                    cout << "Deseja: 1- Tentar novemente | 2- Entrar como atendente" << endl;
                    cin >> opt;
                    if(opt == 2)
                    {
                        acesso = "atendente";
                        break;
                    }
                }
            }
        }
        break;
    }
    while (true)
    {
        if(acesso == "admin")
        {
            string nome;
            string horario;

            cout << "1- Listar Médicos " << endl;
            cout << "2- Listar Epecialidades" << endl;
            cout << "3- Agendar Horario" << endl;
            cout << "4- Listar Agendamentos" << endl;
            cout << "5- Adicionar Novo médico" << endl;
            cout << "6- Alterar especialidade de médico" << endl;
            cout << "7- Excluir Médico" << endl;
            cout << "0- Sair" << endl;

            cin >> opt;

            switch(opt)
            {
                case 1:
                    listar_medicos();
                    break;
                case 2:
                    listar_especialidades();
                    break;
                case 3:
                    agendar_horario_medico();
                    break;
                case 4:
                    ver_agenda();
                    break;
                case 5:
                    contratar_medico();
                    break;
                case 6:
                    alterar_especialidade();
                    break;
                case 7:
                    excluir_medico();
                    break;
            }

            if(opt == 0)
            {
                break;
            }

        }
        else if (acesso == "atendente")
        {
            string nome;
            string horario;

            cout << "1- Listar Médicos " << endl;
            cout << "2- Listar Epecialidades" << endl;
            cout << "3- Agendar Horario" << endl;
            cout << "4- Listar Agendamentos" << endl;
            cout << "0- Sair" << endl;

            cin >> opt;

            switch(opt)
            {
                case 1:
                    listar_medicos();
                    break;
                case 2:
                    listar_especialidades();
                    break;
                case 3:
                    agendar_horario_medico();
                    break;
                case 4:
                    ver_agenda();
                    break;
            }

            if(opt == 0)
            {
                break;
            }
        }
    }
    
}   