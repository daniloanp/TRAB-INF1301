/***************************************************************************
*  $MCI M�dulo de implementa��o: TEST Teste Tabuleiro para labirinto
*
*  Arquivo gerado:              TESTESTADO.c
*  Letras identificadoras:      TEST
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\ESTADO.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: eav
*
*  $HA Hist�rico de evolu��o:
*     1       eav   5/nov/2014 in�cio desenvolvimento
*
***************************************************************************/


#include <string.h>
#include <stdio.h>
#include <malloc.h>

#include    "TST_ESPC.H"

#include    "GENERICO.H"
#include    "LERPARM.H"

#include    "ESTADO.h"

    static const char RESET_ESTADO_CMD         [] = "=resetteste"         ;
    static const char CRIA_ESTADO_CMD          [] = "=criaestado"         ;
    static const char DESTRUIR_ESTADO_CMD      [] = "=destruirestado"     ;
    static const char GET_MENUS_CMD            [] = "=getmenus"           ;
    static const char GET_TABULEIRO_CMD        [] = "=gettabuleiro"       ;

int estaInicializado = 0 ;

#define DIM_VT_ESTADOS   10
#define DIM_VALOR 4

EST_tppEstado vtRefEstados[ DIM_VT_ESTADOS ] ;


/***** Prot�tipos das fun��es encapuladas no m�dulo *****/
   
    static int VerificarInx( int inxEstado );

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***********************************************************************
*
*  $FC Fun��o: TLIS &Testar estado
*
*  $ED Descri��o da fun��o
*     Podem ser criadas at� 10 estados, identificadas pelos �ndices 0 a 10
*
*     Comandos dispon�veis:
*
*     =resetteste
*           - anula o vetor de estados Provoca vazamento de mem�ria
*     =criarestado            inxEstado  CondRetEsp
*     =destruirestado         inxEstado  CondRetEsp
*     =getmenus               inxEstado  CondRetEsp
*     =gettabuleiro           inxEstado  CondRetEsp
*
*
***********************************************************************/


TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
    {
        EST_tpCondRet CondRetObtida = EST_CondRetOK ;
        EST_tpCondRet CondRetEsperada = EST_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */
        MEN_tppMenus menu;
        TAB_tppTabuleiro tabuleiro;
        int i;
        int inxEstado = -1;
        int NumLidos = -1;

        /* Tratar: inicializar contexto */
      
        if ( strcmp( ComandoTeste , RESET_ESTADO_CMD ) == 0 ){

        if ( estaInicializado ){
            for( i = 0 ; i < DIM_VT_ESTADOS ; i++ ){
                EST_DestruirEstado( ( vtRefEstados[ i ] )) ;
            }
        }

        for( i = 0 ; i < DIM_VT_ESTADOS ; i++ ){
            vtRefEstados[ i ] = 0 ;
        }

        estaInicializado = 1 ;

        } /* fim ativa: Tratar: inicializar contexto */
      
        /* Testar EST Criar estado */         
        else if ( strcmp( ComandoTeste , CRIA_ESTADO_CMD ) == 0 )
        {
            NumLidos = LER_LerParametros("ii",&inxEstado,&CondRetEsperada);
            if((NumLidos != 2) || !VerificarInx(inxEstado))
            {
                return TST_CondRetParm;
            }
            printf("\n\ninx = %d\n\n",inxEstado);
            CondRetObtida = EST_CriaEstado( vtRefEstados[inxEstado] );
            return TST_CompararInt( CondRetEsperada , CondRetObtida , "Retorno errado ao criar estado." );
        } /* fim ativa: Testar EST Criar estado */
            
        /* Testar EST Destruir estado */
        else if ( strcmp( ComandoTeste , DESTRUIR_ESTADO_CMD ) == 0 )
        {
            NumLidos = LER_LerParametros("ii",&inxEstado,&CondRetEsperada);
            if((NumLidos != 2) || !VerificarInx(inxEstado))
            {
                return TST_CondRetParm;
            }

            CondRetObtida = EST_DestruirEstado( vtRefEstados[inxEstado] );
            return TST_CompararInt( CondRetEsperada , CondRetObtida , "Retorno errado ao criar estado." );
        } /* fim ativa: Testar EST Destruir estado */
                    
        /* Testar EST Get Menus */
        else if ( strcmp( ComandoTeste , GET_MENUS_CMD ) == 0 )
        {
            NumLidos = LER_LerParametros("ii",&inxEstado,&CondRetEsperada);
            if((NumLidos != 2) || !VerificarInx(inxEstado))
            {
                return TST_CondRetParm;
            }

            MEN_CriarMenus(&menu);

            CondRetObtida = EST_GetMenus( vtRefEstados[inxEstado],menu);
            return TST_CompararInt( CondRetEsperada , CondRetObtida , "Retorno errado ao obter os menus." );
        } /* fim ativa: Testar EST Get Menus */

        /* Testar EST Get Tabuleiro */
        else if ( strcmp( ComandoTeste , GET_TABULEIRO_CMD ) == 0 )
        {
            NumLidos = LER_LerParametros("ii",&inxEstado,&CondRetEsperada);
            if((NumLidos != 2) || !VerificarInx(inxEstado))
            {
                return TST_CondRetParm;
            }

            TAB_CriarTabuleiro(&tabuleiro,DIM_VALOR,DIM_VALOR,"tabuleiro");

            CondRetObtida = EST_GetTabuleiro( vtRefEstados[inxEstado],tabuleiro);
            return TST_CompararInt( CondRetEsperada , CondRetObtida , "Retorno errado ao obter o tabuleiro." );
        } /* fim ativa: Testar EST Get Tabuleiro */
        return TST_CondRetNaoConhec ;  
    }

   
   /*****  C�digo das fun��es encapsuladas no m�dulo  *****/
   
/***********************************************************************
*
*  $FC Fun��o: TEST -Verificar �ndice de estado
*
*  $FV Valor retornado
*     0 - inxEstado n�o vale
*     1 - inxEstado vale
*
***********************************************************************/

   int VerificarInx( int inxEstado)
   {

      if ( ( inxEstado <   0 )
        || ( inxEstado >= DIM_VT_ESTADOS ))
      {
         return 0 ;
      } /* if */

      return 1 ;

   } /* Fim fun��o: TEST -Verificar �ndice de estado */