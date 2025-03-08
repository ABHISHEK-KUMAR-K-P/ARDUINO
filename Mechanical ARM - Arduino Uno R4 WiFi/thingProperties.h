//CODE FOR INTERNET CONNECTION - ARDUINO CLOUD

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char SSID[]     = SSID_NAME;    // Network SSID (name)
const char PASS[]     = PASSWORD;    // Network password (use for WPA, or use as key for WEP)

void onFrontChange();
void onLiftChange();
void onTurnChange();
void onCatcHChange();

int front;
int lift;
int turn;
bool catcH;

void initProperties(){

  ArduinoCloud.addProperty(front, READWRITE, ON_CHANGE, onFrontChange);
  ArduinoCloud.addProperty(lift, READWRITE, ON_CHANGE, onLiftChange);
  ArduinoCloud.addProperty(turn, READWRITE, ON_CHANGE, onTurnChange);
  ArduinoCloud.addProperty(catcH, READWRITE, ON_CHANGE, onCatcHChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASSWORD);

