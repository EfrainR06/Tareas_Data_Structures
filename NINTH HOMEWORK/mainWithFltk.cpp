//Efrain Retana Segura UNA

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include "TorreHanoi.h"
//Ejemplo pedido en clase

const int NUM_DISK = 4;
Pila towers[3];

void drawTowers(int x, int y, int w, int h) {
    int diskHeight = 20;
    for (int t = 0; t < 3; ++t) {
        fl_color(FL_BLACK);
        fl_rectf(x + t * w, y, 10, h);

        int posY = y + h - diskHeight;
        int n = towers[t].size();

        // FIX: Draw from base (0) to top (n-1)
        for (int i = 0; i < n; ++i) {
            int disk = towers[t].get(i);
            int diskWidth = 20 + disk * 20;
            fl_color(FL_BLUE + disk);
            fl_rectf(x + t * w - diskWidth / 2 + 5, posY, diskWidth, diskHeight);
            posY -= diskHeight;
        }
    }
}
class HanoiWindow : public Fl_Window {
public:
    HanoiWindow(int W, int H) : Fl_Window(W, H, "Torres de Hanoi") {
        for (int i = NUM_DISK; i >= 1; --i)
            towers[0].meter(i);
        end();
    }

    void draw() override {
        Fl_Window::draw();
        drawTowers(80,50, 120,200);
    }

    void SolveHanoi(int n, int from, int to, int aux) {
        if (n == 0) return;
        SolveHanoi(n -1, from, aux, to);
        towers[to].meter(towers[from].sacar());
        redraw();
        Fl::check();
        Fl::wait(4);
        SolveHanoi(n -1, aux,to, from);
    }
};
int main() {
    HanoiWindow win(400, 300);
    win.show();
    Fl::wait(1.0);
    win.SolveHanoi(NUM_DISK, 0, 2, 1);
    return  Fl::run();

}

