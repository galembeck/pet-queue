#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

// Constantes (num�ricas) de vari�veis alfanum�ricas:
#define max_name_char 50 // M�ximo de caracteres para "name" (nome do animal)
#define max_specie_char 30 // M�ximo de caracteres para "specie" (esp�cie do animal)


/*
    �NDICE (CONTE�DO) DO ARQUIVO:

    CONSTANTES:
        � max_name_char - constante com o n�mero m�ximo de caracteres alfanum�ricos para "name" (nome do animal);
        � max_specie_char - constante com o n�mero m�ximo de caracteres alfanum�ricos para "specie" (esp�cie do animal);

    ESTRUTURAS:
        - Animal/Pet:
            � Date - estrutura contendo as informa��es de nascimento do animal (dia, m�s e ano);
            � PetInfo - estrutura contendo as informa��es/dados do animal;

        - Fila(s):
            � Node - estrutura contendo os dados do animal e referenciamento ao pr�ximo item (animal) da fila;
            � Queue - estrutura contendo o IN�CIO e o FIM da fila, para quest�es de referenciamento;

    FUN��ES:
        - Manipula��o:
            � createQueue() - fun��o de cria��o da fila (b�sica/limpa);
            � isQueueEmpty(Queue* q) - fun��o de verifica��o do conte�do da fila (1 - VAZIA | 0 - C/ CONTE�DO);
            � insertIntoQueue(Queue* q, PetInfo pet) - fun��o de inser��o de elementos/conte�do (animais) na fila;
            � removeFromQueue(Queue* q) - fun��o de remo��o de elementos/conte�do (animais) da fila;

        - Busca & Impress�o:
            � printQueue(Queue* q) - fun��o de impress�o dos elementos/conte�do (animais) da fila;
            � searchById(Queue* q, int id) - fun��o de busca de elemento (animal) por "ID";
            � searchByName(Queue* q, char *name) - fun��o de busca de elemento (animal) por "nome";
            � getNextPet(Queue* emergency, Queue* normal) - fun��o de busca pelo pr�ximo elemento (animal) a ser atendido em ambas as filas de atendimento;

        - Utilit�rias:
            � freeQueue(Queue* q) - fun��o de exclus�o da fila (e seu conte�do), liberando o espa�o de mem�ria ocupado/alocado anteriormente;
*/



// Estrutura "date" contendo dia, m�s e ano de nascimento do animal
typedef struct date {
    int day, month, year;
} Date;

// Estrutura "petInfo" contendo todas as informa��es/dados necess�rios no preenchimento para cadastro do atendimento do animal
typedef struct petInfo {
    int id; // N�mero de identifica��o (ID) aleat�rio gerado pelo sistema - n�o � necess�rio o preenchimento pelo usu�rio
    char name[max_name_char]; // Nome (alfanum�rico com no m�ximo 50 caracteres)
    char specie[max_specie_char]; // Esp�cie (alfanum�rico com no m�ximo 30 caracteres)
    int age; // Idade
    Date birthDate; // Data de nascimento (estrutura contendo: dia, m�s e ano)
    int priority; // Prioridade de atendimento: 0 - emerg�ncia | 1 - normal)
} PetInfo;



// Defini��o do "N�" ("node") como estrutura que cont�m as informa��es dos animais
typedef struct node {
    PetInfo petInfo;

    struct node *next;
} Node;

// Defini��o do funcionamento/estrutura da "FILA" ("queue")
typedef struct queue {
    Node* beginning;
    Node* ending;
} Queue;



// FUN��ES DE MANIPULA��O DA FILA:

// Fun��o de cria��o da fila (b�sica)
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));

    q -> beginning = q -> ending = NULL;

    return q;
}

// Fun��o de verifica��o de conte�do da fila (1 - VAZIA | 0 - C/ CONTE�DO)
int isQueueEmpty(Queue* q) {
    if (q -> beginning == NULL) return 1;
    return 0;
}

// Fun��o de adi��o de novos animais (conte�do) na fila
void insertIntoQueue(Queue* q, PetInfo pet) {
    Node* new_node = (Node*) malloc(sizeof(Node));

    new_node -> petInfo = pet;
    new_node -> next = NULL;

    if (q -> ending != NULL) {
        q -> ending -> next = new_node;
    } else {
        q -> beginning = new_node;
    }

    q -> ending = new_node;
}

