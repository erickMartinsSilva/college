package listas.lista5;

import java.util.List;

public class GerenciadorIRPF {
    private double total;

    public void adiciona(Tributavel t) {
        total += t.calculaTributos();
    }

    public void adiciona(List<Tributavel> t) {
        for(int i = 0; i < t.size(); i++) {
            total += t.get(i).calculaTributos();
        }
    }

    public double getTotal() {
        return total;
    }
}
