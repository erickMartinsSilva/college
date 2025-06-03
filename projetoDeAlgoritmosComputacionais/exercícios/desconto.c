// O programa, com base em algumas condições, exibe o valor total das compras de um usuário e o desconto sobre elas

#include <stdio.h>

int main()
{
    float vt, desc, vf;
    printf("Insira o valor total de suas compras: ");
    scanf ("%f", &vt);
    if (vt >= 200 && vt < 400) 
    {
        desc = vt * 0.1;
    }
    else if (vt >= 400 && vt < 600) 
    {
        desc = vt * 0.15;
    }
    else if (vt >= 600) 
    {
        desc = vt * 0.2;
    }
    else
    {
        desc = 0;
    }
    printf("Desconto: %.2f\n", desc);
    vf = vt - desc;
    printf("Total a ser pago: %.2f", vf);
    return 0;
}
