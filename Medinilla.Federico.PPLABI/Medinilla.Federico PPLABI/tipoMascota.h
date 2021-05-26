#ifndef TIPOMASCOTA_H_INCLUDED
#define TIPOMASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[21];
}eTipoMascota;


/** \brief inicializa los tipos con sus descripciones
 *
 * \param tipos[] eTipoMascota el array de tipos
 * \param tam int el tamaño del array
 * \return int 1 si hubo error, o 0 si esta todo bien
 *
 */
int initTipos(eTipoMascota tipos[],int tam);
/** \brief muestra UN tipo de mascota
 *
 * \param tipo eTipoMascota recibe una estructura
 * \return int 1 si hubo error, o 0 si esta todo bien
 *
 */
int mostrarTipo(eTipoMascota tipo);
/** \brief muestra TODOS los tipos de mascota
 *
 * \param tipos[] eTipoMascota recibe un array de la estructura
 * \param tam int el tamaño del array
 * \return int 1 si hubo error, o 0 si esta todo bien
 *
 */
int mostrarTipos(eTipoMascota tipos[],int tam);
#endif // TIPOMASCOTA_H_INCLUDED
