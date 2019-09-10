#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


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


float velocidade_km_p_m(float vel_km_por_h){
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
    return (lado*lado);
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
    volume = (4*(3.14)*(pow(raio, 3)))/3

    return volume;
}

