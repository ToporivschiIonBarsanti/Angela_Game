#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
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
// Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
// HIGH when it's open, and LOW when it's pressed.

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);
pinMode(10, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);
pinMode(8, INPUT_PULLUP);
puntiAppoggio = 0;
turno = 0;
vincita = 0;
appoggio = 0;
b1 = 10; b2 = 9; b3 = 8;
randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,1);
//controllo se puntiMeta non erano ancora inseriti e, in questo caso, gli inserisco
if(puntiAppoggio == 0)
{
  lcd.print("Inserisci punti metà");
}
while(puntiAppogio == 0){
  InserisciaMeta();
}
//end region puntiMeta
//codice del gioco
CCV();
Vincita("Macchina");
if(turno == 0){
  lcd.print("è il turno di giocatore");
  while(controllo == 0){
  
  }
}

CCV();
Vincita("Giocatore");

if(turno == 2){
  lcd.print("è il turno di macchina");
  while(controllo == 0){
    MacchinaSceglie();
    Controllo();
  }
  AggiungiPunti(macchina);
  appoggio = macchina;
}
if(turno == 2){ giocatore = 0; macchina = 0; turno = 0; }
// end region gioco
}



void Controllo(){ // mi esegue il controllo rispetto le regole del gioco
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
void MacchinaSceglie(){ // macchina che fa un numero random col rispetto alle regole del gioco
  while(controllo == 0){
    macchina = random(1,7);
    Controllo();
  }
}
void AggiungiPunti(int punti){ puntiTotali = puntiTotali + punti; }
void InserisciMeta() // serve per inserire numero di punti metà //da cambiare
{ 
  
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
  lcd.print(nome + " ha vinto");
}
else if (vincita == 2) {
  lcd.print(nome + " ha perso");
}
}

