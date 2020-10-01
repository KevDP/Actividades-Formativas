README.md

#función add

Análisis de complejidad temporal

El algoritmo presentado funciona mediante un ciclo que condicionan dos casos, el caso en que la lista esté vacía, entonces al determinar la primera posición (head) y la última (tail), se indica que el acceso será en la misma única posición con valor contenida en la lista, el otro caso es cuando la lista no esté vacía, la indicación es que la posición se determinará a partir de la última posición, es decir, de derecha a izquierda, entonces el acceso finalmente apuntará hacia el valor que se pretende agregar y se aumentará en uno la cantidad de valores para que esto sea posible, la complejidad temporal que presenta es de tiempo lineal, ó O(n) para el peor de los casos.

#función find

Análisis de complejidad temporal

El algoritmo presentado funciona mediante un ciclo que condiciona recorrer la propiedad del acceso (DLink p) mientras que el mismo sea diferente de 0, también se condiciona que al llegar al valor (val), se terminarán ambos ciclos, pero esto no quiere decir que usan más pasos que n, puesto que el primero es el que toma en cuenta los pasos totales y el segundo solo funciona bajo una complejidad constante, entonces, al salir del ciclo, esto diría que el valor(val) buscado ya habría sido encontrado, la complejidad temporal que presenta es de tiempo lineal, ó O(n) para el peor de los casos.

#función update

Análisis de complejidad temporal

El algoritmo presentado funciona mediante un ciclo que usa el mismo concepto que la función update, la parte diferente es que, al llegar a la posición buscada(pos), se modificará el valor de la posición dada por el valor ingresado, entonces al terminar el primer ciclo, se comprueba que el valor(val) ingresado ya habría sido integrado en la posición dada, la complejidad temporal que presenta es de tiempo lineal, ó O(n) para el peor de los casos.

#función remove

Análisis de complejidad temporal

El algoritmo presentado funciona mediante un ciclo que recorre el size de la lista obtenida, por lo que decimos que recorre n pasos, contiene una condición que al llegar al valor del índice dado, se determinarán los accesos next y previous a partir del Link propuesto (DLink p), realizada esta condición se optará por encontrar el valor dado(val) a partir de accesos anteriores a la posición en la que se encuentra, entonces al encontrar el valor y removerlo de la lista, el ciclo terminará, de la misma manera el espacio ocupado por ese valor será borrado, la complejidad temporal que presenta es de tiempo lineal, ó O(n) para el peor de los casos.
