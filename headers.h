//---------------------------------------------------------------------
// Arquivo	    : headers.h
// Conteudo	    : definicoes do TAD HEADERS
// Autor	    : Marcelo Andrade
// Historico	: 2022-09-24
//---------------------------------------------------------------------

#ifndef HEADERS_H
#define HEADERS_H

#include <iostream>
#include <string>

using namespace std;

class Email{
    private:
        string mensagem;
        int origem;
        int destino;
        int prioridade;

        Email* prox;

    public:
        //construtores
        Email();
        Email(string, int, int, int);

        //metodos basicos
        string getMensagem();
        int getPrioridade();
        void E_setProx(Email*);
        
    friend class Usuario;
};

class Usuario{
    private:
        int ID;

        Email* primeiro;
        Email* ultimo;
        Usuario* prox;

    public:
        //construtores
        Usuario();
        Usuario(int);
        ~Usuario();

        //metodos basicos
        void U_setProx(Usuario*);
        Usuario* U_getProx();
        int getID();
        string getPrimeiroEmail();

        //outros metodos
        void U_Limpa();
        bool U_Vazia();
        void U_InsereFinal(string, int, int, int);
        void InsereOrdenado(string, int, int, int);
        void removePrimeiroEmail();
        int Tamanho();

    friend class Servidor;
};

class Servidor{
    private:
        int tamanho;

        Usuario* primeiro;
        Usuario* ultimo;
        Usuario* Posiciona(int);

    public:
        //construtores
        Servidor();
        Servidor(int);
        ~Servidor();

        //metodos basicos
        void setUsuario(string, int, int, int);
        string S_getPrimeiroEmail(int);

        //outros metodos
        void S_Limpa();
        bool S_Vazia();
        void S_InsereFinal(int);
        void S_removePrimeiroEmail(int);
        void removeUsuario(int);
        bool existe(int);
        bool usuarioVazio(int);
};

#endif