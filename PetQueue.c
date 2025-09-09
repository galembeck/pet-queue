#include <stdio.h>
#include <stdlib.h>

#include <locale.h>

#define max_user_char 100
#define max_name_char 50
#define max_specie_char 30

/* Projeto Pr�tico (Atividade Avaliativa) 01 | Engenharia de Computa��o - Estrutura de Dados

    GERENCIAMENTO DE ATENDIMENTO EM CL�NICA VETERIN�RIA:

    � OBJETIVO:
        O objetivo deste projeto � aplicar os conceitos estudados de manipula��o din�mica de mem�ria,
        ponteiros e estruturas encadeadas em uma situa��o pr�tica e pr�xima do mundo real.

        A ideia � desenvolver um sistema para simular a fila de atendimento de pets em uma cl�nica veterin�ria.

        O sistema dever� simular a fila de atendimento de pets em uma cl�nica. Cada animal que chega
        deve ser registrado e inclu�do na fila. Animais em caso de emerg�ncia ter�o prioridade e
        devem ser atendidos antes dos demais.

        Portanto este sistema dever�, obrigatoriamente, trabalhar com FILAS.
            - O time dever� adaptar a biblioteca de Filas fornecida durante o estudo da mesma.


        As informa��es necess�rias de cada pet ser�o:
            � ID � c�digo inteiro gerado aleatoriamente entre 100 e 999 (N�O � PERMITIDO ID REPETIDO);
            � Nome � alfanum�rico com no m�ximo 50 caracteres;
            � Esp�cie� alfanum�rico com no m�ximo 30 caracteres (cachorro, gato, ave etc.);
            � Idade� inteiro;
            � Data de Nascimento � estrutura Data contendo dia, m�s e ano inteiros;
            � Prioridade (0 � Emerg�ncia, 1- Normal);

        ATEN��O: O time dever� trabalhar com duas filas: a de emerg�ncia e a de atendimento normal.

    � FUNCIONALIDADES:
        O sistema dever� ter as seguintes FUNCIONALIDADES:
            1. Inserir um pet na fila de atendimento:
                - O sistema dever� determinar se � um atendimento normal ou de emerg�ncia e coloc�-lo na fila correta (dados preenchidos).

            2. Atender o pet:
                - O pet ser� removido da fila;
                - O sistema dever� checar se h� pets na fila de emerg�ncia para remov�-los primeiro;
                - Dever� ser impresso os dados do pet e se foi um atendimento de emerg�ncia ou n�o;

            3. Buscar um pet pelo nome e/ou ID:
                - Caso encontrado, informar ID, Nome, Esp�cie, tipo de atendimento, se j� foi atendido ou n�o.
                - Se a busca encontrar mais de um pet com o mesmo nome, o sistema dever� imprimir todos.

            4. Imprimir um relat�rio com todos os pets na fila de atendimento tanto de emerg�ncia quanto normal:
                - Funcionalidade com a op��o de imprimir todos os pets tanto na fila normal quanto na de emerg�ncia, se existir.
                - O relat�rio dever� ser impresso respeitando o seguinte formato:
                    � ID | Nome | Esp�cie | Idade | Data de Nascimento | Prioridade

            5. Imprimir o pr�ximo pet a ser atendido:
                - As informa��es a serem impressas ser�o:
                    � Nome;
                    � Esp�cie;
                    � Tipo de atendimento emerg�ncia ou normal;

            6. Imprimir todos os pets que j� foram atendidos:
                - Imprimir todas as informa��es na ordem de atendimento.
                - O formato da impress�o deve ser:
                    � ID | Nome | Esp�cie | Idade | Prioridade
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

    printf("\n Ol�! Seja bem-vindo ao sistema de gerenciamento de atendimento em cl�nica veterin�ria.");

    printf("\n\n Para acessar o painel de controle da \"Pet Queue\", voc� deve utilizar o usu�rio a senha correta.");
    printf("\n H�, ao total, apenas 3 tentativas para efetuar corretamente o login (ap�s, o processo � cancelado).");

    printf("\n\n Informe, nos campos abaixo, o \"usu�rio\" e a \"senha\" corretos para acessar o painel.\n");
}

void loginPage() {
    char user[max_user_char];
    int password, trys = 0;

    do {
        loginInformation();

        sleep(1);

        printf("\n � Usu�rio: ");
        fflush(stdin);
        gets(user);

        printf(" � Senha: ");
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

            printf("\n Usu�rio e/ou senha incorreto(s)! Restam-lhe %d tentativas...\n\n", 3-trys);

            sleep(1);
            system("pause");
            system("cls");
        }

        if(trys == 3) {
            companyShowcase();

            sleep(1);

            printf("\n Que pena! Sua tentativas de login se esgotaram :(");
            printf("\n Parece que voc� n�o conseguiu acessar o painel de controle...\n");

            sleep(1);

            exit(0);
        }
    } while((strcmp(user, "admin") != 0) && (password != 1234));

    system("cls");
}
