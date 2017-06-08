# Simple_socket_communication_of_ESP-WROOM-02

ESP-WROOM-02(ESP8266)におけるソケット通信のサンプルスケッチ

## 必須ライブラリ
* [WebSockets](https://github.com/Links2004/arduinoWebSockets)

## ファイル
* esp_client　・・・　クライアント側のプログラム(データを送信する側)
* esp_server　・・・　サーバー側のプログラム(データを受信する側)

## 使い方

### esp_client
    Server_ip　・・・　サーバーのIP

    port　・・・　サーバーのポート

    ssid ・・・　ルーターのSSID

    password　・・・　ルーターのパスワード

```Arduino
//IP
const char* Server_ip("192.168.11.5"); //server_ip
int port = 81; //server_port

//ssid, pass
const char* ssid = "your-ssid";
const char* password = "your-password";
```


### esp_server
    ip　・・・　サーバーのIP

    gateway　・・・　ゲートウェイ

    subnet　・・・　サブネット

    DNS　・・・　DNS

    port　・・・　サーバーのポート

    ssid ・・・　ルーターのSSID

    password　・・・　ルーターのパスワード

```Arduino
//Fit to Router
IPAddress ip(192, 168, 11, 5);
IPAddress gateway(192,168, 11, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress DNS(192, 168, 11, 1);
int port = 81;

//ssid, pass
const char* ssid = "your-ssid";
const char* password = "your-password";
```


## 実行結果
### esp_client(クライアント側)
```
[WSc] Connected to url: /
Send: Hello
[WSc]Recv: ok
Send: Hello
[WSc]Recv: ok
Send: Hello
[WSc]Recv: ok
Send: Hello
[WSc]Recv: ok
Send: Hello
[WSc]Recv: ok
Send: Hello
[WSc]Recv: ok
Send: Hello
[WSc]Recv: ok
```

### esp_server(サーバー側)
```
[2] Connected from 192.168.11.10 url: /
[2] get Text: hello_world
[2] get Text: hello_world
[2] get Text: hello_world
[2] get Text: hello_world
[2] get Text: hello_world
[2] get Text: hello_world
[2] get Text: hello_world
[2] get Text: hello_world
[2] get Text: hello_world
[2] get Text: hello_world
[2] get Text: hello_world
[2] get Text: hello_world
[2] get Text: hello_world
[2] get Text: hello_world
```



## 参考文献
* [GitHub](https://github.com/Links2004/arduinoWebSockets/issues/33)