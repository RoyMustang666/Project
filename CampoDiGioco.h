#ifndef CAMPODIGIOCO_H
#define CAMPODIGIOCO_H
#include "Definizioni.h"
#include <fstream> // serve per leggere la matrice da file
#include <cstdlib>
#include <iostream>
using namespace std;

class CampoDiGioco{

private:
  int Mappa[righeMat][colonneMat];
  // int Mappa[18][32];

public:
  void leggiCampoDiGioco();
  void stampaCampoDiGioco()const;
  CampoDiGioco& operator [](int i,int j);





};
#endif
