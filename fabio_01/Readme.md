### Escreva um programa em C que:

1. **Leia 2 vetores A e B com N elementos, escreva um vetor C, sendo este a junção das vetores A e B. Desta forma, o vetor C deverá ter 2*N elementos.**

2. **Leia 2 vetores A e B com N elementos, escreva o conjunto união entre as vetores A e B; e o conjunto interseção entre as vetores A e B.**

3. **Leia um vetor A com 20 elementos, calcule e escreva o valor de S.**  
    S = (A[0] - A[19])2 + (A[1] - A[18])2 + ... + (A[8] - A[11])2 + (A[9] - A[10])2

4. **Leia um número (vetor com 8 elementos) na base binária, calcule e escreva este número na base hexadecimal e na base decimal.**

5. **Leia um vetor A com N elementos e escreva um vetor B com N elementos, conforme a seguinte condição: se índice de A[índice] é par então B[índice] = 0, caso contrário B[índice] = 1.**

6. **Leia um vetor com N elementos, encontre e escreva o maior e o menor elemento e suas respectivas posições no vetor.**

7. **Leia um vetor com N elementos, ordene-o e escreva-o em ordem crescente.**

8. **Gere um vetor com os N primeiros termos da seqüência de Fibonacci** *(0,1,1,2,3,5,8,13,21,...)***.**

9. **Leia um vetor com N números, calcule e escreva a soma e a media dos números lidos.**

10. **Leia um vetor com tamanho indefinido, calcule e escreva a soma e a media dos números lidos.**

11. **Um dado é lançado 50 vezes, e o valor correspondente é armazenado em um vetor. Faça um programa que determine o percentual de ocorrências de cada face do dado dentre esses 50 lançamentos.**

12. **Leia um número indeterminado de valores, correspondentes a notas, encerrando a entrada de dados quando for informado um valor igual a -1 (que não deve ser armazenado). Após esta entrada de dados, faça:**  
    *a. Mostre a quantidade de valores que foram lidos;  
    b. Exiba todos os valores na ordem em que foram informados, um ao lado do outro;  
    c. Exiba todos os valores na ordem inversa à que foram informados, um abaixo do outro;  
    d. Calcule e mostre a soma dos valores;  
    e. Calcule e mostre a média dos valores;  
    f. Calcule e mostre a quantidade de valores acima da média calculada;  
    g. Calcule e mostre a quantidade de valores abaixo de sete;  
    h. Encerre o programa com uma mensagem;*

13. **Utilize um vetor para resolver o problema a seguir. Uma empresa paga seus vendedores com base em comissões. O vendedor recebe $200 por semana mais 9 por cento de suas vendas brutas daquela semana. Por exemplo, um vendedor que teve vendas brutas de $3000 em uma semana recebe $200 mais 9 por cento de $3000, ou seja, um total de $470. Escreva um programa (usando um array de contadores) que determine quantos vendedores receberam salários nos seguintes intervalos de valores:**  
    *a. $200 - $299  
    b. $300 - $399  
    c. $400 - $499  
    d. $500 - $599  
    e. $600 - $699  
    f. $700 - $799  
    g. $800 - $899  
    h. $900 - $999  
    i. $1000 em diante*

14. **Em uma competição de salto em distância cada atleta tem direito a cinco saltos. O resultado do atleta será determinado pela média dos cinco valores restantes. Você deve fazer um programa que receba o nome e as cinco distâncias alcançadas pelo atleta em seus saltos e depois informe o nome, os saltos e a média dos saltos. O programa deve ser encerrado quando não for informado o nome do atleta. A saída do programa deve ser conforme o exemplo abaixo:**  

        Atleta: Rodrigo Curvêllo  

        Primeiro Salto: 6.5 m  
        Segundo Salto: 6.1 m  
        Terceiro Salto: 6.2 m  
        Quarto Salto: 5.4 m  
        Quinto Salto: 5.3 m  

        Resultado final:  
        Atleta: Rodrigo Curvêllo  
        Saltos: 6.5 - 6.1 - 6.2 - 5.4 - 5.3  
        Média dos saltos: 5.9 m*

