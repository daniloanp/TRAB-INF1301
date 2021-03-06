#if ! defined( GRAFO_ )
#define GRAFO_
/***************************************************************************
*
*  $MCD Módulo de definição: GRA  Grafo genêrico
*
*  Arquivo gerado:              GRAFO.h
*  Letras identificadoras:      GRA
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\Grafo.BSW
*
*  Projeto: INF 1301 / Labirinto
*  Gestor:  LSKDANEAV
*  Autores: eav
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*		 1	   eav	 25/09/2014		//
*
*  $ED Descrição do módulo
*     Implementa um grafo não direcionado sem peso nas arestas, não admitimos aresta para o próprio vertice(laços). 
*     genérico usando uma interface de Listas genéricas duplamente encadeadas.
*     O grafo possui uma cabeça encapsulando o seu estado.
*     O grafo é homogêneo quanto ao tipo.
*     Por hipótese, as ids requeridos pela interface são únicos para cada grafo.
*     Por hipótese, os ponteiros para grafo requeridos pela interface são válidos.
*     Este ponteiro é provido pela função GRA_CriarGrafo
*     Para o bom funcionamento do módulo, o usuário deve garantir estas hipóteses.
***************************************************************************/

#if defined( GRAFO_OWN )
   #define GRAFO_EXT
#else
   #define GRAFO_EXT extern
#endif

#include "LISTA.h"
#include <assert.h>

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma grafo */

typedef struct GRA_tagGrafo* GRA_tppGrafo ;
typedef struct LIS_tagLista* LIS_tppLista ;

/***********************************************************************
*
*  $TC Tipo de dados: GRA Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do grafo
*
***********************************************************************/

  typedef enum {

    GRA_CondRetOK ,
    /* Concluiu corretamente */

    GRA_CondRetGrafoVazio ,
    /* O grafo está vazio(não possui vertices) */

    GRA_CondRetNaoEhVertice ,
   /* Não encontrou o vértice procurado */

    GRA_CondRetEhVizinho ,
    /* Os vértices explicitados são vizinhos*/
		
    GRA_CondRetNaoEhVizinho ,
	  /* Os vértices explicitados não são vizinhos*/
				
	GRA_CondRetFaltouMemoria,
    /* Faltou memória ao tentar criar um elemento de Grafo */
    
	GRA_CondRetNaoEhConexo,
    /* Faltou memória ao tentar criar um elemento de Grafo */
   } GRA_tpCondRet ;

/***********************************************************************
*
*  $FC Função: GRA  &Criar Grafo
*
*  $ED Descrição da função
*     Cria uma Grafo genérico implementado com listas duplamente encadeadas, também genéricas.
*     O grafo é não direcionado e sem pesos nas arestas.  
*     Os possíveis tipos são desconhecidos a priori.
*     A tipagem é implicita.
*     Não existe identificador de tipo associado à Grafo.
*
*  $EP Parâmetros
*     ExcluirValor  - ponteiro para a função que processa a
*                     exclusão do valor referenciado pelo elemento
*                     a ser excluído.
*                     Ver descrição do módulo.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para o Grafo.
*     Este ponteiro será utilizado pelas funções que manipulem este Grafo.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
*  Assertivas de Entrada: 
*       a função passada deve excluir o tipo de dado do grafo 
*       de forma que não vaze memória ou crie ponteiros para o nada.    
*
*  Assertivas de Saida: 
*       O ponteiro retornado deve ser do tipo GRA_tppGrafo, 
*       terá corrente = -1 e 
*       terá dois LIS_tppLista, componentes e vertices, 
*       ambas com 0 elementos(vazias)
***********************************************************************/

   GRA_tppGrafo GRA_CriarGrafo ( void ( * ExcluirValor ) ( void * pDado ) ) ;
   
