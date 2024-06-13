// Import required libraries
#include <AsyncTCP.h>
#include <WebServer.h>
#include "SPIFFS.h"
#include "PublicProperties.h"
#include "EnviromentSetupModel.h"

EnviromentSetup enviromentSetup;
String rangeValue = "0";
const char* PARAM_INPUT = "value";

// Replaces placeholder with button section in your web page
String processor(const String& var) {
  if (var == "rangeValue"){
    return rangeValue;
  }
  return String();
}

void setup() {
  Serial.begin(115200);

  SERVER.on("/", HTTP_GET, enviromentSetup.SetupWebServer());
  SERVER.on("/range", HTTP_GET, webServerHandler->HandleSpeedRequest());

  SERVER.begin();
}
  
void loop() {
  SERVER.handleClient();
}
