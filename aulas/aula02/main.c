#include <stdio.h>
#include <string.h>
#include "agenda.h"

int main() {
    Agenda agenda = criar_agenda(10);

    Contato contato;
    strcpy(contato.nome, "Jose");
    strcpy(contato.telefone, "1111-1111");

    adicionar_contato(agenda, contato);

    listar_contatos(agenda);

    return 0;
}