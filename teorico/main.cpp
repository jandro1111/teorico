#include "lib.h"
using namespace std;
int main(int argc, char* argv[]) {//correr como teorico.exe desde el windows powershel
    string archivo,text,linea, encriptext, desencript;
    int clave=0;
    int option=0;
    srand(time(NULL));
    cout << "1 para encriptar, 2 para desencriptar, 3 para test" << endl;
    while (option < 1 || option>3) {
        cin >> option;
        if (option < 1 || option>3) {
            cout << "opcion invalida" << endl;
        }
    }
    switch (option)
    {
    case 1:
        cout << "ingrese la clave numerica con la que va a desbolquear el archivo despues" << endl;
        cin >> clave;       
        break;
    case 2:
        cout << "ingrese la clave para desbloquear el archivo" << endl;
        cin >> clave;
        break;
    default:
        break;
    }
    aes prueba1(clave);
    aes prueba;
    ifstream doc;
    ofstream doce;
    switch (option)//despues le voy a agregar mas opciones
    {
    case 1:
        cout << "ingrese el nombre del archivo a encriptar" << endl;
        cin >> archivo;
        doc.open(archivo.c_str(), ios::binary);
        if (doc.is_open()) {
            while (getline(doc, linea)) {
                text += linea;
            }
            encriptext = prueba1.aesencrypt(text);
            doc.close();//termine de leer
            doce.open(archivo.c_str(), ios::binary | ios::trunc);//lo abro devuelta en binario y borro lo que tenia para guardar su version encriptada
            doce << encriptext;
            doce.close();
        }
        else {
            cout << "no se pudo abrir el archivo" << endl;
        }
        break;
    case 2:
        try {
            cout << "ingrese el nombre del archivo a desencriptar" << endl;
            cin >> archivo;
            doc.open(archivo.c_str(), ios::binary);
            if (doc.is_open()) {
                while (getline(doc, linea)) {
                    text += linea;
                }
                doc.close();//termine de leer             
                text = prueba1.aesdecrypt(text);//encriptext
                doce.open(archivo.c_str(), ios::binary | ios::trunc);//lo abro devuelta en binario y borro lo que tenia para guardar su version encriptada
                doce << text;
                doce.close();
            }
            else {
                cout << "no se pudo abrir el archivo" << endl;
            }
        }
        catch (std::exception& e)
        {
            std::cout << "error desencriptando el archivo" << endl;
            std::cerr << e.what() << std::endl;
        }
        break;
    case 3:
        cout << "ingrese texto a encriptar" << endl;
        cin >> text;
        encriptext = prueba.aesencrypt(text);
        prueba.aesdecrypt(encriptext);//encriptext
        break;
    default:
        break;
    }
    
    return 0;
}
