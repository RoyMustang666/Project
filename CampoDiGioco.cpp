#include "CampoDiGioco.h"

void CampoDiGioco::leggiMatriceFile(){
  ifstream apriFile("livello1.txt");
    // int num;
    while(!apriFile.eof()){
      for(int riga=0;riga<18;riga++){
        for(int colonna=0;colonna<32;colonna++){
          apriFile >> Mappa[riga][colonna];
        }
      }
    }
    apriFile.close();
}
