#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

#include "fecha.h"

typedef struct
{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;
    int isEmpty;
}eTrabajo;

/** \brief inicializa los trabajos poniendoles isEmpty en VACIO
 *
 * \param array de trabajos
 * \param tamaño del array
 * \return 1 si hubo un error, o 0 si esta todo bien
 *
 */
int initTrabajos(eTrabajo trabajos[],int tam);
/** \brief ordena los trabajos por ID de forma ascendente
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam int tamaño del array
 * \return void
 *
 */
void ordernarTrabajosxID(eTrabajo trabajos[],int tam);
/** \brief encuentra el indice del primer trabajo con el isEmpty vacio
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam int tamaño del array
 * \return 1 si hubo un error, o 0 si esta todo bien
 *
 */
int getEmptyIndexTrabajos(eTrabajo trabajos[],int tam);
/** \brief muestra un trabajo en pantalla
 *
 * \param trabajo eTrabajo estructura de trabajo
 * \param mascotas[] eMascota array de mascotas
 * \param mascotasTam int tamaño del array
 * \param servicios[] eServicio array de servicios
 * \param serviciosTam int tamaño del array
 * \return void
 *
 */
void mostrarTrabajo(eTrabajo trabajo,eMascota mascotas[],int mascotasTam,eServicio servicios[],int serviciosTam);
/** \brief muestra TODOS los trabajos
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam int tamaño del array
 * \param mascotas[] eMascota array de mascotas
 * \param mascotasTam int tamaño del array
 * \param servicios[] eServicio array de servicios
 * \param serviciosTam int tamaño del array
 * \return 1 si hubo un error, o 0 si esta todo bien
 *
 */
int mostrarTrabajos(eTrabajo trabajos[],int tam,eMascota mascotas[],int mascotasTam, eServicio servicios[],int serviciosTam);
/** \brief agrega un trabajo al array de trabajos
 *
 * \param trabajos[] eTrabajo array de trabajos
 * \param tam int tamaño del array
 * \param idTrabajo int* el id actual de los trabajos
 * \param mascotas[] eMascota array de mascotas
 * \param mascotasTam int tamaño del array
 * \param servicios[] eServicio array de servicios
 * \param serviciosTam int tamaño del array
 * \param tipos[] eTipoMascota array de tipos
 * \param tiposTam int tamaño del array
 * \param colores[] eColorMascota array de colores
 * \param coloresTam int tamaño del array
 * \return 1 si hubo un error, o 0 si esta todo bien
 *
 */
int agregarTrabajo(eTrabajo trabajos[],int tam, int* idTrabajo,eMascota mascotas[],int mascotasTam,eServicio servicios[],int serviciosTam,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam);
/** \brief carga los nombres de las mascotas en sus respectivos indices
 *
 * \param id int id de la mascota
 * \param mascotas[] eMascota array de mascotas
 * \param tam int tamaño del array
 * \param nombreMascota[] char string con el nombre de la mascota
 * \return 1 si hubo un error, o 0 si esta todo bien
 *
 */
int cargarNombreMascota(int id,eMascota mascotas[],int tam, char nombreMascota[]);
/** \brief carga las descripciones de los servicios en sus respectivos indices
 *
 * \param id int id del servicio
 * \param servicios[] eServicio array de servicios
 * \param tam int tamaño del array
 * \param descripcionServicio[] char descripcion del servicio
 * \return 1 si hubo un error, o 0 si esta todo bien
 *
 */
int cargarDescripcionServicio(int id,eServicio servicios[],int tam, char descripcionServicio[]);
#endif // TRABAJO_H_INCLUDED