/***********************************************************************
*
*  $FC Função: GRA  &Destruir grafo
*
*  $ED Descrição da função
*     Destrói o grafo fornecido.
*     O parâmetro ponteiro para o grafo não é modificado.
*     Se ocorrer algum erro durante a destruição, o grafo resultará
*     estruturalmente incorreto.
*     OBS. não existe previsão para possíveis falhas de execução.
*
*  $FV Valor retornado
*     GRA_CondRetOK - destruiu sem problemas
*  
*  Assertivas de Entrada: 
*      pGrafo != NULL
*
*  Assertivas de Saida: 
*       pGrafo = NULL
***********************************************************************/

   GRA_tpCondRet GRA_DestruirGrafo( GRA_tppGrafo pGrafo ) ;

/***********************************************************************
*
*  $FC Função: GRA  &Inserir vértice
*
*  $ED Descrição da função
*     Insere um novo vértice no grafo.
*     Caso o grafo esteja vazio, insere o primeiro vértice do grafo. 
*     Neste caso (grafo vazio) o vértice inserido vira o corrente.
*
*  $EP Parâmetros
*     pGrafo     - ponteiro para o grafo onde deve ser inserido o vertice
*     pValor     - ponteiro para o valor a ser armazenado no Nó(deve-se respeitar a homogeneidade do grafo para ter comportamento garantido)
*     idVertice  - identificador do vertice
*
*  $FV Valor retornado
*     GRA_CondRetOK	- O vértice foi inserido com sucesso
*     GRA_CondRetFaltouMemoria - Não foi possível alocar memória para o vértice
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      não existe vertice com id=idVertice e este é único para os vértices de pGrafo
*      pValor tem o mesmo tipo que a função ExcluirValor passada na Criar grafo espera para remover.
*  Assertivas de Saida: 
*      tamanho da lista de vertices de pGrafo incrementa em 1
***********************************************************************/

   GRA_tpCondRet GRA_InserirVertice( GRA_tppGrafo pGrafo , void* pValor , int idVertice) ;
   
/***********************************************************************
*
*  $FC Função: GRA  &Excluir vértice
*
*  $ED Descrição da função
*     Exclui o vértice explicitado do grafo.
*     Caso o grafo esteja vazio, apenas retorna.
*     Caso o vértice explicitado não pertença ao grafo apenas retorna.
*     Percorre a lista de vizinhos do vértice excluindo as respectivas arestas antes de liberar o vértice.
*
*  $EP Parâmetros
*     pGrafo     - ponteiro para o grafo onde deve ser excluido o vértice
*     idVertice  - id do vértice a ser excluido
*
*   $FV Valor retornado
*     GRA_CondRetOK  - Exclusão feita com sucesso
*     GRA_CondRetNaoEhVertice - Não há um vértice com essa id no grafo
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      existe um único vertice em pGrafo com id = idVertice 
*  Assertivas de Saida: 
*      tamanho da lista de vertices de pGrafo diminui em 1
***********************************************************************/

   GRA_tpCondRet GRA_ExcluirVertice( GRA_tppGrafo pGrafo , int idVertice ) ;
 
/***********************************************************************
*
*  $FC Função: GRA  &Inserir Aresta
*
*  $ED Descrição da função
*     Insere uma aresta entre 2 vértices diferentes em ambas direções.
*
*  $EP Parâmetros
*     pGrafo     - ponteiro para o grafo aonde deve ser inserida a aresta
*     idVertice1 - id de um dos vértices
*     idVertice2 - id para o outro vértice
*     idAresta   - identificador para a aresta
*
*  $FV Valor retornado
*     GRA_CondRetOK  - Ambos os vértices existiam e não hávia aresta entre eles
*     GRA_CondRetEhVizinho - Já existe aresta entre os vértices
*     GRA_CondRetNaoEhVertice - idVertice1 (ou idVertice2) não são id's de um vértice do grafo
*     GRA_CondRetFaltouMemoria - Não foi possível alocar memória para a aresta
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      existe um único vertice em pGrafo com id = idVertice1 
*      existe um único vertice em pGrafo com id = idVertice2 
*      idVertice1 != idVertice2 
*      não existe aresta com id = idAresta e este é único para os ids de aresta de pGrafo
*  Assertivas de Saida: 
*      Existe caminho de idVertice1 para idVertice2 e vice-versa. 
*      Este caminho tem tamanho 2.
***********************************************************************/

   GRA_tpCondRet GRA_InserirAresta( GRA_tppGrafo pGrafo , int idVertice1,int idVertice2, int idAresta ) ;

