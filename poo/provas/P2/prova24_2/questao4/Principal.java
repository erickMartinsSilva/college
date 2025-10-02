package provas.P2.prova24_2.questao4;

public class Principal {
    public static void main(String[] args) {
        Caneta c = new Caneta();
        c.setCor("rosa");
        Caneta c2 = new Caneta();
        c2.setCor("amarela");
        c2.setQuantidade(91);
        metodoCan1(c);
        metodoCan2(c2);
        int i = 15;
        Integer j = i++;
        qtd(i);
        ++i;
        qtd2(j);
        System.out.println(i);
        System.out.println(j);
        System.out.println(c.getQuantidade());
        System.out.println(c2.getQuantidade());
        System.out.println(c.getCor());
        System.out.println(c2.getCor());
    }

    public static void metodoCan1(Caneta c) {
        c.setCor("azul");
        c.setQuantidade(3);
    }

    public static void metodoCan2(Caneta c) {
        c.setQuantidade(2);
        c = new Caneta();
        c.setCor("preto");
    }

    public static void qtd(int i) {
        i = 161;
    }

    public static Integer qtd2(Integer i) {
        return i + 17;
    }
}