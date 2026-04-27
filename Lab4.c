#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
//#include "debounce.h"
//#include "counter.h"

//Debounce db_inc;
//Debounce db_dec;
//Counter counter;

long map(long x, long in_min, long in_max, long out_min, long out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void display_led(int value) {
    gpio_put(2, value & 0x1);
    gpio_put(3, (value >> 1) & 0x1);
    gpio_put(4, (value >> 2) & 0x1);
    gpio_put(5, (value >> 3) & 0x1);
}

/*
bool Tick(struct repeating_timer *t) {
    bool inc = gpio_get(6); 
    bool dec = gpio_get(7); 

    if (inc) counter_inc(&counter);
    if (dec) counter_dec(&counter);
    display_led(counter.value); 

    return true; 
}
*/ 

int main() {
    stdio_init_all();
    adc_init();

    gpio_init(2);
    gpio_init(3);
    gpio_init(4);
    gpio_init(5);
    //gpio_init(6); 
    //gpio_init(7);
    adc_gpio_init(26); 

    gpio_set_dir(2, true);
    gpio_set_dir(3, true);
    gpio_set_dir(4, true);
    gpio_set_dir(5, true);
    //gpio_set_dir(6, false);
    //gpio_set_dir(7, false);
    adc_select_input(0); 

    //db_init(&db_inc);
    //db_init(&db_dec);

    //counter_init(&counter);

    //struct repeating_timer timer; 
    //add_repeating_timer_ms(-500, Tick, NULL, &timer); 
    long adc_val = 0;  
    int val = 0; 

    while (true) {
        adc_val = adc_read(); 
        val = map(adc_val, 0, 4095, 0, 15);
        display_led(val); 
        sleep_ms(50); 
    }

}