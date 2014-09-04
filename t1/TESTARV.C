/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              TESTARV.C
*  Letras identificadoras:      TARV
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: dan - Danilo Andr� Nascimento
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*      01      dan    02/09/14
*  $ED Descri��o do m�dulo
*     Este m�odulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo �rvore. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo �rvore:
*
*     =criar        - chama a fun��o ARV_CriarArvore( )
*     =insdir <Char>
*                   - chama a fun��o ARV_InserirDireita( <Char> )
*                     Obs. nota��o: <Char>  � o valor do par�metro
*                     que se encontra no comando de teste.
*
*     "=insesq" <Char>
*                   - chama a fun��o ARV_InserirEsquerda( <Char> )
*     "=irpai"      - chama a fun��o ARV_IrPai( )
*     "=iresq"      - chama a fun��o ARV_IrEsquerda( )
*     "=irdir"      - chama a fun��o ARV_IrDireita( )
*     "=obter" <Char>
*                   - chama a fun��o ARV_ObterValorCorr( ) e compara
*                     o valor retornado com o valor <Char>
*     "=destroi"    - chama a fun��o ARV_DestruirArvore( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "GENERICO.H"
#include    "LERPARM.H"

#include    "ARVORE.H"
#include    "LISTA.H"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_ARV_CMD       "=criar"
#define     INS_DIR_CMD         "=insdir"
#define     INS_ESQ_CMD         "=insesq"
#define     IR_PAI_CMD          "=irpai"
#define     IR_ESQ_CMD          "=iresq"
#define     IR_DIR_CMD          "=irdir"
#define     OBTER_VAL_CMD       "=obter"
#define     DESTROI_CMD         "=destruir"

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TARV Efetuar opera��es de teste espec�ficas para �rvore
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     �rvore sendo testado.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

#define NUM_ARVORES 12
#define TAM_STR_TESTE 255


// Inicia arvores locais como NULL
static ARV_tppArvore arvores[NUM_ARVORES] = {
   NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL // Deselegante mas pr�tico.
};


// Fun��o auxiliar que cria uma lista de caracteres a partir de um vetor de caracteres terminado com '\0'
   static void preencheListaComString(LIS_tppLista lista, char* str) {
      for (str; *str; str++) {
         LIS_InserirElementoApos(lista, *str);
         LIS_AvancarElementoCorrente(lista, 1);
      }
   }

   static TST_tpCondRet comparaListaComString(LIS_tppLista lista, char* str) {
      if(lista != NULL) {
         IrInicioLista(lista);

         for (str; *str; str++) {
            if (LIS_ObterValor(lista) != *str) {
               return TST_CondRetErro;
            }
            LIS_AvancarElementoCorrente(lista, 1);
         }
      }
      return (*str == '\0') ? TST_CondRetOK : TST_CondRetErro; //Se nulo, string acabou e � igual. Se n�o � diferente.
   }

   static TST_tpCondRet preencheStringComLista(LIS_tppLista lista, char* str) {
      if(lista == NULL) {
         str[0]='\0';
         return TST_CondRetOK;
      }
      IrInicioLista(lista);
      do {
         *str = LIS_ObterValor(lista);
         str++;
      }while (LIS_AvancarElementoCorrente(lista,1) != LIS_CondRetFimLista);
      *str = '\0';
      return TST_CondRetOK;
   }
   

// Seta arvore ok como nula

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {
      char str[TAM_STR_TESTE]; //Vetor de Caracteres tempor�rio utilizado para ler outros
      char str_[TAM_STR_TESTE]; //Vetor de Caracteres tempor�rio utilizado para ler outros

      ARV_tpCondRet CondRetObtido   = ARV_CondRetOK ;
      ARV_tpCondRet CondRetEsperada = ARV_CondRetFaltouMemoria ;

      int arvindex = -1;

      //char ValorEsperado = '?'  ;
      //char ValorObtido   = '!'  ;
      LIS_tppLista ListaObtida = NULL;
      LIS_tppLista ListaDada = NULL;
      //char ValorDado     = '\0' ;

      int  NumLidos = -1 ;

      TST_tpCondRet Ret ;

      /* Testar ARV Criar �rvore */

         if ( strcmp( ComandoTeste , CRIAR_ARV_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                               &arvindex, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = ARV_CriarArvore( (arvores+arvindex) ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar �rvore." );

         } /* fim ativa: Testar ARV Criar �rvore */

      /* Testar ARV Adicionar filho � direita */

         else if ( strcmp( ComandoTeste , INS_DIR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isi" ,
                               &arvindex, str , &CondRetEsperada ) ;
            
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            ListaDada = LIS_CriarLista( );
            preencheListaComString(ListaDada, str);
            

            CondRetObtido = ARV_InserirDireita( arvores[arvindex], ListaDada ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado inserir �a direita." );

         } /* fim ativa: Testar ARV Adicionar filho � direita */

      /* Testar ARV Adicionar filho � esquerda */

         else if ( strcmp( ComandoTeste , INS_ESQ_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isi" ,
                               &arvindex,  &str , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm;
            } /* if */

            ListaDada = LIS_CriarLista( );
            preencheListaComString(ListaDada, str);
            
            CondRetObtido = ARV_InserirEsquerda( arvores[arvindex], ListaDada ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao inserir � esquerda." );

         } /* fim ativa: Testar ARV Adicionar filho � esquerda */

      /* Testar ARV Ir para n� pai */

         else if ( strcmp( ComandoTeste , IR_PAI_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                              &arvindex, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = ARV_IrPai( arvores[arvindex] ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para pai." );

         } /* fim ativa: Testar ARV Ir para n� pai */

      /* Testar ARV Ir para n� � esquerda */

         else if ( strcmp( ComandoTeste , IR_ESQ_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                              &arvindex, &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = ARV_IrNoEsquerda( arvores[arvindex] ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para esquerda." );

         } /* fim ativa: Testar ARV Ir para n� � esquerda */

      /* Testar ARV Ir para n� � direita */

         else if ( strcmp( ComandoTeste , IR_DIR_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" ,
                              &arvindex,  &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = ARV_IrNoDireita( arvores[arvindex] ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para direita." );

         } /* fim ativa: Testar ARV Ir para n� � direita */

      /* Testar ARV Obter valor corrente */

         else if ( strcmp( ComandoTeste , OBTER_VAL_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "isi" ,
                              &arvindex,
                              &str,
                              &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = ARV_ObterValorCorr( arvores[arvindex], &ListaObtida ) ;
            
            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter valor corrente." );

            if ( Ret != TST_CondRetOK || CondRetObtido != ARV_CondRetOK ) // RET != 0
            {
               return Ret;
            } /* if */

			   Ret = comparaListaComString( ListaObtida , str );
            preencheStringComLista(ListaObtida, str_);

            return TST_CompararString( str , str_ ,
                                     "Conte�do do n� est� errado." ) ;

         } /* fim ativa: Testar ARV Obter valor corrente */

      /* Testar ARV Destruir �rvore */

         else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {
            NumLidos = LER_LerParametros( "i" ,
                              &arvindex ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */
               
            ARV_DestruirArvore( (arvores+arvindex) ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar ARV Destruir �rvore */

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TARV Efetuar opera��es de teste espec�ficas para �rvore */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/
