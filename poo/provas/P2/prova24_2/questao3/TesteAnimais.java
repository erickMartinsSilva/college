package provas.P2.prova24_2.questao3;

import java.util.List;
import java.util.ArrayList;

public class TesteAnimais {
    public static void main(String[] args) {
        List<Animal> listaAnimais = new ArrayList<Animal>();

        Cachorro c = new Cachorro();
        listaAnimais.add(c);
        Pato p = new Pato();
        listaAnimais.add(p);

        for(Animal a : listaAnimais) {
            a.emitirSom();
            a.mover();
        }
    }
}
