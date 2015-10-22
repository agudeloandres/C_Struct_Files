//**************************************************
// *  RAÚL SALINAS MACIEL.             MAT.662195  *
// *	  					   *
// *             TREE IMPLEMENTATION		   * 
//***************************************************************
//  El programa es de uso público, pero necesito dinero... 	*
//		PLEASE, SEND ME A DOLLAR!!!          		*
//								*
//		Manzana M-7, edif f4, depto. 4			*
//		Col. Villas de San Juan.			*
//		Guadalajara, Jalisco, México			*
//		CP. 44290					*
//								*
// e-mail: al662195@campus.gda.itesm.mx				*
// http://www.gda.itesm.mx/~al662195				*
//***************************************************************

#include <stdio.h>
#include <fstream.h>
#include <conio.h>

enum boolean {TRUE = 1, FALSE = 0};


/****************************************/
/***********CLASS DEFINITIONS************/
/****************************************/

class node{            
 private:
   int info;                    
   node *left, *right, *parent;      
 public:
   node(){left= NULL; right=NULL; parent= NULL;};
   void Key(int ele);
   int Key();
   void LChild(node *tmp);
   node *LChild();
   void RChild(node *tmp);
   node *RChild();
   void Parent(node *tmp);
   node *Parent(); 
};


class tree{
 private:
   node *root;
   void PostOrder(node *x);
   void PreOrder(node *x);
   void PTree(node *x, int h, int reg);
   void InOrder(node *x);
 public:
   tree(){ root= NULL; };
   node *Find(int ele);
   node *TMax();
   node *TMin();
   node *TSuccessor(node *x);
   void Insert(node *Z);
   node *Delete(node *Z);
   void PostOrder(){ PostOrder(root); };
   void PreOrder(){ PreOrder(root); };
   void InOrder(){ InOrder(root); };
   void PTree(){ PTree(root,1,1);};
   void NPrint(node *tmp);
   boolean IsNil(node *tmp);
   boolean Empty();
};


class TImplement{
 private:
  tree *T;
 public:
  TImplement(){T = NULL;};
  void Menu();
  void CallOperation(int sel);  
};
/********************************************
********NODE METHODS IMPLEMENTATION *********
*********************************************/
void node::Key(int ele){
 info= ele;
}

int node::Key(){
 return info;
}

void node::LChild(node *tmp){
 left= tmp;
}

node *node::LChild(){
 return left;
}

void node::RChild(node *tmp){
 right= tmp;
}

node *node::RChild(){
 return right;
}

void node::Parent(node *tmp){
 parent= tmp;
}

node *node::Parent(){
 return parent;
}

/***************************************************
**************TREE: METHODS IMPLEMENTATION***********
****************************************************/


/****EMPTY****/
boolean tree::Empty(){
 if (root == NULL) return TRUE;
 else return FALSE;
}

/****PRINT KEY VALUE ******/
void tree::NPrint(node *tmp){
  cout << tmp->Key() << ", ";
}

/****IS NIL****/
boolean tree::IsNil(node *tmp){
 if ((tmp->LChild() == NULL) && (tmp->RChild() == NULL))
   return TRUE;
 else return FALSE;
}

/*****FIND*******/
node *tree::Find(int ele){
  node *tmp= root, *out= NULL;

  while ((!IsNil(tmp)) && (ele != tmp->Key())){
   if (ele < tmp->Key()) tmp= tmp->LChild();
   else tmp= tmp->RChild();
  }
  if(tmp->Key() == ele) out= tmp; 
  return out;
}

/*****TREE MAXIMUM*******/
node *tree::TMax(){
 node *tmp= root;

 while (tmp->RChild() != NULL)
   tmp= tmp->RChild();
 return tmp;
}

/*****TREE MINIMUM******/
node *tree::TMin(){
 node *tmp= root;

 while (tmp->LChild() != NULL)
   tmp= tmp->LChild();
 return tmp;
}

/****TREE SUCCESSOR****/
node *tree::TSuccessor(node *x){
 node *y= x->RChild();

 while (y->LChild() != NULL)
  y= y->LChild();
 return y;
}

/****INSERT*****/
void tree::Insert(node *Z){
 node *y= NULL, *x= root;

 while(x != NULL){
  y= x;
  if (Z->Key() <= x->Key()) x= x->LChild();
  else x= x->RChild();
 }
 Z->Parent(y);
 if(y == NULL)
  root= Z;
 else{
  if(Z->Key() <= y->Key()) y->LChild(Z);
  else y->RChild(Z);
 }
}

/****DELETE****/
node *tree::Delete(node *Z){
 node *y=NULL, *x, *tmp, *p, *l, *r;
 int ele;

  if ((Z->LChild()==NULL) || (Z->RChild()==NULL))
   y= Z;
  else y= TSuccessor(Z);

  if (y->LChild()!=NULL)
   x= y->LChild();
  else x= y->RChild();

  if (x != NULL){
   tmp= y->Parent();
    x->Parent(tmp);
  }

  if (y->Parent() == NULL)
   root= x;
  else{
   tmp= y->Parent();
   if (y == tmp->LChild())
    tmp->LChild(x);
   else tmp->RChild(x); 
  }

  if (y != Z){
   ele= y->Key();
   Z->Key(ele);

   p= Z->Parent();
   l= Z->LChild();   
   r= Z->RChild();
   if(p==NULL && l==NULL && r==NULL) root= NULL;
  }
  return y;
}

