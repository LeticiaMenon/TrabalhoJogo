# Estruturas de Dados

Este documento descreve as estruturas em C que sustentam as funcionalidades descritas em `01-descricao-projeto.md` e implementam a lógica de `02-fluxograma.md`. A implementação real está em `Projeto_Jogo.c`.

Nesta versão do jogo (*De Repente Vila*), o estado da partida fica em **variáveis globais**, a ordem dos capítulos em um **vetor** e a narrativa em **funções**. As decisões são tomadas com `if / else` e as repetições com `while` e `for`.

## 1. Variáveis globais — estado acumulado da partida

```c
int bondade = 0;
int confianca = 0;
int dragaoAliado = 0;
int gameOver = 0;
int ajudouIrmao = 0;
```

| Variável | Tipo | Papel na partida | Alterada em |
|---|---|---|---|
| `bondade` | `int` | Pontos de Bondade: mede o quanto o jogador se afasta da crueldade da duquesa. Junto com `dragaoAliado`, decide o final. | `capitulo1`, `capitulo2`, `aventuraFloresta`, `capitulo3`, `amizadeDragao`, `capitulo4`, `capitulo5` |
| `confianca` | `int` | Confiança do Dragão (Kael). Precisa ser maior ou igual a 30 para a aliança ser possível. | `capitulo3`, `amizadeDragao`, `capitulo4` |
| `dragaoAliado` | `int` (0 ou 1) | Indica se a aliança com Kael foi firmada. | `capitulo4` |
| `gameOver` | `int` (0 ou 1) | Indica que a partida terminou antes do confronto final (morte na caverna do dragão). | `capitulo4` |
| `ajudouIrmao` | `int` (0 ou 1) | Indica se o jogador ajudou Lucian, irmão de Adrian. Altera apenas os diálogos do confronto final. | `capitulo5` |

Representam tudo o que precisa ser lembrado entre uma escolha e outra. São os únicos dados que mudam durante o jogo: os textos da narrativa são fixos e ficam dentro das funções.

O código não impõe limites aos valores. Somando todas as combinações possíveis de escolhas, `bondade` varia de −70 a 120 e `confianca` de −50 a 85. Os valores 0 e 1 das demais variáveis funcionam como verdadeiro e falso.

No início de cada partida, a `main` zera as cinco variáveis, o que permite a opção de jogar novamente sem reiniciar o programa.

## 2. Vetor `ordem` — sequência dos capítulos

```c
int ordem[5] = {1, 2, 3, 4, 5};
```

Declarado na `main`, guarda a ordem em que os capítulos são executados. Um laço `for` percorre o vetor e, a cada posição, uma cadeia `if / else if` chama o capítulo correspondente:

```c
for (i = 0; i < 5 && gameOver == 0; i++) {
    if (ordem[i] == 1) {
        capitulo1();
    } else if (ordem[i] == 2) {
        capitulo2();
    } else if (ordem[i] == 3) {
        capitulo3();
    } else if (ordem[i] == 4) {
        capitulo4();
    } else if (ordem[i] == 5) {
        capitulo5();
    }
}
```

A condição `gameOver == 0` interrompe o laço assim que o jogador morre, e o confronto final não é executado. Um laço `while (jogarNovamente == 1)` envolve toda a partida.

## 3. Capítulos e cenas — funções do roteiro

Cada cena é uma função `void` que desenha a arte ASCII, exibe o texto narrativo e, quando há decisão, pede uma escolha e atualiza as variáveis globais. Não existe um vetor de cenas: o roteiro está nas próprias funções, na ordem em que elas são chamadas.

