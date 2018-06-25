#include <ESP8266WiFi.h>
#include <WebSocketsClient.h> //https://github.com/Links2004/arduinoWebSockets
#include <Ticker.h>


//ServerIP
const char* ServerIp("192.168.0.5");
int ServerPort = 8000;

//Ssid, pass
const char* Ssid = "your Wi-fi SSID";
const char* Password = "your Wi-fi PASSWORD";


WebSocketsClient webSocket;

//Initialize timer
Ticker ticker;

//Connected Flag
bool ConnectFlag = false;

//Timer callback
void doBlockingIO() {

    if(ConnectFlag){
        Serial.println("Send: Hello");
        webSocket.sendTXT("hello"); //Send Message
    }

}


void webSocketEvent(WStype_t type, uint8_t * payload, size_t lenght) {

    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[WSc] Disconnected!\n");
            ConnectFlag = false;
            break;

        case WStype_CONNECTED:
            {
                Serial.printf("[WSc] Connected to url: %s\n",  payload);
                ConnectFlag = true;
            }
            break;

        case WStype_TEXT:
           Serial.printf("[WSc]Recv: %s\n", payload);

            // send data to back to Server
            //webSocket.sendTXT(payload, lenght);
            break;

        case WStype_BIN:
            Serial.printf("[WSc] get binary lenght: %u\n", lenght);
            hexdump(payload, lenght);

            // echo data back to Server
            webSocket.sendBIN(payload, lenght);
            break;

        case WStype_ERROR:
            Serial.printf("We received an error \n");
            break;

        default:
            break;
    }

}


void setup() {
    Serial.begin(115200);
    Serial.print("\n\nStart\n");

    WiFi.begin(Ssid, Password);
    while(WiFi.status() != WL_CONNECTED) {
        Serial.print('.');
        delay(500);
        }

    Serial.println();
    Serial.printf("Connected, IP address: ");
    Serial.println(WiFi.localIP());

    //serverip
    webSocket.begin(ServerIp, ServerPort);
    webSocket.onEvent(webSocketEvent);
    Serial.println("Client started\n");

    //set timer
    ticker.attach(2, doBlockingIO); //2sec
    //set msec
    // ticker.attach_ms(60000, doBlockingIO);
}


void loop() {
    webSocket.loop();
}
