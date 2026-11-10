#include <stdio.h>

/* DE REPENTE VILA - RPG de texto para terminal
   Versao expandida da historia original.
   Conceitos: variaveis, if/else, while, for, funcoes e vetor.
*/

int bondade = 0;
int confianca = 0;
int dragaoAliado = 0;
int gameOver = 0;
int ajudouIrmao = 0;

void linha() {
    printf("\n============================================================\n");
}

void pausa() {
    int c;
    printf("\n[Pressione ENTER para continuar]");
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int escolher(int quantidade) {
    int opcao = 0;
    int leitura;
    int c;
    while (opcao < 1 || opcao > quantidade) {
        printf("\nSua escolha: ");
        leitura = scanf("%d", &opcao);
        if (leitura != 1) {
            opcao = 0;
        }
        while ((c = getchar()) != '\n' && c != EOF) {
        }
        if (opcao < 1 || opcao > quantidade) {
            printf("Opcao invalida. Digite um numero entre 1 e %d.\n", quantidade);
        }
        if (c == EOF && leitura != 1) {
            return quantidade;
        }
    }
    return opcao;
}

void mostrarStatus() {
    printf("\n[STATUS] Bondade: %d | Confianca do Dragao: %d | Aliado: ",
           bondade, confianca);
    if (dragaoAliado == 1) {
        printf("Sim\n");
    } else {
        printf("Nao\n");
    }
}

void desenharVila() {
    printf("                              \n");
	printf("                             \n");
    printf("                / / \\\\\n");
    printf("               (/ a a\\\\)\n");
    printf("               (\\_-_/)\n");
    printf("               .--'='--.\n");
    printf("             /   ~`Y`~ \\ \n");
    printf("            / / (_ * _)\\\\ \n");
    printf("           / /   )   (  \\\\ \n");
    printf("           \\ \\_/\\_//\\_/ /\n");
    printf("            \\(_) `*' (_)/\n");
    printf("               |       |\n");
    printf("               |       |\n");
    printf("               |       |\n");
    printf("               |       |\n");
    printf("               |       |\n");
    printf("               |       |\n");
    printf("               |       |\n");
    printf("               |       |\n");
    printf("               w*W*w*W*w\n");
}
void desenharDragao() {
    printf("\n");
    printf("                    / \\  //\\\n");
    printf("       |\\___/|      /   \\//  \\\\\n");
    printf("       /O  O  \\__  /    //  | \\ \\\n");
    printf("      /     /  \\/_/    //   |  \\  \\\n");
    printf("      \\_^_\\'/   \\/_   //    |   \\   \\\n");
    printf("       //_^_/     \\/_ //     |    \\    \\\n");
    printf("    ( //) |        \\///      |     \\     \\\n");
    printf("  ( / /) _|_ /   )  //       |      \\     _\\\n");
}

void desenharHeroi() {
    printf("                      {}\n");
    printf("                     {{}}\n");
    printf("                     {{}}\n");
    printf("                      {}\n");
    printf("                    .-\"-.\n");
    printf("                  /    _   \\\n");
    printf("                 /   .- -.   \\\n");
    printf("                 \\ ::   ::  /\n");
    printf("                  \\ :  :  /\n");
    printf("                   )       (\n");
    printf("             .--  \\      //  --.\n");
    printf("            /     |  `--'  |     \\\n");
    printf("           |      |  :::::  |      |\n");
    printf("           |      /   :::   \\      |\n");
    printf("           |__.-'\\   __      /`-.__|\n");
    printf("           \\ .^`\\\\ \/   \\/     //`^. /\n");
    printf("            /    .-`-.|.-`-.     \\\n");
    printf("           `\\__/   .--.  \\__/`\n");
    printf("              |   |\\\\\\\\|  |\n");
    printf("              |   || |||  |\n");
    printf("              |;--.  || .--;|\n");
    printf("              |      ||      |\n");
    printf("              {{{{{{||}}}}}}\n");
    printf("              |  .===||===. |\n");
    printf("              <      ||     >\n");
    printf("               \\:--/||\ --:/\n");
    printf("                |   /||\  |\n");
    printf("                |   ||||  |\n");
    printf("                |   ||||  |\n");
    printf("               /^\\ |||| /^\\\n");
    printf("              /   : ||||:   \\\n");
    printf("             /   /  |||| \\   \\\n");
    printf("            (__.'   \\/   `.__)\n");
}

void desenharCastelo() {
    printf("                         o\n");
    printf("                        _|_\n");
    printf("           o          _|___|_          o\n");
    printf("          _|_        /  / \\  \\        _|_\n");
    printf("         |___|      /__/___\\__\\      |___|\n");
    printf("      ___|[] |___   | []  [] |   ___| []|___\n");
    printf("     /   |   |   \\__|   __   |__/   |   |   \\\n");
    printf("    /____|___|____\\ |  |  |  | /____|___|____\\\n");
    printf("    | []   []   [] | |  |  |  | | []   []   [] |\n");
    printf("    |  .--------.  | |  |  |  | |  .--------.  |\n");
    printf("    |  | []  [] |  |_|__|__|__|_|  | []  [] |  |\n");
    printf("    |  |        |  /            \\  |        |  |\n");
    printf("    |__|________|_/______________\\_|________|__|\n");
    printf("       /  /  /   |   _    _   |   \\  \\  \\\n");
    printf("      /__/__/____|__| |__| |__|____\\__\\__\\\n");
    printf("           ~ ~ ~  REINO DE VALDORIA  ~ ~ ~\n");
}

void desenharBiblioteca() {
    printf("       ________________________________________\n");
    printf("      |  ___  ___  ___   ___  ___  ___  |\n");
    printf("      | |###||###||###| |###||###||###| |\n");
    printf("      | |###||###||###| |###||###||###| |\n");
    printf("      | |___||___||___| |___||___||___| |\n");
    printf("      |--------------------------------|\n");
    printf("      | |###||###||###| |###||###||###| |\n");
    printf("      | |___||___||___| |___||___||___| |\n");
    printf("      |           __________           |\n");
    printf("      |__________/__DIARIO__\\__________|\n");
}

void desenharEstrada() {
    printf("         /\\                        /\\\n");
    printf("        /  \\       /\\            /  \\\n");
    printf("       /____\\     /  \\          /____\\\n");
    printf("         ||      /____\\           ||\n");
    printf("       __||________||_____________||___\n");
    printf("           .----.          .----.\n");
    printf("          / []  \\________/  [] \\\n");
    printf("         |   __    VILA     __   |\n");
    printf("         |__|  |___________|  |__|\n");
    printf("                  /    \ \\n");
    printf("                 /      \ \\n");
    printf("                /        \ \ \n");
}

void desenharFloresta() {
    printf("          /\\       /\\             /\\\n");
    printf("         /**\\     /**\\      /\\   /**\\\n");
    printf("        /****\\   /****\\    /**\\ /****\\\n");
    printf("       /******\\ /******\\  /****V******\\\n");
    printf("          ||       ||      /******\\ ||\n");
    printf("          ||       ||         ||    ||\n");
    printf("       .      .       .       .       .\n");
    printf("         ____        ____        ____\n");
    printf("        /    \\______/    \\______/    \\\n");
    printf("       /      TRILHA DA FLORESTA      \\ \n");
}

void desenharPonte() {
    printf("       /\\                         /\\\n");
    printf("      /**\\     ______________     /**\\\n");
    printf("     /****\\   /_/ /_/ /_/ /_/ \\   /****\\\n");
    printf("       ||    /_/ /_/ /_/ /_/ /_\\    ||\n");
    printf("    ___||___/___________________\\___||___\n");
    printf("       ~ ~ ~ ~ RIO GELADO ~ ~ ~ ~\n");
    printf("         ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
}

void desenharMontanhas() {
    printf("                 /\\          /\\\n");
    printf("            /\\  /  \\   /\\   /  \\\n");
    printf("           /  \\/    \\ /  \\ /    \\\n");
    printf("       /\\ /          V    V      \\\n");
    printf("      /  V                          \\\n");
    printf("     /_____      ____      __________\\\n");
    printf("           \\____/    \\____/\n");
    printf("             *   FONTE   *\n");
}

void desenharCaverna() {
    printf("         ___________________________\n");
    printf("       _/  /\\    /\\   /\\    /\\    \\_\n");
    printf("      /   /  \\__/  \\_/  \\__/  \\    \\\n");
    printf("     /                                \\\n");
    printf("    |      *      _______       *      |\n");
    printf("    |            /       \\             |\n");
    printf("    |           |  LAGO   |            |\n");
    printf("    |            \\_______/             |\n");
    printf("     \\      *                 *       /\n");
    printf("      \\______________________________/\n");
}

void desenharCavaleiros() {
    printf("           |\            //               |\           //                |\           //\n");
    printf("           | \          _!_               | \         _!_                | \         _!_\n");
    printf("            \ \       /___\\               \ \       /___\\               \ \       /___\\\n");
    printf("             \ \     { [+++]}               \ \     { [+++]}               \ \     {[+++]}\n");
    printf("              \ \     .-\"- .                \ \   |.-\"- .|                \ \    |.-\"- .|\n");
    printf("               \\/   (  -  )                  \ \  /(  -  )                  \ \  /(  -  )\n");
    printf("               /( \\ | {&} /\\                /( \\ | {&} /\\                /( \\ | {&} /\\\n");
    printf("              /  \\ / \\ /  >)               /  \\ / \\ /  >)               /  \\ / \\ /  >)\n");
    printf("              \\   /   /--\\                 \\   /   /--\\                 \\   /   /--  \\\n");
    printf("               \\_/  >::::-\\                 \\_/  >::::-\\                 \\_/  >::::-  \\\n");
    printf("                 / /::::/     \\                  / /::::/   \\                /   /::::/      \\\n");
    printf("                 / /||   {&}  |                  / /||  {&}   |               /   /||  {&}   |\n");
    printf("                ( / (\\      /                  (  /(\\      /                (  / (\\        /\n");
    printf("                 / /  \\.__.-                  / /  \\.__ .-                  / /  \\.__ .-\n");
    printf("                / /    | \\                   / /    | \\                    / /    | \\\n");
    printf("               /__|    /__|                 /__|    /__|                    /__|    /__|\n");
    printf("\n");
    printf("           CAVALEIROS NA ESTRADA - LUCIAN E SEUS COMPANHEIROS\n");
}
void prologo() {
    linha();
    printf("                 DE REPENTE VILA\n");
    printf("              Uma segunda chance\n");
    linha();
    printf("\nVoce se lembra de estar lendo 'A Coroa do Destino',\n");
    printf("um romance sobre um heroi que salvaria o reino de Valdoria.\n");
    printf("Na ultima pagina, a cruel duquesa Evelynn de Ravencrest\n");
    printf("morria diante da espada do heroi Adrian.\n");
    printf("\nMas, ao abrir os olhos, voce nao esta mais em seu quarto.\n");
    printf("Cortinas vermelhas, paredes de pedra e um espelho dourado\n");
    printf("revelam uma verdade impossivel: voce agora e Evelynn.\n");
    printf("\nNo livro, a duquesa era odiada pelos servos, temida pelo\n");
    printf("povo e condenada por suas proprias escolhas.\n");
    printf("A batalha final acontecera em poucas semanas.\n");
    printf("\nTalvez voce nao consiga mudar o mundo inteiro.\n");
    printf("Mas pode tentar mudar o destino desta vila.\n");
    pausa();
}


void lembrancaDoPassado() {
    linha();
    printf("FLASHBACK - QUANDO TUDO ERA DIFERENTE\n");
    desenharCastelo();
    linha();
    printf("\nAo tocar um medalhao no diario, uma lembranca invade\n");
    printf("sua mente. Sao memorias da verdadeira Evelynn.\n");
    printf("\nAnos atras, Evelynn e Adrian brincavam nos jardins\n");
    printf("do castelo. Ele era filho de um cavaleiro, e ela,\n");
    printf("a herdeira de Ravencrest. Eram amigos inseparaveis.\n");
    printf("\n'Quando eu for heroi, vou proteger voce!', dizia Adrian.\n");
    printf("'E eu vou proteger voce tambem!', respondia Evelynn.\n");
    printf("\nMas a felicidade terminou quando a mae de Evelynn,\n");
    printf("Lady Helena, morreu durante uma epidemia no reino.\n");
    printf("Evelynn pediu ajuda a nobreza, mas recebeu silencio.\n");
    printf("A dor se transformou em raiva. Ela passou a acreditar\n");
    printf("que bondade era fraqueza e que o poder impediria\n");
    printf("que alguem a ferisse novamente.\n");
    printf("\nAdrian tentou consola-la, mas Evelynn o afastou.\n");
    printf("'Voce nao entende o que perdi. Va embora!'\n");
    printf("Com o tempo, ela aumentou impostos, castigou servos\n");
    printf("e se tornou a duquesa temida por todo o reino.\n");
    printf("\nA lembranca termina. Voce compreende o sofrimento\n");
    printf("da antiga Evelynn, mas sabe que ele nao justifica\n");
    printf("o mal que ela causou. Ainda pode escolher diferente.\n");
    pausa();
}

void viagemAteVila() {
    linha();
    printf("ENTRE O CASTELO E A VILA - A CARTA ESCONDIDA\n");
    desenharBiblioteca();
    linha();
    printf("\nNa biblioteca, voce encontra uma carta da antiga\n");
    printf("administradora das terras de Ravencrest.\n");
    printf("Ela alerta que os impostos estao deixando familias\n");
    printf("sem comida. O conselheiro real, Lorde Varen,\n");
    printf("escondeu as reclamacoes para proteger sua posicao.\n");
    printf("\nVoce decide investigar pessoalmente. Se quer mudar\n");
    printf("o destino de Evelynn, precisa conhecer os danos\n");
    printf("causados pelas ordens que carregam seu nome.\n");
    printf("\nLivia lhe entrega um manto simples para viajar\n");
    printf("sem ser reconhecida. O cocheiro Tomas oferece ajuda.\n");
    printf("Durante o caminho, ele conta que sua irma mora\n");
    printf("na vila e nao consegue alimentar os filhos.\n");
    printf("\nQuando a estrada fica estreita, voces descem da\n");
    printf("carruagem e seguem a pe ate as primeiras casas.\n");
    printf("Voce ve campos abandonados e um moinho parado.\n");
    pausa();
}

void aventuraFloresta() {
    int opcao;
    linha();
    printf("A AVENTURA - O MAPA DO CURANDEIRO\n");
    desenharPonte();
    linha();
    printf("\nDepois de visitar a vila, voce descobre que as\n");
    printf("reservas de graos do reino foram roubadas.\n");
    printf("Uma curandeira chamada Mira revela que os bandidos\n");
    printf("levaram os suprimentos pela Floresta de Cinzas.\n");
    printf("\nEla tambem conta que um dragao antigo, Kael,\n");
    printf("protegia as nascentes que irrigavam a regiao.\n");
    printf("Desde que cacadores o feriram, as fontes secaram.\n");
    printf("Se encontrar Kael e conseguir sua ajuda, voce\n");
    printf("podera descobrir como recuperar a agua da vila.\n");
    printf("\nMira entrega um mapa e ervas para tratar feridas.\n");
    printf("Tomas se oferece para acompanha-la ate a floresta.\n");
    printf("No caminho, voces encontram uma ponte quebrada.\n");
    printf("\nComo deseja atravessar?\n");
    printf("1 - Ajudar Tomas a construir uma passagem segura.\n");
    printf("2 - Procurar uma trilha mais longa entre as pedras.\n");
    printf("3 - Mandar Tomas atravessar primeiro para testar.\n");
    opcao = escolher(3);
    if (opcao == 1) {
        bondade = bondade + 10;
        printf("\nVoces juntam tabuas e amarram cordas. Tomas\n");
        printf("agradece por voce nao colocar a vida dele em risco.\n");
    } else if (opcao == 2) {
        printf("\nVoces encontram um caminho estreito, mas seguro.\n");
        printf("A viagem demora, e a noite comeca a cair.\n");
    } else {
        bondade = bondade - 10;
        printf("\nTomas quase cai no rio ao testar a ponte.\n");
        printf("Ele consegue voltar, mas perde parte da confianca\n");
        printf("que estava comecando a depositar em voce.\n");
    }
    printf("\nMais adiante, voces encontram marcas de correntes,\n");
    printf("penas de flechas e pegadas enormes na lama.\n");
    printf("O mapa de Mira indica uma clareira logo a frente.\n");
    printf("Voce sabe agora por que precisa encontrar o dragao.\n");
    mostrarStatus();
    pausa();
}

void amizadeDragao() {
    int opcao;
    linha();
    printf("ENTRE AS MONTANHAS - UMA AMIZADE IMPROVAVEL\n");
    desenharMontanhas();
    linha();
    printf("\nApos o encontro na floresta, voce retorna ao abrigo\n");
    printf("de Mira para descobrir mais sobre Kael.\n");
    printf("A curandeira explica que dragoes entendem promessas\n");
    printf("e lembram de quem os trata com respeito.\n");
    printf("\nVoce leva agua e ervas ate uma colina proxima.\n");
    printf("Kael aparece entre as arvores. Ainda esta cauteloso.\n");
    printf("Voce se senta longe dele e deixa os suprimentos\n");
    printf("no chao, sem tentar obriga-lo a se aproximar.\n");
    printf("\nO que voce faz para conquistar sua confianca?\n");
    printf("1 - Permanecer ao lado dele e cuidar da asa ferida.\n");
    printf("2 - Deixar comida e respeitar seu espaco.\n");
    printf("3 - Tentar subir em suas costas sem permissao.\n");
    opcao = escolher(3);
    if (opcao == 1) {
        bondade = bondade + 10;
        confianca = confianca + 15;
        printf("\nKael permite que voce troque a faixa da asa.\n");
        printf("Quando termina, ele repousa a cabeca perto de voce.\n");
        printf("Pela primeira vez, voces descansam sem medo.\n");
    } else if (opcao == 2) {
        confianca = confianca + 10;
        printf("\nVoce recua e espera. Kael aceita a comida e\n");
        printf("se aproxima um pouco antes de partir.\n");
    } else {
        confianca = confianca - 20;
        printf("\nKael se assusta e abre as asas, derrubando voce.\n");
        printf("Ele nao a fere, mas se afasta. Confianca nao\n");
        printf("pode ser exigida a forca.\n");
    }
    printf("\nNos dias seguintes, voce visita a colina sempre\n");
    printf("que pode. Conta historias de sua antiga vida,\n");
    printf("observa Kael aprender a voar novamente e descobre\n");
    printf("que ele gosta de dormir perto das fontes quentes.\n");
    printf("Uma noite, Kael leva voce ate uma nascente escondida.\n");
    printf("A agua ainda corre ali. Talvez seja possivel abrir\n");
    printf("novamente os canais que abasteciam a vila.\n");
    printf("\nA amizade cresce em pequenos gestos. Ainda assim,\n");
    printf("Kael precisa decidir se deseja lutar ao seu lado.\n");
    mostrarStatus();
    pausa();
}

void capitulo1() {
    int opcao;
    linha();
    printf("CAPITULO 1 - O DESPERTAR NO CASTELO\n");
    desenharVila();
    linha();
    printf("\nA luz da manha invade o quarto da duquesa. Voce tenta\n");
    printf("se acostumar com o peso de um nome que nao e seu.\n");
    printf("Uma jovem criada chamada Livia entra com o cafe da manha.\n");
    printf("Ao perceber que voce esta acordada, ela se assusta,\n");
    printf("tropeca no tapete e derruba uma bandeja de porcelana.\n");
    printf("\n'Perdao, minha senhora! Por favor, nao me castigue!'\n");
    printf("A garota se ajoelha entre os cacos, tremendo.\n");
    printf("Voce se recorda: no livro, Evelynn punia servos por menos.\n");
    printf("\nO que voce faz?\n");
    printf("1 - Ajudar Livia a recolher os cacos.\n");
    printf("2 - Nao se envolver e deixar que ela limpe.\n");
    printf("3 - Gritar com Livia por sua falta de cuidado.\n");
    opcao = escolher(3);
    if (opcao == 1) {
        bondade = bondade + 20;
        printf("\nVoce se ajoelha ao lado dela e pergunta se esta ferida.\n");
        printf("Livia arregala os olhos. 'A senhora... esta me ajudando?'\n");
        printf("Quando voce diz que acidentes acontecem, ela sorri\n");
        printf("timidamente. Pela primeira vez, alguem ve outra Evelynn.\n");
    } else if (opcao == 2) {
        printf("\nVoce observa em silencio. Livia limpa tudo rapidamente.\n");
        printf("Ela sai aliviada por nao ter sido punida, mas ainda teme\n");
        printf("o que a duquesa podera fazer no futuro.\n");
    } else {
        bondade = bondade - 15;
        printf("\nSua voz ecoa pelo quarto. Livia pede desculpas varias\n");
        printf("vezes e sai chorando. O castelo continua a temer voce.\n");
    }
    printf("\nMais tarde, voce encontra o diario da antiga Evelynn.\n");
    printf("Entre as paginas, ha uma frase sublinhada:\n");
    printf("'Nao existe misericordia para quem nasceu como monstro.'\n");
    printf("Voce fecha o diario. Sera que isso precisa ser verdade?\n");
    mostrarStatus();
    pausa();
    lembrancaDoPassado();
    viagemAteVila();
}

void capitulo2() {
    int opcao;
    linha();
    printf("CAPITULO 2 - A VILA ESQUECIDA\n");
    desenharEstrada();
    linha();
    printf("\nPara entender o reino, voce deixa o castelo em uma\n");
    printf("carruagem discreta. Na estrada, encontra uma vila pobre.\n");
    printf("O moinho esta parado, os campos estao secos e quase nao\n");
    printf("ha comida nas casas. Uma mulher segura uma crianca fraca.\n");
    printf("\n'Os impostos levaram nossa ultima colheita', ela conta.\n");
    printf("'Se a duquesa soubesse de nossa fome, talvez ajudasse.'\n");
    printf("\nVoce sente um aperto no peito: foi Evelynn quem ordenou\n");
    printf("a cobranca desses impostos na historia original.\n");
    printf("Os moradores ainda nao reconheceram seu rosto.\n");
    printf("\nO que voce faz?\n");
    printf("1 - Abrir os estoques de comida de sua carruagem.\n");
    printf("2 - Entregar algumas moedas aos moradores.\n");
    printf("3 - Ignorar os pedidos e continuar a viagem.\n");
    opcao = escolher(3);
    if (opcao == 1) {
        bondade = bondade + 25;
        printf("\nVoce manda distribuir paes, frutas e sacos de graos.\n");
        printf("As criancas correm para ajudar. A mulher agradece,\n");
        printf("sem imaginar que esta diante da propria duquesa.\n");
        printf("A noticia de uma nobre generosa comeca a se espalhar.\n");
    } else if (opcao == 2) {
        bondade = bondade + 10;
        printf("\nVoce entrega uma bolsa de moedas. Nao resolvera a fome\n");
        printf("por muito tempo, mas podera comprar comida por alguns dias.\n");
        printf("Os moradores agradecem sua ajuda.\n");
    } else {
        bondade = bondade - 10;
        printf("\nVoce ordena que o cocheiro siga em frente. Pelo vidro,\n");
        printf("ve a mulher abracar a crianca e abaixar a cabeca.\n");
        printf("O silencio da carruagem parece mais pesado que antes.\n");
    }
    printf("\nAo anoitecer, um viajante menciona rumores sobre um\n");
    printf("dragao negro visto nas florestas do norte. Dizem que\n");
    printf("quem cruza seu caminho nunca retorna.\n");
    mostrarStatus();
    pausa();
    aventuraFloresta();
}

void capitulo3() {
    int opcao;
    linha();
    printf("CAPITULO 3 - O GUARDIAO DA FLORESTA\n");
    desenharFloresta();
    linha();
    printf("\nDe repente uma tempestade começa, sua visão fica debilitada e voce se perde\n");
    printf("na Floresta de Cinzas. Entre as arvores, ouve um rugido.\n");
    printf("Ao seguir o som, encontra um enorme dragao negro preso\n");
    printf("em correntes de ferro, com uma asa gravemente ferida.\n");
    desenharDragao();
    printf("\nSeus olhos dourados acompanham cada movimento seu.\n");
    printf("Uma flecha de cacador esta cravada entre suas escamas.\n");
    printf("Quando voce se aproxima, ele mostra os dentes.\n");
    printf("\nVoce se lembra do livro: este dragao, chamado Kael,\n");
    printf("era considerado uma criatura cruel. Mas agora ele parece\n");
    printf("mais assustado e ferido do que verdadeiramente maligno.\n");
    printf("\nO que voce faz?\n");
    printf("1 - Libertar Kael e cuidar de seus ferimentos.\n");
    printf("2 - Soltar as correntes e partir sem se aproximar.\n");
    printf("3 - Atacar o dragao antes que ele possa reagir.\n");
    opcao = escolher(3);
    if (opcao == 1) {
        bondade = bondade + 20;
        confianca = confianca + 40;
        printf("\nCom cuidado, voce rompe as correntes e retira a flecha.\n");
        printf("Kael rosna, mas nao tenta feri-la. Voce usa seu manto\n");
        printf("para improvisar uma faixa sobre a asa machucada.\n");
        printf("Antes de partir, o dragao inclina a cabeca, como se\n");
        printf("estivesse tentando entender sua estranha gentileza.\n");
    } else if (opcao == 2) {
        bondade = bondade + 10;
        confianca = confianca + 15;
        printf("\nVoce destrava as correntes e se afasta rapidamente.\n");
        printf("Kael se ergue com dificuldade e observa sua partida.\n");
        printf("Ele nao esquece que voce poderia te-lo deixado preso.\n");
    } else {
        bondade = bondade - 20;
        confianca = confianca - 30;
        printf("\nVoce golpeia a criatura. Kael ruge de dor e raiva.\n");
        printf("As correntes se partem com a forca de seu movimento.\n");
        printf("Voce foge por pouco. O dragao memoriza seu rosto.\n");
    }
    printf("\nNa saida da floresta, voce encontra uma escama negra\n");
    printf("sobre a trilha. Talvez o destino ainda una voces.\n");
    mostrarStatus();
    pausa();
    amizadeDragao();
}

void capitulo4() {
    int opcao;
    linha();
    printf("CAPITULO 4 - A CAVERNA DO DRAGAO\n");
    desenharCaverna();
    linha();
    printf("\nUm mensageiro avisa que o heroi Adrian reuniu soldados\n");
    printf("e pretende marchar contra o castelo de Ravencrest.\n");
    printf("Voce volta as montanhas para pedir ajuda a Kael\n");
    printf("para reabrir os canais de agua e proteger a vila.\n");
    printf("\nNo fundo dela, Kael descansa junto a um lago subterraneo.\n");
    desenharDragao();
    printf("\nEle reconhece voce imediatamente. Suas asas se abrem\n");
    printf("e o ar esquenta ao redor de suas presas.\n");
    if (confianca >= 30) {
        printf("Mas seus olhos nao demonstram a mesma hostilidade de antes.\n");
    } else {
        printf("O dragao ainda parece desconfiado de suas intencoes.\n");
    }
    printf("\nVoce precisa decidir se arriscara uma aproximacao.\n");
    printf("1 - Pedir a Kael que forme uma alianca com voce.\n");
    printf("2 - Oferecer comida e tentar ganhar sua amizade.\n");
    printf("3 - Evitar o dragao e seguir viagem.\n");
    printf("4 - Enfrentar Kael para provar sua forca.\n");
    opcao = escolher(4);
    if (opcao == 1) {
        if (confianca >= 30) {
            dragaoAliado = 1;
            confianca = confianca + 30;
            printf("\nVoce explica que nao deseja repetir os crimes de Evelynn.\n");
            printf("Kael escuta em silencio. Entao abaixa a cabeca diante\n");
            printf("de voce, aceitando sua proposta de alianca.\n");
            printf("'Nao se arrependera de confiar em mim', voce promete.\n");
        } else {
            printf("\nVoce pede ajuda, mas Kael recua e solta fumaca pelas\n");
            printf("narinas. Uma alianca exige mais do que palavras.\n");
            printf("Sem confiar em voce, ele se recusa a acompanha-la.\n");
        }
    } else if (opcao == 2) {
        confianca = confianca + 20;
        bondade = bondade + 10;
        printf("\nVoce deixa carne e agua limpa diante de Kael.\n");
        printf("Ele se aproxima devagar, cheirando a oferta.\n");
        if (confianca >= 30) {
            dragaoAliado = 1;
            printf("Depois de comer, o dragao toca sua mao com o focinho.\n");
            printf("E um gesto pequeno, mas suficiente: Kael e seu aliado.\n");
        } else {
            printf("Kael aceita a comida, mas mantem distancia.\n");
            printf("Voce respeita sua decisao e parte sem uma alianca.\n");
        }
    } else if (opcao == 3) {
        printf("\nVoce escolhe nao arriscar. Atravessa a caverna sem\n");
        printf("provocar Kael e segue sozinha rumo ao castelo.\n");
    } else {
        if (confianca >= 30) {
            confianca = confianca - 30;
            printf("\nVoce desembainha a espada. Kael poderia atacar, mas\n");
            printf("reconhece a pessoa que encontrou na floresta.\n");
            printf("Ele permite que voce saia, embora nao aceite ser aliado.\n");
            dragaoAliado = 0;
        } else {
            printf("\nKael interpreta seu gesto como uma ameaca mortal.\n");
            printf("Uma onda de fogo ilumina as paredes da caverna.\n");
            printf("Voce tenta fugir, mas nao consegue escapar.\n");
            gameOver = 1;
        }
    }
    mostrarStatus();
    pausa();
}

void capitulo5() {
    int opcao;
    linha();
    printf("CAPITULO 5 - OS CAVALEIROS FERIDOS\n");
    desenharCavaleiros();
    linha();
    printf("\nAo retornar ao reino, voce descobre que Sir Adrian\n");
    printf("reuniu cavaleiros e marcha contra Ravencrest.\n");
    printf("No caminho, encontra um grupo de soldados atacado\n");
    printf("por bandidos que roubavam alimentos da regiao.\n");
    printf("\nUm jovem cavaleiro de cabelos castanhos esta ferido.\n");
    printf("Seu nome e Lucian. Ele tenta proteger os companheiros,\n");
    printf("mesmo sem conseguir se levantar.\n");
    printf("\n'Nao confie na duquesa', murmura um dos soldados.\n");
    printf("'Ela jamais ajudaria homens do heroi.'\n");
    printf("\nVoce reconhece o sobrenome do jovem: Lucian de Valdoria.\n");
    printf("Ele e o irmao mais novo de Adrian, seu antigo amigo.\n");
    printf("No livro, Lucian desaparecia antes da batalha final.\n");
    printf("Agora voce entende o que aconteceu com ele.\n");
    printf("\nO que voce faz?\n");
    printf("1 - Cuidar de Lucian e dos outros cavaleiros.\n");
    printf("2 - Deixar remedios e comida para os feridos.\n");
    printf("3 - Abandonar o grupo e voltar ao castelo.\n");
    opcao = escolher(3);
    if (opcao == 1) {
        bondade = bondade + 25;
        ajudouIrmao = 1;
        printf("\nVoce limpa os ferimentos de Lucian e improvisa\n");
        printf("curativos para os outros cavaleiros. Depois,\n");
        printf("organiza uma carroca para leva-los a um abrigo.\n");
        printf("\n'Por que esta nos ajudando?', Lucian pergunta.\n");
        printf("'Porque voces precisam de ajuda', voce responde.\n");
        printf("Ele reconhece seu rosto e fica sem palavras.\n");
        printf("'Meu irmao precisa saber o que fez por nos.'\n");
    } else if (opcao == 2) {
        bondade = bondade + 10;
        ajudouIrmao = 1;
        printf("\nVoce deixa agua, comida, faixas e remedios.\n");
        printf("Lucian recebe os suprimentos e agradece.\n");
        printf("Quando percebe quem voce e, fica surpreso:\n");
        printf("'Evelynn? Nao esperava ajuda de voce.'\n");
        printf("Ele promete contar a Adrian o que aconteceu.\n");
    } else {
        bondade = bondade - 15;
        printf("\nVoce parte sem ajudar. Lucian observa sua\n");
        printf("carruagem desaparecer pela estrada.\n");
        printf("A imagem cruel da duquesa permanece intacta.\n");
    }
    printf("\nAo chegar a Ravencrest, encontra os portoes cercados.\n");
    printf("Adrian espera no salao do trono, com a espada em maos.\n");
    printf("Voce reconhece a cena da ultima pagina do livro.\n");
    mostrarStatus();
    pausa();
}

void finalJogo() {
    linha();
    printf("CONFRONTO FINAL - O DESTINO DE EVELYNN\n");
    desenharCastelo();
    linha();
    desenharHeroi();
    printf("\nAdrian entra no salao do trono com a espada erguida.\n");
    printf("'Evelynn, seus crimes contra Valdoria terminam hoje!'\n");
    printf("\nVoce reconhece o amigo de infancia nas feicoes\n");
    printf("do heroi, mas ele so parece enxergar a antiga vila.\n");
    printf("'Adrian, nos fomos amigos. Lembra do jardim?'\n");
    printf("'Lembro. Tambem lembro de quem voce se tornou.'\n");
    printf("\nVoce explica que a morte de Helena mudou Evelynn,\n");
    printf("mas que a dor nunca justificou suas crueldades.\n");
    printf("'Nao posso desfazer o passado. Posso escolher\n");
    printf("o que farei daqui para a frente', voce responde.\n");
    pausa();

    if (bondade >= 60 && dragaoAliado == 1) {
        printf("\n*** FINAL ESPECIAL: UMA NOVA HISTORIA ***\n");
        printf("\nAdrian ainda esta desconfiado e avanca com a espada.\n");
        printf("Antes que a lamina alcance voce, um rugido sacode\n");
        printf("as muralhas. Kael sente que sua amiga esta ameacada.\n");
        desenharDragao();
        printf("\nO dragao pousa diante do salao e abre as asas,\n");
        printf("protegendo voce sem atacar o heroi.\n");
        printf("\nAdrian para imediatamente, perplexo.\n");
        printf("'Como conseguiu a lealdade de um dragao?'\n");
        printf("'Todos dizem que Kael odeia os humanos! E voce...'\n");
        printf("'Voce sempre foi cruel com todos a sua volta!'\n");
        printf("\n'Eu encontrei Kael ferido e o ajudei', voce diz.\n");
        printf("'Nao pedi que confiasse em mim. Cuidei dele,\n");
        printf("respeitei seus limites e conquistei sua amizade.'\n");
        printf("'Eu mudei, Adrian. Nao sou mais a mesma pessoa.'\n");
        printf("\nNesse momento, passos apressados ecoam no corredor.\n");
        if (ajudouIrmao == 1) {
            printf("'Adrian, espere!', grita Lucian, seu irmao.\n");
            printf("'Ela salvou a mim e aos outros cavaleiros!'\n");
            printf("'Mesmo sabendo quem eramos, ela nos ajudou.'\n");
            printf("'Eu estaria morto se nao fosse por Evelynn.'\n");
        } else {
            printf("Um mensageiro chega trazendo relatos da vila.\n");
            printf("'Os moradores confirmam que a duquesa os ajudou.\n");
            printf("Ela tambem procurou recuperar nossas nascentes!'\n");
        }
        printf("\nAdrian olha para Kael e depois para voce.\n");
        printf("O dragao permanece ao seu lado por escolha propria.\n");
        printf("'Talvez eu estivesse lutando contra uma lembranca',\n");
        printf("Adrian admite, baixando a espada.\n");
        printf("\nVoces concordam em reparar os danos ao reino.\n");
        printf("Os canais de agua sao reabertos, e Kael passa\n");
        printf("a proteger as montanhas como um amigo de Valdoria.\n");
        printf("A amizade com Adrian pode, enfim, recomecar.\n");
        printf("\nVOCE VENCEU! O destino foi reescrito.\n");
    } else if (bondade >= 60) {
        printf("\n*** FINAL BOM: A VILA REDIMIDA ***\n");
        printf("\nAdrian hesita. Ele ouviu relatos de sua bondade,\n");
        printf("mas ainda se lembra dos anos de crueldade.\n");
        if (ajudouIrmao == 1) {
            printf("\nLucian entra no salao, apoiado em outro cavaleiro.\n");
            printf("'Irmao, Evelynn nos ajudou quando precisavamos.\n");
            printf("Ela nao pediu nada em troca. Eu vi com meus olhos.'\n");
        } else {
            printf("\nUm mensageiro confirma que voce ajudou moradores\n");
            printf("da vila e tentou reparar antigas injusticas.\n");
        }
        printf("\nAdrian abaixa a espada e olha para voce.\n");
        printf("'Nao posso apagar o que aconteceu. Mas posso\n");
        printf("permitir que voce prove que realmente mudou.'\n");
        printf("\nVoce continua viva e dedica sua nova chance\n");
        printf("a reconstruir as terras de Ravencrest.\n");
        printf("\nVOCE VENCEU! A bondade mudou seu destino.\n");
    } else if (dragaoAliado == 1) {
        printf("\n*** FINAL DO DRAGAO: ASAS DA LIBERDADE ***\n");
        printf("\nAdrian nao acredita que suas mudancas sejam reais.\n");
        printf("Ele avanca com a espada, decidido a mata-la.\n");
        printf("Kael sente o perigo e surge sobre o castelo.\n");
        desenharDragao();
        printf("\nO dragao abre as asas e bloqueia o ataque.\n");
        printf("Adrian recua diante do fogo, sem tempo de reagir.\n");
        printf("Voce sobe nas costas de Kael e escapa pelas nuvens.\n");
        printf("\nO reino ainda nao perdoou Evelynn, mas Kael\n");
        printf("permanece ao seu lado. Sua amizade salvou sua vida.\n");
        printf("\nVOCE VENCEU! Voce escapou com Kael.\n");
    } else {
        printf("\n*** FINAL RUIM: O DESTINO SE REPETE ***\n");
        printf("\nAdrian nao encontra motivos para confiar em voce.\n");
        printf("Nao ha dragao para protege-la nem provas suficientes\n");
        printf("de que Evelynn abandonou sua antiga crueldade.\n");
        printf("O heroi ergue a espada, e o salao fica em silencio.\n");
        printf("\nA ultima pagina do livro se cumpre como antes.\n");
        printf("GAME OVER! Talvez outras escolhas mudassem a historia.\n");
    }
    desenharCastelo();
    mostrarStatus();
}

int main() {
    int jogarNovamente = 1;
    int ordem[5] = {1, 2, 3, 4, 5};
    int i;
    while (jogarNovamente == 1) {
        bondade = 0;
        confianca = 0;
        dragaoAliado = 0;
        gameOver = 0;
        ajudouIrmao = 0;
        prologo();
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
        if (gameOver == 0) {
            finalJogo();
        } else {
            linha();
            printf("GAME OVER! Sua jornada terminou na caverna do dragao.\n");
            mostrarStatus();
        }
        printf("\nDeseja jogar novamente?\n1 - Sim\n2 - Nao\n");
        jogarNovamente = escolher(2);
    }
    printf("\nObrigada por jogar De Repente Vila!\n");
    return 0;
}
