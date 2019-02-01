int puntiTotali;
int puntiAppoggio;
int appoggio;
int puntiMeta;
int avversario;
int programma;
int controllo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  puntiTotali = 0;
  puntiAppoggio = 0;
  appoggio = 0;
  puntiMeta = 0;
  avversario = 0;
  programma = 0;
  controllo = 0;
  randomSeed(analogRead(0));

}

void loop() {
  // put your main code here, to run repeatedly:


  

  if (puntiTotali != 0) {
    Serial.print("Punti totali ");
    Serial.println(puntiTotali);
  }
  if(puntiAppoggio == 0 && appoggio != 3){
    Serial.println("Inserisci punti metà");
  }
  if(appoggio == 3){
    Serial.println("Inserisci punti metà per giocare di nuovo");
  }
  while (puntiAppoggio == 0)
  {
    ControllaMeta();
    
  }
  if (appoggio == 3) {
    appoggio = 0;
  }
  controllo = 0;
  programma = 0;
  avversario = 0;

  CCV();
  if (appoggio != 0 && appoggio != 3) {
    if (appoggio == 1) {
      Serial.println("Macchina ha vinto");
    }
    else if (appoggio == 2) {
      Serial.println("Macchina ha perso");
    }
    puntiMeta = 0;
    puntiTotali = 0;
    puntiAppoggio = 0;
    appoggio = 3;
  }
  if (avversario == 0 && appoggio != 3) {
    while (controllo == 0) {
      ControllaNumeroGiocatore();
      Controllo();
    }
    Serial.print("Giocatore ");
    Serial.println(avversario);
  }
  if (avversario != 0) {
    AggiungiPunti(avversario);
  }
  CCV();
  if (appoggio != 0 && appoggio != 3) {
    if (appoggio == 1) {
      Serial.println("Giocatore ha vinto");
    }
    else if (appoggio == 2) {
      Serial.println("Giocatre ha perso");
    }
    puntiMeta = 0;
    puntiTotali = 0;
    puntiAppoggio = 0;
    appoggio = 3;
  }
  controllo = 0;
  if (programma == 0 && appoggio != 3) {
    MacchinaSceglie();
    Serial.print("Macchina ");
    Serial.println(programma);

  }
  if (programma != 0) {
    AggiungiPunti(programma);
  }
}



void Controllo() {
  if (avversario == 1 && programma != 6 && programma != 1) {
    controllo = 1;
  }
  if (avversario == 2 && programma != 5 && programma != 2) {
    controllo = 1;
  }
  if (avversario == 3 && programma != 4 && programma != 3) {
    controllo = 1;
  }
  if (avversario == 4 && programma != 4 && programma != 3) {
    controllo = 1;
  }
  if (avversario == 5 && programma != 5 && programma != 2) {
    controllo = 1;
  }
  if (avversario == 6 && programma != 6 && programma != 1) {
    controllo = 1;
  }
}

void MacchinaSceglie() {
  while (controllo == 0) {
    programma = random(1, 7);
    Controllo();
  }
}

void AggiungiPunti(int punti) {
  puntiTotali = puntiTotali + punti;
}

void CCV() { //ControlloCondizioniVincita
  if (puntiTotali == puntiMeta) {
    appoggio = 1;
  }
  if (puntiTotali > puntiMeta) {
    appoggio = 2;
  }
}

void ControllaMeta() {
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

void ControllaNumeroGiocatore() {
  while (Serial.available() > 0) {
    String numero = Serial.readString();

    if (numero.toInt() >= 1 && numero.toInt() <= 6) {
      avversario = numero.toInt();
    }
    else {
      Serial.println("Hai sbagliato inserimento del numero");
    }
  }
}

