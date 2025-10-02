package aula8;

import java.util.HashMap;
import java.util.Set;
import java.util.Collection;
import java.util.Iterator;

public class TestaHashMap {
    public static void main(String[] args) {
        // HashMap: estrutura de dados não-indexada onde cada item possui uma chave que permite acessá-lo
        HashMap k = new HashMap();
        int soma = 0;

        Aluno a1 = new Aluno("Erick", 19, "BCC1");
        Aluno a2 = new Aluno("Andrade", 20, "BCC2");
        Aluno a3 = new Aluno("Barretto", 19, "BCC3");
        // adicionando instâncias de Aluno ao HashMap k atribuindo suas matrículas como chaves
        k.put(a1.getMatricula(), a1);
        k.put(a2.getMatricula(), a2);
        k.put(a3.getMatricula(), a3);

        // modos de encontrar elementos num hashmap

        // modo 1
        // método keySet() retorna um Set contendo as chaves de cada elemento do HashMap
        Set h = k.keySet();
        Iterator it = h.iterator();
        // iterando pelo set com o Iterator
        while(it.hasNext()) {
            if(k.get(it.next()) instanceof Aluno) {
                // obtém o elemento desejado com base em sua chave
                Aluno a = (Aluno) k.get(it.next()); 
                soma += a.getIdade();
            }
        }
        System.out.println("Média da idade dos alunos: " + ((double) (soma/k.size())));

        soma = 0;

        // modo 2
        // método values() retorna uma Collection contendo os valores de cada elemento do HashMap
        Collection c = k.values();
        Iterator it1 = c.iterator();
        // iterando pela collection com o Iterator
        while(it1.hasNext()) {
            if(it1.next() instanceof Aluno) {
                Aluno a = (Aluno) it1.next();
                soma += a.getIdade();
            }
        }
        System.out.println("Média da idade dos alunos: " + ((double) (soma/k.size())));


    } 
}