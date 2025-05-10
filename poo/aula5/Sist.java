public class Sist {
    public static void main(String[] args) {
        Leao x = new Leao();
        x.setNome("Simba");
        x.setIdade(10);
        System.out.println(x.getNome());
        System.out.println(x.getIdade());
        System.out.println(x.toString());
        x.rugir();
    }
}