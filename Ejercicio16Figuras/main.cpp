#include <iostream>

using namespace std;

class Figuras{
    protected:
float perimetro;
float area;
public:
    Figuras(){
        perimetro=0;
        area=0;
    }
    Figuras(float perimetro1,float area1, int CantLados1){
        perimetro=perimetro1;
        area=area1;
    }
    void poneDatos(float perimetro1,float area1, int CantLados1){
        perimetro=perimetro1;
        area=area1;
    }
    void MostrarDatos(){
        cout<<"Perimetro: "<<perimetro<<" Area: "<< area<<endl;
    }
    float obtienePerimetro(){
        return perimetro;
    }
};

class Rectangulo: public Figuras{
    float lado1;
    float lado2;
public:
    Rectangulo(float ladoA, float ladoB){
        lado1=ladoA;
        lado2=ladoB;
        perimetro=lado1*2+lado2*2;
        area=lado1*lado2;
    }
    float Calculaperimetro(){
        perimetro=lado1*2+lado2*2;
        return perimetro;
    }
    float CalculaArea(){
        area=lado1*lado2;
        return area;
    }
    void ponedatos(float ladoA, float ladoB){
        lado1=ladoA;
        lado2=ladoB;
    }
};

class TrianguloRectangulo : public Figuras{
    float base;
    float altura;
    float lado3;
public:
    TrianguloRectangulo(float base1, float altura1, float _lado3){
        base=base1;
        altura=altura1;
        lado3=_lado3;
        perimetro=base+lado3+altura;
        area=(base*altura)/2;
    }
    float Calculaperimetro(){
        perimetro=base+lado3+altura;
        return perimetro;
    }
    float CalculaArea(){
        area=(base*altura)/2;
        return area;
    }
    void ponedatos(float ladoA, float ladoB,float ladoC){
        base=ladoA;
        altura=ladoB;
        lado3=ladoC;
    }
};

class Geometrica{
    Figuras *Pila[10];
    int i;
public:
    Geometrica(){
        i=0;
    }
    void ponep(Figuras* elem){
        if (i<10){
            Pila[i]= elem;
            i++;
        }
        else
            cout<<"La pila esta llena"<<endl;
    }
     void sacap(Figuras *elem){
        if (i>0){
            elem=Pila[i];
            delete Pila[i];
            i--;
        }
        else
            cout<<"La pila esta vacía"<<endl;
    }
    void muestrap(){
        Pila[i]->MostrarDatos();
    }
};

int main()
{
    int k,i,tipo;
    Figuras *Objeto1;
    Geometrica obje;
    Rectangulo *Tipo1;
    TrianguloRectangulo *Tipo2;
    float lado1,lado2,lado3,base,altura;
    cout << "Ingrese k: " << endl;
    scanf("%d",&k);
    for(i=0;i<3;i++){
        cout <<"Ingrese el tipo de objeto que quiere ingresar: "<<endl;
        scanf("%d",&tipo);
        if (tipo==1){
            cout<<"Ingrese los dos lados del rectangulo: "<<endl;
            scanf("%f %f",&lado1,&lado2);
            Tipo1= new Rectangulo(lado1,lado2);
            obje.ponep(Tipo1);
        }
        else if (tipo==2){
            cout<<"Ingrese la base, la altura y el tercer lado: "<<endl;
            scanf("%f %f %f",&base,&altura,&lado3);
            Tipo2= new TrianguloRectangulo(base,altura,lado3);
            obje.ponep(Tipo2);
        }
    }
    for(i=0;i<k;i++){
            obje.sacap(Objeto1);
            cout<< "El perimetro: " << Objeto1->obtienePerimetro()<<endl;
        }
    return 0;
}
