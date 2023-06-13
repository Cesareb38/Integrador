#include "Quicksort.h"

/*Nodo* obtenerNodoAnterior(Nodo** primero, Nodo* nodo)
{
    if(*primero == NULL || *primero == nodo){
        return NULL;
    }
    Nodo* actual = *primero;
    Nodo* anterior = NULL;
    Nodo* anterior = NULL;
    printf("while anterior a encontrar nodo anterior");
    while (actual != NULL) {
    printf("Ingreso While");
        if (actual->siguiente == nodo) {
            printf("Ingreso if");
            return actual;
        }
        printf("Esto no deberia aparecer");
        actual = actual->siguiente;
    }
    return NULL;
}

Nodo* particion(Nodo* primero, Nodo* ultimo, Nodo** nuevoPrimero, Nodo** nuevoUltimo, Registro* registro)
{
    // Seleccionar el último nodo como pivote
    Nodo* pivote = ultimo;
    Nodo* j = primero;

    // Recorrer la lista y mover los nodos menores al lado izquierdo del pivote
    while (j != pivote)
    {
        if (atoi(j->linea) > atoi(pivote->linea)){
            trasladar(j,pivote);
        }
        j = j->siguiente;
    }
    // Retornar el puntero al pivote
    return pivote;
}

void quicksortUtil(Nodo* primero, Nodo* ultimo)
{
    if (primero != NULL && ultimo != NULL && primero != ultimo)
    {
        Nodo* nuevoPrimero = NULL;
        Nodo* nuevoUltimo = NULL;
        Nodo* pivote = particion(primero, ultimo);

        // Recursivamente ordenar las sublistas antes y después del pivote
        if (nuevoPrimero != pivote)
        {
            Nodo*temp = nuevoPrimero;
            while (temp->siguiente != pivote)
                temp = temp->siguiente;
            temp->siguiente = NULL;
            quicksortUtil(nuevoPrimero, temp, registro);
            temp = obtenerUltimoNodo(nuevoPrimero);
            temp->siguiente = pivote;
        }

        if (nuevoUltimo != pivote)
        {
            Nodo*temp = pivote->siguiente;
            quicksortUtil(temp, nuevoUltimo, registro);
        }
    }
}

void quicksort(Registro* registro)
{
    quicksortUtil(registro->primero, registro->ultimo);
}
*/
int obtenerNumeroNodos(Registro* registro) {
    int contador = 0;
    Nodo* actual = registro->primero;

    while (actual != NULL) {
        contador++;
        actual = actual->siguiente;
    }

    return contador;
}

// Función auxiliar para obtener el nodo en una posición dada en la lista enlazada
Nodo* obtenerNodo(Registro* registro, int posicion) {
    Nodo* actual = registro->primero;
    int contador = 0;

    while (actual != NULL && contador < posicion) {
        actual = actual->siguiente;
        contador++;
    }

    return actual;
}

// Función auxiliar para intercambiar los valores de dos nodos en la lista enlazada
void intercambiarNodos(Registro* registro, int posicion1, int posicion2) {
    Nodo* nodo1 = obtenerNodo(registro, posicion1);
    Nodo* nodo2 = obtenerNodo(registro, posicion2);

    char temp[4];
    strcpy(temp, nodo1->linea);
    strcpy(nodo1->linea, nodo2->linea);
    strcpy(nodo2->linea, temp);
}

// Función auxiliar para particionar la lista enlazada y devolver la posición del pivote
int particionar(Registro* registro, int inicio, int fin) {
    int i = inicio - 1;
    int j;

    char valorPivote[4];
    strcpy(valorPivote, obtenerNodo(registro, fin)->linea);

    for (j = inicio; j <= fin - 1; j++) {
        if (strcmp(obtenerNodo(registro, j)->linea, valorPivote) < 0) {
            i++;
            intercambiarNodos(registro, i, j);
        }
    }

    intercambiarNodos(registro, i + 1, fin);
    return i + 1;
}

// Función principal del algoritmo QuickSort para la lista enlazada
void quickSortUtil(Registro* registro, int inicio, int fin) {
    if (inicio < fin) {
        int posicionPivote = particionar(registro, inicio, fin);
        quickSortUtil(registro, inicio, posicionPivote - 1);
        quickSortUtil(registro, posicionPivote + 1, fin);
    }
}

// Función de ordenamiento QuickSort para la lista enlazada
void quicksort(Registro* registro) {
    int numeroNodos = obtenerNumeroNodos(registro);
    quickSortUtil(registro, 0, numeroNodos - 1);
}