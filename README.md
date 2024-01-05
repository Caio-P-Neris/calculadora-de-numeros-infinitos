# trabalho_pe

Ideia do trabalho: fazer uma calculadora de alta precisão para números tão grandes quanto o usuário quiser, sendo limitado em teoria apenas pela memória do computador que está rodando (em C).

Instruções para rodar: dentro da pasta codigos -> make // para executar -> ./cliente // usei redirecionamento de entrada

Feito individualmente por: Caio Pereria Neris, RA: 11202230288. Professor Maycon Sambinelli (programação estruturada)


Abordagem: 

Primeiramente minha função le_converte é chamada, onde é lido pelo getline uma string, a ideia é guardar cada dígito convertido para a base 10⁹ em um vetor, cujo tamanho para alocação é adaptado para comportar a nova base (algo que facilita por ser grande), levando em conta a possível alocação de um a mais para a soma. Cada dígito do "numerao" é lido, convertido para int por meio da operação vinda da tabela ascii e é guardado, somando-o a seu respectivo dígito, isso foi possível pois aloquei como "calloc", o que já inicia como zero, facilitando assim esse processo. Também o sinal é dado importante da struct, no código "cliente.c" estão algumas condicionais que consideram corretamente a operação a ser feita de acordo com os sinais, fiz isso para facilitar a construção das operações de soma e subtração, já que se ali dentro esses casos fossem tratados, a chance de dar erro era maior. Também há algumas condicionais para levar em conta casos especiais (dígitos de zeros, tamanhos iguais por conta do dígito extra mas que na verdade são diferentes). Defini como base 10⁹, pois o limite de long long int para multiplicação é 10¹⁹. Dessa forma, realizar as próprias operações +, - e * da linguagem C não dariam problema. Para facilitar as operações, os dígitos no vetor estão do menos para o mais significativo. Dessa forma reduzimos muito o valor de dígitos alocados, que podendo ser do limite long long int, faz com que o número seja muito mais limitado a memória e capacidade do computador, já que apenas para guardar em armazenamento um número com tantos dígitos, já seria praticamente inviável. 

Implementação: 

A ideia é a mais simples, realizar a soma e a subtração dígito a dígito, e sendo a base grande, deixaria mais eficiente, pois quando trabalhamos com números grandes, é uma boa ideia explorar os limites da linguagem matematicamente a seu favor. Para deixar mais eficiente, todas as funções de operação recebem o ponteiro do BigNumber, dessa forma, não é necessário fazer a cópia, o que seria pouco eficiente para os numeros muito grandes. Na soma e subtação, alreramos o maior numero, fazendo assim que nem seja preciso criar outro para ganhar eficiência pelo mesmo argumento acima. No "cliente.c" como dito anteriormente, as condicionnais servem para trabalhar corretamente com a questão de sinal, deixando as operações exclusivamente para somar ou subtrair, deixando-as mais fácil de serem lidas, o que facilitou quando fui procurar os erros. Para a multiplicação, a ideia foi fazer o "algoritmo de fundamental", aquele feito à mão de multiplicar os dígitos e somar com os resultados que ocupam a mesma posição. Nesse caso é criado um novo BigNumber, pois não é possível mudar apenas um BigNumber como nas outras operações. 

Na impressão temos alguns casos especiais, o dígito mais significativo é impresso sem adição de zeros a esquerda, e os demais são para a base "dar certo" em decimal. Temos também o caso de imprimir o sinal e o caso de que um número dê apenas zero. 

Testes: 

Realizei o redirecionamento de entrada e saída conforme ensinado em aula, os testes disponibilizados pelo professor estão em instances. Em "meusresultados" estão or arquivos .out gerados pelo meu programa. Usando "diff" comparei o resultado esperado com o que obtive, e para todos os casos obtive sucesso. Também não encontrei vazamento de memória utilizando o Valgrind.

