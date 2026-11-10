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