/****POSTORDER****/
void tree::PostOrder(node *x){
 node *y= NULL;

 if (x->LChild() != NULL)
  PostOrder(x->LChild());
  
 if (x->RChild() != NULL){
  y= x;
  PostOrder(x->RChild());
 }
 if((x->RChild()==NULL) && (x->LChild()==NULL))
  NPrint(x);
 else{
  if (x == y) NPrint(y);
  else{
   if((x->RChild()==NULL) && (x->LChild()!=NULL))
    NPrint(x);
  }
 }
}

/****PREORDER****/
void tree::PreOrder(node *x){

 NPrint(x);
 if (x->LChild() != NULL)
  PreOrder(x->LChild());
 if (x->RChild() != NULL)
  PreOrder(x->RChild());
}

/****INORDER****/
void tree::InOrder(node *x){

 if(x->LChild() != NULL)
  InOrder(x->LChild());
 NPrint(x);
 if(x->RChild() != NULL)
  InOrder(x->RChild());
}

/****PRINT TREE****/
void tree::PTree(node *x,int h, int reg){
 int i;

 if(x != NULL){
  if(reg == 23){
   cout << "\nPress intro to continue...";
   reg= 1;
  }
  PTree(x->LChild(), h+1, reg);
  for(i=1; i<=h; i++){
   cout << "  ";
  }
  cout <<  x->Key() << "\n";
  reg += 1;
  PTree(x->RChild(), h+1, reg);
 }
}
/************************************************
*******TIMPLEMETN METHODS IMPLEMENTATION*********
*************************************************/

/****MENU****/
void TImplement::Menu(){
 int sel;

 do{
  clrscr();
  cout << "\n\t\tB I N A R Y  T R E E";
  cout << "\n\n\t1. Insert element(int)";
  cout << "\n\t2. Delete element";
  cout << "\n\t3. Maximum";
  cout << "\n\t4. Minimum";
  cout << "\n\t5. Post Order";
  cout << "\n\t6. Pre Order";
  cout << "\n\t7. In Order";
  cout << "\n\t8. Print Tree";
  cout << "\n\t9. Exit";
  cout << "\n\n\t\tOption... ";
  cin >> sel;

  CallOperation(sel);
  
 }while (sel != 9); 
}

/********/
void TImplement::CallOperation(int sel){
 node *Z= new(node);
 int element;

 switch (sel){
  case 1:{
   cout << "\n\nElement to insert: ";
   cin >> element;
   Z->Key(element);
   T->Insert(Z);
   break;
  }
  case 2:{
   if (!T->Empty()){
    cout << "\n\nElement to be deleted: ";
    cin >> element;
    Z= T->Find(element);
    if (Z != NULL){
     Z= T->Delete(Z);
     delete(Z);
    }
    else{
     cout << "\n\n\tElement not found...";
     getch();
    }
   }
   else {
    cout << "\n\n\tEmpty Tree ! ! !";
    getch();
   }
   break;
  }
  case 3:{
   if (!T->Empty()){
    Z= T->TMax();
    element= Z->Key();
    cout << "\n\n\tTree Maximum: " << element;
   }
   else {
    cout << "\n\n\tEmpty Tree ! ! !";
   }
  getch();
  break;
  }
  case 4:{
   if (!T->Empty()){
    Z= T->TMin();
    element= Z->Key();
    cout << "\n\n\tTree Minimum: " << element;
   }
   else {
    cout << "\n\n\tEmpty Tree ! ! !";
   }
   getch();
   break;
  }
  case 5:{
   if(!T->Empty()){
    cout << "\n\n\tTree Printed in Post Order: \n";
    T->PostOrder();
   }
   else {
    cout << "\n\n\tEmpty Tree ! ! !";
   }
   getch();
   break;
  }
  case 6:{
   if (!T->Empty()){
    cout << "\n\n\tTree Printed in Pre Order: \n";
    T->PreOrder();
   }
   else {
    cout << "\n\n\tEmpty Tree ! ! !";
   }
   getch();
   break;
  }
  case 7:{
   if (!T->Empty()){
    cout << "\n\n\tTree Printed In Order: \n";
    T->InOrder();
   }
   else {
    cout << "\n\n\tEmpty Tree ! ! !";
   }
   getch();
   break;
  }
  case 8:{
   if (!T->Empty()){
    clrscr();
    T->PTree();
   }
   else {
    cout << "\n\n\tEmpty Tree ! ! !";
   }
   getch();
   break;
  }
 }
}
/************end TIMPLEMENT*************************************/

/***********
****MAIN****
************/


void main(){
 TImplement RSM;

 RSM.Menu();
}