| Ordem | Função | Cena | Arte ASCII | Opções |
|---|---|---|---|---|
| 0 | `prologo` | De Repente Vila — Uma segunda chance | — | — |
| 1 | `capitulo1` | O despertar no castelo | `desenharVila` | 3 |
| 1a | `lembrancaDoPassado` | Flashback — Quando tudo era diferente | `desenharCastelo` | — |
| 1b | `viagemAteVila` | Entre o castelo e a vila — A carta escondida | `desenharBiblioteca` | — |
| 2 | `capitulo2` | A vila esquecida | `desenharEstrada` | 3 |
| 2a | `aventuraFloresta` | A aventura — O mapa do curandeiro | `desenharPonte` | 3 |
| 3 | `capitulo3` | O guardião da floresta | `desenharFloresta`, `desenharDragao` | 3 |
| 3a | `amizadeDragao` | Entre as montanhas — Uma amizade improvável | `desenharMontanhas` | 3 |
| 4 | `capitulo4` | A caverna do dragão | `desenharCaverna`, `desenharDragao` | 4 |
| 5 | `capitulo5` | Os cavaleiros feridos | `desenharCavaleiros` | 3 |
| 6 | `finalJogo` | Confronto final — O destino de Evelynn | `desenharCastelo`, `desenharHeroi` e, conforme o final, `desenharDragao` | — |

As cenas 1a, 1b, 2a e 3a não aparecem no vetor `ordem`: são chamadas no fim do capítulo anterior (`capitulo1` chama 1a e 1b, `capitulo2` chama 2a e `capitulo3` chama 3a). São 7 pontos de decisão e 22 opções no total.

## 4. Escolhas — `escolher()` e cadeias `if / else if`

```c
int escolher(int quantidade);
```

Lê a opção com `scanf` dentro de um `while`, que repete até o jogador digitar um número entre 1 e `quantidade`. Entradas inválidas exibem uma mensagem de erro e o restante da linha é descartado. Se a entrada acabar (EOF), a função devolve a última opção para não ficar em laço infinito.

O valor devolvido é testado em uma cadeia `if / else if / else`, que aplica o efeito da escolha nas variáveis globais. Exemplo do `capitulo1`:

```c
opcao = escolher(3);
if (opcao == 1) {
    bondade = bondade + 20;
    /* texto da escolha */
} else if (opcao == 2) {
    /* texto da escolha */
} else {
    bondade = bondade - 15;
    /* texto da escolha */
}
```

Efeitos de cada opção:

| Cena | Opção | `bondade` | `confianca` | Outros efeitos |
|---|---|---|---|---|
| `capitulo1` | 1 — Ajudar Livia a recolher os cacos | +20 | — | — |
| | 2 — Não se envolver | — | — | — |
| | 3 — Gritar com Livia | −15 | — | — |
| `capitulo2` | 1 — Abrir os estoques de comida | +25 | — | — |
| | 2 — Entregar moedas | +10 | — | — |
| | 3 — Ignorar os pedidos | −10 | — | — |
| `aventuraFloresta` | 1 — Construir a passagem com Tomas | +10 | — | — |
| | 2 — Procurar trilha mais longa | — | — | — |
| | 3 — Mandar Tomas testar a ponte | −10 | — | — |
| `capitulo3` | 1 — Libertar Kael e cuidar dos ferimentos | +20 | +40 | — |
| | 2 — Soltar as correntes e partir | +10 | +15 | — |
| | 3 — Atacar o dragão | −20 | −30 | — |
| `amizadeDragao` | 1 — Ficar ao lado e cuidar da asa | +10 | +15 | — |
| | 2 — Deixar comida e respeitar o espaço | — | +10 | — |
| | 3 — Subir nas costas sem permissão | — | −20 | — |
| `capitulo4` | 1 — Pedir aliança | — | +30 (se `confianca >= 30`) | `dragaoAliado = 1` (se `confianca >= 30`); caso contrário, o dragão recusa |
| | 2 — Oferecer comida | +10 | +20 | `dragaoAliado = 1` (se `confianca >= 30` depois do +20) |
| | 3 — Evitar o dragão | — | — | — |
| | 4 — Enfrentar Kael | — | −30 (se `confianca >= 30`) | com `confianca >= 30`: `dragaoAliado = 0`; caso contrário: `gameOver = 1` |
| `capitulo5` | 1 — Cuidar de Lucian e dos cavaleiros | +25 | — | `ajudouIrmao = 1` |
| | 2 — Deixar remédios e comida | +10 | — | `ajudouIrmao = 1` |
| | 3 — Abandonar o grupo | −15 | — | — |

