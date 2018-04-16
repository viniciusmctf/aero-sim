#ifndef AVIAO_H
#define AVIAO_H

#include <pthread.h>

typedef struct {
  pthread_t thread;
  size_t combustivel;
} aviao_t;

// Estas funcoes devem cuidar da alocacao dinâmica de memória
aviao_t * aloca_aviao (pthread_t t, size_t p);
void desaloca_aviao (aviao_t* aviao);

#endif
