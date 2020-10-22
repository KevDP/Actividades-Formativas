README.md

#función add

Análisis de complejidad temporal

El algoritmo presentado funciona mediante una serie de llamadas de dos funciones, la primera es la adición de un nodo, el cual servirá para conectar el valor al árbol, la función mencionada ordena el valor y posiciona el nodo según el valor que representa y si es menor o mayor que los otros valores encontrados en el árbol, por otro lado, la segunda función se encarga de hacer un "ordenamiento", de tal manera que el valor recientemente agregado sea el root, es decir, el valor encontrado en el primer nivel, y todos los demás valores sean comparados con él para realizar el árbol y ordenar los nodos y valores, la complejidad temporal que presenta es de tiempo lineal, ó O(n) para el peor de los casos.

#función remove

Análisis de complejidad temporal

El algoritmo presentado funciona mediante una serie de condicionales, donde, a partir del valor a remover, se le asignará instrucciones para ser el root del árbol, entonces, se removerá del árbol y se asignará el sucesor del número borrado como el nuevo root del ábol, la complejidad temporal que presenta es de tiempo lineal, ó O(n) para el peor de los casos.

#función find

Análisis de complejidad temporal

El algoritmo presentado en una serie de llamadas recursivas de la misma función hasta encontrar el valor deseado, si no se encuentra un valor regresará un false, cuando se encuentra el valor deseado se planteará asignar el valor buscado como el nuevo root y se realizará un ordenamiento de los valores de acuerdo al valor buscado(funcion splay), la complejidad temporal que presenta es de tiempo lineal, ó O(n) para el peor de los casos.

#función inorder

Análisis de complejidad temporal

El algoritmo presentado funciona mediante una serie de llamadas recursivas de la misma función para obtener los valores encontrados en el árbol mientras no esté vacío, y comenzando de la ráiz y los valores menores, los valores estarán dilimitados por corchetes ( [ ] ), la complejidad temporal que presenta es de tiempo lineal, ó O(n) para el peor de los casos.

#función size

Análisis de complejidad temporal

El algoritmo presentado funciona mediante una serie de condicionales para aumentar o disminuir el tamaño de valores que se encuentran en el árbol según el uso de las funciones(add, remove, removeAll), la complejidad temporal que presenta es de tiempo constante, ó O(1) para el peor de los casos.


