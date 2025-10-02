package listas.lista6.Empresa;

public class Funcionario {
    private String id;
    private String nome;
    private double salario;

    public Funcionario(String id) {
        this.id = id;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public boolean equals(Object o) {
        if(o instanceof Funcionario) {
            Funcionario f = (Funcionario) o;
            return this.getId().equals(f.getId());
        }
        return false;
    }

    public String toString() {
        return this.id + "-" + this.nome + "-R$" + this.salario;
    }
}
