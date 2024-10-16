#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arrayFixo() {

    printf("Primeiramente para criar um texto como variavel e necessario ele ter o tipo CHAR e ser feito como array já que tipo CHAR só suporta um unico caracter.\n");
    printf("Primeira forma de fazer isso é definir um array com caracteres definidos. Por exemplo, meu nome 'José Augusto' tem 11 letras, mas ocupa 12 posições no array por causa do espaço. Além disso, o array deve ter 13 posições para o caractere nulo '\\0', que marca o fim da string. Se usamos 'fgets()', o array precisa de mais 1 posição para o caractere de nova linha '\\n', totalizando 14 posições.\n");


    char number_name[14];
    printf("Digite meu nome \"José Augusto\" no array:\n");

    fgets(number_name, sizeof(number_name), stdin);

    printf("Meu nome é %s\n", number_name);
}

void arrayDinamico() {
    char texto = 'A';
    char *string;

    string = &texto;

    printf("Valor da variável texto: %c\n", texto);
    printf("Endereço de texto: %p\n", texto);
}

int main() {
    arrayDinamico();
    return 0;
}
