#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#include <locale.h>

#include <time.h>

#include <unistd.h>



#include "QUEUE.h"



#define max_user_char 100

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



// Fun��o auxiliar para gerar ID �nico entre 100 e 999
int generateUniqueId(Queue* emergency, Queue* normal, Queue* attended) {
    int id, exists;
    Node* p;

    do {
        id = 100 + rand() % 900; // 100 a 900
        exists = 0;

        for (p = emergency->beginning; p != NULL; p = p->next)
            if (p->petInfo.id == id) exists = 1;
        for (p = normal->beginning; p != NULL; p = p->next)
            if (p->petInfo.id == id) exists = 1;
        for (p = attended->beginning; p != NULL; p = p->next)
            if (p->petInfo.id == id) exists = 1;

    } while (exists);

    return id;
}



void companyShowcase();

void loginInformation();
void loginPage();

int optionsMenu();

void insertPet(Queue* emergency, Queue* normal, Queue* attended);
void attendPet(Queue* emergency, Queue* normal, Queue* attended);
void searchPet(Queue* emergency, Queue* normal, Queue* attended);
void printAllQueues(Queue* emergency, Queue* normal);
void printNextPet(Queue* emergency, Queue* normal);
void printAttendedPets(Queue* attended);



int main() {
    setlocale(LC_ALL, "portuguese");

    srand(time(NULL));

    Queue* normalQueue = createQueue();
    Queue* emergencyQueue = createQueue();
    Queue* attendedQueue = createQueue();

    int selected_option;

    loginPage();

    do {
        system("cls");

        selected_option = optionsMenu();

        switch(selected_option) {
            case 1:
                insertPet(emergencyQueue, normalQueue, attendedQueue);

                break;
            case 2:
                attendPet(emergencyQueue, normalQueue, attendedQueue);

                break;
            case 3:
                searchPet(emergencyQueue, normalQueue, attendedQueue);

                break;
            case 4:
                printAllQueues(emergencyQueue, normalQueue);

                break;
            case 5:
                printNextPet(emergencyQueue, normalQueue);

                break;
            case 6:
                printAttendedPets(attendedQueue);

                break;
            case 7:
                system("cls");

                companyShowcase();

                sleep(1);

                printf("\n Obrigado por utilizar os servi�os da \"Pet Queue\"!\n\n");

                break;
            default:
                printf("\n A op��o inserida � inv�lida, tente novamente!\n\n");

                sleep(1);

                system("cls");
                break;
        }
    } while(selected_option != 7);

    freeQueue(normalQueue);
    freeQueue(emergencyQueue);
    freeQueue(attendedQueue);

    system("pause");
    return 0;
}



void companyShowcase() {
    printf("\n           ,");
    printf("\n           \\`-._           __");
    printf("\n            \\  `-..____,.'  `.");
    printf("\n             :`.         /    \\`.");
    printf("\n             :  )       :      : \\");
    printf("\n              ;'        '   ;  |  :");
    printf("\n              )..      .. .:.`.;  :");
    printf("\n             /::...  .:::...   ` ;");
    printf("\n             ; _ '    __        /:\\");
    printf("\n             `:o>   /\\o_>      ;:. `.");
    printf("\n            `-`.__ ;   __..--- /:.   \\");
    printf("\n            === \\_/   ;=====_.':.     ;");
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
    printf("\n          /\\     ,/ \\      ;:::::;     ;");
    printf("\n        .:. \\:..|    :     ; '.--|     ;");
    printf("\n       ::.  :''  `-.,,;     ;'   ;     ;");
    printf("\n    .-'. _.'\\      / `;      \\,__:      \\");
    printf("\n    `---'    `----'   ;      /    \\,.,,,/");
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

        if((strcmp(user, "admin@petqueue.com") != 0) || (password != 1234)) {
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
    } while((strcmp(user, "admin@petqueue.com") != 0) || (password != 1234));

    system("cls");
}



