import java.util.Collection;
import java.util.HashSet;
import java.util.Iterator;

public class TestaHashSet {
    // função que retorna a média do tamanho das strings de uma Collection
    // Collection: interface de estruturas de dados implementada tanto por Lists quanto Sets
    public static double mediaTamanhoString(Collection<String> x) {
        double soma = 0;
        Iterator it = x.iterator();

        while(it.hasNext()) {
            String str = (String) it.next();
            soma += str.length();
        }
        return soma / ((double) x.size());
    }

    public static void main(String[] args) {
        // HashSet: estrutura de dados que não garante uma ordem, porém não é aleatória
        HashSet x = new HashSet();
        x.add("Uva");
        x.add("Bolo");
        x.add("Mesa");
        x.add("Camas");
        x.add("Porta");
        System.out.println(x); // saída: [Uva, Mesa, Porta, Cama, Bolo]

        System.out.println(mediaTamanhoString(x));
    }
}