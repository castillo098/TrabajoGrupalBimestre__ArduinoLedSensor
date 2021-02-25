int Trig = 10;  //Pin al cual se envia una señal    
int Echo = 9;   //Se obtiene un pulso que la señal a sido recibida    
int Led = 3;      
int Duracion;
int Distancia;

void setup()
{
  pinMode(Trig, OUTPUT); // trigger como salida 
  pinMode(Echo, INPUT);  // echo como entrada
  pinMode(Led, OUTPUT);  // LED como salida   
  Serial.begin(9600);    //Inicializacion de comunicacion serial a 9600 bps    
}
void loop(){
  digitalWrite(Trig, HIGH);       //Generar el psulo para enviar    
  delay(1);                       //Pin conectado al trigger
  digitalWrite(Trig, LOW);        //del sensor   
  Duracion = pulseIn(Echo, HIGH); // con funcion pulseIn se espera un pulso
                                  // alto en Echo
  Distancia = Duracion / 58.2;    // distancia medida en centimetros
  Serial.println(Distancia);      // envio de valor de distancia por monitor serial
  delay(200);                     // demora entre datos

  if(Distancia <= 20 && Distancia >= 0){
    digitalWrite(Led, HIGH);
    delay(Distancia * 10);
    digitalWrite(Led, LOW); 
  }  
}
