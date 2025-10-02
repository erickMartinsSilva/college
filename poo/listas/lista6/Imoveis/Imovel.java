package listas.lista6.Imoveis;

public class Imovel {
    private int id;
    private String nomeProprietario;
    private String endereco;
    private int tipo; // venda (0) ou aluguel (1)
    private double valor;

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNomeProprietario() {
        return nomeProprietario;
    }

    public void setNomeProprietario(String nomeProprietario) {
        this.nomeProprietario = nomeProprietario;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public String getTipo() {
        if(tipo == 1) {
            return "Aluguel";
        } else {
            return "Venda";
        }
    }

    public void setTipo(String tipo) {
        if(tipo.equals("Aluguel")) {
            this.tipo = 1;
        } else if(tipo.equals("Venda")) {
            this.tipo = 0;
        }
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }
}
