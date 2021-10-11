# Proyecto 1: Implementación de Heaps

## Introducción

En este proyecto analizaremos e implementaremos tres variantes de Heap, a saber, Binary Heap, Binomial Heap y Fibonacci Heap. Nuestro objetivo es ofrecer una guía para conocer sus ventajas y desventajas, sus características y cuáles son los problemas en los que podemos aplicarlos.

## Binary Heap

Es una estructura de datos que toma la forma de árbol binario y que cumple la **Propiedad de Heap**: En un max heap para cualquier nodo C, si P es padre de C, P es mayor o igual a C. En un min heap P sería menor o igual a C. Su utilidad está en la implementación de colas prioridad eficientes. Su eficiencia es tal que comunmente las colas de prioridad son llamadas heap, independiente de cual sea la estructura de datos implementada. Adicionalmente a la propiedad de heap, un binary heap debe cumplir con requisito de forma: debe ser un árbol binario completo. Como es de suponer, encontrar el mínimo (o máximo, según sea el caso) toma tiempo constante. Insertar y borrar son $O(log(n))$ y la unión $O(n)$

Algunas aplicaciones de Binary Heap son:
	* El algoritmo Heap Sort utiliza internamente un binary heap para ordenar un arreglo en tiempo $O(nlogn)$.
	* Implementación de colas de prioridad donde no es importante implementar la operación de unión con máxima eficiencia. 
	* El algoritmo de Dijkstra puede utilizar un binary heap para encontrar el camino más corto.	

### Implementación Binary Heap

Para implementar un binary heap uilizamos un arreglo. Al ser binary heap siempre un árbol binario completo no hay necesidad de utilizar punteros y lo almacenamos de manera compacta. Para acceder a los hijos de un nodo particular, lo haremos mediante un par de operaciones aritméticas sobre el índice del padre. Lo mismo podemos hacer para encontrar el padre. Suponiendo que el arreglo está indexado en 0, las relaciones son las siguientes:

* Índice del Hijo derecho: $2i +2$
* Índice del Hijo izquierdo: $2i + 1$
* Índice del Padre: $\bigl\lfloor\frac{i-1}{2}\bigr\rfloor$

### Rendimiento teórico Binary Heap

La siguiente tabla describe la complejidad temporal en notación Big O de las operaciones soportadas por Binary Heap.

| Operación | Promedio | Peor Caso |
|--|--|--|
| Buscar | $O(n)$ | $O(n)$ |
| Insertar | $O(1)$ | $O(log(n))$ |
| min(max) | $O(1)$ | $O(log(1))$ |
| Eliminar min(max) | $O(log(n))$ | $O(log(n))$ |
| Unión | $O(n+m)$ | $O(n+m)$ |

Donde n y m representan el número de nodos de cada binary heap que forma parte en la operación de unión.

## Binomial Heap



### Implementación Binomial Heap

Para implementar un binary heap uilizamos un arreglo. Al ser binary heap siempre un árbol binario completo no hay necesidad de utilizar punteros y lo almacenamos de manera compacta. Para acceder a los hijos de un nodo particular, lo haremos mediante un par de operaciones aritméticas sobre el índice del padre. Lo mismo podemos hacer para encontrar el padre. Suponiendo que el arreglo está indexado en 0, las relaciones son las siguientes:

* Índice del Hijo derecho: $2i +2$
* Índice del Hijo izquierdo: $2i + 1$
* Índice del Padre: $\bigl\lfloor\frac{i-1}{2}\bigr\rfloor$

### Rendimiento Teórico Binomial Heap


Describir las características principales de los tipos de heaps seleccionados.
• Describir las decisiones de implementación más importantes.
• Plantear varias hipótesis (al menos 2, máximo 4) sobre el rendimiento de las estructuras a
comparar en escenarios específicos. Por ejemplo, “la estructura X es más rápida en la operación
OP que la estructura Y cuando los datos cumplen cierta característica C”, “la estructura X
ocupará más espacio que la estructura Y”, etc.
• Diseñar un experimento que permita contrastar cada hipótesis.
• Ejecutar los experimentos y explicar los resultados obtenidos.