int optionsMenu() {
    int selected_option;

    companyShowcase();

    printf("\n Ol�! Seja bem-vindo ao sistema de gerenciamento de atendimento em cl�nica veterin�ria.");

    printf("\n\n Abaixo, est�o listadas todas as op��es dispon�veis para serem executadas em nosso sistema.");
    printf("\n Escolha, dentre as op��es listadas abaixo (1-7), uma para ser executada a seguir.\n");

    sleep(1);

    printf("\n � Op��o 1: Inserir um pet na fila de atendimento;");
    printf("\n � Op��o 2: Realizar o atendimento de um pet;");
    printf("\n � Op��o 3: Buscar um pet pelo nome e/ou ID;");
    printf("\n � Op��o 4: Imprimir relat�rio dos pets na fila de atendimento (normal e emerg�ncia);");
    printf("\n � Op��o 5: Imprimir o pr�ximo pet a ser atendido;");
    printf("\n � Op��o 6: Imprimir todos os pets que j� foram atendidos;");
    printf("\n � Op��o 7: Sair;");

    sleep(1);
    printf("\n\n Op��o: ");
    scanf("%d", &selected_option);

    return selected_option;
}



void insertPet(Queue* emergency, Queue* normal, Queue* attended) {
    PetInfo newPet;

    char inclusion_confirmation;

    system("cls");

    companyShowcase();

    printf("\n Para incluir um animal na fila de atendimento (normal ou emerg�ncia), � necess�rio preencher algumas informa��es...");
    printf("\n\n Dentre as informa��es ncess�rias, informe, abaixo, os seguintes dados:");
    printf("\n � ID (autom�tico - preenchido pelo sistema);");
    printf("\n � Nome;");
    printf("\n � Esp�cie (cachorro, gato, etc...);");
    printf("\n � Idade;");
    printf("\n � Data de nascimento (DD MM AAAA);");
    printf("\n � Prioridade (0 = EMERG�NCIA | 1 = NORMAL);\n");

    sleep(1);

    newPet.id = generateUniqueId(emergency, normal, attended);

    printf("\n\n ID (autom�tico): %d", newPet.id);
    printf("\n  * OBS: Em nosso sistema, o ID do animal � gerado de forma AUTOM�TICA para evitar duplica��es.");

    printf("\n\n Nome: ");
    fflush(stdin);
    fgets(newPet.name, max_name_char, stdin);
    newPet.name[strcspn(newPet.name, "\n")] = 0;

    printf(" Esp�cie: ");
    fflush(stdin);
    fgets(newPet.specie, max_specie_char, stdin);
    newPet.specie[strcspn(newPet.specie, "\n")] = 0;

    printf(" Idade: ");
    scanf("%d", &newPet.age);

    printf(" Data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &newPet.birthDate.day, &newPet.birthDate.month, &newPet.birthDate.year);

    do {
        printf(" Prioridade (0 = EMERG�NCIA | 1 = NORMAL): ");
        scanf("%d", &newPet.priority);

        if(newPet.priority != 0 && newPet.priority != 1) {
            printf("\n A classifica��o de prioridade inserida � inv�lida!\n\n");
        }
    } while(newPet.priority != 0 && newPet.priority != 1);

    system("cls");

    companyShowcase();

    printf("\n Ao t�rmino do preenchimento dos dados solicitados, confirme o cadastro do seguinte animal na fila de atendimento:");

    printf("\n\n � ID (autom�tico): %d;", newPet.id);
    printf("\n � Nome: %s;", newPet.name);
    printf("\n � Esp�cie: %s;", newPet.specie);
    printf("\n � Idade: %02d;", newPet.age);
    printf("\n � Data de nascimento (DD MM AAAA): %02d/%02d/%02d;", newPet.birthDate.day, newPet.birthDate.month, newPet.birthDate.year);
    printf("\n � Prioridade (0 = EMERG�NCIA | 1 = NORMAL): %d;", newPet.priority);

    printf("\n\n Deseja confirmar a inclus�o do animal cujos dados est�o listados acima? [S/n]: ");

    do {
        fflush(stdin);
        inclusion_confirmation = getchar();
    } while((toupper(inclusion_confirmation) != 'S') && (tolower(inclusion_confirmation) != 'n'));

    if(toupper(inclusion_confirmation) == 'S') {
        if(newPet.priority == 0) {
            insertIntoQueue(emergency, newPet);
            printf("\n * Animal classificado como \"EMERG�NCIA\" na prioridade.");
        } else {
            insertIntoQueue(normal, newPet);
            printf("\n * Animal classificado como \"NORMAL\" na prioridade.");
        }
        printf("\n\n O animal foi inserido/cadastrado na fila de atendimento com sucesso!\n");
    } else {
        printf("\n A inclus�o do animal na fila de atendimento foi cancelada!\n");
    }

    printf("\n");
    sleep(1);
    system("pause");
}

void attendPet(Queue* emergency, Queue* normal, Queue* attended) {
    system("cls");

    companyShowcase();

    printf("\n Abaixo, verificaremos se h� algum animal, primeiramente, na fila de EMERG�NCIA e o atenderemos.\n Caso contr�rio, o pr�ximo animal a ser atendido ser� o primeiro animal da prioridade NORMAL.\n");

    PetInfo attendedPet;

    if (!isQueueEmpty(emergency)) {
        attendedPet = removeFromQueue(emergency);

        printf("\n Dados do animal em atendimento priorit�rio, devido � sua posi��o na fila de atendimento de emerg�ncia:");

        printf("\n\n � ID: %d;", attendedPet.id);
        printf("\n � Nome: %s;", attendedPet.name);
        printf("\n � Esp�cie: %s;", attendedPet.specie);
        printf("\n � Idade: %02d;", attendedPet.age);
        printf("\n � Data de nascimento (DD MM AAAA): %02d/%02d/%02d;", attendedPet.birthDate.day, attendedPet.birthDate.month, attendedPet.birthDate.year);

        printf("\n\n * OBS: Tipo de atendimento (prioridade): EMERG�NCIA\n", attendedPet.priority);
    } else if (!isQueueEmpty(normal)) {
        attendedPet = removeFromQueue(normal);

        printf("\n\n Dados do animal em atendimento, devido � sua posi��o na fila de atendimento normal:");

        printf("\n\n � ID: %d;", attendedPet.id);
        printf("\n � Nome: %s;", attendedPet.name);
        printf("\n � Esp�cie: %s;", attendedPet.specie);
        printf("\n � Idade: %02d;", attendedPet.age);
        printf("\n � Data de nascimento (DD MM AAAA): %02d/%02d/%02d;", attendedPet.birthDate.day, attendedPet.birthDate.month, attendedPet.birthDate.year);

        printf("\n\n * OBS: Tipo de atendimento (prioridade): NORMAL;\n", attendedPet.priority);
    } else {
        printf("\n �tima not�cia! N�o h� animais aguardando atendimento nas filas...\n\n");

        system("pause");

        return;
    }

    insertIntoQueue(attended, attendedPet);

    printf("\n");
    sleep(1);
    system("pause");
}

void searchPet(Queue* emergency, Queue* normal, Queue* attended) {
    int selected_option, id;

    char name[max_name_char];

    do {
        system("cls");
        companyShowcase();

        printf("\n Neste painel, � poss�vel buscar por animais nas filas de atendimento atrav�s de ID ou nome.");

        printf("\n\n Para tal, selecione, abaixo, a op��o desejada para buscar por um animal:");
        printf("\n � Op��o 1: ID;");
        printf("\n � Op��o 2: Nome;");

        printf("\n\n � Op��o 0: Voltar (menu inicial);");

        printf("\n\n Op��o: ");
        scanf("%d", &selected_option);

        system("cls");

        companyShowcase();

        switch (selected_option) {
            case 1: {
                printf("\n Para buscar por algum animal registrado nas filas de atendimento, siga a instru��o abaixo.");

                printf("\n\n Informe o ID do animal: ");
                scanf("%d", &id);

                PetInfo* pet = NULL;

                pet = searchById(emergency, id, 0);
                if (!pet) pet = searchById(normal, id, 0);

                if (!pet) pet = searchById(attended, id, 1);

                if (!pet) {
                    printf("\n N�o foi poss�vel encontrar nenhum animal com o ID \"%d\" nas filas de atendimento.\n", id);
                }

                printf("\n");
                system("pause");
                break;
            }
            case 2: {
                printf("\n Para buscar por algum animal registrado nas filas de atendimento, siga a instru��o abaixo.");
                printf("\n * OBS: Caso seja encontrado mais de um animal com o mesmo nome, todos ser�o exibidos...");

                printf("\n\n Informe o nome do animal: ");
                fflush(stdin);
                fgets(name, max_name_char, stdin);
                name[strcspn(name, "\n")] = 0;

                int total = 0;

                total += searchByName(emergency, name, 0);
                total += searchByName(normal, name, 0);

                total += searchByName(attended, name, 1);

                if (total == 0) {
                    printf("\n Nenhum animal encontrado com o nome \"%s\" nas filas de atendimento.\n", name);
                }

                printf("\n");
                system("pause");
                break;
            }
            case 0:
                printf("\n Retornando ao menu inicial...\n");

                sleep(1);
                break;
            default:
                printf("\n Op��o inv�lida! Tente novamente...\n");

                sleep(1);
                break;
        }
    } while (selected_option != 0);
}

void printAllQueues(Queue* emergency, Queue* normal) {
    system("cls");

    companyShowcase();

    printf("\n Abaixo, est�o listadas os animais cadastrados nas filas de atendimento EMERG�NCIA e NORMAL.");

    printf("\n\n --- EMERG�NCIA ---\n");
    printQueue(emergency);

    printf("\n\n --- NORMAL ---\n");
    printQueue(normal);

    printf("\n\n");
    sleep(1);
    system("pause");
}

void printNextPet(Queue* emergency, Queue* normal) {
    system("cls");

    companyShowcase();

    printf("\n Abaixo � exibido o pr�ximo animal aguardando atendimento registrado nas filas do sistema (emerg�ncia ou normal).");

    PetInfo* pet = getNextPet(emergency, normal);

    if(pet) {
        printf("\n\n Pr�ximo animal (aguardando atendimento):"),
        printf("\n  � Nome: %s;", pet -> name);
        printf("\n  � Esp�cie: %s;", pet -> specie);
        printf("\n  � Tipo de atendimento (prioridade): %s;", pet -> priority == 0 ? "Emerg�ncia (0)" : "Normal (1)\n");
    } else {
        printf("\n\n �tima not�cia! N�o h� animais aguardando atendimento nas filas...\n");
    }

    printf("\n");
    sleep(1);
    system("pause");
}

void printAttendedPets(Queue* attended) {
    system("cls");

    companyShowcase();

    printf("\n Abaixo, ser�o exibidos todos os animais que j� receberam atendimento (organizados na fila de animais atendidos).");

    Node* p;

    printf("\n\n ID | Nome | Esp�cie | Idade | Prioridade");
    printf("\n ------------------------------------------");

    for (p = attended -> beginning; p != NULL; p = p -> next) {
        printf("\n %d | %s | %s | %02d | %s",
               p -> petInfo.id,
               p -> petInfo.name,
               p -> petInfo.specie,
               p -> petInfo.age,
               (p -> petInfo.priority == 0 ? "Emerg�ncia" : "Normal"));
    }

    if (isQueueEmpty(attended)) {
        printf("\n\n A fila de animais atendidos est� vazia! Que tal iniciar alguns atendimentos?\n");
    }

    printf("\n\n");
    sleep(1);
    system("pause");
}
