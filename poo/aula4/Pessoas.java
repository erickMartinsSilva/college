public class Pessoas {
    public static void main(String[] args) {
        Pessoa pessoas[] = new Pessoa[3];

        pessoas[0] = new Pessoa();
        pessoas[0].nome = "Erick";
        pessoas[0].idade = 19;
        pessoas[0].peso = 72.4;
        
        System.out.print(pessoas[0].nome + " " + pessoas[0].idade + " " + pessoas[0].peso);
    }
}