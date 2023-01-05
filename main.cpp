//---------------------------------------------------------------------
// Arquivo      : main.cpp
// Conteudo     : programa de avaliacao do TAD HEADERS
// Autor        : Marcelo Andrade
// Historico    : 2022-09-24 
//---------------------------------------------------------------------

#include <iostream>
#include "headers.h"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){

    string nomeArquivo = argv[1];

    Servidor *a = new Servidor();   //cria um ponteiro da classe Servidor para iniciar o programa

    ifstream arq;
    arq.open(nomeArquivo);    //abre o arquivo com dados

    string linha, comando, mensagem, temp;
    int id, prioridade;
    
    //realiza a leitura linha a linha
    while(getline(arq, linha)){

        stringstream str;

        //condicionais para os comandos do servidor
        if(linha.length() < 15){

            //lê a string e atribui para as variaveis 
            str << linha;
            str >> comando >> id;

            if(comando == "CADASTRA"){
                
                if(a->existe(id) == true){
                    
                    cout << "ERRO: CONTA " << id << " JA EXISTENTE" << endl;
                }
                else{

                    a->S_InsereFinal(id);
                    cout << "OK: CONTA " << id << " CADASTRADA" << endl;
                }
            }

            if(comando == "REMOVE"){
                
                if(a->existe(id) == false){
                    
                    cout << "ERRO: CONTA " << id << " NAO EXISTE" << endl;
                }
                else{

                    a->removeUsuario(id);
                    cout << "OK: CONTA " << id << " REMOVIDA" << endl;
                }
            }

            if(comando == "CONSULTA"){

                if(a->existe(id) == false){
                    
                    cout << "ERRO: CONTA " << id << " NAO EXISTE" << endl;
                }
                else{

                    if(a->usuarioVazio(id) == true){

                        cout << "CONSULTA " << id << ": CAIXA DE ENTRADA VAZIA" << endl;
                    }
                    else{

                        cout << "CONSULTA " << id << ": " << a->S_getPrimeiroEmail(id) << endl;
                        a->S_removePrimeiroEmail(id);
                    }
                }
            }    
        }
        else if(linha.length() > 15){

            //lê a string e atribui para as variaveis 
            str << linha;
            str >> comando >> id >> prioridade;
            string mensagem, aux;

            while(str){

                str >> aux;
                mensagem += aux;
                mensagem += " ";
            }

            if (!mensagem.empty()){

                mensagem.erase(mensagem.size() - 8);
            }
            
            if(comando == "ENTREGA"){
                
                if(a->existe(id) == false){
                    
                    cout << "ERRO: CONTA " << id << " NAO EXISTE" << endl;
                }
                else{

                    a->setUsuario(mensagem, 0, id, prioridade);
                    cout << "OK: MENSAGEM PARA " << id << " ENTREGUE" << endl;
                }
            }
        }
    }

    return 0;
}