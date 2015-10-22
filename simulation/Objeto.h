#include<math.h>
#include <stdlib.h>
#include <stdio.h>
#define ITERACIONES 1000
class GeneradorKnuth
		  {
		  unsigned long M;
		  long Z0,A,C;
 public:
			GeneradorKnuth(long ,long ,long ,long);
			float Aleatorio(void);
          };  //objeto que genera los numeros aleatorios genarador de Knuth
//----------------------------------------------------------------------------
GeneradorKnuth::GeneradorKnuth(long MM,long Z00,long AA,long CC)
 {
  M=MM;
  Z0=Z00;          // constructor del generador de Knuth
  A=AA;
  C=CC;
 }
//----------------------------------------------------------------------------
 float GeneradorKnuth::Aleatorio(void)
 {
 float Zt=(A*Z0+C)%M;
 float Ut=Zt/M;
 Z0=Zt;
 return Ut;     // funcion generadora de numero aleatorios
 }

//----------------------------------------------------------------------------
class Simulador
      {                                  // Objeto que realiza la simulacion
      int NumeroPozos;
      float Probabilidad,Media,ValorPozo;
      float ProbabilidadDeZ;
      GeneradorKnuth *Generador;
public:
  Simulador();
  float ValorEsperado_Z(void);
  float  ValorTotal(void);
  int   ValorBinomial_Y(void);
  void   CambiarNumeroPozos(int);
  void   CambiarValorPozos(float);
  float  MostrarValorPozos();
  void   CambiarMedia(float);
  float  MostrarMedia();
  void   CambiarProbabilidad(float);
  float  MostrarProbabilidad();
  int    MostrarNumeroPozos();
  float MostrarProbabilidadDeZ();
  float ValorTotalProbabilidadZ(void);
  void CambiarValores(float ,float ,float ,float );
  };

//----------------------------------------------------------------------------
Simulador::Simulador()
{
 NumeroPozos=10;
 Probabilidad=1.0/5.0;              //constructor de la clase
 ValorPozo=10000.0;
 Media=50000.0;
 Generador=new GeneradorKnuth(2147483647,2,150005,3);
}
//----------------------------------------------------------------------------
void Simulador::CambiarValores(float Pro,float Med,float Val,float Poz)
{
Probabilidad=Pro;
Media=Med;
ValorPozo=Val;
NumeroPozos=Poz;
}
float Simulador::MostrarProbabilidad()
{
return Probabilidad;       // funcion que retorna el valor de la probabilidad
}
//----------------------------------------------------------------------------
float Simulador::MostrarValorPozos()
{
return ValorPozo;     // funcon que retorna el valor de costo por pozo
}
//----------------------------------------------------------------------------
float Simulador::MostrarMedia()
{
return Media;   //funcion que retorna el valor de la media de la funcion exp
}
//----------------------------------------------------------------------------
int  Simulador::ValorBinomial_Y(void)
 {
 float Valor_Y=0;
 for(int Contador=0;Contador<NumeroPozos;Contador++)
 if(Generador->Aleatorio()<=Probabilidad)
   Valor_Y++;
 return Valor_Y;        // funcion que retorna la cantidad de pozos donde puede
 }                      //haber petroleo utiliza la funcion binomial
 //----------------------------------------------------------------------------
float Simulador::ValorEsperado_Z(void)
{
float  Valor,ValorTotal=0;
for(int Contador=0;Contador<ITERACIONES;Contador++)
{
Valor=-1*Media*log(1-Generador->Aleatorio());
ValorTotal+=Valor;
}                                       // funcion que calcula el valor esperado de
ValorTotal=ValorTotal/ITERACIONES;      // Z esto lo hace calculado el promerio
return ValorTotal;                      // de varios datos.
}
//----------------------------------------------------------------------------
float  Simulador::ValorTotal(void)
{
float V0,V1,Total=0;
for (int a=0;a<100;a++)
 {
 V0=ValorEsperado_Z();
 V1=ValorBinomial_Y();
 Total+=V0*V1;
 }
Total=Total/100;  // esta calcula el valor esperado de Z y lo multiplica por
return Total;       //por la cantidad de pozos en los que se espera encontrar petroleo
}
//-----------------------------------------------------------------------------
float  Simulador::ValorTotalProbabilidadZ(void)
{
return 1-(1-exp(-1/Media*NumeroPozos*ValorPozo));
}
//----------------------------------------------------------------------------
float Simulador::MostrarProbabilidadDeZ()
{
return ProbabilidadDeZ;  //
}
//----------------------------------------------------------------------------
void Simulador::CambiarNumeroPozos(int Dato)
{
 NumeroPozos=Dato; // funcion que permite que el usuario cambie la cantidad de pozos
 }
void Simulador::CambiarValorPozos(float Dato)
{
 ValorPozo=Dato; //funcion que permite cambiar el valor por la perforacon de un pozo
}
//----------------------------------------------------------------------------
void Simulador::CambiarMedia(float Dato)
{
 Media=Dato; // esta funcion permite cambiar la media dee la funcion exponencial
}
//----------------------------------------------------------------------------
int Simulador::MostrarNumeroPozos()
{
return NumeroPozos; // retorna la cantidad de pozos en donde se haran perforaciones
}
//----------------------------------------------------------------------------
void Simulador::CambiarProbabilidad(float Dato)
{
 Probabilidad=Dato; // permite cambiar la probabilidad de consegir petroleo el
}                   // un pozo
//----------------------------------------------------------------------------


