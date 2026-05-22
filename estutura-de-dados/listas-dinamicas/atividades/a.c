#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct nomes_node {
  char nome[50];
  struct nomes_node *next;
} nomes_node;

typedef struct nomes {
  nomes_node *inicio;
  nomes_node *fim;
  size_t size; 
} nomes;

void iniciar_lista(nomes **l) {
  (*l) = malloc(sizeof(nomes));
  (*l)->inicio = NULL;
  (*l)->fim = NULL;
  (*l)->size = 0;
}

static nomes_node *criar_novo_node(char *nome) {
  nomes_node *novo_node = malloc(sizeof(nomes_node));
  strncpy(novo_node->nome, nome, 49);
  novo_node->nome[49] = '\0';
  novo_node->next = NULL;
  return novo_node;
}

static void deleta_node(nomes_node *n) {
  free(n);
}

void nomes_insere(nomes *l, char *nome) {
  nomes_node *novo_node = criar_novo_node(nome);
  if (l->size == 0) {
    l->inicio = novo_node;
    l->fim = novo_node;
    l->fim->next = l->inicio;
  } else if (l->size == 1) {
    l->inicio->next = novo_node;
    l->fim = novo_node;
    l->fim->next = l->inicio;
  } else {
    l->fim->next = novo_node;
    l->fim = novo_node;
    l->fim->next = l->inicio;
  }
  l->size++;
}

void nomes_remove(nomes *l, int x) {
  assert(l->size > 0);

  nomes_node *atual = l->inicio;
  nomes_node *anterior = l->fim;

  // andar até a posição x
  x = x % l->size;
  for (int i = 0; i < x; i++) {
    anterior = atual;
    atual = atual->next;
  }

  // caso: único elemento
  if (l->size == 1) {
    l->inicio = NULL;
    l->fim = NULL;
  } else {
    anterior->next = atual->next;

    if (atual == l->inicio)
      l->inicio = atual->next;

    if (atual == l->fim)
      l->fim = anterior;
  }

  deleta_node(atual);
  l->size--;
}

void mostra_nome(nomes *l) {
  assert(!(l->size == 0));
  printf("%s", l->inicio->nome);
}

void limpa(nomes **l) {
  while ((*l)->size != 0) {
    nomes_remove((*l), 0);
  }
  free(*l);
  *l = NULL;
}

int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  getchar();
  nomes *l;
  iniciar_lista(&l);
  for (int i = 0; i < n; i++) {
    char nome[50];
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';
    nomes_insere(l, nome);
  }
  int pos = 0;
  while (l->size > 1) {
    pos = (pos + x - 1) % l->size;
    nomes_remove(l, pos);
  }
  mostra_nome(l);
  limpa(&l);
  return 0;
}
