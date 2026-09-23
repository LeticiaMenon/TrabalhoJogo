# Estruturas de Dados

Este documento descreve as estruturas em C que sustentam as funcionalidades descritas em `01-descricao-projeto.md` e implementam a lógica de `02-fluxograma.md`. A implementação real dessas estruturas está em `include/jogo.h`.

## 1. `Jogador` — estado acumulado da partida

```c
typedef struct {
    char nome[50];
    int  pontosBondade;    /* varia de -100 a 100 */
    int  confiancaDragao;  /* varia de 0 a 100 */
    bool dragaoAliado;
    int  noAtual;          /* id do NoHistoria em que o jogador está */
    FinalJogo final;
} Jogador;
```

Representa tudo o que precisa ser lembrado entre uma escolha e outra: o quanto o jogador se comportou como "vilã" ou "heroína" (`pontosBondade`), o quanto o dragão confia nela (`confiancaDragao`), se a aliança já foi firmada (`dragaoAliado`), em qual nó da narrativa ela está (`noAtual`) e, ao fim da partida, qual final foi atingido.

É a única struct que muda de valor durante o jogo — todas as outras (`NoHistoria`, `Escolha`) são dados fixos que descrevem o roteiro, carregados uma vez no início.

## 2. `NoHistoria` — um "capítulo" ou cena do roteiro

```c
typedef struct {
    int     id;
    char    textoNarrativo[600];
    int     totalEscolhas;
    Escolha escolhas[MAX_ESCOLHAS];
} NoHistoria;
```

Cada nó é um ponto da história: o texto que é exibido ao jogador e a lista de escolhas disponíveis ali. O jogo, na prática, é um vetor (ou lista) de `NoHistoria`, e `jogador.noAtual` indica em qual posição desse vetor o jogador está.

## 3. `Escolha` — uma opção dentro de um nó

```c
typedef struct {
    char texto[200];
    int  proximoNo;
    int  deltaBondade;
    int  deltaConfiancaDragao;
} Escolha;
```

Cada escolha carrega o efeito que ela tem no estado do jogador (`deltaBondade`, `deltaConfiancaDragao`) e para qual nó o jogo deve seguir (`proximoNo`) caso ela seja selecionada. É essa struct que implementa, na prática, as arestas do grafo narrativo descrito no fluxograma.

## 4. `FinalJogo` — enumeração dos desfechos possíveis

```c
typedef enum {
    FINAL_EM_ABERTO = 0,
    FINAL_MORTE_PELO_HEROI,
    FINAL_PERDOADA_PELO_HEROI,
    FINAL_ALIADA_DO_DRAGAO,
    FINAL_MORTE_PELO_DRAGAO
} FinalJogo;
```

Cada valor corresponde a um dos nós terminais mapeados na tabela de finais do fluxograma. `FINAL_EM_ABERTO` é o valor inicial, usado enquanto a partida ainda está em andamento.

## 5. Como as estruturas se relacionam com as funcionalidades

| Funcionalidade (docs/01) | Estrutura responsável |
|---|---|
| Narrativa ramificada | `NoHistoria` + `Escolha` (grafo de nós) |
| Pontos de Bondade | `Jogador.pontosBondade`, atualizado via `Escolha.deltaBondade` |
| Confiança/aliança do Dragão | `Jogador.confiancaDragao` e `Jogador.dragaoAliado`, atualizados via `Escolha.deltaConfiancaDragao` |
| Múltiplos finais | `FinalJogo`, calculado a partir do estado final de `Jogador` |
| Persistência durante a sessão | `Jogador` mantido em memória durante o loop principal (ver `src/main.c`) |

## 6. Funções previstas (assinatura em `jogo.h`)

```c
void inicializarJogador(Jogador *jogador, const char *nome);
void aplicarEscolha(Jogador *jogador, const Escolha *escolha);
FinalJogo calcularFinal(const Jogador *jogador);
```

- `inicializarJogador` zera o estado e define o nome do personagem.
- `aplicarEscolha` soma os deltas da escolha selecionada ao estado do jogador e atualiza `dragaoAliado` quando `confiancaDragao` cruza o limiar definido.
- `calcularFinal` é chamada no nó de confronto final e decide, a partir de `pontosBondade` e `dragaoAliado`, qual `FinalJogo` será exibido — implementando a condição `L` do fluxograma.
