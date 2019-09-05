### Exercício 02  

#### Escreva um programa em C utilizando vetor de registros, que atenda os seguintes requisitos:  
**1. O programa deve manipular no mínimo 02 (duas) fontes de dados;**  
**2. O programa deve implementar os conceitos de chave primária e chave estrangeira.**  
*CHAVE PRIMÁRIA: campo que serve para identificar unicamente um registro, não pode ser duplicado. Exemplo: matrícula, CPF, número da conta corrente etc.*  
*CHAVE ESTRANGEIRA: campo que faz referência a um campo em um outra fonte de dados. O valor do campo referenciado deve existir na fonte referenciada.*  

#### *Exemplo:*  
                       *Fonte de dados de alunos (Matricula é a chave primária)*
      |Matricula|Nome           |Data de Nascimento|        Endereço          |
      -------------------------------------------------------------------------
      |123456   |Raimundo Nonato|     08/04/1980   |Avenida Frei Serafim, 1234|
      -------------------------------------------------------------------------
      |123456
João Antonio
20/03/1981
Avenida Miguel Rosa, 4321
345678
Maria do Amparo
15/08/1979
Avenida Campos Sales, 1212
↑
Fonte de dados de notas (Matricula_Aluno é a chave estrangeira)
↓
Matricula_Aluno
Disciplina
Nota 1
Nota 2
Nota 3
123456
Alg-01
10.0
9.0
7.0
123456
Est-02
7.0
8.5
9.0 123457
Alg-01
7.5
8.0
9.5 123457
Est-02
9.0
9.5
10.0
SUGESTÕES:
 Sistema de Controle Acadêmico (cadastro de alunos, notas, cursos, disciplinas etc.)
 Sistema de Controle de Estoque (cadastro de produtos, compras, vendas etc.)
 Sistema de Folha de Pagamento (cadastro de funcionários, dependentes etc.)
 Sistema de Controle de Vendas (cadastro de produtos, clientes, vendas etc.)
DISPOSIÇÕES FINAIS:
a) O programa deverá implementar as operações de inclusão, exclusão, consulta e relatório para cada fonte de dados.
b) No caso de existência de cópias (programas iguais), os envolvidos terão suas notas iguais a 0 (zero).
