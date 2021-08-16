#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include "testing.h"

#define TAM 20
#define MULTIPLICADOR 2

void inicializar_vector(int numeros[], int tope){

	for(int i = 0; i < tope; i++){
		numeros[i] = i*MULTIPLICADOR;
	}
}

bool prueba_encolar(cola_t* cola, void* elem){

	if(cola_encolar(cola, elem)){
		return true;
	}

	return false;
}

bool prueba_desencolar(cola_t* cola, void* elem){

	if(cola_desencolar(cola) == elem){
		return true;
	}

	return false;
}

bool prueba_encolar_iterado(cola_t* cola, int numeros[], int tope){

	for(int i = 0; i < tope; i++){
		if(!cola_encolar(cola, &numeros[i])){
			return false;
		}
	}

	return true;
}

bool prueba_ver_primero(cola_t* cola, void* elem){

	if(cola_ver_primero(cola) == elem){
		return true;
	}

	return false;
}

bool prueba_ver_primero_int(cola_t* cola, int* elem){

	if(*(int*)cola_ver_primero(cola) == (*elem)){
		return true;
	}

	return false;
}

bool prueba_desencolar_iterado(cola_t* cola, int numeros[], int tope){

	for(int i = 0; i < tope-1; i++){
		if(!(cola_desencolar(cola) == &numeros[i])){
			return false;
		}
		if(!prueba_ver_primero(cola, &numeros[i+1])){
			return false;
		}
		if(!prueba_ver_primero_int(cola, &numeros[i+1])){
			return false;
		}
	}

	if(!(cola_desencolar(cola) != NULL)){
		return false;
	}

	return true;
}

void prueba_encolar_y_desencolar_mismo_tipo(cola_t* cola){

	int numeros[TAM];
	int tope = TAM-1;

	inicializar_vector(numeros, tope);

	print_test("Se encoló iterado", prueba_encolar_iterado(cola, numeros, tope));
	print_test("Ver primero iterado", prueba_ver_primero(cola, &numeros[0]));
	print_test("Ver primero int iterado", prueba_ver_primero_int(cola, &numeros[0]));

	print_test("Desencolar iterado", prueba_desencolar_iterado(cola, numeros, tope));
}

void prueba_encolar_dinamic(cola_t* cola){

	int* num = malloc(sizeof(int));

	if(!num) return;

	char* letra = malloc(sizeof(char));

	if(!letra){
		free(num);
		return;
	}

	float* num2 = malloc(sizeof(float));

	if(!num2){
		free(num);
		free(letra);
		return;
	}

	(*num) = 30;
	(*letra) = 'b';
	(*num2) = 42.78f;

	print_test("Se encoló num", prueba_encolar(cola, num));
	print_test("Se encoló letra", prueba_encolar(cola, letra));
	print_test("Se encoló num2", prueba_encolar(cola, num2));

	print_test("Ver primero", prueba_ver_primero(cola, num));
}

void prueba_encolar_y_desencolar_distinto(cola_t* cola){

	int num = 1, num2 = 10;
	char* palabra = "Hola";
	char letra = 'K', caracter = '@';
	int* num3 = malloc(sizeof(int));

	if(!num3) return;

	(*num3) = 42;

	double* num4 = malloc(sizeof(double));

	if(!num4){
		free(num3);
		return;
	}

	(*num4) = 13.4;

	print_test("Se encoló num", prueba_encolar(cola, &num));
	print_test("Se encoló num4", prueba_encolar(cola, num4));
	print_test("Se encoló palabra", prueba_encolar(cola, palabra));
	print_test("Se encoló letra", prueba_encolar(cola, &letra));
	print_test("Se encoló num2", prueba_encolar(cola, &num2));
	print_test("Se encoló caracter", prueba_encolar(cola, &caracter));
	print_test("Se encoló num3", prueba_encolar(cola, num3));

	print_test("Ver primero num", prueba_ver_primero(cola, &num));

	print_test("Desencolar num", prueba_desencolar(cola, &num));
	print_test("Ver primero num4", prueba_ver_primero(cola, num4));

	print_test("Desencolar num4", prueba_desencolar(cola, num4));
	print_test("Ver primero palabra", prueba_ver_primero(cola, palabra));

	print_test("Desencolar palabra", prueba_desencolar(cola, palabra));
	print_test("Ver primero letra", prueba_ver_primero(cola, &letra));

	print_test("Desencolar letra", prueba_desencolar(cola, &letra));
	print_test("Ver primero num2", prueba_ver_primero(cola, &num2));

	print_test("Desencolar num2", prueba_desencolar(cola, &num2));
	print_test("Ver primero caracter", prueba_ver_primero(cola, &caracter));

	print_test("Desencolar caracter", prueba_desencolar(cola, &caracter));
	print_test("Ver primero num3", prueba_ver_primero(cola, num3));

	print_test("Desencolar num3", prueba_desencolar(cola, num3));

	free(num3);
	free(num4);
}

void prueba_encolar_y_desencolar_varias_veces(cola_t* cola){

	int numero = 50;

	print_test("Encolar numero", prueba_encolar(cola, &numero));
	print_test("Ver primero", prueba_ver_primero(cola, &numero));
	print_test("Desencolar numero", prueba_desencolar(cola, &numero));

	print_test("cola está vacía", cola_esta_vacia(cola));

	char letra = 'p';

	print_test("Encolar letra", prueba_encolar(cola, &letra));
	print_test("Ver primero", prueba_ver_primero(cola, &letra));
	print_test("Desencolar letra", prueba_desencolar(cola, &letra));

	print_test("cola está vacía", cola_esta_vacia(cola));	

	print_test("Encolar numero", prueba_encolar(cola, &numero));
	print_test("Ver primero numero", prueba_ver_primero(cola, &numero));
	print_test("Desencolar numero", prueba_desencolar(cola, &numero));
}

