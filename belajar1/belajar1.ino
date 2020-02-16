int lampukuning=2; //saya menggunakan pin digital no 2

void setup() {
  // put your setup code here, to run once:
  pinMode(lampukuning, OUTPUT); //ini kode untuk setting pin tersebut mengeluarkan listrik
  //aktifkan serial monitor 
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0 ) { //jika ada tombol yang ditekan maka
    int tombol=Serial.read(); //simpan kode tombol ke dalam variabel
     Serial.println(tombol); //cetak kodenya ke layar

     if(tombol=='1') {
       Serial.println("Lampu Menyala");
       digitalWrite(lampukuning, HIGH);
      } else if (tombol=='2') {
       Serial.println("Lampu Mati");
       digitalWrite(lampukuning, LOW);
      }
   }
   
}
