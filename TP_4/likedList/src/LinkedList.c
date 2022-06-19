#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNodeAux = NULL;

	if(this != NULL && nodeIndex > -1 && ll_len(this) > nodeIndex)
	{
		pNodeAux = this->pFirstNode;

		for(int i = 0; ll_len(this) > i; i++)
		{
			if(i == nodeIndex)
			{
				break;
			}
			else
			{
				pNodeAux = pNodeAux->pNextNode;
			}
		}
	}
    return pNodeAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    if(this != NULL && nodeIndex > -1 && ll_len(this) >= nodeIndex)
    {
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		if(pNewNode != NULL)
		{
			if(nodeIndex == 0)
			{
				pNewNode->pNextNode = this->pFirstNode;
				this->pFirstNode = pNewNode;
			}
			else
			{
				Node* pNodeAux = getNode(this,nodeIndex - 1);///pNodeAux->pNextNode = NODO 4

				pNewNode->pNextNode = pNodeAux->pNextNode; ///pNewNode->pNextNode = NODO 4
				pNodeAux->pNextNode = pNewNode; ///pNodeAux->pNextNode = pNewNode (NODO 3)
			}
			pNewNode->pElement = pElement;
			this->size++;
			returnAux = 0;
		}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	addNode(this, ll_len(this), pElement);
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNodeAux = NULL;

    if(this != NULL && index > -1 && ll_len(this) >= index )
    {
    	pNodeAux = getNode(this, index);
		if(pNodeAux != NULL)
		{
			returnAux = pNodeAux->pElement;
		}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodeAux = NULL;
    if(this != NULL && index > -1 && index <= ll_len(this))
    {
    	pNodeAux = getNode(this, index);

    	if(pNodeAux != NULL)
    	{
    		pNodeAux->pElement = pElement;
			returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    Node* pNodeRemove = NULL;
	Node* pNodeAux = NULL;

    if(this != NULL && index > -1 && index <= ll_len(this))
    {
    	pNodeRemove = getNode(this, index);

		if(pNodeRemove != NULL)
		{
			if(index - 1 < 0)
			{
				this->pFirstNode = NULL;
				this->size = 0;
			}
			else
			{
				pNodeAux = getNode(this, index - 1);

				pNodeAux->pNextNode = pNodeRemove->pNextNode;
				this->size--;
			}
			returnAux = 0;
			free(pNodeRemove);
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int lengthLista;
    if(this != NULL)
    {
    	lengthLista = ll_len(this);

    	for(int i = 0 ; i > lengthLista ; i--)
    	{
    		ll_remove(this, i);
    	}
    	returnAux = 0;
    	this->size = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	if(!ll_clear(this))
    	{
    		free(this);
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int lengthLista;
    void* pAux;

    if(this != NULL)
    {
    	lengthLista = ll_len(this);

    	for(int i = 0; i < lengthLista; i++)
    	{
    		pAux = ll_get(this, i);

    		if(pAux == pElement)
    		{
    			returnAux = 0;
    			break;
    		}
    	}

    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(this->pFirstNode != NULL)
    	{
    		returnAux = 0;
    	}
    	else
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index > -1 && index <= ll_len(this))
    {
    	addNode(this, index, pElement);
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL && index > -1 && index <= ll_len(this))
    {
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if(ll_indexOf(this, pElement) != -1)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2) //
{
    int returnAux = -1;
    int lengthLista;
    void* pElementoAux;
    int contadorCoincidencias = 0;
    if(this != NULL && this2 != NULL)
    {
    	lengthLista = ll_len(this2);
    	for(int i = 0; i < lengthLista; i++)
    	{
    		pElementoAux = ll_get(this2, i);

    		if(ll_indexOf(this, pElementoAux) != -1)
    		{
    			contadorCoincidencias++;
    		}
    	}
    	if(contadorCoincidencias == lengthLista)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElementoAux = NULL;

    if(this != NULL && from < to && from < ll_len(this) && from >= 0 && to <= ll_len(this))
    {
    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL)
    	{
			for(int i = from ; i < to; i++) // de 5 a 10
			{
				pElementoAux = ll_get(this, i);

				if(pElementoAux != NULL)
				{
					ll_add(cloneArray, pElementoAux);
				}
			}
    	}
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int lengthLista;
    if(this != NULL)
    {
    	lengthLista = ll_len(this);
    	cloneArray = ll_subList(this, 0, lengthLista);
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* pElementoA = NULL;
    void* pElementoB = NULL;
    int lengthLista;
    int criterio;
    int flagSwap = 0;
    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
    	lengthLista = ll_len(this);

    	do
    	{
    		flagSwap = 0;

			for(int i = 0; i < lengthLista; i++)
			{
				pElementoA = ll_get(this, i);
				pElementoB = ll_get(this, i + 1);

				if(pElementoA != NULL && pElementoB != NULL)
				{
					criterio = pFunc(pElementoA, pElementoB); /// 1  A > B || 0 B > A

					if((criterio == 1 && order == 1) || (criterio == -1 && order == 0))
					{
						ll_set(this, i, pElementoB);
						ll_set(this, i + 1, pElementoA);

						flagSwap = 1;
					}
				}
			}
    	}while(flagSwap);
		returnAux = 0;
    }

    return returnAux;
}
