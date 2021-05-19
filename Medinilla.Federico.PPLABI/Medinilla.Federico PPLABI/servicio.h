#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[26];
    float precio;
}eServicio;

int initServicios(eServicio servicios[],int tam);
#endif // SERVICIO_H_INCLUDED
