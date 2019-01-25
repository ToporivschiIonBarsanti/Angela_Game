void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
int puntiTotali = 0;
int puntiMinimo = 30;
int puntiMassimo = 100;
int puntiAppoggio = 0;
int appoggio = 0;
int puntiMeta = 0;
int avversario = 0;
int programma = 0;
int controllo = 0;
randomSeed(analogRead(0));

}

void loop() {
  // put your main code here, to run repeatedly:
appoggio = 0;
while(puntiAppoggio == 0)
{
  ControllaInt();
  appoggio = puntiMeta;
  ControllaPuntiMeta();
}
controllo = 0;
programma = 0;
avversario = 0;
CCV("Macchina");
if(avversario == 0){
  while(controllo == 0){
  ControllaInt();
  avversario = appoggio;
  Controllo();
  }
}
if(avversario != 0){
  AggiungiPunti(avversario);
}
CCV("Giocatore");
if(programma == 0){
  MacchinaSceglie();
  }
if(programma != 0){
  AggiungiPunti(programma);
}



}



void Controllo(){
  if(avversario == 1 && programma != 6 && programma != 1){
    controllo = 1;
  }
  if(avversario == 2 && programma != 5 && programma != 2){
    controllo = 1;
  }
  if(avversario == 3 && programma != 4 && programma != 3){
    controllo = 1;
  } 
}
void MacchinaSceglie(){
  while(controllo == 0){
  programma = random(1,7);
  Controllo();
}

void AggiungiPunti(int punti){
  puntiTotali = puntiTotali + punti;
}
void ControllaPuntiMeta(){
if(puntiMeta >= 30 && puntiMeta <= 100){
  puntiAppoggio = 1;
}
}

void CCV(String nome){ //ControlloCondizioniVincita
  if(puntiTotali == puntiMeta){
    Serial.println(nome + " ha vinto");
  }
  if(puntiTotali > puntiMeta){
    Serial.println(nome + " ha perso");
  }
}

void ControllaInt(){
while(Serial.available() > 0){
  int inChar = Serial.read();
  if(isDigit(inChar)){
    inString += (char)inChar;
  }
}
appoggio = (int)inString;
}

