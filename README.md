# trabalho_pe

Instruções para rodar: dentro da pasta codigos -> make // para executar -> ./cliente

Feito individualmente por: Caio Pereria Neris, RA: 11202230288. Professor Maycon Sambinelli (programação estruturada)


Abordagem: 

Defini como base 10⁹, pois o limite de long long int para multiplicação é 10¹⁹. Dessa forma, realizar as próprias operações +, - e * da linguagem C não dariam problema. Realizei a ideia mais simples, a função le_convert() usa o getline para ler os numeros até um \n, cada dígito nessa base tem 9 dígitos na base 10, ficando alocados em um vetor, que guarda do menos para o mais significativo, alocando se preciso mais um dígito para as operações. Dessa forma reduzimos muito o valor de dígitos alocados, que podendo ser do limite long long int, faz com que o número seja muito mais limmitado a memória e capacidade do computador, já que apenas para guardar em armazenamento um número com tantos dígitos, já seria praticamente inviável. 

Implementação: 

A ideia é a mais simples, realizar a soma e a subtração dígito a dígito, e sendo a base grande, deixaria mais eficiente, pois quando trabalhamos com números grandes, é uma boa ideia explorar os limites da linguagem matematicamente a seu favor. Para deixar mais eficiente, todas as funções de operação recebem o ponteiro do BigNumber, dessa forma, não é necessário fazer a cópia, o que seria pouco eficiente para os numeros muito grandes. Na soma e subtação, alreramos o maior numero, fazendo assim que nem seja preciso criar outro para ganhar eficiência pelo mesmo argumento acima. No cliente .c coloquei os "elses e ifs" para trabalhar corretamente com a questão de sinal, deixando as operações exclusivamente para somar ou subtrair, deixando-as mais fácil de serem lidas e de se encontrar erros. Para a multiplicação, a ideia foi fazer o "algoritmo de fundamental", aquele feito à mão de multiplicar os dígitos e somar com os resultados que ocupam a mesma posição. Nesse caso é criado um novo BigNumber, pois não é possível mudar apenas um BigNumber como nas outras operações. 

Na impressão temos alguns casos especiais, o dígito mais significativo é impresso sem adição de zeros a esquerda, e os demais são para a base "dar certo" em decimal. Temos também o caso de imprimir o sinal e o caso de que um número dê apenas zero. 

Testes: 

Realizei o redirecionamento de entrada e saída conforme ensinado em aula, os testes disponibilizados pelo professor estão em instances. Em "meusresultados" estão or arquivos .out gerados pelo meu programa. Usando "diff" comparei o resultado esperado com o que obtive, e para todos os casos obtive sucesso. 

