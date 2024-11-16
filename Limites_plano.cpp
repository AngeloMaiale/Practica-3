#include <iostream>
#include <cmath>
using namespace std;
struct Punto {
    float x;
    float y;
};

int main() {

    int n=0; 
    int xmin,xmax,ymin,ymax;

    cout<<"Xmax: ";
    cin>>xmax;
    cout<<"Xmin: ";
    cin>>xmin;
    cout<<"Ymax: ";
    cin>>ymax;
    cout<<"Ymin: ";
    cin>>ymin;
    cout<<"Ingrese la cantidad de puntos que desea analizar: ";
    cin>>n;
    Punto puntos[n];
    for (int i=0; i<n; i++) {
        bool RV = false;
        while (!RV) {
            float xi=0;
            float yi=0;
            cout<<"Ingrese el punto "<<i+1<<" en x: ";
            cin>>xi;
            cout<<"Ingrese el punto "<<i+1<<" en y: ";
            cin>>yi;
            if (xi>=xmin && xi<=xmax && yi>=ymin && yi<=ymax) {
                RV = true;
                puntos[i].x=xi;
                puntos[i].y=yi;
            } else {
                cout<<"El punto ingresado se encuentra fuera de los limites del plano." << endl;
            }
        }
    }
    double distanciaMaxima = 0;
    Punto punto1,punto2;
    for (int i = 0; i < n; ++i) {
        if (puntos[i].x<xmin || puntos[i].x>xmax || puntos[i].y<ymin || puntos[i].y>ymax) {
            continue;
        }
        for (int j=i+1; j<n; ++j) {
            if (puntos[j].x<xmin || puntos[j].x>xmax || puntos[j].y<ymin || puntos[j].y>ymax) {
                continue;
            }
            double distancia=sqrt((puntos[j].x-puntos[i].x)*(puntos[j].x-puntos[i].x)+(puntos[j].y-puntos[i].y)* (puntos[j].y-puntos[i].y));
            if (distancia>distanciaMaxima) {
                distanciaMaxima=distancia;
                punto1=puntos[i];
                punto2=puntos[j];
            }
        }
    }

    cout<<"La distancia maxima entre dos puntos dentro del plano es: "<<distanciaMaxima<<endl;
    cout<<"Entre los puntos ("<<punto1.x<<", "<<punto1.y<<") y ("<< punto2.x <<", "<< punto2.y <<")."<<endl;

    
    int indicePunto;
    cout<<"Ingrese el indice del punto para calcular distancias: ";
    cin>>indicePunto;
    indicePunto--;

    if (indicePunto>=0 && indicePunto<n) {
        if (puntos[indicePunto].x>=xmin && puntos[indicePunto].x<=xmax && puntos[indicePunto].y>=ymin && puntos[indicePunto].y<=ymax) {
            cout<<"Distancias desde el punto ("<<puntos[indicePunto].x<<", "<<puntos[indicePunto].y <<"):"<<endl;
            for (int i=0; i<n; ++i) {
                if (i==indicePunto) continue;
                if (puntos[i].x>=xmin && puntos[i].x<=xmax && puntos[i].y>=ymin && puntos[i].y<=ymax) {
                    double distancia=sqrt((puntos[i].x-puntos[indicePunto].x)*(puntos[i].x-puntos[indicePunto].x)+(puntos[i].y-puntos[indicePunto].y)*(puntos[i].y-puntos[indicePunto].y));
                    cout<<"("<<puntos[i].x<<","<<puntos[i].y<<"):"<<distancia<<endl;
                }
            }
        } else {
            cout<<"El punto especificado no está dentro del cuadrante."<<endl;
        }
    } else {
        cout<<"Indice de punto fuera de rango."<<endl;
    }

    return 0;
}
