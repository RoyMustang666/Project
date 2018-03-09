#include "CampoDiGioco.h"

CampoDiGioco::CampoDiGioco(){
  Mappa = new int [righeMat];
  for(int i=0;i<righeMat;i++)
    Mappa[i] = new int [colonneMat];
}

// SERVE PER LEGGERE I VARI LIVELLI DA FILE
void CampoDiGioco::leggiCampoDiGioco(int numNemici){
  //if(numNemici==3){
  ifstream apriFile("livello1.txt");
    while(!apriFile.eof()){
      for(int riga=0;riga<righeMat;riga++){
        for(int colonna=0;colonna<colonneMat;colonna++){
          apriFile >> Mappa[riga][colonna];
        }
      }
    }
    apriFile.close();
  //}
  // MANCA LA PARTE DELL'ELSE DOVE I NEMICI SONO DETTATI DALLA SCELTA DELL'UTENTE

  // if(numNemici<3){
  // ifstream apriFile("livello1mp.txt");
  //   while(!apriFile.eof()){
  //     for(int riga=0;riga<righeMat;riga++){
  //       for(int colonna=0;colonna<colonneMat;colonna++){
  //         apriFile >> Mappa[riga][colonna];
  //       }
  //     }
  //   }
  //   apriFile.close();
  // }


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
// CampoDiGioco& CampoDiGioco::Mappa operator [](int i,int j){
//   return Mappa[i][j];
// }


// serve per vedere quale enum ha all'interno il campo di gioco
int CampoDiGioco::getElementoMappa(int i, int j){
  return Mappa[i][j];
}

// es: CampoDiGioco a,b; a.leggiCampoDiGioco(); b=a; adesso b ed ha puntano alla stessa parte
// LA FUNZIONE PER FAR PUNTARE UNA MAPPA A QUESTA MAPPA // ATTENZIONE NON CREA UNA COPIA
int** CampoDiGioco::restituisciMappa(){
  return Mappa;
}

// DISTRUGGO IL MIO CAMPO DI GIOCO IN QUANTO NEL COSTRUTTORE FACCIO DUE NEW
CampoDiGioco::~CampoDiGioco(){
  for(int i =0;i<righeMat;i++)
    delete [] Mappa[i];
  delete [] Mappa;
}

void CampoDiGioco::setElementoMatrice(int i, int j,int numero){
  Mappa[i][j]=numero;
}
