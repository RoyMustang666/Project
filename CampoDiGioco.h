#ifndef CAMPODIGIOCO_H
#define CAMPODIGIOCO_H
#include "Definizioni.h"
#include <fstream> // serve per leggere la matrice da file
#include <cstdlib>
#include <iostream>
using namespace std;

class CampoDiGioco{

private:
  int** Mappa;

  // int Mappa[18][32];

public:
  CampoDiGioco();
  ~CampoDiGioco();
  void leggiCampoDiGioco(string sceltaSingMulti);
  void stampaCampoDiGioco()const;
  int** restituisciMappa()/*const*/; // forse posso farlo const
  // CampoDiGioco& operator [](int i,int j); // non funziona

  int getElementoMappa(int i,int j)const;
  void setElementoMatrice(int i, int j,int numero);
  void swap(int i, int j);





};
#endif
