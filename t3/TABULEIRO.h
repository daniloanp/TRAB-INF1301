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
        
        TAB_TipoCasaInicio ,

        TAB_TipoCasaFim ,
        
        TAB_TipoCasaChao,
        
        TAB_TipoCasaParede
    
    } TAB_TipoCasa ;

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

        TAB_CondRetTabuleiroValido ,
        /* Tabuleiro respeita as assertivas */

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

    TAB_tpCondRet TAB_CriarTabuleiro ( TAB_tppTabuleiro pTab , int altura , int largura , char* nome ) ;
    
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
*  $FC Fun��o: TAB &Pode ir pra cima
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

    TAB_tpCondRet TAB_PodeIrPraCima ( TAB_tppTabuleiro pTab );

/***********************************************************************
*
*  $FC Fun��o: TAB  &Pode ir pra esquerda
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

    TAB_tpCondRet TAB_PodeIrPraEsquerda ( TAB_tppTabuleiro pTab );

/***********************************************************************
*
*  $FC Fun��o: TAB  &Pode ir pra baixo
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

    TAB_tpCondRet TAB_PodeIrPraBaixo ( TAB_tppTabuleiro pTab );

/***********************************************************************
*
*  $FC Fun��o: TAB  &Pode ir pra direita
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

    TAB_tpCondRet TAB_PodeIrPraDireita ( TAB_tppTabuleiro pTab );

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

    TAB_tpCondRet TAB_AndarPraCima ( TAB_tppTabuleiro pTab );

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

    TAB_tpCondRet TAB_AndarPraDireita ( TAB_tppTabuleiro pTab );

/***********************************************************************
*
*  $FC Fun��o: TAB  &Alterar Casa
*
*  $ED Descri��o da fun��o
*     Altera o tipo da casa. 
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*     x - x da casa a ser modificada
*     y - y da casa a ser modificada
*     tipo - novo tipo da casa
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido; 
*
***********************************************************************/

    TAB_tpCondRet TAB_AlterarCasa ( TAB_tppTabuleiro pTab , int x , int y , TAB_TipoCasa tipo ) ;
    
/***********************************************************************
*
*  $FC Fun��o: TAB  &Visualizar Tabuleiro
*
*  $ED Descri��o da fun��o
*     Visualiza tabuleiro. 
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*     pMatriz - ponteiro para a matriz de caracteres
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido; 
*
***********************************************************************/

    TAB_tpCondRet TAB_VisualizarTabuleiro ( TAB_tppTabuleiro pTab , char*** pMatriz ) ;

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

    TAB_tpCondRet TAB_SalvarTabuleiro ( TAB_tppTabuleiro pTab , FILE* saida ) ;
        
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

    TAB_tpCondRet TAB_CarregarTabuleiro ( TAB_tppTabuleiro pTab, FILE* entrada ) ;
        
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

/***********************************************************************
*
*  $FC Fun��o: TAB  &GetTipoCasa
*
*  $ED Descri��o da fun��o
*     Da o tipo da casa referente as coordenadas (x,y)
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*     x - inteiro que representa a coordenada x
*     y - inteiro que representa a coordenada y
*     pTipo - ponteiro para o tipo da casa
*
*  $FV Valor retornado
*     TAB_CondRetOK - O tabuleiro � v�lido;
*     TAB_CondRetNaoEhCasa - As coordenadas explicitadas n�o pertencem ao tabuleiro;
*
***********************************************************************/

    TAB_tpCondRet TAB_GetTipoCasa ( TAB_tppTabuleiro pTab, int x , int y , TAB_TipoCasa* pTipo ) ;

#endif
