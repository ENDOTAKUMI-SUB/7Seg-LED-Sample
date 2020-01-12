/*
 * File:   main.c
 * Author: endo0
 *
 * Created on 2019/12/06, 23:22
 */

// PIC16F1827 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1
#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable (PWRT enabled)
#pragma config MCLRE = OFF      // MCLR Pin Function Select (MCLR/VPP pin function is digital input)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable (Brown-out Reset enabled)
#pragma config CLKOUTEN = OFF   // Clock Out Enable (CLKOUT function is disabled. I/O or oscillator function on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)

// CONFIG2
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = OFF      // PLL Enable (4x PLL disabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = HI        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), high trip point selected.)
#pragma config LVP = OFF        // Low-Voltage Programming Enable (High-voltage on MCLR/VPP must be used for programming)

#define _XTAL_FREQ  8000000 
#define POWER_LED RB3

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

void Wait(unsigned int num){
    int i ;

    for (i=0 ; i<num ; i++){
        __delay_ms(10);
    }
}

void init(void) {
    OSCCON = 0b01110010;
    ANSELA = 0b00000000;
    ANSELB = 0b00000000;
    TRISA  = 0b00000000;
    TRISB  = 0b00000000;
    PORTA  = 0b00000000;
    PORTB  = 0b00000000;
}

void seg(int numeric) {
    switch(numeric){
        case 0:
            RA0 = 0;
            RA1 = 1;
            RA2 = 0;
            RA3 = 0;
            RA7 = 0;
            RB4 = 0;
            RB5 = 0;
            break;
        case 1:
            RA0 = 1;
            RA1 = 1;
            RA2 = 0;
            RA3 = 1;
            RA7 = 1;
            RB4 = 0;
            RB5 = 1;
            break;
        case 2:
            RA0 = 1;
            RA1 = 0;
            RA2 = 0;
            RA3 = 0;
            RA7 = 0;
            RB4 = 1;
            RB5 = 0;
            break;
        case 3:
            RA0 = 1;
            RA1 = 0;
            RA2 = 0;
            RA3 = 0;
            RA7 = 0;
            RB4 = 0;
            RB5 = 1;
            break;
        case 4:
            RA0 = 0;
            RA1 = 0;
            RA2 = 0;
            RA3 = 1;
            RA7 = 1;
            RB4 = 0;
            RB5 = 1;
            break;
        case 5:
            RA0 = 0;
            RA1 = 0;
            RA2 = 1;
            RA3 = 0;
            RA7 = 0;
            RB4 = 0;
            RB5 = 1;
            break;
        case 6:
            RA0 = 0;
            RA1 = 0;
            RA2 = 1;
            RA3 = 0;
            RA7 = 0;
            RB4 = 0;
            RB5 = 0;
            break;
        case 7:
            RA0 = 1;
            RA1 = 1;
            RA2 = 0;
            RA3 = 1;
            RA7 = 0;
            RB4 = 0;
            RB5 = 1;
            break;
        case 8:
            RA0 = 0;
            RA1 = 0;
            RA2 = 0;
            RA3 = 0;
            RA7 = 0;
            RB4 = 0;
            RB5 = 0;
            break;
        case 9:
            RA0 = 0;
            RA1 = 0;
            RA2 = 0;
            RA3 = 1;
            RA7 = 0;
            RB4 = 0;
            RB5 = 1;
            break;
    }
}

void main(void) {
    init();

    unsigned int i,x;
    int a = 0, b = 0;
    
    for(x = 0;x<10;x++){
        i = 40;
        while(i>=1) {
            seg(x);
            
            RB1 = 1;
            RB2 = 0;
            
            Wait(1);
            
            seg(x);
            RB1 = 0;
            RB2 = 1;


            Wait(1);  
            
            i--;
        }
    }
    
    while(1){
        i = 4;
        while(i>=1) {
            seg(b);
            
            RB1 = 1;
            RB2 = 0;
            
            Wait(1);
            
            seg(a);
            RB1 = 0;
            RB2 = 1;


            Wait(1);  
            
            i--;
        }
        
        a++;
        if(a == 10) {
            a = 0;
            b++;
        }
        
        if(b == 10) {
            b = 0;
            a = 0;
        }
        
    }
}