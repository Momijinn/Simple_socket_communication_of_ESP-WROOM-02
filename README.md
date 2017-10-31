Simple_socket_communication_of_ESP-WROOM-02
====
ESP-WROOM-02(ESP8266)におけるソケット通信のサンプルスケッチ

## Description
ESP8266を2台利用して一つをサーバーもう一つをクライアントとしてソケット通信を行うためのサンプルプログラム

## Demo
* クライアント

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

* サーバー

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

## Requirement
* [WebSockets](https://github.com/Links2004/arduinoWebSockets)

## Usage
* esp_client.ino
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

* esp_server.ino
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

## Install
esp_client.inoとesp_server.inoをESP8266へ書き込む

## Licence
This software is released under the MIT License, see LICENSE.

## Author
[Twitter](https://twitter.com/momijinn_aka)

[Blog](http://www.autumn-color.com/)