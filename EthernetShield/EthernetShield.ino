#include <Ethernet.h>
#include <SPI.h>
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
EthernetServer server(80);
int ledMerah=3;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledMerah, OUTPUT);
  Ethernet.begin(mac);
  server.begin();
  Serial.begin(9600);
  Serial.print("IP Arduino Adalah ");
  Serial.print(Ethernet.localIP());
}

void loop() {
  //cek koneksi
  EthernetClient client=server.available();
  if(client) {
    boolean currentLineIsBlank=true;
    String buffer="";
    while(client.connected()) {
      if(client.available()) {
        char c = client.read();
        buffer+=c;
        if (c == "\n" && currentLineIsBlank) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Tye: text/html");
          client.println();
          client.print("<center><h2>Arduino dengan Web</h2><br>");
          client.print("<form>");
          client.print("<p><input type='submit' name='status' value='on'></p>");
          client.print("<p><input type='submit' name='status' value='off'></p>");
          client.print("</form>");
          client.print("</center>");
          break;
        }
        if (c == "\n") {
          currentLineIsBlank=true;
          buffer="";
        } else if (c =="\r") {
            if(buffer.indexOf("GET /?status=on")>=0) {
              digitalWrite(ledMerah, HIGH);
             }
            if(buffer.indexOf("GET /?status=off")>=0) {
              digitalWrite(ledMerah, LOW);
             }
        } else {
          currentLineIsBlank=false;    
        }      
     }    
   } 
   client.stop();
  }
}