/***********************************************************************
*
*  $FC Função: GRA  &Excluir Aresta
*
*  $ED Descrição da função
*     Exclui uma aresta entre 2 vértices.
*     Se não existir uma aresta entre idVertice1 e idVertice2, erro de inexistência
*     Se idVertice1 ou idVertice2 não existirem, erro de inexistencia 
*
*  $EP Parâmetros
*     pGrafo    - ponteiro para o grafo aonde deve ser inserida a aresta
*     idAresta  - id da aresta
*
*  $FV Valor retornado
*     GRA_CondRetOK  - Ambos os vértices existem e havia uma aresta entre eles
*     GRA_CondRetNaoEhVertice - idVertice1 (ou idVertice2) não são id's de um vértice do grafo
*     GRA_CondRetNaoEhVizinho - Não existe aresta entre os dois vértices
*     GRA_CondRetFaltouMemoria - faltou memoria para criar nova componente
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      existe uma única aresta em pGrafo com id = idAresta 
*  Assertivas de Saida: 
***********************************************************************/

   GRA_tpCondRet GRA_ExcluirAresta( GRA_tppGrafo pGrafo , int idAresta ) ;


/***********************************************************************
*
*  $FC Função: GRA  &ObterVizinhos
*
*  $ED Descrição da função
*     Obtem os vizinhos de idVertice, cria e preenche uma lista de int id coms os vizinhos de idVertice e aponta pLista para a lista criada.
*
*  $EP Parâmetros
*     pGrafo        - ponteiro para o grafo aonde deve ser buscada os vizinhos do idVertice
*     pListaVertice - ponteiro para a lista de vértices a ser preenchida com os vizinhos do idVertice
*     idVertice     - id para o vertice
*
*  $FV Valor retornado
*     GRA_CondRetOK  - Retornou a lista
*     GRA_CondRetNaoEhVertice - idVertice não é um vértice do grafo
*     GRA_CondRetFaltouMemoria - Não foi possível alocar memória para a lista de vértices vizinhos
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      existe um único vertice em pGrafo com id = idVertice 
*      pLista = NULL //recomendação para evitar memoryleak
*  Assertivas de Saida:
*      pLista != NULL 
***********************************************************************/

GRA_tpCondRet GRA_ObterVizinhos (GRA_tppGrafo pGrafo, int idVertice, LIS_tppLista* pLista);

/***********************************************************************
*
*  $FC Função: GRA  &ObterOrigens
*
*  $ED Descrição da função
*     Aponta pLista para uma lista criada contendo as int id de origens arbitrárias para cada uma das componentes conexas do grafo.
*     Se o grafo não possuir vértices, não aloca a Lista, evitando a necessidade de desalocar
*
*  $EP Parâmetros
*     pGrafo        - ponteiro para o grafo aonde devem ser buscadas as origens
*     pListaVertice - ponteiro para a lista de vértices a ser preenchida com as origens do grafo
*
*  $FV Valor retornado
*     GRA_CondRetOK  - Retornou a lista
*     GRA_CondRetFaltouMemoria - Não foi possível alocar memória para a lista de vértices de origem
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      pLista = NULL //recomendação para evitar memoryleak
*  Assertivas de Saida: 
***********************************************************************/

GRA_tpCondRet GRA_ObterOrigens ( GRA_tppGrafo pGrafo, LIS_tppLista * pLista);

/***********************************************************************
*
*  $FC Função: GRA  &Obter valor
*
*  $ED Descrição da função
*     Obtem o valor - referência para um valor - do idVertice.
*
*  $EP Parâmetros
*     pGrafo    - ponteiro para o grafo
*     idVertice - id do vértice
*     pDado     - ponteiro para o dado a ser obtido
*
*  $FV Valor retornado
*     GRA_CondRetOK	- o valor foi obtido com sucesso
*     GRA_CondRetNaoEhVertice - idVertice explicitado não pertence ao grafo
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      existe um único vertice em pGrafo com id = idVertice 
*      pDado = NULL //recomendação para evitar memoryleak
*  Assertivas de Saida: 
***********************************************************************/

    GRA_tpCondRet GRA_ObterValor( GRA_tppGrafo pGrafo , int idVertice , void** pDado ) ;   

