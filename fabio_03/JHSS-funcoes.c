#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>


float velocidade_km_p_m(float vel_m_por_seg){
    float vel_km_por_h;
    vel_km_por_h = (vel_m_por_seg) * 3.6;

    return vel_km_por_h;
}


int tempo_em_minutos(int hora, int minutos){
    int minutos_total;
    minutos_total = (hora*60) + minutos;

    return minutos_total;

}


float dolar_para_real(float valorDolar, float valor_em_dolar){
    float valor_em_real;
    valor_em_real = valorDolar * valor_em_dolar;

    return valor_em_real;
}


float velocidade_metro_p_segundo(float vel_km_por_h){
    float vel_m_por_seg;
    vel_m_por_seg = (vel_km_por_h) / 3.6;

    return vel_m_por_seg;
}


int area_triangulo(int altura, int base){
    int area;
    area = (base*altura) / 2;

    return area;
}


int area_quadrado(int lado){
    return pow(lado, 2);
}


int area_retangulo(int base, int altura){
    return (base*altura);
}


float comprimento_circunferencia(float raio){
    float comprimento;
    comprimento = 2 * (3.14) * raio;
    
    return comprimento;
}


float volume_circunferencia(float raio){
    float volume;
    volume = (4*(3.14)*(pow(raio, 3)))/3;

    return volume;
}


int temperatura_fahrenheit(int temp_C){
    int temp_F;
    temp_F = ((9*temp_C) + 160) / 5;

    return temp_F;
}


int temperatura_celsius(int temp_F){
    int temp_C;
    temp_C = ((5*temp_F) - 160) / 9;

    return temp_C;
}


int calcula_fatorial(int numero){
    int fat;
    for (fat = 1; numero > 1; numero--){
        fat *= numero;
    }

    return fat;
}


bool verifica_primo(int numero){
    if ((numero!=0) && (numero!=1)){
        if (numero ==2){
            return true;
        }
        else if (numero >= 3){
            for (int i=2;i<=(numero/2); i++){
                if (numero % i == 0){
                    return false;
                }
            }
        }
    }
    else{
        return false;
    }
}


bool valida_data(int dia, int mes, int ano){
    if((dia>0 && dia<=31) && (mes>0 && mes<=12) && (ano<=2019)){
        if ((dia<=31) && (mes==1||mes==3||mes==5|| \
        mes==7||mes==8||mes==10||mes==12)){
            return true;
        }
        else if ((dia<=30) && (mes==4||mes==6||mes==9||mes==11)){
            return true;
        }
        else if(dia<=28 && mes==2){
            return true;
        }
        // ANO BISSEXTO
        else if((dia==29) && (mes==2) && ((ano%4==0) && (ano%400==0 || ano%100!=0))){
            return true;
        }
        else{
            return true;
        }
    }
}


bool valida_ano_bissexto(int ano){
    if ((ano%4==0) && (ano%400==0 || ano%100!=0)){
        return true;
    }
    else{
        return false;
    }
}
