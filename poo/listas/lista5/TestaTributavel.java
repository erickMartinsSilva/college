package listas.lista5;

public class TestaTributavel {
    public static void main(String[] args) {
        ContaCorrente cc = new ContaCorrente();
        cc.deposita(100);
        System.out.println(cc.calculaTributos());

        // testando polimorfismo
        Tributavel t = cc;
        System.out.println(t.calculaTributos());
        // System.out.println(t.getSaldo());
        // não é possível chamar getSaldo a partir de t, pois esse metodo nao existe na interface Tributavel
    }
}