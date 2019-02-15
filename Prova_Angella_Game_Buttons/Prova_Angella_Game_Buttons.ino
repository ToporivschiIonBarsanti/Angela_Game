int puntiTotali;
int puntiMeta;
int giocatore;
int macchina;
int turno;
int controllo;
int puntiAppoggio; // serve solo per controllare i punti metà
int appoggio; // serve per controllare numero dell'ultimo turno
int vincita;
int b1;
int b2;
int b3;
int b4;
int b5; 
int b6;

void setup() {
  // put your setup code here, to run once:
b1 = 1;
b2 = 2;
b3 = 3;
b4 = 4;
b5 = 5; 
b6 = 6;
puntiAppoggio = 0;
turno = 0;
vincita = 0;
appoggio = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  
//controllo se puntiMeta non erano ancora inseriti e, in questo caso, gli inserisco
if(puntiAppoggio == 0)
{
  Serial.println("Inserisci punti metà");
}
while(puntiAppogio == 0){
  ControllaMeta();
}
//end region puntiMeta
//codice del gioco

if(turno == 0){
  Serial.println("è il turno di giocatore");
}
CCV();
Vincita("giocatore");
while(controllo == 0){
  
}


}



void Controllo(){
  if(giocatore == 1 && macchina != 6 && macchina != 1 && appoggio != 6 && appoggio != 1){
    controllo = 1;
  }
  if(giocatore == 2 && macchina != 5 && macchina != 2 && appoggio != 5 && appoggio != 2){
    controllo = 1;
  }
  if(giocatore == 3 && macchina != 4 && macchina != 3 && appoggio != 4 && appoggio != 3){
    controllo = 1;
  }
  if(giocatore == 4 && macchina != 3 && macchina != 4 && appoggio != 4 && appoggio != 3){
    controllo = 1;
  }
  if(giocatore == 5 && macchina != 2 && macchina != 5 && appoggio != 5 && appoggio != 2){
    controllo = 1;
  }
  if(giocatore == 6 && macchina != 1 && macchina != 6 && appoggio != 6 && appoggio != 1){
    controllo = 1;
  }
}
void MacchinaSceglie(){
  while(controllo == 0){
    macchina = random(1,7);
    Controllo();
  }
}
void AggiungiPunti(int punti){ puntiTotali = puntiTotali + punti; }
void ControllaMeta() // serve per inserire numero di punti metà
{ 
  while (Serial.available() > 0) {
    String meta = Serial.readString();

    if (meta.toInt() >= 30 && meta.toInt() <= 100) {
      puntiMeta = meta.toInt();
      puntiAppoggio = 1;
      Serial.print("Punti metà ");
      Serial.println(puntiMeta);
    }
    else {
      Serial.println("Hai sbagliato inserimento dei punti di metà");
    }

  }
}
void CCV() // controllo condizioni vincita
{
  if(puntiTotali == puntiMeta){
    vincita = 1;
  }
  if(puntiTotali > puntiMeta){
    vincita = 2;
  }
}
void Vincita(String nome){
  if(vincita == 1){
  Serial.println(nome + " ha vinto");
}
else if (vincita == 2) {
  Serial.println(nome + " ha perso");
}
}

