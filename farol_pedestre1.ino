const int ledverde = 1;
const int ledamarela = 5;
const int ledvermelha = 9;
const int ledvermelha2 = 3;
const int ledverde2 = 6;
const byte botao = 2;
volatile byte state = LOW;
boolean delayled = false;

//todos com o número 2 é pedestre

void setup() {
    pinMode(ledverde,OUTPUT);
    pinMode(ledamarela,OUTPUT);
    pinMode(ledvermelha,OUTPUT);
    pinMode(ledverde2,OUTPUT);
    pinMode(ledvermelha2,OUTPUT);
    pinMode(botao, INPUT);
    attachInterrupt(digitalPinToInterrupt(botao), pedestre, CHANGE);
}

void loop() {
  
  digitalWrite(ledverde, HIGH);
  digitalWrite(ledamarela, LOW);
  digitalWrite(ledvermelha, LOW);
  
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledvermelha2, HIGH);
  
  for(int i = 0; delayled == false && i <3000;i+=100){
  	delay(300);
  }
 
  //carro amarelo
  digitalWrite(ledverde, LOW);
  digitalWrite(ledamarela, HIGH);
  digitalWrite(ledvermelha, LOW);
  delay(2000);
  
  /*ped vermelho
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledvermelha2, HIGH);*/
  
  //carro vermelho
  digitalWrite(ledverde, LOW);
  digitalWrite(ledamarela,LOW);
  digitalWrite(ledvermelha,HIGH);
  
  digitalWrite(ledverde2, HIGH);
  digitalWrite(ledvermelha2,LOW);
  delay(3000);

  digitalWrite(ledverde2, LOW);
  delay(1000);
  
  for(int i= 0; i<= 12; i++){
   digitalWrite(ledvermelha2, !(digitalRead(ledvermelha2)));
    	delay(250);
  
  }
  if(delayled == true){
  	delayled = false;
  }
}

 
 void pedestre()
{
   Serial.println("Passei por aqui");
   delayled = true;
}
