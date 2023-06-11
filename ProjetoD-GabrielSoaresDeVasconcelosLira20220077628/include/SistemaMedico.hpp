#ifndef SISTEMA_MEDICO
#define SISTEMA_MEDICO

#include <string>
#include <vector>


void contratar_medico();
void agendar_horario_medico();

void registrar_medico(std::string nome, std::string especialidade);
void salvar_compromisso(std::string nome, std::vector<std::string> compromissos);

void listar_especialidades();
void listar_medicos();
void ver_agenda();

void alterar_especialidade();
void excluir_medico();

#endif // 
