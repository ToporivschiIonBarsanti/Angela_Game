/*Il progetto era sviluppato da Toporivschi Ion, 4^BI, I.T.T. E. Barsanti nel scopo di un progetto di informatica, Angela Game.
  Questo e' la versione finita del progetto nel confine di versione LCD con 3 bottoni.
*/

#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int puntiTotali; int puntiMeta; int puntiGiocatore; int puntiMacchina; bool controllo; int ultimoValore; int endgame;
int b1; int b2; int b3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  b1 = 10; b2 = 9; b3 = 8;
  puntiTotali = 0; puntiMeta = 0; puntiGiocatore = 0; puntiMacchina = 0; controllo = false; ultimoValore = 0; endgame = 0;
  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 0);
  if (puntiTotali != 0) { //mostro punti totali
    lcd.clear();
    lcd.print("Punti totali ");
    lcd.print(puntiTotali);
    delay(1000);
  }
  if (endgame == 3) {
    lcd.setCursor(0, 1);
    lcd.print("Clicca OK");
    while (digitalRead(8) == HIGH) {
      endgame = 0;
    }
    lcd.setCursor(0, 0); lcd.clear();
  }
  if (puntiMeta == 0 && endgame != 3) {
    lcd.clear();
    lcd.print("Dai punti meta");
    delay(1000);
    lcd.clear();
  }
  while (puntiMeta == 0 && endgame != 3) {
    InserisciMeta();
  }
  puntiGiocatore = 0; puntiMacchina = 0;
  if (endgame != 3) {
    TurnoGiocatore();
    AggiungiPunti(puntiGiocatore);
    ultimoValore = puntiGiocatore;
    controllo = false;
    CCV();
    GameEnded("Giocatore");
  }
  if (endgame != 3) {
    TurnoMacchina();
    AggiungiPunti(puntiMacchina);
    ultimoValore = puntiMacchina;
    controllo = false;
    CCV();
    GameEnded("Macchina");
  }
}


//region giocatore/macchina
void Controllo(bool cosa) { //uso un bool per controllare se dirigente e' una macchina o un giocatore
  if (cosa) {
    if (puntiGiocatore == 1 && ultimoValore != 1 && ultimoValore != 6) {
      controllo = true;
    }
    if (puntiGiocatore == 2 && ultimoValore != 2 && ultimoValore != 5) {
      controllo = true;
    }
    if (puntiGiocatore == 3 && ultimoValore != 3 && ultimoValore != 4) {
      controllo = true;
    }
    if (puntiGiocatore == 4 && ultimoValore != 3 && ultimoValore != 4) {
      controllo = true;
    }
    if (puntiGiocatore == 5 && ultimoValore != 2 && ultimoValore != 5) {
      controllo = true;
    }
    if (puntiGiocatore == 6 && ultimoValore != 1 && ultimoValore != 6) {
      controllo = true;
    }
  }
  else {
    if (puntiMacchina == 1 && ultimoValore != 1 && ultimoValore != 6) {
      controllo = true;
    }
    if (puntiMacchina == 2 && ultimoValore != 2 && ultimoValore != 5) {
      controllo = true;
    }
    if (puntiMacchina == 3 && ultimoValore != 3 && ultimoValore != 4) {
      controllo = true;
    }
    if (puntiMacchina == 4 && ultimoValore != 3 && ultimoValore != 4) {
      controllo = true;
    }
    if (puntiMacchina == 5 && ultimoValore != 2 && ultimoValore != 5) {
      controllo = true;
    }
    if (puntiMacchina == 6 && ultimoValore != 1 && ultimoValore != 6) {
      controllo = true;
    }
  }
}
void TurnoGiocatore() {
  lcd.clear();
  lcd.print("Turno giocatore");
  delay(1000);
  lcd.clear();
  while (!controllo) { //faccio un ciclo finche' le condizioni del metodo Controllo erano soddisfate
    puntiGiocatore = 3;
    lcd.print("Giocatore ");
    lcd.print(puntiGiocatore);
    while (digitalRead(8) == HIGH) { //finche' la conferma era cliccata mi entra nel ciclo
      if (digitalRead(10) == LOW) {
        puntiGiocatore++;
        lcd.clear();
        lcd.print("Giocatore ");
        lcd.print(puntiGiocatore);
        delay(500);
      }
      if (digitalRead(9) == LOW) {
        puntiGiocatore--;
        lcd.clear();
        lcd.print("Giocatore ");
        lcd.print(puntiGiocatore);
        delay(500);
      }
      if (puntiGiocatore <= 0 || puntiGiocatore >= 7) { //serve come il controllo aggiuntivo se l'utente esce dallo sccopo del gioco
        if (puntiGiocatore <= 0) {
          puntiGiocatore++;
          lcd.clear();
          lcd.print("Giocatore ");
          lcd.print(puntiGiocatore);
        }
        if (puntiGiocatore > 6) {
          puntiGiocatore--;
          lcd.clear();
          lcd.print("Giocatore ");
          lcd.print(puntiGiocatore);
        }
      }
    }
    Controllo(true);
    if (controllo == false) {
      lcd.clear();
      lcd.print("Valore sbagliato");
      delay(1000);
      lcd.clear();
    }
  }
}
void TurnoMacchina() {
  lcd.clear();
  lcd.print("Turno macchina");
  delay(1000);
  while (!controllo) {
    puntiMacchina = random(1, 7);
    Controllo(false);
  }
  lcd.clear();
  lcd.print("Macchina ");
  lcd.print(puntiMacchina);
  delay(1000);
  lcd.clear();
}
void AggiungiPunti(int punti) {
  puntiTotali += punti;
}
//endregion giocatore/macchina
//region punti meta
void InserisciMeta() {
  puntiMeta = 65; //il medio tra 30 e 100
  lcd.clear();
  lcd.print("Punti meta ");
  lcd.print(puntiMeta);
  while (digitalRead(8) == HIGH) { //finche' e' stata cliccata la conferma
    if (digitalRead(10) == LOW) {
      puntiMeta++;
      lcd.clear();
      lcd.print("Punti meta ");
      lcd.print(puntiMeta);
      delay(500);
    }
    if (digitalRead(9) == LOW) {
      puntiMeta--;
      lcd.clear();
      lcd.print("Punti meta ");
      lcd.print(puntiMeta);
      delay(500);
    }
    if (puntiMeta < 30 || puntiMeta > 100) { //serve se l'utente esce dallo scopo del gioco
      if (puntiMeta < 30) {
        puntiMeta++;
        lcd.clear();
        lcd.print("Punti meta ");
        lcd.print(puntiMeta);
      }
      if (puntiMeta > 100) {
        puntiMeta--;
        lcd.clear();
        lcd.print("Punti meta ");
        lcd.print(puntiMeta);
      }
    }
  }
}
//endregion punti meta

//region endgame
void CCV() { //controllo condizioni di vincita
  if (puntiTotali == puntiMeta) {
    endgame = 1;
  }
  if (puntiTotali > puntiMeta) {
    endgame = 2;
  }
}
void GameEnded(String nome) {
  if (endgame != 0 && endgame != 3) {
    if (endgame == 1) {
      lcd.clear();
      lcd.print(nome);
      lcd.print(" vinto");
      delay(1000); //senza delay non funziona bene, si sparisce subito
    }
    else if (endgame ==  2) {
      lcd.clear();
      lcd.print(nome);
      lcd.print(" perso");
      delay(1000);
    }
    puntiMeta = 0; puntiTotali = 0; ultimoValore = 0; endgame = 3;
  }
}
//endregion endgame
