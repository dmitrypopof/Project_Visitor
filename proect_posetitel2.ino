// Проект позволяет вывести числа до 999 на экран ТВ через разьем RCA
#include "TVout.h"
#include "fontALL.h"
TVout TV;
#include "num0.h" //цифра 0
#include "num1.h"// цифра 1
#include "num2.h"// цифра 2
#include "num3.h"// цифра 3
#include "num4.h"// цифра 4
#include "num5.h"// цифра 5
#include "num6.h"// цифра 6
#include "num7.h"// цифра 7
#include "num8.h"// цифра 8
#include "num9.h"// цифра 9
#include <TextFinder.h>
#include <SPI.h>
#include <Ethernet.h>
byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // Мак адрес
byte ip[] = {  192, 168, 1, 77 }; // IP адрес (изменить в title)
//byte myDns[] = {192, 168, 1, 1};  // адрес DNS-сервера
//byte gateway[] = {192,168,1,1}; // адрес сетевого шлюза
//byte subnet[] = {255, 255, 255, 0};  // маска подсети
EthernetServer server(80);
int get = 0;
String inString = "";

void setup()
{
  TV.begin(PAL,120,70); //максимальное разрешение экрана 120х96 пикселей 
  TV.select_font(font8x8); 
  TV.set_cursor(0,6);
  TV.print("ready to start");
  //Старт
  Serial.begin(9600);
  Ethernet.begin(mac, ip);// Ethernet.begin(mac, ip, myDns,gateway,subnet )
  server.begin();
  Serial.println("device is ready");
}
void loop() {
  EthernetClient client = server.available();
  if (client)  {
    TextFinder response(client);
    while (client.connected())
    {
      if (client.available()) {
        if (response.find("GET /")) {
          if (response.find("guest=")) {
            get = response.getValue();
            Serial.println(get);
            TV.clear_screen();
            inString=get;
    if(inString.length() == 1) // Поймали 1 символ
            {

                switch(inString[0]){
        case '0': TV.bitmap(40,0,num0);break;
        case '1': TV.bitmap(40,0,num1);break;
        case '2': TV.bitmap(40,0,num2);break;
        case '3': TV.bitmap(40,0,num3);break;
        case '4': TV.bitmap(40,0,num4);break;
        case '5': TV.bitmap(40,0,num5);break;
        case '6': TV.bitmap(40,0,num6);break;
        case '7': TV.bitmap(40,0,num7);break;
        case '8': TV.bitmap(40,0,num8);break;
        case '9': TV.bitmap(40,0,num9);break;}           
            }
      else if(inString.length() == 2) // Поймали 2 символа
        {
               switch(inString[0]){
        case '0': TV.bitmap(25,0,num0);break;
        case '1': TV.bitmap(25,0,num1);break;
        case '2': TV.bitmap(25,0,num2);break;
        case '3': TV.bitmap(25,0,num3);break;
        case '4': TV.bitmap(25,0,num4);break;
        case '5': TV.bitmap(25,0,num5);break;
        case '6': TV.bitmap(25,0,num6);break;
        case '7': TV.bitmap(25,0,num7);break;
        case '8': TV.bitmap(25,0,num8);break;
        case '9': TV.bitmap(25,0,num9);break;}           
            
             switch(inString[1]){
        case '0': TV.bitmap(65,0,num0);break;
        case '1': TV.bitmap(65,0,num1);break;
        case '2': TV.bitmap(65,0,num2);break;
        case '3': TV.bitmap(65,0,num3);break;
        case '4': TV.bitmap(65,0,num4);break;
        case '5': TV.bitmap(65,0,num5);break;
        case '6': TV.bitmap(65,0,num6);break;
        case '7': TV.bitmap(65,0,num7);break;
        case '8': TV.bitmap(65,0,num8);break;
        case '9': TV.bitmap(65,0,num9);break;}           
            
        }
      else if(inString.length() == 3) // Поймали 3 символа
        {
               switch(inString[0]){
        case '0': TV.bitmap(0,0,num0);break;
        case '1': TV.bitmap(0,0,num1);break;
        case '2': TV.bitmap(0,0,num2);break;
        case '3': TV.bitmap(0,0,num3);break;
        case '4': TV.bitmap(0,0,num4);break;
        case '5': TV.bitmap(0,0,num5);break;
        case '6': TV.bitmap(0,0,num6);break;
        case '7': TV.bitmap(0,0,num7);break;
        case '8': TV.bitmap(0,0,num8);break;
        case '9': TV.bitmap(0,0,num9);break;}           
            
             switch(inString[1]){
        case '0': TV.bitmap(40,0,num0);break;
        case '1': TV.bitmap(40,0,num1);break;
        case '2': TV.bitmap(40,0,num2);break;
        case '3': TV.bitmap(40,0,num3);break;
        case '4': TV.bitmap(40,0,num4);break;
        case '5': TV.bitmap(40,0,num5);break;
        case '6': TV.bitmap(40,0,num6);break;
        case '7': TV.bitmap(40,0,num7);break;
        case '8': TV.bitmap(40,0,num8);break;
        case '9': TV.bitmap(40,0,num9);break;}  

            switch(inString[2]){
        case '0': TV.bitmap(80,0,num0);break;
        case '1': TV.bitmap(80,0,num1);break;
        case '2': TV.bitmap(80,0,num2);break;
        case '3': TV.bitmap(80,0,num3);break;
        case '4': TV.bitmap(80,0,num4);break;
        case '5': TV.bitmap(80,0,num5);break;
        case '6': TV.bitmap(80,0,num6);break;
        case '7': TV.bitmap(80,0,num7);break;
        case '8': TV.bitmap(80,0,num8);break;
        case '9': TV.bitmap(80,0,num9);break;}
            
        }
          else {
            TV.set_cursor(40,3);
            TV.print(get);
        }

            
            
            
          }
        }
        // Выводим HTML страницу
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println();
        client.println();
        client.println("<!DOCTYPE html>");
        client.println("<html lang=\"ru\">");
        client.println("<head>");
        client.println("<meta charset=\"UTF-8\">");
        client.println("<title>Home</title>");
        client.println("</head>");
        client.println("<body>");
        client.println("<h1>Посетитель</h1>");
        client.println("<h1>");
        client.println(get);
        client.println("</h1>");
        client.println("</body>");
        client.println("</html>");
        client.stop();
      }

      
    }
  }
}
