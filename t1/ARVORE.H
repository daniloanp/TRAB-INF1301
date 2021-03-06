#if ! defined( ARVORE_ )
#define ARVORE_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo �rvore
*
*  Arquivo gerado:              ARVORE.H
*  Letras identificadoras:      ARV
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: eav,lsk - Eduardo Alberto Verdeja & Leonardo Slipoi Kaplan
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       01   eav,lsk  02/09/14  
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa um conjunto simples de fun��es para criar e
*     explorar �rvores bin�rias.
*     A �rvore possui uma cabe�a que cont�m uma refer�ncia para a ra�z da
*     �rvore e outra para um n� corrente da �rvore.
*     Ao iniciar a execu��o do programa n�o existe �rvore.
*     A �rvore poder� estar vazia. Neste caso a raiz e o n� corrente
*     ser�o nulos, embora a cabe�a esteja definida.
*     O n� corrente ser� nulo se e somente se a �rvore estiver vazia.
*     Ao inserir um n� � esquerda ou � direita, o m�dulo tentar� inserir antes no n� corrente.
***************************************************************************/
 
#if defined( ARVORE_OWN )
   #define ARVORE_EXT
#else
   #define ARVORE_EXT extern
#endif


/* Tipo refer�ncia para uma lista */

typedef struct tgArvore* ARV_tppArvore;


/***********************************************************************
*
*  $TC Tipo de dados: ARV Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {

         ARV_CondRetOK = 0 ,
               /* Executou correto */

         ARV_CondRetNaoCriouRaiz = 1 ,
               /* N�o criou n� raiz */

         ARV_CondRetErroEstrutura = 2 ,
               /* Estrutura da �rvore est� errada */

         ARV_CondRetNaoEhFolha = 3 ,
               /* N�o � folha relativa � dire��o de inser��o desejada */

         ARV_CondRetArvoreNaoExiste = 4 ,
               /* �rvore n�o existe */

         ARV_CondRetArvoreVazia = 5 ,
               /* �rvore est� vazia */

         ARV_CondRetNohEhRaiz = 6 ,
               /* N� corrente � raiz */

         ARV_CondRetNaoPossuiFilho = 7 ,
               /* N� corrente n�o possui filho na dire��o desejada */

         ARV_CondRetFaltouMemoria = 8
               /* Faltou mem�ria ao alocar dados */

   } ARV_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: ARV Criar �rvore
*
*  $ED Descri��o da fun��o
*     Cria uma nova �rvore vazia.
*
*  $EP Par�metros
*     $P ppArvoreParm - ponteiro para �rvore a ser criada
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetFaltouMemoria
*
***********************************************************************/

   ARV_tpCondRet ARV_CriarArvore( ARV_tppArvore* ppArvoreParm ) ;


/***********************************************************************
*
*  $FC Fun��o: ARV Destruir �rvore
*
*  $EP Par�metros
*     $P ppArvoreParm - ponteiro para �rvore a ser criada
*
*  $ED Descri��o da fun��o
*     Destr�i o corpo e a cabe�a da �rvore, anulando a �rvore corrente.
*     Faz nada caso a �rvore corrente n�o exista.
*
***********************************************************************/

   void ARV_DestruirArvore( ARV_tppArvore* ppArvoreParm ) ;


/***********************************************************************
*
*  $FC Fun��o: ARV Adicionar filho � esquerda
*
*  $EP Par�metros
*     $P ListaCharParm - lista a ser inserida no novo n�.
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetErroEstrutura
*     ARV_CondRetFaltouMemoria
*     ARV_CondRetNaoEhFolha     - caso n�o seja folha para a esquerda
*
***********************************************************************/

   ARV_tpCondRet ARV_InserirEsquerda( ARV_tppArvore pArvoreParm, void* ListaCharParm ) ;


/***********************************************************************
*
*  $FC Fun��o: ARV Adicionar filho � direita
*
*  $EP Par�metros
*     $P ListaCharParm - lista a ser inserida no novo n�.
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetErroEstrutura
*     ARV_CondRetFaltouMemoria
*     ARV_CondRetNaoEhFolha     - caso n�o seja folha para a direita
*
***********************************************************************/

   ARV_tpCondRet ARV_InserirDireita( ARV_tppArvore pArvoreParm, void* ListaCharParm ) ;


/***********************************************************************
*
*  $FC Fun��o: ARV Ir para n� pai
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetArvoreVazia
*     ARV_CondRetNoEhRaiz
*
***********************************************************************/

   ARV_tpCondRet ARV_IrPai( ARV_tppArvore pArvoreParm ) ;


/***********************************************************************
*
*  $FC Fun��o: ARV Ir para n� � esquerda
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetArvoreVazia
*     ARV_CondRetNaoPossuiFilho   - n� corrente n�o possui filho � esquerda
*
***********************************************************************/

   ARV_tpCondRet ARV_IrNoEsquerda( ARV_tppArvore pArvoreParm ) ;


/***********************************************************************
*
*  $FC Fun��o: ARV Ir para n� � direita
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetArvoreVazia
*     ARV_CondRetNaoPossuiFilho   - n� corrente n�o possui filho � direita
*
***********************************************************************/

   ARV_tpCondRet ARV_IrNoDireita( ARV_tppArvore pArvoreParm ) ;


/***********************************************************************
*
*  $FC Fun��o: ARV Obter lista no n� corrente
*
*  $EP Par�metros
*     $P ListaCharParm - � o par�metro que receber� o endere�o da lista contida no n�.
*                    Este par�metro � passado por refer�ncia.
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetArvoreNaoExiste
*     ARV_CondRetArvoreVazia
*
***********************************************************************/

   ARV_tpCondRet ARV_ObterValorCorr( ARV_tppArvore pArvoreParm, void* ListaCharParm ) ;

#undef ARVORE_EXT

/********** Fim do m�dulo de defini��o: M�dulo �rvore **********/

#else
#endif
