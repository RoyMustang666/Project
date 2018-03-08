#include "CampoDiGioco.h"

// SERVE PER LEGGERE I VARI LIVELLI DA FILE
void CampoDiGioco::leggiCampoDiGioco(){
  ifstream apriFile("livello1.txt");
    while(!apriFile.eof()){
      for(int riga=0;riga<righeMat;riga++){
        for(int colonna=0;colonna<colonneMat;colonna++){
          apriFile >> Mappa[riga][colonna];
        }
      }
    }
    apriFile.close();
}

// STAMPA IL CAMPO DI GIOCO
void CampoDiGioco::stampaCampoDiGioco()const{
  for(int i =0;i<righeMat;i++){
    for(int j =0;j<colonneMat;j++){
      cout<<Mappa[i][j]<<" ";
    }
  cout<<endl;
  }
}

// mi servirà per restituire il contenuto della mappa cioè l'enum
CampoDiGioco& CampoDiGioco::Mappa operator [](int i,int j){
  return Mappa[i][j];
}
