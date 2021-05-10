#include"lib.h"
int randprimos(void) {
    int contador, n;
    printf("\n");
    bool primo = false;
    contador = 2;
    for (n = (rand() % MAXNUM + 1); primo == false; n = (rand() % MAXNUM + 1)) {
        primo = true;
        contador = 2;
        while (contador <= n / 2 && primo)
        {
            if (n % contador == 0) {
                primo = false;
                break;
            }
            contador++;
        }
        if (primo == true) {
            return n;
        }
    }
}
void rsaencrypt(std::string) {

}