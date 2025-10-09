#### QUESTÃO 2

(a) Arquivos CSV são arquivos de registro de tamanho fixo ou variáveis? Justifique.

**Como os registros de um arquivo CSV são armazenados na forma de texto, pode-se concluir que arquivos CSV são arquivos de registro de tamanho variável, visto que cada linha pode ter um tamanho diferente devido à diferentes tamanhos em certos atributos do registro. Por exemplo: um arquivo CSV que armazena registros contendo um nome de uma pesssoa é de tamanho variável pois existem nomes maiores que os outros, logo, nem todos os registros vão ter o mesmo tamanho.**

(b) Explique a dificuldade de se fazer a busca binária neste tipo de arquivo.

**A dificuldade de se fazer a busca binária em arquivos de registro de tamanho variável se dá devido à assimetria e imprevisibilidade no tamanho dos registros. Quando temos um arquivo onde todos os registros possuem o mesmo tamanho (ou seja, um arquivo de registros de tamanho fixo), encontrar exatamente o registro do meio é uma tarefa mais fácil, permitindo dividirmos a busca.**