// Fun��o de remo��o de animal (conte�do) da fila
PetInfo removeFromQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("\n A fila em quest�o est� vazia! Tente buscar por outra fila...\n");

        exit(1);
    }

    Node* aux_node = q -> beginning;

    PetInfo removed_pet = aux_node -> petInfo;

    q -> beginning = q -> beginning -> next;

    if (q -> beginning == NULL) {
        q -> ending = NULL;
    }

    free(aux_node);

    return removed_pet;
}



// FUN��ES DE IMPRESS�O & BUSCA:

// Fun��o de impress�o do conte�do da fila
void printQueue(Queue* q) {
    Node* p;

    printf("\n ID | Nome | Esp�cie | Idade | Data de Nascimento | Prioridade\n");
    printf("-----------------------------------------------------------------");

    if (isQueueEmpty(q)) {
        printf("\n\n A fila de atendimento est� vazia, ou seja, n�o h� nenhum animal registrado!");
    }

    for (p = q -> beginning; p != NULL; p = p -> next) {
        printf("\n %d | %s | %s | %02d | %02d/%02d/%04d | %s",
               p -> petInfo.id,
               p -> petInfo.name,
               p -> petInfo.specie,
               p -> petInfo.age,
               p -> petInfo.birthDate.day,
               p -> petInfo.birthDate.month,
               p -> petInfo.birthDate.year,
               (p -> petInfo.priority == 0 ? "Emerg�ncia" : "Normal"));
    }
}

// Fun��o de busca de animal (conte�do) na fila por "ID"
PetInfo* searchById(Queue* q, int id, int alreadyAttended) {
    Node* p;

    for (p = q->beginning; p != NULL; p = p->next) {
        if (p->petInfo.id == id) {
            printf("\n Animal encontrado:");
            printf("\n  � ID: %d", p -> petInfo.id);
            printf("\n  � Nome: %s", p -> petInfo.name);
            printf("\n  � Esp�cie: %s", p -> petInfo.specie);
            printf("\n  � Tipo de atendimento (prioridade): %s;",
                   p -> petInfo.priority == 0 ? "Emerg�ncia (0)" : "Normal (1)");

            if (alreadyAttended) {
                printf("\n  � Atendimento: realizado;\n");
            } else {
                printf("\n  � Atendimento: aguardando (pendente);\n");
            }

            return &(p->petInfo);
        }
    }

    return NULL;
}

// Fun��o de busca de animal (conte�do) na fila por "nome"
int searchByName(Queue* q, char *name, int alreadyAttended) {
    Node* p;

    int found = 0;

    for (p = q->beginning; p != NULL; p = p->next) {
        if (strcmp(p->petInfo.name, name) == 0) {
            printf("\n Animal encontrado:");
            printf("\n  � ID: %d;", p -> petInfo.id);
            printf("\n  � Nome: %s;", p -> petInfo.name);
            printf("\n  � Esp�cie: %s;", p -> petInfo.specie);
            printf("\n  � Tipo de atendimento (prioridade): %s;",
                   p -> petInfo.priority == 0 ? "Emerg�ncia (0)" : "Normal (1)");

            if (alreadyAttended) {
                printf("\n  � Atendimento: realizado;\n");
            } else {
                printf("\n  � Atendimento: aguardando (pendente);\n");
            }

            found++;
        }
    }

    return found;
}

// Fun��o de busca pelo pr�ximo animal (conte�do) na fila
PetInfo* getNextPet(Queue* emergency, Queue* normal) {
    if (!isQueueEmpty(emergency)) {
        return &(emergency -> beginning -> petInfo);
    }

    if (!isQueueEmpty(normal)) {
        return &(normal -> beginning -> petInfo);
    }

    return NULL;
}



// FUN��ES UTILIT�RIAS

// Fun��o de exclus�o da fila da mem�ra (libera��o de espa�o na mem�ria)
Queue* freeQueue(Queue* q) {
    Node* p = q -> beginning;

    while (p != NULL) {
        Node* aux_node = p -> next;

        free(p);

        p = aux_node;
    }

    free(q);

    return NULL;
}

#endif // QUEUE_H_INCLUDED
