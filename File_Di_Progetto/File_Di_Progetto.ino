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
while(puntiAppoggio == 0)
{
  ControllaPuntiMeta();
}
controllo = 0;
programma = 0;
avversario = 0;
CCV("Programma 101");
if(avversario == 0){
  
}


  

}

void Controllo(int numero){
  if(avversario == 1 && numero != 6 && numero != 1){
    controllo = 1;
  }
  if(avversario == 2 && numero != 5 && numero != 2){
    controllo = 1;
  }
  if(avversario == 3 && numero != 4 && numero != 3){
    controllo = 1;
  } 
}
void MacchinaSceglie(){
  while(){
  randNumber = random(1,7);
  Controllo(randNumber);
  if(controllo == 1){ programma = randNumber; }
   }
}

void AggiungiPunti(int punti){
  puntiTotali = puntiTotali + punti;
}
void ControllaPuntiMeta(){

if(puntiMeta >= 30 && puntiMeta <= 100){
  puntiAppoggio = 1;
}
else
{

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

