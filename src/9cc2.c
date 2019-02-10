#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  TK_NUM = 256,
  TK_EOF,
};

typedef struct {
  int ty;
  int val;
  char input;
} Token;

typedef struct cell {
  Token *head;
  struct cell *tail;
} Cell;

typedef struct {
  Cell *first;
} List;

Cell* make_cell(Token *head, Cell *tail) {
  Cell *new_cell = malloc(sizeof(Cell));
  new_cell->head = head;
  new_cell->tail = tail;
  return new_cell;
}

Cell* nth_cell(Cell *cell, int n) {
  for (int i = 0; cell != NULL; i++, cell = cell->tail) {
    if (i == n) break;
  }
  return cell;
}

Token* nth_token(List *list, int n) {
  if (list == NULL || list->first == NULL) {
    printf("要素の取り出しに失敗しました\n");
    exit(1);
  }
  return nth_cell(list->first, n)->head;
}

Cell* last_cell(Cell *cell) {
  if (cell == NULL) {
    printf("セルの取り出しに失敗しました\n");
    exit(1);
  }
  while (cell->tail != NULL) cell = cell->tail;
  return cell;
}

List* make_list(Cell *cell) {
  List *list = malloc(sizeof(List));
  list->first = cell;
  return list;
}

void push_token(List *list, Token *token) {
  if (list == NULL) {
    printf("要素の追加に失敗しました\n");
    exit(1);
  }

  if (list->first == NULL) {
    list->first = make_cell(token, NULL);
    return;
  }

  Cell *last = last_cell(list->first);
  last->tail = make_cell(token, NULL);
}

List* tokenize(char *p) {
  List *result = make_list(NULL);
  int i = 0;
  while (*p) {
    if (isspace(*p)) {
      p++;
      continue;
    }

    if (*p == '+' || *p == '-') {
      Token *token = malloc(sizeof(Token));
      token->ty = *p;
      token->input = *p;
      push_token(result, token);
      i++;
      p++;
      continue;
    }

    if (isdigit(*p)) {
      Token *token = malloc(sizeof(Token));
      token->ty = TK_NUM;
      token->input = *p;
      token->val = strtol(p, &p, 10);
      push_token(result, token);
      i++;
      continue;
    }

    fprintf(stderr, "トークナイズできません: %s\n", p);
    exit(1);
  }

  Token *eof = malloc(sizeof(Token));
  eof->ty = TK_EOF;
  eof->input = *p;
  push_token(result, eof);
  return result;
}

void error(List *list, int i) {
  fprintf(stderr, "予期しないトークンです: %s\n", nth_token(list, i)->input);
  exit(1);
}

int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "引数の個数が正しくありません\n");
    return 1;
  }

  List *tokens = tokenize(argv[1]);

  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");

  if (nth_token(tokens, 0)->ty != TK_NUM) error(tokens, 0);
  printf("  mov rax, %d\n", nth_token(tokens, 0)->val);

  int i = 1;
  while (nth_token(tokens, i)->ty != TK_EOF) {
    switch (nth_token(tokens, i)->ty) {
      case '+': {
        i++;
        Token *token = nth_token(tokens, i);
        if (token->ty != TK_NUM) error(tokens, i);
        printf("  add rax, %d\n", token->val);
        i++;
        continue;
      }

      case '-': {
        i++;
        Token *token = nth_token(tokens, i);
        if (token->ty != TK_NUM) error(tokens, i);
        printf("  sub rax, %d\n", token->val);
        i++;
        continue;
      }

      default:
        error(tokens, i);
    }
  }

  printf("  ret\n");
  return 0;
}
