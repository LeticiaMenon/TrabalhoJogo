# Descrição do Projeto

## 1. Definição do problema

RPGs tradicionalmente colocam o jogador no papel do herói, numa progressão linear de "bem contra mal" em que o protagonista é sempre o lado certo da história. Poucas experiências exploram a perspectiva inversa: jogar como a antagonista de uma narrativa já escrita, tendo que sobreviver às consequências de decisões dentro de uma história que ela não escreveu e não controla por completo.

O desafio técnico do projeto é modelar, em linguagem C, um sistema de RPG textual que:

1. represente a narrativa como uma estrutura de decisões encadeadas (fluxo não linear, com múltiplos caminhos possíveis a partir de cada ponto da história);
2. rastreie o impacto acumulado das escolhas do jogador por meio de um sistema de pontuação (Pontos de Bondade);
3. determine, a partir desse estado acumulado, qual entre múltiplos finais possíveis será exibido ao jogador.

## 2. Solução proposta

**Eu não quero Morrer!!** é um RPG em texto (interface via terminal) no qual o jogador assume o papel da vilã de uma história de fantasia medieval, para a qual "reencarnou". A cada capítulo, o jogo apresenta uma cena narrativa com opções de ação; cada opção altera o valor de duas variáveis de estado do jogador: **Pontos de Bondade** (impacto geral acumulado das suas ações) e **Confiança do Dragão** (relação construída especificamente com um personagem-chave da trama).

O jogo avança por meio de um grafo de nós narrativos: cada nó contém um texto descritivo e uma lista de escolhas que levam a outros nós. Dois momentos são estruturalmente centrais para o enredo:

- **Encontro com o Dragão** — dependendo da Confiança acumulada até aquele ponto, o dragão pode se tornar aliado da vilã, permanecer hostil (arriscando um game over imediato caso a vilã perca esse confronto), ou simplesmente ser evitado sem aliança.
- **Confronto final com o Herói** — o desfecho do jogo depende da combinação entre os Pontos de Bondade acumulados ao longo de toda a jornada e a existência (ou não) de uma aliança com o dragão.

O jogador "vence" o jogo se atingir Pontos de Bondade suficientes para que o herói opte por poupá-la, **ou** se conseguir que o dragão lute ao seu lado na cena final — as duas rotas de vitória não são excludentes. Na ausência de ambas as condições, o jogo termina em game over.

## 3. Funcionalidades previstas

- Sistema de narrativa ramificada (múltiplos capítulos/nós, cada um com de 2 a 4 escolhas)
- Sistema de pontuação de Pontos de Bondade, atualizado a cada escolha do jogador
- Sistema paralelo de Confiança do Dragão, com um encontro-chave que pode resultar em aliança, fuga sem aliança ou game over
- Cena de confronto final cujo desfecho é calculado a partir do estado acumulado do jogador
- No mínimo 4 finais distintos: morte pelo herói, perdão do herói, aliança com o dragão na batalha final, e derrota no confronto com o dragão
- Persistência do estado do jogador durante a sessão de jogo (via structs em memória — ver `docs/03-estruturas-dados.md`)
- Interface em texto via terminal, com menus numerados e leitura de entrada do usuário

## 4. Escopo desta entrega (1º bimestre)

Nesta etapa entregamos: definição do problema e da solução proposta (este documento), fluxograma da lógica narrativa (`docs/02-fluxograma.md`), descrição das estruturas de dados que sustentarão as funcionalidades (`docs/03-estruturas-dados.md`) e o repositório inicial, organizado, com um esqueleto de código já compilável (`include/jogo.h` e `src/main.c`).

A escrita completa do conteúdo narrativo de cada capítulo, o balanceamento dos valores de pontuação e os testes de todos os caminhos possíveis serão desenvolvidos ao longo do 2º bimestre, para a entrega técnica final.

## 5. Integrantes do grupo

- Grazielli Sousa de Andrade
- Leticia Menon
- Karen Gusikuda
