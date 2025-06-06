#define TRIG 2
#define ECHO A0
#define PWM_PIN 10 //este es el pin del micro




void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  digitalWrite(TRIG, LOW);
  pinMode(PWM_PIN, OUTPUT);
}


void loop () {

  int promedio = promedioDistancia();
  int pwmValor = map(promedio, 0, 1023, 255, 0); //convierte los rangos de distancia (0, 1023) a un valor PWM (255, 0)
  pwmValor = constrain(pwmValor, 0, 255); //es para asegurar que no se salga del rango
  analogWrite(PWM_PIN, pwmValor); //le implementa el pwmValor al PWM_PIN

  lecturaDistancia();
  Serial.print("Promedio: ");
  Serial.print(promedio);
  delay(2000);
  //es para que se repita el promedio cada 2 segundos porque sino se lee una sola vez
}

void lecturaDistancia() {
  lecturaSensor = SensorDistancia(TRIG, ECHO);
  Serial.print("Distancia: ");
  Serial.print(lecturaSensor);
  Serial.print("cm");
  delay(1000);
  //lee lo que está dando el sensor
}

int sensorDistancia(int trigPin, int echoPin) {
  long duracion;
  int distancia;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); //se pone en low por 2 microsegundos para un clean start
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //después manda ondas por 10 microsegundos haber que onda
  digitalWrite(trigPin, LOW); //se apaga

  duracion = pulseIn(echoPin, HIGH); //lee cuanto tarda en volver el eco que mandó el trig, osea el tiempo que el ECHO estuvo en HIGH. el pulseIn mide ese tiempo en microsegundos
  distancia = duracion * 0.034/2; //paso a cm

  return distancia;
}



int promedioDistancia(){
  int suma = 0;
  int distancia = 0;
  for(int i = 0; i < 10; i++){ //toma 10 lecturas

    int lectura sensorDistancia(TRIG, ECHO); //llama a la función y guarda el valor en la variable lectura

    if(lectura == 0 || lectura >= 1023){ //si la lectura está entre eso valores tira error
      Serial.print("Error");
      i--; //reinicia la lectura
      delay(100);
      continue;
    } 

    suma += lectura; //suma las 10 lecturas
    delay(100);

    }
    int promedio = suma/10; //divide la suma por 10 para sacar el promedio
  }
  return promedio;
}









