#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int puntiTotali;
int puntiMeta;
int giocatore;
int macchina;
int controllo;
int puntiAppoggio; // serve solo per controllare i punti metà
int appoggio; //serve per controllare la situazione del gioco, se c'e' un vincitore/perditore
int ultimoValore; // serve per controllare numero dell'ultimo turno
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
puntiMeta = 0;
appoggio = 0;
vincita = 0
ultimoValore = 0;
b1 = 10; b2 = 9; b3 = 8;
randomSeed(analogRead(0));
}

void loop() {
 // put your main code here, to run repeatedly:
  lcd.setCursor(0,1);

  if(puntiTotali != 0){
    lcd.print("Punti totali " + puntiTotali);
  }
//controllo se puntiMeta non erano ancora inseriti e, in questo caso, gli inserisco
 if(puntiAppoggio == 0 && appoggio != 3)
 {
   lcd.print("Inserisci punti metà");
 }
 while(puntiAppoggio == 0){
  InserisciaMeta();
 }
//end region puntiMeta

//codice del gioco
giocatore = 0; macchina = 0; controllo = 0;

CCV();
Vincita("Macchina");
if(appoggio == 3){
lcd.print("Clicca conferma per giocare di nuovo);
while(digitalRead(8) == HIGH){
appoggio = 0;
}
}


TurnoGiocatore(); 
AggiungiPunti(giocatore);
ultimoValore = giocatore;
controllo = 0; //serve per il turno di macchina


CCV();
Vincita("Giocatore");
if(appoggio == 3){
lcd.print("Clicca conferma per giocare di nuovo);
while(digitalRead(8) == HIGH){
appoggio = 0;
}
}

TurnoMacchina();
AggiungiPunti(macchina);
ultimoValore = macchina;
controllo = 0;

// end region gioco




}

void TurnoGiocatore() //controllo se il valore (punti) del giocatore sono in concordanza con le regole del gioco, cio' non si puo andare meno di 1 e piu di 6
{
  lcd.print("Turno giocatore");
while(controllo == 0){ 
giocatore = 1;
while(digitalRead(8) == HIGH){
  
  if(digitalRead(10) == LOW)
  {
    giocatore++;
    lcd.println(giocatore);
    delay(1000);
  }
  if(digitalRead(9) == LOW)
  {
    giocatore--;
    lcd.println(giocatore);
    delay(1000);
  }
  if(giocatore <= 0 || giocatore > 6){
    if(giocatore <= 0){
      giocatore++;
    }
    else if(giocatore  > 6){
      giocatore--;
    }
    lcd.print("Giocatore ");
    lcd.println(giocare);
   // lcd.println(giocatore) //funziona con Serial.;
  }
}
Controllo();
}
}

void Controllo(){ // eseguo il controllo se le regole del gioco erano rispettate
  if(giocatore == 1 && macchina != 6 && macchina != 1 && ultimoValore != 6 && ultimoValore != 1){
    controllo = 1;
  }
  if(giocatore == 2 && macchina != 5 && macchina != 2 && ultimoValore != 5 && ultimoValore != 2){
    controllo = 1;
  }
  if(giocatore == 3 && macchina != 4 && macchina != 3 && ultimoValore != 4 && ultimoValore != 3){
    controllo = 1;
  }
  if(giocatore == 4 && macchina != 3 && macchina != 4 && ultimoValore != 4 && ultimoValore != 3){
    controllo = 1;
  }
  if(giocatore == 5 && macchina != 2 && macchina != 5 && ultimoValore != 5 && ultimoValore != 2){
    controllo = 1;
  }
  if(giocatore == 6 && macchina != 1 && macchina != 6 && ultimoValore != 6 && ultimoValore != 1){
    controllo = 1;
  }
}
void TurnoMacchina(){ // macchina che fa un numero random col rispetto alle regole del gioco
  lcd.print("Turno macchina");
  while(controllo == 0){
    macchina = random(1,7);
    Controllo();
  }
}
void AggiungiPunti(int punti){ puntiTotali = puntiTotali + punti; }

void InserisciMeta() // serve per inserire numero di punti metà //da cambiare
{ 
  puntiMeta = 65; //valore medio tra 100 e 30

  while(digitalRead(8) == HIGH){
  if(digitalRead(10) == LOW)
  {
    puntiMeta++;
    lcd.println(puntiMeta);
    delay(1000);
  }
  if(digitalRead(9) == LOW)
  {
    puntiMeta--;
    lcd.println(puntiMeta);
    delay(1000);
  }
  if(puntiMeta < 30 || puntiMeta > 100){
    if(puntiMeta < 30){
      puntiMeta++;
    }
    else if(puntiMeta  > 100){
      puntiMeta--;
    }
    lcd.print("Punti meta erano cambiati a " + puntiMeta);
   // lcd.println(puntiMeta) //funziona con Serial.;
  }
 }
 puntiAppoggio = 1;
}
void CCV() // controllo condizioni vincita
{
  if(puntiTotali == puntiMeta){
    appoggio = 1;
  }
  if(puntiTotali > puntiMeta){
    appoggio = 2;
  }
}
void Vincita(String nome){
  if (appoggio != 0 && appoggio != 3) {
    if (appoggio == 1) {
      lcd.print(nome)
      lcd.println(" ha perso");
    }
    else if (appoggio == 2) {
      lcdl.println(nome)
      lcd.print(" ha perso");
    }
    puntiMeta = 0;
    puntiTotali = 0;
    puntiAppoggio = 0;
    appoggio = 3;
  }
}

