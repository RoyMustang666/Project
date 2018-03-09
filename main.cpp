#include<iostream>
#include"GestoreGioco.h"
#include"Definizioni.h"

using namespace std;

int main()
{
  GestoreGioco *a=new GestoreGioco();

  a->inizializzatore();
  // a->start();

  delete a;

  return 0;
}
