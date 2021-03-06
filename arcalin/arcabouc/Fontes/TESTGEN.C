/***************************************************************************
*  $MCI M�dulo de implementa��o: TGEN Teste espec�fico para o m�dulo teste gen�rico
*
*  Arquivo gerado:              TESTGEN.c
*  Letras identificadoras:      TGEN
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: C:\AUTOTEST\PROJETOS\ARCABOUC.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*     4       avs   01/fev/2006 criar linguagem script simb�lica
*     3       avs   08/dez/2004 uniformiza��o dos exemplos
*     2       avs   07/jul/2003 unifica��o de todos os m�dulos em um s� projeto
*     1       avs   16/abr/2003 in�cio desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include "TST_ESPC.H"

#include "GENERICO.H"
#include "LERPARM.H"

static const char ESPAC_CMD     [ ] = "=espaco"       ;
static const char BOOL_CMD      [ ] = "=compararbool" ;
static const char CHAR_CMD      [ ] = "=compararchar" ;
static const char INT_CMD       [ ] = "=compararint"  ;
static const char LONG_CMD      [ ] = "=compararlong" ;
static const char FLOAT_CMD     [ ] = "=compararfloat" ;
static const char STRING_CMD    [ ] = "=compararstring" ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TGEN &Testar m�dulo TesteGen
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     TesteGen
*
*     Comandos interpretados:
*
*     =compararbool  <bool esperado> <bool obtido>
*        bool:  0 => FALSE    !=0 => TRUE
*
*     =compararchar  <char esperado> <char obtido>
*        compara sens�vel a caixa e diacr�tico
*
*     =compararint   <int esperado>  <int obtido>
*
*     =compararlong  <long esperado  <long obtido>
*
*     =compararfloat <float esperado>  <float obtido>  <float tolerancia>
*         Vale se  1 - Tolerancia < Esperado / Obtido < 1 + Tolerancia
*
*     =compararstring <string esperado>  <string obtido>
*
*     =espaco        <espaco esperado>  <espaco obtido>
*         esperado deve estar entre aspas duplas
*         obtido inicia no primeiro n�o branco
*         valor  == .  sinaliza espa�o tamanho 0
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*     $P CondRetParm  - par�metro de retorno utilizado para retornar
*                       o valor da condi��o de retorno da fun��o testada
*                       Conter� -1 caso tenha sido observada uma falha
*                       e que n�o corresponda a uma condi��o de retorno
*                       definida em ARV_tpCondRet.
*
*  $FV Valor retornado
*     TST_CondRetOK
*     TST_CondRetNaoConhec
*     TST_CondRetParm
*     TST_CondRetErro      - a fun��o testada resultou em erro.
*                            Neste caso � poss�vel recuperar a falha,
*                            caso a condi��o de retorno fornecida via
*                            CondRetParm seja igual � condi��o esperada
*                            no comando =recuperar.
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int  NumLidos      = -1 ;

      int IntEsperado,
          IntObtido ;

      char CharEsperado,
           CharObtido ;

      long LongEsperado,
           LongObtido ;

      double FloatEsperado ,
             FloatObtido   ,
             Tolerancia     ;

      char StringEsperado[ 250 ] ,
           StringObtido[   250 ] ;

      char EspacEsperado[ 100 ] ;
      char EspacObtido[   100 ] ;

      /* Testar Booleano */

         if ( strcmp( ComandoTeste , BOOL_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                               &IntEsperado , &IntObtido ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            return TST_CompararBool( IntEsperado , IntObtido ,
                                     "Booleanos n�o s�o iguais." ) ;

         } /* fim ativa: Testar Booleano */

      /* Testar caractere */

         else if ( strcmp( ComandoTeste , CHAR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "cc" ,
                               &CharEsperado , &CharObtido ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            return TST_CompararChar( CharEsperado , CharObtido ,
                                     "Caracteres n�o s�o iguais." ) ;

         } /* fim ativa: Testar caractere */

      /* Testar inteiro normal */

         else if ( strcmp( ComandoTeste , INT_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                               &IntEsperado , &IntObtido ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            return TST_CompararInt( IntEsperado , IntObtido ,
                                    "Inteiros n�o s�o iguais." ) ;

         } /* fim ativa: Testar inteiro normal */

      /* Testar inteiro longo */

         else if ( strcmp( ComandoTeste , LONG_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                               &LongEsperado , &LongObtido ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            return TST_CompararInt( LongEsperado , LongObtido ,
                                    "Inteiros longos n�o s�o iguais." ) ;

         } /* fim ativa: Testar inteiro longo */

      /* Testar flutuante */

         else if ( strcmp( ComandoTeste , FLOAT_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "fff" ,
                               &FloatEsperado , &FloatObtido , &Tolerancia ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            return TST_CompararFloat( FloatEsperado , FloatObtido , Tolerancia ,
                                      "Flutuantes fora da toler�ncia." ) ;

         } /* fim ativa: Testar flutuante */

      /* Testar string */

         else if ( strcmp( ComandoTeste , STRING_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ss" ,
                               StringEsperado , StringObtido ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            return TST_CompararString( StringEsperado , StringObtido ,
                                       "Strings n�o s�o iguais." ) ;

         } /* fim ativa: Testar string */

      /* Testar acesso a espa�os */

         else if ( strcmp( ComandoTeste , ESPAC_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ss" ,
                               EspacEsperado , EspacObtido ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            if ( EspacEsperado[ 0 ] == '.' )   /* gera string vazio */
            {
               EspacEsperado[ 0 ] = 0 ;
            } /* if */

            if ( EspacObtido[ 0 ] == '.' )     /* gera string com algum lixo */
            {
               memcpy( EspacObtido , &NumLidos , 20 ) ; /* for�a espaco errado contendo res�duo da pilha */
            } /* if */

            return TST_CompararEspaco( EspacEsperado , EspacObtido ,
                                       strlen( EspacEsperado ) ,
                                       "Espa�os n�o s�o iguais." ) ;

         } /* fim ativa: Testar acesso a espa�os */

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TGEN &Testar m�dulo TesteGen */

/********** Fim do m�dulo de implementa��o: TGEN Teste espec�fico para o m�dulo teste gen�rico **********/

