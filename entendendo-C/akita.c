#include <stdio.h>

int main() {
    char hello[] = "Hello World"; //cadeia de character = string
    printf("%s\n", hello); //Instruções para mostrar na tela
    return 0;
}

//String são como barbante, uma corda ou um fio 
//Forma mais simples de string é uma cadeia de bytes terminada com \0(nulo)
//Se encodarmos usando o "Hello World\0" em UTF-8 cada letra será representado pelo um codigo de 8 Bits que é 1 Byte então o "Hello World\0" tem 11 Bytes de tamanho mais o \0 no final.
//Mas é se for em japonés "ハローワールド\0" que é uma string de 7 simbolos em katakana e vai ocupar 3 Bytes dando no total 21 Bytes mais o \0.
//Cada byte que 1 character ocupa depende da tabela de conversão entre glifos e caracteres esse é o encoding.
//Uma string com caracteres ocidentais de 8 bits é igual a um Array de Bytes



//Array em ingles e tipo uma serie ou conjunto de coisas, uma lista sequencial com cada elemento do array um atrás do outro na memoria sem buracos no meio


//Em algumas liguagens averá 2 palavras distintas um "byte" e um "char" se um char for um ascii de 8 bits então é a mesma coisa que 1 byte na prática como é em C, porém, em C# ou Java cada char representa um caractere UTF-16 que cotém 16 bits ou 2 Bytes portanto é um double byte; não se pode achar que um char e sempre 1 pra 1 com 1 Byte somente quando falamos de C.

//Cada linguagem possui um certo numero oque chamamos de tipos primitivos um char é um exemplo de primitivo que é um pequeno pacote de bits sem metadados outro exemplo são numeros, no mundo real estamos acostumados a pensar em numeros inteiros que seria 0, 1, 2, 3...infinito; e 0, -1, -2, -3...infinito; porém em computadores os numeros são limitados pelos seus tipos é temos diversos tipos de inteiros
//Na maioria das linguagens nos costuma lidar com inteiros de 8, 16, 32 e 64 bits respectivamente int8, int16, int32 e int64
//Em rust é exatamente assim que é dividido e eles são chamados de i8, i16, i32, i64 e até i128
//Um int8 é basicamente um Byte ou um char de C
//No caso de C# um int16 é chamado de Short, um int32 é Integer, no caso de int64 é chamado de Long.
//No caso do C é mais complicado porque um int dependia da arquitetura do cpu int em um pc de 16 bits era int16 mais em um pc de 32 bits se vc recompilasse o codigo no mesmo programa o int passava a ser 32 bits.
//A primeira vista parece uma boa ideia porque toda vez que o cpu's evoluem bastaria recompilar o programa e ele automaticamente teria acesso a mais memoria mas na pratica isso pode levar a diversos bugs inesperados, entao, quem decide o tamanhos dos inteiros de C e o compilador, mas nas liguagens mais modernas como C# e Rust a declaração fica mais explicita quando qual tipo de inteiro vc ta usando.
//A razão para ter diferentes tipos de inteiros é a eficiencia, se vc sabe que no seu programa não irá precisar de numeros maiores que 255 basta alocar um int8 ou 1 Byte que será o surficiente se você colocar um int64 vai disperdiçar 8 bytes que não irão servir para nada, se for uma variavel só não faz diferença, mas se for um array com milhares ou milhoes de elementos vc vai rapidamente disperdiçar megabytes ou até gigabytes de memoria atoa.
//Numeros inteiros te outra caracteristica importante eles podem ser Signed ou Unsigned, se declarar um Unsigned int (0 a 255) pode ser usado para numeros de 0 a hexa ff; mas se fosse Signed int (-127 a 128) quase a metade nesse caso o primeiro bit que é chamado de "bit mais significativo" e costuma ficar a esquerda dependendo do engeners da cpu é onde vai ficar o sinal se o primeiro bit for 0 então é positivo se for 1 então é negativo ex: -127 = 1000 0001.

// PESQUISE INTEIROS NEGATIVOS DPS

//Vamos dizer o seguinte para subtrair dois numeros com sinal como 15 e 5, o pc primeiro vai enxergar eles como binario, em 8 bits em binario no caso de 15 = 0000 1111 - 5 = 0000 0101; computadores usam oque chamamos de metodo de comprimento que é a ideia de fazermos uma subtração virar umma soma e usar o mesmo circuito de soma, para fazer isso ele transforma o segundo numero no seu complemento de 2 ou Two's Complement, pra achar esse complemento é simples basta flipar todos os bits e somar 1 então o numero 5 que é 0000 0101 vai ficar -5 1111 1010+1 que fica -5 1111 1011 o porque de ter esse 1 no final e o morivo para vc estudar a teoria completa de Two's Complement.

//Vamos somar o 15 com o -5
//    11111 111
//15 = 0000 1111
//-5 = 1111 1011+
//     0000 1010

//o 1 que sobrou e descartado e como o primeiro bit e 0 o numero é positivo e depois 1010 que é (8+2) que dá 10 que é o resultado de 15-5

//E com isso demonstramos que é possivel subtrair numeros inteiros com o sinal usando o metodo de complementos e usando o mesmo circuito da maquina de somar binario.
//As cpu's são feitas para tirarem vantagem de base 2 em vez de base 10 para conseguir calcular de forma mais eficiente doque fazermos com numeros decimais, multiplicar e dividir e mais complicado e se tiver interesse estudo o algoritmo de multiplicação de Booth's Multiplication.