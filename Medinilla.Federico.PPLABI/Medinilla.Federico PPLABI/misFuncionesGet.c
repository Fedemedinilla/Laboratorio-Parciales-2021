#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "misFuncionesGet.h"

int getString(char cadena[],int len)
{
	int error=1;
	char auxiliar[5001];

	if(cadena!=NULL && len>0)
	{
		fflush(stdin);
		if(fgets(auxiliar,sizeof(auxiliar),stdin)!=NULL)
		{
			if(auxiliar[strnlen(auxiliar,sizeof(auxiliar))-1] == '\n')
			{
				auxiliar[strnlen(auxiliar,sizeof(auxiliar))-1] = '\0';
			}
			if(strnlen(auxiliar,sizeof(auxiliar))<=len)
			{
				strncpy(cadena,auxiliar,len);
				error=0;
			}
		}
	}
	return error;
}
int getInt(int* resultado)
{
	int error=1;
	char auxiliar[5001];

	if(resultado!=NULL
		&& getString(auxiliar,sizeof(auxiliar))==0
		&& esNumerica(auxiliar,sizeof(auxiliar)))
	{
		*resultado=atoi(auxiliar);
		error=0;
	}
	return error;
}
int getFloat(float* resultado)
{
	int error=1;
	char auxiliar[5001];

	if(resultado!=NULL
		&& getString(auxiliar,sizeof(auxiliar))==0
		&& esFlotante(auxiliar,sizeof(auxiliar)))
	{
		*resultado=atof(auxiliar);
		error=0;
	}
	return error;
}
int esNumerica(char cadena[],int len)
{
	int error=1;
	int i;

	for(i=0;i<len && cadena[i]!='\0';i++)
	{
		if(cadena[i]=='-' || cadena[i]=='+')
		{
			continue;
		}
		if(cadena[i]>'9' || cadena[i]<'0')
		{
			error=0;
			break;
		}
	}
	return error;
}
int esFlotante(char cadena[],int len)
{
	int error=1;
	int i;

	for(i=0;i<len && cadena[i]!='\0';i++)
	{
		if(cadena[i]==',' || cadena[i]=='.')
		{
			continue;
		}
		if(cadena[i]>'9' || cadena[i]<'0')
		{
			error=0;
			break;
		}
	}
	return error;
}
int getNumero(int* resultado,char msg[],char msgError[],int min,int max)
{
	int error=1;
	int auxiliar;

	if(resultado!=NULL
			&& msg!=NULL
			&& msgError!=NULL
			&& min<=max)
	{
		do
		{
			printf("%s",msg);
			if(getInt(&auxiliar)==0
					&& auxiliar>=min
					&& auxiliar<=max)
			{
				*resultado=auxiliar;
				error=0;
				break;
			}
			printf("%s",msgError);
		}while(error!=0);
	}
	return error;
}
int getFlotante(float* resultado,char msg[],char msgError[],int min,int max)
{
	int error=1;
	float auxiliar;

	if(resultado!=NULL
			&& msg!=NULL
			&& msgError!=NULL
			&& min<=max)
	{
		do
		{
			printf("%s",msg);
			if(getFloat(&auxiliar)==0
					&& auxiliar>=min
					&& auxiliar<=max)
			{
				*resultado=auxiliar;
				error=0;
				break;
			}
			printf("%s",msgError);
		}while(error!=0);
	}
	return error;
}
int getNombre(char nombre[], char inputMsg[],char errorMsg[], int tam)
{
	int error=1;
    char auxiliar[51];
    int len;

    printf("%s",inputMsg);
    fflush(stdin);
    scanf("%[^\n]",auxiliar);
    strlwr(auxiliar);
    len=strlen(auxiliar);

    auxiliar[0]=toupper(auxiliar[0]);

    while(strlen(auxiliar)>tam-1)
    {
        printf("%s",errorMsg);
        fflush(stdin);
        scanf("%[^\n]",auxiliar);
        strlwr(auxiliar);
        len=strlen(auxiliar);

        auxiliar[0]=toupper(auxiliar[0]);

        for(int i=0;i<len;i++)
        {
            if(isspace(auxiliar[i]))
            {
            	auxiliar[i+1]=toupper(auxiliar[i+1]);
            }
        }
    }
    for(int i=0;i<tam;i++)
    {
        if(isspace(auxiliar[i]))
        {
        	auxiliar[i+1]=toupper(auxiliar[i+1]);
        }
    }
    strcpy(nombre,auxiliar);
    error=0;
    return error;
}
