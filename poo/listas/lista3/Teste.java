package listas.lista3;

public class Teste {
    public static void main(String[] args) {
        Data d1 = new Data();
        d1.setDia(19);
        d1.setMes(1);
        d1.setAno(2006);
        ContaBancaria c1 = new ContaBancaria();
        c1.setDataAbertura(d1);
        System.out.println(c1.getDataAberturaFormatada());
        c1.depositar(25000.50);
        System.out.println(c1.getSaldoFormatado());
        c1.sacar(500);
        System.out.println(c1.getSaldoFormatado());
        c1.sacar(100000.0);
        System.out.println(c1.getSaldoFormatado());
    }
}
