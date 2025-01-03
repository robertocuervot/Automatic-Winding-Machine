/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K42
        Driver Version    :  2.00
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#include "mcc_generated_files/mcc.h"

// ##################################### CONSTANTES #############################
float w_ideal = 300; // Velocidad angular ideal para motor embobinado en RPM

// ##################################### VARIABLES ##############################
int estado;
bool TMR2_flag, TMR4_flag; //Banderas de los timers
int L, AWG, capas, sel_vel; //Datos que introduce el usuario
int diametro; // Parametros AWG
long tension; // Parametros AWG
int char_leido;
float t_capa1, t_embo;
int n_vueltas;
float RPM;
long int pasos_bobina, pasos_lineal;
float vel_lineal;
long int n_p_lineal, n_p_bobina;
//Para control
int GAIN = 1;
long int adc, promedio, aux, gramos, error;
long int gramo_abajo, gramo_arriba;
int pwm;
int gramos_d;
bool clockwise;

// #################################### FUNCIONES ################################
void mensaje_L(void);
void mensaje_AWG(void);
void mensaje_capas(void);
void mensaje_vels(void);
void mensaje_terminado(void);
void mensaje_capa2(void);
void mensaje_final(void);
void print_num(int);
int recibir_numero(void);
int Lectura_Serial(void);
char recibir_caracter(void);
void send_t(float, float);
void mensaje_boton(void);
int T_tmr2(float);
int T_tmr4(int);
//Para control
uint32_t hx711_read();
void set_gain(int gain1);
void init_hx(int gain1);
int32_t get_average(int times);

/*
                         Main application
 */
