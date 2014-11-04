#if ! defined( TABULEIRO_ )
#define TABULEIRO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: TAB Tabuleiro de labirinto
*
*  Arquivo gerado:              TABULEIRO.h
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\Tabuleiro.BSW
*
*  Projeto: INF 1301 / Labirinto
*  Gestor:  LSKDANEAV
*  Autores: eav
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*		 1	   eav	 20/10/2014		//
*
*  $ED Descri��o do m�dulo
*
***************************************************************************/

#if defined( TABULEIRO_OWN )
   #define TABULEIRO_EXT
#else
   #define TABULEIRO_EXT extern
#endif

#include "GRAFO.h"

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para um tabuleiro */

typedef struct TAB_tpTabuleiro_* TAB_tppTabuleiro ;

/***********************************************************************
*
*  $TC Tipo de dados: TAB Tipo da casa
*
*  $ED Descri��o do tipo
*     Representa se a casa � inicio, fim, ch�o ou parede
*
***********************************************************************/

    typedef enum {
        
        TAB_tpCasaInicio ,

        TAB_tpCasaFim ,
        
        TAB_tpCasaChao,
        
        TAB_tpCasaParede
    
    } TAB_tpCasa ;

/***********************************************************************
*
*  $TC Tipo de dados: TAB Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do tabuleiro
*
***********************************************************************/

    typedef enum {

        TAB_CondRetOK ,
        /* Concluiu corretamente */
				
        TAB_CondRetFaltouMemoria ,
        /* Faltou mem�ria */

        TAB_CondRetNaoEhCasa ,
        /* A casa explicitada nao pertence ao tabuleiro */

        TAB_CondRetMovimentoInvalido ,
        /* Movimento inv�lido */

        TAB_CondRetAlteracaoInvalida , 
        /* Altera��o do valor ( vazio/parede/inicio/fim ) inv�lida */

        TAB_CondRetTabuleiroInvalido ,
        /* Tabuleiro viola as assertivas */

        TAB_CondRetSemSolucao
        /* Tabuleiro n�o tem solu��o */

    } TAB_tpCondRet ;
    
/***********************************************************************
*
*  $FC Fun��o: GRA  &Criar Tabuleiro
*
*  $ED Descri��o da fun��o
*     Cria um Tabuleiro para labirinto, implementado com um grafo gen�rico.
*     O Tabuleiro � implementado com um grafo de tipo homog�neo 
*     gen�rico n�o direcionado sem peso nas arestas. 
*
*  $EP Par�metros
*     Altura - inteiro que representa o tamanho vertical do tabuleiro.
*     Largura - inteiro que representa o tamanho horizontal do tabuleiro.
*
*  $FV Valor retornado
*     GRA_CondRetOK - criou o tabuleiro sem problemas
*     GRA_CondRetFaltouMemoria - faltou memoria ao criar o tabuleiro
*
***********************************************************************/

    TAB_tpCondRet TAB_CriarTabuleiro ( TAB_tppTabuleiro* pTab , int altura , int largura , char* nome ) ;
    
/***********************************************************************
*
*  $FC Fun��o: GRA  &Destruir Tabuleiro
*
*  $ED Descri��o da fun��o
*     Destroi o tabuleiro
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*
*  $FV Valor retornado
*     GRA_CondRetOK - criou o tabuleiro sem problemas
*     GRA_CondRetFaltouMemoria - faltou memoria ao criar o tabuleiro
*
***********************************************************************/

    TAB_tpCondRet TAB_DestruirTabuleiro ( TAB_tppTabuleiro pTab ) ;

/***********************************************************************
*
*  $FC Fun��o: TAB &Pode andar pra cima
*
*  $ED Descri��o da fun��o
*     Valida a possibilidade de um movimento para o norte.
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*
*  $FV Valor retornado
*     TAB_CondRetOK - O movimento � v�lido; 
*     TAB_CondRetMovimentoInvalido - O movimento � inv�lido; 
*
***********************************************************************/

    TAB_tpCondRet TAB_PodeAndarPraCima ( TAB_tppTabuleiro pTab , int colisao );

