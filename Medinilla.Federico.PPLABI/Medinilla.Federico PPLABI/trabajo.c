#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "misFuncionesGet.h"
#include "mascota.h"
#include "tipoMascota.h"
#include "colorMascota.h"
#include "servicio.h"
#include "trabajo.h"

#define VACIO 1
#define OCUPADO 0

int initTrabajos(eTrabajo trabajos[],int tam)
{
    int error=1;

	if(trabajos!=NULL&&tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			trabajos[i].isEmpty=VACIO;
		}
		error=0;
	}

	return error;
}
void ordernarTrabajosxID(eTrabajo trabajos[],int tam)
{
    eTrabajo auxTrabajo;

    if(trabajos!=NULL && tam>0)
    {
        for (int i=0;i<tam-1;i++)
        {
            for(int x=i+1;x<tam;x++)
            {
                if(trabajos[i].id>trabajos[x].id)
                {
                    auxTrabajo=trabajos[i];
                    trabajos[i]=trabajos[x];
                    trabajos[x]=auxTrabajo;
                }
            }
        }
    }
}
int getEmptyIndexTrabajos(eTrabajo trabajos[],int tam)
{
	int indiceVacio=-1;

	if(trabajos!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			if(trabajos[i].isEmpty==VACIO)
			{
				indiceVacio=i;
				break;
			}
		}
	}
	return indiceVacio;
}
void mostrarTrabajo(eTrabajo trabajo,eMascota mascotas[],int mascotasTam,eServicio servicios[],int serviciosTam)
{
    if(!cargarNombreMascota(trabajo.idMascota,mascotas,mascotasTam,mascotas->nombreMascota)
       && !cargarDescripcionServicio(trabajo.idServicio,servicios,serviciosTam,servicios->descripcion))
    {
        printf("\n  |ID: %d|        %3d         %s      %s      %02d/%02d/%4d ",trabajo.id,trabajo.idMascota,mascotas->nombreMascota,servicios->descripcion,trabajo.fecha.dia,trabajo.fecha.mes,trabajo.fecha.anio);
        printf("\n---------------------------------\n");
    }
}
int mostrarTrabajos(eTrabajo trabajos[],int tam,eMascota mascotas[],int mascotasTam, eServicio servicios[],int serviciosTam)
{
    int error=0;
    int flag=1;

    ordernarTrabajosxID(trabajos,tam);
    if(trabajos!=NULL && tam>0)
    {
        for(int i=0;i<tam;i++)
        {
            if(trabajos[i].isEmpty==0)
            {
                printf("\n---------------------------------\n");
                printf("\nID TRABAJO    ID MASCOTA    MASCOTA        SERVICIO        FECHA");
                mostrarTrabajo(trabajos[i],mascotas,mascotasTam,servicios,serviciosTam);
                flag=0;
            }
        }
    }
    if(flag==1)
    {
        error=1;
    }
    return error;
}
int agregarTrabajo(eTrabajo trabajos[],int tam, int* idTrabajo,eMascota mascotas[],int mascotasTam,eServicio servicios[],int serviciosTam,eTipoMascota tipos[],int tiposTam,eColorMascota colores[],int coloresTam,eCliente clientes[],int clientesTam)
{
    int error=1;
    char salida;

    int indiceVacio;
    eTrabajo auxiliar;

    if(trabajos!=NULL && tam>0 && idTrabajo>0)
    {
        while(salida!='s')
        {
            indiceVacio=getEmptyIndexTrabajos(trabajos,tam);
            if(!mostrarMascotas(mascotas,mascotasTam,tipos,tiposTam,colores,coloresTam,clientes,clientesTam)
            &&!getNumero(&auxiliar.idMascota,"\nIngrese el ID de la mascota a la que quiere agregarle el TRABAJO: ","\nERROR - Re-ingrese el ID.",100,200)
            &&!mostrarServicios(servicios,serviciosTam)
            &&!getNumero(&auxiliar.idServicio,"\nIngrese el ID del servicio que quiere agregarle al TRABAJO: ","\nERROR - Re-ingrese el ID.",20000,20004)
            &&!getNumero(&auxiliar.fecha.dia,"\nIngrese el DIA: ","\nERROR - Re-ingrese el dia.",1,31)
            &&!getNumero(&auxiliar.fecha.mes,"\nIngrese el MES: ","\nERROR - Re-ingrese el mes.",1,12)
            &&!getNumero(&auxiliar.fecha.anio,"\nIngrese el ANIO: ","\nERROR - Re-ingrese el anio.",2020,2021))
            {
                auxiliar.id=*idTrabajo;
                printf("\nEste es el trabajo que quiere agregar?\n");
                mostrarTrabajo(auxiliar,mascotas,mascotasTam,servicios,serviciosTam);

                if(getDosChar("\nIngrese S para confirmar, o N para negar: ","\nERROR - Re-ingrese su eleccion.",'s','n')==0)
                {
                    auxiliar.isEmpty=OCUPADO;
                    trabajos[indiceVacio]=auxiliar;
                    (*idTrabajo)++;
                    error=0;
                    printf("\nCarga realizada con exito.");
                }
                else
                {
                    error=1;
                    printf("\nCarga cancelada.");
                }
            }
            if(getDosChar("\nDesea agregar otro?(S para confirmar, N para negar): ","\nERROR - Re-ingrese su eleccion.",'n','s')==0)
            {
                salida='s';
            }
            else
            {
                salida='n';
            }
        }
    }
    return error;
}



int cargarNombreMascota(int id,eMascota mascotas[],int tam, char nombreMascota[])
{
    int error=1;

    if(id>=100 && mascotas!=NULL && tam>0 && nombreMascota!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
            if(mascotas[i].id==id)
            {
                strcpy(nombreMascota,mascotas[i].nombreMascota);
                error=0;
                break;
            }
        }
    }
    return error;
}
int cargarDescripcionServicio(int id,eServicio servicios[],int tam, char descripcionServicio[])
{
    int error=1;

    if(id>=20000 && servicios!=NULL && tam>0 && descripcionServicio!=NULL)
    {
        for(int i=0;i<tam;i++)
        {
            if(servicios[i].id==id)
            {
                strcpy(descripcionServicio,servicios[i].descripcion);
                error=0;
                break;
            }
        }
    }
    return error;
}
