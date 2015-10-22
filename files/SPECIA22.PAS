program menus;
uses
crt,graph;
var
x : integer;


procedure opciones(opc,l:integer);
begin
 setcolor(l);
 case opc of
  1:outtextxy(200,170,'1. CREACION ');
  2:outtextxy(200,200,'2. INSERCION');
  3:outtextxy(200,230,'3. ELIMINACION');
  4:outtextxy(200,260,'4. CONCATENACION');
  5:outtextxy(200,290,'5. SALIR');
 end;
end;
procedure escoger(var tecla:char;var opc:integer);
begin
 repeat
  repeat
   tecla:=readkey;
  until tecla in[#72,#13,#80];
  case tecla of
   #72:begin
        opciones(opc,15);
        if opc=1then
         opc:=5
        else
         dec(opc);
        opciones(opc,1)
       end;
   #80:begin
        opciones(opc,15);
           if opc=5then
         opc:=1
        else
         inc(opc);
        opciones(opc,1)
       end
  end;
 until tecla=#13;
end;
procedure menu;
var
boton:char;
opcion,i,f:integer;
begin
opcion:=1;
repeat
 setcolor(2);
 setfillstyle(2,21);
 bar(1,1,640,480);
 setfillstyle(3,4);
 bar3d(170,60,480,110,10,TopOn);
 settextstyle(8,0,2);
 outtextxy(285,70,'MENU');
 settextstyle(8,0,2);
 setfillstyle(1,3);
 bar3d(170,170,510,350,30,TopOn);
 for i:= 1 to 5 do
  opciones(i,15);
 opciones(opcion,1);
 escoger(boton,opcion);
 case opcion of

              1 :   BEGIN
                     ClearDevice;
                     f :=1;
                     writeln('ESTA CREANDO LA COLA NUMERO ',f );
                       {creacion(cabeza1,fin)}

                   END;
              2 :   begin
                      ClearDevice;
                      {insertar( cabeza1,fin,max,numautos );}
                    END;
              3 :   begin
                    {eliminacion(cabeza1,conta);  }
                    end;
              4 :   begin
                    ClearDevice;
                    {modificar(cabeza1,apellido,placa,modelo,tipo,valor );}
                    end;

              5 :   begin
                    {ClearDevice;
                    contaservicio(cabeza1);
                    readkey ;                                  }
                    end;
              6 :   begin
                    ClearDevice;
 {                   x:= totaldinero(cabeza1 );}
                    END;
              7 :   begin
                    clearDevice;
{                    mostrar(cabeza1,fin);       }
                    readkey;

                    end;
              8 : {salir};
             else
                  begin
                  Sound(220);        { Beep }
                  Delay(200);        { For 200 ms }
                  NoSound;           { Relief! }
                  end;
        end;
until opcion=5;
end;

procedure InicializarModoGrafico;
var
gd,gm : integer;
begin
 Gd := Detect;
 InitGraph(Gd, Gm,'F:\BGI ');
 if GraphResult <> grOk then
  Halt(1);

    end;
begin
InicializarModoGrafico;
menu;
end.