// SE INVIERTEN EN ESTA VERSION LOS ESTADOS DE LAS SALIDAS DE LOS SEMAFOROS PARA CUBRIR CON LA NECESIDAD DEL RELEVADOR DE HIGH A LOW Y VICEVERSA

const int SSVerde = 8;     // Semaforo Salida Verde
const int SEVerde = 9;     // Semaforo Entrada Verde
const int SSRojo = 12;     // Semaforo Salida Rojo
const int SERojo = 13;     // Semaforo Entrada Rojo
const int LFault = 10;     // Luz de Falla

const int ButtonA = 2;  // Sensor A Entrada
const int ButtonB = 3;  // Sensor B Entrada
const int ButtonC = 4;  // Sensor C Salida
const int ButtonD = 5;  // Sensor D Salida
const int ButtonM = 11;  // Boton de semaforos modo manual
const int SelectA = 6;  // Selector modo automatico
const int SelectM = 7;  // Selector modo manual

int EstadoA = 0; // estado actual sensor A
int EstadoB = 0; //estado actual sensor B
int EstadoC = 0; //estado actual sensor C
int EstadoD = 0; //estado actual sensor D
int EstadoAut = 0; //estado actual selector Automatico
int EstadoMan = 0; //estado actual selector Manual
int EstadoPreA = 0;  //estado anterior sensor A
int EstadoPreB = 0;  //estado anterior sensor B
int EstadoPreC = 0;  //estado anterior sensor C
int EstadoPreD = 0;  //estado anterior sensor D
int InState = 0;  //variable entrada contador
int OutState = 0;   //variable salida contador
int MemGana = 0;  //Memoria que evita que se cambie el semaforo cuando un carro de la salida este pasando y despues entre uno en la entrada
int EstadoM = 0; // estado actual boton M
bool M1 = 0;  //memoria secuencial direccion A hacia B
bool M2 = 0;  //memoria secuencial direccion C hacia D
bool M3 = 0;  //memoria secuencial direccion D hacia C
bool M4 = 0;  //memoria secuencial direccion B hacia A
bool M1A = 0;  //memoria secuencial Problema de carros que vayan muy pegados entre ellos
bool M2A = 0;  //memoria secuencial Problema de carros que vayan muy pegados entre ellos
bool M3A = 0;  //memoria secuencial Problema de carros que vayan muy pegados entre ellos
bool M4A = 0;  //memoria secuencial Problema de carros que vayan muy pegados entre ellos

void setup() {
  pinMode(SSVerde, OUTPUT); //Declaro Semaforo salida verde como salida
  pinMode(SSRojo, OUTPUT); //Declaro Semaforo salida rojo como salida
  pinMode(SEVerde, OUTPUT); //Declaro Semaforo entrada verde como salida
  pinMode(SERojo, OUTPUT); //Declaro Semaforo salida verde como salida
  pinMode(LFault, OUTPUT); //Declaro led de falla como salida
 
  pinMode(ButtonA, INPUT); //Declaro Sensor A como entrada
  pinMode(ButtonB, INPUT); //Declaro Sensor B como entrada
  pinMode(ButtonC, INPUT); //Declaro Sensor C como entrada
  pinMode(ButtonD, INPUT); //Declaro Sensor D como entrada
  pinMode(ButtonM, INPUT); //Declaro Boton M como entrada
  pinMode(SelectA, INPUT); //Declaro Selector Automatico como entrada
  pinMode(SelectM, INPUT); //Declaro Selector Manual como entrada
  Serial.begin(9600);
}

