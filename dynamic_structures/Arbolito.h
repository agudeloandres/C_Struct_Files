//RUTINA VISITAR

void visitar(cod *p)
{
 char op;
  printf("%1.0f ",p->info);
}
 //RECORRIDO DE UN ARBOL EN PRE IN Y POSTORDEN
 void preorden(cod *t)
 {
  if(t!=0){
  visitar(t);
  preorden(t->llink);
  preorden(t->rlink);
  }
 }

 void inorden(cod *t)
 {
  if(t!=0){
    inorden(t->llink);
    visitar(t);
    inorden(t->rlink);
  }
 }
void postorden(cod *t)
 {
  if(t!=0){
    postorden(t->llink);
    postorden(t->rlink);
    visitar(t);
  }
 }
