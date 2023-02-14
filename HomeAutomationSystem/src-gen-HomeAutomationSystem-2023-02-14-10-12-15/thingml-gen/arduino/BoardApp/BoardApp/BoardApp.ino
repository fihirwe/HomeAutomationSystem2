#include <stdint.h>
#include <Arduino.h>
/*****************************************************************************
 * Headers for type : LightBulb
 *****************************************************************************/

// Definition of the instance struct:
struct LightBulb_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_inBulb;
// Variables for the current instance state
int LightBulb_LIGHTBULB_SM_State;
// Variables for the properties of the instance
uint8_t LightBulb_PIN11_var;

};
// Declaration of prototypes outgoing messages :
void LightBulb_LIGHTBULB_SM_OnEntry(int state, struct LightBulb_Instance *_instance);
void LightBulb_handle_inBulb_LightBulbOFF(struct LightBulb_Instance *_instance);
void LightBulb_handle_inBulb_LightBulbON(struct LightBulb_Instance *_instance);
// Declaration of callbacks for incoming messages:

// Definition of the states:
#define LIGHTBULB_LIGHTBULB_SM_STATE 0
#define LIGHTBULB_LIGHTBULB_SM_BULBREADY_STATE 1


/*****************************************************************************
 * Headers for type : TemperatureSensor
 *****************************************************************************/


// BEGIN: Code from the c_header annotation TemperatureSensor
#include <DHT.h>
// END: Code from the c_header annotation TemperatureSensor

// Definition of the instance struct:
struct TemperatureSensor_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_inTempSensor;
// Variables for the current instance state
int TemperatureSensor_TEMPERATURESENSOR_SM_State;
// Variables for the properties of the instance
uint8_t TemperatureSensor_PIN0_var;

};
// Declaration of prototypes outgoing messages :
void TemperatureSensor_TEMPERATURESENSOR_SM_OnEntry(int state, struct TemperatureSensor_Instance *_instance);
void TemperatureSensor_handle_inTempSensor_readSensor(struct TemperatureSensor_Instance *_instance);
// Declaration of callbacks for incoming messages:
void register_TemperatureSensor_send_inTempSensor_sensorData_listener(void (*_listener)(struct TemperatureSensor_Instance *, long));
void register_external_TemperatureSensor_send_inTempSensor_sensorData_listener(void (*_listener)(struct TemperatureSensor_Instance *, long));

// Definition of the states:
#define TEMPERATURESENSOR_TEMPERATURESENSOR_SM_STATE 0
#define TEMPERATURESENSOR_TEMPERATURESENSOR_SM_SENSING_STATE 1


/*****************************************************************************
 * Headers for type : WindowServo
 *****************************************************************************/

// Definition of the instance struct:
struct WindowServo_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_inWindow;
// Variables for the current instance state
int WindowServo_WINDOWSERVO_SM_State;
// Variables for the properties of the instance
uint8_t WindowServo_PIN13_var;

};
// Declaration of prototypes outgoing messages :
void WindowServo_WINDOWSERVO_SM_OnEntry(int state, struct WindowServo_Instance *_instance);
void WindowServo_handle_inWindow_WindowOPEN(struct WindowServo_Instance *_instance);
void WindowServo_handle_inWindow_WindowCLOSE(struct WindowServo_Instance *_instance);
// Declaration of callbacks for incoming messages:

// Definition of the states:
#define WINDOWSERVO_WINDOWSERVO_SM_STATE 0
#define WINDOWSERVO_WINDOWSERVO_SM_WINDOWREADY_STATE 1


/* Adds and instance to the runtime and returns its id */
uint16_t add_instance(void * instance_struct);
/* Returns the instance with id */
void * instance_by_id(uint16_t id);

/* Returns the number of byte currently in the fifo */
int fifo_byte_length();
/* Returns the number of bytes currently available in the fifo */
int fifo_byte_available();
/* Returns true if the fifo is empty */
int fifo_empty();
/* Return true if the fifo is full */
int fifo_full();
/* Enqueue 1 byte in the fifo if there is space
   returns 1 for sucess and 0 if the fifo was full */
int fifo_enqueue(byte b);
/* Enqueue 1 byte in the fifo without checking for available space
   The caller should have checked that there is enough space */
int _fifo_enqueue(byte b);
/* Dequeue 1 byte in the fifo.
   The caller should check that the fifo is not empty */
byte fifo_dequeue();
/*****************************************************************************
 * Headers for type : Board
 *****************************************************************************/

// Definition of the instance struct:
struct Board_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_fromSensorPort;
uint16_t id_toACUnit;
uint16_t id_toBulb;
uint16_t id_toServo;
// Variables for the current instance state
int Board_BOARD_SM_State;
// Variables for the properties of the instance

};
// Declaration of prototypes outgoing messages :
void Board_BOARD_SM_OnEntry(int state, struct Board_Instance *_instance);
void Board_handle_fromSensorPort_sensorData(struct Board_Instance *_instance, long value);
// Declaration of callbacks for incoming messages:
void register_Board_send_fromSensorPort_readSensor_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_fromSensorPort_readSensor_listener(void (*_listener)(struct Board_Instance *));
void register_Board_send_toACUnit_AC_ON_payload_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_toACUnit_AC_ON_payload_listener(void (*_listener)(struct Board_Instance *));
void register_Board_send_toACUnit_AC_OFF_payload_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_toACUnit_AC_OFF_payload_listener(void (*_listener)(struct Board_Instance *));
void register_Board_send_toBulb_LightBulbON_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_toBulb_LightBulbON_listener(void (*_listener)(struct Board_Instance *));
void register_Board_send_toBulb_LightBulbOFF_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_toBulb_LightBulbOFF_listener(void (*_listener)(struct Board_Instance *));
void register_Board_send_toServo_WindowOPEN_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_toServo_WindowOPEN_listener(void (*_listener)(struct Board_Instance *));
void register_Board_send_toServo_WindowCLOSE_listener(void (*_listener)(struct Board_Instance *));
void register_external_Board_send_toServo_WindowCLOSE_listener(void (*_listener)(struct Board_Instance *));

