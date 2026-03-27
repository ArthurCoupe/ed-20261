#ifndef AGENDA_H
#define AGENDA_H

#define LIMITE 100

typedef struct contato Contato;
typedef struct agenda Agenda;

Agenda criar_agenda(int tamanho);
void adcionar_contato(Agenda *agenda, Contato contato);
void remover_contato(Agenda *agenda, Contato contato);
void bloquear_contato(Agenda *agenda, Contato contato);
void desbloquear_contato(Agenda *agenda, Contato contato);
void editar_contato(Agenda *agenda, Contato contato);
void listar_contato(Agenda *agenda);