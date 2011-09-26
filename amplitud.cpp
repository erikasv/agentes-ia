#include "amplitud.h"

Amplitud::Amplitud(bool *dirIn) : Algoritmos(dirIn)
{
    direcciones= new bool[7]; //true para vertical, false para horizontal
    for(int i=0; i<7; i++) direcciones[i]=dirIn[i];
}

string Amplitud::buscarSolucion(Nodo *estadoInicial)
{
    Nodo *actual=estadoInicial;
    set.insert(QString::fromStdString(actual->getEstadoString()));
    QQueue<Nodo*> *miCola= new QQueue<Nodo*>();
    list<Nodo*> *listaTmp=new list<Nodo*>();

    listaTmp =expandir(actual);
    while(listaTmp!=0)
    {
        while(!listaTmp->empty())
        {
//            if(!(listaTmp->front()->esIgualA(actual->getPadre())))
            if(!set.contains(QString::fromStdString(listaTmp->front()->getEstadoString())))
            {
                miCola->enqueue(listaTmp->front());
                set.insert(QString::fromStdString(listaTmp->front()->getEstadoString()));
            }
            listaTmp->pop_front();
        }
        actual=miCola->dequeue();
        cout<<miCola->size()<<endl;
        listaTmp=0;
        listaTmp =expandir(actual);
    }

    return actual->getOperadorAplicado();
}
//int main(){
//    Amplitud *ensayo;

//    char** prueba=new char*[7];
//    char** resPrueba=new char*[7];
//    for (int var = 0; var < 7; var++) {
//        prueba[var]=new char[7];
//        resPrueba[var]=new char[7];
//    }
////    prueba[0][0]='E';prueba[0][1]='E';prueba[0][2]='E';prueba[0][3]='0';prueba[0][4]='1';prueba[0][5]='1';prueba[0][6]='1';
////    prueba[1][0]='0';prueba[1][1]='0';prueba[1][2]='0';prueba[1][3]='0';prueba[1][4]='0';prueba[1][5]='1';prueba[1][6]='0';
////    prueba[2][0]='A';prueba[2][1]='A';prueba[2][2]='C';prueba[2][3]='0';prueba[2][4]='0';prueba[2][5]='0';prueba[2][6]='D';
////    prueba[3][0]='1';prueba[3][1]='0';prueba[3][2]='C';prueba[3][3]='0';prueba[3][4]='0';prueba[3][5]='0';prueba[3][6]='D';
////    prueba[4][0]='F';prueba[4][1]='1';prueba[4][2]='G';prueba[4][3]='G';prueba[4][4]='G';prueba[4][5]='B';prueba[4][6]='0';
////    prueba[5][0]='F';prueba[5][1]='0';prueba[5][2]='0';prueba[5][3]='0';prueba[5][4]='0';prueba[5][5]='B';prueba[5][6]='1';
////    prueba[6][0]='F';prueba[6][1]='0';prueba[6][2]='0';prueba[6][3]='1';prueba[6][4]='0';prueba[6][5]='1';prueba[6][6]='1';
//    prueba[0][0]='E';prueba[0][1]='E';prueba[0][2]='E';prueba[0][3]='0';prueba[0][4]='0';prueba[0][5]='0';prueba[0][6]='1';
//    prueba[1][0]='0';prueba[1][1]='0';prueba[1][2]='0';prueba[1][3]='0';prueba[1][4]='0';prueba[1][5]='0';prueba[1][6]='0';
//    prueba[2][0]='A';prueba[2][1]='A';prueba[2][2]='C';prueba[2][3]='0';prueba[2][4]='0';prueba[2][5]='0';prueba[2][6]='D';
//    prueba[3][0]='0';prueba[3][1]='0';prueba[3][2]='C';prueba[3][3]='0';prueba[3][4]='0';prueba[3][5]='0';prueba[3][6]='D';
//    prueba[4][0]='F';prueba[4][1]='0';prueba[4][2]='G';prueba[4][3]='G';prueba[4][4]='G';prueba[4][5]='B';prueba[4][6]='0';
//    prueba[5][0]='F';prueba[5][1]='0';prueba[5][2]='0';prueba[5][3]='0';prueba[5][4]='0';prueba[5][5]='B';prueba[5][6]='0';
//    prueba[6][0]='F';prueba[6][1]='0';prueba[6][2]='0';prueba[6][3]='1';prueba[6][4]='0';prueba[6][5]='0';prueba[6][6]='0';

//    bool *pruebaDir=new bool[6];
//    pruebaDir[0]=false;
//    pruebaDir[1]=true;
//    pruebaDir[2]=true;
//    pruebaDir[3]=true;
//    pruebaDir[4]=false;
//    pruebaDir[5]=true;
//    pruebaDir[6]=false;

//    Nodo *inicio= new Nodo(prueba, 0, "", 0, 0);
//    ensayo=new Amplitud(pruebaDir);
//    string sol=ensayo->buscarSolucion(inicio);
//    cout << sol << endl;
////    list<Nodo*>* miLista=ensayo->expandir(inicio);
////    while(!miLista->empty()){
////        ensayo->imprimir(miLista->front()->getEstado());
////        miLista->pop_front();
////        cout<<endl;
////    }
//}