void main(void) {
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    estado = 0;
    L = 0;
    AWG = 0;
    capas = 0;
    sel_vel = 0;
    t_capa1 = 0.0;
    pasos_bobina = 0;
    pasos_lineal = 0;
    vel_lineal = 0;
    RPM = w_ideal;
    n_p_lineal = 0;
    n_p_bobina = 0;

    init_hx(128);
    adc = 0;
    promedio = 0;
    aux = 0;
    gramos = 0;
    gramos_d = 0;
    pwm = 600;
    clockwise = true;
    
    TMR2_flag = false;

    while (1) {
        // Add your application code
        switch (estado) {
            case 0: //Estado donde el usuario inicia el sistema
                char_leido = recibir_caracter();
                if ((char_leido == 'I') || (char_leido == 'i')) {
                    mensaje_L();
                    L = 0;
                    estado = 1;
                }
                break;
            case 1: //Se lee longitud
                L = Lectura_Serial(); // En um (micrometros))
                if ((L <= 30000) && (L >= 5000)) { //L == 26350, 15800
                    //print_num(L);
                    mensaje_AWG();
                    AWG = 0;
                    estado = 2;
                }
                break;
            case 2: //Se lee AWG
                AWG = recibir_numero();
                switch (AWG) {
                    case 30:
                        //print_num(AWG);
                        diametro = 255; //um
                        tension = 522; //Valor tabla x2
                        gramo_abajo = (1053 * (tension - 20)) + 8000000;
                        gramo_arriba = (1053 * (tension + 20)) + 8000000;
                        AWG = 0;
                        mensaje_capas();
                        capas = 0;
                        estado = 3;
                        break;
                    case 36:
                        diametro = 127;
                        tension = 130;
                        gramo_abajo = (1053 * (tension - 20)) + 8000000;
                        gramo_arriba = (1053 * (tension + 20)) + 8000000;
                        AWG = 0;
                        mensaje_capas();
                        capas = 0;
                        estado = 3;
                        break;
                    default:
                        break;
                }
                break;
            case 3: //Se lee capas
                capas = recibir_numero();
                if ((capas >= 1) && (capas <= 10)) {
                    //print_num(capas);
                    mensaje_vels();
                    T2PR = T_tmr2(5); //Velocidad lineal: 20mm/s
                    DIR1_SetHigh(); //Low hacia motor 
                    sel_vel = 0;
                    estado = 4;
                }
                break;
            case 4:
                sel_vel = recibir_numero();
                switch (sel_vel) {
                    case 1:
                        //print_num(sel_vel);
                        RPM = 100;
                        TMR2_flag = false;
                        estado = 5;
                        break;
                    case 2:
                        //print_num(sel_vel);
                        RPM = w_ideal;
                        TMR2_flag = false;
                        estado = 5;
                        break;
                    case 3:
                        //print_num(sel_vel);
                        RPM = 500;
                        TMR2_flag = false;
                        estado = 5;
                        break;
                    default:
                        break;
                }
                break;

            case 5:
                if (FC_A_GetValue() == false) {
                    if (TMR2_flag) {
                        STEP1_Toggle();
                        TMR2_flag = false;
                    }
                } else { //Cuando llega a final de carrera
                    n_vueltas = L / diametro;
                    t_capa1 = ((float) n_vueltas / RPM) * 60;
                    t_embo = t_capa1 * capas;
                    send_t(t_capa1, t_embo);
                    mensaje_boton();
                    estado = 6;
                }
                break;
            case 6: //Pulsador para iniciar, calculo de pasos a dar
                if (PULS_GetValue() == true) {
                    T4PR = T_tmr4(RPM);
                    DIR2_SetLow(); //Direccion embobinado
                    pasos_bobina = n_vueltas * 200;
                    pasos_bobina = pasos_bobina * 2;
                    vel_lineal = (RPM * (float) diametro) / 60000;
                    T2PR = T_tmr2(vel_lineal);
                    DIR1_SetLow(); //Direccion hacia motor
                    pasos_lineal = L / 10;
                    pasos_lineal = pasos_lineal * 2;
                    TMR2_flag = false;
                    TMR4_flag = false;
                    n_p_lineal = 0;
                    n_p_bobina = 0;
                    PWM5_LoadDutyValue(pwm);
                    PWM6_LoadDutyValue(pwm);
                    estado = 7;
                }
                break;
            case 7:
                if (TMR4_flag) {
                    STEP2_Toggle();
                    n_p_bobina++;
                    TMR4_flag = false;
                }
                if (TMR2_flag) {
                    STEP1_Toggle();
                    n_p_lineal++;
                    TMR2_flag = false;
                }
                
                PWM5_LoadDutyValue(pwm);
                PWM6_LoadDutyValue(pwm);
                promedio = get_average(10);

                if ((promedio < gramo_abajo) && (clockwise == true))
                {
                    pwm --;
                    if(pwm < 400)
                    {
                        clockwise == false;
                    }
                }else if ((promedio > gramo_arriba) && (clockwise == true))
                {
                    pwm++;
                    if(pwm > 800)
                        pwm = 800;
                }
                
                if ((promedio < gramo_abajo) && (clockwise == false))
                {
                    pwm --;
                    if(pwm < 0)
                    {
                        pwm = 0;
                    }
                }else if ((promedio > gramo_arriba) && (clockwise == false))
                {
                    pwm++;
                    if(pwm > 400)
                        clockwise = true;
                }

                if ((n_p_lineal == pasos_lineal)) { // && (n_p_bobina >= pasos_bobina)
                    mensaje_terminado();
                    pwm = 400;
                    PWM5_LoadDutyValue(pwm);
                    PWM6_LoadDutyValue(pwm);
                    if (capas > 1) {
                        mensaje_capa2();
                        n_p_lineal = 0;
                        n_p_bobina = 0;
                        estado = 8;
                    } else {
                        n_p_lineal = 0;
                        n_p_bobina = 0;
                        estado = 9;
                    }

                }
                break;
            case 8:
                if (PULS_GetValue() == true) {
                    DIR1_Toggle(); //Mueve el motor hacia el otro lado
                    capas--;
                    estado = 7;
                }
                break;
            case 9:
                mensaje_final();
                L = 0;
                AWG = 0;
                capas = 0;
                sel_vel = 0;
                t_capa1 = 0.0;
                pasos_bobina = 0;
                pasos_lineal = 0;
                vel_lineal = 0;
                RPM = w_ideal;
                n_p_lineal = 0;
                n_p_bobina = 0;
                estado = 0;
                break;

        }
    }
}

