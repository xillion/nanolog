#include "mbed.h"
#include <pb_encode.h>
#include <pb_decode.h>
#include "nanolog.pb.h"

//OS Objects
USBSerial usb(false);
EventFlags powerEvents;
EventFlags wakeupEvents;

InterruptIn usbPowerInt(SYS_WKUP1, PullDown);
LowPowerTimeout lpTimeout; //Internal counter

//Variables
volatile bool isUsbPowered = false;
volatile bool isBatPowered = true;

//Defines
#define ALARM_WAKEUP   0x00
#define USB_POWER 0x01
#define BAT_POWER 0x02



void power_change_irq()
{
    if (usbPowerInt.read()) {
        isUsbPowered = true;
        powerEvents.set(USB_POWER);
    } else {
        IsUsbPowered = false;
        powerEvents.clear(USB_POWER);
    }
}

void lpTimeoutHendler(){
    lpTimeout.attach(&lpTimeoutHendler, 1s);
    wakeupEvents.set(ALARM_WAKEUP);
}

int main()
{
    /* This is the buffer where we will store our message. */
    uint8_t buffer[128];
    size_t message_length;
    bool status;

    while(true){
        //powerEvents.wait_all(POWER_USB, osWaitForever);
        while(isUsbPowered){
            lpTimeout.detach();
            if(sleep_manager_can_deep_sleep()){
                sleep_manager_lock_deep_sleep();//deny deep sleep
            }

            if(!usb.configured()){
                usb.connect();
            }
            if(usb.configured()){
                if(!usb.connected()){
                    usb.init();
                }
            }
            if(usb.connected()){
                if(usb.available()){

                }
                usb.printf("USB connection established\n");
            }
            else{

            }
        }
        while(isBatPowered){//Battery powered
            if(!sleep_manager_can_deep_sleep()){
                sleep_manager_unlock_deep_sleep();//allow deep sleep
            }
            lpTimeout.attach(&lpTimeoutHendler, 1s);
            wakeupEvents.wait_all(ALARM_WAKEUP);
        }

    }
    return 0;
}
