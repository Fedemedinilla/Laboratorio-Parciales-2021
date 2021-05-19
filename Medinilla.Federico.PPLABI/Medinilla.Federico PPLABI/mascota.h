#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED

#include "tipoMascota.h"
#include "colorMascota.h"

typedef struct
{
    int id;
    char nombreMascota[21];
    int idTipo;
    int idColor;
    int edad;
    int isEmpty;
}eMascota;


int initMascotas(eMascota mascotas[],int tam);
int agregarMascota(eMascota mascotas[],int tam, int* idMascota);
int mostrarMascota(eMascota mascota, eTipoMascota tipo, eColorMascota color);
int buscarxID(eMascota mascotas[],char msg[],char msgError[],int tam,int* idBuscado);
int bajaMascota(eMascota mascotas[], int tam, int* idBuscado);
#endif // MASCOTA_H_INCLUDED
