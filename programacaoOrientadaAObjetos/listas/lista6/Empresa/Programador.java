package listas.lista6.Empresa;

public class Programador extends Funcionario {
    public Programador(String id) {
        super(id);
    }

    public String toString() {
        return super.getId() + "-" + super.getNome() + "-R$" + super.getSalario() + "-P";
    }
}
