#ifndef COLORMASCOTA_H_INCLUDED
#define COLORMASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[21];
}eColorMascota;

/** \brief incializa los COLORES con sus descripciones
 *
 * \param colores[] eColorMascota el array de colores
 * \param tam int el tamaño del array
 * \return int 1 si hubo un error, o 0 si esta todo bien
 *
 */
int initColores(eColorMascota colores[],int tam);
/** \brief muestra UN color
 *
 * \param color eColorMascota estructura de color
 * \return int 1 si hubo un error, o 0 si esta todo bien
 *
 */
int mostrarColor(eColorMascota color);
/** \brief muestra TODOS los colores
 *
 * \param colores[] eColorMascota array de la estructura
 * \param tam int tamaño del array
 * \return int 1 si hubo un error, o 0 si esta todo bien
 *
 */
int mostrarColores(eColorMascota colores[],int tam);
#endif // COLORMASCOTA_H_INCLUDED
