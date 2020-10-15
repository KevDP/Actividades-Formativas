README.md

#función vist (Preorder, Inorder, Postorder, levelbylevel)

Análisis de complejidad temporal

El algoritmo presentado consiste en, através de auxiliares, llamar cuatro diferentes funciones las cuales, tres utilizan llamadas recursivas, es decir, que bajo cierta condición, será que el programa termine, si no es así, se mandará a llamar la función así misma hasta que el ciclo termine, la diferencia entre las tres primeras funciones no es mucha, en realidad lo que se pretende es que cada función obtenga y demuestre a partir del stringstream auxiliar, un orden diferente en obtención de los datos, la última función consiste en un recorrido por el árbol construido que, a partir de un stringstream genere una muestra de los datos ordenados en sentido del nivel en que se encuentran en el arbol (level = función height()), la complejidad temporal que presenta el algoritmo es de tiempo lineal para el peor de los casos, ó O(n) para el peor de los casos.

#función height

Análisis de complejidad temporal

El algoritmo presentado funciona mediante una serie de condicionales para cada uno de los casos posibles en la llamada recursiva, al final, regresa el dato a partir de otro condicional para asegurarse de que el cálculo en los datos no fuera incorrecto, decimos que el height entonces, servirá a partir de el recorrido de los nodos encontrados hacia izquierda o a la derecha y se irán sumando a las variables level_right o level_left, al final, la variable de mayor valor definirá la profundida que se tuvo en el árbol, la complejidad temporal que presenta es de tiempo lineal para el peor de los casos, ó O(n) para el peor de los casos.

#función ancestors

Análisis de complejidad temporal

El algoritmo presentado funciona a partir de una serie de condicionales, a partir del valor o dato proporcionado, las llamadas recursivas recorrerán los nodos arriba hasta la raíz, es decir, que se obtendrán todos los datos de los nodos ancestros del dato proporcionado, la complejidad temporal que presenta es de tiempo lineal para el peor de los casos, ó O(n) para el peor de los casos.

#función whatlevelamI

Análisis de complejidad temporal

El algoritmo presentado funciona mediante una serie de condicional donde a partir de un valor dado sea posible determinar el nivel de profundidad en el que está en el árbol, entonces, dependiendo si el valor es mayor o menor al obtenido, se realizarán llamadas recursivas para recorrer los nodos ya sea izquierda o derecha según sea el caso, si el valor es igual al proporcionado al inicio, se indicará que está en el nivel uno, es decir, en la raíz, la complejidad temporal que presenta es de tiempo lineal para el peor de los casos, ó O(n) para el peor de los casos.