/***********************************************************************
*
*  $FC Fun��o: TAB  &Pode andar pra esquerda
*
*  $ED Descri��o da fun��o
*     Valida a possibilidade de um movimento. 
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*
*  $FV Valor retornado
*     TAB_CondRetOK - O movimento � v�lido; 
*     TAB_CondRetMovimentoInvalido - O movimento � inv�lido; 
*
***********************************************************************/

    TAB_tpCondRet TAB_PodeAndarPraEsquerda ( TAB_tppTabuleiro pTab , int colisao );

/***********************************************************************
*
*  $FC Fun��o: TAB  &Pode andar pra baixo
*
*  $ED Descri��o da fun��o
*     Valida a possibilidade de um movimento. 
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*
*  $FV Valor retornado
*     TAB_CondRetOK - O movimento � v�lido; 
*     TAB_CondRetMovimentoInvalido - O movimento � inv�lido; 
*
***********************************************************************/

    TAB_tpCondRet TAB_PodeAndarPraBaixo ( TAB_tppTabuleiro pTab , int colisao );

/***********************************************************************
*
*  $FC Fun��o: TAB  &Pode andar pra direita
*
*  $ED Descri��o da fun��o
*     Valida a possibilidade de um movimento. 
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*
*  $FV Valor retornado
*     TAB_CondRetOK - O movimento � v�lido; 
*     TAB_CondRetMovimentoInvalido - O movimento � inv�lido; 
*
***********************************************************************/

    TAB_tpCondRet TAB_PodeAndarPraDireita ( TAB_tppTabuleiro pTab , int colisao );

/***********************************************************************
*
*  $FC Fun��o: TAB &Andar pra cima
*
*  $ED Descri��o da fun��o
*     Muda o corrente para o vizinho ao norte dele.
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*
*  $FV Valor retornado
*     TAB_CondRetOK - O movimento � v�lido; 
*
***********************************************************************/

    TAB_tpCondRet TAB_AndarPraCima ( TAB_tppTabuleiro pTab  );

/***********************************************************************
*
*  $FC Fun��o: TAB  &Andar pra esquerda
*
*  $ED Descri��o da fun��o
*     Muda o corrente para o vizinho ao oeste dele. 
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*
*  $FV Valor retornado
*     TAB_CondRetOK - O movimento � v�lido; 
*
***********************************************************************/

    TAB_tpCondRet TAB_AndarPraEsquerda ( TAB_tppTabuleiro pTab );

/***********************************************************************
*
*  $FC Fun��o: TAB  &Andar pra baixo
*
*  $ED Descri��o da fun��o
*     Muda o corrente para o vizinho ao sul dele.
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*
*  $FV Valor retornado
*     TAB_CondRetOK - O movimento � v�lido; 
*
***********************************************************************/

    TAB_tpCondRet TAB_AndarPraBaixo ( TAB_tppTabuleiro pTab );

/***********************************************************************
*
*  $FC Fun��o: TAB  &Andar pra direita
*
*  $ED Descri��o da fun��o
*     Muda o corrente para o vizinho ao leste dele. 
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*
*  $FV Valor retornado
*     TAB_CondRetOK - O movimento � v�lido;
*
***********************************************************************/

    TAB_tpCondRet TAB_AndarPraDireita ( TAB_tppTabuleiro pTab  );

/***********************************************************************
*
*  $FC Fun��o: TAB  &Poe Chao
*
*  $ED Descri��o da fun��o
*     Altera o tipo da casa para chao
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido; 
*     TAB_CondRetFaltouMemoria - ;
*     TAB_CondRetAlteracaoInvalida - ;
*
***********************************************************************/

    TAB_tpCondRet TAB_PoeChao ( TAB_tppTabuleiro pTab ) ;
 
/***********************************************************************
*
*  $FC Fun��o: TAB  &Poe Parede
*
*  $ED Descri��o da fun��o
*     Altera o tipo da casa para parede
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido; 
*     TAB_CondRetFaltouMemoria - ;
*     TAB_CondRetAlteracaoInvalida - ;
*
***********************************************************************/

    TAB_tpCondRet TAB_PoeParede ( TAB_tppTabuleiro pTab ) ;
 
/***********************************************************************
*
*  $FC Fun��o: TAB  &Poe Inicio
*
*  $ED Descri��o da fun��o
*     Altera o tipo da casa para inicio
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido; 
*     TAB_CondRetFaltouMemoria - ;
*     TAB_CondRetAlteracaoInvalida - ;
*
***********************************************************************/

    TAB_tpCondRet TAB_PoeInicio ( TAB_tppTabuleiro pTab ) ;
 