void prueba_encolar_stack(cola_t* cola){

	int numeros[TAM];
	int tope = TAM-1;

	inicializar_vector(numeros, tope);

	print_test("Encolar iterado (20)", prueba_encolar_iterado(cola, numeros, tope));
	print_test("Ver primero", prueba_ver_primero(cola, &numeros[0]));
	print_test("Ver primero int", prueba_ver_primero_int(cola, &numeros[0]));
}

void prueba_encolar_null(cola_t* cola){

	for(int i = 0; i < TAM; i++){
		print_test("Se encoló NULL", cola_encolar(cola, NULL));
	}

	prueba_ver_primero(cola, NULL);
}

void pruebas_crear_y_destruir(){

	cola_t* cola_vacia = cola_crear();
	cola_t* cola_nueva = cola_crear();	// ENCOLAR Y DESENCOLAR MISMO TIPO
	cola_t* cola_nueva2 = cola_crear();	// ENCOLAR VARIABLES EN MEMORIA DINÁMICA
	cola_t* cola_nueva3 = cola_crear();	// ENCOLAR Y DESENCOLAR DISTINTO TIPO
	cola_t* cola_nueva4 = cola_crear();	// ENCOLAR Y DESENCOLAR VARIAS VECES
	cola_t* cola_nueva5 = cola_crear(); // ENCOLAR VARIABLES EN MEMORIA ESTÁTICA
	cola_t* cola_nueva6 = cola_crear(); // ENCOLAR NULL

	printf("\tPRUEBAS CREAR NUEVA COLA\n");
	print_test("Se creó cola_vacia", cola_vacia != NULL);
	print_test("Se creó cola_nueva", cola_nueva != NULL);
	print_test("Se creó cola_nueva2", cola_nueva2 != NULL);
	print_test("Se creó cola_nueva3", cola_nueva3 != NULL);
	print_test("Se creó cola_nueva4", cola_nueva4 != NULL);
	print_test("Se creó cola_nueva5", cola_nueva5 != NULL);
	print_test("Se creó cola_nueva6", cola_nueva6 != NULL);

	printf("\tPRUEBAS ENCOLAR Y DESENCOLAR\n");
	printf("\tPrueba encolar y desencolar mismo tipo.\n");
	prueba_encolar_y_desencolar_mismo_tipo(cola_nueva);
	printf("\tPrueba encolar dinamic.\n");
	prueba_encolar_dinamic(cola_nueva2);
	printf("\tPrueba encolar y desencolar distinto.\n");
	prueba_encolar_y_desencolar_distinto(cola_nueva3);
	printf("\tPrueba encolar y desencolar varias veces.\n");
	prueba_encolar_y_desencolar_varias_veces(cola_nueva4);
	printf("\tPrueba encolar stack.\n");
	prueba_encolar_stack(cola_nueva5);
	printf("\tPrueba encolar NULL\n");
	prueba_encolar_null(cola_nueva6);

	printf("\tPRUEBAS INVÁLIDAS\n");
	print_test("desencolar cola_vacia devuelve NULL", cola_desencolar(cola_vacia) == NULL);
	print_test("desencolar cola_nueva devuelve NULL", cola_desencolar(cola_nueva) == NULL);
	print_test("desencolar cola_nueva3 devuelve NULL", cola_desencolar(cola_nueva3) == NULL);
	print_test("desencolar cola_nueva4 devuelve NULL", cola_desencolar(cola_nueva4) == NULL);
	print_test("ver primero cola_vacia devuelve NULL", cola_ver_primero(cola_vacia) == NULL);

	printf("\tPRUEBA ESTA VACIA\n");
	print_test("cola_vacia está vacía", cola_esta_vacia(cola_vacia));
	print_test("cola_nueva está vacía", cola_esta_vacia(cola_nueva));
	print_test("cola_nueva2 NO está vacía", !cola_esta_vacia(cola_nueva2));
	print_test("cola_nueva3 está vacía", cola_esta_vacia(cola_nueva3));
	print_test("cola_nueva4 está vacía", cola_esta_vacia(cola_nueva4));
	print_test("cola_nueva5 NO está vacía", !cola_esta_vacia(cola_nueva5));
	print_test("cola_nueva6 NO está vacía", !cola_esta_vacia(cola_nueva6));

	printf("\tPRUEBAS DESTRUIR COLA\n");
	cola_destruir(cola_vacia, NULL);
	print_test("Se destruyó cola_vacia", true);
	cola_destruir(cola_nueva, NULL);
	print_test("Se destruyó cola_nueva", true);
	cola_destruir(cola_nueva2, free);
	print_test("Se destruyó cola_nueva2", true);
	cola_destruir(cola_nueva3, NULL);
	print_test("Se destruyó cola_nueva3", true);
	cola_destruir(cola_nueva4, NULL);
	print_test("Se destruyó cola_nueva4", true);
	cola_destruir(cola_nueva5, NULL);
	print_test("Se destruyó cola_nueva5", true);
	cola_destruir(cola_nueva6, NULL);
	print_test("Se destruyó cola_nueva6", true);
}

void pruebas_cola_alumno(void){

	pruebas_crear_y_destruir();
}