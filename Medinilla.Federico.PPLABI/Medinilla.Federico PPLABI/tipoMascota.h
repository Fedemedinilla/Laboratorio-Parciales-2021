#ifndef TIPOMASCOTA_H_INCLUDED
#define TIPOMASCOTA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[21];
}eTipoMascota;

int initTipos(eTipoMascota tipos[],int tam);
int mostrarTipo(eTipoMascota tipo);
int mostrarTipos(eTipoMascota tipos[],int tam);
#endif // TIPOMASCOTA_H_INCLUDED
