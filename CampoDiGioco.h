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
  void leggiMatriceFile();
  void stampa()const{
    for(int i =0;i<18;i++){
      for(int j =0;j<32;j++){
        cout<<Mappa[i][j]<<" ";
      }
    cout<<endl;
    }
  }




};
#endif
