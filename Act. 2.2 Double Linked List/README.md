README.md

#función add

Análisis de complejidad temporal

El algoritmo presentado funciona mediante un ciclo que condiciona recorrer la propiedad del acceso siguiente (Link next) mientras que el mismo sea difirente de 0, al terminar el ciclo, el acceso finalmente apuntará hacia el valor que se pretende agregar y si aumenta en uno la cantidad de valores para que esto sea posible, la complejidad temporal que presenta es de tiempo lineal, ó O(n) para el peor de los casos.

#función find

Análisis de complejidad temporal

El algoritmo presentado funciona mediante un ciclo que condiciona recorrer la propiedad del acceso (Link p) mientras que el mismo sea difirente de 0, también se condiciona que al llegar al valor (val), se terminarán ambos ciclos pero esto no quiere decir que usan más pasos que n, puesto que el primero es el que toma en cuenta los pasos totales y el segundo solo funciona bajo una complejidad constante, entonces, al salir del ciclo, esto diría que el valor(val) buscado ya habría sido encontrado, la complejidad temporal que presenta es de tiempo lineal, ó O(n) para el peor de los casos.

#función update

Análisis de complejidad temporal

El algoritmo presentado funciona mediante un ciclo que usa el mismo concepto que la función update, la parte diferente es que al llegar a la posición buscada(pos), se modificará el valor de la posición dada por el valor ingresado, entonces al terminar el primer ciclo, diría que el valor(val) ingresado ya habría sido integrado en la posición dada, la complejidad temporal que presenta es de tiempo lineal, ó O(n) para el peor de los casos.

#función remove

Análisis de complejidad temporal

El algoritmo presentado funciona mediante un ciclo que recorre el size de la lista obtenida, por lo que decimos que recorre n pasos, contiene una condición que al llegar al valor del índice dado, el acceso auxiliar(Link aux) guardará el acceso de la posición que se pretende remover y de la misma forma se guardará el valor de la posición, entonces el link será relacionado hacia el siguiente valor de la lista, realizada esta condición, el ciclo terminará y el valor y la posición del índice dado, de la misma manera el espacio ocupado por esa posición será borrado, la complejidad temporal que presenta es de tiempo lineal, ó O(n) para el peor de los casos.
