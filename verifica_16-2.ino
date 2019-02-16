int red = 13;
int yellow = 11;
int blue = 7;
int green = 5;
int  durata;
int i =0;
int giro;
int mini;
int maxi;


void rosso() {
  digitalWrite (red, HIGH);
  digitalWrite (yellow, LOW);
  digitalWrite (blue,LOW);
  digitalWrite (green, LOW);
}
void giallo() {
  digitalWrite (red, LOW);
  digitalWrite (yellow, HIGH);
  digitalWrite (blue,LOW);
  digitalWrite (green, LOW);
}
void blu() {
  digitalWrite (red, LOW);
  digitalWrite (yellow, LOW);
  digitalWrite (blue,HIGH);
  digitalWrite (green, LOW);
}
void verde() {
  digitalWrite (red, LOW);
  digitalWrite (yellow, LOW);
  digitalWrite (blue,LOW);
  digitalWrite (green, HIGH);
}
void serie() {
  rosso();
  delay(durata);
  giallo();
  delay(durata);
  blu();
  delay(durata);
  verde();
  delay(durata);
}

void finito() {
  digitalWrite (red, LOW);
  digitalWrite (yellow, LOW);
  digitalWrite (blue,LOW);
  digitalWrite (green, LOW);
}
void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
  //Serial.println("inserire durata dei led(in ms)");
  //while(Serial.available()==0){}
  //durata = Serial.readString().toInt();
  //Serial.println(durata);
  Serial.println("numero di cicli da far eseguire");
  while(Serial.available()==0){}
  giro = Serial.readString().toInt();
  Serial.println(giro);
  Serial.println("durata casuale minima (in ms)");
  while(Serial.available()==0){}
  mini = Serial.readString().toInt();
  Serial.println(mini);
  Serial.println("durata casuale massima in ms (PIU GRABDE DELLA MINIMA");
  while(Serial.available()==0){}
  maxi = Serial.readString().toInt();
  Serial.println(maxi);
  randomSeed(analogRead(0));

  
}


void loop() {
  // put your main code here,; to run repeatedly:
  while(i<giro){
  durata = random (mini,maxi);
  Serial.println("durata impostata randomicamente");
  Serial.println(durata);
  serie();
  i++;
  }
  finito();
  
}