void loop() {
  //leer el estado de los botones y selectores
  EstadoA = digitalRead(ButtonA);
  EstadoB = digitalRead(ButtonB);
  EstadoC = digitalRead(ButtonC);
  EstadoD = digitalRead(ButtonD);
  EstadoAut = digitalRead(SelectA);
  EstadoMan = digitalRead(SelectM);
  EstadoM = digitalRead(ButtonM);

 // unsigned long currentMillis = millis();

  //checo si el selector esta en auto o manual
  if (EstadoAut == HIGH){
// comparo eL ESTADO CON SU ESTADO PREVIO
      if (EstadoA != EstadoPreA) {
        // Si el estado ha cambiado incrementa el contador
        if (EstadoA == HIGH){
          // ecuaciones de memorias extras
           if(M4 == 1)
              M1A = 1;
           if(M1 == 1)
              M1A = 0;
           if(M3 == 1)
              M2A = 1;
           if(M2 == 1)
              M2A = 0;
           if(M1 == 1)
              M3A = 1;
           if(M3 == 1)
              M3A = 0;
           if(M1 == 1)
              M4A = 1;
           if(M4 == 1)
              M4A = 0;        
           M1 = 0;   
           if (EstadoA == 1 && EstadoB ==1)
            M4 =1;    
          Serial.println("on A");
          Serial.println("A: PA: B: PB: C: PC: D: PD: M1: M2: M3: M4: M1A: M2A: M3A: M4A: OutState: InState:");
          Serial.print(EstadoA);
          Serial.print("  ");
          Serial.print(EstadoPreA);
          Serial.print("   ");
          Serial.print(EstadoB);
          Serial.print("  ");
          Serial.print(EstadoPreB);
          Serial.print("   ");
          Serial.print(EstadoC);
          Serial.print("  ");
          Serial.print(EstadoPreC);
          Serial.print("   ");
          Serial.print(EstadoD);
          Serial.print("  ");
          Serial.print(EstadoPreD);
          Serial.print("   ");
          Serial.print(M1);
          Serial.print("   ");
          Serial.print(M2);
          Serial.print("   ");
          Serial.print(M3);
          Serial.print("   ");
          Serial.print(M4);
          Serial.print("   ");
          Serial.print(M1A);
          Serial.print("    ");
          Serial.print(M2A);
          Serial.print("    ");
          Serial.print(M3A);
          Serial.print("    ");
          Serial.print(M4A);
          Serial.print("        ");
          Serial.print(OutState);
          Serial.print("        ");
          Serial.print(InState);
          Serial.println("    ");
          
        } else {
          // ecuaciones de memorias extras
           if(M4 == 1)
              M1A = 1;
           if(M1 == 1)
              M1A = 0;
           if(M3 == 1)
              M2A = 1;
           if(M2 == 1)
              M2A = 0;
           if(M1 == 1)
              M3A = 1;
           if(M3 == 1)
              M3A = 0;
           if(M1 == 1)
              M4A = 1;
           if(M4 == 1)
              M4A = 0;
           M4 = 0;
           if (M1 == 1)
            OutState ++;
          // Si el estado fue LOW entonces el boton se fue de presionado a suelto:
          Serial.println("off A");
          Serial.println("A: PA: B: PB: C: PC: D: PD: M1: M2: M3: M4: M1A: M2A: M3A: M4A: OutState: InState:");
          Serial.print(EstadoA);
          Serial.print("  ");
          Serial.print(EstadoPreA);
          Serial.print("   ");
          Serial.print(EstadoB);
          Serial.print("  ");
          Serial.print(EstadoPreB);
          Serial.print("   ");
          Serial.print(EstadoC);
          Serial.print("  ");
          Serial.print(EstadoPreC);
          Serial.print("   ");
          Serial.print(EstadoD);
          Serial.print("  ");
          Serial.print(EstadoPreD);
          Serial.print("   ");
          Serial.print(M1);
          Serial.print("   ");
          Serial.print(M2);
          Serial.print("   ");
          Serial.print(M3);
          Serial.print("   ");
          Serial.print(M4);
          Serial.print("   ");
          Serial.print(M1A);
          Serial.print("    ");
          Serial.print(M2A);
          Serial.print("    ");
          Serial.print(M3A);
          Serial.print("    ");
          Serial.print(M4A);
          Serial.print("        ");
          Serial.print(OutState);
          Serial.print("        ");
          Serial.print(InState);
          Serial.println("    ");
              }               
        delay(50);
      }
      // sGuarda el estado pasado 
      EstadoPreA = EstadoA;
  
      if (EstadoB != EstadoPreB) {
        // if the state has changed, increment the counter
        if (EstadoB == HIGH) {
          // if the current state is HIGH then the button went from off to on:
          // ecuaciones de memorias extras
           if(M4 == 1)
              M1A = 1;
           if(M1 == 1)
              M1A = 0;
           if(M3 == 1)
              M2A = 1;
           if(M2 == 1)
              M2A = 0;
           if(M1 == 1)
              M3A = 1;
           if(M3 == 1)
              M3A = 0;
           if(M1 == 1)
              M4A = 1;
           if(M4 == 1)
              M4A = 0;    
           if(EstadoA == 1 && EstadoB == 1)
              M1 = 1;      
           M4 = 0;
          Serial.println("on B");
          Serial.println("A: PA: B: PB: C: PC: D: PD: M1: M2: M3: M4: M1A: M2A: M3A: M4A: OutState: InState:");
          Serial.print(EstadoA);
          Serial.print("  ");
          Serial.print(EstadoPreA);
          Serial.print("   ");
          Serial.print(EstadoB);
          Serial.print("  ");
          Serial.print(EstadoPreB);
          Serial.print("   ");
          Serial.print(EstadoC);
          Serial.print("  ");
          Serial.print(EstadoPreC);
          Serial.print("   ");
          Serial.print(EstadoD);
          Serial.print("  ");
          Serial.print(EstadoPreD);
          Serial.print("   ");
          Serial.print(M1);
          Serial.print("   ");
          Serial.print(M2);
          Serial.print("   ");
          Serial.print(M3);
          Serial.print("   ");
          Serial.print(M4);
          Serial.print("   ");
          Serial.print(M1A);
          Serial.print("    ");
          Serial.print(M2A);
          Serial.print("    ");
          Serial.print(M3A);
          Serial.print("    ");
          Serial.print(M4A);
          Serial.print("        ");
          Serial.print(OutState);
          Serial.print("        ");
          Serial.print(InState);
          Serial.println("    ");
          } else {
          // if the current state is LOW then the button went from on to off:
            // ecuaciones de memorias extras
           if(M4 == 1)
              M1A = 1;
           if(M1 == 1)
              M1A = 0;
           if(M3 == 1)
              M2A = 1;
           if(M2 == 1)
              M2A = 0;
           if(M1 == 1)
              M3A = 1;
           if(M3 == 1)
              M3A = 0;
           if(M1 == 1)
              M4A = 1;
           if(M4 == 1)
              M4A = 0;          
           M1 = 0;    
           if (M4 == 1)
           InState--;
          Serial.println("off B");
          Serial.println("A: PA: B: PB: C: PC: D: PD: M1: M2: M3: M4: M1A: M2A: M3A: M4A: OutState: InState:");
          Serial.print(EstadoA);
          Serial.print("  ");
          Serial.print(EstadoPreA);
          Serial.print("   ");
          Serial.print(EstadoB);
          Serial.print("  ");
          Serial.print(EstadoPreB);
          Serial.print("   ");
          Serial.print(EstadoC);
          Serial.print("  ");
          Serial.print(EstadoPreC);
          Serial.print("   ");
          Serial.print(EstadoD);
          Serial.print("  ");
          Serial.print(EstadoPreD);
          Serial.print("   ");
          Serial.print(M1);
          Serial.print("   ");
          Serial.print(M2);
          Serial.print("   ");
          Serial.print(M3);
          Serial.print("   ");
          Serial.print(M4);
          Serial.print("   ");
          Serial.print(M1A);
          Serial.print("    ");
          Serial.print(M2A);
          Serial.print("    ");
          Serial.print(M3A);
          Serial.print("    ");
          Serial.print(M4A);
          Serial.print("        ");
          Serial.print(OutState);
          Serial.print("        ");
          Serial.print(InState);
          Serial.println("    ");
        }
        // Delay a little bit to avoid bouncing
        delay(50);
      }
      // save the current state as the last state, for next time through the loop
      EstadoPreB = EstadoB;
  
      if (EstadoC != EstadoPreC) {
        // if the state has changed, increment the counter
        if (EstadoC == HIGH) {
          // APLASTA C
           if(M4 == 1) // ecuaciones de memorias extras
              M1A = 1;
           if(M1 == 1)
              M1A = 0;
           if(M3 == 1)
              M2A = 1;
           if(M2 == 1)
              M2A = 0;
           if(M1 == 1)
              M3A = 1;
           if(M3 == 1)
              M3A = 0;
           if(M1 == 1)
              M4A = 1;
           if(M4 == 1)
              M4A = 0;
           M2 =0;
           if (EstadoC == 1 && EstadoD == 1)
            M3 =1;
            
          Serial.println("on C");
          Serial.println("A: PA: B: PB: C: PC: D: PD: M1: M2: M3: M4: M1A: M2A: M3A: M4A: OutState: InState:");
          Serial.print(EstadoA);
          Serial.print("  ");
          Serial.print(EstadoPreA);
          Serial.print("   ");
          Serial.print(EstadoB);
          Serial.print("  ");
          Serial.print(EstadoPreB);
          Serial.print("   ");
          Serial.print(EstadoC);
          Serial.print("  ");
          Serial.print(EstadoPreC);
          Serial.print("   ");
          Serial.print(EstadoD);
          Serial.print("  ");
          Serial.print(EstadoPreD);
          Serial.print("   ");
          Serial.print(M1);
          Serial.print("   ");
          Serial.print(M2);
          Serial.print("   ");
          Serial.print(M3);
          Serial.print("   ");
          Serial.print(M4);
          Serial.print("   ");
          Serial.print(M1A);
          Serial.print("    ");
          Serial.print(M2A);
          Serial.print("    ");
          Serial.print(M3A);
          Serial.print("    ");
          Serial.print(M4A);
          Serial.print("        ");
          Serial.print(OutState);
          Serial.print("        ");
          Serial.print(InState);
          Serial.println("    ");
        } else {
          // if the current state is LOW then the button went from on to off:
          // ecuaciones de memorias extras
           if(M4 == 1)
              M1A = 1;
           if(M1 == 1)
              M1A = 0;
           if(M3 == 1)
              M2A = 1;
           if(M2 == 1)
              M2A = 0;
           if(M1 == 1)
              M3A = 1;
           if(M3 == 1)
              M3A = 0;
           if(M1 == 1)
              M4A = 1;
           if(M4 == 1)
              M4A = 0;  
           M3 = 0;
           if (M2 ==1)
           OutState--;
          Serial.println("off C");
          Serial.println("A: PA: B: PB: C: PC: D: PD: M1: M2: M3: M4: M1A: M2A: M3A: M4A: OutState: InState:");
          Serial.print(EstadoA);
          Serial.print("  ");
          Serial.print(EstadoPreA);
          Serial.print("   ");
          Serial.print(EstadoB);
          Serial.print("  ");
          Serial.print(EstadoPreB);
          Serial.print("   ");
          Serial.print(EstadoC);
          Serial.print("  ");
          Serial.print(EstadoPreC);
          Serial.print("   ");
          Serial.print(EstadoD);
          Serial.print("  ");
          Serial.print(EstadoPreD);
          Serial.print("   ");
          Serial.print(M1);
          Serial.print("   ");
          Serial.print(M2);
          Serial.print("   ");
          Serial.print(M3);
          Serial.print("   ");
          Serial.print(M4);
          Serial.print("   ");
          Serial.print(M1A);
          Serial.print("    ");
          Serial.print(M2A);
          Serial.print("    ");
          Serial.print(M3A);
          Serial.print("    ");
          Serial.print(M4A);
          Serial.print("        ");
          Serial.print(OutState);
          Serial.print("        ");
          Serial.print(InState);
          Serial.println("    ");
        }
        // Delay a little bit to avoid bouncing
        delay(50);
      }
      // save the current state as the last state, for next time through the loop
      EstadoPreC = EstadoC;
   
       if (EstadoD != EstadoPreD) {
        // Si D APLASTA
        if (EstadoD == HIGH) {
          // if the current state is HIGH then the button went from off to on:
          // ecuaciones de memorias extras
           if(M4 == 1)
              M1A = 1;
           if(M1 == 1)
              M1A = 0;
           if(M3 == 1)
              M2A = 1;
           if(M2 == 1)
              M2A = 0;
           if(M1 == 1)
              M3A = 1;
           if(M3 == 1)
              M3A = 0;
           if(M1 == 1)
              M4A = 1;
           if(M4 == 1)
              M4A = 0;
           if(EstadoC == 1 && EstadoD == 1)
            M2 = 1;
           M3 = 0;
          Serial.println("on D");
          Serial.println("A: PA: B: PB: C: PC: D: PD: M1: M2: M3: M4: M1A: M2A: M3A: M4A: OutState: InState:");
          Serial.print(EstadoA);
          Serial.print("  ");
          Serial.print(EstadoPreA);
          Serial.print("   ");
          Serial.print(EstadoB);
          Serial.print("  ");
          Serial.print(EstadoPreB);
          Serial.print("   ");
          Serial.print(EstadoC);
          Serial.print("  ");
          Serial.print(EstadoPreC);
          Serial.print("   ");
          Serial.print(EstadoD);
          Serial.print("  ");
          Serial.print(EstadoPreD);
          Serial.print("   ");
          Serial.print(M1);
          Serial.print("   ");
          Serial.print(M2);
          Serial.print("   ");
          Serial.print(M3);
          Serial.print("   ");
          Serial.print(M4);
          Serial.print("   ");
          Serial.print(M1A);
          Serial.print("    ");
          Serial.print(M2A);
          Serial.print("    ");
          Serial.print(M3A);
          Serial.print("    ");
          Serial.print(M4A);
          Serial.print("        ");
          Serial.print(OutState);
          Serial.print("        ");
          Serial.print(InState);
          Serial.println("    ");
        } else {
         // if the current state is LOW then the button went from on to off:
          // ecuaciones de memorias extras
           if(M4 == 1)
              M1A = 1;
           if(M1 == 1)
              M1A = 0;
           if(M3 == 1)
              M2A = 1;
           if(M2 == 1)
              M2A = 0;
           if(M1 == 1)
              M3A = 1;
           if(M3 == 1)
              M3A = 0;
           if(M1 == 1)
              M4A = 1;
           if(M4 == 1)
              M4A = 0;
           M2 = 0;
           if (M3 == 1)
            InState ++;
          Serial.println("off D");
          Serial.println("A: PA: B: PB: C: PC: D: PD: M1: M2: M3: M4: M1A: M2A: M3A: M4A: OutState: InState:");
          Serial.print(EstadoA);
          Serial.print("  ");
          Serial.print(EstadoPreA);
          Serial.print("   ");
          Serial.print(EstadoB);
          Serial.print("  ");
          Serial.print(EstadoPreB);
          Serial.print("   ");
          Serial.print(EstadoC);
          Serial.print("  ");
          Serial.print(EstadoPreC);
          Serial.print("   ");
          Serial.print(EstadoD);
          Serial.print("  ");
          Serial.print(EstadoPreD);
          Serial.print("   ");
          Serial.print(M1);
          Serial.print("   ");
          Serial.print(M2);
          Serial.print("   ");
          Serial.print(M3);
          Serial.print("   ");
          Serial.print(M4);
          Serial.print("   ");
          Serial.print(M1A);
          Serial.print("    ");
          Serial.print(M2A);
          Serial.print("    ");
          Serial.print(M3A);
          Serial.print("    ");
          Serial.print(M4A);
          Serial.print("        ");
          Serial.print(OutState);
          Serial.print("        ");
          Serial.print(InState);
          Serial.println("    ");
          }
        // Delay a little bit to avoid bouncing
        delay(50);
      }
      // save the current state as the last state, for next time through the loop
      EstadoPreD = EstadoD;


       if (OutState >= InState && M3 == 0){
        digitalWrite(SSVerde, LOW);
        digitalWrite(SSRojo, HIGH);
        digitalWrite(SEVerde, HIGH);
        digitalWrite(SERojo, LOW);
      } 
      if (InState > OutState){
        digitalWrite(SEVerde, LOW);
        digitalWrite(SERojo, HIGH);
        digitalWrite(SSVerde, HIGH);
        digitalWrite(SSRojo, LOW);
      }
      if (InState< 0 && OutState>=1){
       InState = 0;
       OutState --;
       }
       if (OutState< 0 && InState>=1){
       InState --;
       OutState = 0;
       }   
       if (M3 ==1){
       digitalWrite(SEVerde, LOW);
       digitalWrite(SERojo, HIGH);
       digitalWrite(SSVerde, HIGH);
       digitalWrite(SSRojo, LOW);
       }}
    
    if (EstadoMan == HIGH){
     if (EstadoM ==   HIGH){
        digitalWrite(SSVerde, HIGH);
        digitalWrite(SSRojo, LOW);
        digitalWrite(SEVerde, LOW);
        digitalWrite(SERojo, HIGH);
        }
        else {
        digitalWrite(SSVerde, LOW);
        digitalWrite(SSRojo, HIGH);
        digitalWrite(SEVerde, HIGH);
        digitalWrite(SERojo, LOW);
        }
      }  
    }
      
    