15. **Uma grande emissora de televisão quer fazer uma enquete entre os seus telespectadores para saber qual o melhor jogador após cada jogo. Para isto, faz-se necessário o desenvolvimento de um programa, que será utilizado pelas telefonistas, para a computação dos votos. Para computar cada voto, a telefonista digitará um número, entre 1 e 23, correspondente ao número da camisa do jogador. Um número de jogador igual zero, indica que a votação foi encerrada. Se um número inválido for digitado, o programa deve ignorá-lo, mostrando uma breve mensagem de aviso, e voltando a pedir outro número. Após o final da votação, o programa deverá exibir:**

    *a. O total de votos computados;  
    b. Os números e respectivos votos de todos os jogadores que receberam votos;  
    c. O percentual de votos de cada um destes jogadores;  
    d. O número do jogador escolhido como o melhor jogador da partida, juntamente com o número de votos e o percentual de votos dados a ele.*  
    
**Observe que os votos inválidos e o zero final não devem ser computados como votos. O resultado aparece ordenado pelo número do jogador. O programa deve fazer uso de vetores. Abaixo segue uma tela de exemplo. A disposição das informações deve ser o mais próxima possível ao exemplo. Os dados são fictícios e podem mudar a cada execução do programa.**  

        Enquete: Quem foi o melhor jogador?  
        Número do jogador (0=fim): 9  
        Número do jogador (0=fim): 10  
        Número do jogador (0=fim): 9  
        Número do jogador (0=fim): 10  
        Número do jogador (0=fim): 11  
        Número do jogador (0=fim): 10  
        Número do jogador (0=fim): 50  
        Informe um valor entre 1 e 23 ou 0 para sair!  
        Número do jogador (0=fim): 9  
        Número do jogador (0=fim): 9  
        Número do jogador (0=fim): 0  

        Resultado da votação:  
        Foram computados 8 votos.  
        Jogador Votos %  
        9 4 50,0%  
        10 3 37,5%  
        11 1 12,5%  

        O melhor jogador foi o número 9, com 4 votos, sendo 50% do total de votos.

16. **Uma empresa de pesquisas precisa tabular os resultados da seguinte enquete feita a um grande quantidade de organizações:**  
    *"Qual o melhor Sistema Operacional para uso em servidores?"  
    As possíveis respostas são:  
    1- Windows Server  
    2- Unix  
    3- Linux  
    4- Netware  
    5- Mac OS  
    6- Outro*  

Você foi contratado para desenvolver um programa que leia os dados da enquete e informe ao final o resultado da mesma. O programa deverá ler os valores até ser informado o valor 0, que encerra a entrada dos dados. Não deverão ser aceitos valores além dos válidos para o programa (0 a 6). Os valores referentes a cada uma das opções devem ser armazenados num vetor. Após os dados terem sido completamente informados, o programa deverá calcular a percentual de cada um dos concorrentes e informar o vencedor da enquete. O formato da saída foi dado pela empresa, e é o seguinte:

        Sistema Operacional Votos %
        ------------------- ----- ---
        Windows Server 1500 17%
        Unix 3500 40%
        Linux 3000 34%
        Netware 500 5%
        Mac OS 150 2%
        Outro 150 2%
        ------------------- -----
        Total 8800
        O Sistema Operacional mais votado foi o Unix, com 3500 votos, sendo 40% dos votos.

17. **As Organizações Tabajara resolveram dar um abono aos seus colaboradores em reconhecimento ao bom resultado alcançado durante o ano que passou. Para isto contratou você para desenvolver um programa que servirá como uma projeção de quanto será gasto com o pagamento deste abono. Após reuniões envolvendo a diretoria executiva, a diretoria financeira e os representantes do sindicato laboral, chegou-se a seguinte forma de cálculo:**  

    *a. Cada funcionário receberá o equivalente a 20% do seu salário bruto de dezembro; O piso do abono será de R$ 100,00, isto é, aqueles funcionários cujo salário for muito baixo, recebem este valor mínimo; Neste momento, não se deve ter nenhuma preocupação com colaboradores com tempo menor de casa, descontos, impostos ou outras particularidades. Seu programa deverá permitir a digitação do salário de um número indefinido (desconhecido) de salários. Um valor de salário igual a 0 (zero) encerra a digitação. Após a entrada de todos os dados o programa deverá calcular o valor do abono concedido a cada colaborador, de acordo com a regra definida acima. Ao final, o programa deverá apresentar:*  
    *b. O salário de cada funcionário, juntamente com o valor do abono;*  
    *c. O número total de funcionário processados;*  
    *d. O valor total a ser gasto com o pagamento do abono;*  
    *e. O número de funcionário que receberá o valor mínimo de 100 reais;*  
    *f. O maior valor pago como abono;*  

