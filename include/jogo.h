#ifndef JOGO_H
#define JOGO_H

#include <stdbool.h>

#define MAX_ESCOLHAS        4
#define MAX_TEXTO          600
#define MAX_TEXTO_ESCOLHA  200
#define LIMIAR_BONDADE      50   /* pontosBondade minimo para o Heroi poupar a vila */
#define LIMIAR_CONFIANCA    60   /* confiancaDragao minima para a alianca acontecer */

typedef enum {
    FINAL_EM_ABERTO = 0,
    FINAL_MORTE_PELO_HEROI,
    FINAL_PERDOADA_PELO_HEROI,
    FINAL_ALIADA_DO_DRAGAO,
    FINAL_MORTE_PELO_DRAGAO
} FinalJogo;

typedef struct {
    char nome[50];
    int  pontosBondade;     /* varia de -100 a 100 */
    int  confiancaDragao;   /* varia de 0 a 100 */
    bool dragaoAliado;
    int  noAtual;
    FinalJogo final;
} Jogador;

typedef struct {
    char texto[MAX_TEXTO_ESCOLHA];
    int  proximoNo;
    int  deltaBondade;
    int  deltaConfiancaDragao;
} Escolha;

typedef struct {
    int     id;
    char    textoNarrativo[MAX_TEXTO];
    int     totalEscolhas;
    Escolha escolhas[MAX_ESCOLHAS];
} NoHistoria;

/* Inicializa o estado do jogador no comeco da partida. */
void inicializarJogador(Jogador *jogador, const char *nome);

/* Aplica os efeitos de uma escolha ao estado do jogador
   (pontos de bondade, confianca do dragao e alianca). */
void aplicarEscolha(Jogador *jogador, const Escolha *escolha);

/* Calcula o final da partida a partir do estado acumulado do jogador. */
FinalJogo calcularFinal(const Jogador *jogador);

/* Retorna o texto de encerramento correspondente a um final. */
const char *textoFinal(FinalJogo final);

#endif /* JOGO_H */
