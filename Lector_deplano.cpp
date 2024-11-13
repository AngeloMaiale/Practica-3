#include<iostream>
using namespace std;

struct Coords{
    float x;
    float y;
};

int main(){
    int Cc=0;
    cout<<"Ingrese la cantidad de coordenadas a analizar: ";
    cin>>Cc;
    Coords puntos[Cc];
    for (int i=0; i<Cc;i++){
        cout<<"Ingrese la coordenada numero "<<i+1<<" en X: ";
        cin>>puntos[i].x;
        cout<<"Ingrese la coordenada numero "<<i+1<<" en Y: ";
        cin>>puntos[i].y;
    };
    for (int i=0; i<Cc;i++){

    if(puntos[i].x>0 && puntos[i].y>0){
        cout<<"La coordenada "<<i+1<<" se encuentra en el cuadrante 1"<<endl;
    }
    else if(puntos[i].x<0 && puntos[i].y>0){
        cout<<"La coordenada "<<i+1<<" se encuentra en el cuadrante 2"<<endl;
    }
    else if(puntos[i].x<0 && puntos[i].y<0){
        cout<<"La coordenada "<<i+1<<" se encuentra en el cuadrante 3"<<endl;
    }
    else if(puntos[i].x>0 && puntos[i].y<0){
        cout<<"La coordenada "<<i+1<<" se encuentra en el cuadrante 4"<<endl;
    }
    else if(puntos[i].x==0 && puntos[i].y==0){
        cout<<"La coordenada "<<i+1<<" se encuentra en el punto de origen"<<endl;
    }
    else {
        cout<<"La coordenada "<<i+1<<" no se encuentra en un solo cuadrante o no es valida"<<endl;
    }
    }
    for(int i=0; i<Cc; i++){
        float t=puntos[i].x+1;
        if(puntos[i].y==t){
            cout<<"La coordenada ("<<puntos[i].x<<","<<puntos[i].y<<") pertenece a la ecuacion f(x)=x+1"<<endl;
        }
        else if(puntos[i].y!=t){
            cout<<"La coordenada ("<<puntos[i].x<<","<<puntos[i].y<<") no pertenece a la ecuacion f(x)=x+1"<<endl;
        }
        else {
            cout<<"La coordenada ("<<puntos[i].x<<","<<puntos[i].y<<") no es valida"<<endl;
        }
    }
return 0;
}