/***********************************************************************
*
*  $FC Função: GRA  &Obter valores
*
*  $ED Descrição da função
*     Preenche uma lista passada por referencia com os valores de cada vertice do grafo.
*
*  $EP Parâmetros
*     pGrafo    - ponteiro para o grafo
*     pValores - lista a ser preenchida com os valores de cada vertice
*
*  $FV Valor retornado
*     GRA_CondRetOK	- o valor foi obtido com sucesso
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      pValores != NULL (Lista é criada pelo cliente; é passada uma lista vazia, não uma referencia nula)
***********************************************************************/

    GRA_tpCondRet GRA_ObterValores( GRA_tppGrafo pGrafo, LIS_tppLista pValores ) ;   

/***********************************************************************
*
*  $FC Função: GRA  &Alterar valor
*
*  $ED Descrição da função
*     Altera o valor - referência para um valor -  do idVertice.
*     A função não libera memória do valor anterior. É necessário obtê-lo e limpar manulamente
*
*  $EP Parâmetros
*     pGrafo    - ponteiro para o grafo
*     idVertice - id do vértice
*     pDado     - ponteiro para o dado a ser alterado
*
*  $FV Valor retornado
*     GRA_CondRetOK	- O vértice teve o valor alterado com sucesso
*     GRA_CondRetNaoEhVertice - o vértice explicitado não pertence ao grafo
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      existe um única vertice em pGrafo com id = idVertice 
*  Assertivas de Saida: 
*      apos GRA_ObterValor(pGrafo,idVertice,a) -> *a = pDado
***********************************************************************/

  GRA_tpCondRet GRA_AlterarValor( GRA_tppGrafo pGrafo , int idVertice , void* pDado ) ;   

/***********************************************************************
*
*  $FC Função: GRA  &Buscar caminho
*
*  $ED Descrição da função
*     Retorna um caminho - lista de idVertice - traçando um caminho do vértice origem até o vértice destino.
*     O caminho retornado é invertido - para a visualização correta deve-se ler a lista de trás pra frente, dado que a lista é duplamente encadeada, isto não deve ser um problema.
*
*  $EP Parâmetros
*     pGrafo            - ponteiro para o grafo
*     idVerticeOrigem   - id do vértice origem
*     idVerticeDestino  - id do vértice destino
*     pLista            - ponteiro para a lista de ids que armazenara o caminho
*
*  $FV Valor retornado
*     GRA_CondRetOK	- O caminho foi preenchido com sucesso
*     GRA_CondRetNaoEhVertice - ao menos um dos vértices explicitados não pertencem ao grafo
*     GRA_CondRetNaoEhConexo - não ha caminho entre os dois vertices dados
*     GRA_CondRetFaltouMemoria - não há espaço para preencher a lista
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      existe um único vertice em pGrafo com id = idVerticeOrigem 
*      existe um único vertice em pGrafo com id = idVerticeDestino
*      pLista = NULL //recomendação para evitar memoryleak
*  Assertivas de Saida: 
*      pLista != NULL
***********************************************************************/

  GRA_tpCondRet GRA_BuscarCaminho( GRA_tppGrafo pGrafo , int idVerticeOrigem , int idVerticeDestino,   LIS_tppLista * pLista ) ;   


/***********************************************************************
*
*  $FC Função: GRA  &Inserir Vizinho Corrente
*
*  $ED Descrição da função
*     Insere um novo vizinho para o corrente com o idVertice dado. A aresta terá o id passado em idAresta
*
*  $EP Parâmetros
*     pGrafo - ponteiro para o grafo onde deve ser inserido o vertice
*     pValor - ponteiro para o valor a ser armazenado no Nó(deve-se respeitar a homogeneidade do grafo para ter comportamento garantido)
*     idVertice - identificador do vertice
*     idAresta - identificador da aresta
*
*  $FV Valor retornado
*     GRA_CondRetOK	- O vértice foi inserido com sucesso
*     GRA_CondRetFaltouMemoria - Não foi possível alocar memória para o vértice
*     GRA_CondRetGrafoVazio - O grafo esta vazio, não há corrente
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      não existe vertice com id = idVertice e este é único para os ids de vertice de pGrafo
*      não existe aresta com id = idAresta e este é único para os ids de aresta de pGrafo
*       pGrafo->corrente != -1
*  Assertivas de Saida:
*      Existe caminho de tamanho 2 entre o corrente e o idVertice
*      tamanho da lista de vertices de pGrafo incrementa em 1
***********************************************************************/

   GRA_tpCondRet GRA_InserirVizinhoCorrente( GRA_tppGrafo pGrafo , void* pValor , int idVertice, int idAresta) ;
   