// Definition of the states:
#define BOARD_BOARD_SM_AC_OFFBULBOFFWINDOWCLOSE_STATE 0
#define BOARD_BOARD_SM_STATE 1
#define BOARD_BOARD_SM_IDLE_STATE 2
#define BOARD_BOARD_SM_AC_ONBULBONWINDOWOPEN_STATE 3


/*****************************************************************************
 * Headers for type : ACUnit
 *****************************************************************************/

// Definition of the instance struct:
struct ACUnit_Instance {

// Instances of different sessions
bool active;
// Variables for the ID of the ports of the instance
uint16_t id_inACUnit;
// Variables for the current instance state
int ACUnit_ACUNIT_SM_State;
// Variables for the properties of the instance
uint8_t ACUnit_PIN12_var;

};
// Declaration of prototypes outgoing messages :
void ACUnit_ACUNIT_SM_OnEntry(int state, struct ACUnit_Instance *_instance);
void ACUnit_handle_inACUnit_AC_OFF_payload(struct ACUnit_Instance *_instance);
void ACUnit_handle_inACUnit_AC_ON_payload(struct ACUnit_Instance *_instance);
// Declaration of callbacks for incoming messages:

// Definition of the states:
#define ACUNIT_ACUNIT_SM_STATE 0
#define ACUNIT_ACUNIT_SM_STANDBY_STATE 1


// Definition of Enumeration  DigitalState
#define DIGITALSTATE_LOW 0
#define DIGITALSTATE_HIGH 1


/*****************************************************************************
 * Implementation for type : TemperatureSensor
 *****************************************************************************/


// BEGIN: Code from the c_global annotation TemperatureSensor
DHT dht(0, DHT11);
// END: Code from the c_global annotation TemperatureSensor

// Declaration of prototypes:
//Prototypes: State Machine
void TemperatureSensor_TEMPERATURESENSOR_SM_OnExit(int state, struct TemperatureSensor_Instance *_instance);
//Prototypes: Message Sending
void TemperatureSensor_send_inTempSensor_sensorData(struct TemperatureSensor_Instance *_instance, long value);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void TemperatureSensor_TEMPERATURESENSOR_SM_OnEntry(int state, struct TemperatureSensor_Instance *_instance) {
switch(state) {
case TEMPERATURESENSOR_TEMPERATURESENSOR_SM_STATE:{
_instance->TemperatureSensor_TEMPERATURESENSOR_SM_State = TEMPERATURESENSOR_TEMPERATURESENSOR_SM_SENSING_STATE;
TemperatureSensor_TEMPERATURESENSOR_SM_OnEntry(_instance->TemperatureSensor_TEMPERATURESENSOR_SM_State, _instance);
break;
}
case TEMPERATURESENSOR_TEMPERATURESENSOR_SM_SENSING_STATE:{
dht.begin();
pinMode(_instance->TemperatureSensor_PIN0_var, OUTPUT);
break;
}
default: break;
}
}

