#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include "define.h"
#include "sensor.h"
#include "displayLCD.h"
#include "BluetoothSerial.h"
#include <WiFiManager.h>
#include <WebServer.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

extern String ssid;
extern String password;
extern String id_BLE;
extern String id_device;
extern BluetoothSerial SerialBT;
extern bool blockSend;

extern bool flagCheckUpdate;
extern bool flagUpdate;
extern String fwVer;
extern String fwContent;

void connectWIFI();
void saveCredentialsToEEPROM();
void loadCredentialsFromEEPROM();

void settingBLE_ThresholdPositive(void);
// String getName_ThresholdPositive(sick_type sick);
// uint32_t getData_ThresholdPositive(sick_type sick);
float EnterCalib(void);

void connect_GoogleSheet(void);
void postData_GoogleSheet(uint8_t sick, uint32_t sensor_val1, uint32_t sensor_val2, uint32_t sensor_val3, String id);

void settingWifi(void);
void settingUpdate(void);
void settingThreshold(void);

void checkFirmware(void);
void firmwareUpdate(void);
#endif