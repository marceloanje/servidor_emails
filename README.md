# Servidor de Emails

## Descrição

Desenvolvimento de um servidor de emails eficiente, visando corrigir falhas e minimizar o consumo excessivo de memória do servidor atual. O objetivo é implementar um sistema robusto de gerenciamento de emails, explorando conceitos de tipos abstratos de dados e alocação dinâmica de memória para suportar as operações principais de cadastro, remoção, entrega e consulta de emails.

### Principais Funcionalidades

- **Cadastro de Novo Usuário:** Criação dinâmica de caixas de entrada para novos usuários, sem pré-definição de número máximo de contas. As mensagens destinadas a esses usuários são armazenadas na caixa de entrada correspondente.
- **Remoção de Usuário:** Exclusão de um usuário do sistema, incluindo a remoção automática de todas as mensagens da caixa de entrada associada.
- **Entrega de Email:** Recebimento e armazenamento de emails destinados a usuários existentes, ordenados por prioridade na caixa de entrada. A prioridade determina a ordem de armazenamento das mensagens.
- **Consulta de Email:** Recuperação da próxima mensagem na caixa de entrada de um usuário, com base na prioridade estabelecida.

---

## Complexidade Temporal e Espacial

### Complexidade Temporal

A complexidade temporal do programa é \( O(n^2) \), onde \( n \) representa a quantidade de operações ou elementos processados. Isso significa que o tempo de execução do programa aumenta quadrativamente com o aumento da quantidade de operações.

### Complexidade Espacial

A complexidade espacial do programa é \( O(n^2) \), refletindo que a quantidade de memória utilizada pelo programa também cresce quadrativamente com o aumento da quantidade de elementos processados.

---

### Instruções de Execução

Para compilar e executar este programa, siga estas etapas:

#### Requisitos

Certifique-se de ter os seguintes requisitos instalados no seu sistema:

- **GCC**: Um compilador C++ para compilar o código.
- **Make**: Uma ferramenta de automação de compilação.

#### Passos

1. **Clone o Repositório**
   ```bash
   git clone https://github.com/marceloanje/servidor_emails.git
   ```

2. **Navegue até a pasta do Projeto**
   ```bash
   cd servidor_emails
   ```

3. **Compilação**       
   Execute o comando make na pasta raiz do projeto para compilar o código.
   ```bash
   make
   ```
   
4. **Exucução**       
   Após a compilação bem-sucedida, execute o programa.
   ```bash
   run.out diretorio-do-arquivo-de-entrada
   ```

---

### Mais Detalhes

Um documento PDF contendo detalhes adicionais sobre o sistema está disponível [aqui](https://github.com/marceloanje/servidor_emails/blob/main/Documentacao.pdf). Esse documento oferece uma visão mais abrangente do projeto, incluindo descrições detalhadas, especificações técnicas e outras informações relevantes.
