//Efrain Retana Segura UNA

#ifndef RECTA_H
#define RECTA_H

struct Recta {
    float A;
    float B;
    float C;
};

Recta* crear_recta(float A,float B, float C);
float pendiente_recta(const Recta* r);
bool punto_en_recta(const Recta* r, float x, float y);



#endif //RECTA_H
