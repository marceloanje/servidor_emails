//---------------------------------------------------------------------
// Arquivo	    : headers.cpp
// Conteudo	    : implementacao do TAD HEADERS
// Autor	    : Marcelo Andrade
// Historico	: 2022-09-24
//---------------------------------------------------------------------

#include "headers.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


//*******************EMAIL*******************

//contrutor default - inicia a classe Email sem argumentos
//entrada:
//saida:
Email::Email(){}

//contrutor parametrico - inicia a classe Email com valores
//entrada: mensagem, origem, destino, prioridade
//saida:
Email::Email(string _mensagem, int _origem, int _destino, int _prioridade){

    mensagem = _mensagem;
    origem = _origem;
    destino = _destino;
    prioridade = _prioridade;
}

//metodo get para mensagem - retorna o valor de mensagem
//entrada:
//saida: mensagem
string Email::getMensagem(){

    return mensagem;
}

//metodo get para prioridade - retorna o valor de prioridade
//entrada:
//saida: prioridade
int Email::getPrioridade(){

    return prioridade;
}

//metodo set para prox - altera o valor de prox
//entrada: Email
//saida:
void Email::E_setProx(Email* p){

    prox = p;
}

//*******************USUARIO*******************

//contrutor default - inicia a classe Usuario sem argumentos
//entrada:
//saida:
Usuario::Usuario(){

    primeiro = NULL;
    ultimo = primeiro;   
}

//contrutor parametrico - inicia a classe Usuario com valores
//entrada: id
//saida:
Usuario::Usuario(int _id){

    ID = _id;

    primeiro = NULL;
    ultimo = primeiro;
}

//destrutor - deleta um Usuario
//entrada:
//saida:
Usuario::~Usuario(){

    U_Limpa();
    delete primeiro;
}

//metodo set para prox - altera o valor de prox
//entrada: Usuario
//saida:
void Usuario::U_setProx(Usuario* p){

    prox = p;
}

//metodo get para prox - retorna o valor de prox
//entrada:
//saida: prox
Usuario* Usuario::U_getProx(){

    return prox;
}

//metodo get para id - retorna o valor de id
//entrada:
//saida: id
int Usuario::getID(){

    return ID;
}

//metodo get para email - retorna o valor do primeiro email da lista
//entrada:
//saida: mensagem
string Usuario::getPrimeiroEmail(){

    Email* e;

    e = primeiro;

    return e->getMensagem();
}

