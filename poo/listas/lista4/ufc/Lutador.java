package listas.lista4.ufc;
import java.util.ArrayList;
import java.lang.Math;

public abstract class Lutador {
    private final String nome;
    private final int idade;
    private final double peso;

    public Lutador(String nome, int idade, double peso) {
        this.nome = nome;
        this.idade = idade;
        this.peso = peso;
    }

    public String getNome() {
        return nome;
    }

    public int getIdade() {
        return idade;
    }

    public double getPeso() {
        return peso;
    }

    public String toString() {
        return this.nome + "/" + this.idade + "/" + this.peso;
    }

    public String categoriaLutador() {
        if(this instanceof PesoPesado) return "Peso pesado";
        else if(this instanceof MeioPesado) return "Meio pesado";
        else if(this instanceof PesoMedio) return "Peso medio";
        else return "Peso pena";
    }

    public void possiveisLutas(Lutador[] array) {
        for (Lutador lutador : array) {
            if (this.categoriaLutador().equals(lutador.categoriaLutador())) {
                System.out.println(lutador);
            }
        }
    }

    public Lutador sorteioLuta(Lutador[] array) {
        ArrayList<Lutador> mesmaCategoria = new ArrayList<>();

        for(Lutador lutador : array) {
            if(this.categoriaLutador().equals(lutador.categoriaLutador())) {
                mesmaCategoria.add(lutador);
            }
        }

        return mesmaCategoria.get((int) (Math.random() * mesmaCategoria.size()));
    }
}
