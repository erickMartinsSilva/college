package listas.lista6.Empresa;

public class AnalistaSistemas extends Funcionario {
    public AnalistaSistemas(String id) {
        super(id);
    }

    public String toString() {
        return super.getId() + "-" + super.getNome() + "-R$" + super.getSalario() + "-A";
    }
}
