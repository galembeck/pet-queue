# Projeto PetQueue

Este projeto é uma implementação de uma fila de atendimento para pets, desenvolvida em C, como parte da disciplina de Estrutura de Dados. O objetivo é gerenciar o atendimento de animais de estimação em uma clínica veterinária, utilizando uma estrutura de dados do tipo fila (Queue).

## Estrutura do Projeto
- `src/QUEUE.h`: Biblioteca que define a estrutura da fila e suas funções.
- `src/PetQueue.c`: Código principal do sistema, responsável pela interação com o usuário e execução das funcionalidades do menu.
- `public/ESTRUTURA DE DADOS - PROJETO 01.pdf`: Documento com a especificação do projeto.

## Estrutura de Dados
A fila é implementada para armazenar informações dos pets que aguardam atendimento. Cada elemento da fila representa um pet, contendo dados como nome, espécie, idade, e motivo do atendimento.

### Funções da Biblioteca (`QUEUE.h`)
A biblioteca define as principais operações sobre a fila:
- **Inicialização da fila**: Cria uma fila vazia pronta para uso.
- **Inserção (enqueue)**: Adiciona um novo pet ao final da fila.
- **Remoção (dequeue)**: Remove o pet do início da fila (atendimento realizado).
- **Verificação de fila vazia**: Indica se há pets aguardando atendimento.
- **Verificação de fila cheia**: Indica se a fila atingiu sua capacidade máxima.
- **Consulta ao primeiro elemento**: Permite visualizar o próximo pet a ser atendido.
- **Exibição da fila**: Mostra todos os pets aguardando atendimento.

## Funcionamento do Sistema
O sistema apresenta um menu interativo ao usuário, permitindo as seguintes funcionalidades:

1. **Adicionar pet à fila**: O usuário informa os dados do pet, que é inserido na fila de atendimento.
2. **Atender pet**: Remove o pet do início da fila, simulando o atendimento.
3. **Visualizar próximo pet**: Exibe os dados do pet que será atendido em seguida.
4. **Listar todos os pets na fila**: Mostra todos os pets aguardando atendimento.
5. **Verificar se a fila está vazia ou cheia**: Informa o estado atual da fila.
6. **Sair**: Encerra o programa.

## Como Executar
1. Compile o projeto utilizando um compilador C:
   ```sh
   gcc src/PetQueue.c -o src/PetQueue.exe
   ```
2. Execute o programa:
   ```sh
   ./src/PetQueue.exe
   ```

## Considerações
- O projeto utiliza conceitos fundamentais de filas para gerenciar o atendimento de pets.
- O menu facilita a interação e o gerenciamento dos dados.
- O código está organizado para facilitar manutenção e futuras melhorias.

---

**Desenvolvido para fins acadêmicos na disciplina de Estrutura de Dados.**
