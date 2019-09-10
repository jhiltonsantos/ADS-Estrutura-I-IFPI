#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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




