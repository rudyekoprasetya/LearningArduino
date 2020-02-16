int pinMerah=2; //pin digital nomor 2
int pinHijau=3; //pin digital nomor 3
int pinKuning=4; //pin digital nomor 4
int perintah; //variable untuk menampung perintah keyboard

void setup() {

 //setting pin
 pinMode(pinMerah, OUTPUT);
 pinMode(pinHijau, OUTPUT);
 pinMode(pinKuning, OUTPUT);

 //aktifkan serial
 Serial.begin(9600);  

}

void loop() {
//menampilkan menu ke serial menonitor
 Serial.println("+----------------------------+");
 Serial.println("+     Aplikasi Kontrol LED   +");
 Serial.println("+----------------------------+");

 Serial.println("Tekan Nomor Keyboard dibawah");
 Serial.println("1. LED Merah Menyala");
 Serial.println("2. LED Kuning Menyala");
 Serial.println("3. LED Hijau Menyala");
 Serial.println("4. Semua LED mati");
 Serial.println("5. Semua Menyala");
 Serial.println("Pilihan[] ");
 delay(1000); //untuk jeda 1 detik
 
 //jika ada perintah dari serial
 if(Serial.available() > 0) {
   //membaca input serial/keyboard
   perintah=Serial.read();   
 
 //kode ON OFF led dengan keyboard
 if(perintah=='1') { 
    digitalWrite(pinMerah, HIGH);
    digitalWrite(pinKuning, LOW);
    digitalWrite(pinHijau, LOW);
    Serial.println("Lampu Merah Menyala");
 } else if(perintah=='2') { 
    digitalWrite(pinMerah, LOW);
    digitalWrite(pinKuning, HIGH);
    digitalWrite(pinHijau, LOW);
    Serial.println("Lampu Kuning Menyala");
 } else if (perintah=='3') {
    digitalWrite(pinMerah, LOW);
    digitalWrite(pinKuning, LOW);
    digitalWrite(pinHijau, HIGH);
    Serial.println("Lampu Hijau Menyala");  
 } else if (perintah=='4') {
    digitalWrite(pinMerah, LOW);
    digitalWrite(pinKuning, LOW);
    digitalWrite(pinHijau, LOW);
    Serial.println("Lampu Mati Semua");   
 } else if (perintah=='5') {
    digitalWrite(pinMerah, HIGH);
    digitalWrite(pinKuning, HIGH);
    digitalWrite(pinHijau, HIGH);
    Serial.println("Lampu Menyala Semua");  
 }
       }
}