**A tela abaixo é um exemplo de execução do programa, apenas para fins ilustrativos. Os valores podem mudar a cada execução do programa.**  

        *Projeção de Gastos com Abono*  
        ============================  
        *Salário: 1000*  
        *Salário: 300*  
        *Salário: 500*  
        *Salário: 100*  
        *Salário: 4500*  
        *Salário: 0*  
        *Salário - Abono*  
        *R$ 1000.00 - R$ 200.00*  
        *R$ 300.00 - R$ 100.00*  
        *R$ 500.00 - R$ 100.00*  
        *R$ 100.00 - R$ 100.00*  
        *R$ 4500.00 - R$ 900.00*  

        *Foram processados 5 colaboradores*  
        *Total gasto com abonos: R$ 1400.00*  
        *Valor mínimo pago a 3 colaboradores*  
        *Maior valor de abono pago: R$ 900.00*

18. **Faça um programa que carregue um vetor com os modelos de cinco carros (exemplos de modelos: FUSCA, GOL, VECTRA etc). Carregue um outro vetor com o consumo desses carros, isto é, quantos quilômetros cada um desses carros faz com um litro de combustível. Calcule e mostre:**  
    * O modelo do carro mais econômico;  
     Quantos litros de combustível cada um dos carros cadastrados consome para percorrer uma distância de 1000 quilômetros e quanto isto custará, considerando um que a gasolina custe R$ 2,25 o litro. Abaixo segue uma tela de exemplo. A disposição das informações deve ser o mais próxima possível ao exemplo. Os dados são fictícios e podem mudar a cada execução do programa.*  

        Comparativo de Consumo de Combustível  
        Veículo 1  
        Nome: fusca  
        Km por litro: 7  
        Veículo 2  
        Nome: gol  
        Km por litro: 10  
        Veículo 3  
        Nome: uno  
        Km por litro: 12.5  
        Veículo 4  
        Nome: Vectra  
        Km por litro: 9  
        Veículo 5  
        Nome: Peugeout  
        Km por litro: 14.5  

        Relatório Final  
        1 - fusca - 7.0 - 142.9 litros - R$ 321.43  
        2 - gol - 10.0 - 100.0 litros - R$ 225.00  
        3 - uno - 12.5 - 80.0 litros - R$ 180.00  
        4 - vectra - 9.0 - 111.1 litros - R$ 250.00  
        5 - peugeot - 14.5 - 69.0 litros - R$ 155.17  

        O menor consumo é do peugeot.

19. **Sua organização acaba de contratar um estagiário para trabalhar no Suporte de Informática, com a intenção de fazer um levantamento nas sucatas encontradas nesta área. A primeira tarefa dele é testar todos os N mouses que se encontram lá, testando e anotando o estado de cada um deles, para verificar o que se pode aproveitar deles. Foi requisitado que você desenvolva um programa para registrar este levantamento. O programa deverá receber um número indeterminado de entradas, cada uma contendo: um número de identificação do mouse e o tipo de defeito:**  
    *a. necessita da esfera;  
    b. necessita de limpeza;  
    c. necessita troca do cabo ou conector;  
    d. quebrado ou inutilizado.*  

**Uma identificação igual a zero encerra o programa. Ao final o programa deverá emitir o seguinte relatório:**  

        Quantidade de mouses: 100  
        Situação Quantidade Percentual  
        1- necessita da esfera 40 40%  
        2- necessita de limpeza 30 30%  
        3- necessita troca do cabo ou conector 15 15%  
        4- quebrado ou inutilizado 15 15%