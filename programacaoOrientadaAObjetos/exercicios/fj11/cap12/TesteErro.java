package cap12;

public class TesteErro {
    public static void main(String[] args) {
        System.out.println("inicio do main");
        metodo1();
        System.out.println("fim do main");
    }

    static void metodo1() {
        System.out.println("inicio do metodo1");
        metodo2();
        System.out.println("fim do metodo1");
    }
    
    static void metodo2() {
        System.out.println("inicio do metodo2");
        ContaCorrente cc = new ContaCorrente(1);
        // try catch: estrutura que permite tratar exceções num programa
        for(int i = 0; i <= 15; i++) {
            try {
                cc.deposita(i + 1000);
                System.out.println(cc.getSaldo());
                // causa uma exception quando i > 5 pois o programa vai tentar acessar uma referência nula
                if(i == 5) {
                    cc = null;
                }
            } catch(NullPointerException e) {
                System.out.println("erro: " + e);
            }
        }
        System.out.println("fim do metodo2");
    }
}