/***********************************************************************
*
*  $FC Função: GRA  &Excluir Vizinho Corrente
*
*  $ED Descrição da função
*     Exclui o vizinho do corrente com idVertice passado.
*
*  $EP Parâmetros
*     pGrafo - ponteiro para o grafo de onde deve ser excluido o vértide
*     idVertice - identificador do vertice
*
*  $FV Valor retornado
*     GRA_CondRetOK  - Operação efetuada com sucesso
*     GRA_CondRetNaoEhVertice - idVertice não é um vértice do grafo
*     GRA_CondRetNaoEhVizinho - Não existe aresta entre o corrente e idVertice
*     GRA_CondRetGrafoVazio - O grafo esta vazio, não há corrente
*     GRA_CondRetFaltouMemoria - faltou memoria para criar nova componente
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      existe um único vertice em pGrafo com id = idVertice
*      pGrafo->corrente != -1
*      existe aresta entre o corrente e idVertice
*  Assertivas de Saida: 
*      tamanho da lista de vertices de pGrafo diminui em 1
***********************************************************************/

   GRA_tpCondRet GRA_ExcluirVizinhoCorrente( GRA_tppGrafo pGrafo , int idVertice) ;


/***********************************************************************
*
*  $FC Função: GRA  &Obter Vizinhos Corrente
*
*  $ED Descrição da função
*     Obtem os vizinhos do vértice corrente
*     Se o corrente não possuir vizinhos, retorna uma lista de tamanho 0
*
*  $EP Parâmetros
*     pGrafo - ponteiro para o grafo aonde deve ser inserida a aresta
*     pListaVertice - ponteiro para a lista de vértices a ser preenchida com os vizinhos de pVertice
*
*  $FV Valor retornado
*     GRA_CondRetOK  - Retornou a lista
*     GRA_CondRetGrafoVazio - O grafo esta vazio, não há corrente
*     GRA_CondRetFaltouMemoria - Não foi possível alocar memória para a lista de vértices
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      pGrafo->corrente != -1
*      pLista = NULL //recomendação para evitar memoryleak
*  Assertivas de Saida: 
*      pLista != NULL
***********************************************************************/

GRA_tpCondRet GRA_ObterVizinhosCorrente(GRA_tppGrafo pGrafo, LIS_tppLista* pLista);


/***********************************************************************
*
*  $FC Função: GRA  &Obter Valor Corrente
*
*  $ED Descrição da função
*     Obtem o valor - referência para um valor - do vértice corrente.
*
*  $EP Parâmetros
*     pGrafo - ponteiro para o grafo
*     pDado - ponteiro para o dado a ser obtido
*
*  $FV Valor retornado
*     GRA_CondRetOK	- O vértice teve o valor alterado com sucesso
*     GRA_CondRetGrafoVazio - o grafo está vazio, não há corrente
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      pGrafo->corrente != -1
*      pDado = NULL //recomendação para evitar memoryleak
*  Assertivas de Saida: 
***********************************************************************/

    GRA_tpCondRet GRA_ObterValorCorrente( GRA_tppGrafo pGrafo , void** pDado ) ;   

/***********************************************************************
*
*  $FC Função: GRA  &Obter ID Corrente
*
*  $ED Descrição da função
*     Obtem o ID do vértice corrente.
*
*  $EP Parâmetros
*     pGrafo - ponteiro para o grafo
*     id - ponteiro para o inteiro a ser preenchido com a id
*
*  $FV Valor retornado
*     GRA_CondRetOK	- ID obtida com sucesso
*     GRA_CondRetGrafoVazio - o grafo está vazio, não há corrente
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      pGrafo->corrente != -1
*      pDado = NULL //recomendação para evitar memoryleak
*  Assertivas de Saida: 
***********************************************************************/

    GRA_tpCondRet GRA_ObterIDCorrente( GRA_tppGrafo pGrafo , int* id ) ;  