/***********************************************************************
*
*  $FC Fun��o: TAB  &Poe Fim
*
*  $ED Descri��o da fun��o
*     Altera o tipo da casa para fim
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido; 
*     TAB_CondRetFaltouMemoria - ;
*     TAB_CondRetAlteracaoInvalida - ;
*
***********************************************************************/

    TAB_tpCondRet TAB_PoeFim ( TAB_tppTabuleiro pTab ) ;
 
/***********************************************************************
*
*  $FC Fun��o: TAB  &Get Tipo Casa
*
*  $ED Descri��o da fun��o
*     Da o tipo (ch�o, parede, inicio ou fim) da casa representada por (x,y). 
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*     x - x da casa a ser modificada
*     y - y da casa a ser modificada
*     tipo - ponteiro para o tipo da casa
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido;
*     TAB_CondRetNaoEhCasa - O tabuleiro n�o possuia uma casa representada por (x,y)
*
***********************************************************************/   

    TAB_tpCondRet TAB_GetTipoCasa ( TAB_tppTabuleiro pTab, int x , int y , TAB_tpCasa* tipo ) ;

/***********************************************************************
*
*  $FC Fun��o: TAB  &Get Altura
*
*  $ED Descri��o da fun��o
*     Da a altura do tabuleiro.
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*     altura - ponteiro para a altura
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido;
*
***********************************************************************/   

    TAB_tpCondRet TAB_GetAltura ( TAB_tppTabuleiro pTab, int* altura ) ;

/***********************************************************************
*
*  $FC Fun��o: TAB  &Get Largura
*
*  $ED Descri��o da fun��o
*     Da a largura do tabuleiro.
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*     largura - ponteiro para a largura
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido;
*
***********************************************************************/   

    TAB_tpCondRet TAB_GetLargura ( TAB_tppTabuleiro pTab, int* largura ) ;

/***********************************************************************
*
*  $FC Fun��o: TAB  &Validar Tabuleiro
*
*  $ED Descri��o da fun��o
*     Valida o tabuleiro. 
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido; 
*
***********************************************************************/

    TAB_tpCondRet TAB_ValidarTabuleiro ( TAB_tppTabuleiro pTab ) ;
    
/***********************************************************************
*
*  $FC Fun��o: TAB  &Salvar Tabuleiro
*
*  $ED Descri��o da fun��o
*     Salva o tabuleiro em um arquivo.
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*     saida - ponteiro para o arquivo aonde o tabuleiro vai ser salvo
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido; 
*
***********************************************************************/

    TAB_tpCondRet TAB_SalvarTabuleiro ( TAB_tppTabuleiro pTab , char* saida ) ;
        
/***********************************************************************
*
*  $FC Fun��o: TAB  &Carregar Tabuleiro
*
*  $ED Descri��o da fun��o
*     Carrega o tabuleiro de um arquivo.
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*     entrada - ponteiro para o arquivo de onde o tabuleiro vai ser lido
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido; 
*
***********************************************************************/

    TAB_tpCondRet TAB_CarregarTabuleiro ( TAB_tppTabuleiro pTab, char* entrada ) ;
        
/***********************************************************************
*
*  $FC Fun��o: TAB  &Solucionar Tabuleiro
*
*  $ED Descri��o da fun��o
*     Soluciona o tabuleiro. A solu��o � retornada em uma string de caracteres.
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*     pSolucao - ponteiro para a cadeia de caracteres que representa a solu��o
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido;
*     TAB_CondRetSemSolucao - O tabuleiro n�o possui solu��o;
*
***********************************************************************/

    TAB_tpCondRet TAB_SolucionarTabuleiro ( TAB_tppTabuleiro pTab, char* pSolucao ) ;    

/***********************************************************************
*
*  $FC Fun��o: TAB  &Posicao do Jogador
*
*  $ED Descri��o da fun��o
*     Da a posi��o (x,y) do jogador no tabuleiro.
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*     pX - ponteiro para inteiro que representa a coordenada X do jogador
*     pY - ponteiro para inteiro que representa a coordenada Y do jogador
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido;
*
***********************************************************************/

    TAB_tpCondRet TAB_PosicaoJogador ( TAB_tppTabuleiro pTab , int* x , int* y ) ;        

#endif
