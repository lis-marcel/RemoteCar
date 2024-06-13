#include <WiFi.h>
#include "EnviromentSetupModel.h"
#include "PublicProperties.h"

void EnviromentSetup::SetupWebServer() {
    // TODO - load page from file into sth like struct in esp32 !!!!!!!!!!!!!!!
    // String webPage;

    SERVER.send(200, "text/html", WEB_PAGE);
}

void EnviromentSetup::SetupPinout() {
    // configure LED PWM functionalitites
    ledcSetup(BCK_PWMCHANNEL, FREQ, RESOLUTION);
    ledcSetup(FWD_PWMCHANNEL, FREQ, RESOLUTION);
    
    // attach the channel to the GPIO to be controlled
    ledcAttachPin(BCK_PIN, BCK_PWMCHANNEL);
    ledcAttachPin(FWD_PIN, FWD_PWMCHANNEL);
    
    ledcWrite(BCK_PWMCHANNEL, 0);
    ledcWrite(FWD_PWMCHANNEL, 0);
}

void EnviromentSetup::SetupNetwork() {
    WiFi.begin(NET_SSID, NET_PASSWD);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    // Print ESP Local IP Address
    Serial.println("");
    Serial.println(WiFi.localIP());
}