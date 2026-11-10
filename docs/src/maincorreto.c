#include <stdio.h>
#include <string.h>
#include "jogo.h"

void inicializarJogador(Jogador *jogador, const char *nome) {
    strncpy(jogador->nome, nome, sizeof(jogador->nome) - 1);
    jogador->nome[sizeof(jogador->nome) - 1] = '\0';
    jogador->pontosBondade = 0;
    jogador->confiancaDragao = 0;
    jogador->dragaoAliado = false;
    jogador->noAtual = 0;
    jogador->final = FINAL_EM_ABERTO;
}

void aplicarEscolha(Jogador *jogador, const Escolha *escolha) {
    jogador->pontosBondade += escolha->deltaBondade;
    if (jogador->pontosBondade > 100)  jogador->pontosBondade = 100;
    if (jogador->pontosBondade < -100) jogador->pontosBondade = -100;

    jogador->confiancaDragao += escolha->deltaConfiancaDragao;
    if (jogador->confiancaDragao > 100) jogador->confiancaDragao = 100;
    if (jogador->confiancaDragao < 0)   jogador->confiancaDragao = 0;

    if (jogador->confiancaDragao >= LIMIAR_CONFIANCA) {
        jogador->dragaoAliado = true;
    }

    jogador->noAtual = escolha->proximoNo;
}

FinalJogo calcularFinal(const Jogador *jogador) {
    if (jogador->pontosBondade >= LIMIAR_BONDADE || jogador->dragaoAliado) {
        return jogador->dragaoAliado ? FINAL_ALIADA_DO_DRAGAO : FINAL_PERDOADA_PELO_HEROI;
    }
    return FINAL_MORTE_PELO_HEROI;
}

const char *textoFinal(FinalJogo final) {
    switch (final) {
        case FINAL_MORTE_PELO_HEROI:
            return "O Heroi nao viu bondade suficiente em voce. FIM (derrota).";
        case FINAL_PERDOADA_PELO_HEROI:
            return "Seus atos de bondade convenceram o Heroi a poupa-la. FIM (vitoria).";
        case FINAL_ALIADA_DO_DRAGAO:
            return "O Dragao luta ao seu lado contra o Heroi. FIM (vitoria).";
        case FINAL_MORTE_PELO_DRAGAO:
            return "O Dragao nao confiou em voce e venceu o confronto. FIM (derrota).";
        default:
            return "Fim em aberto.";
    }
}

/* Monta os nos de exemplo usados nesta entrega. O conteudo completo de cada
   capitulo (varios nos, mais ramificacoes) sera escrito no 2o bimestre;
   aqui o objetivo e provar que a estrutura de dados e o loop funcionam. */
static void montarNosDemo(NoHistoria nos[3]) {
    nos[0].id = 0;
    strcpy(nos[0].textoNarrativo,
        "Capitulo 1: voce acorda no corpo da 'vila' da historia, em pleno "
        "mercado do reino. Um aldeao a reconhece.");
    nos[0].totalEscolhas = 2;
    strcpy(nos[0].escolhas[0].texto,
        "1. Poupar o aldeao, mesmo sabendo que ele pode denuncia-la");
    nos[0].escolhas[0].proximoNo = 1;
    nos[0].escolhas[0].deltaBondade = 10;
    nos[0].escolhas[0].deltaConfiancaDragao = 0;
    strcpy(nos[0].escolhas[1].texto,
        "2. Usar o medo do aldeao a seu favor");
    nos[0].escolhas[1].proximoNo = 1;
    nos[0].escolhas[1].deltaBondade = -10;
    nos[0].escolhas[1].deltaConfiancaDragao = 0;

    nos[1].id = 1;
    strcpy(nos[1].textoNarrativo,
        "Capitulo 2: um dragao ferido bloqueia seu caminho na floresta.");
    nos[1].totalEscolhas = 2;
    strcpy(nos[1].escolhas[0].texto,
        "1. Aproximar-se com calma e tentar cuidar do dragao");
    nos[1].escolhas[0].proximoNo = 2;
    nos[1].escolhas[0].deltaBondade = 5;
    nos[1].escolhas[0].deltaConfiancaDragao = 40;
    strcpy(nos[1].escolhas[1].texto,
        "2. Provocar o dragao para testar sua forca");
    nos[1].escolhas[1].proximoNo = 2;
    nos[1].escolhas[1].deltaBondade = -5;
    nos[1].escolhas[1].deltaConfiancaDragao = -20;

    /* No terminal (sem escolhas) desta versao de demonstracao: dispara o
       calculo do final assim que e alcancado. */
    nos[2].id = 2;
    strcpy(nos[2].textoNarrativo,
        "Capitulo 3: o Heroi finalmente a encontra, frente a frente.");
    nos[2].totalEscolhas = 0;
}

int main(void) {
int i;
int escolha;
    NoHistoria nos[3];
    montarNosDemo(nos);

    Jogador jogador;
    char nome[50];

    printf("Nome da sua personagem: ");
    if (!fgets(nome, sizeof(nome), stdin)) {
        return 1;
    }
    nome[strcspn(nome, "\n")] = '\0';
    inicializarJogador(&jogador, nome);

    while (jogador.final == FINAL_EM_ABERTO) {
        NoHistoria *no = &nos[jogador.noAtual];
        printf("\n%s\n", no->textoNarrativo);

        if (no->totalEscolhas == 0) {
            jogador.final = calcularFinal(&jogador);
            printf("\n%s\n", textoFinal(jogador.final));
            break;
        }
		
        for ( i=0; i < no->totalEscolhas; i++) {
            printf("%s\n", no->escolhas[i].texto);
        }

        int escolha = -1;
        printf("Escolha uma opcao: ");
        if (scanf("%d", &escolha) != 1) {
            return 1;
        }
        while (getchar() != '\n') { /* limpa o buffer de entrada */ }

        if (escolha < 1 || escolha > no->totalEscolhas) {
            printf("Opcao invalida, tente novamente.\n");
            continue;
        }

        aplicarEscolha(&jogador, &no->escolhas[escolha - 1]);
    }

    return 0;
}