// ################################### FUNCIONES #################################

void mensaje_L(void) {
    char mensaje[] = "\nLongitud\ten\tum:";
    for (int i = 0; i < sizeof (mensaje); i++) //for para enviar el mensaje caracter por caracter
    {
        if (UART1_is_tx_ready()) {
            UART1_Write(mensaje[i]);
        }
        __delay_ms(10);
    }
}

void mensaje_AWG(void) {
    char mensaje[] = "\nAWG:";
    for (int i = 0; i < sizeof (mensaje); i++) //for para enviar el mensaje caracter por caracter
    {
        if (UART1_is_tx_ready()) {
            UART1_Write(mensaje[i]);
        }
        __delay_ms(10);
    }
}

void mensaje_capas(void) {
    char mensaje[] = "\nCapas:";
    for (int i = 0; i < sizeof (mensaje); i++) //for para enviar el mensaje caracter por caracter
    {
        if (UART1_is_tx_ready()) {
            UART1_Write(mensaje[i]);
        }
        __delay_ms(10);
    }
}

void mensaje_vels(void) {
    char mensaje[] = "\nLento:1\tIdeal:2\tRapido:3";
    for (int i = 0; i < sizeof (mensaje); i++) //for para enviar el mensaje caracter por caracter
    {
        if (UART1_is_tx_ready()) {
            UART1_Write(mensaje[i]);
        }
        __delay_ms(10);
    }
}

void mensaje_terminado(void) {
    char mensaje[] = "\nCapa_terminada";
    for (int i = 0; i < sizeof (mensaje); i++) //for para enviar el mensaje caracter por caracter
    {
        if (UART1_is_tx_ready()) {
            UART1_Write(mensaje[i]);
        }
        __delay_ms(10);
    }
}

void mensaje_capa2(void) {
    char mensaje[] = "\nPulse\tpara\tsiguiente\tcapa";
    for (int i = 0; i < sizeof (mensaje); i++) //for para enviar el mensaje caracter por caracter
    {
        if (UART1_is_tx_ready()) {
            UART1_Write(mensaje[i]);
        }
        __delay_ms(10);
    }
}

void mensaje_final(void) {
    char mensaje[] = "\nPROCESO\tTERMINADO";
    for (int i = 0; i < sizeof (mensaje); i++) //for para enviar el mensaje caracter por caracter
    {
        if (UART1_is_tx_ready()) {
            UART1_Write(mensaje[i]);
        }
        __delay_ms(10);
    }
}

void print_num(int num) {
    char mensaje[6];
    sprintf(mensaje, "%d", num);
    for (int i = 0; i < sizeof (mensaje); i++) //for para enviar el mensaje caracter por caracter
    {
        if (UART1_is_tx_ready()) {
            UART1_Write(mensaje[i]);
        }
        __delay_ms(10);
    }
}

int recibir_numero(void) {
    int numero;
    volatile uint8_t rxData;
    if (UART1_is_rx_ready()) //
    {
        rxData = UART1_Read();
        numero = (int) rxData;
    }
    return numero;
}

int Lectura_Serial(void) {

    int REF_grados = 0;
    int arreglo_bit[6];

    uint8_t rxData;
    // Logic to echo received data
    if (UART1_is_rx_ready()) {
        for (int i = 0; i < 6; i++) {
            rxData = UART1_Read(); // Leer un car�cter del puerto serie
            arreglo_bit[i] = (rxData & 0x0F);
        }
    }
    REF_grados = (arreglo_bit[5] + (10 * arreglo_bit[4]) + (100 * arreglo_bit[3])
            + (1000 * arreglo_bit[2]) + (10000 * arreglo_bit[1]) + (100000 * arreglo_bit[0]));
    return REF_grados;
}

