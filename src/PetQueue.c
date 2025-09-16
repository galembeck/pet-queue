#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#include <locale.h>

#include <time.h>

#include <unistd.h>



#include "QUEUE.h"



#define max_user_char 100

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



// Função auxiliar para gerar ID único entre 100 e 999
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

                printf("\n Obrigado por utilizar os serviços da \"Pet Queue\"!\n\n");

                break;
            default:
                printf("\n A opção inserida é inválida, tente novamente!\n\n");

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

        if((strcmp(user, "admin@petqueue.com") != 0) || (password != 1234)) {
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
    } while((strcmp(user, "admin@petqueue.com") != 0) || (password != 1234));

    system("cls");
}



int optionsMenu() {
    int selected_option;

    companyShowcase();

    printf("\n Olá! Seja bem-vindo ao sistema de gerenciamento de atendimento em clínica veterinária.");

    printf("\n\n Abaixo, estão listadas todas as opções disponíveis para serem executadas em nosso sistema.");
    printf("\n Escolha, dentre as opções listadas abaixo (1-7), uma para ser executada a seguir.\n");

    sleep(1);

    printf("\n º Opção 1: Inserir um pet na fila de atendimento;");
    printf("\n º Opção 2: Realizar o atendimento de um pet;");
    printf("\n º Opção 3: Buscar um pet pelo nome e/ou ID;");
    printf("\n º Opção 4: Imprimir relatório dos pets na fila de atendimento (normal e emergência);");
    printf("\n º Opção 5: Imprimir o próximo pet a ser atendido;");
    printf("\n º Opção 6: Imprimir todos os pets que já foram atendidos;");
    printf("\n º Opção 7: Sair;");

    sleep(1);
    printf("\n\n Opção: ");
    scanf("%d", &selected_option);

    return selected_option;
}



void insertPet(Queue* emergency, Queue* normal, Queue* attended) {
    PetInfo newPet;

    char inclusion_confirmation;

    system("cls");

    companyShowcase();

    printf("\n Para incluir um animal na fila de atendimento (normal ou emergência), é necessário preencher algumas informações...");
    printf("\n\n Dentre as informações ncessárias, informe, abaixo, os seguintes dados:");
    printf("\n º ID (automático - preenchido pelo sistema);");
    printf("\n º Nome;");
    printf("\n º Espécie (cachorro, gato, etc...);");
    printf("\n º Idade;");
    printf("\n º Data de nascimento (DD MM AAAA);");
    printf("\n º Prioridade (0 = EMERGÊNCIA | 1 = NORMAL);\n");

    sleep(1);

    newPet.id = generateUniqueId(emergency, normal, attended);

    printf("\n\n ID (automático): %d", newPet.id);
    printf("\n  * OBS: Em nosso sistema, o ID do animal é gerado de forma AUTOMÁTICA para evitar duplicações.");

    printf("\n\n Nome: ");
    fflush(stdin);
    fgets(newPet.name, max_name_char, stdin);
    newPet.name[strcspn(newPet.name, "\n")] = 0;

    printf(" Espécie: ");
    fflush(stdin);
    fgets(newPet.specie, max_specie_char, stdin);
    newPet.specie[strcspn(newPet.specie, "\n")] = 0;

    printf(" Idade: ");
    scanf("%d", &newPet.age);

    printf(" Data de nascimento (DD MM AAAA): ");
    scanf("%d %d %d", &newPet.birthDate.day, &newPet.birthDate.month, &newPet.birthDate.year);

    do {
        printf(" Prioridade (0 = EMERGÊNCIA | 1 = NORMAL): ");
        scanf("%d", &newPet.priority);

        if(newPet.priority != 0 && newPet.priority != 1) {
            printf("\n A classificação de prioridade inserida é inválida!\n\n");
        }
    } while(newPet.priority != 0 && newPet.priority != 1);

    system("cls");

    companyShowcase();

    printf("\n Ao término do preenchimento dos dados solicitados, confirme o cadastro do seguinte animal na fila de atendimento:");

    printf("\n\n º ID (automático): %d;", newPet.id);
    printf("\n º Nome: %s;", newPet.name);
    printf("\n º Espécie: %s;", newPet.specie);
    printf("\n º Idade: %02d;", newPet.age);
    printf("\n º Data de nascimento (DD MM AAAA): %02d/%02d/%02d;", newPet.birthDate.day, newPet.birthDate.month, newPet.birthDate.year);
    printf("\n º Prioridade (0 = EMERGÊNCIA | 1 = NORMAL): %d;", newPet.priority);

    printf("\n\n Deseja confirmar a inclusão do animal cujos dados estão listados acima? [S/n]: ");

    do {
        fflush(stdin);
        inclusion_confirmation = getchar();
    } while((toupper(inclusion_confirmation) != 'S') && (tolower(inclusion_confirmation) != 'n'));

    if(toupper(inclusion_confirmation) == 'S') {
        if(newPet.priority == 0) {
            insertIntoQueue(emergency, newPet);
            printf("\n * Animal classificado como \"EMERGÊNCIA\" na prioridade.");
        } else {
            insertIntoQueue(normal, newPet);
            printf("\n * Animal classificado como \"NORMAL\" na prioridade.");
        }
        printf("\n\n O animal foi inserido/cadastrado na fila de atendimento com sucesso!\n");
    } else {
        printf("\n A inclusão do animal na fila de atendimento foi cancelada!\n");
    }

    printf("\n");
    sleep(1);
    system("pause");
}

