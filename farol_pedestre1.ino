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
  
    //carro verde
  digitalWrite(ledverde, LOW);
 
  digitalWrite(ledamarela, HIGH);

  digitalWrite(ledvermelha, LOW);

   
  //vermelho pedestre
  digitalWrite(ledverde2, LOW);
  digitalWrite(ledvermelha2, HIGH);
  delay(5000);
  
  if (digitalRead(botao)== HIGH)
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
	
  }
  

}
void blink1(){
state =  !state;
}

