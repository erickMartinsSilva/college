package listas.lista5;

public class TesteGerenciadorIRPF {
    public static void main(String[] args) {
        Cliente c1 = new Cliente();
        c1.setNome("Erick");
        c1.setCpf("000");

        ContaCorrente conta1 = new ContaCorrente();
        conta1.setNumero(1);
        conta1.deposita(1000);
        ContaCorrente conta2 = new ContaCorrente();
        conta2.setNumero(2);
        conta2.deposita(2500);
        SeguroDeVida s1 = new SeguroDeVida();

        c1.addTributavel(conta1);
        c1.addTributavel(conta2);
        c1.addTributavel(s1);

        GerenciadorIRPF g1 = new GerenciadorIRPF();
        g1.adiciona(c1.getTributaveis());
        System.out.println(g1.getTotal());
    }
}