/***********************************************************************
*
*  $FC Função: GRA  &Alterar valor Corrente
*
*  $ED Descrição da função
*     Altera o valor - referência pra um valor -  no vértice corrente.
*     A função não libera memória do valor anterior. É necessário obtê-lo e limpar manulamente
*
*  $EP Parâmetros
*     pGrafo - ponteiro para o grafo
*     pDado - ponteiro para o dado a ser inserido
*
*  $FV Valor retornado
*     GRA_CondRetOK	- O vértice corrente teve o valor alterado com sucesso
*     GRA_CondRetGrafoVazio - o grafo está vazio, não há corrente
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      pGrafo->corrente != -1
*  Assertivas de Saida: 
*      apos GRA_ObterValorCorrente(pGrafo,a) -> *a = pDado
***********************************************************************/

  GRA_tpCondRet GRA_AlterarValorCorrente( GRA_tppGrafo pGrafo , void * pDado ) ;   
  

/***********************************************************************
*
*  $FC Função: GRA  &Fmap
*
*  $ED Descrição da função
*    Executa a função passada para cada vértice do grafo. 
*    A função retorna falha caso a f retorne falha. 
*    Se f retornar ok a funcao continua.
*  $EP Parâmetros
*     pGrafo - ponteiro para o grafo
*     f - ponteiro para a funcao
*  $FV Valor retornado
*     GRA_CondRetOK	- O vertice foi achado
*     GRA_CondRetNaoEhVertice - O vertice nao foi achado
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*  Assertivas de Saida:
*
***********************************************************************/  
  
  GRA_tpCondRet GRA_Fmap( GRA_tppGrafo pGrafo , GRA_tpCondRet f(void* pDado) );  

/***********************************************************************
*
*  $FC Função: GRA  &Buscar vertice
*
*  $ED Descrição da função
*     Implementa uma busca genêrica no grafo
*     Retorna o id do vertice que satisfaz o predicado
*     O predicado é uma função de callback com a validação específica.
*     Ele recebe 2 parametros. O primeiro parametro representa o valor de cada vertice na busca. O segundo parametro representa o valor do vértice buscado. 
*
*  $EP Parâmetros
*     pGrafo - ponteiro para o grafo
*     idVertice - ponteiro do id do vertice a ser buscado
*     predicado - ponteiro para função que compara dois valores
*       pDado - cada valor de vertice no grafo
*       _parametro - valor comparado ao de cada vertice do grafo (valor procurado)
*     parametro - valor procurado
*
*  $FV Valor retornado
*     GRA_CondRetOK	- O vertice foi achado
*     GRA_CondRetNaoEhVertice - O vertice nao foi achado
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*  Assertivas de Saida:
*
***********************************************************************/

  GRA_tpCondRet GRA_BuscarVertice( GRA_tppGrafo pGrafo , int* idVertice , int predicado(void* pDado, void* _parametro), void* parametro ) ;  

/***********************************************************************
*
*  $FC Função: GRA  &Buscar caminho corrente
*
*  $ED Descrição da função
*     Retorna um caminho - lista de int idVertice - traçando um caminho do corrente ao vertice dado
*     O caminho retornado é invertido - para a visualização correta deve-se ler a lista de trás pra frente.

*  $EP Parâmetros
*     pGrafo - ponteiro para o grafo
*     idVerticeDestino - id do vértice destino
*     pLista - ponteiro para a lista de ids que armazenara o caminho
*
*  $FV Valor retornado
*     GRA_CondRetOK	- O caminho foi preenchido com sucesso
*     GRA_CondRetNaoEhVertice - ao menos um dos vértices explicitados não pertencem ao grafo
*     GRA_CondRetNaoEhConexo - não ha caminho entre os dois vertices dados
*     GRA_CondRetFaltouMemoria - não há espaço para preencher a lista
*     GRA_CondRetGrafoVazio - o grafo está vazio, não há corrente
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      pGrafo->corrente != -1
*      existe um único vertice em pGrafo com id = idVerticeDestino
*      pLista = NULL //recomendação para evitar memoryleak
*  Assertivas de Saida:
*      pLista != NULL
***********************************************************************/

  GRA_tpCondRet GRA_BuscarCaminhoCorrente( GRA_tppGrafo pGrafo ,  int idVerticeDestino,   LIS_tppLista * pLista ) ;    