A aliança exige `confianca >= 30`. Nas opções 1 e 4 do `capitulo4`, o teste usa o valor que o jogador já tinha. Na opção 2, o teste acontece depois de somar +20.

## 5. Finais — decididos em `finalJogo()`

O jogo não usa uma enumeração: o final é escolhido por uma cadeia `if / else if` sobre `bondade` e `dragaoAliado`, e a primeira condição verdadeira vence. A derrota na caverna acontece antes, no `capitulo4`.

| Prioridade | Condição | Final | Resultado |
|---|---|---|---|
| antes do confronto | `gameOver == 1` | Game over na caverna do dragão | Derrota. `finalJogo()` não é chamada. |
| 1 | `bondade >= 60 && dragaoAliado == 1` | Final especial: Uma nova história | Vitória |
| 2 | `bondade >= 60` | Final bom: A vila redimida | Vitória |
| 3 | `dragaoAliado == 1` | Final do dragão: Asas da liberdade | Vitória (foge com Kael) |
| 4 | nenhuma das anteriores | Final ruim: O destino se repete | Game over |

A variável `ajudouIrmao` não muda o final: nos finais 1 e 2 ela apenas escolhe entre o diálogo de Lucian (`ajudouIrmao == 1`) e o do mensageiro.

## 6. Como as estruturas se relacionam com as funcionalidades

| Funcionalidade (docs/01) | Estrutura responsável |
|---|---|
| Narrativa ramificada | Funções de capítulo e cena + cadeias `if / else if` sobre o retorno de `escolher()` |
| Pontos de Bondade | Variável `bondade`, atualizada em cada escolha |
| Confiança/aliança do Dragão | Variáveis `confianca` e `dragaoAliado`, atualizadas nas escolhas dos capítulos 3 e 4 e em `amizadeDragao` |
| Múltiplos finais | Condições em `finalJogo()` sobre `bondade` e `dragaoAliado`, mais `gameOver` para a derrota na caverna |
| Sequência da aventura | Vetor `ordem[5]` percorrido por um `for` na `main` |
| Jogar novamente | Laço `while (jogarNovamente == 1)` e reinício das variáveis globais |
| Persistência durante a sessão | Variáveis globais, que existem durante toda a execução do programa |

## 7. Conceitos de programação aplicados

| Conceito | Onde aparece |
|---|---|
| Variáveis | Estado global (seção 1); locais como `opcao`, `i` e `jogarNovamente` |
| `if / else` | Efeito das escolhas, teste de `confianca >= 30` e escolha do final |
| `while` | `escolher()` (repete até a opção ser válida), `pausa()` (descarta a entrada até o ENTER) e `main` (jogar novamente) |
| `for` | `main`, percorrendo o vetor `ordem` |
| Vetor | `ordem[5]` |
| Funções | Interface, arte ASCII, cenas, capítulos e final (seção 8) |

## 8. Funções do programa (assinaturas em `Projeto_Jogo.c`)

```c
/* Interface */
void linha();            /* imprime a linha separadora */
void pausa();            /* espera o ENTER */
int  escolher(int quantidade);
void mostrarStatus();    /* mostra bondade, confiança e aliança */

/* Arte ASCII */
void desenharVila();
void desenharDragao();
void desenharHeroi();
void desenharCastelo();
void desenharBiblioteca();
void desenharEstrada();
void desenharFloresta();
void desenharPonte();
void desenharMontanhas();
void desenharCaverna();
void desenharCavaleiros();

/* Cenas e capítulos */
void prologo();
void lembrancaDoPassado();
void viagemAteVila();
void aventuraFloresta();
void amizadeDragao();
void capitulo1();
void capitulo2();
void capitulo3();
void capitulo4();
void capitulo5();
void finalJogo();

int main();
```
