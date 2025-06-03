package aula2;

public class SegundoPrograma {
    public static void main(String[] args) {
        System.out.println("ola");
        Carro fiatStrada = new Carro();
        fiatStrada.ano = 2006;
        fiatStrada.cor = "preto";
        System.out.println(fiatStrada.ano);
        System.out.println(fiatStrada.cor);

        Carro renaultKwid = fiatStrada;
        renaultKwid.ano = 2023;
        fiatStrada = new Carro();
        fiatStrada.ano = 1999;
        System.out.println(renaultKwid.ano);
        System.out.println(fiatStrada.ano);

        Moto cb1000 = new Moto();
        cb1000.placa = "SAGJGIA";
        cb1000.ano = 2001;
        cb1000.cor = "verde";
        System.out.println(cb1000.placa);
        System.out.println(cb1000.ano);
        System.out.println(cb1000.cor);

        cb1000.ligar();

        Moto m2 = null;
        System.out.println(m2.placa);
    }
}