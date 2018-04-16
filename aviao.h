#ifndef AVIAO_H
#define AVIAO_H

#include <pthread.h>

typedef struct {
  pthread_t thread;
  size_t combustivel;
  size_t id;
} aviao_t;

// Estas funcoes devem cuidar da alocacao dinâmica de memória
aviao_t * aloca_aviao (pthread_t thread, size_t combustivel, size_t id);
void desaloca_aviao (aviao_t* aviao);

#endif
