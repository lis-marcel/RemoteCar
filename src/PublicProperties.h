#ifndef PUBLICPROPERTIES_H
#define PUBLICPROPERTIES_H
#include <WebServer.h>

// network
const char* NET_SSID = "foxnet";
const char* NET_PASSWD = "liskowoplus";

// setting PWM properties
const int FREQ = 5000;
const int FWD_PWMCHANNEL = 0;
const int BCK_PWMCHANNEL = 1;
const int RESOLUTION = 9;

// set pinout 
const int FWD_PIN = 2;
const int BCK_PIN = 4;

// web srever
WebServer SERVER{80};

String WEB_PAGE = "<!DOCTYPE HTML><html>\n"
"  <head>\n"
"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
"    <title>ESP Web Server</title>\n"
"  </head>\n"
"  <body>\n"
"    <div>\n"
"      <div class=\"settings\">\n"
"        <p><span id=\"textRangeValue\">0</span></p>\n"
"        <p><input type=\"range\" id=\"pwmRange\" min=\"-100\" max=\"100\" step=\"1\" default value=\"0\"></p>\n"
"      </div>\n"
"      \n"
"      <script>\n"
"        const pwm = document.getElementById(\"pwmRange\");\n"
"        var i = 0;\n"
"\n"
"        async function updatePwmRange() {\n"
"          try {\n"
"            var pwmValue = document.getElementById(\"pwmRange\").value;\n"
"            var pwmIntValue = parseInt(pwmValue);\n"
"\n"
"            document.getElementById(\"textRangeValue\").innerHTML = pwmIntValue + '%';\n"
"\n"
"            const response = await fetch(`/range?value=${pwmIntValue}`);\n"
"\n"
"            if (!response.ok) {\n"
"              throw new Error(`Request failed with status ${response.status}`);\n"
"            }\n"
"            const data = await response.json();\n"
"            console.log(data);\n"
"          }\n"
"\n"
"          catch (error) {\n"
"            console.error(error)\n"
"          }\n"
"        }\n"
"\n"
"        function initalizePwmRange() {\n"
"          updatePwmRange()\n"
"          pwm.addEventListener(\"input\", updatePwmRange)\n"
"        }\n"
"\n"
"        initalizePwmRange();\n"
"      </script>\n"
"    </div>\n"
"\n"
"    <div>\n"
"      <p>\n"
"        <iframe src=\"http://192.168.50.230:81/view\" width=\"640\" height=\"480\" />\n"
"      </p>\n"
"    </div>\n"
"  </body>\n"
"  </html>\";";

#endif