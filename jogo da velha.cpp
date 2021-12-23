#include <stdio.h>
#include <stdlib.h>

const int linha = 3;
const int coluna = 5;
char xadrez [linha][coluna];

int tabuleiro();
void instrucoes();
int jogada1();
int jogada2();
int vencedor(int venceu);

int main()
{
    int resultado;
    tabuleiro();
    instrucoes();
    
    for(int i=0; i<9; i++)
    {
        resultado = i%2;
        if(resultado==0)
        {
            vencedor(jogada1());
        }
        else if(resultado==1)
        {
           vencedor(jogada2());
        }
    }

    return 0;
}

int tabuleiro()
{
    int resultado,i,u;
    //vai execultar como se fosse uma matriz
    for(i=0; i<linha; i++)
    {
        for(u=0; u<coluna; u++)
        {
            if(i==2)
            //na terceira e ultima linha ele vai adicionar espaço nas colunas de numero par
            //e pipe '|' par coluna de numero impar
            { 
                resultado = u % 2;
                
                if(resultado==0)
                {
                    xadrez[i][u] = ' ';
                }
                else if (resultado==1)
                {
                    xadrez[i][u] = '|';
                }
            }
            else
            //esse daqui vai para as duas primeiras linhas
            {
                resultado = u % 2;
                //se for par ele vai adicionar o anderline para representar as linhas
                //do jogo da velha, se for impar ele vai execultar as colunas
                //apois isso ele vai cair para if da linha 21
                if(resultado==1)
                { 
                    xadrez[i][u] = '|';
                }
                else if(resultado==0)
                { 
                    xadrez[i][u] = '_';
                }
            } 
        }
        printf("\n");
    }
    return 0;
}
 void instrucoes()
 {
    printf("\n1. As instrucoes sao simples, o programa vai sinalizar de quem e a vez");
    printf("\n2. Os jogadores precisam escolher antes de comecar quem vai ficar com 'x' ou 'o'");
    printf("\n3. O jogo vai dizer quem ganhou se foi 'x' ou 'o'");
    printf("\n4. O jogador precisara passar a coordenada de onde ele quer que o 'x' ou a 'o' fique");
    printf("\n4.1. por exemplo se ele passar '2 2' ele vai fixar a jogada no meio do xadrez");
    printf("\n4.2. PRIMEIRO vem a LINHA e SEGUNDO vem a COLUNA, nao esqueca");
    printf("\n---\\(>.<)/ BOM JOGO \\(>.<)/---");
    
 }

int jogada1()
{
    int linha1, coluna1;
    int i, n; //contadores for

    //jogada do jogador 1
    printf("\njogador 1 'o': ");
    scanf("%d %d", &linha1, &coluna1 );

    if(linha1>=3 || coluna1 >=5)
    {
        printf("\nmovimento invalido, tenten de novo");
        jogada1();
        
    }
    else
    {
        xadrez[linha1][coluna1] = 'O';

        //vai imprimir a jogada
        for(i=0; i<linha; i++)
        {
            for(n=0; n<coluna; n++)
            {
                printf("%c", xadrez[i][n]);
            }
            printf("\n");
        }
    }


    return 1;
}

int jogada2()
{
    int linha1, coluna1;
    int i, n; //contadores for

    //jogada do jogador 2
    printf("\njogador 2 'x': ");
    scanf("%d %d", &linha1, &coluna1);    

    if(linha1>=3 || coluna1 >=5)
    {
        printf("\nmovimento invalido, tenten de novo");
        jogada2();
    }
    else
    {
        xadrez[linha1][coluna1] = 'X';

        //vai imprimir a jogada feita
        for(i=0; i<linha; i++)
        {
            for(n=0; n<coluna; n++)
            {
                printf("%c", xadrez[i][n]);
            }
            printf("\n");
        }
    }
        
    return 2 ;
}

int vencedor(int venceu)
{
    if(//linhas
       (xadrez[0][0] =='O' && xadrez[0][2] =='O' && xadrez[0][4] =='O' ) ||
       (xadrez[1][0] =='O' && xadrez[1][2] =='O' && xadrez[1][4] =='O' ) ||
       (xadrez[2][0] =='O' && xadrez[2][2] =='O' && xadrez[2][4] =='O' ) ||
       //colunas
       (xadrez[0][0] =='O' && xadrez[1][0] =='O' && xadrez[2][0] =='O' ) ||
       (xadrez[0][2] =='O' && xadrez[1][2] =='O' && xadrez[2][2] =='O' ) ||
       (xadrez[0][4] =='O' && xadrez[1][4] =='O' && xadrez[2][4] =='O' ) ||
       //diagonais
       (xadrez[0][0] =='O' && xadrez[1][2] =='O' && xadrez[2][4] =='O' ) ||
       (xadrez[2][0] =='O' && xadrez[1][2] =='O' && xadrez[0][4] =='O' ) )
    {
        printf(" JOGADOR %d VENCEU!! \\(>u<)/", venceu);
        exit(0);
    }
    
    
    else if(
       // linha
       (xadrez[0][0] =='X' && xadrez[0][2] =='X' && xadrez[0][4] =='X' ) ||
       (xadrez[1][0] =='X' && xadrez[1][2] =='X' && xadrez[1][4] =='X' ) ||
       (xadrez[2][0] =='X' && xadrez[2][2] =='X' && xadrez[2][4] =='X' ) ||
       //colunas
       (xadrez[0][0] =='X' && xadrez[1][0] =='X' && xadrez[2][0] =='X' ) ||
       (xadrez[0][2] =='X' && xadrez[1][2] =='X' && xadrez[2][2] =='X' ) ||
       (xadrez[0][4] =='X' && xadrez[1][4] =='X' && xadrez[2][4] =='X' ) ||
       //diagonais
       (xadrez[0][0] =='X' && xadrez[1][2] =='X' && xadrez[2][4] =='X' ) ||
       (xadrez[2][0] =='X' && xadrez[1][2] =='X' && xadrez[0][4] =='X' ))
    {
        printf(" JOGADOR %d VENCEU!! \\(>u<)/", venceu);
        exit(0);
    }
    
    
    return 0 ;
}