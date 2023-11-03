#include "bitmaps.h"
#include "font.h"
#include "lcd_registers.h"

//SD
#include <SPI.h>
#include <SD.h>


#include "pitches.h"
//Definición de Pines
#define LCD_RST PD_0
#define LCD_CS PD_1
#define LCD_RS PD_2
#define LCD_WR PD_3
#define LCD_RD PE_1
int DPINS[] = {PB_0, PB_1, PB_2, PB_3, PB_4, PB_5, PB_6, PB_7};

//***************************************************************************************************************
// Definición de Pines
//***************************************************************************************************************


//Pines de los leds
#define ledR PF_1
#define ledA PF_2
#define ledV PF_3

//Botones
#define NOTE_C4_1 260
#define btn1 PF_4
#define btn2 PF_0

//***************************************************************************************************************
// Prototipo de Funciones
//***************************************************************************************************************
void BTN1(void);
void BTN2(void);

//SD
void writeSD(void);
void readSD(void);

//***************************************************************************************************************
// Variables Globales
//***************************************************************************************************************
String datoC;

File archivo; 

//Valores globales
int valor = 0; 
int dB = 0;

//Valores del Buzzer
int buzzerPin = PF_1;
int melody[] = {
   NOTE_C4_1, NOTE_D4};
   
int melody2[] = {
   NOTE_D4, NOTE_C4_1};

int noteDurations[] = {
  4, 2};

  void setup() {
  
  Serial.begin(115200);
  Serial2.begin(115200);
  
  while (!Serial) {
    ; 
  }


  Serial.print("Initializing SD card...");
  pinMode(PA_3, OUTPUT);
  SPI.setModule(0);

  if (!SD.begin(PA_3)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  //Pines de Salida
  pinMode(buzzerPin,OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);

  
  readSD();
  
  
  Serial.begin(115200);
  GPIOPadConfigSet(GPIO_PORTB_BASE, 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7, GPIO_STRENGTH_8MA, GPIO_PIN_TYPE_STD_WPU);
  Serial.println("Inicio");
  
  }

  //***************************************************************************************************************
// Loop Principal
//***************************************************************************************************************


void loop() {

  if(digitalRead(btn1) == LOW){
    BTN1();
     
   }
   
  if(digitalRead(btn2) == LOW){
    BTN2();
    writeSD();
    
   }

  if(Serial2.available() > 0){
    valor = Serial2.read(); 
    Serial.println(valor);
  }
  
  delay(100);
  
}

//***************************************************************************************************************
// Función ReadSD
//***************************************************************************************************************

void readSD(void){
  archivo = SD.open("datos.txt");
  if (archivo) {
    Serial.println("El archivo contiene lo siguiente:");

    // read from the file until there's nothing else in it:
    while (archivo.available()) {
      Serial.write(archivo.read());
    }
    // close the file:
    archivo.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening datos.txt");
  }
  }

//***************************************************************************************************************
// Función WriteSD
//***************************************************************************************************************
void writeSD(void){
    archivo = SD.open("datos.txt", FILE_WRITE);
  
  if (archivo) {
    Serial.print("Writing to datos.txt...");
    
    archivo.println(datoC);
    // close the file:
    archivo.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening datos.txt");
  }
  
  }


//***************************************************************************************************************
// Función BTN1
//***************************************************************************************************************

void BTN1(void){
  Serial.println("La temperatura registrada es: ");
  Serial.println(valor);
     
}

//***************************************************************************************************************
// Función BTN2
//***************************************************************************************************************
void BTN2(void){
  Serial.println("La temperatura almacenada es: ");
  Serial.println(valor);
}
