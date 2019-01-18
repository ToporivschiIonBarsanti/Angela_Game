void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
int puntiTotali = 0;
int puntiAppoggio = 0;
int puntiMeta = 0;
int avversario = 0;
int programma = 0;
int controllo = 0;
randomSeed(analogRead(0));

}

void loop() {
  // put your main code here, to run repeatedly:
controllo = false;
programma = 0;
avversario = 0;
CCV("Programma 101");
if(avversario == 0){
  
}


  

}

void Controllo(int numero){
  if(avversario == 1 && numero != 6){
    controllo = 1;
  }
  if(avversario == 2 && numero != 5){
    controllo = 1;
  }
  if(avversario == 3 && numero != 4){
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

void CCV(String nome){ //ControlloCondizioniVincita
  if(puntiTotali == puntiMeta){
    Serial.println(nome + " ha vinto");
  }
  if(puntiTotali > puntiMeta){
    Serial.println(nome + " ha perso");
  }
}