// On Exit Actions:
void TemperatureSensor_TEMPERATURESENSOR_SM_OnExit(int state, struct TemperatureSensor_Instance *_instance) {
switch(state) {
case TEMPERATURESENSOR_TEMPERATURESENSOR_SM_STATE:{
TemperatureSensor_TEMPERATURESENSOR_SM_OnExit(_instance->TemperatureSensor_TEMPERATURESENSOR_SM_State, _instance);
break;}
case TEMPERATURESENSOR_TEMPERATURESENSOR_SM_SENSING_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void TemperatureSensor_handle_inTempSensor_readSensor(struct TemperatureSensor_Instance *_instance) {
if(!(_instance->active)) return;
//Region TEMPERATURESENSOR_SM
uint8_t TemperatureSensor_TEMPERATURESENSOR_SM_State_event_consumed = 0;
if (_instance->TemperatureSensor_TEMPERATURESENSOR_SM_State == TEMPERATURESENSOR_TEMPERATURESENSOR_SM_SENSING_STATE) {
if (TemperatureSensor_TEMPERATURESENSOR_SM_State_event_consumed == 0 && 1) {
delay(250);
TemperatureSensor_send_inTempSensor_sensorData(_instance, dht.readTemperature());
TemperatureSensor_TEMPERATURESENSOR_SM_State_event_consumed = 1;
}
}
//End Region TEMPERATURESENSOR_SM
//End dsregion TEMPERATURESENSOR_SM
//Session list: 
}

// Observers for outgoing messages:
void (*external_TemperatureSensor_send_inTempSensor_sensorData_listener)(struct TemperatureSensor_Instance *, long)= 0x0;
void (*TemperatureSensor_send_inTempSensor_sensorData_listener)(struct TemperatureSensor_Instance *, long)= 0x0;
void register_external_TemperatureSensor_send_inTempSensor_sensorData_listener(void (*_listener)(struct TemperatureSensor_Instance *, long)){
external_TemperatureSensor_send_inTempSensor_sensorData_listener = _listener;
}
void register_TemperatureSensor_send_inTempSensor_sensorData_listener(void (*_listener)(struct TemperatureSensor_Instance *, long)){
TemperatureSensor_send_inTempSensor_sensorData_listener = _listener;
}
void TemperatureSensor_send_inTempSensor_sensorData(struct TemperatureSensor_Instance *_instance, long value){
if (TemperatureSensor_send_inTempSensor_sensorData_listener != 0x0) TemperatureSensor_send_inTempSensor_sensorData_listener(_instance, value);
if (external_TemperatureSensor_send_inTempSensor_sensorData_listener != 0x0) external_TemperatureSensor_send_inTempSensor_sensorData_listener(_instance, value);
;
}



/*****************************************************************************
 * Implementation for type : ACUnit
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void ACUnit_ACUNIT_SM_OnExit(int state, struct ACUnit_Instance *_instance);
//Prototypes: Message Sending
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void ACUnit_ACUNIT_SM_OnEntry(int state, struct ACUnit_Instance *_instance) {
switch(state) {
case ACUNIT_ACUNIT_SM_STATE:{
_instance->ACUnit_ACUNIT_SM_State = ACUNIT_ACUNIT_SM_STANDBY_STATE;
ACUnit_ACUNIT_SM_OnEntry(_instance->ACUnit_ACUNIT_SM_State, _instance);
break;
}
case ACUNIT_ACUNIT_SM_STANDBY_STATE:{
pinMode(_instance->ACUnit_PIN12_var, OUTPUT);
break;
}
default: break;
}
}

// On Exit Actions:
void ACUnit_ACUNIT_SM_OnExit(int state, struct ACUnit_Instance *_instance) {
switch(state) {
case ACUNIT_ACUNIT_SM_STATE:{
ACUnit_ACUNIT_SM_OnExit(_instance->ACUnit_ACUNIT_SM_State, _instance);
break;}
case ACUNIT_ACUNIT_SM_STANDBY_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void ACUnit_handle_inACUnit_AC_OFF_payload(struct ACUnit_Instance *_instance) {
if(!(_instance->active)) return;
//Region ACUNIT_SM
uint8_t ACUnit_ACUNIT_SM_State_event_consumed = 0;
if (_instance->ACUnit_ACUNIT_SM_State == ACUNIT_ACUNIT_SM_STANDBY_STATE) {
if (ACUnit_ACUNIT_SM_State_event_consumed == 0 && 1) {
digitalWrite(_instance->ACUnit_PIN12_var, LOW);
ACUnit_ACUNIT_SM_State_event_consumed = 1;
}
}
//End Region ACUNIT_SM
//End dsregion ACUNIT_SM
//Session list: 
}
void ACUnit_handle_inACUnit_AC_ON_payload(struct ACUnit_Instance *_instance) {
if(!(_instance->active)) return;
//Region ACUNIT_SM
uint8_t ACUnit_ACUNIT_SM_State_event_consumed = 0;
if (_instance->ACUnit_ACUNIT_SM_State == ACUNIT_ACUNIT_SM_STANDBY_STATE) {
if (ACUnit_ACUNIT_SM_State_event_consumed == 0 && 1) {
digitalWrite(_instance->ACUnit_PIN12_var,HIGH);
ACUnit_ACUNIT_SM_State_event_consumed = 1;
}
}
//End Region ACUNIT_SM
//End dsregion ACUNIT_SM
//Session list: 
}

// Observers for outgoing messages:



/*****************************************************************************
 * Implementation for type : LightBulb
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void LightBulb_LIGHTBULB_SM_OnExit(int state, struct LightBulb_Instance *_instance);
//Prototypes: Message Sending
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void LightBulb_LIGHTBULB_SM_OnEntry(int state, struct LightBulb_Instance *_instance) {
switch(state) {
case LIGHTBULB_LIGHTBULB_SM_STATE:{
_instance->LightBulb_LIGHTBULB_SM_State = LIGHTBULB_LIGHTBULB_SM_BULBREADY_STATE;
LightBulb_LIGHTBULB_SM_OnEntry(_instance->LightBulb_LIGHTBULB_SM_State, _instance);
break;
}
case LIGHTBULB_LIGHTBULB_SM_BULBREADY_STATE:{
pinMode(_instance->LightBulb_PIN11_var, OUTPUT);
break;
}
default: break;
}
}

// On Exit Actions:
void LightBulb_LIGHTBULB_SM_OnExit(int state, struct LightBulb_Instance *_instance) {
switch(state) {
case LIGHTBULB_LIGHTBULB_SM_STATE:{
LightBulb_LIGHTBULB_SM_OnExit(_instance->LightBulb_LIGHTBULB_SM_State, _instance);
break;}
case LIGHTBULB_LIGHTBULB_SM_BULBREADY_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void LightBulb_handle_inBulb_LightBulbOFF(struct LightBulb_Instance *_instance) {
if(!(_instance->active)) return;
//Region LIGHTBULB_SM
uint8_t LightBulb_LIGHTBULB_SM_State_event_consumed = 0;
if (_instance->LightBulb_LIGHTBULB_SM_State == LIGHTBULB_LIGHTBULB_SM_BULBREADY_STATE) {
if (LightBulb_LIGHTBULB_SM_State_event_consumed == 0 && 1) {
digitalWrite(_instance->LightBulb_PIN11_var, LOW);
LightBulb_LIGHTBULB_SM_State_event_consumed = 1;
}
}
//End Region LIGHTBULB_SM
//End dsregion LIGHTBULB_SM
//Session list: 
}
void LightBulb_handle_inBulb_LightBulbON(struct LightBulb_Instance *_instance) {
if(!(_instance->active)) return;
//Region LIGHTBULB_SM
uint8_t LightBulb_LIGHTBULB_SM_State_event_consumed = 0;
if (_instance->LightBulb_LIGHTBULB_SM_State == LIGHTBULB_LIGHTBULB_SM_BULBREADY_STATE) {
if (LightBulb_LIGHTBULB_SM_State_event_consumed == 0 && 1) {
digitalWrite(_instance->LightBulb_PIN11_var,HIGH);
LightBulb_LIGHTBULB_SM_State_event_consumed = 1;
}
}
//End Region LIGHTBULB_SM
//End dsregion LIGHTBULB_SM
//Session list: 
}

// Observers for outgoing messages:



/*****************************************************************************
 * Implementation for type : Board
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void Board_BOARD_SM_OnExit(int state, struct Board_Instance *_instance);
//Prototypes: Message Sending
void Board_send_fromSensorPort_readSensor(struct Board_Instance *_instance);
void Board_send_toACUnit_AC_ON_payload(struct Board_Instance *_instance);
void Board_send_toACUnit_AC_OFF_payload(struct Board_Instance *_instance);
void Board_send_toBulb_LightBulbON(struct Board_Instance *_instance);
void Board_send_toBulb_LightBulbOFF(struct Board_Instance *_instance);
void Board_send_toServo_WindowOPEN(struct Board_Instance *_instance);
void Board_send_toServo_WindowCLOSE(struct Board_Instance *_instance);
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void Board_BOARD_SM_OnEntry(int state, struct Board_Instance *_instance) {
switch(state) {
case BOARD_BOARD_SM_STATE:{
_instance->Board_BOARD_SM_State = BOARD_BOARD_SM_IDLE_STATE;
Board_BOARD_SM_OnEntry(_instance->Board_BOARD_SM_State, _instance);
break;
}
case BOARD_BOARD_SM_AC_OFFBULBOFFWINDOWCLOSE_STATE:{
Board_send_fromSensorPort_readSensor(_instance);
break;
}
case BOARD_BOARD_SM_IDLE_STATE:{
Board_send_toServo_WindowCLOSE(_instance);
Board_send_toACUnit_AC_OFF_payload(_instance);
Board_send_toBulb_LightBulbOFF(_instance);
Board_send_fromSensorPort_readSensor(_instance);
break;
}
case BOARD_BOARD_SM_AC_ONBULBONWINDOWOPEN_STATE:{
Board_send_fromSensorPort_readSensor(_instance);
break;
}
default: break;
}
}

// On Exit Actions:
void Board_BOARD_SM_OnExit(int state, struct Board_Instance *_instance) {
switch(state) {
case BOARD_BOARD_SM_STATE:{
Board_BOARD_SM_OnExit(_instance->Board_BOARD_SM_State, _instance);
break;}
case BOARD_BOARD_SM_AC_OFFBULBOFFWINDOWCLOSE_STATE:{
break;}
case BOARD_BOARD_SM_IDLE_STATE:{
break;}
case BOARD_BOARD_SM_AC_ONBULBONWINDOWOPEN_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void Board_handle_fromSensorPort_sensorData(struct Board_Instance *_instance, long value) {
if(!(_instance->active)) return;
//Region BOARD_SM
uint8_t Board_BOARD_SM_State_event_consumed = 0;
if (_instance->Board_BOARD_SM_State == BOARD_BOARD_SM_AC_OFFBULBOFFWINDOWCLOSE_STATE) {
if (Board_BOARD_SM_State_event_consumed == 0 && value > 30) {
Board_BOARD_SM_OnExit(BOARD_BOARD_SM_AC_OFFBULBOFFWINDOWCLOSE_STATE, _instance);
_instance->Board_BOARD_SM_State = BOARD_BOARD_SM_AC_ONBULBONWINDOWOPEN_STATE;
Board_BOARD_SM_OnEntry(BOARD_BOARD_SM_AC_ONBULBONWINDOWOPEN_STATE, _instance);
Board_BOARD_SM_State_event_consumed = 1;
}
else if (Board_BOARD_SM_State_event_consumed == 0 && 1) {
Board_send_toACUnit_AC_OFF_payload(_instance);
Board_send_toServo_WindowCLOSE(_instance);
Board_send_toBulb_LightBulbOFF(_instance);
Board_send_fromSensorPort_readSensor(_instance);
Board_BOARD_SM_State_event_consumed = 1;
}
}
else if (_instance->Board_BOARD_SM_State == BOARD_BOARD_SM_AC_ONBULBONWINDOWOPEN_STATE) {
if (Board_BOARD_SM_State_event_consumed == 0 && value < 30) {
Board_BOARD_SM_OnExit(BOARD_BOARD_SM_AC_ONBULBONWINDOWOPEN_STATE, _instance);
_instance->Board_BOARD_SM_State = BOARD_BOARD_SM_AC_OFFBULBOFFWINDOWCLOSE_STATE;
Board_BOARD_SM_OnEntry(BOARD_BOARD_SM_AC_OFFBULBOFFWINDOWCLOSE_STATE, _instance);
Board_BOARD_SM_State_event_consumed = 1;
}
else if (Board_BOARD_SM_State_event_consumed == 0 && 1) {
Board_send_toServo_WindowOPEN(_instance);
Board_send_toACUnit_AC_ON_payload(_instance);
Board_send_toBulb_LightBulbON(_instance);
Board_send_fromSensorPort_readSensor(_instance);
Board_BOARD_SM_State_event_consumed = 1;
}
}
//End Region BOARD_SM
//End dsregion BOARD_SM
//Session list: 
}
int Board_handle_empty_event(struct Board_Instance *_instance) {
 uint8_t empty_event_consumed = 0;
if(!(_instance->active)) return 0;
//Region BOARD_SM
if (_instance->Board_BOARD_SM_State == BOARD_BOARD_SM_IDLE_STATE) {
if (1) {
Board_BOARD_SM_OnExit(BOARD_BOARD_SM_IDLE_STATE, _instance);
_instance->Board_BOARD_SM_State = BOARD_BOARD_SM_AC_OFFBULBOFFWINDOWCLOSE_STATE;
Board_BOARD_SM_OnEntry(BOARD_BOARD_SM_AC_OFFBULBOFFWINDOWCLOSE_STATE, _instance);
return 1;
}
}
//begin dispatchEmptyToSession
//end dispatchEmptyToSession
return empty_event_consumed;
}

// Observers for outgoing messages:
void (*external_Board_send_fromSensorPort_readSensor_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_fromSensorPort_readSensor_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_fromSensorPort_readSensor_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_fromSensorPort_readSensor_listener = _listener;
}
void register_Board_send_fromSensorPort_readSensor_listener(void (*_listener)(struct Board_Instance *)){
Board_send_fromSensorPort_readSensor_listener = _listener;
}
void Board_send_fromSensorPort_readSensor(struct Board_Instance *_instance){
if (Board_send_fromSensorPort_readSensor_listener != 0x0) Board_send_fromSensorPort_readSensor_listener(_instance);
if (external_Board_send_fromSensorPort_readSensor_listener != 0x0) external_Board_send_fromSensorPort_readSensor_listener(_instance);
;
}
void (*external_Board_send_toACUnit_AC_ON_payload_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_toACUnit_AC_ON_payload_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_toACUnit_AC_ON_payload_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_toACUnit_AC_ON_payload_listener = _listener;
}
void register_Board_send_toACUnit_AC_ON_payload_listener(void (*_listener)(struct Board_Instance *)){
Board_send_toACUnit_AC_ON_payload_listener = _listener;
}
void Board_send_toACUnit_AC_ON_payload(struct Board_Instance *_instance){
if (Board_send_toACUnit_AC_ON_payload_listener != 0x0) Board_send_toACUnit_AC_ON_payload_listener(_instance);
if (external_Board_send_toACUnit_AC_ON_payload_listener != 0x0) external_Board_send_toACUnit_AC_ON_payload_listener(_instance);
;
}
void (*external_Board_send_toACUnit_AC_OFF_payload_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_toACUnit_AC_OFF_payload_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_toACUnit_AC_OFF_payload_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_toACUnit_AC_OFF_payload_listener = _listener;
}
void register_Board_send_toACUnit_AC_OFF_payload_listener(void (*_listener)(struct Board_Instance *)){
Board_send_toACUnit_AC_OFF_payload_listener = _listener;
}
void Board_send_toACUnit_AC_OFF_payload(struct Board_Instance *_instance){
if (Board_send_toACUnit_AC_OFF_payload_listener != 0x0) Board_send_toACUnit_AC_OFF_payload_listener(_instance);
if (external_Board_send_toACUnit_AC_OFF_payload_listener != 0x0) external_Board_send_toACUnit_AC_OFF_payload_listener(_instance);
;
}
void (*external_Board_send_toBulb_LightBulbON_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_toBulb_LightBulbON_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_toBulb_LightBulbON_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_toBulb_LightBulbON_listener = _listener;
}
void register_Board_send_toBulb_LightBulbON_listener(void (*_listener)(struct Board_Instance *)){
Board_send_toBulb_LightBulbON_listener = _listener;
}
void Board_send_toBulb_LightBulbON(struct Board_Instance *_instance){
if (Board_send_toBulb_LightBulbON_listener != 0x0) Board_send_toBulb_LightBulbON_listener(_instance);
if (external_Board_send_toBulb_LightBulbON_listener != 0x0) external_Board_send_toBulb_LightBulbON_listener(_instance);
;
}
void (*external_Board_send_toBulb_LightBulbOFF_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_toBulb_LightBulbOFF_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_toBulb_LightBulbOFF_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_toBulb_LightBulbOFF_listener = _listener;
}
void register_Board_send_toBulb_LightBulbOFF_listener(void (*_listener)(struct Board_Instance *)){
Board_send_toBulb_LightBulbOFF_listener = _listener;
}
void Board_send_toBulb_LightBulbOFF(struct Board_Instance *_instance){
if (Board_send_toBulb_LightBulbOFF_listener != 0x0) Board_send_toBulb_LightBulbOFF_listener(_instance);
if (external_Board_send_toBulb_LightBulbOFF_listener != 0x0) external_Board_send_toBulb_LightBulbOFF_listener(_instance);
;
}
void (*external_Board_send_toServo_WindowOPEN_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_toServo_WindowOPEN_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_toServo_WindowOPEN_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_toServo_WindowOPEN_listener = _listener;
}
void register_Board_send_toServo_WindowOPEN_listener(void (*_listener)(struct Board_Instance *)){
Board_send_toServo_WindowOPEN_listener = _listener;
}
void Board_send_toServo_WindowOPEN(struct Board_Instance *_instance){
if (Board_send_toServo_WindowOPEN_listener != 0x0) Board_send_toServo_WindowOPEN_listener(_instance);
if (external_Board_send_toServo_WindowOPEN_listener != 0x0) external_Board_send_toServo_WindowOPEN_listener(_instance);
;
}
void (*external_Board_send_toServo_WindowCLOSE_listener)(struct Board_Instance *)= 0x0;
void (*Board_send_toServo_WindowCLOSE_listener)(struct Board_Instance *)= 0x0;
void register_external_Board_send_toServo_WindowCLOSE_listener(void (*_listener)(struct Board_Instance *)){
external_Board_send_toServo_WindowCLOSE_listener = _listener;
}
void register_Board_send_toServo_WindowCLOSE_listener(void (*_listener)(struct Board_Instance *)){
Board_send_toServo_WindowCLOSE_listener = _listener;
}
void Board_send_toServo_WindowCLOSE(struct Board_Instance *_instance){
if (Board_send_toServo_WindowCLOSE_listener != 0x0) Board_send_toServo_WindowCLOSE_listener(_instance);
if (external_Board_send_toServo_WindowCLOSE_listener != 0x0) external_Board_send_toServo_WindowCLOSE_listener(_instance);
;
}




#define MAX_INSTANCES 8
#define FIFO_SIZE 256

/*********************************
 * Instance IDs and lookup
 *********************************/

void * instances[MAX_INSTANCES];
uint16_t instances_count = 0;

void * instance_by_id(uint16_t id) {
  return instances[id];
}

uint16_t add_instance(void * instance_struct) {
  instances[instances_count] = instance_struct;
  return instances_count++;
}

/******************************************
 * Simple byte FIFO implementation
 ******************************************/

byte fifo[FIFO_SIZE];
int fifo_head = 0;
int fifo_tail = 0;

// Returns the number of byte currently in the fifo
int fifo_byte_length() {
  if (fifo_tail >= fifo_head)
    return fifo_tail - fifo_head;
  return fifo_tail + FIFO_SIZE - fifo_head;
}

// Returns the number of bytes currently available in the fifo
int fifo_byte_available() {
  return FIFO_SIZE - 1 - fifo_byte_length();
}

// Returns true if the fifo is empty
int fifo_empty() {
  return fifo_head == fifo_tail;
}

// Return true if the fifo is full
int fifo_full() {
  return fifo_head == ((fifo_tail + 1) % FIFO_SIZE);
}

// Enqueue 1 byte in the fifo if there is space
// returns 1 for sucess and 0 if the fifo was full
int fifo_enqueue(byte b) {
  int new_tail = (fifo_tail + 1) % FIFO_SIZE;
  if (new_tail == fifo_head) return 0; // the fifo is full
  fifo[fifo_tail] = b;
  fifo_tail = new_tail;
  return 1;
}

// Enqueue 1 byte in the fifo without checking for available space
// The caller should have checked that there is enough space
int _fifo_enqueue(byte b) {
  fifo[fifo_tail] = b;
  fifo_tail = (fifo_tail + 1) % FIFO_SIZE;
  return 0; // Dummy added by steffend
}

// Dequeue 1 byte in the fifo.
// The caller should check that the fifo is not empty
byte fifo_dequeue() {
  if (!fifo_empty()) {
    byte result = fifo[fifo_head];
    fifo_head = (fifo_head + 1) % FIFO_SIZE;
    return result;
  }
  return 0;
}

/*****************************************************************************
 * Implementation for type : WindowServo
 *****************************************************************************/

// Declaration of prototypes:
//Prototypes: State Machine
void WindowServo_WINDOWSERVO_SM_OnExit(int state, struct WindowServo_Instance *_instance);
//Prototypes: Message Sending
//Prototypes: Function
// Declaration of functions:

// Sessions functionss:


// On Entry Actions:
void WindowServo_WINDOWSERVO_SM_OnEntry(int state, struct WindowServo_Instance *_instance) {
switch(state) {
case WINDOWSERVO_WINDOWSERVO_SM_STATE:{
_instance->WindowServo_WINDOWSERVO_SM_State = WINDOWSERVO_WINDOWSERVO_SM_WINDOWREADY_STATE;
WindowServo_WINDOWSERVO_SM_OnEntry(_instance->WindowServo_WINDOWSERVO_SM_State, _instance);
break;
}
case WINDOWSERVO_WINDOWSERVO_SM_WINDOWREADY_STATE:{
pinMode(_instance->WindowServo_PIN13_var, OUTPUT);
break;
}
default: break;
}
}

// On Exit Actions:
void WindowServo_WINDOWSERVO_SM_OnExit(int state, struct WindowServo_Instance *_instance) {
switch(state) {
case WINDOWSERVO_WINDOWSERVO_SM_STATE:{
WindowServo_WINDOWSERVO_SM_OnExit(_instance->WindowServo_WINDOWSERVO_SM_State, _instance);
break;}
case WINDOWSERVO_WINDOWSERVO_SM_WINDOWREADY_STATE:{
break;}
default: break;
}
}

// Event Handlers for incoming messages:
void WindowServo_handle_inWindow_WindowOPEN(struct WindowServo_Instance *_instance) {
if(!(_instance->active)) return;
//Region WINDOWSERVO_SM
uint8_t WindowServo_WINDOWSERVO_SM_State_event_consumed = 0;
if (_instance->WindowServo_WINDOWSERVO_SM_State == WINDOWSERVO_WINDOWSERVO_SM_WINDOWREADY_STATE) {
if (WindowServo_WINDOWSERVO_SM_State_event_consumed == 0 && 1) {
digitalWrite(_instance->WindowServo_PIN13_var,HIGH);
WindowServo_WINDOWSERVO_SM_State_event_consumed = 1;
}
}
//End Region WINDOWSERVO_SM
//End dsregion WINDOWSERVO_SM
//Session list: 
}
void WindowServo_handle_inWindow_WindowCLOSE(struct WindowServo_Instance *_instance) {
if(!(_instance->active)) return;
//Region WINDOWSERVO_SM
uint8_t WindowServo_WINDOWSERVO_SM_State_event_consumed = 0;
if (_instance->WindowServo_WINDOWSERVO_SM_State == WINDOWSERVO_WINDOWSERVO_SM_WINDOWREADY_STATE) {
if (WindowServo_WINDOWSERVO_SM_State_event_consumed == 0 && 1) {
digitalWrite(_instance->WindowServo_PIN13_var, LOW);
WindowServo_WINDOWSERVO_SM_State_event_consumed = 1;
}
}
//End Region WINDOWSERVO_SM
//End dsregion WINDOWSERVO_SM
//Session list: 
}

// Observers for outgoing messages:






/*****************************************************************************
 * Definitions for configuration : BoardApp
 *****************************************************************************/

//Declaration of instance variables
//Instance temperaturesensorObj
// Variables for the properties of the instance
struct TemperatureSensor_Instance temperaturesensorObj_var;
// Variables for the sessions of the instance
//Instance acunitObj
// Variables for the properties of the instance
struct ACUnit_Instance acunitObj_var;
// Variables for the sessions of the instance
//Instance windowservoObj
// Variables for the properties of the instance
struct WindowServo_Instance windowservoObj_var;
// Variables for the sessions of the instance
//Instance boardObj
// Variables for the properties of the instance
struct Board_Instance boardObj_var;
// Variables for the sessions of the instance
//Instance lightbulbObj
// Variables for the properties of the instance
struct LightBulb_Instance lightbulbObj_var;
// Variables for the sessions of the instance


// Enqueue of messages TemperatureSensor::inTempSensor::sensorData
void enqueue_TemperatureSensor_send_inTempSensor_sensorData(struct TemperatureSensor_Instance *_instance, long value){
if ( fifo_byte_available() > 8 ) {

_fifo_enqueue( (1 >> 8) & 0xFF );
_fifo_enqueue( 1 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_inTempSensor >> 8) & 0xFF );
_fifo_enqueue( _instance->id_inTempSensor & 0xFF );

// parameter value
union u_value_t {
long p;
byte bytebuffer[4];
} u_value;
u_value.p = value;
_fifo_enqueue(u_value.bytebuffer[0] & 0xFF );
_fifo_enqueue(u_value.bytebuffer[1] & 0xFF );
_fifo_enqueue(u_value.bytebuffer[2] & 0xFF );
_fifo_enqueue(u_value.bytebuffer[3] & 0xFF );
}
}
// Enqueue of messages Board::fromSensorPort::readSensor
void enqueue_Board_send_fromSensorPort_readSensor(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_fromSensorPort >> 8) & 0xFF );
_fifo_enqueue( _instance->id_fromSensorPort & 0xFF );
}
}
// Enqueue of messages Board::toACUnit::AC_OFF_payload
void enqueue_Board_send_toACUnit_AC_OFF_payload(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toACUnit >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toACUnit & 0xFF );
}
}
// Enqueue of messages Board::toACUnit::AC_ON_payload
void enqueue_Board_send_toACUnit_AC_ON_payload(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toACUnit >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toACUnit & 0xFF );
}
}
// Enqueue of messages Board::toBulb::LightBulbOFF
void enqueue_Board_send_toBulb_LightBulbOFF(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toBulb >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toBulb & 0xFF );
}
}
// Enqueue of messages Board::toBulb::LightBulbON
void enqueue_Board_send_toBulb_LightBulbON(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toBulb >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toBulb & 0xFF );
}
}
// Enqueue of messages Board::toServo::WindowOPEN
void enqueue_Board_send_toServo_WindowOPEN(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toServo >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toServo & 0xFF );
}
}
// Enqueue of messages Board::toServo::WindowCLOSE
void enqueue_Board_send_toServo_WindowCLOSE(struct Board_Instance *_instance){
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source port of the instance
_fifo_enqueue( (_instance->id_toServo >> 8) & 0xFF );
_fifo_enqueue( _instance->id_toServo & 0xFF );
}
}


