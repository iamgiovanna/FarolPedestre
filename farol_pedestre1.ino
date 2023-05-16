// C++ code
//

const int ledverde = 1;
const int ledamarela = 5;
const int ledvermelha = 9;
const int ledvermelha2 = 3;
const int ledverde2 = 6;
const byte botao = 2;
volatile byte state = LOW;


void setup()
{
  pinMode(ledverde, OUTPUT);
  pinMode(ledvermelha, OUTPUT);
  pinMode(ledamarela, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(botao) , blink1 , CHANGE);
}

//verificar em que cor está o farol

void loop()
{
  //carro verde
  digitalWrite(ledverde, HIGH);
  digitalWrite(ledamarela, LOW);
  digitalWrite(ledvermelha, LOW);

   
  //vermelho pedestre
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledvermelha2, HIGH);
  delay(5000);
  
   //carro amarelo
  digitalWrite(ledverde, LOW);
  digitalWrite(ledamarela, HIGH);
  digitalWrite(ledvermelha, LOW);

   
  //vermelho pedestre
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledvermelha2, HIGH);
  delay(5000);
  
  //carro vermelho
  digitalWrite(ledverde, LOW);
  digitalWrite(ledamarela, LOW);
  digitalWrite(ledvermelha, HIGH);
  delay(5000);


  //verde pedestre
  digitalWrite(ledverde2, HIGH);
  digitalWrite(ledvermelha2, LOW);
  delay(5000);

  
  if (digitalRead(2)== HIGH)
{   //chamando a função
  
    pedestre();
}
  
}

void pedestre()
{
 //CARRO AMARELO
  digitalWrite(ledamarela, HIGH);
  digitalWrite(ledverde, LOW);
  digitalWrite(ledvermelha, LOW);
  delay(2000); 
	
  //vermelho pedestre
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledvermelha2, HIGH);
  delay(5000); 
 	    
  //VERDE PEDESTRE E VERMELHO CARRO
  digitalWrite(ledverde2, HIGH);
  digitalWrite(ledvermelha, HIGH);
  digitalWrite(ledamarela, LOW);
  digitalWrite(ledvermelha2, LOW);
  delay(5000);
  
  for(int i=0; i<=10; i++){
  //pisca pisca
    digitalWrite(ledvermelha2,HIGH);
  	delay(100);
    digitalWrite(ledvermelha2, LOW);
	delay(100);
  }

}

void blink1()
{
	state =  !state;
}

