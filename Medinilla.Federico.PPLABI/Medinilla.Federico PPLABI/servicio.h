#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[26];
    float precio;
}eServicio;

/** \brief inicializa los servicios con sus respectivas descripciones
 *
 * \param servicios[] eServicio array de servicios
 * \param tam int tamaño del array
 * \return int 1 si hubo un error, o 0 si esta todo bien
 *
 */
int initServicios(eServicio servicios[],int tam);
/** \brief muestra UN servicio
 *
 * \param servicio eServicio la estructura de un servicio
 * \return int 1 si hubo un error, o 0 si esta todo bien
 *
 */
int mostrarServicio(eServicio servicio);
/** \brief muestra TODOS los servicios
 *
 * \param servicios[] eServicio array de servicios
 * \param tam int tamaño del array
 * \return int 1 si hubo un error, o 0 si esta todo bien
 *
 */
int mostrarServicios(eServicio servicios[],int tam);
#endif // SERVICIO_H_INCLUDED
