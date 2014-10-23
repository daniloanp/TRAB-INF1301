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

typedef struct TAB_tppTabuleiro_* TAB_tppTabuleiro ;

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

        TAB_CondRetMovimentoInvalido ,
        /* Movimento inv�lido */

        TAB_CondRetAlteracaoInvalida 
        /* Altera��o do valor ( vazio/parede/inicio/fim ) inv�lida */

    } TAB_tpCondRet ;

/***********************************************************************
*
*  $FC Fun��o: GRA  &Criar Tabuleiro
*
*  $ED Descri��o da fun��o
*     Cria um Tabuleiro para labirinto, implementado com um grafo gen�rico.
*     
*     O tabuleiro implementa um grafo de casas.
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
*  $FC Fun��o: GRA  &Valida Movimento
*
*  $ED Descri��o da fun��o
*     Valida a possibilidade de um movimento. 
*     Caso a id passada seja igual a uma das ids correspondentes as dire��es (N,S,L,O) do v�rtice corrente,
*     o movimento � v�lido.
*
*  $EP Par�metros
*     pTab - ponteiro para o tabuleiro
*     idProximo - inteiro que representa o id do v�rtice de destino
*
*  $FV Valor retornado
*     GRA_CondRetOK - O movimento era v�lido; o v�rtice de destino � vizinho do corrente
*     GRA_CondRetMovimentoInvalido - O movimento era inv�lido; os v�rtices n�o s�o vizinhos ou o v�rtice de destino n�o existe;
*
***********************************************************************/

    TAB_tpCondRet TAB_ValidaMovimento ( TAB_tppTabuleiro pTab , int idProximo ) ;

#endif