//metodo para esvaziar a lista de Email
//entrada:
//saida:
void Usuario::U_Limpa(){

    Email *p;

    p = primeiro->prox;
    while(p!=NULL){
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
}

//metodo booleano para verificar se a lista de Email de um Usuario esta vazia
//entrada:
//saida: true ou false
bool Usuario::U_Vazia(){

    return (primeiro == NULL);
}

//metodo para inserir um Email no final da lista
//entrada: mensagem, origem, destino, prioridade
//saida:
void Usuario::U_InsereFinal(string _mensagem, int _origem, int _destino, int _prioridade){

    Email *novo = new Email(_mensagem, _origem, _destino, _prioridade);

    if(U_Vazia()){

        primeiro = novo;
        ultimo = novo;
    }
    else{

        ultimo->E_setProx(novo);
        ultimo = novo;
    }
}

//metodo para inserir um email na lista de acordo com sua prioridade
//entrada: mensagem, origem, destino, prioridade
//saida:
void Usuario::InsereOrdenado(string _mensagem, int _origem, int _destino, int _prioridade){

    Email *novo = new Email(_mensagem, _origem, _destino, _prioridade);
    Email *aux;

    if(U_Vazia()){
        primeiro = novo;
        ultimo = primeiro;
        ultimo->prox = NULL;
    }
    else if(novo->getPrioridade() > primeiro->getPrioridade()){

        novo->E_setProx(primeiro);
        primeiro = novo;
    }
    else{
        aux = primeiro;

        while(aux->prox && novo->getPrioridade() <= aux->prox->getPrioridade())

            aux = aux->prox;
            novo->E_setProx(aux->prox);
            aux->E_setProx(novo);
    }
}

//metodo para remover o primeiro Email da lista de um Usuario
//entrada:
//saida:
void Usuario::removePrimeiroEmail(){

    Email* e;

    if(Tamanho() == 1){
        primeiro == NULL;
        ultimo = primeiro;
    }

    e = primeiro->prox;
    primeiro = e;

    if(primeiro == NULL){
        
        ultimo = primeiro;
    }
    else if(primeiro->prox == NULL){

        ultimo = primeiro;
    }
}

//metodo que informa o tamanho da lista de um Usuario
//entrada:
//saida: tamanho
int Usuario::Tamanho(){

        if(U_Vazia()) // se for vazia, entã retorna 0
			return 0;

		Email* e = primeiro;
		int tam = 0;
		
		// percorre a lista
		do{
			e = e->prox;
			tam++;
		}
		while(e);
		
		return tam;
}


//*******************Servidor*******************

//contrutor default - inicia a classe Servidor sem argumentos
//entrada:
//saida:
Servidor::Servidor(){

    primeiro = NULL;
    ultimo = primeiro;   
}

//contrutor parametrico - inicia a classe Servidor com um usuario
//entrada: id
//saida:
Servidor::Servidor(int _id){

    primeiro = new Usuario(_id);
    ultimo = primeiro;
}

//destrutor - deleta um Servidor
//entrada:
//saida:
Servidor::~Servidor(){

    S_Limpa();
    delete primeiro;
}

//metodo set para Usuario - adicona email a um membro da lista de Usuario determinado
//entrada: mensagem, origem, destino, prioridade
//saida:
void Servidor::setUsuario(string _mensagem, int _origem, int _destino, int _prioridade){

    Usuario *p;

    p = Posiciona(_destino);
    p->InsereOrdenado(_mensagem, _origem, _destino, _prioridade);
}

//metodo get para Usuario - retorna o primeiro email de membro da lista de Usuario determinado
//entrada: id
//saida: mensagem
string Servidor::S_getPrimeiroEmail(int id){

    Usuario* p;

    p = Posiciona(id);

    return p->getPrimeiroEmail();
}

//metodo para posicionar o ponteiro na posição estabelecida
//entrada: posição, bool
//saida: Usuario
Usuario* Servidor::Posiciona(int id){

    Usuario* p = primeiro;
		
		while(p){

			if(p->getID() == id)
				return p;

			p = p->prox;
		}
}

//metodo para esvaziar a lista de Usuario
//entrada:
//saida:
void Servidor::S_Limpa(){

    Usuario *p;

    p = primeiro->prox;
    while(p!=NULL){
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}

//metodo booleano para verificar se a lista de Usuario esta vazia
//entrada:
//saida: true ou false
bool Servidor::S_Vazia(){

    return (primeiro == NULL);
}

//metodo para inserir um Usuario no final da lista
//entrada: id
//saida:
void Servidor::S_InsereFinal(int _id){

    Usuario *aux, *novo = new Usuario(_id);

    novo->prox = NULL;

    if(primeiro == NULL){
        
        primeiro = novo;
    }
    else{

        aux = primeiro;
        while(aux->prox)
            aux = aux->prox;
        aux->prox = novo;
    }
    tamanho++;
}

//metodo para remover o primeiro Email de um membro da lista de Usuario
//entrada: id
//saida:
void Servidor::S_removePrimeiroEmail(int id){

    Usuario *p;

    if(primeiro->getID() == id){
        p = primeiro;
    }
    else{
        p = Posiciona(id);
    }

    p->removePrimeiroEmail();
}

//metodo para remover um membro determinado da lista de Usuario
//entrada: id
//saida:
void Servidor::removeUsuario(int id){

    Usuario *aux, *remover = NULL;

    if(primeiro->getID() == id){

        remover = primeiro;
        primeiro = remover->prox;
    }
    else{

        aux = primeiro;
        while(aux->prox && aux->prox->getID() != id)
            aux = aux->prox;
        if(aux->prox){

            remover = aux->prox;
            aux->prox = remover->prox;
        }  
    }
    tamanho--;
}

//metodo para verificar se um deterinado membro da lista de Usuario existe
//entrada: id
//saida: true ou false
bool Servidor::existe(int id){

    Usuario* c = primeiro;
    int cont = 0;
		
		while(cont < tamanho){
            if(c == NULL)
                return false;
            
			if(c->getID() == id)
				return true;

			c = c->U_getProx();
            
            cont++;
		}

	return false;
}

//metodo para verificar se um deterinado membro da lista de Usuario esta vazio
//entrada: id
//saida: true ou false
bool Servidor::usuarioVazio(int id){

    Usuario* p;

    if(primeiro->getID() == id){
        p = primeiro;
    }
    else{
        p = Posiciona(id);
    }
    
    return p->U_Vazia();
}