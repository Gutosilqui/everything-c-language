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


//Em algumas liguagens averá 2 palavraas distintas um "byte" e um "char" se um char for um ascii de 8 bits então é a mesma coisa que 1 byte na prática como é em C, porém, em C# ou Java cada char representa um caractere UTF-16 que cotém 16 bits ou 2 Bytes portanto é um double byte; não se pode achar que um char e sempre 1 pra 1 com 1 Byte somente quando falamos de C.

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
//Tudo isso foi para mostrar a diferença de inteiros com sinal e sem-sinal.

//Dentro da CPU existem varios registraddores que e como se fossem variaveis globais fixas no hardware.
//No Nintendo tinha os registradores A, X, Y e outros, toddos de 8 bits e quando falamos de um Intel ou um AMD moderno estamos falando de registradores é funçoes de 64 bits, mas e quando precisamos fazer conta com numeros acima dos Hexabytes que os 64 bits possam comportar, isso não é incomum principalmente no mundo de BigData e DataScience. Para isso existe tipos compostos como o bigInteger que tecnicamente não tem limites.
//Se você tentar colocar um numero de 128 bits em um registrador de 64 bits vai dar overflow, daí esse numero seria truncado e metade seria perdido, em vez disso, alocamos memoria na RAM pra guardar esse número e, a grosso modo, fazemos a soma com a primeira metade e depois com a segunda metade, e concatenamos o resultado.
//E possivel fazer soma com numero grande como duas somas de numeros menores basta carregar o carry bit para segunda soma.
//Então precisaria de pelo menos duas instruções de adição numa maquina de 64 bits pra somar 2 bigInteger de 128 bits, mas é possivel, so irá custar duas vezes mais caros doque somar numeros menores de 64 bits, tudo em computação tem um custo não é automatico nem tudo igual.
//Todos esse nomes que parecem complicados são apenas convenções de representar numeros inteiros decimais em formato binarios, com limites que vão de oito a 64 bits depedendo da arquitetura nativa da CPU, ou mais se usarmos abstrações como bigInteger.
//E com esses numeros podemos fazer praticamente tudo que precisamos, pense que as gerações de 8 e 16 bits foi baseada inteira em numeros inteiros.
//Todo joguinho de nintendo até mega drive é feito usando numeros inteiros.

//A tela de um jogo tem 320 colunas x 240 linhas de resolução, que é um numero inteiros, um sprite de nintendinho tem 8x8 pixels ou 8x18 pixels para mover um sprite de lugar basta somar de 1 em 1 pixel, os sprites podem escolher entre paletas de 4 cores dentre 54 disponiveis, pontuações de jogos, quantidade de vidas, numeros de fases é tudo numeros inteiros.
//E fora dos games em aplicativos de produtividade seja planilhas, processadores de texto tudo é baseado em numeros inteiros quantidade de letras ou palavras de texto é um numero inteiro mesmo se você mexer com coisas como preços que tem frações da moedas em centavos basta multiplicar por 100 e fazer contas com inteiros e so no final dividir por 100 e truncar depois por 2 casas decimais, então preço de produtos, salarios, impostos tudo pode ser calculado facilmente e mais importante rapido porque o hardware tem circuitos para somar numeros inteiros.
//Foi principalmente com o advento de coisas como computação grafica, programação em 3D que numeros fracionados começaram a fazer diferença no mundo comercial, e claro na computação cientifica ja precisara fazer calculos fracionados com muita precisão, em previsões de meteorologia ou laboratorios. mas isso era em nichos mais isolados e restritos com acesso a hardware especializado. Desde o começo do seculo XX ja haviam formas de calcular numeros fracionados.
//O Z! de Korad Zese, já havia esses conceitos, inclusive seu Z4 foi o primeiro computador comercial dos anos 1940 a ter suporte a numeros fracionados, Mainframes como o UNIVAC ou os da IBM dos anos 60 tinham suporte a calcular numeros fracionados também, mas so quando começamos a adotar arquitetura de 32 bits no começo dos anos 80 que os diversos padroes começaram a convergir pro que viria a se tornar o padrão IEEE 754. E so apartir dos anos 80 que começamos a adotar em microcomputadores domésticos.
//Nos CPU's de 8 bits como o 8086 a Intel começou a desenvolver oque se chamaria de co-processadores matematicos, como o 8087. Até a era do 386 a gente tinha a opção de adicionar um segundo chip, como o 80387 ue custava muito e poucos programas usavam. A partir do Intel 486DX, em 1989, as CPU's começaram a incluir as unidades de ponto flutuante integradas. isso eliminou a necessidade de co-processadores matematicos separados para realizar essas operações.
//Precisamos intender para que serviam os co-processadores ja que estavamos indo bem co apenas numeros inteiros, os CPU's dos anos 80 eram bons em processar numeros inteiros, mais eventualmente precisamos fracionar numeros decimais em particular numeros irracionais ou seja numeros que não podem ser representados por uma fração de numeros inteiros como 2√, π e muito mais que vão até o infinito.
//Se um numero com decimais pode ser representado por uma fração podemos usar numeros inteiros por exemplo o numero      0.3333333... e o inteiro 1/3 assim muitos numeros com casas decimais infinitas podem ser representados claramente por numeros inteiros finitos, mas o mesmo não acontece com numeros irracionais como π e computadores não tem memoria infinita então não temos como representar perfeito daí precisamos de uma aproximação e a palavra correta para isso "Aproximação" oque significa que ele não vai ser armazenado na memmoria como acha que deveria e sim algo aproximado a isso, essa aproximação e chamada de IEEE 754 que chamamos de ponto flutuante.
//Simplificando grosseiramente ja expliquei 