//project air purifier
//pendefinisian pin IO
int PWM = 6; //set pwm berada pada pin6 arduino
int INA = 7; //INPUT driver motor A merupakan pin 7 arduino
int INB = 8; //INPUT driver motor B merupakan pin 8 arduino
int ledA=A0; // led A di tempatkan pada pin analog 0
int ledB=A3; // led B di tempatkan pada pin analog 3
int ledC=A5; // led C di tempatkan pada pin analog 5
int pb = 5 //pin 5 digunakan sebagai pushbutton
int counter = 0; //pendefinisian counter

//pembuatan fungsi, motor melakukan perputaran di set PWM 70 dari 255(atau sekitar 36% kecepatan putar motor)
int fungsiA(){
  digitalWrite(INA,HIGH); 
  digitalWrite(INB,LOW);
  analogWrite(PWM,70); //set kecepatan
  analogWrite(ledA,180); //led A menyala
  analogWrite(ledB,0); //led B mati
  analogWrite(ledC,0); //led C mati
  Serial.println("kondisiA");
  
}
//pembuatan fungsi, motor melakukan perputaran di set PWM 150 dari 255(atau sekitar 58% kecepatan putar motor)
int fungsiB(){
  digitalWrite(INA,HIGH);
  digitalWrite(INB,LOW);
  analogWrite(PWM,150); //set kecepatan
  digitalWrite(ledA,HIGH); //led A menyala
  digitalWrite(ledB,HIGH); //led A menyala
  digitalWrite(ledC,LOW); //led A mati
  Serial.println("kondisiB");  
}
//pembuatan fungsi, motor melakukan perputaran di set PWM 255 dari 255(atau sekitar 100% kecepatan putar motor)
int fungsiC(){
  digitalWrite(INA,HIGH);
  digitalWrite(INB,LOW);
  analogWrite(PWM,255); //set kecepatan
  digitalWrite(ledA,HIGH); //led A menyala
  digitalWrite(ledB,HIGH); //led B menyala
  digitalWrite(ledC,HIGH); //led C menyala
  Serial.println("kondisiC");  
}
//melakukan fungsi, motor berhenti & semua lampu mati
int fungsiD(){
  digitalWrite(INA,LOW);
  digitalWrite(INB,LOW);
  digitalWrite(ledA,LOW);
  digitalWrite(ledB,LOW);
  digitalWrite(ledC,LOW);
}
//melakukan fungsi penghitungan apabila pushbutton di tekan
int fungsi(){
    int sensor=digitalRead(pb); //pembacaan digital pada pushbutton disimpan pada variabel sensor
    Serial.print("nilai awal counter adalah= "); 
    Serial.println(counter); //melakukan print nilai counter
    if (sensor ==0){ //active low(apabila kondisi low) maka
    counter ++; //counter akan menghitung naik
    Serial.print("nilai akhir counter adalah= ");
    Serial.println(sensor);//melakukan print nilai
    Serial.println(counter); //melakukan print nilai counter   
   }
}  
//setup dan penetuan mode dari pin
void setup() {
  // put your setup code here, to run once:
  pinMode(PWM, OUTPUT);
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(pb, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
      while(counter==0){ //selama kondisi counter == 0 terpenuhi maka
        fungsiD(); //fungsi D akan dijalankan
        fungsi(); //fungsi pengecekan push button akan berjalan
        delay(200); //delay 200ms
      }while(counter==1){ //selama kondisi counter == 1 maka
        fungsiA(); //fungsi A dijalankan
        fungsi(); //fungsi pengecekan push button akan berjalan
        delay(200); //delay 200ms
      }while(counter==2){ //selama kondisi counter == 2 maka
        fungsiB(); //fungsi B dijalankan
        fungsi();//fungsi pengecekan push button akan berjalan
        delay(200); //delay 200 ms
      }while(counter==3){ //selama kondisi counter == 3 maka
        fungsiC(); //fungsi C dijalankan
        fungsi(); //fungsi pengecekan push button akan berjalan
        delay(200); //delay 200ms
      }while(counter==4){ //apabila kondisi counter == 4 maka
        counter=0; //nilai counter di reset kembali menjadi 0
      }
} 