void attendPet(Queue* emergency, Queue* normal, Queue* attended) {
    system("cls");

    companyShowcase();

    printf("\n Abaixo, verificaremos se há algum animal, primeiramente, na fila de EMERGÊNCIA e o atenderemos.\n Caso contrário, o próximo animal a ser atendido será o primeiro animal da prioridade NORMAL.\n");

    PetInfo attendedPet;

    if (!isQueueEmpty(emergency)) {
        attendedPet = removeFromQueue(emergency);

        printf("\n Dados do animal em atendimento prioritário, devido à sua posição na fila de atendimento de emergência:");

        printf("\n\n º ID: %d;", attendedPet.id);
        printf("\n º Nome: %s;", attendedPet.name);
        printf("\n º Espécie: %s;", attendedPet.specie);
        printf("\n º Idade: %02d;", attendedPet.age);
        printf("\n º Data de nascimento (DD MM AAAA): %02d/%02d/%02d;", attendedPet.birthDate.day, attendedPet.birthDate.month, attendedPet.birthDate.year);

        printf("\n\n * OBS: Tipo de atendimento (prioridade): EMERGÊNCIA\n", attendedPet.priority);
    } else if (!isQueueEmpty(normal)) {
        attendedPet = removeFromQueue(normal);

        printf("\n\n Dados do animal em atendimento, devido à sua posição na fila de atendimento normal:");

        printf("\n\n º ID: %d;", attendedPet.id);
        printf("\n º Nome: %s;", attendedPet.name);
        printf("\n º Espécie: %s;", attendedPet.specie);
        printf("\n º Idade: %02d;", attendedPet.age);
        printf("\n º Data de nascimento (DD MM AAAA): %02d/%02d/%02d;", attendedPet.birthDate.day, attendedPet.birthDate.month, attendedPet.birthDate.year);

        printf("\n\n * OBS: Tipo de atendimento (prioridade): NORMAL;\n", attendedPet.priority);
    } else {
        printf("\n Ótima notícia! Não há animais aguardando atendimento nas filas...\n\n");

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

        printf("\n Neste painel, é possível buscar por animais nas filas de atendimento através de ID ou nome.");

        printf("\n\n Para tal, selecione, abaixo, a opção desejada para buscar por um animal:");
        printf("\n º Opção 1: ID;");
        printf("\n º Opção 2: Nome;");

        printf("\n\n º Opção 0: Voltar (menu inicial);");

        printf("\n\n Opção: ");
        scanf("%d", &selected_option);

        system("cls");

        companyShowcase();

        switch (selected_option) {
            case 1: {
                printf("\n Para buscar por algum animal registrado nas filas de atendimento, siga a instrução abaixo.");

                printf("\n\n Informe o ID do animal: ");
                scanf("%d", &id);

                PetInfo* pet = NULL;

                pet = searchById(emergency, id, 0);
                if (!pet) pet = searchById(normal, id, 0);

                if (!pet) pet = searchById(attended, id, 1);

                if (!pet) {
                    printf("\n Não foi possível encontrar nenhum animal com o ID \"%d\" nas filas de atendimento.\n", id);
                }

                printf("\n");
                system("pause");
                break;
            }
            case 2: {
                printf("\n Para buscar por algum animal registrado nas filas de atendimento, siga a instrução abaixo.");
                printf("\n * OBS: Caso seja encontrado mais de um animal com o mesmo nome, todos serão exibidos...");

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
                printf("\n Opção inválida! Tente novamente...\n");

                sleep(1);
                break;
        }
    } while (selected_option != 0);
}

void printAllQueues(Queue* emergency, Queue* normal) {
    system("cls");

    companyShowcase();

    printf("\n Abaixo, estão listadas os animais cadastrados nas filas de atendimento EMERGÊNCIA e NORMAL.");

    printf("\n\n --- EMERGÊNCIA ---\n");
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

    printf("\n Abaixo é exibido o próximo animal aguardando atendimento registrado nas filas do sistema (emergência ou normal).");

    PetInfo* pet = getNextPet(emergency, normal);

    if(pet) {
        printf("\n\n Próximo animal (aguardando atendimento):"),
        printf("\n  º Nome: %s;", pet -> name);
        printf("\n  º Espécie: %s;", pet -> specie);
        printf("\n  º Tipo de atendimento (prioridade): %s;", pet -> priority == 0 ? "Emergência (0)" : "Normal (1)\n");
    } else {
        printf("\n\n Ótima notícia! Não há animais aguardando atendimento nas filas...\n");
    }

    printf("\n");
    sleep(1);
    system("pause");
}

void printAttendedPets(Queue* attended) {
    system("cls");

    companyShowcase();

    printf("\n Abaixo, serão exibidos todos os animais que já receberam atendimento (organizados na fila de animais atendidos).");

    Node* p;

    printf("\n\n ID | Nome | Espécie | Idade | Prioridade");
    printf("\n ------------------------------------------");

    for (p = attended -> beginning; p != NULL; p = p -> next) {
        printf("\n %d | %s | %s | %02d | %s",
               p -> petInfo.id,
               p -> petInfo.name,
               p -> petInfo.specie,
               p -> petInfo.age,
               (p -> petInfo.priority == 0 ? "Emergência" : "Normal"));
    }

    if (isQueueEmpty(attended)) {
        printf("\n\n A fila de animais atendidos está vazia! Que tal iniciar alguns atendimentos?\n");
    }

    printf("\n\n");
    sleep(1);
    system("pause");
}
