#include <AsyncTCP.h>
#include <WebServer.h>
#include <PublicProperties.h>

class WebServerHandler {
    private:
        PublicProperties publicProperties;

    public:
        void HandleSpeedRequest() {
            String stringValue = publicProperties.server.arg("value");
            int intValue = stringValue.toInt();

            Serial.println(stringValue);

            int dutyCycle = (pow(2,(1+(abs(intValue)*0.02)))-2)/6*511;

            if (intValue < 0) {
                ledcWrite(publicProperties.fwdPwmChannel, 0);
                ledcWrite(publicProperties.bckPwmChannel, dutyCycle);
            } else {
                ledcWrite(publicProperties.bckPwmChannel, 0);
                ledcWrite(publicProperties.fwdPwmChannel, dutyCycle);
            }

            publicProperties.server.send(200, "text/plain", String(intValue));
        }
};