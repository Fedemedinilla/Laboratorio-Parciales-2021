#ifndef COLORMASCOTA_H_INCLUDED
#define COLORMASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[21];
}eColorMascota;

int initColores(eColorMascota colores[],int tam);
int mostrarColor(eColorMascota color);
int mostrarColores(eColorMascota colores[],int tam);
#endif // COLORMASCOTA_H_INCLUDED
