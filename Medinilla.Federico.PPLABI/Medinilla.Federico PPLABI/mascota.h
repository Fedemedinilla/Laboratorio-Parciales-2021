#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

#include "tipoMascota.h"
#include "colorMascota.h"
#include "cliente.h"

typedef struct
{
    int id;
    char nombreMascota[21];
    int idCliente;
    int idTipo;
    int idColor;
    int edad;
    int isEmpty;
}eMascota;


/** \brief inicializa las MASCOTAS con sus respectivo isEmpty en VACIO
 *
 * \param mascotas[] eMascota array de estructuras de mascotas
 * \param tam int tamaño del array
 * \return int 1 si hubo un error, o 0 si esta todo bien
 *
 */
int initMascotas(eMascota mascotas[],int tam);
/** \brief agrega una mascota con todos sus campos completos al array de mascotas
 *
 * \param mascotas[] eMascota array de estructuras de mascotas
 * \param tam int tamaño del array
 * \param idMascota int* el id actual
 * \param tipos[] eTipoMascota array de tipos
 * \param tiposTam int tamaño del array
 * \param colores[] eColorMascota array de colores
 * \param coloresTam int tamaño del array
 * \return int 1 si hubo un error, o 0 si esta todo bien
 *
 */
int agregarMascota(eMascota mascotas[],int tam, int* idMascota,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam);
/** \brief modifica una mascota ya existente
 *
 * \param mascotas[] eMascota array de estructuras de mascotas
 * \param tam int tamaño del array
 * \param idMascota int* el id actual
 * \param tipos[] eTipoMascota array de tipos
 * \param tiposTam int tamaño del array
 * \param colores[] eColorMascota array de colores
 * \param coloresTam int tamaño del array
 * \return int 1 si hubo un error, o 0 si esta todo bien
 *
 */
int modificarMascota(eMascota mascotas[],int tam, int* idMascota,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam);
/** \brief muestra UNA mascota en consola
 *
 * \param mascota eMascota estructura de mascota
 * \param tipos[] eTipoMascota array de tipos
 * \param tiposTam int tamaño del array
 * \param colores[] eColorMascota array de colores
 * \param coloresTam int tamaño del array
 * \return void
 *
 */
void mostrarMascota(eMascota mascota,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam);
/** \brief muestra todas las mascotas
 *
 * \param mascota eMascota estructura de mascota
 * \param tipos[] eTipoMascota array de tipos
 * \param tiposTam int tamaño del array
 * \param colores[] eColorMascota array de colores
 * \param coloresTam int tamaño del array
 * \return int 1 si hubo un error, o 0 si esta todo bien
 *
 */
int mostrarMascotas(eMascota mascotas[],int tam, eTipoMascota tipos[],int tiposTam, eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam);
/** \brief busca en el array de mascotas por ID
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tam int tamaño del array
 * \param idBuscado int el id que esta buscando el usuario
 * \return int devuelve el INDICE en el que esta ubicado ese ID
 *
 */
int buscarxID(eMascota mascotas[],int tam,int idBuscado);
/** \brief realiza una baja logica de una mascota, cambiandole el isEmpty a VACIO
 *
 * \param mascota eMascota estructura de mascota
 * \param tipos[] eTipoMascota array de tipos
 * \param tiposTam int tamaño del array
 * \param colores[] eColorMascota array de colores
 * \param coloresTam int tamaño del array
 * \return int 1 si hubo un error, o 0 si esta todo bien
 *
 */
int bajaMascota(eMascota mascotas[],int tam,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam);
/** \brief muestra un mini-menu para que el usuario elija que modificar
 *
 * \return int 1 si hubo un error, o 0 si esta todo bien
 *
 */
int mostrarMenuParaModificar();
/** \brief carga las descripciones de los TIPOS en el indice indicado para ser mostrados
 *
 * \param id int se usa el id para elegir la descripcion
 * \param tipos[] eTipoMascota array de tipos
 * \param tam int tamaño del array
 * \param descripcion[] char donde se va a guardar la descripcion cargada
 * \return int 1 si hubo un error, o 0 si esta todo bien
 *
 */
int cargarDescripcionTipo(int id,eTipoMascota tipos[],int tam, char descripcion[]);
/** \brief carga las descripciones de los COLORES en el indice indicado para ser mostrados
 *
 * \param id int se usa el id para elegir la descripcion
 * \param tipos[] eColorMascota array de colores
 * \param tam int tamaño del array
 * \param descripcion[] char donde se va a guardar la descripcion cargada
 * \return int 1 si hubo un error, o 0 si esta todo bien
 *
 */
int cargarNombreColor(int id,eColorMascota colores[],int tam, char nombreColor[]);
/** \brief ordena las mascotas por ID de forma ascendente
 *
 * \param mascotas[] eMascota array de mascotas
 * \param tam int tamaño del array
 * \return void
 *
 */
void ordernarMascotasxID(eMascota mascotas[],int tam);

int cargarNombreCliente(int id,eCliente clientes[],int tam, char nombreCliente[]);
int mostrarMascotasPorColor(eMascota mascotas[],int tam,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam);
int buscarMascotaPorColor(eMascota mascotas[],int tam,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,int id, eCliente clientes[],int clientesTam);
int buscarMascotasPorTipo(eMascota mascotas[],int tam,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,int id, eCliente clientes[],int clientesTam);
int mostrarMascotasPorTipo(eMascota mascotas[],int tam,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam);
int mostrarMascotaDeMenorEdad(eMascota mascotas[],int tam);


#endif // MASCOTA_H_INCLUDED
