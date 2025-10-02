package provas.P2.prova23_1.questao1;

import java.util.ArrayList;

public class Pais {
    private String codigo;
    private String nome;
    private int populacao;
    private double dimensao;
    private ArrayList<Pais> listaFronteiras = new ArrayList<Pais>();

    public Pais(String codigo) {
        this.codigo = codigo.toUpperCase();
    }

    public Pais(String codigo, String nome, double dimensao) {
        this(codigo);
        this.nome = nome;
        this.dimensao = dimensao;
    }

    public String getCodigo() {
        return codigo;
    }

    public String getNome() {
        return nome;
    }

    public int getPopulacao() {
        return populacao;
    }

    public void setPopulacao(int populacao) {
        this.populacao = populacao;
    }

    public double getDimensao() {
        return dimensao;
    }

    public ArrayList<Pais> getFronteiras() {
        return listaFronteiras;
    }

    public boolean equals(Object o) {
        if(o instanceof Pais) {
            Pais p = (Pais) o;
            return this.codigo.equals(p.codigo);
        }
        return false;
    }

    public String toString() {
        return nome;
    }

    public double getDensidadePopulacional() {
        return populacao / dimensao;
    }

    public boolean fazFronteira(Pais p) {
        if(listaFronteiras.contains(p)) return true;
        return false;
    }

    public void atribuirFronteira(Pais p) {
        listaFronteiras.add(p);
    }
}