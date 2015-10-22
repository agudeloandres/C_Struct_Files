// Inicializaci¢n de la LLS.
iniclls(lls **l0,int *n,int *k,lls **ava)
{
int n1;
clrscr();
printf("digita N1");
scanf("%d",&n1);
(*n) = n1;
*l0 = new lls[n];
(*k) = 0;
(*ava) = *l0+1;
}


//Calculo del maximo.
lls calcmax(lls *l0,int n)
{
int i;
lls *max;
max = l0;
for(i=0;i<=n;i++){
   max++;
}
return max;
}/*

// Incertar nodo a la lista.
void incernod(lls **ava,lls max,lls **lk)
{
float cod;
char  nom[35];
int   i,lon;
if(*ava <= max){
  printf("CODIGO: ");
  scanf ("%f",&cod);
  printf("NOMBRE: ");
  cin.getline(nom,35);
  (*ava)->codigo=cod;
  log=strlen(nom);
  for(i=1;i<=lon;i++){
     (*ava)->nombre[i]=nom[i];
  }
  *lk = *ava;
  *ava++;
}
else{
  printf{"LISTA LLENA.");
  gatch();
}
return;
}

// Busqueda de nodo.
void buscnod(*lk,float cod,**li,int i)
{
*li = l0 + 1;
*i = 1;
while(*li <= lk && (*li) -> codigo != cod)
     *li++;
     *i++;
}
if((*li) -> codigo != cod){
  *li = lk + 1;
}
return;
}

// Corrimiento a la izquierda.
void corrizq(lls *li,lls **lk, int *k)
{
lls *l1,*l2;
if(li != *lk){
  *l1 = li;
  do{
    l2 = l1 + 1;
    l1 -> codigo = l2 -> codigo;
    l1 -> nombre = l2 -> nombre;
    l1 = l2;
  }while(l2 != *lk);
}
(*lk)--;
(*li)--;
return;
}

// Corrimiento a la derecha.
void corrder(lls *li,lls **l0, int *k)
{
lls *l1,*l2;
if(li == *l0 + 1){
  l0 = l0 + 1;
}
else{
    do{
      l2 = l1 - 1;
      l1 -> codigo = l2 -> codigo;
      l1 -> nombre = l2 -> nombre;
      l1 = l2;
    }while(l2 < *l0);
    (*l0)++;
}
*k--;
return;
}

// Cancelacion de nodos.
void cancnod(lls * l0,lls *lk,lls *li,int *k,float cod)
{
buscnod(&*l0,&*lk,float cod,l1);
int i;
if(li > (*lk)){
  clrscr();
  printf("nodo no existe");
  getch();
  clrscr();
}
else{
    if(i < *k - 1){
      corrder(&(*l0),&i,*k);
    }
    else{
	 corrizq(li,&(lk),*k)
    }
}
return;
}

// Escribir nodos.
void escrnod(lls *l0,lls *lk)
{
lls *l1;
lls *l1;
l1 = l0 + 1;
for(li=l1;li<=lk;li++){
   printf("%8.0f   %-35s\n",li -> codigo, li -> nombre);
}
return;
} */