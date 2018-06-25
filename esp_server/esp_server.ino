#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>

//IP
IPAddress ip(192, 168, 0, 5);
IPAddress gateway(192,168, 0, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress DNS(192, 168, 0, 1);
int port = 8000;

//SSID, pass
const char* Ssid = "your Wi-fi SSID";
const char* Password = "your Wi-fi Password";



WebSocketsServer webSocket = WebSocketsServer(port);


void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
    const char * SendMessage = "Server-Message";

    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[%u] Disconnected!\n", num);
            break;

        case WStype_CONNECTED:
            {
                IPAddress ip = webSocket.remoteIP(num);
                Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);
            }
            break;

        case WStype_TEXT:
            Serial.printf("[%u] get Text: %s\n", num, payload);

            // echo data back to browser
            webSocket.sendTXT(num, SendMessage, strlen(SendMessage));
            // send data to all connected clients 全てのクライアントへ送信
            //webSocket.broadcastTXT(payload, length);
            break;

        case WStype_BIN:
            Serial.printf("[%u] get binary length: %u\n", num, length);
            hexdump(payload, length);
            // echo data back to browser
            webSocket.sendBIN(num, payload, length);
            break;

        case WStype_ERROR:
            break;

        default:
            break;
    }

}

void setup() {
    Serial.begin(115200);
    Serial.print("\n\nStart\n");

    WiFi.config(ip, gateway, subnet, DNS); //static ip
    delay(100);

    WiFi.begin(Ssid, Password);
    while(WiFi.status() != WL_CONNECTED) {
        Serial.print('.');
        delay(500);
    }
    Serial.println();
    Serial.printf("Connected, IP address: ");
    Serial.println(WiFi.localIP());


    webSocket.begin();
    webSocket.onEvent(webSocketEvent);
    Serial.printf("Server Started\n");
}

void loop() {
    webSocket.loop();
}
