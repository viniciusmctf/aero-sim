#include <pthread.h>
#include <semaphore.h>

typedef aviao_t pthread_t
typedef esteira_t pthread_t
typedef tempo_t size_t

typedef struct {
	pthread_mutex_t* pistas_livres;
	pthread_mutex_t* portoes_livres;
	sem_t* esteiras_livres;
	esteira_t* esteiras;
	tempo_t t_pouso_decolagem;
	tempo_t t_remover_bagagens;
	tempo_t t_inserir_bagagens;
	tempo_t t_bagagens_esteira;
} aeroporto_t;


/**
 * Esta função deve fazer a alocação dinâmica de um aeroporto (malloc)
 * e atribuir os parâmetros (recebidos por um array de unsigned ints)
 * aos atributos da struct aeroporto
 **/
aeroporto_t* iniciar_aeroporto (size_t* args, size_t n_args);

/**
 * Esta função deve ser chamada quando um novo avião se aproxima
 * do aeroporto. Nesta situação um avião deve pousar em seguida,
 * mas somente se houver uma pista livre para ele.
 **/
void aproximacao_aeroporto (aeroporto_t*, aviao_t*);

/**
 * Esta função deve fazer com que o aviao pouse, utilizando uma pista livre.
 * Ela não pode ser chamada se não houver pistas livres. Em seguida o avião 
 * deve se acoplar a um portão, caso haja um livre, se não houver, ele deve
 * esperar.
 **/
void pousar_aviao (aeroporto_t*, aviao_t*);

/**
 * Esta função deve acoplar um avião a um portão de embarque livre.
 * Ela não deve ser chamada caso não hajam portões livres. Em seguida, o
 * o avião deve transportar suas bagagens para fora e receber novas bagagens.
 * Um avião não pode decolar sem receber novas bagagens.
 **/
void acoplar_portao (aeroporto_t*, aviao_t*);

/**
 * Esta função deve levar as bagagens de um avião para uma esteira e
 * colocar novas bagagens num avião para que ele seja liberado para
 * decolagem. Um avião não pode decolar sem receber novas bagagens.
 * Um avião não pode receber novas bagagens sem colocar as antigas
 * em uma esteira.
 **/
void transportar_bagagens (aeroporto_t*, aviao_t*);

/**
 * Esta função deve colocar novas bagagens numa esteira, caso ela
 * esteja disponível. A esteira ficará ocupada enquanto houverem
 * bagagens nela.
 **/
void adicionar_bagagens_esteira (aeroporto_t*, aviao_t*);

/**
 * Esta função deve fazer com que um avião decole, caso haja
 * uma pista disponível para tal. Um avião que decolar deve
 * ter sua execução terminada.
 **/
void decolar_aviao(aeroporto_t*, aviao_t*);

/**
 * Esta função deve desalocar todos os recursos previamente 
 * alocados pelo aeroporto.
 **/
int finalizar_aeroporto (aeroporto_t*);