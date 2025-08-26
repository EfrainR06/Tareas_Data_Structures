//Efrain Retana Segura UNA

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include "TorreHanoi.h"
// Ejemplo pedido en clase

const int NUM_DISK = 4;
Pila towers[3];

// Dibuja las tres torres y los discos en la ventana
void drawTowers(int x, int y, int w, int h) {
    int diskHeight = 20;
    for (int t = 0; t < 3; ++t) {
        fl_color(FL_BLACK);
        fl_rectf(x + t * w, y, 10, h);

        int posY = y + h - diskHeight;
        int n = towers[t].size();

        // Dibuja los discos desde la base hasta la cima
        for (int i = 0; i < n; ++i) {
            int disk = towers[t].get(i);
            int diskWidth = 20 + disk * 20;
            fl_color(FL_BLUE + disk);
            fl_rectf(x + t * w - diskWidth / 2 + 5, posY, diskWidth, diskHeight);
            posY -= diskHeight;
        }
    }
}

// Ventana principal para mostrar las Torres de Hanoi
class HanoiWindow : public Fl_Window {
public:
    // Constructor: inicializa la torre con los discos en la primera pila
    HanoiWindow(int W, int H) : Fl_Window(W, H, "Torres de Hanoi") {
        for (int i = NUM_DISK; i >= 1; --i)
            towers[0].meter(i);
        end();
    }

    // Dibuja la ventana y las torres
    void draw() override {
        Fl_Window::draw();
        drawTowers(80,50, 120,200);
    }

    // Resuelve el problema de las Torres de Hanoi de forma recursiva y visualiza cada paso
    void SolveHanoi(int n, int from, int to, int aux) {
        if (n == 0) return;
        SolveHanoi(n -1, from, aux, to);
        towers[to].meter(towers[from].sacar());
        redraw(); // Actualiza la ventana
        Fl::check();
        Fl::wait(4); // Espera para mostrar el movimiento
        SolveHanoi(n -1, aux,to, from);
    }
};

int main() {
    // Crea la ventana principal y muestra la configuración inicial
    HanoiWindow win(400, 300);
    win.show();
    Fl::wait(1.0); // Espera antes de iniciar la solución

    // Inicia la resolución visual de las Torres de Hanoi
    win.SolveHanoi(NUM_DISK, 0, 2, 1);

    // Ejecuta el bucle principal de FLTK
    return  Fl::run();
}