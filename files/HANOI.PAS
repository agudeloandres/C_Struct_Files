/*program torres_De_Hanoi( input, output );
  uses crt;
  type
    Torre            = 'A'..'c';
    Numero_De_Discos = 0..16;
  var
   Torre_Origen,Torre_Destino,Torre_De_paso : torre;
   discos: Numero_De_Discos;
{ ************************************************************************** }
procedure Apilar_Discos(N : Numero_De_Discos;Torre_Origen,
			Torre_Destino,Torre_De_paso : torre);
{ ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ }
procedure Mover(  Torre_Origen,Torre_Destino : torre);
  begin {procedure Mover}
   writeln( OUTPUT, ' Mover un disco de la torre ',
	    Torre_Origen, ' a la Torre ',Torre_Destino     )
  end;  {procedure Mover}
{ ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ }
begin {procedure Apilar_Discos}
 if N = 1 then
   Mover (  Torre_Origen,Torre_Destino )
 else
   begin
    Apilar_Discos(N-1,Torre_Origen,Torre_De_paso,Torre_Destino);
    Mover (  Torre_Origen,Torre_Destino );
    Apilar_Discos(N-1,Torre_De_paso,Torre_Destino,Torre_Origen)
   end
  {endif}
 end;{procedure Apilar_Discos}
{ ************************************************************************** }

begin {program torres_De_Hanoi}
 clrscr;
 write   ( OUTPUT, 'Este programa desplegar  la secuencia ');
 writeln ( OUTPUT, 'de movimientos para ');
 write   ( OUTPUT, 'las Torres de hanoi. cuando se le pida, ');
 writeln ( OUTPUT, 'teclee el n£mero ');
 write   ( OUTPUT, 'de discos. el m ximo n£mero es 16. ');
 writeln ( OUTPUT, 'Sin embargo, recuerde ');
 write   ( OUTPUT, 'que 16 discos desplegar¡an m s de 65,000 ');
 writeln ( OUTPUT, 'movimientos. ');
 writeln ( OUTPUT);
 write   ( OUTPUT, 'Cuando quiera terminar, teclee 0 para el n£mero ');
 writeln ( OUTPUT, 'de discos.');
 writeln ( OUTPUT);
 Torre_Origen :='A';Torre_destino := 'C'; Torre_De_Paso :='B';
 REPEAT
   write   ( OUTPUT, 'Cu ntos discos ser n movidos?  ');
   readln( INPUT,Discos );
   writeln ( OUTPUT);

   if Discos > 0 then
    begin
     writeln ( OUTPUT);
     writeln ( OUTPUT, 'Los movimientos para ',Discos :1,' discos son:');
     writeln ( OUTPUT);
     Apilar_Discos ( Discos,Torre_Origen,Torre_destino,torre_De_paso);
     writeln ( OUTPUT);
     writeln ( OUTPUT)
   end
  until Discos =0
  end. */

# include <conio.h>
# include <stdio.h>
# include <stdlib.h>
# include <dos.h>

main (){

int n;
clrscr();

printf ("digite el numero de discos que movera ");
scanf ("%d",&n);


