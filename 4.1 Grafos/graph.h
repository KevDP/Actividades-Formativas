#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;


string show_vector(vector<int> vec){
	string result = "";
	for (int i=0; i<vec.size(); i++){
		result = result + to_string(vec[i]) + " ";
	}
	return result;
}


class Graph {
	private:
	vector<vector<int>> adj_matrix; // Matriz de adyacencia con vectores anidados 
	vector<vector<int>> adj_list; // Lista de adyancencia con vectores anidados
	int num_vertices;  // Número de vertices
	int num_arcos; // Número de arcos

	public:
	Graph(){}   // Constructor por default

	//  - Funciones para cargar -
	void loadGraphMat(string filename, int vertices, int arcos);
	void loadGraphList(string filename, int vertices, int arcos);

	// - Funciones para imprimir -
	string printAdjMat();
	string printAdjList();

	// - Algoritmos de búsqueda -
	string DFS(int init_vertex, int target_vertex);
	string BFS(int init_vertex, int target_vertex);
};


void Graph::loadGraphMat(string filename, int vertices, int arcos){

	num_arcos = arcos;
	num_vertices = vertices;

	// - Crear matriz de adyancencia -

	for (int i=0; i<vertices; i++){
		vector<int> row(vertices, 0);
		adj_matrix.push_back(row);
	}

  // - Leer archivos -

	ifstream file;
	file.open(filename);
	while(file.good()){
		string x; // (2, 3)
		string y;
		getline(file, x, ',');
    if (x != ""){
			getline(file, y, '\n'); 
			x = x.substr(1, x.length()-1);
			y = y.substr(1, y.length()-2);
			int x_node = stoi(x);
			int y_node = stoi(y);

			// - Llenar el grafo -

			adj_matrix[x_node][y_node] = 1;
			adj_matrix[y_node][x_node] = 1; 
		}
	}
}



void Graph::loadGraphList(string filename, int vertices, int arcos){

	num_vertices = vertices;
	num_arcos = arcos;

	// - Crear lista de adyacencia -

	for (int i=0; i<vertices; i++){
		vector<int> row;
		adj_list.push_back(row);
	}

	// - Leer archivos -

		ifstream file;
	file.open(filename);
	while(file.good()){
		string x; // (2, 3)
		string y;
		getline(file, x, ',');
    if (x != ""){
			getline(file, y, '\n'); 
			x = x.substr(1, x.length()-1);
			y = y.substr(1, y.length()-2);
			int x_node = stoi(x);
			int y_node = stoi(y);

			// - Llenar el grafo -

			adj_list[x_node].push_back(y_node);
			adj_list[y_node].push_back(x_node); 
		}
	}
}

string Graph::printAdjMat(){
	string matrix = "";
	for(int i=0; i<adj_matrix.size(); i++){
		for(int j=0; j<adj_matrix[i].size(); j++){
			matrix = matrix + to_string(adj_matrix[i][j]) + " ";
		}
	}
	return matrix;
}

string Graph::printAdjList(){

	string list = "";

	for(int i=0; i<adj_list.size(); i++){
		list += "vertex " + to_string(i) + " : ";
		sort(adj_list[i].begin(), adj_list[i].end());
		for(int j=0; j<adj_list[i].size(); j++){
			list += to_string(adj_list[i][j]) + " ";
		}
	}
	return list;
}


string Graph::DFS(int init_vertex, int target_vertex){

	// - Copiar la lista de adyacencia (adj_list) -

	vector<vector<int>> adj_list_copia;
	for (int i=0; i<adj_list.size(); i++){
		adj_list_copia.push_back(adj_list[i]);
	}

	vector<int> stack;
	vector<int> visited;
	bool found = false;
	int current = init_vertex;

	while (!found && !(visited.size() >= num_vertices)){

		// - ¿Ya ha sido visitado? -

		bool already_visited = false;
		for (int i=0; i<visited.size(); i++){
			if(current == visited[i]) {
				already_visited = true;
				break;
			}
		}

		// - Agregar a visitados -

		if (!already_visited) visited.push_back(current);

		// - ¿Ya se encontró? -

		if (current == target_vertex){
			found = true;
			break;
		}

		// - Borrar valores ya visitados -

		for (int i=0; i<adj_list_copia[current].size(); i++){
			for (int j=0; j<visited.size(); j++){
				if(adj_list_copia[current][i] == visited[j])
					adj_list_copia[current].erase(adj_list_copia[current].begin()+i);
			}
		}
		if (adj_list_copia[current].size() > 0){
			stack.push_back(current);

			// - Revisar al último hijo del nodo -

			int temp_index = current;
			current = adj_list_copia[current].back();
			adj_list_copia[temp_index].pop_back();
		} 
		else {

			// - ¿Tocó "pared" alguna?

			current = stack[stack.size()-1];
			stack.pop_back();
		}
	}
	stack.push_back(current);
	
	// - Cambiar toda la lista a string -

	string visited_str = show_vector(visited);
	string path_str = show_vector(stack);
	string list_result = "visited: " + visited_str + "path: " + path_str;
	list_result = list_result.substr(0, list_result.size()-1);
	return list_result;
}


string Graph::BFS(int init_vertex, int target_vertex){
  
	vector<vector<int>> queue;
	vector<vector<int>> visited;
	int current = init_vertex;
	int parent = -1;
	bool found = false;

	while (true){

		// - Agregar a visitados -

		visited.push_back(vector<int>({parent, current}));

		// - ¿Ha sido encontrado? -
		if (current == target_vertex){
			found = true;
			break;
		}

		// - Ingresar a la queue de no ser encontrado -

		for (int i=0; i<adj_list[current].size(); i++){
			int val = adj_list[current][i];
			bool already_visited = false;
			for (int j=0; j<visited.size(); j++){
				if (visited[j][1] == val){
					already_visited = true;
					break;
				}
			}
			if (!already_visited) queue.push_back(vector<int>({current, val}));
		}

		// - Traer de la queue -

		parent = queue[0][0];
		current = queue[0][1];
		queue.erase(queue.begin());
	}
  
	// - Obtener el recorrido (más corto) -

	vector<int> path;
	int find = target_vertex;
	do {
		for (int i=0; i<visited.size(); i++){
			if (visited[i][1] == find){
				path.insert(path.begin(), find);
				find = visited[i][0];
			}
		}
	} while (find != -1);
	vector<int> converted_visited;
	for (int i=0; i<visited.size(); i++){
		converted_visited.push_back(visited[i][1]);
	}

	// Cambiar toda la lista a string

	string visited_str = show_vector(converted_visited);
	string path_str = show_vector(path);
	string matrix_result = "visited: " + visited_str + "path: " + path_str;
	matrix_result = matrix_result.substr(0, matrix_result.size()-1);
	return matrix_result;	
}