//New dispatcher for messages
void dispatch_WindowCLOSE(uint16_t sender) {
if (sender == boardObj_var.id_toServo) {
WindowServo_handle_inWindow_WindowCLOSE(&windowservoObj_var);

}

}


//New dispatcher for messages
void dispatch_AC_ON_payload(uint16_t sender) {
if (sender == boardObj_var.id_toACUnit) {
ACUnit_handle_inACUnit_AC_ON_payload(&acunitObj_var);

}

}


//New dispatcher for messages
void dispatch_readSensor(uint16_t sender) {
if (sender == boardObj_var.id_fromSensorPort) {
TemperatureSensor_handle_inTempSensor_readSensor(&temperaturesensorObj_var);

}

}


//New dispatcher for messages
void dispatch_WindowOPEN(uint16_t sender) {
if (sender == boardObj_var.id_toServo) {
WindowServo_handle_inWindow_WindowOPEN(&windowservoObj_var);

}

}


//New dispatcher for messages
void dispatch_LightBulbOFF(uint16_t sender) {
if (sender == boardObj_var.id_toBulb) {
LightBulb_handle_inBulb_LightBulbOFF(&lightbulbObj_var);

}

}


//New dispatcher for messages
void dispatch_AC_OFF_payload(uint16_t sender) {
if (sender == boardObj_var.id_toACUnit) {
ACUnit_handle_inACUnit_AC_OFF_payload(&acunitObj_var);

}

}