char recibir_caracter(void) {
    volatile uint8_t rxData_buf;
    char caracter;
    if (UART1_is_rx_ready()) //
    {
        rxData_buf = UART1_Read();
        caracter = (char) rxData_buf;
    }
    return caracter;
}

void send_t(float t_capa, float t_total) {
    char aux[] = "\nTiempo\testimado:";
    for (int i = 0; i < sizeof (aux); i++) //for para enviar el mensaje caracter por caracter
    {
        if (UART1_is_tx_ready()) {
            UART1_Write(aux[i]);
        }
        __delay_ms(10);
    }
    char mensaje[5];
    sprintf(mensaje, "%f", t_total);
    for (int i = 0; i < sizeof (mensaje); i++) //for para enviar el mensaje caracter por caracter
    {
        if (UART1_is_tx_ready()) {
            UART1_Write(mensaje[i]);
        }
        __delay_ms(10);
    }
}

void mensaje_boton(void) {
    char mensaje[] = "\nPulse\tpara\tiniciar";
    for (int i = 0; i < sizeof (mensaje); i++) //for para enviar el mensaje caracter por caracter
    {
        if (UART1_is_tx_ready()) {
            UART1_Write(mensaje[i]);
        }
        __delay_ms(10);
    }
}

int T_tmr2(float mm_s) {
    float v_registro, periodo_tmr;
    float periodo, frecuencia;
    v_registro = 0;
    frecuencia = 0;
    periodo_tmr = 0;

    frecuencia = mm_s * 100; //Paso de mm/s a Hz
    periodo = (1 / frecuencia) * 1000000; //De Hz a us
    periodo_tmr = periodo / 2;
    v_registro = (periodo_tmr * 255) / 14336;
    //v_registro = 255 - ((5120 - periodo_tmr) / 20); //Valor que debe tener el registro que controla periodo del timmer
    return (int) v_registro;
}

int T_tmr4(int rpm) {
    float v_registro, periodo_tmr;
    float periodo, frecuencia;
    v_registro = 0;
    frecuencia = 0;
    periodo_tmr = 0;
    periodo = 0;

    frecuencia = (float) rpm * (10 / 3); //Paso de rpm a Hz
    periodo = (1 / frecuencia) * 1000000; //De Hz a us
    periodo_tmr = periodo / 2;
    v_registro = (periodo_tmr * 255) / 3072;
    //v_registro = 255 - ((5120 - periodo_tmr) / 20); //Valor que debe tener el registro que controla periodo del timmer
    return (int) v_registro;
}

uint32_t hx711_read() {
    int8_t i;
    uint32_t data = 0;

    SCK_SetLow();
    __delay_us(1);
    while (DOUT_GetValue() == 1);
    for (i = 0; i < 24; i++) {
        SCK_SetHigh();
        data = data << 1;
        __delay_us(1);
        SCK_SetLow();
        __delay_us(1);
        if (DOUT_GetValue())
            data++;
    }

    for (i = 0; i < GAIN; i++) {
        SCK_SetHigh();
        __delay_us(1);
        SCK_SetLow();
        __delay_us(1);
    }
    data = data ^ 0x800000;
    return (data);
}

void set_gain(int gain1) {
    switch (gain1) {
        case 128: // channel A, gain factor 128
            GAIN = 1;
            break;
        case 64: // channel A, gain factor 64
            GAIN = 3;
            break;
        case 32: // channel B, gain factor 32
            GAIN = 2;
            break;
    }

    SCK_SetLow();
    hx711_read();
}

void init_hx(int gain1) {
    SCK_SetLow(); //Output
    //DOUT_SetHigh(); //Input
    set_gain(gain1);
}

int32_t get_average(int times) {
    uint32_t sum = 0;
    for (int i = 0; i < times; i++) {
        sum = sum + hx711_read();
        //delay_ms(1);
    }
    return (sum / times);
}

/**
 End of File
 */