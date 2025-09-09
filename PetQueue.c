#include <stdio.h>
#include <stdlib.h>

#include <locale.h>

#define max_user_char 100
#define max_name_char 50
#define max_specie_char 30

/* Projeto Prático (Atividade Avaliativa) 01 | Engenharia de Computação - Estrutura de Dados

    GERENCIAMENTO DE ATENDIMENTO EM CLÍNICA VETERINÁRIA:

    º OBJETIVO:
        O objetivo deste projeto é aplicar os conceitos estudados de manipulação dinâmica de memória,
        ponteiros e estruturas encadeadas em uma situação prática e próxima do mundo real.

        A ideia é desenvolver um sistema para simular a fila de atendimento de pets em uma clínica veterinária.

        O sistema deverá simular a fila de atendimento de pets em uma clínica. Cada animal que chega
        deve ser registrado e incluído na fila. Animais em caso de emergência terão prioridade e
        devem ser atendidos antes dos demais.

        Portanto este sistema deverá, obrigatoriamente, trabalhar com FILAS.
            - O time deverá adaptar a biblioteca de Filas fornecida durante o estudo da mesma.


        As informações necessárias de cada pet serão:
            • ID – código inteiro gerado aleatoriamente entre 100 e 999 (NÃO É PERMITIDO ID REPETIDO);
            • Nome – alfanumérico com no máximo 50 caracteres;
            • Espécie– alfanumérico com no máximo 30 caracteres (cachorro, gato, ave etc.);
            • Idade– inteiro;
            • Data de Nascimento – estrutura Data contendo dia, mês e ano inteiros;
            • Prioridade (0 – Emergência, 1- Normal);

        ATENÇÃO: O time deverá trabalhar com duas filas: a de emergência e a de atendimento normal.

    º FUNCIONALIDADES:
        O sistema deverá ter as seguintes FUNCIONALIDADES:
            1. Inserir um pet na fila de atendimento:
                - O sistema deverá determinar se é um atendimento normal ou de emergência e colocá-lo na fila correta (dados preenchidos).

            2. Atender o pet:
                - O pet será removido da fila;
                - O sistema deverá checar se há pets na fila de emergência para removê-los primeiro;
                - Deverá ser impresso os dados do pet e se foi um atendimento de emergência ou não;

            3. Buscar um pet pelo nome e/ou ID:
                - Caso encontrado, informar ID, Nome, Espécie, tipo de atendimento, se já foi atendido ou não.
                - Se a busca encontrar mais de um pet com o mesmo nome, o sistema deverá imprimir todos.

            4. Imprimir um relatório com todos os pets na fila de atendimento tanto de emergência quanto normal:
                - Funcionalidade com a opção de imprimir todos os pets tanto na fila normal quanto na de emergência, se existir.
                - O relatório deverá ser impresso respeitando o seguinte formato:
                    • ID | Nome | Espécie | Idade | Data de Nascimento | Prioridade

            5. Imprimir o próximo pet a ser atendido:
                - As informações a serem impressas serão:
                    • Nome;
                    • Espécie;
                    • Tipo de atendimento emergência ou normal;

            6. Imprimir todos os pets que já foram atendidos:
                - Imprimir todas as informações na ordem de atendimento.
                - O formato da impressão deve ser:
                    • ID | Nome | Espécie | Idade | Prioridade
*/

void companyShowcase();

void loginInformation();
void loginPage();

int main() {
    setlocale(LC_ALL, "portuguese");

    loginPage();

    system("pause");
    return 0;
}

void companyShowcase() {
    printf("\n           ,");
    printf("\n           \`-._           __");
    printf("\n            \\  `-..____,.'  `.");
    printf("\n             :`.         /    \`.");
    printf("\n             :  )       :      : \\");
    printf("\n              ;'        '   ;  |  :");
    printf("\n              )..      .. .:.`.;  :");
    printf("\n             /::...  .:::...   ` ;");
    printf("\n             ; _ '    __        /:\\");
    printf("\n             `:o>   /\o_>      ;:. `.");
    printf("\n            `-`.__ ;   __..--- /:.   \\");
    printf("\n            === \_/   ;=====_.':.     ;");
    printf("\n             ,/'`--'...`--....        ;");
    printf("\n                  ;                    ;");
    printf("\n                .'                      ;");
    printf("\n              .'                        ;");
    printf("\n            .'     ..     ,      .       ;");
    printf("\n           :       ::..  /      ;::.     |");
    printf("\n          /      `.;::.  |       ;:..    ;");
    printf("\n         :         |:.   :       ;:.    ;");
    printf("\n         :         ::     ;:..   |.    ;");
    printf("\n          :       :;      :::....|     |");
    printf("\n          /\     ,/ \      ;:::::;     ;");
    printf("\n        .:. \:..|    :     ; '.--|     ;");
    printf("\n       ::.  :''  `-.,,;     ;'   ;     ;");
    printf("\n    .-'. _.'\      / `;      \,__:      \\");
    printf("\n    `---'    `----'   ;      /    \,.,,,/");
    printf("\n                       `----`");

    printf("\n\n        \"Pet Queue | Vet Booking System\"\n\n");
}

void loginInformation() {
    companyShowcase();

    printf("\n Olá! Seja bem-vindo ao sistema de gerenciamento de atendimento em clínica veterinária.");

    printf("\n\n Para acessar o painel de controle da \"Pet Queue\", você deve utilizar o usuário a senha correta.");
    printf("\n Há, ao total, apenas 3 tentativas para efetuar corretamente o login (após, o processo é cancelado).");

    printf("\n\n Informe, nos campos abaixo, o \"usuário\" e a \"senha\" corretos para acessar o painel.\n");
}

void loginPage() {
    char user[max_user_char];
    int password, trys = 0;

    do {
        loginInformation();

        sleep(1);

        printf("\n º Usuário: ");
        fflush(stdin);
        gets(user);

        printf(" º Senha: ");
        scanf("%d", &password);

        sleep(1);

        printf("\n Carregando");

        sleep(1);
        printf(" .");
        sleep(1);
        printf(" .");
        sleep(1);
        printf(" .\n\n");

        sleep(1);

        if((strcmp(user, "admin") != 0) && (password != 1234)) {
            trys++;

            printf("\n Usuário e/ou senha incorreto(s)! Restam-lhe %d tentativas...\n\n", 3-trys);

            sleep(1);
            system("pause");
            system("cls");
        }

        if(trys == 3) {
            companyShowcase();

            sleep(1);

            printf("\n Que pena! Sua tentativas de login se esgotaram :(");
            printf("\n Parece que você não conseguiu acessar o painel de controle...\n");

            sleep(1);

            exit(0);
        }
    } while((strcmp(user, "admin") != 0) && (password != 1234));

    system("cls");
}
