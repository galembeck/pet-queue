#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

// Constantes (numéricas) de variáveis alfanuméricas:
#define max_name_char 50 // Máximo de caracteres para "name" (nome do animal)
#define max_specie_char 30 // Máximo de caracteres para "specie" (espécie do animal)


/*
    ÍNDICE (CONTEÚDO) DO ARQUIVO:

    CONSTANTES:
        • max_name_char - constante com o número máximo de caracteres alfanuméricos para "name" (nome do animal);
        • max_specie_char - constante com o número máximo de caracteres alfanuméricos para "specie" (espécie do animal);

    ESTRUTURAS:
        - Animal/Pet:
            • Date - estrutura contendo as informações de nascimento do animal (dia, mês e ano);
            • PetInfo - estrutura contendo as informações/dados do animal;

        - Fila(s):
            • Node - estrutura contendo os dados do animal e referenciamento ao próximo item (animal) da fila;
            • Queue - estrutura contendo o INÍCIO e o FIM da fila, para questões de referenciamento;

    FUNÇÕES:
        - Manipulação:
            • createQueue() - função de criação da fila (básica/limpa);
            • isQueueEmpty(Queue* q) - função de verificação do conteúdo da fila (1 - VAZIA | 0 - C/ CONTEÚDO);
            • insertIntoQueue(Queue* q, PetInfo pet) - função de inserção de elementos/conteúdo (animais) na fila;
            • removeFromQueue(Queue* q) - função de remoção de elementos/conteúdo (animais) da fila;

        - Busca & Impressão:
            • printQueue(Queue* q) - função de impressão dos elementos/conteúdo (animais) da fila;
            • searchById(Queue* q, int id) - função de busca de elemento (animal) por "ID";
            • searchByName(Queue* q, char *name) - função de busca de elemento (animal) por "nome";
            • getNextPet(Queue* emergency, Queue* normal) - função de busca pelo próximo elemento (animal) a ser atendido em ambas as filas de atendimento;

        - Utilitárias:
            • freeQueue(Queue* q) - função de exclusão da fila (e seu conteúdo), liberando o espaço de memória ocupado/alocado anteriormente;
*/



// Estrutura "date" contendo dia, mês e ano de nascimento do animal
typedef struct date {
    int day, month, year;
} Date;

// Estrutura "petInfo" contendo todas as informações/dados necessários no preenchimento para cadastro do atendimento do animal
typedef struct petInfo {
    int id; // Número de identificação (ID) aleatório gerado pelo sistema - não é necessário o preenchimento pelo usuário
    char name[max_name_char]; // Nome (alfanumérico com no máximo 50 caracteres)
    char specie[max_specie_char]; // Espécie (alfanumérico com no máximo 30 caracteres)
    int age; // Idade
    Date birthDate; // Data de nascimento (estrutura contendo: dia, mês e ano)
    int priority; // Prioridade de atendimento: 0 - emergência | 1 - normal)
} PetInfo;



// Definição do "NÓ" ("node") como estrutura que contém as informações dos animais
typedef struct node {
    PetInfo petInfo;

    struct node *next;
} Node;

// Definição do funcionamento/estrutura da "FILA" ("queue")
typedef struct queue {
    Node* beginning;
    Node* ending;
} Queue;



// FUNÇÕES DE MANIPULAÇÃO DA FILA:

// Função de criação da fila (básica)
Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));

    q -> beginning = q -> ending = NULL;

    return q;
}

// Função de verificação de conteúdo da fila (1 - VAZIA | 0 - C/ CONTEÚDO)
int isQueueEmpty(Queue* q) {
    if (q -> beginning == NULL) return 1;
    return 0;
}

// Função de adição de novos animais (conteúdo) na fila
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

// Função de remoção de animal (conteúdo) da fila
PetInfo removeFromQueue(Queue* q) {
    if (isQueueEmpty(q)) {
        printf("\n A fila em questão está vazia! Tente buscar por outra fila...\n");

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



// FUNÇÕES DE IMPRESSÃO & BUSCA:

// Função de impressão do conteúdo da fila
void printQueue(Queue* q) {
    Node* p;

    printf("\n ID | Nome | Espécie | Idade | Data de Nascimento | Prioridade\n");
    printf("-----------------------------------------------------------------");

    if (isQueueEmpty(q)) {
        printf("\n\n A fila de atendimento está vazia, ou seja, não há nenhum animal registrado!");
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
               (p -> petInfo.priority == 0 ? "Emergência" : "Normal"));
    }
}

// Função de busca de animal (conteúdo) na fila por "ID"
PetInfo* searchById(Queue* q, int id, int alreadyAttended) {
    Node* p;

    for (p = q->beginning; p != NULL; p = p->next) {
        if (p->petInfo.id == id) {
            printf("\n Animal encontrado:");
            printf("\n  º ID: %d", p -> petInfo.id);
            printf("\n  º Nome: %s", p -> petInfo.name);
            printf("\n  º Espécie: %s", p -> petInfo.specie);
            printf("\n  º Tipo de atendimento (prioridade): %s;",
                   p -> petInfo.priority == 0 ? "Emergência (0)" : "Normal (1)");

            if (alreadyAttended) {
                printf("\n  º Atendimento: realizado;\n");
            } else {
                printf("\n  º Atendimento: aguardando (pendente);\n");
            }

            return &(p->petInfo);
        }
    }

    return NULL;
}

// Função de busca de animal (conteúdo) na fila por "nome"
int searchByName(Queue* q, char *name, int alreadyAttended) {
    Node* p;

    int found = 0;

    for (p = q->beginning; p != NULL; p = p->next) {
        if (strcmp(p->petInfo.name, name) == 0) {
            printf("\n Animal encontrado:");
            printf("\n  º ID: %d;", p -> petInfo.id);
            printf("\n  º Nome: %s;", p -> petInfo.name);
            printf("\n  º Espécie: %s;", p -> petInfo.specie);
            printf("\n  º Tipo de atendimento (prioridade): %s;",
                   p -> petInfo.priority == 0 ? "Emergência (0)" : "Normal (1)");

            if (alreadyAttended) {
                printf("\n  º Atendimento: realizado;\n");
            } else {
                printf("\n  º Atendimento: aguardando (pendente);\n");
            }

            found++;
        }
    }

    return found;
}

// Função de busca pelo próximo animal (conteúdo) na fila
PetInfo* getNextPet(Queue* emergency, Queue* normal) {
    if (!isQueueEmpty(emergency)) {
        return &(emergency -> beginning -> petInfo);
    }

    if (!isQueueEmpty(normal)) {
        return &(normal -> beginning -> petInfo);
    }

    return NULL;
}



// FUNÇÕES UTILITÁRIAS

// Função de exclusão da fila da memóra (liberação de espaço na memória)
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
