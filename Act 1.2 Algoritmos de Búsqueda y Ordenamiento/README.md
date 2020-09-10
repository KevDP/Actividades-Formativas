README.md

#Método de Seleccion

Análisis de complejidad temporal

El algoritmo presentado recorre n por n pasos, pues se utiliza ciclos anidados, el primero es i que va desde el tamaño del arreglo - 1 hasta llegar a cero, es decir, que va disminuyendo i con cada paso hasta que sea cero, el segundo es j que va desde 1 hasta i, aumentando j con cada paso, por lo que se simularía que el arreglo se recorrería de derecha a izquierda, dicho esto, se puede afirmar que es de tiempo cuadrático, ó O(n^2) para el peor de los casos.

#Método de Burbuja

Análisis de complejidad temporal

De la misma forma que el anterior, este algoritmo presentado recorre n por n pasos, pues se utiliza ciclos anidados, el primero es i que va desde el tamaño del arreglo - 1 hasta llegar a cero, es decir, que va disminuyendo la cantidad de número que toma con cada paso hasta que se agoten, el segundo es j que va desde 1 hasta i, aumentando con cada paso, por lo que también se simularía que el arreglo se recorrería de derecha a izquierda, dicho esto, se puede afirmar que es de tiempo cuadrático, ó O(n^2) para el peor de los casos.

#Método Merge

Análisis de complejidad temporal

El algoritmo presentado funciona partir el arreglo a la mitad de tal forma como lo haría una estructura de árbol, pero también realizará comparaciones a manera de los subgrupos generados en cada nivel, dicho esto, se afirma que el algoritmo es de tiempo On(log(n)) para el peor de los casos.

#Búsqueda Secuencial

Análisis de complejidad temporal

El algoritmo presentado utiliza un ciclo que recorre desde 0 hasta llegar al tamaño del arreglo, dicho esto, se puede afirmar que es de tiempo lineal, ó O(n) para el peor de los casos.

#Búsqueda Binaria

Análisis de complejidad temporal

El algoritmo presentado funciona tomando mid como punto inicial y partir el array a la mitad en esa posición, formando un árbol con las particiones de los arreglos, de esta forma valida si el valor buscado es mayor o menor que mid y aumenta o disminuye su posición hasta encontrarlo, entonces podemos decir que, el algoritmo es de tiempo logarítmico, ó O(log(n)) para el peor de los casos.