/***********************************************************************
*
*  $FC Função: GRA  &Ir vizinho corrente
*
*  $ED Descrição da função
*     muda o corrente para o vizinho dado
*   
*  $EP Parâmetros
*     pGrafo - ponteiro para o grafo
*     idVertice - id do vértice vizinho ao corrente que será o novo corrente
*
*  $FV Valor retornado
*     GRA_CondRetOK	- O caminho foi preenchido com sucesso
*     GRA_CondRetNaoEhVertice - ao menos um dos vértices explicitados não pertencem ao grafo
*     GRA_CondRetNaoEhvizinho - idVertice nao eh vizinho do corrente
*     GRA_CondRetGrafoVazio - o grafo está vazio, não há corrente
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      pGrafo->corrente != -1
*      existe um único vertice em pGrafo com id = idVertice 
*      existe aresta entre o corrente e idVertice
*  Assertivas de Saida: 
*      pGrafo->corrente = idVertice
***********************************************************************/

  GRA_tpCondRet GRA_IrVizinhoCorrente( GRA_tppGrafo pGrafo , int idVertice ) ;   

/***********************************************************************
*
*  $FC Função: GRA  &Mudar corrente
*
*  $ED Descrição da função
*     muda o corrente para o vertice dado.
*     esta é a única maneira de mudar de componente conexa. 
*   
*  $EP Parâmetros
*     pGrafo - ponteiro para o grafo
*     idVertice - id do vértice que será o novo corrente
*
*  $FV Valor retornado
*     GRA_CondRetOK	- O caminho foi preenchido com sucesso
*     GRA_CondRetNaoEhVertice - o vértice explicitado não pertence ao grafo
*     GRA_CondRetGrafoVazio - o grafo está vazio, não há corrente
*
*  Assertivas de Entrada: 
*      pGrafo != NULL
*      pGrafo->corrente != -1
*      existe um único vertice em pGrafo com id = idVertice 
*  Assertivas de Saida: 
*      pGrafo->corrente = idVertice
***********************************************************************/

  GRA_tpCondRet GRA_MudarCorrente( GRA_tppGrafo pGrafo , int idVertice ) ;   

#ifdef _DEBUG
/***********************************************************************
*
*  $FC Função: GRA  &Verifica
*
*  $ED Descrição da função
*     Verifica as assertivas estruturais do grafo.
*   
*  $EP Parâmetros
*     pGrafo - ponteiro para o grafo
*     Numerros - a quantidade de erros
*
*  $FV Valor retornado
*     GRA_CondRetOK	- O grafo é válido
*
*  Assertivas de Entrada: 
*
*  Assertivas de Saida: 
*
***********************************************************************/
  GRA_tpCondRet GRA_Verifica( GRA_tppGrafo pGrafo, int* Numerros) ; 

/***********************************************************************
*
*  $FC Função: GRA  &Deturpa
*
*  $ED Descrição da função
*     Deturpa um TAD Grafo, invalidando uma ou mais assertivas estruturais do grafo.
*   
*  $EP Parâmetros
*     pGrafo - ponteiro para o grafo
*     acao - inteiro representando a ação (tipo de assertiva a ser invalidade) a ser executada no grafo.
*
*  $FV Valor retornado
*     GRA_CondRetOK - A acao era valida e foi executada com sucesso. (O Grafo passa a ser invalido)
*
*  Assertivas de Entrada: 
*
*  Assertivas de Saida: 
*
***********************************************************************/
  GRA_tpCondRet GRA_Deturpa( GRA_tppGrafo pGrafo, int acao) ; 
#endif

#endif