//New dispatcher for messages
void dispatch_LightBulbON(uint16_t sender) {
if (sender == boardObj_var.id_toBulb) {
LightBulb_handle_inBulb_LightBulbON(&lightbulbObj_var);

}

}


//New dispatcher for messages
void dispatch_sensorData(uint16_t sender, long param_value) {
if (sender == temperaturesensorObj_var.id_inTempSensor) {
Board_handle_fromSensorPort_sensorData(&boardObj_var, param_value);

}

}


int processMessageQueue() {
if (fifo_empty()) return 0; // return 0 if there is nothing to do

uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 2:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_readSensor = 2;
dispatch_readSensor((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 7:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_WindowOPEN = 2;
dispatch_WindowOPEN((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 5:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_LightBulbOFF = 2;
dispatch_LightBulbOFF((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 3:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_AC_OFF_payload = 2;
dispatch_AC_OFF_payload((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 8:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_WindowCLOSE = 2;
dispatch_WindowCLOSE((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 6:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_LightBulbON = 2;
dispatch_LightBulbON((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
case 1:{
byte mbuf[8 - 2];
while (mbufi < (8 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_sensorData = 2;
union u_sensorData_value_t {
long p;
byte bytebuffer[4];
} u_sensorData_value;
u_sensorData_value.bytebuffer[0] = mbuf[mbufi_sensorData + 0];
u_sensorData_value.bytebuffer[1] = mbuf[mbufi_sensorData + 1];
u_sensorData_value.bytebuffer[2] = mbuf[mbufi_sensorData + 2];
u_sensorData_value.bytebuffer[3] = mbuf[mbufi_sensorData + 3];
mbufi_sensorData += 4;
dispatch_sensorData((mbuf[0] << 8) + mbuf[1] /* instance port*/,
 u_sensorData_value.p /* value */ );
break;
}
case 4:{
byte mbuf[4 - 2];
while (mbufi < (4 - 2)) mbuf[mbufi++] = fifo_dequeue();
uint8_t mbufi_AC_ON_payload = 2;
dispatch_AC_ON_payload((mbuf[0] << 8) + mbuf[1] /* instance port*/);
break;
}
}
return 1;
}


//external Message enqueue

void initialize_configuration_BoardApp() {
// Initialize connectors
register_TemperatureSensor_send_inTempSensor_sensorData_listener(&enqueue_TemperatureSensor_send_inTempSensor_sensorData);
register_Board_send_fromSensorPort_readSensor_listener(&enqueue_Board_send_fromSensorPort_readSensor);
register_Board_send_toACUnit_AC_OFF_payload_listener(&enqueue_Board_send_toACUnit_AC_OFF_payload);
register_Board_send_toACUnit_AC_ON_payload_listener(&enqueue_Board_send_toACUnit_AC_ON_payload);
register_Board_send_toBulb_LightBulbOFF_listener(&enqueue_Board_send_toBulb_LightBulbOFF);
register_Board_send_toBulb_LightBulbON_listener(&enqueue_Board_send_toBulb_LightBulbON);
register_Board_send_toServo_WindowOPEN_listener(&enqueue_Board_send_toServo_WindowOPEN);
register_Board_send_toServo_WindowCLOSE_listener(&enqueue_Board_send_toServo_WindowCLOSE);


// Network Initialization
// End Network Initialization

// Init the ID, state variables and properties for instance temperaturesensorObj
temperaturesensorObj_var.active = true;
temperaturesensorObj_var.id_inTempSensor = add_instance( (void*) &temperaturesensorObj_var);
temperaturesensorObj_var.TemperatureSensor_TEMPERATURESENSOR_SM_State = TEMPERATURESENSOR_TEMPERATURESENSOR_SM_SENSING_STATE;
temperaturesensorObj_var.TemperatureSensor_PIN0_var = 0;

TemperatureSensor_TEMPERATURESENSOR_SM_OnEntry(TEMPERATURESENSOR_TEMPERATURESENSOR_SM_STATE, &temperaturesensorObj_var);
// Init the ID, state variables and properties for instance acunitObj
acunitObj_var.active = true;
acunitObj_var.id_inACUnit = add_instance( (void*) &acunitObj_var);
acunitObj_var.ACUnit_ACUNIT_SM_State = ACUNIT_ACUNIT_SM_STANDBY_STATE;
acunitObj_var.ACUnit_PIN12_var = 12;

ACUnit_ACUNIT_SM_OnEntry(ACUNIT_ACUNIT_SM_STATE, &acunitObj_var);
// Init the ID, state variables and properties for instance windowservoObj
windowservoObj_var.active = true;
windowservoObj_var.id_inWindow = add_instance( (void*) &windowservoObj_var);
windowservoObj_var.WindowServo_WINDOWSERVO_SM_State = WINDOWSERVO_WINDOWSERVO_SM_WINDOWREADY_STATE;
windowservoObj_var.WindowServo_PIN13_var = 13;

WindowServo_WINDOWSERVO_SM_OnEntry(WINDOWSERVO_WINDOWSERVO_SM_STATE, &windowservoObj_var);
// Init the ID, state variables and properties for instance lightbulbObj
lightbulbObj_var.active = true;
lightbulbObj_var.id_inBulb = add_instance( (void*) &lightbulbObj_var);
lightbulbObj_var.LightBulb_LIGHTBULB_SM_State = LIGHTBULB_LIGHTBULB_SM_BULBREADY_STATE;
lightbulbObj_var.LightBulb_PIN11_var = 11;

LightBulb_LIGHTBULB_SM_OnEntry(LIGHTBULB_LIGHTBULB_SM_STATE, &lightbulbObj_var);
// Init the ID, state variables and properties for instance boardObj
boardObj_var.active = true;
boardObj_var.id_fromSensorPort = add_instance( (void*) &boardObj_var);
boardObj_var.id_toACUnit = add_instance( (void*) &boardObj_var);
boardObj_var.id_toBulb = add_instance( (void*) &boardObj_var);
boardObj_var.id_toServo = add_instance( (void*) &boardObj_var);
boardObj_var.Board_BOARD_SM_State = BOARD_BOARD_SM_IDLE_STATE;

Board_BOARD_SM_OnEntry(BOARD_BOARD_SM_STATE, &boardObj_var);
}




void setup() {
initialize_configuration_BoardApp();

}

void loop() {

// Network Listener// End Network Listener

int emptyEventConsumed = 1;
while (emptyEventConsumed != 0) {
emptyEventConsumed = 0;
emptyEventConsumed += Board_handle_empty_event(&boardObj_var);
}

    processMessageQueue();
}
